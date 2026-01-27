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
int used[1001];
int x[1001];
void Try(int i, ll sum)
{
    for (int j = 1; j <= n; j++)
    {
        if (!used[j])
        {
            used[j] = 1;
            if (i == 1 || abs(j - x[i - 1]) != 1) // loai truong hop x[0] = 0 nan bat dau tu i == 1
            {
                x[i] = j;
                if (i == n)
                {
                    cout << sum * 10 + j << endl;
                }
                else
                {
                    Try(i + 1, sum * 10 + j);
                }
            }
            used[j] = 0;
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        Try(1, 0); // De loai truong hop x[0] = 0 va x[1] = 1
    }
    return 0;
}