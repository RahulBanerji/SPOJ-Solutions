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
#define FOR(i, n)  for(int i = 0;i < n; i++)
#define pi(a)   printf("%d\n", a)
#define all(c)  c.begin(), c.end()
#define tr(container, it)   for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define gc getchar_unlocked
#define sdi(a, b)   si(a);si(b)
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

int n;
const int MAXN = 5e4+5;
const int MINN = -15008;
int arr[MAXN];
struct Tree{ int maxisum, maxlsum, maxrsum, sum; };
Tree T[4*MAXN];

int max3(int a, int b, int c){
  return max(a, max(b,c));
}

void build(int node, int start, int end){
  if(start > end)
    return;
  if(start == end){
    T[node].maxrsum = T[node].maxlsum = T[node].maxisum = T[node].sum = arr[start];
    return;
  }
  int mid = (start+end)>>1;
  int left = node<<1, right = left+1;
  build(left, start, mid);
  build(right, mid+1, end);
  T[node].sum = T[left].sum+T[right].sum;
  T[node].maxisum = max3(T[left].maxisum, T[right].maxisum, T[left].maxrsum+T[right].maxlsum);
  T[node].maxlsum = max(T[left].maxlsum, T[left].sum+T[right].maxlsum);
  T[node].maxrsum = max(T[right].maxrsum, T[right].sum+T[left].maxrsum);
}

Tree query(int node, int start, int end, int l, int r){
  // cout<<node<<endl;
  // cout<<start<<' '<<end<<' '<<l<<' '<<r<<endl;
  if(start > end || start > r || end < l){
    // cout<<"HE"<<endl;
    Tree res;
    res.sum = 0;
    res.maxisum = MINN;
    res.maxlsum = MINN;
    res.maxrsum = MINN;
    return res;
  }
  if(l <= start && end <= r){
    // cout<<node<<endl;
    return T[node];
  }
  int mid = (start+end)>>1;
  int left = node<<1, right = left+1;
  // cout<<"KAR"<<endl;
  // cout<<left<<endl;
  Tree leftRet = query(left, start, mid, l, r);
  // cout<<leftRet.sum<<' '<<leftRet.maxisum<<' '<<leftRet.maxrsum<<' '<<leftRet.maxlsum<<endl;
  Tree rightRet = query(right, mid+1, end, l, r);
  // cout<<rightRet.sum<<' '<<rightRet.maxisum<<' '<<rightRet.maxrsum<<' '<<rightRet.maxlsum<<endl;
  Tree ans;
  ans.sum = leftRet.sum+rightRet.sum;
  ans.maxisum = max3(leftRet.maxisum, rightRet.maxisum, leftRet.maxrsum+rightRet.maxlsum);
  ans.maxlsum = max(leftRet.maxlsum, leftRet.sum+rightRet.maxlsum);
  ans.maxrsum = max(rightRet.maxrsum, rightRet.sum+leftRet.maxrsum);
  // cout<<ans.sum<<' '<<ans.maxisum<<' '<<ans.maxrsum<<' '<<ans.maxlsum<<endl;
  // cout<<ans.maxisum<<endl;
  return ans; 
}


int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    si(n);
    FOR(i, n) si(arr[i]);
    build(1, 0, n-1);
    // for(int i = 1;i <= 5; i++){
    //   cout<<T[i].sum<<' '<<T[i].maxisum<<' '<<T[i].maxlsum<<' '<<T[i].maxrsum<<endl;
    // }
    int q;
    si(q);
    while(q--){
      int l, r;
      sdi(l,r);
      Tree ans = query(1, 0, n-1, l-1, r-1);
      printf("%d\n", ans.maxisum);
    }
    return 0;
}