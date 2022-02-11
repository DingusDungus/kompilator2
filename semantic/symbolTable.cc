#include "symbolTable.h"

void symbolTable::stBuilderRec(Node *walker, Node *parent)
    {
        auto next = walker->children.begin();
        std::cout << walker->value << std::endl;
        while (next != walker->children.end())
        {
            if ((*next)->type == "VarDeclaration")
            {
                variable *newRecord = new variable();
                auto child = (*next)->children.begin();
                newRecord->type = (*child)->children.front()->value;
                child++;
                newRecord->id = (*child)->children.front()->value;
                put(newRecord->id, newRecord);
                next++;
            }
            else if ((*next)->type == "MainClass")
            {
                Class *newRecord = new Class();
                auto child = (*next)->children.begin();
                newRecord->id = (*child)->children.front()->value;
                newRecord->type = "MainClass";
                put(newRecord->id, newRecord);
                enterScope();
                stBuilderRec((*next), walker);
                next++;
                exitScope();
            }
            else if ((*next)->type == "PublicMainMethod")
            {
                method *newRecord = new method();
                auto child = (*next)->children.begin();
                newRecord->id = "main";
                newRecord->type = "PublicMainMethod";
                newRecord->parameters.insert({(*child)->children.front()->value, "String"});
                put(newRecord->id, newRecord);
                enterScope();
                stBuilderRec((*next), walker);
                next++;
                exitScope();
            }
            else if ((*next)->type == "ClassDeclaration")
            {
                Class *newRecord = new Class();
                auto child = walker->children.begin();
                newRecord->id = (*child)->children.front()->value;
                newRecord->type = "Class";
                put(newRecord->id, newRecord);
                enterScope();
                stBuilderRec((*next), walker);
                next++;
                exitScope();
            }
            else if ((*next)->type == "MethodDeclaration")
            {
                Class *newRecord = new Class();
                auto child = (*next)->children.begin();
                newRecord->type = (*child)->children.front()->value;
                child++;
                newRecord->id = (*child)->children.front()->value;
                put(newRecord->id, newRecord);
                enterScope();
                stBuilderRec((*next), walker);
                next++;
                exitScope();
            }
            stBuilderRec((*next), walker);
            next++;
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