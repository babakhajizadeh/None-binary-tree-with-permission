#include "parse.h"

Node* Parse::creatNode(int number, bool permission)
{
    node_obj = new Node;
    node_obj->setNumber(number);
    //check if we're not created the root node yet
    if (this->allnodeslist.empty()){ // root node
        node_obj->setPermision(true);// root node is always accessable
        if (!permission) std::cout << " [!] Root node must be always true\n";
        node_obj->setParent(NULL);
    else{ // we'e already in sub tree nodes
        

    }

}