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

int n;
int x[1001];
int a[1000001];
void Try(int i)
{
    if (i == 0)
    {
        return;
    }
    cout << "[";
    for (int j = 1; j <= i; j++)
    {
        cout << a[j];
        if (j == i)
        {
            cout << "]";
        }
        else
            cout << " ";
    }
    cout << endl;
    for (int j = 0; j < i; j++)
    {
        a[j] += a[j + 1];
    }
    Try(i - 1);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        Try(n);
    }
    return 0;
}