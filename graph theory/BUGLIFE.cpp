#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define test ll t;cin>>t;while(t--)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define st string
#define len length
#define pb push_back
#define v vector<ll>
#define bs binary_search
#define lb lower_bound
#define fr(i,a,b) for(ll i=a;i<b;i++)
#define mp make_pair
#define mod 1000000007

bool isPrime(ll n)
{
    if(n==1)
    {
        return false;
    }
    else if(n==2||n==3)
    {
        return true;
    }
    else
    {
        for(ll i=2;i<=sqrt(n);i++)
        {
            if(n%i==0)
            {
                return false;
            }
        }
    }
        return true;
}

// a<b for gcd(a,b)
ll gcd(ll a, ll b)
{
    if(a==0)
    {
        return b;
    }
    else
    {
        return gcd(b%a,a);
    }
}

ll lcm(ll a, ll b)
{
    return (max(a,b)/gcd(a,b))*min(a,b);
}

bool isEven(ll a)
{
    if(a%2==0)
    {
      return true;
    }
    return false;
}

void addEdge(vector<ll>adj[],ll a,ll b)
{
	adj[a].pb(b);
	adj[b].pb(a);
}
//
//bool isBipartite(ll source,vector<ll>adj[],vector<ll>visited,vector<ll>color)
//{
//	visited[source]=1;
//	for(int i=0;i<adj[source].size();i++)
//	{
//		ll x=adj[source][i];
//		
//		if(visited[x]==0)
//		{
//			visited[x]=1;
//			color[x]=!color[source];
//			
//			if(!isBipartite(x,adj,visited,color))
//			{
//				return false;
//			}
//		}
//		else
//		{
//			if(color[x]==color[source])
//			{
//				return false;
//			}
//		}
//	}
//	return true;
//}

void rangBharo(ll source,vector<ll>adj[],vector<ll>visited,vector<ll>&color)
{
	visited[source]=1;
	for(int i=0;i<adj[source].size();i++)
	{
		ll x=adj[source][i];
		if(visited[x]==0)
		{
			color[x]=!color[source];
			visited[x]=1;
			rangBharo(x,adj,visited,color);
		}
	}
}

int main()
{
	ll cnt=1;
	fast;
	test
	{
		ll vertex,edges;
		cin>>vertex>>edges;
		
		ll arr1[edges],arr2[edges];
		vector<ll>adj[vertex+1];
		vector<ll>visited(vertex+1,0);
		vector<ll>color(vertex+1);
		fr(i,0,edges)
		{
			cin>>arr1[i]>>arr2[i];
			addEdge(adj,arr1[i],arr2[i]);
		}
		for(int i=1;i<vertex+1;i++)
		{
			if(visited[i]==0)
			{
				color[i]=0;
				rangBharo(i,adj,visited,color);
			}
		}
		
		
//		fr(i,1,vertex+1)
//		{
//			cout<<i<<" "<<color[i]<<endl;
//		}
//		cout<<endl;
		bool state=true;
		fr(i,0,edges)
		{
			if(color[arr1[i]]==color[arr2[i]])
			{
				state=false;
				break;
			}
		}
			cout<<"Scenario #"<<cnt<<":"<<endl;
		if(state)
		{
			cout<<"No suspicious bugs found!";
		}
		else
		{
			cout<<"Suspicious bugs found!";
		}
		cout<<endl;
	}
	cnt++;
}
