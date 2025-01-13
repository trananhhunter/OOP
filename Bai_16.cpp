#include <bits/stdc++.h>
using namespace std;

class CanBo{
	private:
		string maCB,maDV,hoTen;
		int namSinh;
	public:
		CanBo(){
		}
		void nhap(){
			cout << "Ma can bo : "; cin >> maCB;
			cout << "Ma don vi : "; cin >> maDV;
			cin.ignore();
			cout << "Ho ten : "; getline(cin,hoTen);
			cout << "Nam sinh : "; cin >> namSinh;
		}
		string getMacb(){
			return maCB;
		}
		string getMadv(){
			return maDV;
		}
		string getHoTen(){
			return hoTen;
		}
		int getNamSinh(){
			return namSinh;
		}
};

class Luong : public CanBo{
	private:
		double phuCap,heSoLuong,baoHiem;
	public:
		Luong() : CanBo(){
		}
		void nhap(){
			CanBo::nhap();
			cout << "Phu cap : "; cin >> phuCap;
			cout << "He so luong : "; cin >> heSoLuong;
			cout << "Bao hiem : "; cin >> baoHiem;
		}
		double luong(){
			return (double)heSoLuong* 290.000 + phuCap - baoHiem;
		}
		void in(){
			cout << "|" << setw(10) << setfill(' ') << left << getMacb();
			cout << "|" << setw(10) << setfill(' ') << left << getMadv();
			cout << "|" << setw(30) << setfill(' ') << left << getHoTen();
			cout << "|" << setw(10) << setfill(' ') << left << getNamSinh();
			cout << "|" << setw(10) << setfill(' ') <<left << fixed << setprecision(3)<< phuCap;
			cout << "|" << setw(15) << setfill(' ') << left << heSoLuong;
			cout << "|" << setw(10) << setfill(' ') << left<< fixed << setprecision(3)<< baoHiem;
			cout << "|" << setw(15) << setfill(' ') << left << fixed << setprecision(3)<< luong() << "|" << endl;
		}
};

void inLuong(vector<Luong> &a){
	cout << "Danh sach luong can bo : \n";
	cout << "|" << setw(10) << setfill(' ') << left << "Ma can bo";
			cout << "|" << setw(10) << setfill(' ') << left << "Ma don vi";
			cout << "|" << setw(30) << setfill(' ') << left << "Ho ten";
			cout << "|" << setw(10) << setfill(' ') << left << "Nam sinh";
			cout << "|" << setw(10) << setfill(' ') <<left << "Phu cap";
			cout << "|" << setw(15) << setfill(' ') << left << "He so luong";
			cout << "|" << setw(10) << setfill(' ') << left<<"Bao hiem";
			cout << "|" << setw(15) << setfill(' ') << left << "Luong" << "|" << endl;
	for(int i=0;i<a.size();i++){
		a[i].in();
	}
}

void nhapLuong(vector<Luong>& a,int n){
	for(int i=0;i<n;i++){
		cout << "Can bo " << i +1<< ":\n";
		Luong ok; ok.nhap();
		a.push_back(ok);
	}
}

int main(){
	vector<Luong> a;
	int n; cout << "So luong can bo : "; cin >> n;
	nhapLuong(a,n);
	inLuong(a);
	
}

























