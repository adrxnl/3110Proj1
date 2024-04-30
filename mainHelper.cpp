#include "btree.hpp"
#include "linkedlist.hpp"

//#ifdef MAIN_HELPER_CPP
//#define MAIN_HELPER_CPP

void displayMenu(){
    cout << "\n\nSelect an action to execute: \n\n";
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
    cout << "\nLoading AVL\n";
    string currLine;
    int counter = 0;
    while(getline(fileStream, currLine)){
        counter++;
        vector<string> dataMembers;
        string token;
        stringstream sStream(currLine);

        while (getline(sStream, token, ',')){
            dataMembers.push_back(token);
        }

        TreeMember* newMember = new TreeMember(stoi(dataMembers.at(0)), dataMembers.at(1), dataMembers.at(2), dataMembers.at(3), dataMembers.at(4), dataMembers.at(5), stoi(dataMembers.at(6)));
        userTree->update_root(userTree->insert(userTree->get_root(), newMember));
        if(counter % 1000 == 0){
            cout << "\nLoaded 1000, current #" << counter << endl;
        }
    }
    
    fileStream.close();
}


void insert_into_structures(AVLTree* userTree, linkedlist* userList, int amountOfRotations){

    int ID, zipcode;
    string name, birthDate, streetAddress, currentState, cityName;

    ID = 2100000 + amountOfRotations;
    cin.ignore();
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
    cout << "Enter ID of student to be removed: ";
    int searchID;
    cin >> searchID;

    if(userList->search_with_ID(searchID) == nullptr){
        cout << "Could not find student with ID#: " << searchID << endl;
        return;
    }

    userTree->update_root(userTree->remove(userTree->get_root(), searchID));
    userList->remove(userList->search_with_ID(searchID));
}

void search_with_ID(AVLTree* userTree, linkedlist* userList){
    cout << "Enter ID of student to be searched: ";
    int searchID;
    cin >> searchID;

    TreeMember* treeSearchMember = userTree->search_with_ID(searchID);

    listMember* listSearchMember = userList->search_with_ID(searchID);

    if(treeSearchMember == nullptr || listSearchMember == nullptr){
        cout << "Could not find student with id# " << searchID << endl;
        return;
    }

    cout << "\nTree Member:\n";
    treeSearchMember->displayMember();

    cout << "\n\nList Member:\n";
    listSearchMember->displayMember(); 
}

void search_with_name(AVLTree* userTree, linkedlist* userList){
    cout << "Enter name of student: ";
    cin.ignore();
    string searchName;
    getline(cin, searchName);


    listMember* listSearchMember = userList->search_with_name(searchName);

    if(listSearchMember == nullptr){
        cout << "Could not find student with name: " << searchName << endl;
        return;
    }

    listSearchMember->displayMember();
    cout << endl;
}

void update_member(AVLTree* userTree, linkedlist* userList){
    cout << "Enter ID of student to update: ";
    int searchID;
    cin >> searchID;

    TreeMember* treeTargetMember = userTree->search_with_ID(searchID);
    listMember* listTargetMember = userList->search_with_ID(searchID);

    if(treeTargetMember == nullptr || listTargetMember == nullptr){
        cout << "could not find student with ID#: " << searchID << endl;
        return;
    }
    int zipcode;
    string name,birthDate,streetAddress,currentState,cityName;


    cout << "Current data:\n";
    listTargetMember->displayMember();
    cin.ignore();
    cout << "\n\nEnter new name: ";
    getline(cin,name);
    cout << "Enter new birth date(YYYY-MM-DD): ";
    cin >> birthDate;
    cin.ignore();
    cout << "Enter new street Address: ";
    getline(cin, streetAddress);
    cout << "Enter new state: ";
    cin >> currentState;
    cin.ignore();
    cout << "Enter new City name: ";
    getline(cin, cityName);
    cout << "Enter new zipcode(numerical): ";
    cin >> zipcode;

    treeTargetMember->updateMember(name,birthDate, streetAddress, currentState, cityName, zipcode);
    listTargetMember->updateMember(name,birthDate, streetAddress, currentState, cityName, zipcode);

    cout << "\n\nNew data:\n";
    treeTargetMember->displayMember();
}


//#endif