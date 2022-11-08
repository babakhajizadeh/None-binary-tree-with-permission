#ifndef NODE_H
#define NODE_H

/* Node type class*/

#include <vector>
#include <stdlib.h>

class Node
{
private:
    int number;
    bool permission;
    Node* parrent;
    std::vector<Node*> childlist;
    
public:
    Node();
    bool getPermision();
    void setPermision(bool); // once permission is explicitly defiend
    void setPermission();    // no permision explicitly defined parrent's permision inheritance
    
    void setNumber(int);
    int getNumber();
//    Node* addChild(Node * n, int number);

};

#endif // Node