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

int n, s;
int cnt = 0;
int a[1000001];
int x[1001];
vector<string> v;

void Try(int i, int bd, ll sum)
{
    if (sum > s)
    {
        return;
    }
    for (int j = bd; j <= n; j++)
    {
        if (sum + a[j] <= s)
        {
            x[i] = j;
            if (sum + a[j] == s)
            {
                string tmp;
                cnt++;
                for (int k = 1; k <= i; k++)
                {
                    tmp = tmp + to_string(a[x[k]]) + " ";
                }
                tmp.pop_back();
                v.pb(tmp);
                return;
            }
            else
            {
                Try(i + 1, j, sum + a[j]);
            }
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> s;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        cnt = 0;
        sort(a + 1, a + n + 1);
        Try(1, 1, 0);
        if (cnt)
        {
            cout << cnt << " ";
            for (string x : v)
            {
                cout << "{";
                cout << x << "} ";
            }
            cout << endl;
        }
        else
        {
            cout << "-1" << endl;
        }
        v.clear();
    }
    return 0;
}