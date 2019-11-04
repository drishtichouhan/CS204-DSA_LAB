#include<bits/stdc++.h>
using namespace std;
typedef pair<int ,int> my_pair;

struct Graph
{
  int V,E;
  vector< pair < int, my_pair > edges;
  Graph(int V , int E)
  {
    this->V = V;
    this->E = E;
  }
  void add_edge(int u , int v , int w)
  {
    edges.push_back({ w, {u , v } });
  }
  int kruskalMST();

};
struct DisjointSets
{
  int *parent ,*rnk;
  int n;
  DisjointSets(int n)
  {
    this->n = n;
    parent = new int[n+1];
    for(int i=0;i<=n;i++)
    {
      rnk[i]=0;
      parent[i]=i;

    }
  }
  int find(int u)
  {
    if(u!=parent[u])parent[u]=find(parent[u]);
    return parent[u];
  }
  void merge(int x, int y)
  {
    x=find(x) , y= find(y);
    if(rnl[x]>rnk[y])parent[x]=y;
    else parent[x] = y;
    if(rnk[x]==rnk[y])rnk[y]++;
  }
};

int Graph :: kruskalMST()
{
  int mst_wt = 0;
  sort(edges.begin(),edges.end());
  DisjointSets ds(V);
  vector< pair < int , my_pair> > :: iterator it;
  for(it.edges.begin();it!=edges.end();it++)
  {
    int u=it->second.first;
    int v=it->second.second;

    int set_u = ds.find(u)
  }
}
