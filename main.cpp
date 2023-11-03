#include <iostream>


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

        int getHeadData() const {
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

        void display() const {
            Node* current = _head;
            while (current) {
                std::cout << current->getData() << " ";
                current = current->getNext();
            }
            std::cout << "\n";
        }

        int length() const {
            Node* current = _head;
            int count = 0;
            while (current) {
                count++;
                current = current->getNext();
            }
            return count;
        }

        bool isEmpty() const {
            return _head == nullptr;
        }

        void prepend(int val) {
            Node* nextNode = new Node(val);
            nextNode->setNext(_head);
            _head = nextNode;
        }

        Node* find(int val) {
            Node* current = _head;
            while (current) {
                int data = current->getData();
                if (data == val) return current;
                current = current->getNext();
            }
            return nullptr;
        }

        // void remove(int val) {
        //     Node* prev = nullptr;
        //     Node* current = _head;
        //     while (current) {
        //         if (current->getData() == val) {
        //             prev->setNext(current->getNext());
        //             delete current;
        //             return;
        //         }
        //         prev = current;
        //         current = current->getNext();
        //     }
        // }

    private:
        Node* _head;      
};

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