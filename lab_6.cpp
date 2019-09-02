#include<iostream>
using namespace std;

struct node
{
  long long int user_id;
  long long int recharge;
  struct node* left ;
  struct node* right;
};
struct node* create_node(long long int ID,long long int recharge)
{
  struct node* NODE = new struct node;
  NODE->user_id = ID;
  NODE->recharge = recharge;
  NODE->left = NULL;
  NODE->right = NULL;
  return node;
}
struct node* insert(struct node* root,long long int UID,long long money)
{
  if(root==NULL)
  {
    return create_node(UID,recharge)

  }
  if(UID<root->user_id)
  {
    root->left = insert(root->left,UID);
  }
   if(UID>root->user_id)
  {
    root->right = insert(root->right,UID);
  }
  if(UID==root->user_id)
  {
    root->recharge+=money;
  }
}
struct node* search(struct node* root, long long int ID)
{
  struct node* tmp;
  tmp = root;

  while(root!=NULL)
  {
    if(UID>root->user_id)
    {
      root=root->right;
      search(root,ID);

    }
    if(UID<root->user_id)
    {
      root=root->left;
      search(root,ID);
    }


    else return root;
  }
  return tmp;

}
int main()
{
  int users,q;
  cin>>users;
  cin>>q;
  while(q)
  {
    int num;
    cin>>num;
    if(num==1)
    {
      int a,b;
      cin>>a>>b;
      search()
    }
  }

}
