#include<bits/stdc++.h>
using namespace std;
struct Node{
 int x;
 int y;
 struct Node* ptr=NULL;
};
struct Node* createNode()
{
 struct Node* temp;
 temp= (struct Node*)malloc(sizeof(struct Node));
 return temp;
}
void freeNode(struct Node* node)
{
 struct Node* temp;
 free(node);
 temp=NULL;
}

void addStart_FUNC1(struct Node** str, int x1 ,int y1 )
{
 struct Node* newNode;
 newNode=createNode();

 newNode->x=x1;
 newNode->y=y1;
 newNode->ptr=*str;
 *str=newNode;
}
void deleteStart_FUNC2(struct Node** str)
{
 struct Node* temp;
 if(*str == NULL) /* empty link list */
 {
  return;
 }
 else
 {
  temp=*str;
  *str=(*str)->ptr;
  free(temp);
 }
}
void del_FUNC3(struct Node** str, int x1 , int y1)
{
  struct Node* temp= *str;
  struct Node* prev=NULL;
  if((temp!=NULL)&&(temp->x==x1)&&(temp->y==y1))
  {
   	*str=temp->ptr;
  	free(temp);
 	 return;
  }
  else
 {
  	while(temp!=NULL&&((temp->x)!=x1)&&((temp->y)!=y1))
	{
		prev=temp;
		temp=temp->ptr;
	}
        if(temp==NULL)cout<<"Node not present";
	prev->ptr=temp->ptr;
 	free(temp);
  }
}

 void search_by_distance_FUNC4(struct Node** str ,float d)
{
 struct Node* temp;
 temp=*str;
 while(temp!=NULL)
 {
  int a=temp->x;
  int b=temp->y;
  float dist=sqrt((a*a)+(b*b));
  if(dist<=d)cout<<(temp->x)<<(temp->y);
  else temp=temp->ptr;
 }
  
}
bool search_FUNC5(struct Node** str ,int x1, int y1)
{
 struct Node* temp;
 temp=*str;
 while(temp!=NULL)
 {
  if (temp->x==x1&&temp->y==y1)return true;
  else temp=temp->ptr;
 }
  if(temp==NULL)return false;
  
}
int length(struct Node** str)
{
 struct Node* temp;
 int cnt=0;
 temp=*str;
 if(temp==NULL)cout<<"0";
 else
 {
  while(temp!=NULL)
  {
   cnt++;
   temp=temp->ptr;
  }
  cout<<cnt;
 }
}
int main()
{
 long long int t;
 cin>>t;
 struct Node *str = NULL;
 while(t--)
 {
  int ip;
  cin>>ip;
  if(ip==1)
  {
	  int a,b;
	  cin>>a>>b;
	  addStart_FUNC1(&str,a,b);
  }
  if(ip==2)
  {
	deleteStart_FUNC2(&str);
  }
  if(ip==3)
  {
	 int a,b;
	  cin>>a>>b;
	  del_FUNC3(&str,a,b);
  }
  if(ip==4)
  {
	  float d;
	  cin>>d;
	  search_by_distance_FUNC4(&str,a,b);
  }
  if(ip==5)
  {
	  int a,b;
	  cin>>a>>b;
	  search_FUNC5(&str,a,b);
  }
  if(ip==6)
  {
	length(&str);
  }
 }
 return 0;
}
	 
  
	 
	  
   
   
 
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
