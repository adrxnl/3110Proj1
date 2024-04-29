//H file call for linked list file
#include "linkedlist.hpp" 

#ifndef LL_CPP
#define LL_CPP

listMember::listMember(int ID, string name, string birthDate, string streetAddress, string currentState, string cityName, int zipcode){
    this->ID = ID;
    this->name = name;
    this->birthDate = birthDate;
    this->streetAddress = streetAddress;
    this->currentState = currentState;
    this->cityName = cityName;
    this->zipcode = zipcode;
    this->next = nullptr;
}

void listMember::displayMember(){
    cout << "ID: " << this->ID;
    cout << "\nName: " << this->name;
    cout << "\nBirthday: " << this->birthDate;
    cout << "\nAddress: " << this->streetAddress << ", " << this->cityName << ", " << this->currentState << ", " << this->zipcode << endl;
}


//Basic Linked List structure setup
linkedlist::linkedlist(){   
    tail = NULL;
    head = NULL;
    cout << "Properly INitiazlise\n";
}

//Function to insert member into the linked list
void linkedlist::insert(listMember* memberToInsert){ 
    //If list is empty
    if(this->head == NULL){
        memberToInsert->next = nullptr;
        this->tail = memberToInsert;
        this->head = memberToInsert;
    }
    else{//if list is not empty 
        this->tail->next = memberToInsert;
        this->tail = memberToInsert;
        memberToInsert->next = nullptr;
    }
}

//Function to delete specific member
void linkedlist::remove(listMember* memberToRemove){
    //Case to reduce traversal time if member is head of list
    if(head == memberToRemove){
        head = memberToRemove->next;
        delete memberToRemove;
    }
    //Case to reduce traversal time if member is tail of list
    else if(tail == memberToRemove){
        listMember* prevMember = head;
        while(prevMember->next != memberToRemove){
            prevMember = prevMember->next;
        }
        tail = prevMember;
        prevMember->next = nullptr;
        delete memberToRemove;
    }
    //Case to traverse list to find member to remove
    else{
        listMember* prevMember = head;
        while(prevMember->next != memberToRemove){
            prevMember = prevMember->next;
        }
        prevMember->next = memberToRemove->next;
        memberToRemove->next = nullptr;
        delete memberToRemove;
    }
}

//Function to search for member using ID
listMember* linkedlist::search_with_ID(int idtoSearch){
    listMember* currMember = head;
    //While loop to traverse through list
    while (currMember != nullptr){
        if(currMember->ID == idtoSearch){
            return currMember;
        }
        else{
            currMember = currMember->next;
        }
    }
    
    return nullptr;
}

//Function to search for member using ID
listMember* linkedlist::search_with_name(string nameToSearch){
    listMember* currMember = head;
    //While loop to traverse through list
    while (currMember != nullptr){
        if(currMember->name == nameToSearch){
            return currMember;
        }
        else{
            currMember = currMember->next;
        }
    }
    
    return nullptr;
}

#endif