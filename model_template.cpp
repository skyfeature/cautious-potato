#include <bits/stdc++.h>

using namespace std;

typedef long long lli;
typedef long double ld;
typedef pair<lli, lli > plli;
typedef vector<lli> vlli;
typedef vector<plli > vplli;

#define rep(i,a) for(i = 0 ; i < a ; i++)
#define repr(i,a) for(i = a ; i >= 0 ; i--)
#define REP(i,a,b) for(i = a ; i <= b ; i++)
#define REPR(i,a,b) for(i = a ; i >= b ; i--)

#define scan(N) scanf("%lld",&N)
#define print(N) printf("%lld",N)
#define scan2(N1,N2) scanf("%lld %lld",&N1,&N2)
#define print2(N1,N2) printf("%lld %lld",N1,N2)
#define scan3(N1,N2,N3) scanf("%lld %lld %lld",&N1,&N2,&N3)
#define print3(N1,N2,N3) printf("%lld %lld %lld",N1,N2,N3)

#define mem(a,b)memset(a,b,sizeof(a))
#define opt ios_base::sync_with_stdio(false);cin.tie(NULL);
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a)*((b)/gcd(a,b)))
#define sqr(x) (x)*(x)
#define all(a) a.begin(),a.end()
#define mp make_pair
#define pb push_back
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl

#define endl '\n'

const long long INF = 2000000000000;
const long long MOD = 1000000007;
const long long MAXN = 301;

template<class T> bool is_prime(T n)
{
	if((n%2 == 0 and n > 2) or n < 2 )
		return false;
	for(T i = 3; i*i <= n ; i += 2)
	{
		if( n % i == 0)
			return false;
	}
	return true;
}
lli power(lli a,lli b)
{
    lli value;
    if(!b)
    	return 1;
    else if(b%2==0)
    {
        value = power(a,b/2)%MOD;
        return (value * value)%MOD;
    }
    else
    {
        value = power(a,b/2)%MOD;
        return ((a*value)%MOD*(value))%MOD;
    }
}
vlli c(MAXN);
lli n,m,dp[MAXN][MAXN];

lli f(lli i,lli val)
{
    if(i >= m)
        return 0;
    if(val < 0)
        return 0;
    if(!val)
        return 1;
    if(dp[i][val] != -1)
        return dp[i][val];
    lli ans = f(i,val - c[i]) + f(i+1,val);
    return dp[i][val] = ans;
}

void solve()
{
    mem(dp,-1);
    lli i;
    cin >> m;
    rep(i,m)
        cin >> c[i];
    cin >> n;
    cout << f(0,n) << endl;
}
int main()
{
	opt;
	lli t;
	cin >> t;
	while(t--)
        solve();
	return 0;
}