#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9;

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int v, e;
    cin >> v >> e;

    vector<vector<int>> a(v);

    while (e--)
    {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    int n;
    cin >> n;
    while (n--)
    {
        int A, B;
        cin >> A >> B;

        bool IsIn = false;
        for(int i=0; i<a[A].size(); i++)
        {
            if(a[A][i] == B)
            {
                cout << "YES" << '\n';
                IsIn = true;
                break;
            }
        }
        
        if(!IsIn)
        {
            cout << "NO" << '\n';
        }

    }
    

    // for(int i=0; i<v; i++)
    // {
    //     cout << i << "-> ";
    //     for(int j=0; j<a[i].size(); j++)
    //     {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    
    return(0);
}