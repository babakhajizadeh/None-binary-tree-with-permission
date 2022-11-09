#include "node.h"

Node::Node()
{
    number = 0;
    permission = false;
    Node* parrent = NULL;
    std::vector<Node*> childlist = {};
}

bool Node::getPermision()
{
    return permission;
}

void Node::setPermision(bool explicit_permision)
{
    this->permission = explicit_permision;
}

void Node::setPermission()
{
    this->permission = parent->permission;
}

void Node::setNumber(int input_number)
{
    this->number = input_number;
}

int Node::getNumber()
{
    return this->number;
}
void Node::setParent(Node* input_parent)
{
    this->parent = input_parent;
}
void Node::setChild(Node* input_child)
{
    this->parent = input_child;
}
Node* Node::getParent();
{
    return this->parent;
}
