#include <bits/stdc++.h>
using namespace std;

bool used[1001];
vector<int> ke[1001];
int parent[1001];
int v, e;
int check = 0;
int a;

bool DFS(int u)
{
    used[u] = true;
    for (int v : ke[u])
    {
        if (!used[v])
        {
            parent[v] = u;
            if (DFS(v))
            {
                return true;
            }
        }
        else if (parent[u] != 1 && v == 1 && check != 1)
        {
            check = 1;
            a = u;
            return true;
        }
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        a = 0;
        check = 0;
        cin >> v >> e;
        memset(used, false, sizeof(used));
        memset(parent, 0, sizeof(parent));
        for (int i = 1; i <= v; i++)
        {
            ke[i].clear();
        }
        for (int i = 1; i <= e; i++)
        {
            int x, y;
            cin >> x >> y;
            ke[x].push_back(y);
            ke[y].push_back(x);
        }
        for (int i = 1; i <= v; i++)
        {
            sort(ke[i].begin(), ke[i].end());
        }
        DFS(1);
        if (check)
        {
            stack<int> st;
            st.push(1);
            st.push(a);
            while (parent[a] != 0)
            {
                st.push(parent[a]);
                a = parent[a];
            }
            while (!st.empty())
            {
                cout << st.top() << " ";
                st.pop();
            }
            cout << endl;
        }
        else
            cout << "NO\n";
    }
}