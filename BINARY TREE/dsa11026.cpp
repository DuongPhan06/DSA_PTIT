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

int a[1000001];
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

node *build(int a[], int l, int r)
{
    if (l > r)
    {
        return NULL;
    }
    int m = (l + r) / 2;
    node *root = new node(a[m]);
    root->left = build(a, l, m - 1);
    root->right = build(a, m + 1, r);
    return root;
}

void Duyet_LNR(node *root)
{
    if (root != NULL)
    {
        Duyet_LNR(root->left);
        Duyet_LNR(root->right);
        cout << root->val << " ";
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
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        node *root = build(a, 0, n - 1);
        Duyet_LNR(root);
        cout << endl;
    }
    return 0;
}