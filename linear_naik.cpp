#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;

// a<x<b = x-a / b-a
naik(){
	
	float x,a,b,miu;
	
    cout << "masukkan nilai x = ";
    cin >> x;

    cout << "masukkan nilai batas awal (a) = ";
    cin >> a;

    cout << "masukkan nilai batas akhir (b) = ";
    cin >> b;

    if(x<=a){
        miu = 0;
    } else if (x>a && x<b){
        miu = (x-a) / (b-a);
    } else {
        miu = 1;
    }
	
	cout << "nilai miu = " << miu;
	
	return 0;
	
}

int main(){
	naik();
}