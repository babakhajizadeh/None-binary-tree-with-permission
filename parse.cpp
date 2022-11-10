#include "parse.h"

bool Parse::parseNode(int id, bool permission) //Node already created only permission operation
{
    Node* m_currentNode;
    //check if we're not created the root node yet
    if (allnodes.empty()) // root node
    { 
        node_obj->setPermision(true);// root node is always accessable
        if (!permission){ 
            std::cout << " [!] Invalid imput; The root permission must be always true\n";
            return false;
        }
    }
    else // sub-tree nodes
    { 
        Node* m_currentNode = NULL;
        for(auto node : allnodes) //finds nodes with id
        {
            if (node->getId() == id) m_currentNode = node; 
        }
        if (m_currentNode == NULL) std::cout << " [!] Node not found, Id not Exist";
        m_currentNode->setPermision(permission); //set permision to founded node
        return true;  
    }
}

bool Parse::parseNode(int id, int parent_id) 
{
    node_obj = new Node;
    node_obj->setId(id);
    Node* m_currentParent;
    if (allnodes.empty()){
        std::cout << " [!] Invalid input; The root has not defined.";
        return flase;
        
    }

}