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
void spiral_Order(node *root)
{
    stack<node *> st1, st2;
    st1.push(root);
    while (!st1.empty() || !st2.empty())
    {
        while (!st1.empty())
        {
            node *tmp = st1.top();
            st1.pop();
            cout << tmp->val << " ";
            if (tmp->right != NULL)
            {
                st2.push(tmp->right);
            }
            if (tmp->left != NULL)
            {
                st2.push(tmp->left);
            }
        }
        while (!st2.empty())
        {
            node *tmp = st2.top();
            st2.pop();
            cout << tmp->val << " ";
            if (tmp->left != NULL)
            {
                st1.push(tmp->left);
            }
            if (tmp->right != NULL)
            {
                st1.push(tmp->right);
            }
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
        spiral_Order(root);
        cout << endl;
    }
    return 0;
}