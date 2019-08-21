#include <bits/stdc++.h>
#include <stack>
#include <string>
#include <math.h>
#include <vector>
using namespace std;


struct node
{
  string s;
  struct node* LEFT;
  struct node* RIGHT;
};

struct node* create(string array)
{
  struct node* tmp= (struct node*)malloc(sizeof(struct node));
  tmp->LEFT = NULL;
  tmp->RIGHT = NULL;
  tmp->s = array;
  return tmp; 
}

int Precedence(char a)
{
  if(a =='(')
  {
    return -1;
  }
  else if(a=='^')
  {
    return 3;
  }
  else if(a=='*' || a=='/')
  {
    return 2;
  }
  else if(a=='+' || a=='-')
  {
    return 1;
  }
}
struct node* TREE_CONSTRUCT(string expr)
{
  stack<char> temp;
  stack<struct node* > arr;
  for(int i=0;i<expr.length();i++)
  {
    if(expr[i]>='0' && expr[i]<='9')
    {
      int j=i;
      int k=0;
      while(expr[j]>='0' && expr[j]<='9')
      {
        k = k*10 + (expr[j] - '0');
        j++;
      }
      string tmp1 = to_string(k);
      
      arr.push(create(tmp1));
      i = j-1;
    }
    else if(expr[i] == '(')
    {
      temp.push(expr[i]);

    }
    else if(expr[i]=='*' || expr[i] == '-' || expr[i]=='+' || expr[i]=='^' || expr[i]=='/')
    {
      if(temp.empty() == 1)
      {
        
        temp.push(expr[i]);
      }
      else{
        if(expr[i]=='^' && temp.top()=='^')
        {
          temp.push(expr[i]);
        }
          else if(Precedence(temp.top()) < Precedence(expr[i]))
          {
            
           temp.push(expr[i]);

          }
        else{
          while(temp.empty() == 0)
          {
           if(Precedence(temp.top()) >= Precedence(expr[i]))
           {
            string a=" ";
            a[0] = temp.top();
            temp.pop();
            struct node* n = create(a);
            n->RIGHT = arr.top();
            arr.pop();
            struct node* min = create("0");
            
            if(arr.empty()==1)
            {
              n->LEFT = min;
            }
            else
            {
              n->LEFT = arr.top();
              arr.pop();
            }
            arr.push(n);
          }
          }
          temp.push(expr[i]);
        }
      }
    }

    
    else if(expr[i]==')')
    {
      
      while(temp.top() !='(')
      {
          string a=" ";
          a[0] = temp.top();
          temp.pop();
          struct node* n = create(a);
          n->RIGHT = arr.top();
          arr.pop();
          struct node* min = create("0");
          
          if(arr.empty()==1)
          {
              n->LEFT = min;
          }
          else
          {
            n->LEFT = arr.top();
            arr.pop();
          }
          arr.push(n);
      }
      
      temp.pop();
    }
    
  
  }
    while(temp.empty() != 1)
    {
      string a=" ";
      a[0] = temp.top();
      
      temp.pop();
      struct node* n = create(a);
      n->RIGHT = arr.top();
      arr.pop();
      struct node* min = create("0");
      if(arr.empty()==1)
      {
        n->LEFT = min;
      }
      else
      {
        n->LEFT = arr.top();
        arr.pop();
      }
      arr.push(n);
    }
  
  return arr.top();

}

int EVALUATE(struct node *head)
{
  if(head==NULL)
  {
    return -1;
  }
  if(head->LEFT == NULL && head->RIGHT == NULL)
  {
    
    return stoi(head->s);
  }
  
  int left  = EVALUATE(head->LEFT);
  int right = EVALUATE(head->RIGHT);
  
  string str = head->s;
  if(str[0] == '+')
  {
    
    return left + right;
  }
  if(str[0] == '*'){
    
    return left *  right;
  }
  if(str[0] == '-')
  {
    
    return left - right;
  }
  if(str[0] == '/')
  {
      
    return left / right;
  }
  if(str[0] == '^')
  {
      
    return pow(left,right);
  }
return -1;
}
int main()
{
  int test ;
  cin>>test ;
  vector< vector<int> > exp(test);
  for(int i=0;i<test;i++)
  {
    int n;
    cin>>n;
    for(int j=0;j<n;j++)
    {
      string str;
      cin>>str;
      exp[i].push_back(EVALUATE(TREE_CONSTRUCT(str)));
    }
  }
  for(int k=0;k<test;k++)
  {
    for(int j=0;j<exp[k].size();j++)
    {
      cout<<exp[k][j]<<endl;
    }
  }
  
  return 0;
}
