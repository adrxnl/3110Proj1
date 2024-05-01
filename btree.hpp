//This is the Binary Tree header file, which declares 
//all of the appropriate variables and functions within 
//the Tree Member and AVL Tree Classes

#include <iostream>
#include <string>
#include<queue>
#include<fstream>
#include<sstream>
using namespace std;

#ifndef B_TREE_HPP
#define B_TREE_HPP

//Class for tree nodes aka members
class TreeMember{
    public:
        //All of the appropriate information necessary to create each person as a tree member
        int ID;
        string name;
        string birthDate;
        string streetAddress;
        string currentState;
        string cityName;
        int zipcode;

        //Pointers necessary to reflect tree properties
        TreeMember* left;
        TreeMember* right;
    
    //Member constructor
    TreeMember(int ID, string name, string birthDate, string streetAddress, string currentState, string cityName, int zipcode);

    //Function to display relavent member information
    void displayMember();

    //Function to update information for a given member
    void updateMember(string name, string birthDate, string streetAddress, string currentState, string cityName, int zipcode);
};

//Class implementing the AVL Tree
class AVLTree{
private:
    //Pointer for root of tree
    TreeMember* root;
public:
    AVLTree(); //Constructor

    //Necessary functions to implement the properties of the AVL tree
    TreeMember* get_root();
    void update_root(TreeMember* newRoot);
    TreeMember* insert(TreeMember* currRoot, TreeMember* memberToAdd);
    TreeMember* search_with_ID(int searchID);
    TreeMember* remove(TreeMember* currRoot, int searchID);
    TreeMember* minValueNode(TreeMember* currRoot);
    TreeMember* balance(TreeMember* targetMember);
    int get_height(TreeMember* targetMember);
    int get_difference(TreeMember* targetMember);
    TreeMember* rr_rotate(TreeMember* parentNode);
    TreeMember* ll_rotate(TreeMember* parentNode);
    TreeMember* lr_rotate(TreeMember* parentNode);
    TreeMember* rl_rotate(TreeMember* parentNode);
    TreeMember* rightRotate(TreeMember *y);
    TreeMember* leftRotate(TreeMember *x);
};  



#endif
