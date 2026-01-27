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

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string s;
        getline(cin, s);
        stack<string> st;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == ')' || isalpha(s[i]))
            {
                st.push(string(1, s[i]));
            }
            else if (s[i] == '(')
            {
                string tmp = "";
                while (!st.empty() && st.top() != ")")
                {
                    tmp += st.top();
                    st.pop();
                }
                if (!st.empty() && st.top() == ")")
                {
                    st.pop(); // Xoa dau ")"
                }
                st.push(tmp);
            }
            else
            {
                if (s[i] == '+')
                {
                    st.push(string(1, s[i]));
                }
                else
                {
                    string t = st.top();
                    st.pop();
                    for (int i = 0; i < t.size(); i++)
                    {
                        if (t[i] == '+')
                        {
                            t[i] = '-';
                        }
                        else if (t[i] == '-')
                        {
                            t[i] = '+';
                        }
                    }
                    st.push(t);
                    st.push(string(1, s[i]));
                }
            }
        }
        string ans = "";
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        cout << ans << endl;
    }
    return 0;
}