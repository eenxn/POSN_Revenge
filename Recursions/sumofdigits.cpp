#include <iostream>
using namespace std;

int sum1(int n)
{
    if(n < 1)
    {
        return 0;
    }
    return sum1(n/10) + n%10;
}

int sum2(int n)
{
    int ans = 0;
    while (n>=1)
    {
        ans += n%10;
        n /=10;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    cout << "Recursive = " << sum1(n) << "\n";
    cout << "Iterative = " << sum2(n) << "\n";
}