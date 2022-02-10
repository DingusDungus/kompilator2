#include "scope.h"
#include <iostream>
#include <vector>

class symbolTable
{
private:
    scope *root;
    scope *current;
public:
    symbolTable() {root = new scope(); }
    void enterScope() { current = current->nextChild(); }
    void exitScope() { current = current->Parent(); }
    void put(std::string key, record *item)
    {
        current->put(key, item);
    }
    record *lookup(std::string key)
    {
        return current->lookup(key);
    }
};