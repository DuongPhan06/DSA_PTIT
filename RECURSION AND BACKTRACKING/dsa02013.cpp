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

int s, p, n;
int prime[201];
int x[1001];
vector<int> v;
set<vector<int>> se;
int cnt = 0;
void sieve()
{
    for (int i = 0; i <= 200; i++)
    {
        prime[i] = 1;
    }
    prime[0] = prime[1] = 0;
    for (int i = 2; i <= sqrt(200); i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= 200; j += i)
            {
                prime[j] = 0;
            }
        }
    }
}

void Try(int i, int bd, ll sum)
{
    if (sum > s)
    {
        return;
    }
    if (i == n)
    {
        if (sum == s)
        {
            cnt++;
            vector<int> tmp;
            for (int k = 0; k < i; k++)
            {
                tmp.pb(v[x[k]]);
            }
            se.insert(tmp);
        }
        return;
    }
    for (int j = bd; j < v.size(); j++)
    {
        if (v[j] > p)
        {
            if (sum + v[j] <= s)
            {
                x[i] = j;
                Try(i + 1, j + 1, sum + v[j]);
            }
        }
    }
}

int main()
{
    sieve();
    for (int i = 2; i <= 200; i++)
    {
        if (prime[i])
        {
            v.pb(i);
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> p >> s;
        cnt = 0;
        Try(0, 0, 0);
        cout << cnt << endl;
        for (auto x : se)
        {
            for (int k : x)
            {
                cout << k << " ";
            }
            cout << endl;
        }
        se.clear();
    }
    return 0;
}