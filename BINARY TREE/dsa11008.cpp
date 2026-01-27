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
    int data;
    node *left, *right;
    node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
void makeNode(node *root, int u, int v, char c)
{
    if (c == 'L')
    {
        root->left = new node(v);
    }
    else
        root->right = new node(v);
}
void insert(node *root, int u, int v, char c)
{
    if (root == NULL)
    {
        return;
    }
    if (root->data == u)
    {
        makeNode(root, u, v, c);
    }
    insert(root->left, u, v, c);
    insert(root->right, u, v, c);
}
int height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + max(height(root->right), height(root->left));
}
bool check(node *root, int level, int h)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->right == NULL && root->left == NULL && level < h)
    {
        return false;
    }
    return check(root->left, level + 1, h) && check(root->right, level + 1, h);
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
        while (n--)
        {
            int u, v;
            char c;
            cin >> u >> v >> c;
            if (root == NULL)
            {
                root = new node(u);
                makeNode(root, u, v, c);
            }
            else
            {
                insert(root, u, v, c);
            }
        }
        int h = height(root);
        if (check(root, 1, h))
        {
            cout << 1 << endl;
        }
        else
            cout << 0 << endl;
    }
    return 0;
}