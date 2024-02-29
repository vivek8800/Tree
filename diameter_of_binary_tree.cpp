/*
input: 10, 20, 40, -1, -1,50, -1, -1, 30, 60, -1, -1, 70, -1, -1

output:->  Diameter of binary tree is: 4

**********************************************************************************
Find the diameter of binary tree

defination: diameter means longest path of the edges which may include root not or not.

Possible outcome from this is that

//*************when root node not included in finding diameter of BT **************

option 1: Either longest path or diameter exist in left side of binary tree.

option 2: Either longest path or diameter exist in right side of binary tree.

//~~~~~~~~~~~~~~ when root node included in finding diameter of BT ~~~~~~~~~~~~~~~

option 3: Either longest path or diameter exist i combination of ( left side + root node + right side)
Hint: option 3 can be calculated by using height function of binary tree.

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

// function to get the height of binary tree
int daimeterOfbinaryTree(Node* root)
{
    // if root will be null then diameter : 0
    if(root==nullptr)
    {
        return 0;
    }
    
    //Either longest path or diameter exist in left side of binary tree.
    int option1=daimeterOfbinaryTree(root->left);
    
    // Either longest path or diameter exist in right side of binary tree.
    int option2=daimeterOfbinaryTree(root->right);
    
    // Either longest path or diameter exist i combination of ( left side + root node + right side)
    int option3= height(root->left) + height(root->right);
    
    // diameter of binary tree will be maximum of option1, option2, option3
    int ans= max(option1, max(option2, option3));
    
    return ans;
}

int main()
{
    // create a empty node and store the ans of buildTree() function
    Node* root=nullptr;
    
    root=buildTree();
    
    cout<<"Diameter of binary tree is: "<<daimeterOfbinaryTree(root)<<endl;;
    
    return 0;
}