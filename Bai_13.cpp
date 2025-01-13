#include <bits/stdc++.h>
using namespace std;

class MonHoc{
	private:
		string tenMonHoc;
		double diemChuyenCan,diemKiemTra,diemThi;
	public:
		MonHoc(){
		}	
		string getTenMon(){
			return tenMonHoc;
		}
		double getDiemChuyenCan(){
			return diemChuyenCan;
		}
		double getDiemKiemTra(){
			return diemKiemTra;
		}
		double getDiemThi(){
			return diemThi;
		}
		void nhap(){
			cout << "Ten mon hoc : "; getline(cin,tenMonHoc);
			cout << "Diem chuyen can : "; cin >> diemChuyenCan;
			cout << "Diem kiem tra : "; cin >> diemKiemTra;
			cout << "Diem thi : "; cin >> diemThi; cin.ignore();
		}
		
};

class SinhVien : public MonHoc{
	private:
		string hoTen,maSinhVien;
	public:
		SinhVien() : MonHoc(){
		}
		double diemHocPhan(){
			return getDiemChuyenCan()*0.1 + getDiemKiemTra()*0.3 + getDiemThi()*0.6;
		}
		void nhap(){
			cout << "Ho ten : "; getline(cin,hoTen);
			cout << "Ma sinh vien : "; cin >> maSinhVien; cin.ignore();
			MonHoc::nhap();
		}
		void in(){
			cout << "|" << setw(30) << setfill(' ') << left << hoTen;
			cout << "|" << setw(15) << setfill(' ') << left << maSinhVien;
			cout << "|" << setw(30) << setfill(' ') << left << getTenMon();
			cout << "|" << setw(20) << setfill(' ') << left << fixed << setprecision(2) <<getDiemChuyenCan();
			cout << "|" << setw(20) << setfill(' ') << left <<fixed << setprecision(2) << getDiemKiemTra();
			cout << "|" << setw(20) << setfill(' ') << left << fixed << setprecision(2) << getDiemThi() ;
			cout << "|" << setw(20) << setfill(' ') << left << fixed << setprecision(2) << diemHocPhan() << "|" << endl;
		}
		
};


void inSinhVien(SinhVien a[],int n){
	cout << "|" << setw(30) << setfill(' ') << left << "Ho Ten";
			cout << "|" << setw(15) << setfill(' ') << left << "Ma Sinh Vien";
			cout << "|" << setw(30) << setfill(' ') << left << "Ten Mon Hoc";
			cout << "|" << setw(20) << setfill(' ') << left << fixed << setprecision(2) <<"Diem Chuyen Can";
			cout << "|" << setw(20) << setfill(' ') << left <<fixed << setprecision(2) << "Diem Kiem Tra";
			cout << "|" << setw(20) << setfill(' ') << left << fixed << setprecision(2) << "Diem Thi" ;
			cout << "|" << setw(20) << setfill(' ') << left << fixed << setprecision(2) << "Diem Hoc Phan" << "|" << endl;
	cout << setw(132) << setfill('-') << "-" << endl;
	for(int i=0;i<n;i++){
		a[i].in();
	}
	cout << setw(132) << setfill('-') << "-" << endl;
}

void nhapSinhVien(SinhVien a[],int n){
	for(int i=0;i<n;i++){
		cout << "Sinh vien thu " << i + 1 << ":\n";
		a[i].nhap();
	}
}


void sinhVienCamThi(SinhVien a[],int n){
	cout << "Danh sach sinh vien cam thi !!!\n";
	cout << "|" << setw(30) << setfill(' ') << left << "Ho Ten";
			cout << "|" << setw(15) << setfill(' ') << left << "Ma Sinh Vien";
			cout << "|" << setw(20) << setfill(' ') << left << fixed << setprecision(2) <<"Diem Chuyen Can";
			cout << "|" << setw(20) << setfill(' ') << left <<fixed << setprecision(2) << "Diem Kiem Tra";
			cout << "|" << setw(20) << setfill(' ') << left << fixed << setprecision(2) << "Diem Thi" ;
			cout << "|" << setw(20) << setfill(' ') << left << fixed << setprecision(2) << "Diem Hoc Phan" << "|" << endl;
	cout << setw(132) << setfill('-') << "-" << endl;
	for(int i=0;i<n;i++){
		if(a[i].getDiemChuyenCan() < 5 && a[i].getDiemKiemTra() == 0){
			a[i].in();
		}
	}
	cout << setw(132) << setfill('-') << "-" << endl;
}


void sinhVienThiLai(SinhVien a[],int n){
	cout << "Danh sach sinh vien thi lai !!!\n";
	cout << "|" << setw(30) << setfill(' ') << left << "Ho Ten";
			cout << "|" << setw(15) << setfill(' ') << left << "Ma Sinh Vien";
			cout << "|" << setw(20) << setfill(' ') << left << fixed << setprecision(2) <<"Diem Chuyen Can";
			cout << "|" << setw(20) << setfill(' ') << left <<fixed << setprecision(2) << "Diem Kiem Tra";
			cout << "|" << setw(20) << setfill(' ') << left << fixed << setprecision(2) << "Diem Thi" ;
			cout << "|" << setw(20) << setfill(' ') << left << fixed << setprecision(2) << "Diem Hoc Phan" << "|" << endl;
	cout << setw(132) << setfill('-') << "-" << endl;
	for(int i=0;i<n;i++){
		if(a[i].diemHocPhan() < 4.0){
			a[i].in();
		}
	}
	cout << setw(132) << setfill('-') << "-" << endl;
}


int main(){
	int n; cout << "Nhap so luong sinh vien : "; cin >> n; cin.ignore();
	SinhVien a[n];
	nhapSinhVien(a,n);
	//inSinhVien(a,n);
	sinhVienCamThi(a,n);
	//sinhVienThiLai(a,n);
	
}















