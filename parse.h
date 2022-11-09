#ifndef PARSE_H
#define PARSE_H
#include "node.h"

class Parse
{
private:
    Node* node_obj;
    std::vector<Node*> allnodeslist = {};

public:
    Node* getParent();          //finds belonging parent
    Node* creatNode(int, int);
    Node* creatNode(int, bool);
};

#endif