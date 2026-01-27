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
        st.push("1");
        int cnt = 2;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'I')
            {
                st.push(to_string(cnt));
            }
            else
            {
                string tmp = st.top();
                st.pop();
                tmp = to_string(cnt) + tmp;
                st.push(tmp);
            }
            cnt++;
        }
        string ans = "";
        vector<string> v;
        while (!st.empty())
        {
            v.pb(st.top());
            st.pop();
        }
        reverse(v.begin(), v.end());
        for (string x : v)
        {
            cout << x;
        }
        cout << endl;
    }
    return 0;
}