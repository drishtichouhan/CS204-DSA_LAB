//Find if there is a triplet in a BST that adds to zero

//code:


#include <bits/stdc++.h>
using namespace std;


class node
{
    public:
    int key;
    node *left;
    node *right;
};
void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout<<root->key;
        inorder(root->right);
    }
}

node* deleteNode(node* root, int key)
{
    // base case
    if (root == NULL) return root;


    if (key < root->key)
        root->left = deleteNode(root->left, key);


    else if (key > root->key)
        root->right = deleteNode(root->right, key);


    else
    {

        if (root->left == NULL)
        {
            node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
           node *temp = root->left;
            free(root);
            return temp;
        }


        struct node* temp = minValueNode(root->right);

        root->key = temp->key;


        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}


void convert(node* root, node** head, node** tail)  //This function converts the tree into a doubly linked list
{

    if (root == NULL)
        return;


    if (root->left)
        convert(root->left, head, tail);


    root->left = *tail;


    if (*tail)
        (*tail)->right = root;
    else
        *head = root;


    *tail = root;


    if (root->right)
        convert(root->right, head, tail);
}


bool isPresent(node* head, node* tail, int sum)
{
    while (head != tail)
    {
        int curr = head->key + tail->key;
        if (curr == sum)
            return true;
        else if (curr > sum)
            tail = tail->left;
        else
            head = head->right;
    }
    return false;
}


bool isTripletPresent(node *root)
{

    if (root == NULL)
    return false;


    node* head = NULL;
    node* tail = NULL;
    convert(root, &head, &tail);


    while ((head->right != tail) && (head->key < 0))
    {

        if (isPresent(head->right, tail, -1*head->key))
            return true;
        else
            head = head->right;
    }


    return false;
}


node* newNode(int num)
{
    node* temp = new node();
    temp->key = num;
    temp->left = temp->right = NULL;
    return temp;
}


void insert(node* temp, int key)
{
    queue<struct node*> q;
    q.push(temp);
    while (!q.empty()) {
        node* temp = q.front();
        q.pop();

        if (!temp->left) {
            temp->left = newNode(key);
            break;
        } else
            q.push(temp->left);

        if (!temp->right) {
            temp->right = newNode(key);
            break;
        } else
            q.push(temp->right);
    }
}
int main()
{
    node* root = NULL;
    int num;
    cout<<"Enter the number of values:"<<"\n";
    cin>>num;
    cout<<"Enter values";
    for(int i=0;i<num;i++)

    {
    	int val;
    	cin>>val;
    	root=insert(root,val);
    }
    if (isTripletPresent(root))
        cout << "Present"<<"\n";
    else
        cout << "Not Present"<<"\n";
    return 0;
}
