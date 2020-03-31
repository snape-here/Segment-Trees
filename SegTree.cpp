#include<bits/stdc++.h> 
using namespace std;
 
#define ull unsigned long long
#define int long long
#define ld long double
#define pb push_back
#define pi  pair< int,int >
#define pl  pair< ll,ll >
#define f first
#define s second 
#define INF 100000000000
#define endl "\n"

const int N=1e5+5;

int arr[N],st[4*N];

void build(int si , int ss , int se)
{
	if(ss == se)
	{
		st[si] = arr[ss];
		return ;
	}
 
	int mid = (ss + se) / 2;
	build(2*si , ss , mid);
	build(2*si+1 ,mid+1 , se);
 
	st[si] = min(st[2*si] , st[2*si+1]);
}

int query(int si , int ss , int se , int qs , int qe)
{
	if(ss > qe || se < qs)
		return INF;
 
	if(ss >= qs && se <= qe)
		return st[si];
 
	int mid = (ss + se) / 2;
 
	return min(query(2*si , ss , mid , qs , qe) , query(2*si+1 , mid+1 , se , qs , qe));
}

void update(int si , int ss , int se , int qi)
{
	if(ss == se)
	{
		st[si]=arr[ss];
		return;
	}

	int mid = (ss + se) / 2;

	if(qi<=mid)
		update(2*si , ss , mid , qi);
	else
		update(2*si+1 , mid+1 , se , qi);

	st[si]=min(st[2*si+1] , st[2*si]);
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n,q,l,r;

    cin>>n;

    for(int i=1;i<=n;i++)
    	cin>>arr[i];

    build(1,1,n);

    cin>>q;

    while(q--)
    {
    	cin>>l>>r;
    	cout<<query(1,1,n,l+1,r+1)<<endl;
    }

    return 0;
   
}