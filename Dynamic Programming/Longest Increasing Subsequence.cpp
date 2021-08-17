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

bool isSquare(ll x)
{
	 ll n1=sqrt(x);
	 double n2=sqrt(x);
	 if(n2-n1==0)
	 {
	  return true;
	 }
	 return false;
}

int lengthOfLIS(vector<int>&nums) {
        
    int LIS[nums.size()];
    
    //initialising the LIS array with 1 as a single element can also be an increasing subsequence
    for(int i=0;i<nums.size();i++){
        LIS[i]=1;
    }
    
    for(int i=1;i<nums.size();i++){
        for(int j=0;j<i;j++){
            if(nums[j]<nums[i])
            {
                LIS[i]=max(LIS[i],LIS[j]+1);
            }
        }
    }
        
    int ans=1;
    for(int i=0;i<nums.size();i++){
        ans=max(ans,LIS[i]);
    }
    return ans;
}

void solve()
{
	ll n;
	cin>>n;
	vector<int> v1;
	fr(i,0,n)
	{
		ll x;
		cin>>x;
		v1.pb(x);
	}
	
	cout<<lengthOfLIS(v1);
	
}
int main()
{
	fast;
	solve();
}


