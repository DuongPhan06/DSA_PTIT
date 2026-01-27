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
char a[2] = {'A', 'B'};
int cnt = 0;
vector<string> v;
bool check(string &s)
{
    int cnt = 1;
    int gtln = 0;
    for (int i = 0; i < s.size() - 1; i++)
    {
        if (s[i] == 'A' && s[i + 1] == 'A')
        {
            cnt++;
        }
        else
        {
            cnt = 1;
        }
        gtln = max(gtln, cnt);
    }
    return gtln == k;
}

void Try(int i, string s)
{
    if (i > n + 1)
    {
        return;
    }
    if (i == n + 1)
    {
        if (check(s))
        {
            cnt++;
            v.pb(s);
            return;
        }
    }
    for (int j = 0; j <= 1; j++)
    {
        x[i] = j;
        Try(i + 1, s + a[j]);
    }
}
int main()
{
    cin >> n >> k;
    Try(1, "");
    cout << cnt << endl;
    for (string x : v)
    {
        cout << x << endl;
    }
    return 0;
}