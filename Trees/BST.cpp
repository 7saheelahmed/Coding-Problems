#include<iostream>
using namespace std;

struct BSTNode
{
  int data;
  BSTNode *left;
  BSTNode *right;
};

BSTNode *rootptr=NULL;

BSTNode* getNode(int data){
    BSTNode* newNode = new BSTNode();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
BSTNode* Insert(BSTNode *root,int data){
    if(root==NULL){
        root = getNode(data);
    }
    else if(data<=root->data){
        root->left = Insert(root->left,data);
    }
    else{
        root->right = Insert(root->right,data);
    }
    return root;   
}
bool Search(BSTNode *root , int data){
    if(root==NULL){
        return false;
    }
    else if(root->data == data){
        return true;
    }
    else if(data<=root->data){
        return Search(root->left,data);
    }
    else{
        return Search(root->right,data);
    }
}

int main(){
    rootptr = Insert(rootptr , 10);
    Insert(rootptr , 15);
    Insert(rootptr , 5);
    Insert(rootptr , 20);
    if(Search(rootptr , 1))
        cout<<"Arey Mil hi gya";
    else
        cout<<"Nahi Mila";
        
    return 0;
}

