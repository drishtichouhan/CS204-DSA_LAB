//BFS traversal of a graph built using adjacency matrices

#include<bits/stdc++.h>
using namespace std;

class Graph{
	int v;
	int e;
	int** adj;
	public:
			Graph(int v,int e);
			void addE(int src , int des);
			void BFS(int src);

};
void Graph::addE(int src, int e)
{


    adj[src][e] = 1;
    adj[e][src] = 1;
}

Graph :: Graph (int v , int e)
{
	this->v = v;
	this->e = e;
	adj = new int*[v];
	for (int r = 0; r < v ;r++)
	{
		adj[r] = new int[v];
		for(int c = 0;c < v;c++)
		{
			adj[r][c] = 0;
		}
	}

}
void Graph::BFS(int src)
{
	vector<bool> vis(v ,false);
	vector<int> q;
	q.push_back(src);
	vis[src] = true;
	int s;
	while(!q.empty())
	{
		s = q[0]; //visited vertex;
		cout<< s << " ";
		q.erase(q.begin());
		for(int i = 0; i < v; i++)
		{
			if(adj[s][i] == 1  &&  (!vis[i]))
			{
				q.push_back(i);
				vis[i] = true;
			}
		}
	}
}

int main()
{
	int ver,edg;
	cout<<"Enter the number of vertices"<<"\n";
	cin>>ver;
	cout<<"Enter the number of edges"<<"\n";
	cin>>edg;
	Graph GRAPH(ver , edg);
	cout<<"Enter vertex pairs which have an edge between them:"<<"\n";
	for(int i = 0;i < edg;i++)
	{

		int a,b;
		cin>>a>>b;
		GRAPH.addE(a,b);
	}
	cout<<"BFS of given graph is :"<<"\n";
	GRAPH.BFS(0);
}
