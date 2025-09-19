#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 9e18;

vector<int> coins = {1, 3, 4};
int money;

vector<int> mm;

int solve(int n)
{
    if (n<0) return INF;
    if (n == 0) return 0;
    if (mm[n] != INF) return mm[n];
    int ans = INF; for(auto c : coins) ans = min(ans, 1+solve(n-c));

    return mm[n] = ans;
}

int32_t main()
{
    cin.tie(0); ios::sync_with_stdio(0);

    cin >> money;
    mm.assign(money+1, INF);
    cout << solve(money) << '\n';

    return (0);
}