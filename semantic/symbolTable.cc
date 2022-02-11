#include "symbolTable.h"

void symbolTable::stBuilderRec(Node *walker, Node *parent)
    {
        for (auto next = walker->children.begin();next != walker->children.end();next++)
        {
            if ((*next)->type == "VarDeclaration")
            {
                variable *newRecord = new variable();
                auto child = (*next)->children.begin();
                newRecord->type = (*child)->value;
                child++;
                newRecord->id = (*child)->value;
                put(newRecord->id, newRecord);
                std::cout << "Record: type: " << newRecord->type << " id: " << newRecord->id << std::endl;

            }
            else if ((*next)->type == "MainClass")
            {
                Class *newRecord = new Class();
                auto child = (*next)->children.begin();
                newRecord->id = (*child)->value;
                newRecord->type = "MainClass";
                put(newRecord->id, newRecord);
                std::cout << "Record: type: " << newRecord->type << " id: " << newRecord->id << std::endl;
                enterScope();
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
                std::cout << "Record: type: " << newRecord->type << " id: " << newRecord->id << std::endl;
                enterScope();
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
                std::cout << "Record: type: " << newRecord->type << " id: " << newRecord->id << std::endl;
                enterScope();
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
                std::cout << "Record: type: " << newRecord->type << " id: " << newRecord->id << std::endl;
                enterScope();
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
        current = root;
        for (auto i = current->records.begin();i != current->records.end();i++)
        {
            std::cout << "Record: type: " << i->second->type << " id: " << i->second->id << std::endl;
        }
        std::cout << std::endl;


    }