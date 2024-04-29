#include "btree.hpp"
#include "linkedlist.hpp"
#include "mainHelper.cpp"

#ifndef MAIN_CPP
#define MAIN_CPP


int main(){
    AVLTree* userTree = new AVLTree();
    linkedlist* userList = new linkedlist();
    string fileName = "fakePersonData.csv";

    loadLinkedList(fileName, userList);
    loadAVL(fileName, userTree);



   int userChoice = -1;
   int amountOfRotations = 1;

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
                cout << "still working on this shi";
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