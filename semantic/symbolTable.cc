#include "symbolTable.h"
#include "scope.h"
#include <string>

void symbolTable::stBuilderRec(Node *walker, Node *parent)
{
    for (auto next = walker->children.begin(); next != walker->children.end(); next++)
    {
        if ((*next)->type == "VarDeclaration" || (*next)->type == "TypeIdentifier")
        {
            variable *newRecord = new variable();
            auto child = (*next)->children.begin();
            if ((*child)->type != "identifierType")
            {
                newRecord->type = (*child)->value;
            }
            else
            {
                auto temp = (*child)->children.begin();
                newRecord->type = (*temp)->value;
            }
            child++;
            newRecord->id = (*child)->value;
            put(newRecord->id, newRecord);
            declared(newRecord->id);

            // std::cout << "Record: type: " << newRecord->type << " id: " << newRecord->id << std::endl;
        }
        else if ((*next)->type == "MainClass")
        {
            Class *newRecord = new Class();
            auto child = (*next)->children.begin();
            newRecord->id = (*child)->value;
            newRecord->type = "MainClass";
            put(newRecord->id, newRecord);
            // std::cout << "Record: type: " << newRecord->type << " id: " << newRecord->id << std::endl;
            declared(newRecord->id);
            enterScope();
            current->scopeRecord = newRecord;
            stBuilderRec((*next), walker);
            exitScope();
        }
        else if ((*next)->type == "PublicMainMethod")
        {
            method *newRecord = new method();
            auto child = (*next)->children.begin();
            newRecord->id = "main";
            newRecord->type = "PublicMainMethod";
            newRecord->parameters.insert({(*child)->value, "String"});
            put(newRecord->id, newRecord);
            // std::cout << "Record: type: " << newRecord->type << " id: " << newRecord->id << std::endl;
            declared(newRecord->id);
            enterScope();
            current->scopeRecord = newRecord;
            stBuilderRec((*next), walker);
            exitScope();
        }
        else if ((*next)->type == "ClassDeclaration")
        {
            Class *newRecord = new Class();
            auto child = walker->children.begin();
            newRecord->id = (*child)->children.front()->value;
            newRecord->type = "Class";
            put(newRecord->id, newRecord);
            // std::cout << "Record: type: " << newRecord->type << " id: " << newRecord->id << std::endl;
            declared(newRecord->id);
            enterScope();
            current->scopeRecord = newRecord;
            stBuilderRec((*next), walker);
            exitScope();
        }
        else if ((*next)->type == "MethodDeclaration")
        {
            method *newRecord = new method();
            auto child = (*next)->children.begin();
            newRecord->type = (*child)->value;
            child++;
            newRecord->id = (*child)->value;
            put(newRecord->id, newRecord);
            // std::cout << "Record: type: " << newRecord->type << " id: " << newRecord->id << std::endl;
            declared(newRecord->id);
            enterScope();
            child++;
            addParameters((*child), newRecord);
            current->scopeRecord = newRecord;
            stBuilderRec((*next), walker);
            exitScope();
        }
        else
        {
            stBuilderRec((*next), walker);
        }
    }
}

void symbolTable::addParameters(Node *ptr, method *scopeRecord)
{
    if (ptr->type == "TypeIdentifier")
    {
        auto child = ptr->children.begin();
        std::string type = (*child)->value;
        child++;
        std::string id = (*child)->value;
        scopeRecord->parameters.insert({id, type});
    }

    for (auto i = ptr->children.begin(); i != ptr->children.end(); i++)
    {
        addParameters((*i), scopeRecord);
    }
}

void symbolTable::stBuilder()
{
    Node *walker = nodeRoot;
    stBuilderRec(walker, walker);
}

symbolTable::symbolTable()
{
    root = new scope();
    current = root;
}

void symbolTable::enterScope() { current = current->nextChild(); }
void symbolTable::exitScope() { current = current->Parent(); }

void symbolTable::init(Node *root)
{
    nodeRoot = root;
    stBuilder();
}

void symbolTable::put(std::string key, record *item)
{
    current->put(key, item);
}

record *symbolTable::lookup(std::string key)
{
    return current->lookup(key);
}

void symbolTable::printSTtree()
{
    root->printRecords();
}

void symbolTable::resetScopes()
{
    root->resetScope();
    current = root;
}

scope *symbolTable::operator[](int index)
{
    if (index < current->children.size())
    {
        return current->children[index];
    }
    else
    {
        return nullptr;
    }
}

scope *symbolTable::getCurrent()
{
    return current;
}

