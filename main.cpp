#include "btree.hpp"
#include "linkedlist.hpp"

#ifndef MAIN_CPP
#define MAIN_CPP

void displayMenu();
void loadLinkedList(string fileName, linkedlist* userList);
void loadAVL(string fileName, AVLTree* userTree);

int main(){
    AVLTree* userTree = new AVLTree();
    linkedlist* userList = new linkedlist();
    string fileName = "fakePersonData.csv";

    loadLinkedList(fileName, userList);
    loadAVL(fileName, userTree);


 /*   int userChoice = -1;

    do{
        displayMenu();
        cin >> userChoice;
        switch(userChoice){
            case 1:
                break;
            case 2:
                break;
            case 3: 
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            default: 
        }
    }while(userChoice != 6);

    return 0;

*/

}



void displayMenu(){
    cout << "Select an action to execute: \n\n";
    cout << "1. Add student.\n";
    cout << "2. Remove student.\n";
    cout << "3. Search student by ID.\n";
    cout << "4. Search student by name.\n";
    cout << "5. Update student info.\n";
    cout << "6. Exit.\n";
    cout << "\nEnter selection: ";
}


void loadLinkedList(string fileName, linkedlist* userList){
    ifstream fileStream(fileName);

    if(!fileStream.is_open()){
        cout << "Could not open the file\n";
        return;
    }
    
    string currLine;
    while(getline(fileStream, currLine)){
        vector<string> dataMembers;
        string token;
        stringstream sStream(currLine);
        while (getline(sStream, token, ',')){
            dataMembers.push_back(token);
        }

        listMember* newMember = new listMember(stoi(dataMembers.at(0)), dataMembers.at(1), dataMembers.at(2), dataMembers.at(3), dataMembers.at(4), dataMembers.at(5), stoi(dataMembers.at(6)));
        userList->insert(newMember);
    }
    
    fileStream.close();
}

void loadAVL(string fileName, AVLTree* userTree){
    ifstream fileStream(fileName);

    if(!fileStream.is_open()){
        cout << "Could not open the file\n";
        return;
    }

    string currLine;
    while(getline(fileStream, currLine)){
        vector<string> dataMembers;
        string token;
        stringstream sStream(currLine);

        while (getline(sStream, token, ',')){
            dataMembers.push_back(token);
        }

        TreeMember* newMember = new TreeMember(stoi(dataMembers.at(0)), dataMembers.at(1), dataMembers.at(2), dataMembers.at(3), dataMembers.at(4), dataMembers.at(5), stoi(dataMembers.at(6)));
        TreeMember* throwAway = userTree->insert(userTree->get_root(), newMember);

    }
    
    fileStream.close();
}


#endif