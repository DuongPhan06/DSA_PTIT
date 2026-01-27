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

vector<string> v;
string s;
int n;
int x[1001];
int used[1001] = {0};
int gtnn = INT_MAX;

int kt(string &a, string &b)
{
    int f[26] = {0};
    int dem = 0;
    for (int i = 0; i < a.size(); i++)
    {
        f[a[i] - 'A'] = 1;
    }
    for (int i = 0; i < b.size(); i++)
    {
        if (f[b[i] - 'A'] == 1)
        {
            dem++;
        }
    }
    return dem;
}

void Try(int i, int kq)
{
    if (i == n)
    {
        gtnn = min(gtnn, kq);
        return;
    }
    for (int j = 0; j < n; j++)
    {
        if (used[j] == 0)
        {
            used[j] = 1;
            x[i] = j;
            if (i == 0)
            {
                Try(i + 1, kq);
            }
            else
            {
                Try(i + 1, kq + kt(v[x[i - 1]], v[j]));
            }
            used[j] = 0;
        }
    }
}

int main()
{
    faster;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        v.pb(s);
    }
    Try(0, 0);
    cout << gtnn << endl;
    return 0;
}