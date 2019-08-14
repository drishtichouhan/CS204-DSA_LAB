#include<bits/stdc++.h>
using namespace std;
int check(string exp)
{

  int x=0;
  for(int i=0;i<exp.length();i++)
  {
    if(exp[i]=='{'||exp[i]=='['||exp[i]=='('||exp[i]=='<'||exp[i]=='|'||exp[i]=='}'||exp[i]==']'||exp[i]==')'||exp[i]=='>')
    {
    }
    else
    {
      x=1;
      break;
    }
  }
  return x;
}
bool Matching_parantheses(string str)
{
  stack<char> arr;
  arr.push('0');
  char x;
  for(int i=0;i<str.length();i++)
  {
    if(str[i]=='('||str[i]=='['||str[i]=='{'||str[i]=='<')
    {
      arr.push(str[i]);
      continue;
    }

    if(str[i]==')')
    {
      x=arr.top();
      arr.pop();
      if(x!='(')return false;

    }
    if(str[i]=='}')
    {
      x=arr.top();
      arr.pop();
      if(x!='{')return false;

    }
    if(str[i]==']')
    {
      x=arr.top();
      arr.pop();
      if(x!='[')return false;

    }
    if(str[i]=='>')
    {
      x=arr.top();
      arr.pop();
      if(x!='<')return false;

    }
    if(str[i]=='|')
    {
      x=arr.top();
      if(x=='|')arr.pop();
      else arr.push(str[i]);


    }

  }
   if(arr.top()=='0')return true;
   else return false;
}


int main()
{
  int t;
  cin>>t;
  for(int j=0;j<t;j++)
  {
    string exp;
    cin>>exp;
    if(check(exp)==1)
    {
      cout<<"NO";
    }

    else
    {
      if(Matching_parantheses(exp))
      {
        cout<<"YES";
      }
      else cout<<"NO";
    }

 }


  return 0;
}
