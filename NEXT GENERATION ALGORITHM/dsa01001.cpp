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
    while (t--)
    {
        bool check = true;
        string s;
        cin >> s;
        int i = s.size() - 1;
        while (i >= 0 && s[i] == '1')
        {
            i--;
        }
        if (i == -1)
        {
            check = false;
        }
        if (!check)
        {
            for (int j = 0; j < s.size(); j++)
            {
                cout << 0;
            }
        }
        else
        {
            s[i] = '1';
            for (int j = i + 1; j < s.size(); j++)
            {
                s[j] = '0';
            }
            cout << s;
        }
        cout << endl;
    }
    return 0;
}