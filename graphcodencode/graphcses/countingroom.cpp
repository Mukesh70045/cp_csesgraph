#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(i, n) for (ll i = 0; i < n; i++)
#define forn(i, n) for (ll i = 1; i < n; i++)
#define forne(i, n) for (ll i = 1; i <= n; i++)
#define revn(i, n) for (ll i = n - 1; i >= 0; i--)
#define sortl(v) sort(v.begin(), v.end())
#define reversal(v) reverse(v.begin(), v.end())
#define countset(n) __builtin_popcountll(n)
#define maxelement(v) *max_element(v.begin(), v.end())
#define minelement(v) *min_element(v.begin(), v.end())
#define vi vector<ll>
#define f(map) for (auto it : map)
#define read(n) \
    ll n;       \
    cin >> n;
const int inf = 1e9 + 7;

ll n,
    m;
bool visited[1006][1006];

vector<vector<char>> input(1006, vector<char>(1006, '#'));

bool isvalid(ll x, ll y)
{
    // if it is one base indexed;
    if (input[x][y] == '#')
        return false;
    if (x < 1 || x > n || y < 1 || y > m)
        return false;
    if (visited[x][y] == true)
        return false;
    return true;
}
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
void dfs(ll x, ll y)
{
    visited[x][y] = true;
    // cout << x << " " << y << endl;
    for (int i = 0; i < 4; i++)
    {
        if (isvalid(x + dx[i], y + dy[i]))
        {
            dfs(x + dx[i], y + dy[i]);
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    ll test = 1;
    // cin >> test;
    while (test--)
    {

        cin >> n >> m;
        forne(i, n)
        {
            forne(j, m)
            {
                cin >> input[i][j];
                visited[i][j] = false;
            }
        }

        ll count = 0;
        forne(i, n)
        {
            forne(j, m)
            {
                if (visited[i][j] == false && input[i][j] == '.')
                {
                    dfs(i, j);
                    count++;
                }
            }
        }
        cout << count << endl;
    }

    return 0;
}
