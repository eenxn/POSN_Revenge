#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <sstream>
using namespace std;

int precedence(string s)
{
    if(s == "*" || s == "/")
    {
        return 2;
    }
    if(s == "+" || s == "-")
    {
        return 1;
    }

    return (-1);
}

queue<string> postfix(vector<string> vec)
{
    stack<string> st;
    queue<string> q;

    for(int i=0; i<vec.size(); i++)
    {
        if(isdigit(vec[i][0]))
        {
            q.push(vec[i]);
        }
        else
        {
            if(st.empty() || precedence(vec[i]) > precedence(st.top())) st.push(vec[i]);

            else
            {
                if(precedence(vec[i]) <= precedence(st.top()))
                {
                    string temp;
                    temp = st.top();
                    st.pop();
                    q.push(temp);
                    st.push(vec[i]);
                }
            }
        }
        
    }

    //for test na kub :)))
    stack<string> s_test = st;
    queue<string> q_test = q;
    cout << "stack: ";
    while (!s_test.empty())
    {
        cout << s_test.top() << " ";
        s_test.pop();
    }
    cout << endl;
    cout << "queue: ";
    while (!q_test.empty())
    {
        cout << q_test.front() << " ";
        q_test.pop();
    }
    cout << endl;


    return q;
}

int main()
{
    string infix;
    vector<string> tokens;
    getline(cin, infix);

    stringstream ss(infix);
    string temp;
    while(ss >> temp)
    {
        tokens.push_back(temp);
    }

    auto q = postfix(tokens);
    // while (!q.empty())
    // {
    //     cout << q.front() << "\n";
    //     q.pop();
    // }
    return 0;
}