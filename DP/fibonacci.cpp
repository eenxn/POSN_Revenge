#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> memo;
vector<int> dp;

//manual
int fib(int n)
{
    if(n==0 or n==1) return n;
    return fib(n-2) + fib(n-1);
}

//dynamic programming memoization
int fibo_memo(int n)
{
    if(n==0 or n==1) return memo[n];
    if(memo[n] != -1) return memo[n];

    return memo[n]  = fibo_memo(n-1) + fibo_memo(n-2);

}

//dynamic programming bottom-up
int fibo_dp(int n)
{
    for (int i=2; i<=n; i++)
    {
        dp[i] = dp[i-2] + dp[i-1];
    }

    return dp[n];

}

int32_t main()
{
    //cin.tie(0); ios::sync_with_stdio(0);

    int n; cin>>n;
    
    
    memo.assign(n+1, -1);
    memo[0]=0; memo[1]=1;
    
    dp.resize(n+1);
    dp[0]=0; dp[1]=1;

    cout << fibo_dp(n) << '\n';
    cout << fibo_memo(n) << '\n';
    cout << fib(n) << '\n';
    
    return (0);
}