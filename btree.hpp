#include <iostream>
#include <string>
#include<queue>
#include<fstream>
#include<sstream>
using namespace std;

#ifndef B_TREE_HPP
#define B_TREE_HPP

class TreeMember{
    public:
        int ID;
        string name;
        string birthDate;
        string streetAddress;
        string currentState;
        string cityName;
        int zipcode;
        TreeMember* left;
        TreeMember* right;
    TreeMember(int ID, string name, string birthDate, string streetAddress, string currentState, string cityName, int zipcode);
    void displayMember();
};

class AVLTree{
private:
    TreeMember* root;
public:
    AVLTree();
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