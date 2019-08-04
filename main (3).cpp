#include<bits/stdc++.h>
using namespace std;




bool isSmaller(string a, string b)
{
    int n1 = a.length(), n2 = b.length();

    if (n1 < n2)return true;
    if (n2 < n1)return false;

    for (int i=0; i<n1; i++)
    if (a[i] < b[i])return true;
         
    else if (a[i] > b[i])return false;
         

       return false;
}
string SUMALGO(string str1, string str2)
{

    if (str1.length() > str2.length())
        swap(str1, str2);

    string str = "";
    int n1 = str1.length(), n2 = str2.length();
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
    int carry = 0;
    for (int i=0; i<n1; i++)
    {
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
    for (int i=n1; i<n2; i++)
    {
        int sum = ((str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
    if (carry)
        str.push_back(carry+'0');

    reverse(str.begin(), str.end());

    return str;
}



string subtract(string str1, string str2)
{

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
    string ans="";
    int a=0;
    for(int i=0;i<str.length();++i)
    {
        if(str[i]!='0')
            a=1;
        if(a==1)
            ans.push_back(str[i]);
       
    }
    if(ans=="")ans="0";
    return ans;
}

string remain(string str1, string str2)
{
        int n=str1.length();
        int m=str2.length();
        if(n<m)
        {
            return str1;
        }
        else
        {
            string rem;
            string q;
            int i;
            
            for( i=0;i<m;++i)rem.push_back(str1[i]);
            if(isSmaller(rem, str2)){rem.push_back(str1[i]);i++;}

            while(i<=n)
            {
                int q1=0;
                while(!isSmaller(rem, str2)){rem=subtract(rem, str2);q1++;}
                
                q.push_back(q1+'0');
                if(i<n)
                {rem.push_back(str1[i]);}
                int j=0;
                for(;j<rem.length();j++)if(rem[j]!='0')break;
                if(j==rem.length())rem="0";
                i++;
            }
            return rem;
        }
}

int main()
{
    int t;
    cin>>t;
    cin>>ws;
    while(t--)
    {
        string arr;
        cin>>arr;
        int n=arr.length();
        if(n==1&&arr=="1")
            {cout<<"Not a Prime"<<endl;}
        else if(n==1&&arr=="2")
            {cout<<"Prime"<<endl;}
        else
        {
            string arr2="2";bool ip=true;
            while(arr2.length()<=(n/2+1)&&isSmaller(arr2, arr))
            {
                string r=remain(arr, arr2);
                if(r=="0")
                    {cout<<"Not a Prime"<<endl;ip=false;break;}
                arr2=SUMALGO(arr2, "1");

            }
            if(ip==true)cout<<"Prime"<<endl;
        }

    }
    return 0;
}