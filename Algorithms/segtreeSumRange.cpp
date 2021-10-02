//#define sort(nums) sort(nums.begin(),nums.end())
#include <bits/stdc++.h>
#define mod 1000000007
#define deb(x) cout<<#x<<" "<<x<<endl
using namespace std;
using ll = unsigned long long int;

ll segtree[4*200000];


void jets(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void buildtree(ll* arr,ll* segtree,ll start,ll end,ll node){
	if(start==end){
		segtree[node]=arr[start];
		return ;
	}
	ll mid=(start+end)/2;
	buildtree(arr,segtree,start,mid,(2*node)+1);
	buildtree(arr,segtree,mid+1,end,(2*node)+2);
	segtree[node]=segtree[(2*node)+1]+segtree[(2*node)+2];
}

ll findsum(ll node,ll lx,ll rx,ll l, ll r){
	if(r<lx || l>rx)
		return 0;
	if(lx>=l && rx<=r)
		return segtree[node];
	else{
		ll mid=(lx+rx)/2;
		return findsum((2*node)+1,lx,mid,l,r)+
		findsum((2*node)+2,mid+1,rx,l,r);
	}
}

void update(ll i,ll val,ll lx,ll rx,ll node){
	if(i<lx || i>rx)
		return ;
	segtree[node]+=val;
	if(lx!=rx){
		ll mid=(lx+rx)/2;
		update(i,val,lx,mid,2*node+1);
		update(i,val,mid+1,rx,2*node+2);
	}
}


int main(){
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    jets();
    ll n,q;
    cin>>n>>q;
    ll size=n;
    if(n&(n-1)!=0){
    	while(size&(size-1)!=0)
    		size++;
    }
    ll arr[size]={0};
    for(ll i=0;i<n;i++){
    	cin>>arr[i];
    }
    memset(segtree,0,sizeof(segtree));
    buildtree(arr,segtree,0,n-1,0);
    while(q--){
    	ll t,l,r;//t is the type if query i.e 1 means sum 2 means update
    	cin>>t>>l>>r;
    	if(t==2)
    	cout<<findsum(0,0,n-1,l-1,r-1)<<endl;
    	else{
            l--;
    		ll val=r-arr[l];
    		arr[l]=r;
    		update(l,val,0,n-1,0);
    	}
    }
    return 0;
}