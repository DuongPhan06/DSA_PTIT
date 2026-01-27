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
            if (s[i] == ']')
            {
                st.push("]");
            }
            else if (isalpha(s[i]))
            {
                st.push(string(1, s[i]));
            }
            else if (s[i] == '[')
            {
                string tmp;
                while (!st.empty() && st.top() != "]")
                {
                    tmp += st.top();
                    st.pop();
                }
                st.pop();
                st.push(tmp);
            }
            else if (isdigit(s[i]))
            {
                string k = "";
                string so = "";
                while (i >= 0 && isdigit(s[i]))
                {
                    so = to_string(s[i] - '0') + so;
                    i--;
                }
                i++;
                int n = stoi(so);
                while (n--)
                {
                    k += st.top();
                }
                st.pop();
                st.push(k);
            }
        }
        while (!st.empty())
        {
            cout << st.top();
            st.pop();
        }
        cout << endl;
    }
    return 0;
}