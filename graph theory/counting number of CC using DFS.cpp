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
#define vec vector<ll>
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

void dfs(ll v, vector<ll>adj[],ll visited[])
{
	visited[v]=1;
//	cout<<v<<" ";
	ll i;
	for(i=0;i<adj[v].size();i++)
	{
		ll x=adj[v][i];
		if(visited[x]==0)
		{
			dfs(x,adj,visited);
		}
	}
}


int main()
{
	ll v,e;
	cin>>v>>e;
	
	vector<ll>adj[v+1];
	while(e--)
	{
		ll a,b;
		cin>>a>>b;
		addEdge(adj,a,b);
	}
	ll visited[v+1]={0};
	
	ll cnt=0;
	for(ll i=1;i<=v;i++)
	{
		if(visited[i]==0)
		{
			dfs(i,adj,visited);
			cnt++;
		}
	}
	cout<<cnt<<endl;
}
