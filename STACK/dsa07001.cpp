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
    string s;
    vector<int> v;
    while (getline(cin, s))
    {
        string a = s.substr(0, 4);
        if (a == "push")
        {
            for (int i = 0; i < s.size(); i++)
            {
                int tmp = 0;
                while (isdigit(s[i]))
                {
                    tmp = tmp * 10 + (s[i] - '0');
                    i++;
                }
                if (tmp != 0)
                {
                    v.pb(tmp);
                }
                tmp = 0;
            }
        }
        else if (a == "pop")
        {
            v.pop_back();
        }
        else
        {
            if (!v.empty())
            {
                for (int x : v)
                {
                    cout << x << " ";
                }
                cout << endl;
            }
            else
            {
                cout << "empty" << endl;
            }
        }
    }
    return 0;
}