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
int dp[1000001];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        dp[a[i]] = i; // So a[i] o vi tri thu i
    }
    int gtln = 1, tmp = 1;
    for (int i = 2; i <= n; i++)
    {
        if (dp[i] > dp[i - 1])
        {
            tmp++;
        }
        else
        {
            tmp = 1;
        }
        gtln = max(gtln, tmp); // Tim day con tang dai nhat lien tiep VD 1 2 3 4 5
    }
    cout << n - gtln << endl;
    return 0;
}