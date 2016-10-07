#include <iostream>
#include <math.h>
using namespace std;
int a,b;
int gcd(int m ,int n){
	if(m%n == 0)
		return n;
	else
		return gcd(n,m%n);
}
int main(){
	int tem,top,ans;
    while(cin>>a>>b){
		tem = a > b ? gcd(a,b) : gcd(b,a);
		top =sqrt(tem);
		ans = 0;
		for(int i = 1; i <= top ; ++i){
			if(tem % i ==0)
				ans++;
		}
		ans *=2;
		if(top * top == tem)
			ans -=1;
		cout<<ans<<endl;
	}
    return 0;
}
