#include<bits/stdc++.h> 
using namespace std; 
  
  

  
 
string subtraction(string str1, string str2) 
{ 

    
    if (str1.length()<str2.length()) 
        swap(str1, str2); 
  
    
    string str = ""; 
  
     
    int n1 = str1.length(), n2 = str2.length(); 
  

    reverse(str1.begin(), str1.end()); 
    reverse(str2.begin(), str2.end()); 
      
    int carry = 0; 
  
    
    
    for (int i=0; i<n2; i++) 
    { 
        
        int sub = ((str1[i]-'0')-(str2[i]-'0')-carry); 
          
         
        if (sub < 0) 
        { 
            sub = sub + 10; 
            carry = 1; 
        } 
        else
            carry = 0; 
  
        str.push_back(sub + '0'); 
    } 
  
    
    for (int i=n2; i<n1; i++) 
    { 
        int sub = ((str1[i]-'0') - carry); 
          
         
        if (sub < 0) 
        { 
            sub = sub + 10; 
            carry = 1; 
        } 
        else
            carry = 0; 
              
        str.push_back(sub + '0'); 
    } 
  
    
    reverse(str.begin(), str.end()); 
  
    return str; 
} 
  
 
int main() 
{ 
    cin>>t;
    for(i=0;i<t;i++)
    {
       string num1,num2;
    
       cin>>num1;
    
        cin>>num2;
    
         cout << subtraction(num1, num2) << endl; 
    }
      
    
    
      
    return 0; 
} 

