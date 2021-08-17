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

bool isBipartite(ll source,vector<ll>adj[],vector<ll>visited,vector<ll> color)
{
	visited[source]=1;
	for(int i=0;i<adj[source].size();i++)
	{
		if(visited[adj[source][i]]==0)
		{
			ll x=adj[source][i];
			visited[x]=1;
			color[x]=!color[source];
			
			if(!isBipartite(x,adj,visited,color))
			{
				return false;
			}
		}
		else
		{
			if(color[source]==color[adj[source][i]])
			{
				return false;
			}
		}
	}
	return true;
}


int main()
{
	ll vertex,edges;
	cin>>vertex>>edges;
	
	vector<ll>adj[vertex+1];
	vector<ll>color(vertex+1);
	vector<ll>visited(vertex+1,0);
//	memset(&visited,0,vertex+1);
	
	while(edges--)
	{
		ll a,b;
		cin>>a>>b;
		addEdge(adj,a,b);
	}
	color[1]=0;
	
	if(isBipartite(1,adj,visited,color))
	{
		cout<<"yes";
	}
	else
	{
		cout<<"no";
	}
}
