
  

/*Create a linked list where each node contains x and y coordinates of a point. Implement the
following functions:
1. AddFirst(a,b)
This function adds a point containing ‘a’ as x-coordinate and ‘b’ as ycoordinate at the start of the linked list.
2. DelFirst()
This function deletes the first element in the linked list.
If it is not in the list or list is empty, print -1
3. Del (a,b)
This function deletes the node with point containing ‘a’ as x-coordinate and ‘b’ as ycoordinate.
If it is not in the list or list is empty, print -1
4. Search(d)
This function gives all the points that are present at atmost ‘d’ distance (Euclidean)
from the origin.
If such points exist, print the number of such points.
Else print -1
5. Search(a,b)
This function prints True, if there exists a point with ‘a’ as x-coordinate and ‘b’ as ycoordinate in the linked list.
Else it prints False
6. Length()
This function prints the length of the linked list, i.e., the number of nodes present in
the list.


Input Format:
• Each line of the input contains F representing the function number followed by space
separated Ai argument(s) if required for the corresponding function.


Example Input:
• 1 2 3 (Adds node with (2,3) coordinate point at the beginning of the linked list)
• 1 3 4 (Adds node with (3,4) coordinate point at the beginning of the linked list)
• 1 5 6 (Adds node with (5,6) coordinate point at the beginning of the linked list)
• 1 1 1 (Adds node with (1,1) coordinate point at the beginning of the linked list)
• 1 2 9 (Adds node with (2,9) coordinate point at the beginning of the linked list)
• 2 (Deletes the node at the beginning of the linked list i.e., (2,9))
• 3 1 1 (Deletes the node with (1,1) coordinate point from the linked list)
• 4 5
• 5 2 3
• 5 4 6
• 6
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;


struct node{
int x;
int y;
struct node *next;


};
struct node *createNode()
{
    struct node *temp;
temp = (struct node *) malloc(sizeof(struct node));
return temp;
}

void AddFirst(struct node** head,int a,int b){

      struct node *newNode;
newNode = createNode();
if(newNode == NULL)
{
cout<<"Cannot create new node."<<endl;
 return;
}
newNode->x = a;
newNode->y = b;
newNode->next = *head;
*head = newNode;

}

int DelFirst(struct node **head){
    struct node *temp;
if(*head == NULL){
return -1;}

else {
temp = *head;
*head = (*head)->next;
free(temp);
return 0;

}
}


int Del(struct node **start,int x1, int y1){
 	struct node *temp = *start;
 	struct node *prev = NULL;
 	while(temp != NULL){
 		if(temp->x == x1 && temp->y == y1){
 			if(temp == *start){
 				int x=DelFirst(start);
 				return x;
 			}
 			prev->next = temp->next;
 			free(temp);
 			return 0;
 		}
 		else{
 			prev = temp;
 			temp = temp->next;
 		}
 	}
 	return -1;
 }

string searchs(struct node *head, int a,int b){
    struct node *temp;
    temp = head;
     if(temp == NULL){
return "False";}
    while(temp != NULL){
    if(temp->x == a && temp->y ==b) break;
    else temp = temp->next;
    }
            if(temp == NULL)
		return "False";
else
            return "True";
}

int Length(struct node *head){
     struct node *temp;
       temp=head;
       int len=0;
       while(temp != NULL){
            temp= temp->next;
            len++;
       }
       return len;

}


int searchd(struct node *head,int d){
    struct node *temp=head;

	int cnt=0;
    while(1){
        if(temp==NULL){

            break;
        }
         if(d>=sqrt(((temp->x)*(temp->x)+(temp->y)*(temp->y)))){
            cnt++;

        }


     temp=temp->next;

    }

    if(cnt==0){return -1;}
	else{return cnt;}



}
void printList(struct node *head)
{
struct node *temp;
temp = head;
while(temp != NULL)
{
   cout<<"("<<temp->x<<","<<temp->y<<")"<<" ";
temp = temp->next;
}
}


int main()
{
    struct node *start=NULL;

	int n;
	cin>>n;
	int A[n][3];
	for(int i=0;i<n;i++){
		cin>>A[i][0];
		switch (A[i][0]){
			case 1: cin>>A[i][1]>>A[i][2];break;
			case 3: cin>>A[i][1]>>A[i][2];break;
			case 5: cin>>A[i][1]>>A[i][2];break;
			case 2: break;
			case 6: break;
			case 4: cin>>A[i][1];break;
		}
	}
	cout<<endl;
	for(int i=0;i<n;i++){

		switch (A[i][0]){
			case 1: AddFirst(&start,A[i][1],A[i][2]);break;
			case 2:	if(DelFirst(&start)==-1){cout<<DelFirst(&start)<<endl;}
			          break;
			case 3: if(Del(&start,A[i][1],A[i][2])==-1) {cout<<Del(&start,A[i][1],A[i][2])<<endl;}
			            break;
			case 4:	cout<<searchd(start,A[i][1])<<endl;break;
			case 5: cout<<searchs(start,A[i][1],A[i][2])<<endl;break;
			case 6: cout<<Length(start)<<endl;break;
		}
	}
	return 0;
}
