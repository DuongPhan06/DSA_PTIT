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
int used[1001];
int x[1001];
string s;
vector<string> v;
void Try(int i, string t)
{
    if (i == n)
    {
        v.pb(t);
        return;
    }
    for (int j = 0; j < n; j++)
    {
        if (used[j] == 0)
        {
            used[j] = 1;
            Try(i + 1, t + s[j]);
            used[j] = 0;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> s;
        n = s.size();
        Try(0, "");
        for (string x : v)
        {
            cout << x << " ";
        }
        cout << endl;
        v.clear();
    }
    return 0;
}