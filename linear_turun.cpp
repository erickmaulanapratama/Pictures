#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;

// a<x<b = b-a / b-a
turun(){
	
	float x,a,b,miu;
    
	cout << "masukkan nilai x = ";
    cin >> x;

    cout << "masukkan nilai batas awal (a) = ";
    cin >> a;

    cout << "masukkan nilai batas akhir (b) = ";
    cin >> b;

    if(x>=b){
        miu = 0;
    } else if (x>a && x<b){
        miu = (b-x) / (b-a);
    } else {
        miu = 1;
    }
	
	cout << "nilai miu = " << miu;
	
	return 0;

}

int main(){
	
    turun();
    
}