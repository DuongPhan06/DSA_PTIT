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
int n, k;
int x[1001];
set<string> se;
void ql(int i, int bd, string t)
{
    if (i == k)
    {
        string tmp = "";
        for (int i = 0; i < k; i++)
        {
            tmp = tmp + v[x[i]] + " ";
        }
        se.insert(tmp);
        return;
    }
    for (int j = bd; j < v.size(); j++)
    {
        x[i] = j;
        ql(i + 1, j + 1, t + v[j]);
    }
}
int main()
{
    cin >> n >> k;
    set<string> k;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        k.insert(s);
    }
    for (auto x : k)
    {
        v.pb(x);
    }
    ql(0, 0, "");
    for (string x : se)
    {
        cout << x << endl;
    }
    return 0;
}