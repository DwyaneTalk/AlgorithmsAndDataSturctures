/*
ID: dwyanet1
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("gift1.in");
ofstream fout("gift1.out");

string name[10];
int in[10];
int out[10];
int num;
int getNum (string s) {
    int i;
    for (i=0; i< num; ++i) {
        if (name[i] == s)
            return i;
    }
}
int main(){
    fin >>num;
    int i ,j;
    for ( i = 0; i < num; ++i) {
        fin >> name[i];
    }
    for ( i = 0; i < num; ++i) {
        string giver ,geter;
        int count,n;
        fin >> giver;
        n = getNum(giver);
        fin >> in[n] >> count;
        if (!count) continue;
        out[n] -= in[n] - in[n] % count;
        for (j = 0; j < count; ++j) {
            fin >> geter;
            int k = getNum(geter);
            out[k] += in[n] / count;
        }
    }
    for (i = 0; i < num; ++i)
        fout << name[i] << " "<< out[i] << endl;
    return 0;
}
                          Architecture: i386
Source: homerun
Version: 0.2.2-0ubuntu1
Depends: libhomerun0 (= 0.2.2-0ubuntu1)
Filename: pool/universe/h/homerun/libhomerun-dev_0.2.2-0ubuntu1_i386.deb
Size: 7052
MD5sum: a98329cec30607624538b47c0c03af26
SHA1: d9b12e8dc6de5c887a6b065a33b68eb6afa97144
SHA256: 21c4be1ddfe92a72b24994af09ce1c84e984d1afc57c71454c38a5a76aa71a5f
Description: application launcher for KDE Plasma desktop - development files
Homepage: https://projects.kde.org/projects/playground/base/homerun
Description-md5: 6f4d17df8dbdb68e748d2ef0d2e87db7
Bugs: https://bugs.launchpad.net/ubuntu/+filebug
Origin: Ubuntu

Package: libhomerun0
Priority: extra
Section: universe/libs
Ins