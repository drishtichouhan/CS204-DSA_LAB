#include<bits/stdc++.h>
using namespace std;

bool is_bipartite(vector <vector <int>> graph , int first , int* color_array)
{
  bool res=1;
  for(int i=0;i<graph[first].size();i++)
  {
    if(color_array[graph[first][i]]==0)
    {
      color_array[graph[first][i]]=3-color_array[first];
      res=res&is_bipartite(graph,i,color_array);
    }
    else if((color_array[graph[first][i]]==1)&&(color_array[first]==1)||(color_array[graph[first][i]]==2)&&(color_array[first]==2))
    {
      return 0;
    }

  }
  return res;

}
int main()
{
  long long int ver,edg;

  cin>>ver>>edg;
  vector <vector<int> > graph(ver+edg);


  for(int i=0;i<edg;i++)
  {
    int a,b,c;
    cin>>a>>b>>c;

    if(c%2==0)
    {
      
      ver++;
      graph[ver-1].push_back(a-1);
      graph[ver-1].push_back(b-1);
      graph[a-1].push_back(ver-1);
      graph[b-1].push_back(ver-1);

    }
    else
    {
      graph[a-1].push_back(b-1);
      graph[b-1].push_back(a-1);
    }
  }

  int c[ver]={0};
 bool result=1;
  for(int i=0;i<ver;i++)
  {
    if(c[i]==0)
    {
      c[i]=1;
      result=is_bipartite(graph,i,c);
    }
    if(result==0)break;
  }
  if(result)cout<<"YES";
	else cout<<"NO";


}