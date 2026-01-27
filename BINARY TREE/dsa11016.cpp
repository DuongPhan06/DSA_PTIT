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
void ThemNode(node *root, int u, int v, char c)
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
        ThemNode(root, u, v, c);
    }
    insert(root->left, u, v, c);
    insert(root->right, u, v, c);
}
multiset<int> me;
void Duyet_LNR(node *t)
{
    if (t != NULL)
    {
        Duyet_LNR(t->left);
        me.insert(t->val);
        Duyet_LNR(t->right);
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
        me.clear();
        for (int i = 1; i <= n; i++)
        {
            int u, v;
            char c;
            cin >> u >> v >> c;
            if (root == NULL)
            {
                root = new node(u);
                ThemNode(root, u, v, c);
            }
            else
            {
                insert(root, u, v, c);
            }
        }
        Duyet_LNR(root);
        for (auto x : me)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}