#include "node.h"

Node::Node()
{
    id = 0;
    permission = false;
    Node* parent = NULL;
    std::vector<Node*> childlist = {};
}

void Node::setId(int input_id)
{
    this->id = input_id;
}

void Node::setPermision(bool explicit_permision)
{
    this->permission = explicit_permision;
}

void Node::setPermission()
{
    this->permission = parent->getPermision();
}

void Node::setParent(Node* input_parent)
{
    this->parent = input_parent;
}

void Node::setChild(Node* input_child)
{
    this->childlist.push_back(input_child);
}

int Node::getId()
{
    return this->id;
}
