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
int height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + max(height(root->right), height(root->left));
}
bool check1(node *root, int level, int h)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->right == NULL && root->left == NULL && level < h)
    {
        return false;
    }
    return check1(root->left, level + 1, h) && check1(root->right, level + 1, h);
}
bool check2(node *root)
{
    if (root == NULL)
    {
        return true;
    }
    if ((root->left == NULL && root->right != NULL) || (root->left != NULL && root->right == NULL))
    {
        return false;
    }
    return check2(root->left) && check2(root->right);
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
        int h = height(root);
        if (check1(root, 1, h) && check2(root))
        {
            cout << "Yes\n";
        }
        else
            cout << "No\n";
    }
    return 0;
}