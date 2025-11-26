#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); ios::sync_with_stdio(0);

    map<int, int> mp = {
        {4, 40},
        {1, 10},
        {3, 30},
        {2, 20}
    };

    mp.emplace(3, 31);
    mp.emplace(5, 50);
    
    mp[3] = 33;

    auto it1 = mp.find(3);
    if(it1 != mp.end())
    {
        cout << (*it1).second << '\n'; 
    }
    for (auto [k, v]: mp)
    {
        cout << k << " " << v << '\n';
    }
    auto it2 = mp.lower_bound(3);
    cout << (*it2).second << '\n';
    auto it3 = mp.upper_bound(2);
    cout << (*it3).second << '\n';

    return (0);
}