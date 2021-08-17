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
	adj[a].push_back(b);
	adj[b].push_back(a);
}

void print(vector<ll>adj[],ll vertex)
{
	for(ll i=1;i<vertex;i++)
	{
		cout<<i<<"|";
		ll x;
		for(x=0;x<(adj[i]).size();x++)
		{
			cout<<adj[i][x]<<"->";
		}
		cout<<endl;
	}
}
int main()
{
	ll n,m;
	cin>>n>>m;
//	n- number of vertices
//m-number of edges
vector<ll>v1[n+1];

while(m--)
{
	ll a,b;
	cin>>a>>b;
	addEdge(v1,a,b);
}
print(v1,n+1);

}
