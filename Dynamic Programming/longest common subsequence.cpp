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
int LCS(string s1,string s2){

int len1=s1.length();
int len2=s2.length();
int table[len1+1][len2+1];
    
 for(int i=0;i<=len1;i++){
     for(int j=0;j<=len2;j++){
         if(i==0||j==0){
             table[i][j]=0;
         }
     }
 }
    
    for(int i=1;i<=len1;i++){
        for(int j=1;j<=len2;j++){
            if(s1[i-1]==s2[j-1]){
                table[i][j]=1+table[i-1][j-1];
            }
            else{
                table[i][j]=max(table[i-1][j],table[i][j-1]);
            }
        }
    }
    return table[len1][len2];
}

void solve(void)
{
	string s1,s2;
	cin>>s1>>s2;
	int ans=LCS(s1,s2);
	cout<<ans<<endl;
}

int main()
{
	fast;
	solve();
}


