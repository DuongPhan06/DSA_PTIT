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

int n, k;
int x[1001];
vector<string> v;

bool check(string &s)
{
    int ma = 0;
    int tmp = 0;
    int cnt = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '1')
        {
            tmp++;
        }
        else
        {
            if (tmp == k)
            {
                cnt++;
            }
            tmp = 0;
        }
        ma = max(ma, tmp);
    }
    if (tmp == k)
    {
        cnt++;
    }
    return (cnt == 1 && ma == k);
}
void Try(int i)
{
    for (int j = 0; j <= 1; j++)
    {
        x[i] = j;
        if (i == n)
        {
            string tmp = "";
            for (int f = 1; f <= n; f++)
            {
                tmp += to_string(x[f]);
            }
            if (check(tmp))
            {
                v.pb(tmp);
            }
        }
        else
        {
            Try(i + 1);
        }
    }
}
int main()
{
    cin >> n >> k;
    Try(1);
    for (string x : v)
    {
        cout << x << endl;
    }
    return 0;
}