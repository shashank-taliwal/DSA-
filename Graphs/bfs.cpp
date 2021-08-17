#include<bits/stdc++.h>
using namespace std;


vector<int>bfsOfGraph(vector<int>adj[],int vertex)
{
	vector<int>bfs;
	int visited[vertex+1];
	memset(visited,0,sizeof(visited));
	
	for(int i=1;i<=vertex;i++)
	{
		queue<int>q;
		if(!visited[i])
		{
			q.push(i);
			visited[i]=1;
			while(!q.empty())
			{
				int node=q.front();
				q.pop();
				bfs.push_back(node);
				for(int j=0;j<adj[node].size();j++)
				{
					if(!visited[adj[node][j]])
					{
						q.push(adj[node][j]);
						visited[adj[node][j]]=1;
					}
				}
			}	
		}
	}
	return bfs;
}
int main()
{
	int edges,vertex;
	cin>>vertex>>edges;
	vector<int>adj[vertex+1];
	while(edges--)
	{
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	vector<int>bfs=bfsOfGraph(adj,vertex);
	for(int i=0;i<bfs.size();i++)
	{
		cout<<bfs[i]<<" ";
	}
}


