//header
#include <iostream>
#include <stdio.h>
using namespace std;

//variabel global
float x, bAwal, bAkhir, Z, z1, z2, a[8], z[8];

//fungsi linear naik
float linearNaik(float x, float bAwal, float bAkhir){

	//variabel lokal
	float miu;
	
	//proses
    if (x<=bAwal){
        miu = 0;
    } else if (x>bAwal && x<bAkhir){
        miu = (x-bAwal)/(bAkhir-bAwal);
    } else{
        miu = 1;
    }

	//return
    return miu;
}

//fungsi linear turun
float linearTurun(float x, float bAwal, float bAkhir){

	//variabel lokal
	float miu;

	//proses
	if (x<=bAwal){
        miu = 1;
    } else if (x>bAwal && x<bAkhir){
        miu = (bAkhir-x)/(bAkhir-bAwal);
    } else{
        miu = 0;
    }

	//return
    return miu;
}

//fungsi main
int main(){

	//variabel lokal
	float demamrendah, demamtinggi, bercaksedikit, bercakbanyak, gbkecil, gbbesar;

	//judul
	cout << "----------------------------------------" << endl;
	cout << "Diagnosis Rubella dengan Fuzzy Tsukamoto" << endl;
	cout << "----------------------------------------" << endl << endl;

	//input demam
	cout << "Input Banyak Data Gejala" << endl;
	cout << "1. Demam = "; cin >> x;

	//set domain demam
	bAwal = 1;
	bAkhir = 10;

	//proses miu demam
	demamrendah = linearTurun(x,bAwal,bAkhir);
	demamtinggi = linearNaik(x,bAwal,bAkhir);

	//input bercak merah
	cout << "2. Bercak Merah = "; cin >> x;

	//set domain bercak merah
	bAwal = 1;
	bAkhir = 5;

	//peoses miu bercak merah
	bercaksedikit = linearTurun(x,bAwal,bAkhir);
	bercakbanyak = linearNaik(x,bAwal,bAkhir);

	//input pembesaran kelenjar getah bening
	cout << "3. Pembesaran Kelenjar Getah Bening = "; cin >> x;

	//set domain pembesaran kelenjar getah bening
	bAwal = 1;
	bAkhir = 10;

	//proses miu pembesaran kelenjar getah bening
	gbkecil = linearTurun(x,bAwal,bAkhir);
	gbbesar = linearNaik(x,bAwal,bAkhir);

	cout << endl;

	cout << "----------------------------------------" << endl << endl;
	
	//tahap1
	cout << "----------------------------------------" << endl;
	cout << "Tahap 1 <-> Fuzzyfikasi" << endl;
	cout << "----------------------------------------" << endl << endl;
	
	//output miu demam
	cout << "miu Demam Rendah = " << demamrendah << endl;
	cout << "miu Demam Tinggi = " << demamtinggi << endl << endl;

	//output miu bercak merah
	cout << "miu Bercak Merah Sedikit = " << bercaksedikit << endl;
	cout << "miu Bercak Merah Banyak = " << bercakbanyak << endl << endl;

	//output miu pembesaran kelenjar getah bening
	cout << "miu Pembesaran Kelenjar Getah Bening Kecil = " << gbkecil << endl;
	cout << "miu Pembesaran Kelenjar Getah Bening Besar = " << gbbesar << endl << endl;

	cout << "----------------------------------------" << endl << endl;

	//tahap2
	cout << "----------------------------------------" << endl;
	cout << "Tahap 2 <-> Inferensi" << endl;
	cout << "----------------------------------------" << endl << endl;

	//proses perbadingan nilai demam & bercak (a-prediket 1-8)
	a[0] = min(demamrendah,bercaksedikit); //normal
	a[1] = min(demamrendah,bercaksedikit); //normal
	a[2] = min(demamrendah,bercakbanyak); //normal
	a[3] = min(demamrendah,bercakbanyak); //rubella
	a[4] = min(demamtinggi,bercaksedikit); //normal
	a[5] = min(demamtinggi,bercaksedikit); //rubella
	a[6] = min(demamtinggi,bercakbanyak); //rubella
	a[7] = min(demamtinggi,bercakbanyak); //rubella
	
	//proses perbandingan semua nilai (a-prediket 1-8)
    a[0] = min(gbkecil,a[0]); //normal
	a[1] = min(gbbesar,a[1]); //normal
	a[2] = min(gbkecil,a[2]); //normal
	a[3] = min(gbbesar,a[3]); //rubella
	a[4] = min(gbkecil,a[4]); //normal
	a[5] = min(gbbesar,a[5]); //rubella
	a[6] = min(gbkecil,a[6]); //rubella
	a[7] = min(gbbesar,a[7]); //rubella
	
	//proses mencari nilai z1 - z8
	z[0] = (bAkhir - bAwal) * a[0] + bAwal; //normal
	z[1] = (bAkhir - bAwal) * a[1] + bAwal; //normal
	z[2] = (bAkhir - bAwal) * a[2] + bAwal; //normal
	z[3] = bAkhir - (bAkhir-bAwal) * a[3]; //rubella
	z[4] = (bAkhir - bAwal) * a[4] + bAwal; //normal
	z[5] = bAkhir - (bAkhir-bAwal) * a[5]; //rubella
	z[6] = bAkhir - (bAkhir-bAwal) * a[6]; //rubella
	z[7] = bAkhir - (bAkhir-bAwal) * a[7]; //rubella

	//output a-prediket 1-8  & z1 - z8
	for (int i = 0; i < 8; i++){
        cout <<"a-prediket"<< i+1 << " = " << a[i] << endl << "Z"<< i+1 << " = " << z[i] << endl << endl;
    }

	cout << "----------------------------------------" << endl << endl;
	
	//tahap3
	cout << "----------------------------------------" << endl;
	cout << "Tahap 3 <-> Defuzzyfikasi" << endl;
	cout << "----------------------------------------" << endl << endl;
	
	//proses mencari Z
	for ( int i = 0; i < 8; i++)
    {
        z1+= z[i]*a[i];
        z2+= a[i];
    }

	Z = z1/z2;

	//output defuzzyfikasi
	cout << "Z* = " << z1 << endl;
	cout << "Z* = " << z2 << endl;
	cout << "Hasil Defuzzyfikasi = " << Z << endl << endl;

	cout << "---------------------------------------" << endl;

	//return
    return 0;
}