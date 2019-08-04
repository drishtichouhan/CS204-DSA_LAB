#include <bits/stdc++.h> 
using namespace std; 
  

pair<string,int> Division(string dividend, int divisor) 
{ 
    
    string quotient; 
    
    int i = 0; 
    int sub = dividend[i] - '0'; 
    while (sub < divisor) 
       sub = sub * 10 + (dividend[++i] - '0'); 
      
    
    while (dividend.size() > i) 
    { 
        
        quotient += (sub / divisor) + '0'; 
          
     
        sub = (sub % divisor) * 10 + dividend[++i] - '0'; 
    } 
      
    
    if (quotient.length() == 0) 
        quotient="0"; 
    
    pair<string,int> v={quotient,(sub+'0')/10};
    return v;
} 
  

int main() 
{ 
    string div;
    int divisor;
    cin>>div;
    cin>>divisor;
	pair<string,int> v=Division(div,divisor);
cout<<v.first<<endl<<v.second<<endl;
    //cout << Division(div, divisor);     
    return 0; 
} 
