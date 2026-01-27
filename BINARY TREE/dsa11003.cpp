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

int in[1000001], pre[1000001];
int search(int in[], int x, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (in[i] == x)
        {
            return i;
        }
    }
    return -1;
}
void postOrder(int in[], int pre[], int n)
{
    int root = search(in, pre[0], n);
    if (root != 0)
    {
        postOrder(in, pre + 1, root);
    }
    if (root != n - 1)
    {
        postOrder(in + root + 1, pre + root + 1, n - root - 1);
    }
    cout << pre[0] << " ";
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
            cin >> in[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> pre[i];
        }
        postOrder(in, pre, n);
        cout << endl;
    }
    return 0;
}