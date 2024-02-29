/*
input: 10, 20, 40, -1, -1,50, -1, -1, 30, 60, -1, -1, 70, -1, -1

output: 40, 20, 50, 10, 60, 30, 70 

*/
#include<iostream>
#include<queue>
using namespace std;

class Node
{
    public:
    
    int data;
    Node* left;
    Node* right;
    
    Node(int data)
    {
        this->data=data;
        this->left=nullptr;
        this->right=nullptr;
    }
};

// function to build tree
Node* buildTree()
{
    // take input from user to create tree
    int data;
    cout<<"Enter the data to create tree: "<<endl;
    cin>>data;
    
    // Base case:- if data is -1 then replace with null and return
    if(data==-1)
    {
        return nullptr;
    }
    
    // if data is not equal to -1 then follow 3 step
    // step:1 create a root node
    Node* root=new Node(data);
    
    // Step:2 call recursive function for left of tree
    root->left=buildTree();
    
    // Step:3 call recursive function for right of tree
    root->right=buildTree();
    
    return root;
}

// function to give output inorder traversal of a tree
void inorderTraversal(Node *root)
{
    // if root node is null then return
    if(root==nullptr)
    {
        return;
    }
    
    //*************** Else follow LNR ******************//
    
    // Step: 1 -> call function to the left of the tree
    inorderTraversal(root->left);
    
    // Step: 2 -> print the root data
    cout<<root->data<<" ";
    
    // Step: 3 -> call function to the right of the tree
    inorderTraversal(root->right);
}


int main()
{
    Node* root=nullptr;
    
    root=buildTree();
    
    inorderTraversal(root);
    
    return 0;
}
