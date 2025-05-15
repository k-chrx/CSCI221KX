#ifndef _NODE_H_
#define _NODE_H_
#include <string>
using namespace std;

//creates a node class that holds an integer for its data
class Node {
    //defines data, and next as a pointer.
    private:
        string data; //data in the beginning node
        Node *next; //pointer to the next node

    public:
        Node(string initdata);

        string getData();

        Node *getNext();

        void setData(string newData);

        void setNext(Node *newnext);
        
}; // end Node class


#endif