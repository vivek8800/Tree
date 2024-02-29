/*
input: 10, 20, 40, -1, -1,50, -1, -1, 30, 60, -1, -1, 70, -1, -1

output: 10, 20, 30, 40, 50, 60, 70
//**************************************************************

For level order traversal,

We have to do following steps:
first, we need to create a queue which will hold pointer of Node
we will push root node initially then we will follow the steps.

Now, Step 1:
create a temperory node and store front of queue in temperory node.

Step 2:
delete the node(for first time only root node will be there)

Step 3:
print the data stored in temperory Node

Step 4:
Push the child of the node that we have poped in step 2.

REPETE THIS STEP

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

// function to print level ordr tree
void levelOrderTraversal(Node* root)
{
    // create a queue which store pointer(address) of Node
    queue<Node*> q;
    
    // initially push root node at the begning
    q.push(root);
    
    // iterate till q is not empty (only root node will be there)
    while(!q.empty())
    {
        // Step: A->  create a temperory node and store front node of queue
        Node* temp=q.front();
        
        // Step: B -> Now pop that front Node
        q.pop();
        
        // Step: C -> print the data stored in temperory Node
        cout<<temp->data<<" ";
        
        // Step: D -> insert child of poped node (which we have poped in step B)\
        // if there wiil be left child then push in queue
        if(temp->left)
        {
            q.push(temp->left);
        }
        
        // if there will be right child then push in queue
        if(temp->right)
        {
            q.push(temp->right);
        }
    }
}


int main()
{
    Node* root=nullptr;
    
    root=buildTree();
    
    levelOrderTraversal(root);
    
    return 0;
}



