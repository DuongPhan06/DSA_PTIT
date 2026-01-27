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

int x[1001];
int n, k;
void Try(int i)
{
    for (int j = x[i - 1] + 1; j <= n; j++)
    {
        x[i] = j;
        if (i == k)
        {
            for (int i = 1; i <= k; i++)
            {
                cout << char(x[i] + 'A' - 1);
            }
            cout << endl;
        }
        else
        {
            Try(i + 1);
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        Try(1);
    }
    return 0;
}