#include <iostream>
#include <memory>


class LinkedList {

    private:
        class Node {
            public:
                Node(int data, Node* next = nullptr) : _data(data), _next(next) {}
                ~Node() { std::cout << "Deleting node " << _data << std::endl; }

                int getData() { return _data; }
                void setData(int data) {_data = data; }
                Node* getNext() { return _next; }
                void setNext(Node* next) {_next = next;}

            private:
                int _data;
                Node* _next;
                
        };

    public:
        LinkedList() : _head(nullptr) {}
        LinkedList(int headData) : _head(new Node(headData)) {}
        ~LinkedList() {
            while (_head) {
                Node* toDelete = _head;
                _head = _head->getNext();
                std::cout << "Deleting node from LL" << "\n";
                delete toDelete;
            }
        }
        int getHeadData() {
            if (_head) return _head->getData(); 
            throw std::runtime_error("empty list!!!");
        }
        void append(int val) { 
            Node* nextNode = new Node(val);
            if (!_head) {
                _head = nextNode;
            } else {
                Node* current = _head;
                while (current->getNext()) {
                    current = current->getNext();
                }
                current->setNext(nextNode);
            }
        }
        void display() {
            Node* current = _head;
            while (current) {
                std::cout << current->getData() << " ";
                current = current->getNext();
            }
            std::cout << "\n";
        }
    private:
        Node* _head;
};

int main() {
    
    LinkedList ll;
    ll.append(6);
    ll.append(8);
    ll.display();


    return 0;
}