int symbolTable::size()
{
    return current->children.size();
}

void symbolTable::declared(std::string key)
{
    if (current->declarationCount.count(key) == 0)
    {
        current->declarationCount.insert({key, 1});
    }
    else
    {
        auto var = current->declarationCount.find(key);
        current->declarationCount[var->first] = 2;
    }
}

bool symbolTable::duplicatesFound()
{
    scope *ptr = root;
    bool returnBool = false;
    for (auto i = ptr->declarationCount.begin(); i != ptr->declarationCount.end(); i++)
    {
        if (i->second > 1)
        {
            std::cout << "Error: Duplicate declaration " << i->first << " found in " << ptr->scopeRecord->type << " " << ptr->scopeRecord->id << "!\n";
            returnBool = true;
        }
    }
    for (int i = 0; i < ptr->children.size(); i++)
    {
        returnBool = duplicatesFoundRec(ptr->children[i]);
    }

    return returnBool;
}
bool symbolTable::duplicatesFoundRec(scope *ptr)
{
    bool returnBool = false;
    for (auto i = ptr->declarationCount.begin(); i != ptr->declarationCount.end(); i++)
    {
        if (i->second > 1)
        {
            std::cout << "Error: Duplicate declaration " << i->first << " found in " << ptr->scopeRecord->type << " " << ptr->scopeRecord->id << "!\n";
            returnBool = true;
        }
    }
    for (int i = 0; i < ptr->children.size(); i++)
    {
        returnBool = duplicatesFoundRec(ptr->children[i]);
    }
    return returnBool;
}

bool symbolTable::testType(Node *ptr, std::string type)
{
    if (expressionCheckRecNode(ptr))
    {
        return true;
    }
    if (expressionElements.size() > 0)
    {
        for (int i = 0; i < expressionElements.size(); i++)
        {
            if (type != expressionElements[i])
            {
                std::cout << "Error: Expression in "
                          << current->scopeRecord->type
                          << " "
                          << current->scopeRecord->id
                          << " consists of differing types\n";
                return true;
            }
        }
        expressionElements.clear();
        return false;
    }
}
bool symbolTable::testType(Node *ptr)
{
    if (expressionCheckRecNode(ptr))
    {
        return true;
    }
    if (expressionElements.size() > 0)
    {
        std::string type = expressionElements[0];
        for (int i = 0; i < expressionElements.size(); i++)
        {
            if (type != expressionElements[i])
            {
                std::cout << "Error: Expression in "
                          << current->scopeRecord->type
                          << " "
                          << current->scopeRecord->id
                          << " consists of differing types\n";
                return true;
            }
        }
        expressionElements.clear();
        return false;
    }
}
bool symbolTable::testTypeIdentifier(Node *ptr)
{
    auto child = ptr->children.begin();
    record *varRecord = current->lookup((*child)->value);
    child++;
    if (expressionCheckRecNode((*child)))
    {
        return true;
    }
    if (expressionElements.size() > 0)
    {
        std::string type = varRecord->type;
        for (int i = 0; i < expressionElements.size(); i++)
        {
            if (type != expressionElements[i])
            {
                std::cout << "Error: Assign statement in "
                          << current->scopeRecord->type
                          << " "
                          << current->scopeRecord->id
                          << " expression doesn't match identifier type\n";
                return true;
            }
        }
        expressionElements.clear();
        return false;
    }
}

method *symbolTable::methodLookup(std::string className, std::string methodName)
{
    method *methodRecord = nullptr;
    std::cout << "Method: " << methodName << " class: " << className << "\n";
    scope *origin = current;
    while (current != nullptr)
    {
        if (current->isInScope(className))
        {
            scope *classScope;
            for (int i = 0; i < current->children.size(); i++)
            {
                if (current->children[i]->scopeRecord->id == className)
                {
                    std::cout << "Hit\n";
                    classScope = current->children[i];
                    record *rec = classScope->lookup(methodName);
                    if (rec != nullptr)
                    {
                        std::cout << "methodcall, methodName: " << rec->id << std::endl;
                        methodRecord = (method *)rec;
                        current = origin;
                        std::cout << "Hello\n";
                        return methodRecord;
                    }
                    break;
                }
            }
            break;
        }
        current = current->parent;
    }
    return methodRecord;
}

