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
    stack<int> st;
    vector<string> v;
    while (t--)
    {
        string s;
        getline(cin, s);
        v.pb(s);
    }
    for (string x : v)
    {
        string a = x.substr(0, 5);
        if (a == "PUSH ")
        {
            for (int i = 0; i < x.size(); i++)
            {
                int tmp = 0;
                while (isdigit(x[i]))
                {
                    tmp = tmp * 10 + (x[i] - '0');
                    i++;
                }
                if (tmp != 0)
                {
                    st.push(tmp);
                }
            }
        }
        else if (a == "POP")
        {
            if (!st.empty())
            {
                st.pop();
            }
        }
        else if (a == "PRINT")
        {
            if (!st.empty())
            {
                cout << st.top() << endl;
            }
            else
            {
                cout << "NONE" << endl;
            }
        }
    }
    return 0;
}