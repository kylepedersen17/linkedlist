#include "LinkedList.h"
#include <iostream>

template <typename T>
LinkedList<T>::Node::Node(T data) : _data(data), _next(nullptr) {}

template <typename T>
LinkedList<T>::Node::~Node() {}

template <typename T>
T& LinkedList<T>::Node::getData() { return _data; }

template <typename T>
const T& LinkedList<T>::Node::getData() const { return _data; }

template <typename T>
void LinkedList<T>::Node::setData(T data) {_data = data; }

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::Node::getNext() { return _next; }

template <typename T>
void LinkedList<T>::Node::setNext(Node* next) {_next = next;}

template <typename T>
LinkedList<T>::LinkedList() : _head(nullptr) {}

template <typename T>
LinkedList<T>::LinkedList(T headData) : _head(new Node(headData)) {}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& other) {
    _head = nullptr;
    Node* current = other._head;
    while (current) {
        this->append(current->getData());
        current = current->getNext();
    }
}

template <typename T>
LinkedList<T>::~LinkedList() {
    while (_head) {
        Node* toDelete = _head;
        _head = _head->getNext();
        // std::cout << "Deleting node from LL" << "\n";
        delete toDelete;
    }
}

template <typename T>
T LinkedList<T>::getHeadData() const {
    if (_head) return _head->getData(); 
    throw std::runtime_error("empty list!!!");
}

template <typename T>
void LinkedList<T>::append(T val) { 
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

template <typename T>
void LinkedList<T>::display() const {
    if (isEmpty()) {
        std::cout << "Empty list" << std::endl;
        return;
    }
    Node* current = _head;
    while (current) {
        std::cout << current->getData() << " -> ";
        current = current->getNext();
    }
    std::cout << "X \n";
}

template <typename T>
size_t LinkedList<T>::length() const {
    Node* current = _head;
    int count = 0;
    while (current) {
        count++;
        current = current->getNext();
    }
    return count;
}

template <typename T>
bool LinkedList<T>::isEmpty() const {return _head == nullptr;}

template <typename T>
void LinkedList<T>::prepend(T val) {
    Node* nextNode = new Node(val);
    nextNode->setNext(_head);
    _head = nextNode;
}

template <typename T>
bool LinkedList<T>::contains(T val) {
    LinkedList<T>::Node* current = _head;
    while (current) {
        T data = current->getData();
        if (data == val) return true;
        current = current->getNext();
    }
    return false;
}

template <typename T>
void LinkedList<T>::clear() {
    LinkedList<T>::Node* current = _head;
    LinkedList<T>::Node* next = nullptr;

    while (current) {
        next = current->getNext();
        delete current;
        current = next;
    }
    _head = nullptr;
}

template <typename T>
void LinkedList<T>::remove(T val) {
    Node* prev = nullptr;
    Node* current = _head;
    while (current) {
        if (current->getData() == val) { 
            if (prev == nullptr) { //head node
                _head = current->getNext();
            } else {
                prev->setNext(current->getNext());
            }
            delete current;
            return;
        }
        prev = current;
        current = current->getNext();
    }
    std::cout << val << " not in list. \n";
}

template <typename T>
T& LinkedList<T>::operator[](int index) {
    int count = 0;
    Node* current = _head;
    while (current) {
        if (count == index) return current->getData();
        count++;
        current = current->getNext();
    }
    throw std::out_of_range("index out of range");
}

template <typename T>
bool LinkedList<T>::operator==(const LinkedList<T>& other) const {
    Node* current = _head;
    Node* otherCurrent = other._head;
    while (current && otherCurrent) {
        if (current->getData()!= otherCurrent->getData()) return false;
        current = current->getNext();
        otherCurrent = otherCurrent->getNext();
    }
    return current == nullptr && otherCurrent == nullptr;
}

template <typename T>
bool LinkedList<T>::operator!=(const LinkedList<T>& other) const {
    return!(*this == other);
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other) {
    if (this!= &other) {
        clear();
        Node* current = other._head;
        while (current) {
            append(current->getData());
            current = current->getNext();
        }
    }
    return *this;
}

template <typename T>
LinkedList<T>::LinkedList(LinkedList<T>&& other) noexcept {
    _head = other._head;
    other._head = nullptr;
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T>&& other) noexcept {
    if (this != &other) {
        clear();                       
        _head = other._head;          
        other._head = nullptr;     
    }
    return *this;
}
