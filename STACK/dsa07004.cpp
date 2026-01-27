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

int check(char a, char b)
{
    if (a == '(' && b == '(')
    {
        return 1;
    }
    else if (a == ')' && b == ')')
    {
        return 1;
    }
    else if (a == ')' && b == '(')
    {
        return 2;
    }
}

int solve(string &s)
{
    vector<char> v;
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else
        {
            if (!st.empty() && st.top() == '(')
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }
    }
    int cnt = 0;
    while (st.size() >= 1)
    {
        char a = st.top();
        st.pop();
        char b = st.top();
        st.pop();
        cnt += check(b, a);
    }
    return cnt;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin.ignore();
        string s;
        cin >> s;
        cout << solve(s) << endl;
    }
    return 0;
}