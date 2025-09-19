#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 9e18;

vector<int> coins = {1, 3, 4};

int solve(int x)
{
   vector<int> dp(x+1, INF);
   dp[0] = 0;
   
   for(int i=1; i<=x; i++)
   {
       for(auto c : coins)
       {
            if((i-c) >= 0)
            {
                dp[i] = min(dp[i], 1+dp[i-c]);
            }
       }
   }

   return dp[x];
}

int32_t main()
{
    cin.tie(0); ios::sync_with_stdio(0);

    int money; cin>>money;
    cout << solve(money) << '\n';

    return (0);
}