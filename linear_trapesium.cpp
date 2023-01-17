#include<iostream>
#include<stdio.h>
#include<cmath.h>
using namespace std;

//
trapesium(){
	
	float x,a,b,c,d,miu;
	
    cout << "masukkan nilai x = ";
    cin >> x;

    cout << "masukkan nilai batas awal (a) = ";
    cin >> a;

    cout << "masukkan nilai tengah 1 (b) = ";
    cin >> b;

	cout << "masukkan nilai tengah 2 (c) = ";
    cin >> c;
    
    cout << "masukkan nilai batas akhir (d) = ";
    cin >> d;

    if(x<=a || x>=d){
        miu = 0;
    } else if (x>a && x<b){
        miu = (x-a) / (b-a);
    } else if (x>=b && x<=c){
        miu = 1;
    } else {
    	miu = (d-x) / (d-c);
	}
	
	cout << "nilai miu = " << miu;
	
	return 0;
	
}

int main(){
	
    trapesium();
    
}