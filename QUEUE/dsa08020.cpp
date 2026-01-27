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

int prime[10000];
bool used[10001];
void sieve()
{
    for (int i = 0; i <= 10000; i++)
    {
        prime[i] = 1;
    }
    prime[0] = prime[1] = 0;
    for (int i = 2; i <= 100; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= 10000; j += i)
            {
                prime[j] = 0;
            }
        }
    }
}

void solve()
{
    sieve();
    int s, t;
    cin >> s >> t;
    memset(used, false, sizeof(used));
    queue<pair<int, int>> q;
    q.push({s, 0});
    used[s] = true;
    while (!q.empty())
    {
        pair<int, int> x = q.front();
        q.pop();
        int num = x.fi, steps = x.se;
        if (num == t)
        {
            cout << steps << endl;
            return;
        }
        string t = to_string(num);
        for (int i = 0; i <= 3; i++)
        {
            string tmp = t;
            for (char c = '0'; c <= '9'; c++)
            {
                tmp[i] = c;
                int k = stoi(tmp);
                if (k >= 1000 && !used[k] && prime[k])
                {
                    used[k] = true;
                    q.push({k, steps + 1});
                }
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