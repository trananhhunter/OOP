#include <bits/stdc++.h>
using namespace std;

class NhanSu{
	private:
		string maNV,hoTen;
		int namSinh;
	public:
		NhanSu(){
		}
		void nhap(){
			cout << "Ma nhan vien : "; getline(cin,maNV);
			cout << "Ho ten : "; getline(cin,hoTen);
			cout << "Nam sinh : "; cin >> namSinh;
		}
		string getMa(){
			return maNV;
		}
		string getHoTen(){return hoTen;
		}
		int getNamSinh() {return namSinh;
		}
};

class CanBo : public NhanSu{
	private:
		double luongCB,heSoLuong;
	public:
		CanBo() : NhanSu(){
		}	
		void nhap(){
			NhanSu::nhap();
			cout << "Luong co ban : "; cin >> luongCB;
			cout << "He so luong : "; cin >> heSoLuong; cin.ignore();
		}
		double tienluong(){
			return luongCB*heSoLuong;
		}
		void in(){
			cout << "|" << setw(15) << setfill(' ') << left << getMa();
			cout << "|" << setw(30) << setfill(' ') << left << getHoTen();
			cout << "|" << setw(10) << setfill(' ') << left << getNamSinh();
			cout << "|" << setw(15) << setfill(' ') << left << luongCB;
			cout << "|" << setw(15) << setfill(' ') << left << heSoLuong;
			cout << "|" << setw(30) << setfill(' ') << left << tienluong() << "|" << endl;
		}
};

void nhapCanBo(CanBo a[],int n){
	for(int i=0;i<n;i++){
		cout << "Can bo " << i + 1 << ":\n";
		a[i].nhap();
	}
}

void inCanBo(CanBo a[],int n){
	cout << "Danh sach can bo : \n";
	cout << setw(122) << setfill('-') << "-"<< endl;
	cout << "|" << setw(15) << setfill(' ') << left << "Ma Nhan Vien";
			cout << "|" << setw(30) << setfill(' ') << left << "Ho Ten";
			cout << "|" << setw(10) << setfill(' ') << left << "Nam Sinh";
			cout << "|" << setw(15) << setfill(' ') << left << "Luong Co Ban";
			cout << "|" << setw(15) << setfill(' ') << left << "He So Luong";
			cout << "|" << setw(30) << setfill(' ') << left << "Tien Luong" << "|" << endl;
	cout << setw(122) << setfill('-') << "-"<< endl;
	for(int i=0;i<n;i++){
		a[i].in();
	}
	cout << setw(122) << setfill('-') << "-"<< endl;
}

bool cmp(CanBo a,CanBo b){
	if(a.tienluong() != b.tienluong()) return a.tienluong() > b.tienluong();
	else return a.getHoTen() > b.getHoTen();
}

void sapxep(CanBo a[],int n){
	cout << "Danh sach can bo theo tien luong giam dan :\n";
	sort(a,a+n,cmp);
	inCanBo(a,n);
}



class CongNhan : public NhanSu{
	private:
		int ngayCong;
	public:
		CongNhan() : NhanSu(){
		}
		void nhap(){
			NhanSu::nhap();
			cout << "Ngay cong : "; cin >> ngayCong; cin.ignore();
		}
		double thuong(){
			return (double)ngayCong*100.000;
		}
		void in(){
			cout << "|" << setw(15) << setfill(' ') << left << getMa();
			cout << "|" << setw(30) << setfill(' ') << left << getHoTen();
			cout << "|" << setw(10) << setfill(' ') << left << getNamSinh();
			cout << "|" << setw(15) << setfill(' ') << left << ngayCong;
			cout << "|" << setw(30) << setfill(' ') << left << thuong() << "|" << endl;
		}
		int getNgayCong() {return ngayCong;
		}
		
};

void nhapCongNhan(CongNhan a[],int n){
	for(int i=0;i<n;i++){
		cout << "Cong nhan " << i + 1 << ":\n";
		a[i].nhap();
	}
}

void inCongNhan(CongNhan a[],int n){
	cout << "Danh sach cong nhan :\n";
		cout << setw(106) << setfill('-') << "-"<< endl;
	cout << "|" << setw(15) << setfill(' ') << left << "Ma Nhan Vien";
			cout << "|" << setw(30) << setfill(' ') << left << "Ho Ten";
			cout << "|" << setw(10) << setfill(' ') << left << "Nam Sinh";
			cout << "|" << setw(15) << setfill(' ') << left << "Ngay Cong";
			cout << "|" << setw(30) << setfill(' ') << left << "Thuong" << "|" << endl;
	cout << setw(106) << setfill('-') << "-"<< endl;
	for(int i =0;i<n;i++){
		a[i].in();
	}		
	cout << setw(106) << setfill('-') << "-"<< endl;
}

void thuongDS(CongNhan a[],int n){
	cout << "Danh sach cong nhan duoc thuong : \n";
	bool check = false;
	for(int i=0;i<n;i++){
		if(a[i].getNgayCong() > 26 ){
			a[i].in();
			check = true;
		}
	}
	if(!check) cout << "Khong co cong nhan nao duoc thuong !!!\n";
}


int main(){
	int n,m;
	CanBo a[100]; 
	CongNhan b[100];
	while(true){
		cout << "--- Menu ---\n";
		cout << "1. Can Bo\n";
		cout << "2. Cong Nhan\n";
		cout << "3. Thoat\n";
		int lc; cout << "Lua chon : "; cin >> lc;
		if(lc == 3){
			break;
		}else if(lc == 1){
			cout << "So luong can bo : "; cin >> n; cin.ignore();
			nhapCanBo(a,n);
			inCanBo(a,n);
			sapxep(a,n);
		}
		else if(lc == 2){
			cout << "So luong cong nhan : "; cin >> m; cin.ignore();
			nhapCongNhan(b,m);
			inCongNhan(b,m);
			thuongDS(b,m);
		}
		else cout << "Lua chon khong hop le !\n";
	}
	return 0;
}













