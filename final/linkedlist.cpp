#include <iostream>
#include "node.hpp"
#include "linkedlist.hpp"
#include <fstream>
#include <string>
using namespace std;

        LinkedList::LinkedList(string cat) {
            head = NULL;
            category = cat;
        }
        
        // should make a destructor that traverses the list and deletes all of the nodes
        // and then sets the head back to NULL
       /* NOTE: destructor did not work. We discussed this on friday, the work day, in class. Gives "free(): invalid pointer" error.
        LinkedList::~LinkedList() {
            Node * current = head;
            Node * temp = NULL;
            category = "";
            cerr<<"a"<<endl;
            if (current == NULL) {
                cerr<<"b"<<endl;
                return;             // list is already empty
            } 
            
            if (current->getNext() == NULL) { // single element list
                cerr<<"c"<<endl;
                delete current;
                cerr<<"d"<<endl;
                head = NULL;
                cerr<<"e"<<endl;
                return;
            } 
            
            while (current->getNext() != NULL) {
                cerr<<"f"<<endl;
                temp = current->getNext();
                cerr<<"g"<<endl;
                delete current;
                cerr<<"h"<<endl;
                current = temp;
            }
            
        
        }  // destructor
        */
        
        // counts the elements in the list
        int LinkedList::size() {
            Node *current = head;
            int count = 0;
            while(current != NULL){
                count++;
                current = current->getNext();
            }
            return count;
        }
        
        // locates the node containing the name and deletes it
        // remember to release the memory the Node is using
        void LinkedList::delete_node(string name) {
            Node *temp = head;
            //for if list is empty
            if(temp == NULL){
                cout<<"list is empty." <<endl;
                return;
            }
            //for if head has indicated name to be deleted
            else if(temp->getData()== name){
                head = head->getNext(); 
                delete temp;
                  return;
            }
            //otherwise traverse the list and find the node with the name in it to delete
            else {
                Node *pre_node = head; 
                while(temp->getData() !=name){
                    if(temp->getNext() == NULL){
                        cout << name <<  " does not exist in this list." <<endl;
                        return;
                    }
                    temp = temp->getNext();
                    if (temp->getData() == name){
                        pre_node->setNext(temp->getNext());
                        delete temp;
                        cout << name << " has been deleted." <<endl;
                        return;
                    }
                    pre_node = temp;
    
                }
            }
        }
    
        // Insert elements at the END of the list
        void LinkedList::insert(string val) {
            Node *temp = new Node(val);
            if(head == NULL){
                head = temp;
            }else{
                Node *current = head;
                while(current->getNext() != NULL){
                    current = current->getNext();
                }
                current->setNext(temp);
            }
        }
    
        // prints the data in the last node of the list
        void LinkedList::print_last() {
            Node *current = head;
            if(head==NULL){
                cout <<"list is empty" << endl;
                return;
            }
            while(current->getNext() != NULL){
                current = current->getNext();
            }
            cout << current->getData() <<endl;
            
        }
    
        void LinkedList::printList() {
            Node * current = head;
            if(head==NULL){
                cout <<"list is empty" << endl;
                return;
            }
            while (current != NULL) {
                cout << current->getData() << endl;
                current = current->getNext();
            }
        }
        //returns the name of the txt files
        string LinkedList::getTxtName(int num){
            Node * current = head;
            if(head==NULL){
                cout <<"list is empty" << endl;
                return "";
            }
            for (int i=1; i<=num; i++){
                if(i==num){
                    return current->getData();
                }
                current = current->getNext();
            }
            return "error";
        }
        //gets the category from the linked list
        string LinkedList::getCat(){
            return category;
        }
        //prints the first line of each txt file, which should be the tittle and author.
        void LinkedList::printTitles(){
            Node*current = head;
            int i = 0;
            while(current != NULL){
                i++;
                ifstream input;
                input.open(current->getData());
                if(input.fail()){
                    cout<< "Could not open file"<<endl;;
                    return;
                }
                string title;
                getline(input,title);
                cout <<i <<". "<< title<< endl;
                current= current->getNext();
                input.close();
            }
        }