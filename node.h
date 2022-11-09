#ifndef NODE_H
#define NODE_H

/* Node type class*/

#include <iostream>
#include <vector>
#include <stdlib.h>

class Node
{
private:
    int number;             // a node's numerical value
    bool permission;        // a node's bollean permision
    std::vector<Node*> childlist;
                             // vector of pinters to children nodes
public:
    Node();
    void setPermision(bool); // set permission once permission is explicitly defiend
    void setPermission();    // set permision when explicitly defined, parrent's permision inheritance
    void setChild(Node*);    // creats a child for a node
    void setNumber(int);     // set a node's value
    bool getPermision();     // reads a node permision    
    Node* getChild(int);     //find a specific child  
    int getNumber();         //reads a node's numerical value
};

#endif // Node