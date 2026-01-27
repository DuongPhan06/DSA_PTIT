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

int a[1001][1001], b[1001][1001];
bool visited[1001];
int x[1001];
int cot[100], h1[101], h2[101];
ll gtln = INT_MIN;
void Try(int i, ll sum)
{
    for (int j = 1; j <= 8; j++)
    {
        if (cot[j] != 0 && h1[i - j + 8] != 0 && h2[i + j - 1] != 0)
        {
            cot[j] = h1[i - j + 8] = h2[i + j - 1] = 0;
            x[i] = j;
            if (i == 8)
            {
                gtln = max(gtln, sum + a[i][j]);
            }
            else
            {
                Try(i + 1, sum + a[i][j]);
            }
            cot[j] = h1[i - j + 8] = h2[i + j - 1] = 1;
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        gtln = INT_MIN;
        memset(visited, false, sizeof(visited));
        for (int i = 1; i <= 100; i++)
        {
            cot[i] = h1[i] = h2[i] = 1;
        }
        for (int i = 1; i <= 8; i++)
        {
            for (int j = 1; j <= 8; j++)
            {
                cin >> a[i][j];
            }
        }
        Try(1, 0);
        cout << gtln << endl;
    }
    return 0;
}