/*
input: 10, 20, 40, -1, -1, 50, -1, -1, 30, 60, -1, -1, 70, -1, -1

output: 

Printing top view: 
-2 40
-1 20
0 60
1 30
2 70

*/


#include<iostream>
#include<map>
#include<queue>
using namespace std;

// create a class to to build tree
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

void topView(Node* root)
{
    if(root==nullptr)
    {
        return;
    }
    
    // create a map to storing distance and  topNode->data 
    map<int, int> topNode;
    
    // level order
    // create a queue of pair where we will store pointer data and horizontal distance(HD)
    queue<pair<Node*, int>> q;
    
    q.push(make_pair(root, 0));
    
    while(!q.empty())
    {
        // Node* temp= q.front();
        pair<Node*, int> temp = q.front();
        
        q.pop();
        
        Node* frontNode=temp.first;
        
        int HD= temp.second;
        
       // create entry
        topNode[HD] = frontNode->data;
        
        if(frontNode->left)
        {
            q.push(make_pair(frontNode->left, HD-1));
        }
        
        if(frontNode->right)
        {
            q.push(make_pair(frontNode->right, HD + 1));
        }
    }
    
    cout<<"Printing top view: "<<endl;
    
    for(auto i: topNode)
    {
        cout<<i.first<<" "<<i.second<<endl;
    }
    
}

void printLeftTree(Node* root, vector<int> &ans, int level)
{
    if(root==nullptr)
    {
        return;
    }
    
    if(level==ans.size())
    {
        ans.push_back(root->data);
    }
    
    printLeftTree(root->left, ans, level+1);
    
    printLeftTree(root->right, ans, level+1);
}

int main()
{
    // create a empty node and store the ans of buildTree() function
    Node* root=nullptr;
    
    root=buildTree();
    
    vector<int> ans;
    
    int level=0;
    
    printLeftTree(root, ans, level);
    return 0;
}
