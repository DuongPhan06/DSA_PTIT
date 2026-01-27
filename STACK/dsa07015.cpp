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

int pre(char c)
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
    return -1;
}

string trans(string s)
{
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
            st.pop();
        }
        else if (isdigit(s[i]))
        {
            while (i < s.size() && isdigit(s[i]))
            {
                ans += s[i];
                i++;
            }
            ans += ' ';
            i--;
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
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    return ans;
}

ll cal(string s)
{
    stack<ll> st;
    string num = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (isdigit(s[i]))
        {
            while (i < s.size() && isdigit(s[i]))
            {
                num += s[i];
                i++;
            }
            st.push(stoll(num));
            num = "";
            i--;
        }
        else if (s[i] != ' ')
        {
            ll b = st.top();
            st.pop();
            ll a = st.top();
            st.pop();
            switch (s[i])
            {
            case '+':
                st.push(a + b);
                break;
            case '-':
                st.push(a - b);
                break;
            case '*':
                st.push(a * b);
                break;
            case '/':
                st.push(a / b);
                break;
            }
        }
    }
    return st.top();
}

void solve()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string s;
        cin >> s;
        string ans = trans(s);
        ll result = cal(ans);
        cout << result << endl;
    }
}

int main()
{
    solve();
    return 0;
}