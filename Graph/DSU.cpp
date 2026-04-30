#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<int> parent, sz;

void build(int n)
{
    parent.resize(n+1);
    sz.assign(n+1, 1);

    for (int i=1; i<=n; i++) parent[i]=1;
}

int root(int a)
{
    if (parent[a] == a) return a;
    return parent[a] = root(parent[a]);
}

void unite(int a, int b)
{
    int u = root(a);
    int v = root(b);
    if(u==v) return;
    if(sz[v]>sz[u]) swap(u,v);
    parent[v] = u;
    sz[u] += sz[v];
}

bool isSame(int a, int b)
{
    return root(a) == root(b);
}

int32_t main()
{
    cin.tie(0);ios::sync_with_stdio(0);
    
    int n; cin>>n;

    return 0;
}