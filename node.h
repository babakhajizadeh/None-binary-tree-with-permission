#ifndef NODE_H
#define NODE_H

/* Node type class*/

#include <iostream>
#include <vector>
#include <stdlib.h>

class Node
{
private:
    int id;             // a node's numerical value
    bool permission;        // a node's bollean permision
    std::vector<Node*> childlist;
                             // vector of pinters to children nodes
public:
    /* default constructor */
    Node();
    /* set permission once permission is explicitly defiend */
    void setPermision(bool explicit_permision); 
    /* set permision when no exolicit permision defined 
    must navigate from root to node's parent */
    void setPermission(Node* root);
    void setChild(Node* child);      // creats a child for a node
    void setId(int input_id);      // set a node's value
    bool getPermision();             // reads a node permision    
    Node* getChild(int id);      //find a specific child  
    int getId();                 //reads a node's numerical value
};

#endif // Node