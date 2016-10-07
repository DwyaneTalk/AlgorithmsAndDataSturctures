#include <iostream>
using namespace std;
int num[7]={1,2,5,10,20,50,100};

int main(){
    int p ,res;
    while(cin>>p){
        res = 0;
        for(int i = 6; i > 0; i--){
            res += p / num[i];
            p = p%num[i];
        }
        cout << (res+p)<<endl;
     }
    return 0;
}
