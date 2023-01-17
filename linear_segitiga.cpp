#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;

//
segitiga(){
	
	float x,a,b,c,miu;
	
    cout << "masukkan nilai x = ";
    cin >> x;

    cout << "masukkan nilai batas awal (a) = ";
    cin >> a;

    cout << "masukkan nilai tengah (b) = ";
    cin >> b;

	cout << "masukkan nilai batas akhir (c) = ";
    cin >> c;

    if(x<=a || x>=c){
        miu = 0;
    } else if (x>=a && x<=b){
        miu = (x-a) / (b-a);
    } else if (x>=b && x<=c ){
        miu = (c-x) / (c-b);
    } else {
    	miu = 1;
	}
	
	cout << "nilai miu = " << miu;
	
	return 0;
	
}

int main(){
	
    segitiga();
    
}