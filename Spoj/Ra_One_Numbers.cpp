#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(false);cin.tie(0)
#define pb push_back
#define digit(x) floor(log10(x))+1
#define mod 1000000007
#define endl "\n"
#define int long long
typedef long double ld;
typedef vector<vector<int> > matrix;
typedef vector<int> arr;
typedef vector<string> vs;
typedef vector<pair<int,int> > pv;
#define test() int t;cin>>t;while(t--)
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define ROF(i,a,b) for(int i=a;i>=b;--i)
#define all(x) x.begin(),x.end()
#define debug(x) cerr << #x << " is " << x << endl;
int bx[]={0,0,1,-1,1,-1,-1,1};
int by[]={1,-1,0,0,1,-1,1,-1};
//=================================================================//
string s;
int n;
int dp[10][2][82][82];

int solve(int pos, bool tight, int even, int odd) {
    if(pos==n) {
        int ans = even-odd;
        if(s.length()&1) ans = -1*ans;
        if(ans==1) return 1;
        return 0;
    }

    int &res = dp[pos][tight][even][odd];
    if(res != -1) return res;
    int ans = 0;

    int end = (tight) ? s[pos]-'0' : 9;
    for(int dig=0;dig<=end;dig++) {
        if(pos&1)
            ans+=solve(pos+1, tight&(dig==end), even, odd + dig);
        else
            ans+=solve(pos+1, tight&(dig==end), even + dig, odd);
    }
    return res = ans;
}


#undef int
int main(){
#define int long long 
    fast;
    test() {
        int a,b;
        cin>>a>>b;
        s = to_string(a-1);
        n = s.length();
        memset(dp, -1, sizeof dp);
        int ans1 = solve(0,1,0,0);
        s = to_string(b);
        n = s.length();
        memset(dp, -1, sizeof dp);
        int ans2 = solve(0,1,0,0);
        cout<<ans2-ans1<<endl;
    }   
    return 0;
}