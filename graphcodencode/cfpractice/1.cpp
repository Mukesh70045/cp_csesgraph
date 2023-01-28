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
const int maxn = 1e6;
const int M = 1e9 + 7;
vector<ll> fact(1e6);
vector<ll> inversion(1e6);
vector<bool> seive(maxn, true);
void sieveness()
{
    seive[0] = seive[1] = false;

    for (ll i = 2; i * i <= maxn; i++)
    {
        if (seive[i] == true)
            for (ll j = i * i; j <= maxn; j += i)
            {
                seive[j] = false;
            }
    }
}
bool isprime(long long n)
{
    // check whether a number is prime or not
    for (long long i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}
long long binpow(long long a, long long b, long long m)
{
    a %= m;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
void initialization()
{
    fact[0] = 1;
    fact[1] = 1;
    for (ll i = 2; i <= 3000000; i++)
    {
        fact[i] = (fact[i - 1] * i) % M;
    }
    inversion[3000000] = binpow(fact[3000000], M - 2, M) % M;
    for (ll i = 3000000; i > 0; i--)
    {
        inversion[i - 1] = (inversion[i] * i) % M;
    }
}
ll C(ll n, ll k)
{
    ll res = (((fact[n] * inversion[k]) % M) * inversion[n - k]) % M;
    return res;
}
vector<ll> factorization(ll n)
{
    vector<ll> res;
    for (ll i = 1; i * i <= n; i++)
    {
        if ((n % i) == 0)
        {
            ll a = n / i;
            if (i == a)
            {
                res.push_back(i);
            }
            else
            {
                res.push_back(i);
                res.push_back(n / i);
            }
        }
    }
    return res;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    ll test = 1;
    cin >> test;
    while (test--)
    {
        ll i, j, a, b, c, d, v1, v2, f, cnt, ans, res, print;
        ll w, h;
        cin >> w >> h;
        vector<ll> v;
        ans = -1;
        forne(i, 2)
        {
            read(k);
            v.clear();
            forne(j, k)
            {
                ll a;
                cin >> a;
                v.push_back(a);
            }
            v1 = (v[k - 1] - v[0]);
            v1 *= h;
            // cout << v1 << endl;
            ans = max(ans, v1);
        }
        v1 = 0;
        forne(i, 2)
        {
            read(k);
            v.clear();

            forne(j, k)
            {

                cin >> a;
                v.push_back(a);
            }
            v1 = (v[k - 1] - v[0]);
            v1 *= w;
            ans = max(ans, v1);
        }
        cout << ans << endl;
    }

    return 0;
}
