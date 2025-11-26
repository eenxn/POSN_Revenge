#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<int> s = {1, 2, 3, 2, 1, 1, 2, 3, 12, 12, 3, 31};

    s.insert(13);

    for (auto &e: s)
    {
        cout << e << " ";
    }
    cout << '\n';

    return (0);
}