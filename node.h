#ifndef NODE_H
#define NODE_H

/* Node type class*/

#include <iostream>
#include <vector>
#include <stdlib.h>

class Node
{
private:
    int number;
    bool permission;
    Node* parent;
    std::vector<Node*> childlist;
    
public:
    Node();
    bool getPermision();
    void setPermision(bool); // once permission is explicitly defiend
    void setPermission();    // no permision explicitly defined parrent's permision inheritance
    void setParent(Node*);
    void setChild(Node*);
    void setNumber(int);
    //Node* getParent();         //finds belonging parent
    Node* getChild();          //finds belonging parent

    int getNumber();
//    Node* addChild(Node * n, int number);

};

#endif // Node