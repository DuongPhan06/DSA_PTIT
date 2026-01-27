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

// Xay dung cay nhi phan tim kiem can bang thi phai sap xep mang tang dan
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

node *build(node *root, int l, int r)
{
    if (l > r)
    {
        return NULL;
    }
    int m = (l + r) / 2;
    root = new node(a[m]);
    build(root->left, l, m - 1);
    build(root->right, m + 1, r);
    return root;
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
        node *root = build(root, 0, n - 1);
        cout << root->val << endl;
    }
    return 0;
}