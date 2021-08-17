#include<bits/stdc++.h>
using namespace std;

//In this file, adjacency list is implemented using an array of vectors

int main()
{
	int vertex,edges;
	cin>>vertex>>edges;
	
	vector<int>adj[vertex+1];
	
	while(edges--)
	{
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		
//		assuming the graph to be undirected
		adj[y].push_back(x);
	}
	
	for(int i=1;i<vertex+1;i++)
	{
		cout<<i<<" |";
		for(int j=0;j<(adj[i]).size();j++)
		{
			cout<<adj[i][j]<<" ";
		}
		cout<<endl;
	}
}
