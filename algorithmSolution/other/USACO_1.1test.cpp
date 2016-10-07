/*
ID: dwyanet1
PROG: test
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("test.in");
ofstream fout("test.out");
int a, b;

int main(){
    fin >> a >> b;
    fout << ( a + b )<< endl;
    return 0;
}
