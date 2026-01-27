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
char s[2] = {'H', 'A'};
set<string> se;
bool check(string &s)
{
    for (int i = 0; i < s.size() - 1; i++)
    {
        if (s[i] == 'H' && s[i + 1] == 'H')
        {
            return false;
        }
    }
    return true;
}
void Try(int i, string t)
{
    if (i > n)
    {
        return;
    }
    if (i == n && t.back() == 'A' && t[0] == 'H')
    {
        if (check(t))
        {
            se.insert(t);
            return;
        }
    }
    for (int j = 0; j < 2; j++)
    {
        x[i] = j;
        Try(i + 1, t + s[j]);
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        se.clear();
        cin >> n;
        Try(0, "");
        for (auto x : se)
        {
            cout << x << endl;
        }
    }
    return 0;
}