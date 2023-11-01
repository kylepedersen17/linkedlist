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
        ~LinkedList() {}
        int getHeadData() {
            if (_head) return _head->getData(); 
            throw std::runtime_error("empty list!!!");
        }

    private:
        Node* _head;
};

int main() {
    
    LinkedList* ll = new LinkedList(4);

    std::cout << ll->getHeadData();

    return 0;
}