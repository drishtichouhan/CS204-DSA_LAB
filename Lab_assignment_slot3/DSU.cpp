/*Given input no. of vertices and no. of edges and the edges, determine whether
the graph is cyclic or not*/

#include <bits/stdc++.h>
using namespace std;
const int N= 4e6;

vector <pair <int, int> > edges;
int rank_n[N];
int parent[N];

int find_r(int x)
{
    if(x!=parent[x])
    {
        //Path_compression
        parent[x]= find_r(parent[x]);
    }

    return parent[x];
}

void union_do(int x, int y)
{
    int rx= find_r(x);
    int ry= find_r(y);
    if(rx!=ry)
    {

        if(rank_n[rx]<rank_n[ry])
        {
            parent[rx]= ry;
        }
        else if(rank_n[rx]>rank_n[ry])
        {
            parent[ry]= rx;
        }
        else if(rank_n[rx]==rank_n[ry])
        {
       e
            parent[rx]= ry;
            rank_n[ry]++;
        }
    }
}

bool is_cyclic()
{
    for(int i=0; i<edges.size(); i++)
    {
        int rx= find_r(edges[i].first);
        int ry= find_r(edges[i].second);
        if(rx==ry)
        {

            return 1;
        }

        union_do(rx, ry);
    }
    return 0;
}

int main()
{
    // n is no of vertices, e is no of edges
    int n;
    cin>> n;

    for(int i=1; i<=n; i++)
    {
        parent[i]=i;
        rank_n[i]=0;
    }

    int e;
    cin>> e;
    for(int i=0; i<e; i++)
    {

        int x, y;
        cin>>x >>y;
        edges.push_back({x,y});
    }
    if(is_cyclic())
    {
        cout<< "Given graph is cyclic";
    }
    else
    {
        cout<< "Given graph is acyclic";
    }

}
