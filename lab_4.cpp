#include <bits/stdc++.h>
#define longI long long int
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)


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
vector<string> INFIX_to_POSTFIX(vector<string> temp)
{
    stack<string> array;
    array.push("N");
    int l = temp.size();
    vector<string> vec;
    for(int i = 0; i < l; i++)
    {
        if((temp[i][0] >= '0' && temp[i][0] <= '9'))
            vec.push_back(temp[i]);
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
                if(temp[i]=="^"&&array.top()=="^")break;
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
     int left= EVALUATION(root->LEFT);
     int right=EVALUATION(root->RIGHT);
     if(s=="+")
       result=left+right;
     else if(s=="-")
       result=left-right;
     else if(s=="*")
       result=left*right;
     else if(s=="/")
       result=left/right;
     else
     {
       result=1;
       for(longI i =0;i<right;i++)result*=left;
     }
   }
   return result;
}
node* TREE_CONSTRUCT(vector <string> postfix)
{
   node *root=NULL;
   vector <node*> yolo;
   int i=0;
   while(i!=postfix.size())
   {
     if(postfix[i]!="+" && postfix[i]!="-" && postfix[i]!="*" && postfix[i]!="/" && postfix[i]!="^")
       {
         node *temp=(node *)malloc(sizeof(node));
         temp->s=postfix[i];
         for(longI j=0;j<postfix[i].size();j++)
         if(postfix[i][j]<'0' || postfix[i][j]>'9')return NULL;
         yolo.push_back(temp);
       }
     else
     {
       if(yolo.size()<2)return NULL;
       node *s1=yolo.back();
       yolo.pop_back();
       node *s2=yolo.back();
       yolo.pop_back();
       node *temp=(node *)malloc(sizeof(node));
       temp->s=postfix[i];
       temp->LEFT=s2;
       temp->RIGHT=s1;
       yolo.push_back(temp);
     }
     i++;
   }
   if(yolo.size()!=1)return NULL;
   return yolo.back();
}

int main()
{
  fastio;
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    for(longI i=0;i<n;i++)
    {
      string s;
      cin>>s;
      vector <string> converted=Convert_string_to_vector(s);
      converted=INFIX_to_POSTFIX(converted);
      node* root=TREE_CONSTRUCT(converted);
      if(root!=NULL)
      cout<<EVALUATION(root)<<"\n";
      else cout<<"CANT BE EVALUATED\n";
    }
  }
  return 0;
}

  
