#include <iostream>
#include <vector>
using namespace std;

int bs1(vector<int> n, int target)
{
    int si = 0;
    int ei = n.size()-1;

    while (si<ei)
    {
        int mid = (si + ei)/2;
        
        if(n[mid] < target)
        {
            si = mid;
        }

        else if(n[mid] > target)
        {
            ei = mid;
        }

        else if(n[mid] == target)
        {
            return mid;
        }
    }
    return -1;
}

int bs2(vector<int> n, int target, int start, int end)
{
    if(start > end)
    {
        return -1;
    }

    int mid = (start + end)/2;

    if(n[mid] < target)
    {
        start = mid;
    }

    else if(n[mid] > target)
    {
        end = mid;
    }

    else if(n[mid] == target)
    {
        return mid;
    }

    return bs2(n, target, start, end);
}

int main()
{
    vector<int> n = {1, 2, 3, 4, 5};
    int target = 4;

    cout << bs1(n, target) << "\n";
    cout << bs2(n, target, 0, n.size()-1) << "\n";

    return 0;
}