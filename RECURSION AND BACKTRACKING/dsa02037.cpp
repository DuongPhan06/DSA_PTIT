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

int prime[1001];
int a[1000001], x[1001];
bool used[1001];
int n;
vector<vector<int>> v;
void sieve()
{
    for (int i = 0; i <= 1000; i++)
    {
        prime[i] = 1;
    }
    prime[0] = prime[1] = 0;
    for (int i = 2; i <= sqrt(1000); i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= 1000; j += i)
            {
                prime[j] = 0;
            }
        }
    }
}
bool cmp(vector<int> &a, vector<int> &b)
{
    int n = min(a.size(), b.size());
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
        {
            return a[i] < b[i];
        }
    }
    return a.size() < b.size();
}

void Try(int i, int bd, ll sum)
{
    if (prime[sum])
    {
        vector<int> tmp;
        for (int k = 1; k < i; k++)
        {
            tmp.pb(a[x[k]]);
        }
        v.pb(tmp);
    }

    if (i > n)
    {
        return;
    }
    for (int j = bd; j <= n; j++)
    {
        if (used[j] == false)
        {
            used[j] = true;
            x[i] = j;
            Try(i + 1, j + 1, sum + a[j]);
            used[j] = false;
        }
    }
}

int main()
{
    sieve();
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        sort(a + 1, a + n + 1, greater<int>());
        Try(1, 1, 0);
        sort(v.begin(), v.end(), cmp);
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = 0; j < v[i].size(); j++)
            {
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
        v.clear();
    }
    return 0;
}