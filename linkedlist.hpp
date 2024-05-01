//This is the Linked List header file, which declares 
//all of the appropriate variables and functions within 
//the List Member and Linked List Classes

//Include to read to main
#include "btree.hpp"

#ifndef LL_HPP
#define LL_HPP

//Class definition of "listMember"
class listMember{
    //All variables and creation function
    public:
        int ID;
        string name;
        string birthDate;
        string streetAddress;
        string currentState;
        string cityName;
        int zipcode;
        listMember* next;
        void displayMember();
        listMember(int ID, string name, string birthDate, string streetAddress, string currentState, string cityName, int zipcode);
        void updateMember(string name, string birthDate, string streetAddress, string currentState, string cityName, int zipcode);
};

//Class definition of "linkedlist"
class linkedlist{
    //Head and tail nodes for linked list
    private:
        listMember* head;
        listMember* tail;

    //Creation and maipulation functions for linked list
    public:
        linkedlist();
        void insert(listMember* memberToInsert);
        void remove(listMember* memberToRemove);
        listMember* search_with_name(string nameToSearch);
        listMember* search_with_ID(int idToSearch);

};

#endif
