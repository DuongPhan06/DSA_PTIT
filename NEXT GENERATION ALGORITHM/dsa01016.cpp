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
void Try(int i, int bd, ll sum)
{
    if (sum > n)
    {
        return;
    }
    if (sum == n)
    {
        cout << "(";
        for (int k = 1; k < i; k++)
        {
            cout << x[k];
            if (k != i - 1)
            {
                cout << " ";
            }
        }
        cout << ") ";
        return;
    }
    for (int j = bd; j >= 1; j--)
    {
        x[i] = j;
        Try(i + 1, j, sum + j);
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        Try(1, n, 0);
        cout << endl;
    }
    return 0;
}