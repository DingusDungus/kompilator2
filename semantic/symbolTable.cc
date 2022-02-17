#include "symbolTable.h"
#include "scope.h"
#include <string>

void symbolTable::stBuilderRec(Node *walker, Node *parent)
{
    for (auto next = walker->children.begin(); next != walker->children.end(); next++)
    {
        if ((*next)->type == "VarDeclaration")
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
    expressionCheckRecNode(ptr);
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
    expressionCheckRecNode(ptr);
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
    expressionCheckRec((*child));
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
        }
        else if ((*next)->type == "IF_ElseStatement" || (*next)->type == "WhileStatement")
        {
            if (testType((*next), "boolean"))
            {
                return true;
            }
        }
        else if ((*next)->type == "AssignStatement")
        {
            if (testTypeIdentifier((*next)))
            {
                return true;
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
        }
        else if ((*next)->type == "SystemOutPrintStatement")
        {
            if (testType((*next), "int"))
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
            enterScope();
            std::cout << "METHOD CALL!" << std::endl;
            std::cout << "METHOD CALL!" << std::endl;
            std::cout << "METHOD CALL!" << std::endl;
            std::cout << "METHOD CALL!" << std::endl;
            if (expressionCheckRec((*next)))
            {
                return true;
            }
            exitScope();
        }
        else if ((*next)->type == "MethodDeclaration")
        {
            enterScope();
            expressionCheckRec((*next));
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
            record* base = lookup(methodName);
            method* targetMethod = (method*)base;
            record* targetReturn = lookup(returnType);
            std::string returnId = ""; // for error reporting
            if (targetReturn) {
                returnType = targetReturn->type;
                returnId = (*endChild)->value;
            }else{
                returnType = (*endChild)->type;
                returnType = getTypeLiteralExpression(returnType);
                if (returnType == "n/a") {
                    returnId = (*endChild)->value;
                    auto params = targetMethod->parameters;
                    returnType = "Undefined identifier";
                    for (auto i = params.begin(); i != params.end(); ++i) {
                        if (returnId == i->first) {
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
            if (targetType != returnType) {
                std::cout <<
                    "Error: Return type in method: "
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
            else {
                std::cout << "params not empty" << std::endl;
                std::cout << "Nr of params: " << params.size() << std::endl;
                for (auto j = params.begin(); j != params.end(); ++j) {
                    std::cout << "Method Parameters: type: "
                        << j->second <<
                        " id: "
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

std::string symbolTable::getTypeLiteralExpression(std::string literal){
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

void symbolTable::expressionCheckRecNode(Node *nodePtr)
{
    if (nodePtr->type == "Identifier")
    {
        record *identifierVal = lookup(nodePtr->value);
        expressionElements.push_back(identifierVal->type);
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
        expressionCheckRecNode((*i));
    }
}

bool symbolTable::typeCheck()
{
    return expressionCheck();
}
