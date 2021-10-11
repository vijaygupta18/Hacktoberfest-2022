#include<bits/stdc++.h>
#define ps(x, y) fixed << setprecision(y) << x
 #define BOOST  ios_base::sync_with_stdio(false);    cin.tie(NULL);
 #define vi  vector<int>
#define pb push_back
#define pob pop_back
#define f first
#define s second
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define rall(v) v.rbegin(), v.rend()
#define next next_permutation
#define perv prev_permutation
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define setbit(x) __builtin_popcount(x)
#define w(t) while (t--)
#define pq priority_queue

#define FOR(i,a,b) for ( i = (a); i < (b); ++i)
#define FORN(i,a) FOR(i,0,a)
#define ROF(i,a,b) for ( i = (b)-1; i >= (a); --i)
#define ROFN(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

using namespace std;
#define int long long
int inf = 1000000005;
int mod = 1000000007;
int32_t main(){
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("outputt.txt", "w", stdout);
#endif
int n; //size of array
cin>>n;

int a[n];

for(int i=0;i<n;i++)  cin>>a[i];

vector<int>pre(n),suf(n);

for(int i=0;i<n;i++)
  cin>>a[i];

pre[0]=a[0];
suf[n-1]=a[n-1];

for(int i=1;i<n;i++)  pre[i]=pre[i-1]+a[i];

for(int i=n-2;i>=0;i--)  suf[i]=suf[i+1]+a[i];


int ans=-1;
  for(int i=1;i<n-1;i++){
    if(pre[i-1]==suf[i+1])  {
      ans=i;
       break;
    }
  }

if(ans==-1) 
  cout<<"Pivot index not found";
else cout<<ans<<endl;

return 0;
}

/*Time complexity
calculating suffix and prefix sums takes o(n) and then calculating pivot index also taking o(n) hence the overall complexity is O(n)
*/
