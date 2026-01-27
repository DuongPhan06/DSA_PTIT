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

bool check(string &s)
{
    stack<char> st;
    for (char x : s)
    {
        if (x != ')' && x != ' ')
        {
            st.push(x);
        }
        else if (x == ')')
        {
            if (st.empty())
            {
                return true; // thua dau dong ngoac
            }
            int cnt = 0;
            while (!st.empty() && st.top() != '(')
            {
                cnt++;
                st.pop();
            }
            if (st.empty() || cnt <= 1) // thieu dau mo ngoac VD a+b) va (a)
            {
                return true;
            }
            else
            {
                st.pop();
            }
        }
    }
    return false;
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
        if (check(s))
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
    return 0;
}