#include "btree.hpp"

#ifndef B_TREE_CPP
#define B_TREE_CPP

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

TreeMember* AVLTree::get_root(){
    return this->root;
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



/*void AVLTree::remove(int searchID){
    root = remove(root, searchID);
}
*/

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
    int left_height = get_height(targetMember->left);
    int right_height = get_height(targetMember->right);
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
        if(get_difference(targetMember->left) >= 0){
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
    if(currRoot == nullptr){
        currRoot = memberToAdd;
        return currRoot;
    }else if(memberToAdd->ID < currRoot->ID){
        currRoot->left = insert(currRoot->left, memberToAdd);
        currRoot = balance(currRoot);
    }else{
        currRoot->right = insert(currRoot->right, memberToAdd);
        currRoot = balance(currRoot);
    }
    return currRoot;
}

TreeMember* AVLTree::remove(TreeMember* currRoot, int searchID){
    if(currRoot == nullptr){
        cout << "Could not remove, no target found with ID#" << searchID << endl;
        return currRoot;
    }
    if(searchID < currRoot->ID){
        currRoot->left = remove(currRoot->left, searchID);
    }else if(searchID > currRoot->ID){
        currRoot->right = remove(currRoot->right, searchID);
    }else{
        // Node with only one child or no child
        if(currRoot->left == nullptr || currRoot->right == nullptr){
            TreeMember* temp = currRoot->left ? currRoot->left : currRoot->right;

            // No child case
            if(temp == nullptr){
                temp = currRoot;
                currRoot = nullptr;
            }else{ // One child case
                *currRoot = *temp; // Copy the contents of the non-empty child
            }
            delete temp;
        }else{
            // Node with two children: Get the inorder successor (smallest in the right subtree)
            TreeMember* temp = minValueNode(currRoot->right);

            // Copy the inorder successor's data to this node
            currRoot->ID = temp->ID;

            // Delete the inorder successor
            currRoot->right = remove(currRoot->right, temp->ID);
        }
    }

    // If the tree had only one node, then return
    if(currRoot == nullptr){
        return currRoot;
    }

    // Update height of the current node
    currRoot = balance(currRoot);

    return currRoot;
}

// Function to find the node with minimum value in a tree rooted at currRoot
TreeMember* AVLTree::minValueNode(TreeMember* currRoot){
    TreeMember* current = currRoot;

    // Loop down to find the leftmost leaf
    while(current->left != nullptr){
        current = current->left;
    }
    return current;
}


#endif