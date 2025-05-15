#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H
#include <string>
#include "node.hpp"
using namespace std;

class LinkedList {
    public:
        Node *head;
		string category;

		// constructor
        LinkedList(string cat); 
        
		/*
		//destructor
		~LinkedList();
		*/

        int size(); 

		void delete_node(string name);

		void insert(string val);

        bool isEmpty(); 

		void print_last();

		void printList();

		string getCat();

		string getTxtName(int num);

		void printTitles();



}; // end class


#endif