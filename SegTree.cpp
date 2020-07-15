#include<bits/stdc++.h> 
using namespace std;
 
#define ull unsigned long long
#define int long long
#define ld long double
#define pb push_back
#define pi  pair< int,int >
#define ff first
#define ss second
#define mod 1000000007
#define inf 300000000000000007
#define endl "\n"

const int N=2e5+5;

int n,m,q,l,r;

int a[N],tree[N];

void build(int ind , int st , int en)
{
    if(st==en)
    {
        tree[ind]=a[st];
        return;
    }

    int mid=(st+en)/2;

    build(2*ind+1,st,mid);
    build(2*ind+2,mid+1,en);

    tree[ind]=tree[2*ind+1]+tree[2*ind+2];
}

int getsum(int ind , int st , int en , int l , int r)
{
    if(l>r)
        return 0;
        
    if(l==st && r==en)
        return tree[ind];
        
    int mid=(st+en)/2;
        
    return getsum(2*ind+1,st,mid,l,min(r,mid))+getsum(2*ind+2,mid+1,en,max(l,mid+1),r);
}

void update(int ind , int st , int en , int pos , int val)
{
    if(st==en)
        tree[ind]=val;
        
    else
    {
        int mid=(st+en)/2;
        
        if(pos<=mid)
            update(2*ind+1,st,mid,pos,val);
        else
            update(2*ind+2,mid+1,en,pos,val); 
            
        tree[ind]=tree[2*ind+1]+tree[2*ind+2];
    }
}

signed main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>a[i];
        
    build(0,0,n-1);

    for(int i=0;i<m;i++)
    {
        cin>>q>>l>>r;
        if(q==1)
            update(0,0,n-1,l,r);
        else
            cout<<getsum(0,0,n-1,l,r-1)<<endl;
    }

    return 0;
}
