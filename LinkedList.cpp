#include "LinkedList.h"
#include <iostream>

LinkedList::Node::Node(int data) : _data(data), _next(nullptr) {}
LinkedList::Node::~Node() { std::cout << "Deleting node " << _data << std::endl; }

int LinkedList::Node::getData() { return _data; }
void LinkedList::Node::setData(int data) {_data = data; }
LinkedList::Node* LinkedList::Node::getNext() { return _next; }
void LinkedList::Node::setNext(Node* next) {_next = next;}


LinkedList::LinkedList() : _head(nullptr) {}
LinkedList::LinkedList(int headData) : _head(new Node(headData)) {}

LinkedList::~LinkedList() {
    while (_head) {
        Node* toDelete = _head;
        _head = _head->getNext();
        std::cout << "Deleting node from LL" << "\n";
        delete toDelete;
    }
}

int LinkedList::getHeadData() const {
    if (_head) return _head->getData(); 
    throw std::runtime_error("empty list!!!");
}

void LinkedList::append(int val) { 
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

void LinkedList::display() const {
    Node* current = _head;
    while (current) {
        std::cout << current->getData() << " ";
        current = current->getNext();
    }
    std::cout << "\n";
}

int LinkedList::length() const {
    Node* current = _head;
    int count = 0;
    while (current) {
        count++;
        current = current->getNext();
    }
    return count;
}

bool LinkedList::isEmpty() const {
    return _head == nullptr;
}

void LinkedList::prepend(int val) {
    Node* nextNode = new Node(val);
    nextNode->setNext(_head);
    _head = nextNode;
}

LinkedList::Node* LinkedList::find(int val) {
    Node* current = _head;
    while (current) {
        int data = current->getData();
        if (data == val) return current;
        current = current->getNext();
    }
    return nullptr;
}

// void LinkedList::remove(int val) {
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
