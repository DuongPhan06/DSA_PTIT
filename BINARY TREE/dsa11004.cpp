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
    node *right, *left;
    node(int x)
    {
        val = x;
        right = left = NULL;
    }
};
void Makeroot(node *root, int u, int v, char c)
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
        Makeroot(root, u, v, c);
    }
    solve(root->left, u, v, c);
    solve(root->right, u, v, c);
}
void levelOrder(node *root)
{
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *top = q.front();
        q.pop();
        cout << top->val << " ";
        if (top->left != NULL)
        {
            q.push(top->left);
        }
        if (top->right != NULL)
        {
            q.push(top->right);
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        node *root = NULL;
        for (int i = 0; i < n; i++)
        {
            int u, v;
            char c;
            cin >> u >> v >> c;
            if (root == NULL)
            {
                root = new node(u);
                Makeroot(root, u, v, c);
            }
            else
            {
                solve(root, u, v, c);
            }
        }
        levelOrder(root);
        cout << endl;
    }
    return 0;
}