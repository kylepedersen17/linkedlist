#include <iostream>
#include "LinkedList.h"

int main() {
    
    LinkedList ll;
    ll.prepend(25);
    ll.append(6);
    ll.append(8);
    std::cout << ll.length() << "\n";
    ll.display();
    ll.prepend(24);
    ll.display();
    std::cout << ll.length() << "\n";

    return 0;
}