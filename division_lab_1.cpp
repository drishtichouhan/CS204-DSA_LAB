
    
#include <bits/stdc++.h>

using namespace std;



string subtract(string str1,string str2)
{
 string result;
    int idx=0;
    if(IsBigger(str1,str2)){
        swap(str1,str2);
        idx=1;
    }

    int x=str1.length(),y=str2.length();
    int diff=x-y,carry=0;

    for(int i=y-1;i>=0;i--){
        int sub=(str1[diff+i]-'0')-(str2[i]-'0')-carry;
        if(sub<0){
            sub+=10;
            carry=1;
            result += to_string(sub);
        }
        else{
            result += to_string(sub);
            carry=0;
        }
    }
    for(int i=diff-1;i>=0;i--){
        if(str1[i]=='0'&& carry){
            result += to_string(9);
            continue;
        }
        int sub=(str1[i]-'0')-carry;
        if( i>0 || sub >0){
            result += to_string(sub);
        }
    }
    if(idx){result.append("-");}

    reverse(result.begin(),result.end());

    return result;
}
int IsBigger(string str1,string str2){
    int l1 = str1.length();
    int l2 = str2.length();
    if(l2>l1){
        return 1;
    }
    else{
        int i=0;
        if(l1==l2){
            while(str1[i]==str2[i]){
                i++;
            }
            if(i>l1){return 0;}
            if(str2[i]>str1[i])
            {
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    int t;
    cin>>t;
    while(t>=1){
      string divi;
      string divisor;
      cin>>divi;
      cin>>divisor;
      if(IsBigger(divi,divisor)){
          cout<<0<<endl<<divi;
          return 0;
      }
      int order=divi.length()-divisor.length()+1;
      char str[order];
      for(int i=0;i<order;i++){
          str[i]='0';
      }
      while(!IsBigger(divi,divisor)){
          int n=divi.length()-divisor.length();
          string copy=divisor;
          if(divi[0]<divisor[0]){
              for(int i=1;i<n;i++)copy.push_back('0');
              int quo=0;
              while(!IsBigger(divi,copy)){
                   divi = subtract(divi,copy);
                  quo++;
              }
              str[order-n]=quo +'0';
          }
          else{
              for(int i=0;i<n;i++)copy.push_back('0');
              int quo=0;
              while(!IsBigger(divi,copy)){
                   divi = subtract(divi,copy);
                   quo++;
              }
              str[order-1-n]=quo+'0';
          }

      }
      int l = 0;
      while(str[l]=='0'){
          l++;
      }
      for(int i = l;i<order;i++){
              if(str[i]<49 || str[i]>58){cout<<'0';}
          else{cout<<str[i];}
      }
      cout<<endl<<divi<<endl;
      t--;
    }
    return 0;
}
