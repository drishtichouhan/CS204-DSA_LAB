
  
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int value;
    int p;
    node* left;
    node* right;
};
node* leftrotate(node* y)
{
    node* x= y->right;
    node* temp= x->left;
    x->left= y;
    y->right= temp;
    return x;
}

node* rightrotate(node* x)
{
    node* y= x->left;
    node* temp= y->right;
    y->right= x;
    x->left= temp;
    return y;
}

node* newnode(int x)
{
    node* temp= new node;
    temp->value= x;
    temp->p= rand()%100;
    temp->left=NULL;
    temp->right= NULL;
    return temp;
}

node* search_s(node* root, int value)
{
    if(root==NULL || root->value==value)
    {
        return root;
    }

    if(root->value>value)
    {
        return search_s(root->left, value);
    }
    if(root->value<value)
    {
        return search_s(root->right, value);
    }
}

node* insert_node(node* root, int value)
{
    if(root==NULL)
    {
        return newnode(value);
    }

    if(root->value>=value)
    {
        root->left= insert_node(root->left, value);
        if(root->left->p>root->p)
        {
            root= rightrotate(root);
        }
    }
    else if(root->value<value)
    {
        root->right= insert_node(root->right, value);
        if(root->right->p>root->p)
        {
            root= leftrotate(root);
        }
    }

    return root;
}

node* deletenode(node* root, int value)
{
    if(root==NULL)
    {
        return root;
    }
    //If value is not equal to root's value, we check in its rightp or leftp subtree//
    if(root->value>value)
    {
        root->left= deletenode(root->left, value);
    }
    else if(root->value<value)
    {
        root->right= deletenode(root->right, value);
    }
    else if(root->value==value)
    {
        if(root->left==NULL)
        {
            node* temp= root->right;
            delete(root);
            root= temp;
        }
        else if(root->right==NULL)
        {
            node* temp= root->left;
            delete(root);
            root= temp;
        }
        else if(root->left!=NULL && root->right!=NULL)
        {
            if(root->left->p>root->right->p)
            {
                root= rightrotate(root);
                root->right= deletenode(root->right, value);
            }
            else if(root->right->p>root->left->p)
            {
                root= leftrotate(root);
                root->left= deletenode(root->left, value);
            }
        }
    }
    return root;
}

void inorder(node* root)
{
    if (root!=NULL)
    {
        inorder(root->left);
        cout << "value: "<< root->value << " | Priority: "
            << root->p;
        if (root->left)
            cout << " | left child: " << root->left->value;
        if (root->right)
            cout << " | right child: " << root->right->value;
        cout << endl;
        inorder(root->right);
    }
    else{
        cout<<"Empty"<<endl;
    }
}
int main()
{
     struct node *root = NULL;
     int in,del,se;
     cin>>in>>del>>se;
     int arr[in];
     for(int i=1;i<=in;i++){
            int val;
            cin>>val;
            arr[i-1]=val;
        root = insert_node(root,val);
     }


    cout << "Inorder traversal of the given tree \n";
    inorder(root);
    for(int i=1;i<=del;i++){
            int temp;
            cin>>temp;
        root = deletenode(root,temp);
          cout << "Inorder traversal of the modified tree after deletion of node \n";
    inorder(root);
    }
   for(int i=1;i<=se;i++){
        int val;
      cin>>val;
            node *res = search_s(root, val);

            if(res==NULL)
    {
        cout<<" Not Found!!!" <<endl;
    }
    else
    {
        cout<< "Found!!!" <<endl;
    }
    }


    return 0;
}


/*
9 2 2
1 7 6 4 3 2 8 9 10
8 3
7
3
*/

