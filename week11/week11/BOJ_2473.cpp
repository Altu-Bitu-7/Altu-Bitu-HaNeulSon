#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll; 
ll n;
ll a[5004];
ll ans[4];
ll ret = 1e18; 

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	sort(a+1, a+1+n);
	for(int i=1; i<=n-2; i++){
		ll st = i+1;
		ll en = n;
		while(st < en){
			ll v = a[i] + a[st] + a[en];
			if(abs(v) < ret){ 
				ret = abs(v); 
				ans[1] = a[i];
				ans[2] = a[st];
				ans[3] = a[en];
			}
			if(v < 0) {
        st++;
      } 
			else {
         en--;
      } 
		}
	}
	cout << ans[1] << ' ' << ans[2] << ' ' << ans[3];
	return 0;
}