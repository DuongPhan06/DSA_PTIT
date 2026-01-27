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

ll check(char c, ll a, ll b)
{
    if (c == '*')
    {
        return a * b;
    }
    else if (c == '/')
    {
        return a / b;
    }
    else if (c == '-')
    {
        return a - b;
    }
    else if (c == '+')
    {
        return a + b;
    }
    else if (c == '^')
    {
        return a ^ b;
    }
}

int solve(string &s)
{
    stack<ll> st;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (isdigit(s[i]))
        {
            st.push(s[i] - '0');
        }
        else
        {
            ll t1 = st.top();
            st.pop();
            ll t2 = st.top();
            st.pop();
            ll t = check(s[i], t1, t2);
            st.push(t);
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