#include <regex>
#include "parse.h"

bool Parse::parseNode(int id, std::string permission) //Node already created only permission operation
{
    Node* m_currentNode = NULL;
    for(auto node : allnodes) //finds nodes with id
    {
        if (node->getId() == id)
        { 
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


bool Parse::parseNode(int id, int parent_id) 
{
    // check if there is root
    if (allnodes.empty()){
        Node* root = new Node;
        root->setId(1);
        root->setPermision("true");
        allnodes.push_back(root);
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
    allnodes.push_back(node_obj);
    return true;
}

bool Parse::init()
{
    std::cout << " [i] input raw string containing menu sequences\n";
    std::cout << " [example] (2,1),(3,1),(4,1),(5,2),(6,2),(2,false),(7,3)\n";
    std::cout << "input:";
    std::getline(std::cin, raw);
    std::regex re("[\\)(,]");
    std::sregex_token_iterator first{raw.begin(), raw.end(), re, -1}, last;
    std::vector<std::string> tokens{first, last};
    for (std::string element : tokens) {
        if (element == "") continue;
        node_string.push_back(element);
    }
    for(int i = 0;i < node_string.size();i++)
    {
        if (node_string[i+1] == "true"){
            std::cout << " [ l 72 debug parsenode() is called with " << std::stoi(node_string[i])
                      << " and " << "true" << std::endl;
            init_status = parseNode(std::stoi(node_string[i]),"true");
            i++;
            continue;
        }
        if (node_string[i+1] == "false"){
            std::cout << " [ l 79 debug parsenode() is called with " << std::stoi(node_string[i])
                      << " and " << "false" << std::endl;
            init_status = parseNode(std::stoi(node_string[i]),"false");
            i++;
            continue;
        }
        std::cout << " [ l 85 debug parsenode() is called with " << std::stoi(node_string[i])
                  << " and " << stoi(node_string[i+1]) << std::endl;
        init_status = parseNode(std::stoi(node_string[i]),stoi(node_string[i+1]));
        i++;
    }
    return true;
}

void Parse::display()
{
    for(auto node : allnodes){
        if (node->getPermission() == "true") std::cout << " [i] sub-menu " << node->getId() 
                                                     << " is accessed.\n"; 
        if (node->getPermission() == "false") std::cout << " [i] sub-menu " << node->getId() 
                                                     << " is denied.\n";
    }
}