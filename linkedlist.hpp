//Include to read to main
#include "btree.hpp"

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
        listMember(int ID, string name, string birthDate, string streetAddress, string cityName, int zipcode);
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
