#ifndef PARSE_H
#define PARSE_H
#include "node.h" // includes iostream, vector and stdlib
 
class Parse
{
private:
    std::vector<std::string> node_string;
    std::string raw;
    Node* node_obj;
    std::vector<Node*> allnodes = {};
    bool init_status;

public:
    bool init();  //responsible to call proper parse method
    bool parseNode(int, int);
    bool parseNode(int, bool); // node is laready built
    void display();
};

#endif