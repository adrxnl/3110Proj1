#include "btree.hpp"

class listMember{
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

class linkedlist
{
private:
    listMember* head;
    listMember* tail;

public:
    linkedlist();
    void insert(listMember* memberToInsert);
    void remove(listMember* memberToRemove);
    listMember* search_with_name(string nameToSearch);
    listMember* search_with_ID(int idToSearch);

};