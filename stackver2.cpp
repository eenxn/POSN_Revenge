#include <iostream>
#include <vector>
#include <sstream>
#include <stack>
using namespace std;

int RPN(vector<string> &tokens)
{
    stack<int> s;
    
    for(int i=0; i<tokens.size(); i++)
    {
        if(isdigit(tokens[i][0]))
        {
            s.push(stoi(tokens[i]));
        }
        else
        {
            int a;
            int b;

            b = s.top();
            s.pop();

            a = s.top();
            s.pop();
        
            if(tokens[i] == "+")
            {
                s.push(a+b);
            }
            else if(tokens[i] == "-")
            {
                s.push(a-b);
            }
            else if(tokens[i] == "*")
            {
                s.push(a*b);
            }
            else if(tokens[i] == "/")
            {
                s.push(a/b);
            }
        }
    }

    return s.top();
}

int main()
{
    string s;
    vector<string> tokens;
    getline(cin, s);

    stringstream ss(s);
    string t;
    while(ss >> t)
    {
        tokens.push_back(t);
    }

    cout << RPN(tokens) << "\n";

    return 0;
}