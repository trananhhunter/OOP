#include <bits/stdc++.h>
using namespace std;


class Nguoi{
	protected:
		string hoten;
		int namsinh;
	public:
		Nguoi(){
		}
		string getHoten(){
			return hoten;
		}
};

class SinhVien: public Nguoi{
	private:
		string masv;
		double diemtb;
	public:
		SinhVien() : Nguoi(){
		}
		void nhap(){
			cout << "Ma sinh vien : "; cin >> masv; cin.ignore();
			cout << "Ho ten : "; getline(cin,hoten);
			cout << "Nam sinh : "; cin >> namsinh;
			cout << "Diem trung binh : "; cin >> diemtb;
		}
		void in(){
			cout << "| " << setw(15) << setfill(' ') << left << masv
			     << "| " << setw(30) << setfill(' ') << left << hoten
			     << "| " << setw(9) << setfill(' ') << left << namsinh
			     << "| " << setw(18) << setfill(' ') << left << diemtb
			     << " |" << endl;

		}
		double getDtb(){
			return diemtb;
		}
		string getMa(){
			return masv;
		}
};

void nhapSinhVien(SinhVien a[],int n){
	for(int i=0;i<n;i++){
		cout << "Sinh vien thu " << i + 1 << ":\n";
		a[i].nhap();
	}
}
void inSinhVien(SinhVien a[],int n){
			cout << "| " << setw(15) << setfill(' ') << left << "Ma sinh vien"
				     << "| " << setw(30) << setfill(' ') << left << "Ho ten"
				     << "| " << setw(9) << setfill(' ') << left << "Nam sinh"
				     << "| " << setw(18) << setfill(' ') << left << "Diem trung binh"
				     << " |" << endl;
	for(int i=0;i<n;i++){
		a[i].in();
	}
}

bool cmp(SinhVien a,SinhVien b){
	if(a.getDtb() != b.getDtb()) return a.getDtb() > b.getDtb();
	else a.getHoten() > b.getHoten();
}

bool cmp2(SinhVien a,SinhVien b){
	if(a.getDtb() != b.getDtb()) return a.getDtb() < b.getDtb();
	else a.getHoten() > b.getHoten();
}


void sapxep(SinhVien a[],int n){
	cout << "Diem trung binh giam dan :\n";
	cout << "| " << setw(15) << setfill(' ') << left << "Ma sinh vien"
				     << "| " << setw(30) << setfill(' ') << left << "Ho ten"
				     << "| " << setw(9) << setfill(' ') << left << "Nam sinh"
				     << "| " << setw(18) << setfill(' ') << left << "Diem trung binh"
				     << " |" << endl;	sort(a,a+n,cmp);
	for(int i=0;i<n;i++){
		a[i].in();
	}
	cout << "Diem trung binh tang dan :\n";
	cout << "| " << setw(15) << setfill(' ') << left << "Ma sinh vien"
				     << "| " << setw(30) << setfill(' ') << left << "Ho ten"
				     << "| " << setw(9) << setfill(' ') << left << "Nam sinh"
				     << "| " << setw(18) << setfill(' ') << left << "Diem trung binh"
				     << " |" << endl;	sort(a,a+n,cmp2);
	for(int i=0;i<n;i++){
		a[i].in();
	}
}

void Timkiem(SinhVien a[],int n){
	string find;
	cin.ignore();
	cout << "Nhap ma sinh vien can tim : "; getline(cin,find);
	bool check = true;
	for(int i=0;i<n;i++){
		if(find == a[i].getMa()){
				cout << "| " << setw(15) << setfill(' ') << left << "Ma sinh vien"
				     << "| " << setw(30) << setfill(' ') << left << "Ho ten"
				     << "| " << setw(9) << setfill(' ') << left << "Nam sinh"
				     << "| " << setw(18) << setfill(' ') << left << "Diem trung binh"
				     << " |" << endl;
			a[i].in();
			check = false;
			break;
		}
	}
	if(check) cout << "Khong ton tai sinh vien co ma sinh vien " << find << endl;
}


class GiangVien : public Nguoi{
	private:
		string bomoncongtac,mondanggiangday;
		int sobaibao;
	public:
		GiangVien(): Nguoi(){
		}
		void nhap(){
			cout << "Ho ten : "; getline(cin,hoten);
			cout << "Nam sinh : "; cin >> namsinh; cin.ignore();
			cout << "Bo mon cong tac : "; getline(cin,bomoncongtac);
			cout << "Mon dang giang day : "; getline(cin,mondanggiangday);
			cout << "So bai bao : "; cin >> sobaibao; cin.ignore();
		}
		void in(){
			cout << "|" << setw(30)<< setfill(' ') << left << hoten;
			cout << "|" << setw(9) << setfill(' ')<< left << namsinh;
			cout << "|" << setw(30) << setfill(' ') << left  << bomoncongtac;
			cout << "|" << setw(30) << setfill(' ') << left  << mondanggiangday ;
			cout << "|" << setw(15) << setfill(' ') << left  << sobaibao << endl;
		}
		int getSobaibao(){
			return sobaibao;
		}
		string getBomon(){
			return bomoncongtac;
		}
		string getDay(){
			return mondanggiangday;
		}
};

void inGiangVien(GiangVien a[],int n){
		cout << "|" << setw(30)<< setfill(' ') << left << "Ho ten";
			cout << "|" << setw(9) << setfill(' ')<< left << "Nam sinh";
			cout << "|" << setw(30) << setfill(' ') << left  << "Bo mon cong tac";
			cout << "|" << setw(30) << setfill(' ') << left  << "Mon dang giang day";
			cout << "|" << setw(15) << setfill(' ') << left  << "So bai bao " << endl;
		for(int i=0;i<n;i++){
			a[i].in();
		}
		
}

bool cmp3(GiangVien a,GiangVien b){
	if(a.getBomon() != b.getBomon()) return a.getBomon() < b.getBomon();
	else a.getDay() > b.getDay();
}

void boMon(GiangVien a[],int n){
	sort(a,a+n,cmp3);
	string bomon = "";
	for(int i=0;i<n;i++){
		if(a[i].getBomon() != bomon){
			bomon = a[i].getBomon();
			cout << "Bo mon " << bomon << " :\n";
		}
		a[i].in();
	}
}

bool cmp4(GiangVien a,GiangVien b){
	if(a.getSobaibao() != b.getSobaibao()) return a.getSobaibao() < b.getSobaibao();
	else a.getHoten() > b.getHoten();
}

void sapxepgiangvien(GiangVien a[],int n){
	sort(a,a+n,cmp4);
	inGiangVien(a,n);
}

int main(){
	int n; cout << "Nhap so luong giang vien : "; cin >> n; cin.ignore();
//	SinhVien a[n];
//	nhapSinhVien(a,n);
//	inSinhVien(a,n);
//	cout << endl;
//	sapxep(a,n);
//	cout << endl;
//	Timkiem(a,n);
	GiangVien a[n];
	for(int i=0;i<n;i++){
		cout << "Giang vien thu " << i + 1 << ":\n";
		a[i].nhap();
	}
	inGiangVien(a,n);
	cout << endl;
	boMon(a,n);
	cout << endl;
	sapxepgiangvien(a,n);
}






















