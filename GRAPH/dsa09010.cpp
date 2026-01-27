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
vector<int> t_ke[1001];
bool used[1001];
stack<int> st;
void DFS1(int u)
{
    used[u] = true;
    for (int v : ke[u])
    {
        if (!used[v])
        {
            used[v] = true;
            DFS1(v);
        }
    }
    st.push(u);
}
void DFS2(int u)
{
    used[u] = true;
    for (int v : t_ke[u])
    {
        if (!used[v])
        {
            used[v] = true;
            DFS2(v);
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int v, e;
        cin >> v >> e;
        memset(used, false, sizeof(used));
        for (int i = 1; i <= v; i++)
        {
            ke[i].clear();
        }
        for (int i = 1; i <= v; i++)
        {
            t_ke[i].clear();
        }
        for (int i = 1; i <= e; i++)
        {
            int x, y;
            cin >> x >> y;
            ke[x].pb(y);
            t_ke[y].pb(x);
        }
        for (int i = 1; i <= v; i++)
        {
            if (!used[i])
            {
                DFS1(i);
            }
        }
        memset(used, false, sizeof(used));
        int cnt = 0;
        while (!st.empty())
        {
            int s = st.top();
            st.pop();
            if (!used[s])
            {
                DFS2(s);
                cnt++;
            }
        }
        if (cnt == 1)
        {
            cout << "YES\n";
        }
        else
            cout << "NO\n";
    }
    return 0;
}