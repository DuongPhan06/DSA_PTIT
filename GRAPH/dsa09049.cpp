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
vector<ll> ke[200001];
ll value[1000001];
ll DFS(ll u)
{
    ll size = 0;
    value[u] = 1;
    for (ll v : ke[u])
    {
        size += DFS(v);
        value[u] += value[v];
    }
    value[u] += size;
    return size + 1;
}
int main()
{
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        ke[x].pb(i);
    }
    DFS(1);
    for (int i = 1; i <= n; i++)
    {
        cout << value[i] << " ";
    }
    return 0;
}