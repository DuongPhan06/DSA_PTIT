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
            st.push(string(1, s[i]));
        }
        else
        {
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();
            string tmp1 = "(" + op1 + s[i] + op2 + ")";
            st.push(tmp1);
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