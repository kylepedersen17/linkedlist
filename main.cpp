#include <iostream>
#include <string>
#include "LinkedList.h"
#include <sstream>

// #define QUICK_TEST


#ifdef QUICK_TEST

int main() {


    LinkedList<bool> ll1;
    size_t currLength = ll1.length();
    ll1.append(true);
    currLength = ll1.length(); //expect 1
    ll1.append(true);
    currLength = ll1.length(); //expect 2
    ll1.append(false); 

    currLength = ll1.length(); //expect 3
    ll1.remove(true);
    currLength = ll1.length(); //expect 2

    return 0;


}

#else
int main() {
    
    std::string user_input;

    LinkedList<int> ll;

    std::cout << "List 1 and List 2:'" << std::endl;

    while (true) {
        std::cout << "Enter a command (type 'exit' to quit): ";

        std::getline(std::cin, user_input);
        std::istringstream ss(user_input);
        std::string command;

        ss >> command;
        int val;

        if (command == "exit") {
            break;
        } else if (command == "append") {
            ss >> val;
            ll.append(val);
            ll.display();
        } else if (command == "length") {
            std::cout << ll.length() <<"\n";
        } else if (command == "head") {
            std::cout << ll.getHeadData() <<"\n";
        } else if (command == "empty") {
            bool isEmpty = ll.isEmpty();
            std::cout << (isEmpty ? "The list is empty" : "The list is not empty") << std::endl;
        } else if (command == "prepend") {
            ss >> val;
            ll.prepend(val);
            ll.display();
        } else if (command == "contains") {
            ss >> val;
            bool contains = ll.contains(val);
            if (contains) {
                std::cout << "Yes, " << val << " is in the list. \n";
            } else {
                std::cout << "No, " << val << " is not in the list. \n";
            }
        } else if (command == "clear") {
            ll.clear();
            std::cout << "Cleared list\n";
        } else if (command == "remove") {
            ss >> val;
            ll.remove(val);
            ll.display();
        } else if (command == "display") {
            ll.display();
        } else {
            std::cout << "Invalid command.\n";
        }
    }

    std::cout << "Program ended" << '\n';
    return 0;
}

#endif