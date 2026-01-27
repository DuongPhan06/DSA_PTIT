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

int a[1000001];
int x[1001];
int n, k;
vector<string> v;
void Try(int i)
{
    for (int j = x[i - 1] + 1; j <= n; j++)
    {
        x[i] = j;
        if (i == k)
        {
            string t;
            for (int i = 1; i <= k; i++)
            {
                t += to_string(x[i]);
            }
            v.pb(t);
        }
        else
        {
            Try(i + 1);
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        v.clear();
        cin >> n >> k;
        string s = "";
        for (int i = 0; i < k; i++)
        {
            int x;
            cin >> x;
            s += to_string(x);
        }
        Try(1);
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] == s)
            {
                cout << i + 1 << endl;
                break;
            }
        }
    }
    return 0;
}