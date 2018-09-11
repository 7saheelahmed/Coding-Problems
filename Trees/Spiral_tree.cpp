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

int height(BST* root){
    if(root==NULL){
        return 0;
    }
    else{
        int lheight = height(root->leftptr);
        int rheight = height(root->rightptr);
        if(lheight>rheight)
            return(lheight+1);
        else
            return(rheight+1);
    }
}
void printGivenLevel(BST* root,int level,bool itr){
    if(root==NULL)
        return;
    else if(level==1)
        cout<<root->data<<" ";
    else if(level>1){
        if(itr){
            printGivenLevel(root->leftptr,level-1,itr);
            printGivenLevel(root->rightptr,level-1,itr);
        }
        else{
            printGivenLevel(root->rightptr,level-1,itr);
            printGivenLevel(root->leftptr,level-1,itr);
        }
        
    }
        
}

void printSpiral(BST* root){
    int h;
    bool itr=false;
    h = height(root);
    for(int i=1;i<=h;i++){
        printGivenLevel(root,i,itr);
        itr=!itr;
    }
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
    printSpiral(root);
    return 0;
}