#include <iostream>
#include <bits/stdc++.h>
#define mx 9999
using namespace std;
/* The problem is to find shortest distances between every pair of vertices in a given edge weighted directed Graph.
   You are given 2 integers , N is the number of vertices, M is the number of edges.
 You'll also be given  a,b ,c  where a and b represents an edge from a vertex  to a vertex  and c respresents the weight of that edge.
 Note that the value of graph[i][j] is 0 if i is equal to j
 and graph[i][j] is INF (infinite) if there is no edge from vertex i to j.
 Output : Shortest distance matrix
*/

int main()
{
    int n,m;
    cin>>n>>m;
    int graph[n][n];
     int temp[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j!=i){
                graph[i][j]=mx;
                temp[i][j]=0;
            }
            else{
                graph[i][j]=0;
                temp[i][j]=0;
            }
        }

    }
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        int l;
        cin>>l;
        graph[x][y]=l;

    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            temp[i][j]=graph[i][j];
        }
    }
    for(int k=0;k<n;k++){
         for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(temp[i][k]+temp[k][j]<temp[i][j]){
                temp[i][j]=temp[i][k]+temp[k][j];
            }
        }
    }

}
 for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (temp[i][j] == mx)
                cout<<"INF"<<"     ";
            else
                cout<<temp[i][j]<<"     ";
        }
        cout<<endl;
    }


}