std::string symbolTable::getType(Node *ptr)
{
    std::string type = "";
    if (ptr->type == "Identifier")
    {
        record *identifierVal = lookup(ptr->value);
        if (identifierVal != nullptr)
        {
            return identifierVal->type;
        }
        else
        {
            std::cout << "Error: variable " << ptr->value << " is not declared\n";
            return "";
        }
    }
    else if (ptr->type == "IntegerLiteral")
    {
        return "int";
    }
    else if (ptr->type == "BooleanExpression")
    {
        return "boolean";
    }
    else if (ptr->type == "ThisExpression")
    {
        return current->scopeRecord->id;
    }
    else if (ptr->type == "intArray")
    {
        return "intArray";
    }
    for (auto i = ptr->children.begin(); i != ptr->children.end(); i++)
    {
        type = getType((*i));
    }
    return type;
}

std::vector<std::string> symbolTable::getParams(Node *ptr, std::vector<std::string> params)
{
    auto expressionList = ptr->children.begin();
    for (auto i = (*expressionList)->children.begin();i != (*expressionList)->children.end();i++)
    {
        params.push_back(getType((*i)));
    }
    return params;
}

bool symbolTable::expressionCheck()
{
    current = root;
    Node *nodePtr = nodeRoot;
    resetScopes();
    bool returnBool;
    return expressionCheckRec(nodePtr);
}

bool symbolTable::expressionCheckRec(Node *nodePtr)
{
    for (auto next = nodePtr->children.begin(); next != nodePtr->children.end(); next++)
    {
        if ((*next)->type == "Expression")
        {
            if (testType((*next)))
            {
                return true;
            }
            if (expressionCheckRec((*next)))
            {
                return true;
            }
        }
        else if ((*next)->type == "IF_ElseStatement" || (*next)->type == "WhileStatement")
        {
            if (testType((*next), "boolean"))
            {
                return true;
            }
            if (expressionCheckRec((*next)))
            {
                return true;
            }
        }
        else if ((*next)->type == "AssignStatement")
        {
            auto child = (*next)->children.begin();
            child++;
            if ((*child)->type != "MethodCall")
            {
                if (testType((*next)))
                {
                    return true;
                }
                if (expressionCheckRec((*next)))
                {
                    return true;
                }
            }
            else
            {
                Node *methodCallNode = (*child);
                auto mChild = methodCallNode->children.begin();
                std::string className;
                method *methodRecord;
                if ((*mChild)->value == "this")
                {
                    className = (*mChild)->value;
                }
                else
                {
                    className = (*(*mChild)->children.begin())->value;
                }
                mChild++;
                if (className != "this")
                {
                    methodRecord = methodLookup(className, (*mChild)->value);
                }
                else
                {
                    methodRecord = (method*)lookup((*mChild)->value);
                }
                if (methodRecord == nullptr)
                {
                    std::cout << "Error; method: " << (*mChild)->value << " does not exist!\n";
                    return true;
                }
                else
                {
                    mChild++;
                    std::cout << "method exists, checking parameters" << std::endl;
                    std::vector<std::string> params1;
                    std::vector<std::string> params2;
                    for (auto i = methodRecord->parameters.begin(); i != methodRecord->parameters.end(); i++)
                    {
                        params1.push_back(i->second);
                    }
                    params2 = getParams((*mChild), params2);
                    if (params1.size() != params2.size())
                    {
                        std::cout << "Error; Invalid number of parameters in methodcall!\n";
                        return true;
                    }
                    for (int i = 0;i < params1.size();i++)
                    {
                        if (params2[i] != params1[i])
                        {
                            std::cout << "Error; Invalid parameter in methodcall!\n";
                            return true;
                        }
                    }
                }
            }
        }
        else if ((*next)->type == "ArrayIndexAssignStatement")
        {
            if (testType((*next), "int"))
            {
                return true;
            }
            auto child = (*next)->children.begin();
            child++;
            expressionCheckRec((*child));
            if (expressionElements.size() > 0)
            {
                std::string type = "int";
                for (int i = 0; i < expressionElements.size(); i++)
                {
                    if (type != expressionElements[i])
                    {
                        std::cout << "Error: Assign statement in "
                                  << current->scopeRecord->type
                                  << " "
                                  << current->scopeRecord->id
                                  << " expression doesn't match identifier type\n";
                        return true;
                    }
                }
                expressionElements.clear();
            }
            if (expressionCheckRec((*next)))
            {
                return true;
            }
        }
        else if ((*next)->type == "SystemOutPrintStatement")
        {
            if (testType((*next), "int"))
            {
                return true;
            }
            if (expressionCheckRec((*next)))
            {
                return true;
            }
        }
        else if ((*next)->type == "dotlength")
        {
            if (testType((*next), "intArray"))
            {
                return true;
            }
            if (expressionCheckRec((*next)))
            {
                return true;
            }
        }
        else if ((*next)->type == "MainClass")
        {
            enterScope();
            if (expressionCheckRec((*next)))
            {
                return true;
            }
            exitScope();
        }
        else if ((*next)->type == "PublicMainMethod")
        {
            enterScope();
            if (expressionCheckRec((*next)))
            {
                return true;
            }
            exitScope();
        }
        else if ((*next)->type == "ClassDeclaration")
        {
            enterScope();
            if (expressionCheckRec((*next)))
            {
                return true;
            }
            exitScope();
        }
        else if ((*next)->type == "MethodCall")
        {
            std::cout << "MEthOD!!!\n";
            if (expressionCheckRec((*next)))
            {
                return true;
            }
        }
        else if ((*next)->type == "MethodDeclaration")
        {
            enterScope();
            auto child = (*next)->children.begin();
            auto endChild = (*next)->children.end();
            endChild--;
            while ((*endChild)->children.empty() == false)
            {
                endChild = (*endChild)->children.begin();
            }
            std::string returnType = (*endChild)->value;
            std::string targetType = (*child)->value;
            child++;
            std::string methodName = (*child)->value;
            record *base = lookup(methodName);
            method *targetMethod = (method *)base;
            record *targetReturn = lookup(returnType);
            std::string returnId = ""; // for error reporting
            if (targetReturn)
            {
                returnType = targetReturn->type;
                returnId = (*endChild)->value;
            }
            else
            {
                returnType = (*endChild)->type;
                returnType = getTypeLiteralExpression(returnType);
                if (returnType == "n/a")
                {
                    returnId = (*endChild)->value;
                    auto params = targetMethod->parameters;
                    returnType = "Undefined identifier";
                    for (auto i = params.begin(); i != params.end(); ++i)
                    {
                        if (returnId == i->first)
                        {
                            returnType = i->second;
                        }
                    }
                }
            }
            // std::cout << "methodType: " << targetType
            // << " methodName: " << methodName
            // << " targetMethodType: " << targetMethod->type
            // << " returnType: " << returnType
            // << std::endl;
            if (targetType != returnType)
            {
                std::cout << "Error: Return type in method: "
                          << methodName << " '"
                          << targetType << "' "
                          << "doesn't match type being returned: "
                          << returnId << " '"
                          << returnType << "'"
                          << std::endl;
            }
            // more for methodCall checking, saving here for then
            // some other stuff above will be moved to methodCall
            auto params = targetMethod->parameters;
            if (params.empty())
            {
                std::cout << "params empty" << std::endl;
            }
            else
            {
                std::cout << "params not empty" << std::endl;
                std::cout << "Nr of params: " << params.size() << std::endl;
                for (auto j = params.begin(); j != params.end(); ++j)
                {
                    std::cout << "Method Parameters: type: "
                              << j->second << " id: "
                              << j->first << std::endl;
                }
            }
            if (expressionCheckRec((*next)))
            {
                return true;
            }
            exitScope();
        }
        else
        {
            if (expressionCheckRec((*next)))
            {
                return true;
            }
        }
    }
    return false;
}

