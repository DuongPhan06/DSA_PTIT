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
vector<string> v;
int f;
int x[1001];
void Try(int i, int bd, string t)
{
    if (i == k)
    {
        cout << t << endl;
        return;
    }
    for (int j = bd; j < f; j++)
    {
        x[i] = j;
        Try(i + 1, j + 1, t + v[j] + " ");
    }
}
int main()
{
    set<string> se;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        se.insert(s);
    }
    for (auto x : se)
    {
        v.pb(x);
    }
    f = v.size();
    Try(0, 0, "");
    return 0;
}