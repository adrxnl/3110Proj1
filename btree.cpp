#include "btree.hpp"


TreeMember::TreeMember(int ID, string name, string birthDate, string streetAddress, string currentState, string cityName, int zipcode){
    this->ID = ID;
    this->name = name;
    this->birthDate = birthDate;
    this->streetAddress = streetAddress;
    this->currentState = currentState;
    this->cityName = cityName;
    this->zipcode = zipcode;
    this->left = nullptr;
    this->right = nullptr;
}

void TreeMember::displayMember(){
    cout << "ID: " << this->ID;
    cout << "\nName: " << this->cityName;
    cout << "\nBirthday: " << this->birthDate;
    cout << "\nAddress: " << this->streetAddress << ", " << this->cityName << ", " << this->currentState << ", " << this->zipcode << endl;
}


AVLTree::AVLTree()
{
    root = nullptr;
}

TreeMember* AVLTree::search_with_ID(int searchID){
    TreeMember* currNode = this->root;
    while(currNode != nullptr){
        if(searchID == currNode->ID){
            return currNode;
        }else if(currNode->ID < searchID){
            currNode = currNode->right;
        }else{
            currNode = currNode->left;
        }
    }
}

TreeMember* AVLTree::search_with_name(string searchName){
    
}


TreeMember AVLTree::

int AVLTree::get_height(TreeMember* targetMember){
    int height = 0;
    if(targetMember != nullptr){
        int left_height = get_height(targetMember->left);
        int right_height = get_height(targetMember->right);
        int max_height = max(left_height, right_height);
        height = max_height + 1;
    }
    return height;
}

int AVLTree::get_difference(TreeMember* targetMember){
    int left_height = get_height(targetMember);
    int right_height = get_height(targetMember);
    int balance_factor = left_height - right_height;
    return balance_factor;
}

TreeMember* AVLTree::rr_rotate(TreeMember* parentNode){
    TreeMember* tempNode = parentNode->right;
    parentNode->right = tempNode->left;
    tempNode->left = parentNode;
    return tempNode;
}

TreeMember* AVLTree::ll_rotate(TreeMember* parentNode){
    TreeMember* tempNode = parentNode->left;
    parentNode->left = tempNode->right;
    tempNode->right = parentNode;
    return tempNode;
}

TreeMember* AVLTree::lr_rotate(TreeMember* parentNode){
    TreeMember* tempNode = parentNode->left;
    parentNode->left = rr_rotate(tempNode);
    return ll_rotate(parentNode);
}

TreeMember* AVLTree::rl_rotate(TreeMember* parentNode){
    TreeMember* tempNode = parentNode->right;
    parentNode->right = ll_rotate(tempNode);
    return rr_rotate(parentNode);
}


TreeMember* AVLTree::balance(TreeMember* targetMember){
    int balance_factor = get_difference(targetMember);
    if(balance_factor > 1){
        if(get_difference(targetMember->left) > 0){
            targetMember = ll_rotate(targetMember);
        }
        else{
            targetMember = lr_rotate(targetMember);
        }
    }
    else if(balance_factor < -1){
        if(get_difference(targetMember->right) > 0){
            targetMember = rl_rotate(targetMember);
        }
        else{
            targetMember = rr_rotate(targetMember);
        }
    }
    return targetMember;
}
TreeMember* AVLTree::insert(TreeMember* currRoot,TreeMember* memberToAdd){
    if(currRoot = nullptr){
        currRoot = memberToAdd;
        return;
    }else if(memberToAdd->ID < currRoot->ID){
        currRoot->left = insert(currRoot->left, memberToAdd);
        currRoot = balance(currRoot);
    }else{
        currRoot->right = insert(currRoot->right, memberToAdd);
        currRoot = balance(currRoot);
    }
    return currRoot;
}