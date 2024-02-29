/*

input: 10, 20, 40, -1, -1,50, -1, -1, 30, 60, -1, -1, 70, -1, -1

output: binary tree is balanced

*****************************************************************

Check if given binary tree is balanced or not?

Sol:- At each node, Absolute difference of left sub tree's height and right sub tree's height should be less than or equal to 1

Approach:
    solve 1 case 
    
            At each Node
            /        \
           /          \
          /            \ 
  Height of left    Height of right  
    sub tree         sub tree
        \               /
         \             /
          \           /
           \         /
            \       /
          difference<=1
          
    After this, recursion will take care

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

// function that return maximum height of tree 
int height(Node* root)
{
    // Base Case: if root will be null then height will be 0
    if(root==nullptr)
    {
        return 0;
    }
    
    // call to recursion that will return left height
    int leftHeight=height(root->left);
    
    // call to recursion that will return left height
    int rightHeight=height(root->right);
    
    // maximum height will be max of left height and right height + 1
    // + 1, because in left or right height-> root node is not included so to add root node , added +1
    int ans=max(leftHeight, rightHeight) + 1;
    
    return ans;
}

bool isBalanced(Node* root)
{
    // if no node or root is null then binary tree is balanced
    if(root ==nullptr)
    {
        return true;
    }
    
    // solve 1 Case
    int leftHeight=height(root->left);
    
    int rightHeight=height(root->right);
    
    int diff= abs(leftHeight-rightHeight);
    
    bool ans1=(diff<=1);
    
    // rest recursion will take care 
    
    bool leftAns= isBalanced(root->left);
    
    bool rightAns= isBalanced(root->right);
    
    if(ans1 && leftAns && rightAns)
    {
        return true;
    }
    
    else
    {
        return false;
    }
    
}

int main()
{
    // create a empty node and store the ans of buildTree() function
    Node* root=nullptr;
    
    root=buildTree();
    
    bool ans= isBalanced(root);
    
    if(ans)
    {
        cout<<"binary tree is balanced"<<endl;
    }
    
    else
    {
        cout<<"Binary tree in not balanced"<<endl;
    }
    
    return 0;
}