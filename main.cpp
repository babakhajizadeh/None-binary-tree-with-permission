#include "parse.h"

int main()
{
    bool status; //if any error
    Parse* run = new Parse;
    status = run->init();
    if (!status) std::cout << " [!]Program has encountered Error(s).Exits\n";
    else run->display();
    return 0;
}
