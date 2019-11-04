#include <bits/stdc++.h> 
using namespace std; 
  

stack<int> sort_Stack(stack<int> input) 
{ 
    stack<int> tmp; 
  
    while (!input.empty()) 
    { 
        
        int temp = input.top(); 
        input.pop(); 
  
        
        while (!tmp.empty() && tmp.top() < temp)
        { 
            input.push(tmp.top()); 
            tmp.pop(); 
        } 
  
        
        tmp.push(temp); 
    } 
  
    return tmp; 
} 
  
void sortArray(int arr[], int n) 
{ 
   
    stack<int> input; 
    for (int i=0; i<n; i++) 
       input.push(arr[i]);

    stack<int> tmpStack = sort_Stack(input);  
    for (int i=0; i<n; i++) 
    { 
        arr[i] = tmpStack.top(); 
        tmpStack.pop(); 
    } 
} 
  

int main() 
{ 
    cout<<"Enter no. of elements:"<<"\n";
    int num;
    cin>>num;

    int arr[num];
    cout<<"Enter elements"<<"\n";
    for(int i=0;i<num;i++)cin>>arr[i];
    int n = sizeof(arr)/sizeof(arr[0]); 
  
    sortArray(arr, n); 
  
    for (int i=0; i<n; i++) 
       cout << arr[i] << " "; 
  
    return 0; 
}