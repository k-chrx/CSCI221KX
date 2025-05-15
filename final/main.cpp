#include <iostream>
#include <fstream>
#include <string>
#include "linkedlist.hpp"
#include "node.hpp"
#include <vector>
#include <limits>
using namespace std;
int main(){
    //create linked lists holding poems for each category
    LinkedList Sad("Sad");
    LinkedList Happy("Happy");

    //loop through files in the Happy category to add them into the Happy linkedlist
    ifstream poem_file;
    poem_file.open("Happy_files.txt");
    if(poem_file.fail()){
        cout<< "Could not open file"<<endl;;
        return 0;
    }
    string poem_txt_name;
    while(!poem_file.eof()){
        getline(poem_file, poem_txt_name);
        Happy.insert(poem_txt_name);
    }
    poem_file.close();
    //loop through files in the Sad category to add them into the Sad linkedlist
    poem_file.open("Sad_files.txt");
    if(poem_file.fail()){
        cout<< "Could not open file"<<endl;;
        return 0;
    }
    while(!poem_file.eof()){
        getline(poem_file, poem_txt_name);
        Sad.insert(poem_txt_name);
    }
    poem_file.close();

    //create vector with categories. These will be LinkedLists
    vector<LinkedList> category = {Happy, Sad};

   //give user the avaliable poems
    cout << "These are the current categories we have right now:" << endl;
    for(unsigned int i=0; i<category.size(); i++){
        cout << category[i].getCat() <<endl;
    }
    
    //create catname string to store the category
    string catname;
    //create txt_name to store file name for reading later
    string txt_name;
    
    //loop through category vector and see if user input is valid
    bool Valid_Category = false;
    int vec_index;
    while(Valid_Category == false){
   
        //ask user what they would like to browse
        cout << "Which category would you like to browse or add to? Please type in category exactly as listed!" << endl; 
        cin >> catname;
       
        //loops through vector and compares user input to elements in list
        for(unsigned int i=0; i<category.size(); i++){
            if(catname == category[i].getCat()){
                vec_index = i;
                Valid_Category = true;
            }
        }
        //ask user to input a valid response if their response is not in the list.
        if (Valid_Category == false){
            cout << "Please input a valid category. Here are the avaliable categories again: " << endl;
            for(unsigned int i=0; i<category.size(); i++){
                cout << category[i].getCat() <<endl;
            }
        }
        
    }
    //Asks the user whether they would like to browse or insert into the library.
    int BI_choice=0;
    cout << "Choose to either add a new poem or read a peom in this category. Type in 1 to add a new poem. Type in 2 to read a poem." <<endl;
    cin >> BI_choice;
    //This helps to fix errors caused by inputting non-integers
    if(cin.fail()){
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    //Asks user to put in valid response if they didn't
    while( (BI_choice !=1) && (BI_choice !=2) ){
        cout<<"Please put in a valid response! Here are your choices again: Type in 1 to add a new poem or type in 2 to read a poem from this category."<<endl;
        cin >> BI_choice;
        if(cin.fail()){
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

//ADD TO LIBRARY FUNCTION
    if(BI_choice == 1){
        ofstream insert_txt;
        //stores poem lines
        string insert_PL;
        //stores txt file name
        string insert_txt_name;
        
        //stores a bool to end the while loop inserting lines into the txt file
        bool dont_exit = true;

        insert_txt_name = insert_txt_name + ".txt";
        
        //will check if file already exists in the indicated category file
        ifstream check_similiar;
        string check_txt;
        bool check = true;
        
        while(check==true){
            check_similiar.open(category[vec_index].getCat()+"_files.txt");
            check = false;
            cout << "Give the file of your poem a name (No spaces as this will mess up the program!). This should be different from the poem's name: "<<endl;
            cin >> insert_txt_name;

            //cin.ignore fixes issue of the first getline() getting skipped
            cin.ignore();
            insert_txt_name = insert_txt_name + ".txt";
            while(!check_similiar.eof()){
                getline(check_similiar, check_txt);
                if (check_txt == insert_txt_name){
                    cout << "A poem already has that file name, please choose another!" << endl;
                    check = true;
                }
            
            }
            check_similiar.close();
        }
        //inserts line with title and author's name into the created poem
        string insert_title;
        string insert_author;
        insert_txt.open(insert_txt_name);
        //create first line with name of poem and author
        cout << "Now type in the title of the poem" << endl;
        //getline() is used to get the whole title and name of the author
        getline(cin, insert_title);
        cout << "Now type in the author's name" <<endl;
        getline(cin, insert_author);
        insert_PL = insert_title + " " + "-" +" by "+ insert_author;
        insert_txt << insert_PL<<endl;
        insert_txt <<endl;
        cout <<"Now type in each line of the poem. Press enter when you are done with one line so you can put in the next. Type in exit_insert when you are done."<<endl;
        
        while(dont_exit){
            //stores the poem line the user inputs
            getline(cin, insert_PL);
            if(insert_PL == "exit_insert"){
                dont_exit = false;
            }
            else insert_txt << insert_PL<<endl;
        }
        insert_txt.close();
        //appends the file of the poem to one of the indicated list files
        insert_txt.open(category[vec_index].getCat()+"_files.txt", ios::app);
        insert_txt << endl<<insert_txt_name;
        cout<< "Your new poem has been added! Start the program up again and you'll be able to read the newly added addition!"<<endl;
    }

//BROWSE FUNCTION
    if(BI_choice==2){
        //print out the first line of each poem in the list
        cout<< "These are the poems in the "<< category[vec_index].getCat() << " category:"<<endl;
        category[vec_index].printTitles();
        cout<<endl;

        int poem_num=-1;
        //loop this until user puts in a valid results
        while( (poem_num < 0) || (poem_num > category[vec_index].size()) ){
                    
            cout<< "Type in the number associated with the poem you want to read to read it. Type in 0 to exit out of the program."<<endl;
            cin >> poem_num;
            if(cin.fail()){
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                poem_num = -1;
            }

            if(poem_num ==0){
                cout<<"exiting program!"<<endl;
                return 0;
            }
        }
        //makes the program output look neater
        cout <<endl;
        //Add code that prints out the content of the poems.
        poem_txt_name = category[vec_index].getTxtName(poem_num);
        poem_file.open(poem_txt_name);
        if(poem_file.fail()){
            cout<< "Could not open file"<<endl;;
            return 0;
        }
        string poem_line;
        while(!poem_file.eof()){
            getline(poem_file, poem_line);
            cout << poem_line<<endl;
        }
        poem_file.close();
    }
return 0;
}