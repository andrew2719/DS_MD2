#include<bits/stdc++.h>
using namespace std;



class Node
{
public:
    int val;
    Node* left;
    Node* right;

    Node(int val)
    {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node* insert(int i,int j,int a[])
{

    int mid = (i+j)/2;
    cout<<"root = "<<a[mid]<<endl;
    Node* root = new Node(a[mid]);
    if(i==j)
        return root;
    if(i<mid){
        cout<<"left =";
        for(int k=i;k<mid;k++)
            cout<<a[k]<<" ";
        cout<<endl;
        root->left = insert(i,mid-1,a);
    }
    if(mid<j)
    {
        cout<<"right =";
        for(int k=mid+1;k<=j;k++)
            cout<<a[k]<<" ";
        cout<<endl;
        root->right = insert(mid+1,j,a);
    }
    return root;

}
void inorder(Node* root)
{
    if(root==nullptr)
        return;
    cout<<root->val<<" ";
    inorder(root->left);
    inorder(root->right);
}
int main()
{
    int a[] = {1,2,3,4,5,6,7,8,9};int n = sizeof(a)/sizeof(a[0]);
    Node *root = nullptr;
    root = insert(0,n-1,a);
    inorder(root);
}