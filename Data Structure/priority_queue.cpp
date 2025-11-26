#include <bits/stdc++.h>
using namespace std;

int main() 
{
    cin.tie(nullptr); ios::sync_with_stdio(false);

    priority_queue<int, vector<int>, greater<int>> pq;

    pq.push(2);
    pq.push(1);
    pq.push(3);
    pq.push(4);

    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }

    return (0);
}