#ifndef NODE_H
#define NODE_H

/* Node type class*/

#include <iostream>
#include <vector>
#include <stdlib.h>

class Node
{
private:
    int id;                 // a node's numerical value
    std::string permission;        // a node's permision
    /* true has access
       false will be denied
       not_set inherits from parent.
    */
    Node* parent;
    std::vector<Node*> childlist;
                             // vector of pinters to children nodes
public:
    /* default constructor */
    Node();
    void setId(int input_id);      /* set a node's value */
    /* set permission once permission is explicitly defiend */
    void setPermision(std::string explicit_permision); 
    /* set permision when no exolicit permision defined 
    so parent permission applied*/
    void setParent(Node* input_parent);    // set a parent for node
    void setChild(Node* input_child);      // sets a child for a node
    std::string getPermission();                   // reads a node permision    
    Node* getChild(int id);                //find a specific child  
    int getId();                           //reads a node's numerical value
};

#endif // 