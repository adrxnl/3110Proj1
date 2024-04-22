//H file call for linked list file
#include "linkedlist.hpp" 

//Basic Linked List structure setup
linkedlist::linkedlist(){   
    tail = nullptr;
    head = nullptr;
}

//Function to insert member into the linked list
void linkedlist::insert(listMember* memberToInsert){ 
    //If list is empty
    if(head == nullptr){
        memberToInsert->next = nullptr;
        tail = memberToInsert;
        head = memberToInsert;
    }
    //Insert after empty member
    else{ 
        tail->next = memberToInsert;
        tail = memberToInsert;
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
