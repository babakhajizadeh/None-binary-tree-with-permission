#ifndef PARSE_H
#define PARSE_H
#include "node.h"

class Parse
{
private:
    Node* node_obj;
    std::vector<Node*> allnodes = {};

public:
    bool parseNode(int, int);
    bool parseNode(int, bool); // node is laready built
};

#endif