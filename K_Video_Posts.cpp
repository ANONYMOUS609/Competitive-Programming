#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(false);cin.tie(0)
#define pb push_back
#define digit(x) floor(log10(x))+1
#define mod 1000000007
#define endl "\n"
#define int long long
#define matrix vector<vector<int> >
#define vi vector<int>
#define pii pair<int,int>
#define vs vector<string>
#define vp vector<pii>
#define test() int t;cin>>t;while(t--)
#define all(x) x.begin(),x.end()
#define debug(x) cerr << #x << " is " << x << endl;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
const int sz = 100005;
void showArr(int *arr, int n){for(int i=0;i<n;i++) cout<<arr[i]<<" ";}
//=================================================================//


int32_t main(){
    fast;
    int n, k;
    cin>>n>>k;
    int sum = 0;
    int arr[n];
    for(int i=0;i<n;i++) {
        cin>>arr[i];
        sum+=arr[i];
    }
    vector<int> v;
    if((sum%k)!=0) {
        cout<<"No"<<endl;
    } else {
        int tmp = 0;
        int cnt = 0;
        int avg = sum/k;
        for(int i=0;i<n;i++) {
            if(tmp+arr[i] < avg) {
                tmp+=arr[i];
                cnt++;
            } else if(tmp + arr[i] == avg){
                cnt++;
                tmp+=arr[i];
                v.push_back(cnt);
                cnt = 0;
                tmp = 0;
            } else {
                cout<<"No";
                exit(0);
            }
        }
        cout<<"Yes"<<endl;
        for(int i=0;i<v.size();i++) {
            cout<<v[i]<<" ";
        }
    }
    
    return 0;
}