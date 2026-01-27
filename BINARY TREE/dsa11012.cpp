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

struct node
{
    int val;
    node *left, *right;
    node(int x)
    {
        val = x;
        left = right = NULL;
    }
};
void makeRoot(node *root, int u, int v, char c)
{
    if (c == 'L')
    {
        root->left = new node(v);
    }
    else
    {
        root->right = new node(v);
    }
}
void solve(node *root, int u, int v, char c)
{
    if (root == NULL)
    {
        return;
    }
    if (root->val == u)
    {
        makeRoot(root, u, v, c);
    }
    solve(root->left, u, v, c);
    solve(root->right, u, v, c);
}
bool same(node *root1, node *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    if (root1 != NULL && root2 != NULL)
    {
        return (root1->val == root2->val) && same(root1->right, root2->right) && same(root1->left, root2->left);
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        node *root1 = NULL;
        node *root2 = NULL;
        for (int i = 0; i < n; i++)
        {
            int u, v;
            char c;
            cin >> u >> v >> c;
            if (root1 == NULL)
            {
                root1 = new node(u);
                makeRoot(root1, u, v, c);
            }
            else
            {
                solve(root1, u, v, c);
            }
        }
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int u, v;
            char c;
            cin >> u >> v >> c;
            if (root2 == NULL)
            {
                root2 = new node(u);
                makeRoot(root2, u, v, c);
            }
            else
            {
                solve(root2, u, v, c);
            }
        }
        if (same(root1, root2))
        {
            cout << 1 << endl;
        }
        else
            cout << 0 << endl;
    }
    return 0;
}