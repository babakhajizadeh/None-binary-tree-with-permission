#include "parse.h"

Node* Parse::creatNode(int id, bool permission)
{
    node_obj = new Node;
    node_obj->setId(id);
    //check if we're not created the root node yet
    if (this->allnodeslist.empty()){ // root node
        node_obj->setPermision(true);// root node is always accessable
        if (!permission) std::cout << " [!] Root permission must be always true\n";
    else{ // we'e already in sub tree nodes
        

    }

}