std::string symbolTable::getTypeLiteralExpression(std::string literal)
{
    if (literal == "IntegerLiteral")
    {
        return "int";
    }
    else if (literal == "BooleanExpression")
    {
        return "boolean";
    }
    return "n/a";
}

bool symbolTable::expressionCheckRecNode(Node *nodePtr)
{
    if (nodePtr->type == "Identifier")
    {
        record *identifierVal = lookup(nodePtr->value);
        if (identifierVal != nullptr)
        {
            expressionElements.push_back(identifierVal->type);
        }
        else
        {
            std::cout << "Error: variable " << nodePtr->value << " is not declared\n";
            return true;
        }
    }
    else if (nodePtr->type == "IntegerLiteral")
    {
        expressionElements.push_back("int");
    }
    else if (nodePtr->type == "BooleanExpression")
    {
        expressionElements.push_back("boolean");
    }
    else if (nodePtr->type == "ThisExpression")
    {
        expressionElements.push_back(current->scopeRecord->id);
    }
    else if (nodePtr->type == "intArray")
    {
        expressionElements.push_back("intArray");
    }
    for (auto i = nodePtr->children.begin(); i != nodePtr->children.end(); i++)
    {
        if (expressionCheckRecNode((*i)))
        {
            return true;
        }
    }
    return false;
}

bool symbolTable::typeCheck()
{
    return expressionCheck();
}
