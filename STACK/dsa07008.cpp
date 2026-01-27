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

int pre(char &c)
{
    if (c == '(')
    {
        return 0;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '^')
    {
        return 3;
    }
}

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string s;
        cin >> s;
        stack<char> st;
        string ans = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                st.push(s[i]);
            }
            else if (s[i] == ')')
            {
                while (!st.empty() && st.top() != '(')
                {
                    ans += st.top();
                    st.pop();
                }
                st.pop(); // Xoa dau ')'
            }
            else if (isalpha(s[i]))
            {
                ans += s[i];
            }
            else
            {
                while (!st.empty() && pre(st.top()) >= pre(s[i]))
                {
                    ans += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        while (!st.empty() && st.top() != '(')
        {
            ans += st.top();
            st.pop();
        }
        cout << ans << endl;
    }
    return 0;
}