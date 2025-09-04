#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    cin.tie(0); ios::sync_with_stdio(0);

    vector<int> arr= {4, -5, 4, -3, 4, 4, -4};

    int mx = arr[0], sum = arr[0];
    for(int i=1; i<arr.size(); i++)
    {
        sum+=arr[i];
        mx = max(mx, sum);

        if (sum <0)
        {
            sum =0;
        }
    }
    cout << mx << '\n';

    return (0);
}