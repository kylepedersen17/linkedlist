#include <iostream>
#include <memory>

class Node {
    public:
        Node(int data, Node* next = NULL) : _data(data), _next(next) {}
        ~Node() { std::cout << "Deleting node " << _data << std::endl; }

        int getData() { return _data; }
        void setData(int data) {_data = data; }
        Node* getNext() { return _next; }
        void setNext(Node* next) {_next = next;}

    private:
        int _data;
        Node* _next;
        
};

class LinkedList {
    public:
        LinkedList() : _head(nullptr) {}
        ~LinkedList() {}
        Node* getHead() { return _head; }
        Node* getNext() { return _head->getNext();}

    private:
        Node* _head;
};

int main() {
    
    LinkedList ll;

    std::cout << ll.getHead();

    return 0;
}