

#include <bits/stdc++.h>
#define longI long long int

#define mod 1000000007
#pragma GCC optimize ("-O2")
#define mod2 998244353
#define MAXN 1000000000
#define v32 vector<int>
#define v64 vector<lli>
#define v1024 vector <vector <int>>
#define v4096 vector <vector <lli>>
#define vt vector
#define f(x, y, z) for (lli x = y; x < z; x++)
#define fd(x, y, z) for (lli x = y; x > z; x--)
#define lb lower_bound
#define ld long double

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ist insert

using namespace std;

vector<string> Convert_string_to_vector(string s)
{
    int k = s.length();
    vector<string> str;
    for(int i = 0; i<k;i++)
    {
        string s1="";
        if((s[i] >= '0' && s[i] <= '9'))
        {
            int j = i;
            while(i!=s.size() && s[i] >= '0' && s[i] <= '9')
            {
                s1+=s[i];
                i++;
            }

            i--;
        }
        else
        {
            s1+=s[i];
        }
        str.push_back(s1);

    }

    return str;
}
int Precedence(string arr)
{
    if(arr == "^")
    return 3;
    else if(arr == "*" || arr == "/")
    return 2;
    else if(arr == "+" || arr == "-")
    return 1;
    else
    return -1;
}
vector<string> IN_to_PO(vector<string> temp)
{
    stack<string> array;
    array.push("N");
    int l = temp.size();
    vector<string> vec;
    for(int i = 0; i < l; i++)
    {
        if((temp[i][0] >= '0' && temp[i][0] <= '9'))
            vec.push_back(s[i]);
        else if(temp[i] == "(")
           array.push("(");
        else if(temp[i] == ")")
        {
            while(array.top() != "N" && array.top() != "(")
            {
                string c = array.top();
                array.pop();
                vec.push_back(c);
            }
            if(array.top() == "(")
            {
                string c = array.top();
                array.pop();
            }
        }
        else{
            while(array.top() != "N" && Precedence(temp[i]) <= Precedence(array.top()))
            {
                string c = array.top();
                array.pop();
                vec.push_back(c);
            }
            array.push(temp[i]);
        }

    }
    while(array.top() != "N")
    {
        string c = array.top();
        array.pop();
        vec.push_back(c);
    }

    return vec;

}

struct node
{
  string s;
  node* LEFT=NULL;
  node* RIGHT=NULL;
};
longI EVALUATION(node *root)
{
   string s=root->s;
   longI result=0;
   if(s!="+" && s!="-" && s!="*" && s!="/" && s!="^")
   return stoi(s);
   else
   {
     int lans=EVALUATION(root->LEFT),rans=EVALUATION(root->RIGHT);
     if(s=="+")
       result=lans+rans;
     else if(s=="-")
       result=lans-rans;
     else if(s=="*")
       result=lans*rans;
     else if(s=="/")
       result=lans/rans;
     else
     {
       result=1;
       for(longI=0;i<rans;i++)ans*=lans;
     }
   }
   return result;
}
node* TREE_CONSTRUCT(vector <string> postfix)
{
   node *root=NULL;
   vt <node*> stk;
   int i=0;
   while(i!=postfix.size())
   {
     if(postfix[i]!="+" && postfix[i]!="-" && postfix[i]!="*" && postfix[i]!="/" && postfix[i]!="^")
       {
         node *temp=(node *)malloc(sizeof(node));
         temp->s=postfix[i];
         f(j,0,postfix[i].size())
         if(postfix[i][j]<'0' || postfix[i][j]>'9')return NULL;
         stk.push_back(temp);
       }
     else
     {
       if(stk.size()<2)return NULL;
       node *s1=stk.back();
       stk.pop_back();
       node *s2=stk.back();
       stk.pop_back();
       node *temp=(node *)malloc(sizeof(node));
       temp->s=postfix[i];
       temp->LEFT=s2;
       temp->RIGHT=s1;
       stk.push_back(temp);
     }
     i++;
   }
   if(stk.size()!=1)return NULL;
   return stk.back();
}

int main()
{
  fastio;
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(longI=0;i<n;i++)
    {
      string s;cin>>s;
      vector <string> converted=stringTovector(s);
      converted=IN_to_PO(converted);
      node* root=TREE_CONSTRUCT(converted);
      if(root!=NULL)
      cout<<EVALUATION(root)<<"\n";
      else cout<<"CANT BE EVALUATED\n";
    }
  }
  return 0;
}
