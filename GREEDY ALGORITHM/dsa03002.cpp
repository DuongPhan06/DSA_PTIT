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
    string a, b;
    cin >> a >> b;
    string tmp1 = a, tmp2 = b;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == '6')
        {
            a[i] = '5';
        }
    }
    for (int i = 0; i < b.size(); i++)
    {
        if (b[i] == '6')
        {
            b[i] = '5';
        }
    }
    cout << stoll(a) + stoll(b) << " ";
    for (int i = 0; i < tmp1.size(); i++)
    {
        if (tmp1[i] == '5')
        {
            tmp1[i] = '6';
        }
    }
    for (int i = 0; i < tmp2.size(); i++)
    {
        if (tmp2[i] == '5')
        {
            tmp2[i] = '6';
        }
    }
    cout << stoll(tmp1) + stoll(tmp2) << endl;
    return 0;
}