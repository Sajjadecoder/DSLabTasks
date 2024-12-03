#include<iostream>
#include<string>
using namespace std;
struct Node{
    int val;
    Node *left;
    Node *right;
    int height;
    Node(int v){
        val = v;
        height=1;
        left =right = nullptr;
    }
};
int getheight(Node *root){
    if (!root)
    {
        return 0;
    }return root->height;
    
}
int getbal(Node *root){
    return getheight(root->left)-getheight(root->right);
}
Node*leftRotate(Node *root){
    Node *child = root->right;
    Node* childLeft = child->left;
    child->left = root;
    root->right = childLeft;
    root->height = 1 +max(getheight(root->left),getheight(root->right));
    child->height = 1 +max(getheight(child->left),getheight(child->right));
    return child;
}
Node*rightRotate(Node *root){
    Node *child = root->left;
    Node* childRight = child->right;
    child->right= root;
    root->left=childRight;
    root->height = 1 +max(getheight(root->left),getheight(root->right));
    child->height = 1 +max(getheight(child->left),getheight(child->right));
    return child;
}
Node *insertNode (Node *root,int data){
    if (!root)
    {
        return new Node(data);
    }
    if (data<root->val)
    {
        root->left = insertNode(root->left,data);
    }
    if (data>root->val)
    {
        root->right = insertNode(root->right,data);
    }
    root->height = 1 +max(getheight(root->left),getheight(root->right));
    int bal = getbal(root);
    if (bal>1)
    {
        if (data<root->left->val)
        {
            return rightRotate(root);
        }else{
            root->left= leftRotate(root->left);
            return rightRotate(root);
        }
        
    }
    else if (bal<-1)
    {
        if (data>root->right->val)
        {
            return leftRotate(root);
        }else{
            root->right=rightRotate(root->right);
            return leftRotate(root);
        }
        
    }else {
        return root;
    }
    
}
void inorder(Node *root,int numToFind,int &minDiff,int &currentAns){
    if (!root)
    {
        return;
    }
    int diff = abs(root->val - numToFind);
    if (diff < minDiff) {
        minDiff = diff;
        currentAns = root->val;
    }
    inorder(root->left,numToFind,minDiff,currentAns);
    inorder(root->right,numToFind,minDiff,currentAns);
    
    
}
int main(){
    int nums[] = {100,120,450,250,160,90};
    int ans = 0;
    int t = 299;
    Node *root = nullptr;
    for (int i = 0; i < 6; i++)
    {
        root = insertNode(root,nums[i]);
    }
    int diff=  1000000;
    inorder(root,t,diff,ans);
    cout<<"Value closest to "<<t<<" is: "<<ans;
    
    return 0;
}   