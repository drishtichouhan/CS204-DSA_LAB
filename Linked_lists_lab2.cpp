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

void AddFirst(struct Node** str, int x1 ,int y1 )
{
 struct Node* newNode;
 newNode=createNode();

 newNode->x=x1;
 newNode->y=y1;
 newNode->ptr=*str;
 *str=newNode;
}
void DelFirst(struct Node** str)
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
void Del(struct Node** str, int x1 , int y1)
{
  struct Node* temp;
  temp=*str;
  struct Node* prev=NULL;
  while(temp!=NULL)
  { if(((temp->x)==x1)&&((temp->y)==y1))break;
    prev=temp;
    temp=temp->ptr;
  }
  if(temp==*str){

      DelFirst(str);
      return;
  }
  if(temp==NULL){
      cout<<"-1";
      return;
  }

  prev->ptr=temp->ptr;
  free(temp);

}

void Search_D(struct Node** str ,float d)
{
    struct Node* temp;
    temp=*str;
    int cnt=0;
	while(temp!=NULL)
	{

		int dist=(temp->x)*(temp->x)+(temp->y)*(temp->y);
		if(dist<=d*d){cnt=cnt+1;}
		temp=temp->ptr;
	}
  cout<<cnt;
}
int search_xy(struct Node** str ,int x1, int y1)
{
 struct Node* temp;
 temp=*str;
 while(temp!=NULL)
 {
  if((temp->x==x1)&&(temp->y==y1))return 1;
  temp=temp->ptr;
 }
  if(temp==NULL)return 0;

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
 struct Node* str = NULL;
 while(t--)
 {
  int ip;
  cin>>ip;
  if(ip==1)
  {
    int a,b;
    cin>>a>>b;
    AddFirst(&str,a,b);
  }
  if(ip==2)
  {
  DelFirst(&str);
  }
  if(ip==3)
  {
   int a,b;
    cin>>a>>b;
    Del(&str,a,b);
  }
  if(ip==4)
  {
    float d;
    cin>>d;
    Search_D(&str,d);
  }
  if(ip==5)
  {
    int a,b;
    cin>>a>>b;
    if(search_xy(&str,a,b))cout<<"True";
    else cout<<"False";
  }
  if(ip==6)
  {
  length(&str);
  }
 }
 return 0;
}
