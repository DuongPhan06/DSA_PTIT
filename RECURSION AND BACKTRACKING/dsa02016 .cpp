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
int cot[1001], h1[1001], h2[1001];
int x[1001];
int cnt = 0;
void Try(int i)
{
    for (int j = 1; j <= n; j++)
    {
        if (cot[j] == 1 && h1[i - j + n] == 1 && h2[i + j - 1] == 1)
        {
            x[i] = j;
            cot[j] = h1[i - j + n] = h2[i + j - 1] = 0;
            if (i == n)
            {
                cnt++;
            }
            else
            {
                Try(i + 1);
            }
            cot[j] = h1[i - j + n] = h2[i + j - 1] = 1;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cnt = 0;
        cin >> n;

        for (int i = 1; i <= 100; i++)
        {
            cot[i] = h1[i] = h2[i] = 1;
        }
        Try(1);
        cout << cnt << endl;
    }
    return 0;
}