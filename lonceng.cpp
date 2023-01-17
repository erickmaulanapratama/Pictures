#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;

//
lonceng(){
	
	float x,r1,b1,y,b2,r2,miu;

    cout << "masukkan nilai x = ";
    cin >> x;

    cout << "masukkan nilai Rule 1 (r1) = ";
    cin >> r1;

	cout << "Masukan nilai Beta 1 (b1) = ";
    cin >> b1;
	
    cout << "masukkan nilai Gamma (y) = ";
    cin >> y;
    
    cout << "masukkan nilai Beta 2 (b2) = ";
    cin >> b2;
    
    cout << "masukkan nilai Rule 2 (r2) = ";
    cin >> r2;

    if(x<=r1 || x>=r2){
		miu = 0;
	} else if(x>=b1 && x<=y){
		miu = 1-2*pow((y-x) / (y-r1),2);
	} else if(x>=r1 && x<=b1){
		miu = 2*pow((x-r1) / (y-r1),2);
	} else if(x>=y && x<=b2){
		miu = 1-2*pow((x-y) / (r2-y),2);
	} else if(x>=b2 && x<=r2){
		miu = 2*pow((r2-x) / (r2-y),2);
    }else{
    	miu = 1;
	}
	
	cout << "nilai miu = " << miu;
	
	return 0;
	
}

int main(){
	
    lonceng();
    
}