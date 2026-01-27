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

int a[1001][1001];
int x[1001];
ll sum;
ll toiuu = 1e9;
bool visited[1001];
int cmin = 1e9, n;
void Try(int i)
{
    for (int j = 2; j <= n; j++)
    {
        if (visited[j] == false)
        {
            visited[j] = true;
            x[i] = j; // Thanh pho lua chon di tu thu i la thanh pho j
            sum += a[x[i]][x[i - 1]];
            if (i == n)
            {
                toiuu = min(toiuu, sum + a[x[n]][1]); // Phai quay ve thanh ph thu nhat
            }
            else if (sum + cmin * (n - i + 1) < toiuu) // giam bot truong hop
            {
                Try(i + 1);
            }
            sum -= a[x[i]][x[i - 1]]; // backtrack lai de di huong khac
            visited[j] = false;
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            if (a[i][j] != 0)
            {
                cmin = min(cmin, a[i][j]);
            }
        }
    }
    x[1] = 1;
    visited[1] = 1;
    Try(2);
    cout << toiuu << endl;
    return 0;
}