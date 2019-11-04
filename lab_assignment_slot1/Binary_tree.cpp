//Question : Find mirror of a given node in Binary Tree

// Code :

#include<bits/stdc++.h>
using namespace std;
struct Node{
	int key;
	struct Node *left;
	struct Node *right;
};
struct Node* new_node(int k)
{
	struct Node* n = (struct Node*)malloc(sizeof(struct Node*));
	if(n!=NULL)
	{
		n->key=k;
		n->left=NULL;
		n->right=NULL;
		return n;
	}
	else 
	{
		cout<<"Memory allocation failed";

	}
}

int Find_mirror(int val,struct Node* left , struct Node* right)
{
	if(right==NULL||left==NULL)return 0;
	if(left->key==val)return right->key;
	if(right->key==val)return left->key;
	int value = Find_mirror(val,left->left,right->right);
	if(value)return value;
	Find_mirror(val,left->right,right->left);
}

int MIRROR(struct Node* root, int val)
{
	if(root==NULL)return 0;
	if(val==root->key)return val;
	return Find_mirror(val,root->left,root->right);
}
void insert(struct Node* temp, int key) 
{ 
    queue<struct Node*> q; 
    q.push(temp);
    while (!q.empty()) { 
        struct Node* temp = q.front(); 
        q.pop(); 
  
        if (!temp->left) { 
            temp->left = new_node(key); 
            break; 
        } else
            q.push(temp->left); 
  
        if (!temp->right) { 
            temp->right = new_node(key); 
            break; 
        } else
            q.push(temp->right); 
    } 
} 
  

int main()
{
	cout<<"Enter the number of elements in the tree:"<<"\n";
	int num;
	cin>>num;
	int arr[1000];
	struct Node* root=NULL;
	
	for(int i=0;i<num;i++)cin>>arr[i];
	for(int i=0;i<num;i++)
	{		cout<<"YO";
		insert(root,arr[i]); 
	}
	int target;
	cin>>target;
	int mirror_value=MIRROR(root,target);
	if (mirror_value)  
        cout << "Mirror of Node " << target  
             << " is Node " << mirror_value << endl;  
    else
        cout << "Mirror of Node " << target  
             << " is NULL! " << endl; 

}