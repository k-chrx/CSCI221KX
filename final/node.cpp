// node.cpp

#include "node.hpp"
#include <string>
using namespace std;
//Note to prof Johnson: we discussed this over email and you said the Node class does not need a destructor.
        Node::Node(string initdata) {
                data = initdata; //the initialized data is set as the head
                next = nullptr; //the next node is set as NULL, as there is no next node yet.
        }

        string Node::getData() { //function that return data of a given node.
                return data;
        }

        Node * Node::getNext() { // pointer that gets the next node
                return next;
        }

        void Node::setData(string newData) { // sets data in node
                data = newData;
        }

        void Node::setNext(Node *newnext) {
                next = newnext;
        }
