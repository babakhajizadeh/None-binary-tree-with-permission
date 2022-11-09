#include "node.h"

Node::Node()
{
    id = 0;
    permission = false;
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

void Node::setPermission(Node* root)
{
    int m_id = this->id;
    for (auto & node_obj : root->childlist){
    //here we go...breadth travers algorithm
    }
}

void Node::setId(int input_id)
{
    this->id = input_id;
}

int Node::getId()
{
    return this->id;
}

void Node::setChild(Node* input_child)
{

}
