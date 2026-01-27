#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define se second
#define pf push_front
#define mp make_pair
#define MAX_N 1e9
#define MIN_N -1e9
#define MAX_SIZE 1000000
#define PI 3.141592653589793238
#define pb push_back
#define sz(s) s.size()
const int mod = 1e9 + 7;
#define faster                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

int calc(int a, int b, char c)
{
    if (c == '+')
    {
        return a + b;
    }
    if (c == '-')
    {
        return a - b;
    }
    if (c == '*')
    {
        return a * b;
    }
    if (c == '/')
    {
        return a / b;
    }
    return 0;
}

int solve(string &s)
{
    stack<int> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (isdigit(s[i]))
        {
            st.push(s[i] - '0');
        }
        else
        {
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();
            int x = calc(op2, op1, s[i]);
            st.push(x);
        }
    }
    return st.top();
}

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string s;
        getline(cin, s);
        cout << solve(s) << endl;
    }
    return 0;
}