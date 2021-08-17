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


void addEdge(vector<ll>adj[],ll a, ll b)
{
	adj[a].pb(b);
	adj[b].pb(a);
}

bool dfs(ll vertex,vector<ll>adj[],vector<ll>&visited,ll parent)
{
	visited[vertex]=1;
	
	for(int i=0;i<adj[vertex].size();i++)
	{
		ll x=adj[vertex][i];
		if(visited[x]==0)
		{
			if(dfs(x,adj,visited,vertex))
			{
				return true;
			}
		}
		else
		{
			if(parent!=x)
			{
				return true;
			}
		}
	}
	return false;
}
int main()
{
	ll vertex,edges;
	cin>>vertex>>edges;
	vector<ll>adj[vertex+1];
	vector<ll>visited(vertex+1,0);
	
	while(edges--)
	{
		ll a,b;
		cin>>a>>b;
		addEdge(adj,a,b);
	}
	
	if(dfs(1,adj,visited,-1))
	{
		cout<<"CYCLE EXISTS!!";
	}
	else
	{
		cout<<"NO CYCLE EXISTING!!";
	}
}

