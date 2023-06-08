#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* left,*right;
    bool right_thread;
};
node* convert(node* root)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->left==NULL&&root->right==NULL)
    {
        return root;
    }
    if(root->left!=NULL)
    {
        node* l = convert(root->left);
        l->right = root;
        l->right_thread = true;
    }
    if(root->right==NULL)
    {
        return root;
    }
    return convert(root->right);
}
node *leftmost(node* root)
{
    while(root!=NULL&&root->left!=NULL)
    {
        root = root->left;
    }
    return root;
}
void inorder(node* root)
{
    if(root==NULL)
    {
        return;
    }
    node *current = leftmost(root);
    while(current!=NULL)
    {
        cout<<current->data<<" ";
        if(current->right_thread)
        {
            current = current->right;
        }
        else
        {
            current = leftmost(current->right);
        }
    }
}
node* newnode(int data)
{
    node* temp=new node();
    temp->data = data;
    temp->left=temp->right=NULL;
    return temp;
}
int main()
{
    /*           10
                /  \
               /    \
              20     30
             /  \   /  \
            40  50 60  70
    */
    node* root = newnode(10);
    root->left = newnode(20);
    root->right = newnode(30);
    root->left->right = newnode(50);
    root->left->left = newnode(40);
    root->right->left = newnode(60);
    root->right->right = newnode(70);
    convert(root);
    //Printing Inorder by Using Threads...
    cout<<"Inorder of the given tree is : ";
    inorder(root);
    return 0;
}
