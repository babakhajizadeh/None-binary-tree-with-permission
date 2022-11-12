#include "node.h"

Node::Node()
{
    id = 0;
    permission = "not_set"; //defualt permission
    Node* parent = NULL;
    std::vector<Node*> childlist = {};
}

void Node::setId(int input_id)
{
    this->id = input_id;
}

void Node::setPermision(std::string explicit_permision)
{
    this->permission = explicit_permision;
}

void Node::setParent(Node* input_parent)
{
    this->parent = input_parent;
}

void Node::setChild(Node* input_child)
{
    this->childlist.push_back(input_child);
}

std::string Node::getPermission()
{
    if (this->permission != "not_set")
        return this->permission;
    else return parent->getPermission();
}

int Node::getId()
{
    return this->id;
}
