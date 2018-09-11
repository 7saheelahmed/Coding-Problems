#include<iostream>
using namespace std;

struct BST{
    int data;
    BST *leftptr;
    BST *rightptr;
};

BST* createNode(int data){
    BST* temp = new BST();
    temp->data = data;
    temp->leftptr=NULL;
    temp->rightptr=NULL;
    return temp;
} 

BST* insertNode(BST* root, int data){
    if(root==NULL){
        return createNode(data);
    }
    else if(data<=root->data){
        root->leftptr = insertNode(root->leftptr,data);
    }
    else{
        root->rightptr = insertNode(root->rightptr,data);
    }
    return root;
}

int getLeafNodeCount(BST* root){
    if(!root)
        return 0;
    if(root->leftptr==NULL && root->rightptr==NULL)
        return 1;
    else{
        return getLeafNodeCount(root->leftptr)+getLeafNodeCount(root->rightptr);
    }
}
void getLeafNodeSum(BST* root,int *sum){
    if(!root)
        return;
    if(root->leftptr==NULL && root->rightptr==NULL)
        *sum+=root->data;
    getLeafNodeSum(root->leftptr,sum);
    getLeafNodeSum(root->rightptr,sum);
    
}

int main(){
    BST *root = NULL;
    root = insertNode(root,50);
    insertNode(root,30);
    insertNode(root,20);
    insertNode(root,40);
    insertNode(root,70);
    insertNode(root,60);
    insertNode(root,80);
    cout<<"\n"<<getLeafNodeCount(root);
    int sum = 0;
    getLeafNodeSum(root,&sum);
    cout<<"SUM OF LEAF NODES: "<<sum;
    return 0;
}