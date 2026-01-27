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

vector<int> ke[1001];
int v, e;
// Có chu trình euler với đồ thị có hướng thì bán bậc vào bằng bán bậc ra
bool check()
{
    int deg1[1001] = {0};
    int deg2[1001] = {0};
    for (int i = 1; i <= v; i++)
    {
        deg1[i] = ke[i].size();
    }
    for (int i = 1; i <= v; i++)
    {
        for (int x : ke[i])
        {
            deg2[x]++;
        }
    }
    for (int i = 1; i <= v; i++)
    {
        if (deg1[i] != deg2[i])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> v >> e;
        for (int i = 1; i <= v; i++)
        {
            ke[i].clear();
        }
        for (int i = 1; i <= e; i++)
        {
            int x, y;
            cin >> x >> y;
            ke[x].pb(y);
        }
        if (check())
        {
            cout << 1 << endl;
        }
        else
            cout << 0 << endl;
    }
    return 0;
}