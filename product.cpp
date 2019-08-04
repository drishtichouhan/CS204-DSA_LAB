#include <bits/stdc++.h>
using namespace std;
int main()
{

    int i,j,tmp;
    string str1,str2;
    cin>>str1;
    cin>>str2;
    int num1 = str1.length();
    
    int num2 = str2.length();
    
    int arr1[num1],arr2[num2];
    int pro[300]={0};
    
    
    for(i = num1-1,j=0;i>=0;i--,j++)
    {
        arr1[j] = str1[i]-'0';
    }
    for(i = num2-1,j=0;i>=0;i--,j++)
    {
        arr2[j] = str2[i]-'0';
    }
    for(i = 0;i < num2;i++)
    {
        for(j = 0;j < num1;j++)
        {
            pro[i+j] += arr2[i]*arr1[j];
        }
    }
    for(i = 0;i < num1+num2;i++)
    {
        tmp = pro[i]/10;
        pro[i] = pro[i]%10;
        pro[i+1] = pro[i+1] + tmp;
    }
    for(i = num1+num2; i>= 0;i--)
    {
        if(pro[i] > 0)
            break;
    }
    
    for(;i >= 0;i--)
    {
       cout<<pro[i];
    }
    return 0;
}
