//This is the main file that creates a linked list and AVL tree full of 
//fake members for the user to view, manipulate, and evaluate time complexity. 

#include "btree.hpp"
#include "linkedlist.hpp"
#include "mainHelper.cpp"

#ifndef MAIN_CPP
#define MAIN_CPP


int main(){
    AVLTree* userTree = new AVLTree(); //Tree structure
    linkedlist* userList = new linkedlist(); //Linked List structure
    string fileName = "fakePersonData.csv";

    //Load both structures
    loadLinkedList(fileName, userList); 
    loadAVL(fileName, userTree);



   int userChoice = -1;
   int amountOfRotations = 1;

    //Menu selection 
    do{
        amountOfRotations++;
        displayMenu();
        cout << "\nEnter selection: ";
        cin >> userChoice;

        switch(userChoice){
            case 1://insert
                insert_into_structures(userTree, userList, amountOfRotations);
                break;
            case 2://remove
                remove_from_structures(userTree, userList);
                break;
            case 3://ID search
                search_with_ID(userTree, userList);
                break;
            case 4://Name search
                search_with_name(userTree, userList);
                break;
            case 5://update
                update_member(userTree, userList);
                break;
            case 6://exit
                break;
            default: 

                cout << "Invalid input try again\n";
        }
    }while(userChoice != 6);

    return 0;

}


#endif
