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

int a[100001];
bool used[100001];
void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    memset(used, false, sizeof(used));
    queue<int> q;
    q.push(a[0]);
    used[a[0]] = true;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        int tmp = x;
        for (int i = 0; i < n; i++)
        {
            if (x != a[i])
            {
                tmp = tmp * 10 + a[i];
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
        solve();
    }
    return 0;
}