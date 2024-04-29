#include "btree.hpp"
#include "linkedlist.hpp"

//#ifdef MAIN_HELPER_CPP
//#define MAIN_HELPER_CPP

void displayMenu(){
    cout << "Select an action to execute: \n\n";
    cout << "1. Add student.\n";
    cout << "2. Remove student.\n";
    cout << "3. Search student by ID.\n";
    cout << "4. Search student by name.\n";
    cout << "5. Update student info.\n";
    cout << "6. Exit.\n";
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
        userTree->update_root(userTree->insert(userTree->get_root(), newMember));

    }
    
    fileStream.close();
}


void insert_into_structures(AVLTree* userTree, linkedlist* userList, int amountOfRotations){

    int ID, zipcode;
    string name, birthDate, streetAddress, currentState, cityName;

    ID = 2000000 + amountOfRotations;
    cout << "Enter Name of Student to be added: ";
    getline(cin, name);
    cout << "Enter birth Date (YYYY-MM-DD): ";
    cin >> birthDate;
    cin.ignore();
    cout << "Enter street Address: ";
    getline(cin, streetAddress);
    cout << "Enter State of Residency: ";
    cin >> currentState;
    cout << "Enter City Name: ";
    cin.ignore();
    getline(cin, cityName);
    cout << "Enter zipcode (numeric only): ";
    cin >> zipcode;

    TreeMember* newTreeMember = new TreeMember(ID,name,birthDate,streetAddress,currentState,cityName,zipcode);
    
    listMember* newListMemeber = new listMember(ID,name,birthDate,streetAddress,currentState,cityName,zipcode);
    
    userList->insert(newListMemeber);
    userTree->update_root(userTree->insert(userTree->get_root(), newTreeMember));

}

void remove_from_structures(AVLTree* userTree, linkedlist* userList){

}

void search_with_ID(AVLTree* userTree, linkedlist* userList){

}

void search_with_name(AVLTree* userTree, linkedlist* userList){

}

//#endif