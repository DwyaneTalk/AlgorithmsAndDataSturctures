/*
ID: dwyanet1
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("ride.in");
ofstream fout("ride.out");
string str1, str2;

int main(){
    fin >> str1 >> str2;
    int num1 =1, num2 = 1;
    int i;
    for(i =0; i < str1.length(); ++i) {
        num1 *= str1[i] - 'A' + 1;
        num1 = num1 % 47;
   }
    for(i =0; i < str2.length(); ++i) {
        num2 *= str2[i] - 'A' + 1;
        num2 = num2 % 47;
    }
    if (num1 == num2)
        fout << "GO" << endl;
    else
        fout << "STAY" << endl;
    return 0;
}
