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

const int m = 1000000;
int prime[m];
void sieve()
{
    for (int i = 0; i <= m; i++)
    {
        prime[i] = 1;
    }
    prime[0] = prime[1] = 0;
    for (int i = 2; i <= sqrt(m); i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= m; j += i)
            {
                prime[j] = 0;
            }
        }
    }
}

int main()
{
    sieve();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int check = 0;
        for (int i = 2; i <= n; i++)
        {
            if (prime[i] && prime[n - i])
            {
                check = 1;
                cout << i << " " << n - i << endl;
                break;
            }
        }
        if (!check)
        {
            cout << "-1" << endl;
        }
    }
    return 0;
}