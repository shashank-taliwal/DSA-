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


ll distan[10001];
void addEdge(vector<ll>adj[],ll a,ll b)
{
	adj[a].pb(b);
	adj[b].pb(a);
}

void dfs(ll vertex,vector<ll>adj[],ll visited[],ll dist)
{
//	this implementation of dfs will give shortest single path froma given source in trees

distan[vertex]=dist;
visited[vertex]=1;
for(int i=0;i<adj[vertex].size();i++)
{
	ll x=adj[vertex][i];
	if(visited[x]==0)
	{
		dfs(x,adj,visited,distan[vertex]+1);
	}
}
}
int main()
{
	ll vertex,edges;
	cin>>vertex>>edges;
	
	vector<ll>adj[vertex+1];
	ll visited[vertex+1];
	
	while(edges--)
	{
		ll vertex1,vertex2;
		cin>>vertex1>>vertex2;
		addEdge(adj,vertex1,vertex2);
	}
	
	dfs(1,adj,visited,0);
	fr(i,1,vertex+1)
	{
		cout<<i<<":"<<distan[i]<<endl;
	}
}
