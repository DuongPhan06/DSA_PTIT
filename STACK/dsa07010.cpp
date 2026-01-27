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

string solve(string &s)
{
    stack<string> st;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (isalpha(s[i]))
        {
            string tmp = string(1, s[i]);
            st.push(tmp);
        }
        else
        {
            string tmp1 = st.top();
            st.pop();
            string tmp2 = st.top();
            st.pop();
            string t = tmp1 + tmp2 + s[i];
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
        cin >> s;
        cout << solve(s) << endl;
    }
    return 0;
}