#include <bits/stdc++.h>
using namespace std;

class NhanVien{
	private:
		string hoTen,chucVu,gioiTinh,diaChi;
		int namSinh,namVaoLam;
	public:
		NhanVien(){
		}
		int tuoi(){
			return 2025 - namSinh;
		}
		int namLamViec(){
			return 2025 - namVaoLam;
		}
		friend istream& operator >> (istream& is,NhanVien& a);
		friend ostream& operator << (ostream& os,NhanVien a);
		string getGioiTinh(){
			return gioiTinh;
		}
};

istream& operator >> (istream& is,NhanVien& a){
	cout << "Ho ten : "; getline(is,a.hoTen);
	cout << "Chuc Vu : "; getline(is,a.chucVu);
	cout << "Gioi Tinh : \n"; 
	while(true){
		cout << "1. Nam \n";
		cout << "2. Nu \n";
		cout << "3. Khac \n";
		int lc; cout << "Lua chon : "; is >> lc;
		if(lc == 1){
			a.gioiTinh = "Nam";
			break;
		}
		else if(lc == 2){
			a.gioiTinh = "Nu";
			break;
		}
		else if(lc == 3){
			a.gioiTinh = "Khac";
			break;
		}
		else cout << "Lua chon khong hop le !!!\n";
	}
	is.ignore();
	cout << "Dia Chi : "; getline(is,a.diaChi);
	cout << "Nam Sinh : "; is >> a.namSinh;
	cout << "Nam Vao Lam : "; is >> a.namVaoLam; is.ignore();
	return is;
}

ostream& operator << (ostream& os,NhanVien a){
	os << "|" << setw(25) << setfill(' ') << left << a.hoTen;
	os << "|" << setw(15) << setfill(' ') << left << a.chucVu;
	os << "|" << setw(10) << setfill(' ') << left << a.gioiTinh;
	os << "|" << setw(25) << setfill(' ') << left << a.diaChi;
	os << "|" << setw(8) << setfill(' ') << left << a.namSinh;
	os << "|" << setw(8) << setfill(' ') << left << a.namVaoLam;
	os << "|" << setw(5) << setfill(' ') << left << a.tuoi() << "|" << endl;
	return os;
}

void nhapNhanVien(NhanVien a[],int n){
	for(int i=0;i<n;i++){
		cout << "Nhan vien " << i + 1 << ":\n";
		cin >> a[i];
	}
}

void inNhanVien(NhanVien a[],int n){
	cout << setw(105) << setfill('-') << "-" << endl;
	cout << "|" << setw(25) << setfill(' ') << left << "Ho Ten";
	cout << "|" << setw(15) << setfill(' ') << left << "Chuc Vu";
	cout << "|" << setw(10) << setfill(' ') << left << "Gioi Tinh";
	cout << "|" << setw(25) << setfill(' ') << left << "Dia Chi";
	cout << "|" << setw(8) << setfill(' ') << left << "Nam Sinh";
	cout << "|" << setw(10) << setfill(' ') << left << "Nam Vao Lam";
	cout << "|" << setw(5) << setfill(' ') << left << "Tuoi" << "|" << endl;
	cout << setw(105) << setfill('-') << "-" << endl;
	for(int i =0;i<n;i++){
		cout << a[i];
	}
	cout << setw(105) << setfill('-') << "-" << endl;
}



void veHuu(NhanVien a[],int n){
	cout << "Danh sach nhan vien ve huu :\n";
	cout << setw(105) << setfill('-') << "-" << endl;
	cout << "|" << setw(25) << setfill(' ') << left << "Ho Ten";
	cout << "|" << setw(15) << setfill(' ') << left << "Chuc Vu";
	cout << "|" << setw(10) << setfill(' ') << left << "Gioi Tinh";
	cout << "|" << setw(25) << setfill(' ') << left << "Dia Chi";
	cout << "|" << setw(8) << setfill(' ') << left << "Nam Sinh";
	cout << "|" << setw(10) << setfill(' ') << left << "Nam Vao Lam";
	cout << "|" << setw(5) << setfill(' ') << left << "Tuoi" << "|" << endl;
	cout << setw(105) << setfill('-') << "-" << endl;
	int check1 = 1;
	for(int i =0;i<n;i++){
		if((a[i].getGioiTinh() == "Nam" && a[i].tuoi() >= 60)||(a[i].getGioiTinh() == "Nu" && a[i].tuoi() >= 55)){
			cout << a[i];
			check1 = 0;
		}
	}
	cout << setw(105) << setfill('-') << "-" << endl;
	if(check1 == 1) cout << "Khong co nhan vien nao ve huu !!!\n";
}


void lamTren20Nam(NhanVien a[],int n){
	cout << "Danh sach nhan vien lam tren 20 nam :\n";
	cout << setw(105) << setfill('-') << "-" << endl;
	cout << "|" << setw(25) << setfill(' ') << left << "Ho Ten";
	cout << "|" << setw(15) << setfill(' ') << left << "Chuc Vu";
	cout << "|" << setw(10) << setfill(' ') << left << "Gioi Tinh";
	cout << "|" << setw(25) << setfill(' ') << left << "Dia Chi";
	cout << "|" << setw(8) << setfill(' ') << left << "Nam Sinh";
	cout << "|" << setw(10) << setfill(' ') << left << "Nam Vao Lam";
	cout << "|" << setw(5) << setfill(' ') << left << "Tuoi" << "|" << endl;
	cout << setw(105) << setfill('-') << "-" << endl;
	int check3 = 1;
	for(int i =0;i<n;i++){
		if(a[i].namLamViec() >= 20){
			cout << a[i];
			check3 = 0;
		}
	}
	cout << setw(105) << setfill('-') << "-" << endl;
	if(check3 == 1) cout << "Khong co nhan vien nao ve huu !!!\n";
}

int main(){
	int n; cout << "So luong nhan vien : "; cin >> n; cin.ignore();
	NhanVien a[n];
	nhapNhanVien(a,n);
	inNhanVien(a,n);
	veHuu(a,n);
	lamTren20Nam(a,n);
}














