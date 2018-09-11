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
std::pair<int, bool> helper(BSTNode* root){
    
    if(root==NULL)
        return std::make_pair(0, true);
    
    std::pair<int, bool> answer1 = helper(root->left);
    int left_count = answer1.first;bool is_left_unival = answer1.second;
    std::pair<int, bool> answer2 = helper(root->right);
    int right_count = answer2.first;bool is_right_unival = answer2.second;
    
    bool is_unival = true;
    if(!is_right_unival or !is_left_unival)
        is_unival = false;
    
    if(root->left!=NULL && root->left->data!=root->data)
        is_unival = false;
    if(root->right!=NULL && root->right->data!=root->data)
        is_unival = false;
    
    if(is_unival)
        return std::make_pair(left_count+right_count+1,true);
    else
        return std::make_pair(left_count+right_count,true);
    
}
int unival(BSTNode* root){
    std::pair<int, bool> answer = helper(root);
    return answer.first;
}


int main(){
    rootptr = Insert(rootptr , 3);
    Insert(rootptr , 2);
    Insert(rootptr , 3);
    Insert(rootptr , 2);
    Insert(rootptr , 2);
    Insert(rootptr , 2);
    cout<<unival(rootptr);
    //Insert(rootptr , 2);
    //if(Search(rootptr , 1))
      //  cout<<"Arey Mil hi gya";
    //else
      //  cout<<"Nahi Mila";
        
    return 0;
}

