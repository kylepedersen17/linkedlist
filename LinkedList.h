#pragma once
#include <iostream>

template <typename T>
class LinkedList {
    public:
        class Node {
            public:
                Node(T data);
                ~Node();
                Node(const Node& other);

                T& getData();
                const T& getData() const;
                void setData(T data);
                Node* getNext();
                void setNext(Node* next);

            private:
                T _data;
                Node* _next;
        };

    public:
        LinkedList();
        LinkedList(T headData);
        LinkedList(const LinkedList& other); // copy constructor
        LinkedList(LinkedList<T>&& other) noexcept; //move constructor
        ~LinkedList();
        
        // class methods
        T getHeadData() const;
        void append(T val);
        void display() const;
        size_t length() const;
        bool isEmpty() const;
        void prepend(T val);
        bool contains(T val); 
        void remove(T val);
        void clear();

        //operator overloads
        T& operator[](int index);
        bool operator==(const LinkedList<T>& other) const;
        bool operator!=(const LinkedList<T>& other) const;
        LinkedList<T>& operator=(const LinkedList<T>& other);
        LinkedList<T>& operator=(LinkedList<T>&& other) noexcept;

    private:
        Node* _head;      
};

 #include "LinkedList.inl"