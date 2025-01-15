#include <iostream>
using namespace std;

int cd(int n)
{
    if(n<1)
    {
        return 0;
    }
    return 1 + cd(n/10);
}

int main()
{
    int n;
    cin >> n;
    cout << cd(n) << "\n";
    
    return 0;
}