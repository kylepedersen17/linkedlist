#pragma once

#include <iostream>

class LinkedList {

    private:
        class Node {
            public:
                Node(int data);
                ~Node();

                int getData();
                void setData(int data);
                Node* getNext();
                void setNext(Node* next);

            private:
                int _data;
                Node* _next;
                
        };

    public:
        LinkedList();
        LinkedList(int headData);
        ~LinkedList();
        int getHeadData() const;
        void append(int val);
        void display() const;
        int length() const;
        bool isEmpty() const;
        void prepend(int val);
        Node* find(int val); 

    private:
        Node* _head;      
};