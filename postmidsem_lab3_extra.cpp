#include <bits/stdc++.h> 

using namespace std;

int traverse(vector<vector<int>> GRAPH,vector<vector<int>> &SEEN,int x, int y, int color);
int find(vector<vector<int>> GRAPH,vector<vector<int>> SEEN);
int main()
{
	int rows,cols,c;

	cin>>rows>>cols>>c;
	vector<vector<int>> GRAPH;
	vector<vector<int>> SEEN;
	GRAPH.resize(rows, vector<int>(cols, 0));
	SEEN.resize(rows, vector<int>(cols, 0));
	for (auto &it : SEEN)
	{
    	fill(it.begin(), it.end(), 0);
	}
	
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)
		{
			
			cin>>GRAPH[i][j];
		}
	}
	
	cout<<find(GRAPH,SEEN)<<endl;

	return 0;
}
int traverse(vector<vector<int>> GRAPH,vector<vector<int>> &SEEN,int x, int y, int color)
{
	
	int rows=GRAPH.size();
	int cols=GRAPH[0].size();
	int res=1;
	
	SEEN[x][y]=1;
	if((x<(rows-1)) && (!SEEN[x+1][y]) && (GRAPH[x+1][y]==color)) 
	{
		
		res+=traverse(GRAPH,SEEN,x+1,y,color);
	}
	if((y<(rows-1)) && (!SEEN[x][y+1]) && (GRAPH[x][y+1]==color)) 
	{
		
		res+=traverse(GRAPH,SEEN,x,y+1,color);
	}
	if(x>0 && (!SEEN[x-1][y]) && (GRAPH[x-1][y]==color))
	{
		
		res+=traverse(GRAPH,SEEN,x-1,y,color);
	}
	else if((y>0) && (!SEEN[x][y-1]) && (GRAPH[x][y-1]==color)) 
	{
		
		res+=traverse(GRAPH,SEEN,x,y-1,color);
	}
	return res;

}
int find(vector<vector<int>> GRAPH,vector<vector<int>> SEEN)
{
	int size=0;
	int max_size=0;

	for(int i=0;i<GRAPH.size();i++)
	{
		for(int j=0;j<GRAPH[0].size();j++)
		{
			if(!SEEN[i][j])
			{
				size=traverse(GRAPH,SEEN,i,j,GRAPH[i][j]);
				if(size>max_size)
				{
					max_size=size;
				}
			}
		}
	}
	cout<<"largest connected block :";
	return max_size;
	
}