#include <iostream>
using namespace std;

string revstr(string s)
{
    string ans;

    if(s.length() == 0)
    {
        return ans;
    }
    
    string str = s;
    str.pop_back();
    return s.back() + revstr(str);
}

int main()
{
    string s;
    getline(cin, s);
    cout << revstr(s) << "\n";

    return 0;
}