#include <regex>
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
            if (node->getId() == id){ 
                m_currentNode = node;
                break;
            } 
        }
        if (m_currentNode == NULL) 
        { 
            std::cout << " [!] Error,Node not found, Id not Exist";
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
    if (id == parent_id)
    {
        std::cout << " [!] Error, a Node's id and it's parent's id can not be the same ";
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
    node_obj->setParent(m_currentParent);
    node_obj->setPermission(); //parent's permission will be used
}
void Parse::init()
{
    std::cout << " [i] input raw string containing menu sequences\n";
    std::cout << " [example] (2.1),(3,1),(4,1),(5,2),(6,2),(2,false),(7,3)\n";
    std::cout << "input:";
    std::getline(std::cin, raw);
    std::regex re("[\\)(,]");
    std::sregex_token_iterator first{raw.begin(), raw.end(), re, -1}, last;
    std::vector<std::string> tokens{first, last};
    for (std::string node_string : tokens) {
        if (node_string == "") continue;
        std::cout << node_string << std::endl;
    }
}