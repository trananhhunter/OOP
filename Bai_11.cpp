#include <bits/stdc++.h>
using namespace std;

class SinhVien{
	private :
		double d[5];
		string hoten;
		int namsinh;
		
	public:
		SinhVien(){
		}
		void nhap(){
			cout << "Ho ten : "; getline(cin,hoten);
			cout << "Nam sinh : "; cin >> namsinh;
			cout << "Nhap 5 diem mon hoc : \n";
			for(int i=0;i<5;i++){
				cout << "Diem " << i +1 << ": "; cin >> d[i];
			}
			cin.ignore();
		}
		void in(){
			cout << "|" << setw(30) << setfill(' ') << left << hoten;
			cout << "|" << setw(10) << setfill(' ') << left << namsinh;
			cout << "|" << setw(8) << setfill(' ') << left << d[0];
			cout << "|" << setw(8) << setfill(' ') << left << d[1];
			cout << "|" << setw(8) << setfill(' ') << left << d[2];
			cout << "|" << setw(8) << setfill(' ') << left << d[3];
			cout << "|" << setw(8) << setfill(' ') << left << d[4] <<"|\n";	
		}
		double dtb(){
			double diem=0;
			for(int i=0;i<5;i++) diem+= d[i];
			return (double)diem /5;
		}
		bool checkthilai(){
			for(int i=0;i<5;i++){
				if(d[i] < 5){
					return true;
				}
			}
			return false;
		}
		string getHoTen(){
			return hoten;
		}
		int getNamsinh(){
			return namsinh;
		}
		double getDiem(int i) {
        	return d[i];
    	}
    	bool totnghiep(){
    		for(int i=0;i<5;i++){
    			if(d[i] <= 5 && dtb() < 7){
    				return true;
				}
			}
			return false;
		}
		bool doan(){
			for(int i=0;i<5;i++){
    			if(d[i] <= 5 && dtb() >= 7){
    				return true;
				}
			}
			return false;
		}
		double gpa(){
			if (dtb() >= 9.0 && dtb() <= 10.0) {
		        return 4.0;
		    } else if (dtb() >= 8.0 && dtb() < 9.0) {
		        return 3.5;
		    } else if (dtb() >= 7.0 && dtb() < 8.0) {
		        return 3.0;
		    } else if (dtb() >= 6.0 && dtb() < 7.0) {
		        return 2.5;
		    } else if (dtb() >= 5.0 && dtb() < 6.0) {
		        return 2.0;
		    } else if (dtb() >= 4.0 && dtb() < 5.0) {
		        return 1.0;
		    } else {
		        return 0.0; // Du?i 4.0, không d?t
		    }
		}
		
};

void inSinhVien(SinhVien a[],int n){
	cout << "|" << setw(30) << setfill(' ') << left << "Ho ten";
			cout << "|" << setw(10) << setfill(' ') << left << "Nam sinh";
			cout << "|" << setw(8) << setfill(' ') << left << "Diem 1";
			cout << "|" << setw(8) << setfill(' ') << left << "Diem 2";
			cout << "|" << setw(8) << setfill(' ') << left << "Diem 3";
			cout << "|" << setw(8) << setfill(' ') << left << "Diem 4";
			cout << "|" << setw(8) << setfill(' ') << left << "Diem 5" <<"|\n";
	cout << setw(88) << setfill('-') << "-" << endl;
	for(int i=0;i<n;i++){
		a[i].in();
	}
}



void thilai(SinhVien a[],int n){
	cout << "Danh sach sinh vien phai thi lai : \n";
	bool check = true;
	for(int i=0;i<n;i++){
		if(a[i].checkthilai()){
			check = false;
			cout << a[i].getHoTen() << " " << a[i].getNamsinh();
			for(int j=0;j<5;j++){
				if(a[i].getDiem(j) < 5){
					cout << " Mon " << j + 1 << " Diem : " << a[i].getDiem(j); 
				}
			}
			cout << endl;
		}
	}
	if(check) cout << "Khong co sinh vien thi lai !\n";
}


void totnghiepne(SinhVien a[],int n){
	cout << "Danh sach sinh vien phai tot nghiep : \n";
	bool check = true;
	for(int i=0;i<n;i++){
			if(a[i].totnghiep()){
				a[i].in();
				check = false;
			}
		
	}
	if(check) cout << "Khong co sinh vien tot nghiep !\n";
}


void doanne(SinhVien a[],int n){
	cout << "Danh sach sinh vien lam do an : \n";
	bool check = true;
	for(int i=0;i<n;i++){
			if(a[i].doan()){
				a[i].in();
				check = false;
			}
		
	}
	if(check) cout << "Khong co sinh vien lam do an !\n";
}

void quydoi(SinhVien a[],int n){
	for(int i=0;i<n;i++){
		cout << a[i].getHoTen() << " Gpa : " << fixed << setprecision(2) << a[i].gpa() << endl;
	}
}


int main(){
	int n; cout << "Nhap so luong sinh vien : "; cin >> n;cin.ignore();
	SinhVien a[n];
	for(int i=0;i<n;i++){
		cout << "Sinh vien thu " << i + 1 << ":\n";
		a[i].nhap();
	}
	inSinhVien(a,n);
	cout << endl;
	thilai(a,n);
	totnghiepne(a,n);
	doanne(a,n);
	quydoi(a,n);
}


















