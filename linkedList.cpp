#include "linkedlist.hpp"

linkedlist::linkedlist(){
    tail = nullptr;
    head = nullptr;
}

void linkedlist::insert(listMember* memberToInsert){
    if(head == nullptr){
        memberToInsert->next = nullptr;
        tail = memberToInsert;
        head = memberToInsert;
    }else{
        tail->next = memberToInsert;
        tail = memberToInsert;
        memberToInsert->next = nullptr;
    }
}

void linkedlist::remove(listMember* memberToRemove){
    if(head == memberToRemove){
        head = memberToRemove->next;
        delete memberToRemove;
    }else if(tail == memberToRemove){
        listMember* prevMember = head;
        while(prevMember->next != memberToRemove){
            prevMember = prevMember->next;
        }
        tail = prevMember;
        prevMember->next = nullptr;
        delete memberToRemove;
    }else{
        listMember* prevMember = head;
        while(prevMember->next != memberToRemove){
            prevMember = prevMember->next;
        }
        prevMember->next = memberToRemove->next;
        memberToRemove->next = nullptr;
        delete memberToRemove;
    }
}