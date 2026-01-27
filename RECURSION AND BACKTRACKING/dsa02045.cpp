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

int n;
int x[1001];
string s;
set<string> se;
void Try(int i, int bd, string t)
{
    if (i > n)
    {
        return;
    }
    if (i <= n)
    {
        se.insert(t);
    }
    for (int j = bd; j < n; j++)
    {
        x[i] = j;
        Try(i + 1, j + 1, t + s[j]);
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cin >> s;
        Try(0, 0, "");
        for (auto x : se)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}