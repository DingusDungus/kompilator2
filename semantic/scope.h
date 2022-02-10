#include <iostream>
#include <vector>
#include <map>

class record
{
public:
    std::string id;
    std::string type;
    void setValues(std::string p_id, std::string p_type)
    {
        id = p_id;
        type = p_type;
    }
};

class Class : public record
{
public:
    std::map<std::string, std::string> variables;
    std::map<std::string, std::string> methods;
};

class method : public record
{
public:
    std::map<std::string, std::string> parameters;
    std::map<std::string, std::string> methods;
};

class variable : public record
{
public:
};

class scope
{
private:
    int next = 0;
    scope *parent;
    std::vector<scope *> children;
    std::map<std::string, record *> records;

public:
    scope() {}
    scope(scope *parent) { this->parent = parent; }

    void put(std::string key, record *item)
    {
        records.insert({key, item});
    }

    scope *nextChild()
    {
        scope *nextChild;
        if (next >= children.size())
        {
            nextChild = new scope(this);
            children.push_back(nextChild);
        }
        else 
        {
            nextChild = children[next];
        }
        next++;
        return nextChild;
    }

    scope *Parent() { return parent; }

    record *lookup(std::string key)
    {
        if (records.count(key) == 1)
        {
            record *record = records.find(key)->second;
            return record;
        }
        else
        {
            if (parent == nullptr)
            {
                return nullptr;
            }
            else
            {
                return parent->lookup(key);
            }
        }
    }

    void resetScope()
    {
        next = 0;
        for (int i = 0;i < children.size();i++)
        {
            children[i]->resetScope();
        }
    }
};