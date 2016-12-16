/*My First Template :D*/
#include <bits/stdc++.h>
#include <limits.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
 
#define MOD (ll)1000000007
#define pb   push_back
#define EPS 1e-9
#define FOR(i,n)  for(int i = 0;i < n; i++)
#define FORE(i,a,b) for(int i = a;i <= b; i++)
#define pi(a)   printf("%d\n", a)
#define all(c)  c.begin(), c.end()
#define tr(container, it)   for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define gc getchar_unlocked
#define sdi(a, b)   si(a);si(b)
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'

template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}
template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return mod_exp(a, p-2, p);}
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}

void si(int &x){
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

ll dp[10005];

int main(){
    io;
    int t;
    cin >> t;
    int kase = 1;
    while(t--){
        memset(dp, 0, sizeof(dp));
        cout << "Case " << kase << ": " ;
        kase++; 
        int n;
        cin >> n;
        ll arr[n];
        FOR(i,n)    cin>>arr[i];
        if(n == 0){
            cout << 0 << endl;
        }else if(n == 1){
            cout << arr[0] << endl;
        }else if(n == 2){
            cout << max(arr[0], arr[1]) << endl;
        }else{
            dp[0] = arr[0];
            dp[1] = max(arr[0],arr[1]);
            for(int i = 2;i < n; i++){
                dp[i] = max(dp[i-1], dp[i-2]+arr[i]);
            }
            cout << dp[n-1] << endl;
        }
    }
    return 0;
}
