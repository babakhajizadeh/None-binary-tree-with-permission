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
    permission = explicit_permision;
}

void Node::setPermission()
{
    permission = parrent->permission;
}

void Node::setNumber(int input_number)
{
    number = input_number;
}

int Node::getNumber()
{
    return number;
}
