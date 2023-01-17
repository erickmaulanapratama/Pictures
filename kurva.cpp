#include<iostream>
#include<stdio.h>
#include<cmath>	
using namespace std;



int main(){
	
	float a,b,b1,b2,c,d,r1,r2,x,y,miu;
	int opsi;
	
	cout << "Program Mencari Nilai Fuzzy" << endl;
	cout << "Silahkan Pilih Kurva (1-7)" << endl;
	cout << "1. Naik" << endl;
	cout << "2. Turun" << endl;
	cout << "3. Segitiga" << endl;
	cout << "4. Trapesium" << endl;
	cout << "5. Pertumbuhan" << endl;
	cout << "6. Penyusutan" << endl;
	cout << "7. Lonceng" << endl << endl;
	cout << "Pilihan Anda = "; cin >> opsi;
	cout << endl; 
	
	switch(opsi){
		case 1:
			
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
			
		break;
		
		case 2:
			
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

		break;
		
		case 3:
			
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
			
		break;
		
		case 4:
			
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

		break;
		
		case 5:
			
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
			
		break;
		
		case 6:
			
			cout << "masukkan nilai x = ";
		    cin >> x;
		
		    cout << "masukkan nilai Alpha (a) = ";
		    cin >> a;
		
			cout << "Masukan nilai Beta (b) = ";
		    cin >> b;
		
		    cout << "masukkan nilai Gamma (y) = ";
		    cin >> y;
		        
		    if(x<=a){
		        miu = 1;
		    } else if (x>=a && x<=b){
		        miu = 1-2*pow((x-a)/(y-a),2);
		    } else if (x>=b && x<=y){
		        miu = 2*pow((y-x)/(y-a),2);
		    } else {
		    	miu = 0;
			}
			
			cout << "nilai miu = " << miu;
			
		break;
		
		case 7:
			
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
			
		break;
		
		default:
			
			cout << "Pilihan Anda Tidak Tersedia" << endl;
			
		break;
	}
}