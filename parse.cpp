#include "parse.h"

bool Parse::parseNode(int id, bool permission) //Node already created only permission operation
{
    //check if we're not created the root node yet
    if (allnodes.empty()) // there is no root yet, need to be created
    { 
        if (!permission or id != 1) // error. no root has defined
        { 
            std::cout << " [!] Invalid imput; The root permission or id is wrong\n";
            return false;
        }
        if (permission and id == 1) // root node creation
        {
            node_obj = new Node;
            node_obj->setId(1);
            node_obj->setPermision(true);// root node is always accessable
            allnodes.push_back(node_obj);
        }
    }
    else // sub-tree nodes, only permision needs to be set (explicitly)
    { 
        Node* m_currentNode = NULL;
        for(auto node : allnodes) //finds nodes with id
        {
            if (node->getId() == id) m_currentNode = node;
            break; 
        }
        if (m_currentNode == NULL) 
        { 
            std::cout << " [!] Node not found, Id not Exist";
            return false;
        }
        m_currentNode->setPermision(permission); //set permision to founded node
        return true;  
    }
}

bool Parse::parseNode(int id, int parent_id) 
{
    // check if there is root node
    if (allnodes.empty()){
        std::cout << " [!] Invalid input; The root has not defined.";
        return false;
    }
    node_obj = new Node;
    node_obj->setId(id);
    Node* m_currentParent;
    for (auto node : allnodes){
        if (node->getId() == parent_id)
        {
            m_currentParent = node;
            break;
        }
    }
    m_currentParent->setChild(node_obj);
    node_obj->setPermission(); //parent's permission will be used
}