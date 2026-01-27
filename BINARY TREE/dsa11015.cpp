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
void ThemNoot(node *root, int u, int v, char c)
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
void insert(node *root, int u, int v, char c)
{
    if (root == NULL)
    {
        return;
    }
    if (root->val == u)
    {
        ThemNoot(root, u, v, c);
    }
    insert(root->left, u, v, c);
    insert(root->right, u, v, c);
}
int Maxsum(node *root, int &ans)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return root->val;
    }
    int l = Maxsum(root->left, ans);
    int r = Maxsum(root->right, ans);
    if (root->right != NULL && root->left != NULL)
    {
        ans = max(ans, l + r + root->val);
        return max(l, r) + root->val;
    }
    if (root->left == NULL)
    {
        return r + root->val;
    }
    if (root->right == NULL)
    {
        return l + root->val;
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
                ThemNoot(root, u, v, c);
            }
            else
            {
                insert(root, u, v, c);
            }
        }
        int ans = -1e9;
        Maxsum(root, ans);
        cout << ans << endl;
    }
    return 0;
}