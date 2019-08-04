#include<bits/stdc++.h> 
using namespace std; 
  

string SUMALGO(string arr1, string arr2) 
{ 
    int l2,l1,i;
    if (arr1.length() > arr2.length()) 
        swap(arr1, arr2); 
  
    
    string result = ""; 
  

     l1 = arr1.length();
     l2 = arr2.length(); 
  
    
    reverse(arr1.begin(), arr1.end()); 
    reverse(arr2.begin(), arr2.end()); 
  
    int carry = 0; 
    for ( i=0; i<l1; i++) 
    { 
         
        int sum = ((arr1[i]-'0')+(arr2[i]-'0')+carry); 
        result.push_back(sum%10 + '0'); 
  
         
        carry = sum/10; 
    } 
  
     
    for ( i=l1; i<l2; i++) 
    { 
        int sum = ((arr2[i]-'0')+carry); 
        result.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
  
     
    if (carry) 
        result.push_back(carry+'0'); 
  
    
    reverse(result.begin(), result.end()); 
  
    return result; 
} 
  
int main() 
{ 
    string str1,str2;
    
    cin>>str1;
    cin>>str2;
    cout << SUMALGO(str1, str2); 
    return 0; 
} 
