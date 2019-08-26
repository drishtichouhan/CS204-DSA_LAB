#include <bits/stdc++.h>
#include <stack>
#include <string>
#include <math.h>
#include <vector>
#include<map>
using namespace std;

//node decleration
struct node
{
  string s;
  struct node* LEFT;
  struct node* RIGHT;
};

//node construction
struct node* create(string array)
{
  struct node* tmp= (struct node*)malloc(sizeof(struct node));
  tmp->LEFT = NULL;
  tmp->RIGHT = NULL;
  tmp->s = array;
  return tmp;
}


//precedence function
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

//this function constructs the expression tree
struct node* TREE_CONSTRUCT(string expr,map <string,int> *mp)
{
  stack<char> temp;
  stack<struct node* > arr;

  int flag=0;//this flag distinguishes between unary and binary minus
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
      flag=0;
      temp.push(expr[i]);

    }
    else if(expr[i]=='*' || expr[i] == '-' || expr[i]=='+' || expr[i]=='^' || expr[i]=='/')
    {
      if(temp.empty() == 1)
      {

        temp.push(expr[i]);
      }
      else
      {
        if(expr[i]=='^' && temp.top()=='^')
        {
          temp.push(expr[i]);
        }
          else if(Precedence(temp.top()) < Precedence(expr[i]))
          {
            if(flag==0)
            {
              flag=1;
            }

           temp.push(expr[i]);

          }
        else
        {
          while(temp.empty() == 0)
          {
           if(Precedence(temp.top()) >= Precedence(expr[i]))
           {
            string a=" ";
            a[0] = temp.top();
            temp.pop();
            struct node* Node = create(a);
            Node->RIGHT = arr.top();
            arr.pop();
            struct node* min = create("0");

            if(arr.empty()==1)
            {
              Node->LEFT = min;
            }
            else
            {
              Node->LEFT = arr.top();
              arr.pop();
            }
            arr.push(Node);
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
          struct node* Node = create(a);
          Node->RIGHT = arr.top();
          arr.pop();
          struct node* min = create("0");

          if(arr.empty()==1)
          {
              Node->LEFT = min;
          }
          else if(flag==1)
          {
            Node->LEFT=min;
          }
          else
          {
            Node->LEFT = arr.top();
            arr.pop();
          }
          arr.push(Node);
      }

      temp.pop();
    }
    else
    {
      int x=i;
      string str;
      for(x;x<expr.length();x++)
      {
        if(!((expr[x]>='a'&&expr[x]<='z')||(expr[x]>='A'&& expr[x]<='Z')))
        {
          break;
        }
        str.push_back(expr[x]);
      }
        auto itr1 = (*mp).find(str);

        if(itr1 == (*mp).end())
        {
            return NULL;
        }
        else{
            string value = to_string(itr1->second);

            arr.push(create(value));

        }
        i =x-1;
      }
    }



    while(temp.empty()!= 1)
    {
      string a=" ";
      a[0] = temp.top();

      temp.pop();
      struct node* Node = create(a);
      Node->RIGHT = arr.top();
      arr.pop();
      struct node* min = create("0");
      if(arr.empty()==1)
      {
        Node->LEFT = min;
      }
      else
      {
        Node->LEFT = arr.top();
        arr.pop();
      }
      arr.push(Node);
    }

  return arr.top();

}

int EVALUATE(struct node *head)
{
  if(head==NULL)
  {
    return INT_MIN;
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
return INT_MIN;
}
int main()
{
  int test ;
  cin>>test ;
  vector<int> vec;
  for(int i=0;i<test;i++)
  {
    int n;
    cin>>n;
    map<string,int> mapping;
    for(int j=0;j<n;j++)
    {
      string str;
      cin>>str;
      int check=0;
      for(int p=0;p<str.length();p++)
      {
                if(str[p]=='=')
                {
                    check=1;
                    string s1,s2;
                    s1 = str.substr(0,p);
                    s2 = str.substr(p+1,str.length());
                    auto itr = mapping.find(s1);
                    if(itr == mapping.end())
                    {
                        if(EVALUATE(TREE_CONSTRUCT(s2,&mapping))==INT_MIN)
                        {
                            vec.push_back(INT_MIN);
                        }
                        else{
                            mapping[s1] = EVALUATE(TREE_CONSTRUCT(s2,&mapping));
                        }
                    }
                    else
                    {
                        if(EVALUATE(TREE_CONSTRUCT(s2,&mapping))==INT_MIN)
                        {
                            vec.push_back(INT_MIN);
                        }
                        else{
                            itr->second = EVALUATE(TREE_CONSTRUCT(s2,&mapping));
                        }
                    }
                }
			}
      if((check==0))
      {
        vec.push_back(EVALUATE(TREE_CONSTRUCT(str,&mapping)));
      }

    }
  }
  for(int k=0;k<vec.size();k++)
  {
    if(vec[k] == INT_MIN)
    {
              cout<<"CANNOT BE EVALUATED"<<endl;
    }
    else
    {
    cout<<vec[k]<<endl;
  }
 }

  return 0;
}
