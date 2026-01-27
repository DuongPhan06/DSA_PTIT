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

vector<char> v;
set<string> se;
int n;
int x[1001];
int visited[1001];
set<string> f;
bool check(string &s)
{
    int k = s.size();
    for (int i = 1; i < k - 1; i++)
    {
        if (s[i] == 'A' || s[i] == 'E')
        {
            if (s[i - 1] != 'A' && s[i - 1] != 'E' && s[i + 1] != 'A' && s[i + 1] != 'E')
            {
                return false;
            }
        }
    }
    return true;
}

void Try(int i, string t)
{
    if (i == n)
    {
        if (check(t))
        {
            cout << t << endl;
        }
        return;
    }
    for (int j = 0; j < n; j++)
    {
        if (visited[j] == 0)
        {
            visited[j] = 1;
            Try(i + 1, t + v[j]);
            visited[j] = 0;
        }
    }
}
int main()
{
    char s;
    cin >> s;
    for (char x = 'A'; x <= s; x++)
    {
        v.pb(x);
    }
    n = v.size();
    Try(0, "");
    for (auto x : f)
    {
        cout << x << endl;
    }
    return 0;
}