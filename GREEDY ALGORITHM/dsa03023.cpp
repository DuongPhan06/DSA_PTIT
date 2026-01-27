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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int T = 0;
    int X = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'T')
        {
            T++;
        }
        else if (s[i] == 'X')
        {
            X++;
        }
    }
    int ans = 0;
    for (int i = 0; i < X; i++)
    {
        if (s[i] == 'T')
        {
            int j = X; // Sap xep dang sau xanh
            while (s[j] != 'X')
            {
                j++;
            }
            swap(s[i], s[j]);
            ans++;
        }
        else if (s[i] == 'D')
        { // Sap xeo sao cho do ve cuoi day
            int j = s.size() - 1;
            while (s[j] != 'X')
            {
                j--;
            }
            swap(s[i], s[j]);
            ans++;
        }
    }
    for (int i = X; i < T + X; i++)
    {
        if (s[i] != 'T')
        {
            int j = T + X;
            while (s[j] != 'T') // Chuyen trang ve thu hai
            {
                j++;
            }
            swap(s[i], s[j]);
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}