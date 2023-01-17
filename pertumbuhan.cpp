#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;

//
pertumbuhan(){
	
	float x,a,b,y,miu;
	
    cout << "masukkan nilai x = ";
    cin >> x;

    cout << "masukkan nilai Alpha (a) = ";
    cin >> a;

	cout << "Masukan nilai Beta (b) = ";
    cin >> b;

    cout << "masukkan nilai Gamma (y) = ";
    cin >> y;
	
    if(x<=a){
        miu = 0;
    } else if (x>=a && x<=b){
        miu = 2*pow((x-a)/(y-a),2);
    } else if (x>=b && x<=y){
        miu = 1-2*pow((y-x)/(y-a),2);
    } else {
    	miu = 1;
	}
	
	cout << "nilai miu = " << miu;
	
	return 0;
	
}

int main(){
	
    pertumbuhan();
    
}