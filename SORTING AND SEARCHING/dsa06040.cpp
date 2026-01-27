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

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        long long *a = new long long[x];
        long long *b = new long long[y];
        long long *c = new long long[z];
        for (int i = 0; i < x; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < y; i++)
        {
            cin >> b[i];
        }
        for (int i = 0; i < z; i++)
        {
            cin >> c[i];
        }
        long long d[100000];
        long h = 0;
        long k = 0;
        int check = 0;
        for (int i = 0; i < x; i++)
        {
            for (int j = k; j < y; j++)
            {
                if (a[i] == b[j])
                {
                    d[h] = a[i];
                    h++;
                    check = 1;
                    break;
                }
                else if (b[j] > a[i])
                {
                    k = j;
                    break;
                }
            }
        }
        if (check == 0)
        {
            cout << "-1";
        }
        else
        {
            k = 0;
            for (long i = 0; i < h; i++)
            {
                for (long j = k; j < z; j++)
                {
                    if (d[i] == c[j])
                    {
                        cout << d[i] << " ";
                        check = 2;
                        break;
                    }
                    else if (c[j] > d[i])
                    {
                        k = j;
                        break;
                    }
                }
            }
            if (check == 1 || check == 0)
            {
                cout << "-1";
            }
        }
        cout << endl;
    }
    return 0;
}