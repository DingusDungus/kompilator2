#include "symbolTable.h"

void symbolTable::stBuilderRec(Node *walker, Node *parent)
{
    for (auto next = walker->children.begin(); next != walker->children.end(); next++)
    {
        if ((*next)->type == "VarDeclaration")
        {
            variable *newRecord = new variable();
            auto child = (*next)->children.begin();
            newRecord->type = (*child)->value;
            child++;
            newRecord->id = (*child)->value;
            put(newRecord->id, newRecord);
            declared(newRecord->id);

            //std::cout << "Record: type: " << newRecord->type << " id: " << newRecord->id << std::endl;
        }
        else if ((*next)->type == "MainClass")
        {
            Class *newRecord = new Class();
            auto child = (*next)->children.begin();
            newRecord->id = (*child)->value;
            newRecord->type = "MainClass";
            put(newRecord->id, newRecord);
            //std::cout << "Record: type: " << newRecord->type << " id: " << newRecord->id << std::endl;
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
            //std::cout << "Record: type: " << newRecord->type << " id: " << newRecord->id << std::endl;
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
            //std::cout << "Record: type: " << newRecord->type << " id: " << newRecord->id << std::endl;
            declared(newRecord->id);
            enterScope();
            current->scopeRecord = newRecord;
            stBuilderRec((*next), walker);
            exitScope();
        }
        else if ((*next)->type == "MethodDeclaration")
        {
            Class *newRecord = new Class();
            auto child = (*next)->children.begin();
            newRecord->type = (*child)->value;
            child++;
            newRecord->id = (*child)->value;
            put(newRecord->id, newRecord);
            //std::cout << "Record: type: " << newRecord->type << " id: " << newRecord->id << std::endl;
            declared(newRecord->id);
            enterScope();
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
        std::cout << "Inserted\n";
        current->declarationCount.insert({key, 1});
    }
    else
    {
        std::cout << "Duplicate found\n";
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
void symbolTable::listDuplicates()
{
    
}

void symbolTable::listDuplicatesRec(scope *ptr)
{
    
}
