#include <iostream>
using namespace std;

int rec_fibonacci(int n)
{
    if(n == 0 || n == 1)
    {
        return 1;
    }
    return rec_fibonacci(n-2) + rec_fibonacci(n-1);
}

int ite_fibonacci(int n)
{
    int f1 = 1;
    int f2 = 1;
    int ans;

    if(n == 0 || n == 1)
    {
        return 1;
    }

    for(int i=2; i<=n; i++)
    {
        ans = f1 + f2;
        f1 = f2;
        f2 = ans;
    }
    return ans; 
}

int main()
{
    int n;
    cin >> n;
    cout << "Recursive = " << rec_fibonacci(n) << "\n";
    cout << "Iterative = " << ite_fibonacci(n) << "\n";
}