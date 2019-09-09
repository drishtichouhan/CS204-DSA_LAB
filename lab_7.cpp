#include<bits/stdc++.h>
using namespace std;
int Append(string x , string y)
{
  string XY = x.append(y);
  string YX = y.append(x);
  if(XY.compare(YX)>0)
  { return 1;}
  else return 0;

}

void output(vector<string> str)
{
  sort(str.begin(),str.end(),Append);

  for(int i=0;i<str.size();i++)
  {
    cout<< str[i];

  }
}
int main()
{
  long long int test;
  cin>>test;
  for(int k=0;k<test;k++)
  {
    vector <string> input;
    long long int lines;
    cin>>lines;

    for(int j=0;j<lines;j++)
    {
      string s;
      cin>>s;
      input.push_back(s);
    }
    cout<< " The longest concatenation possible is :";
    output(input);
  }
}
