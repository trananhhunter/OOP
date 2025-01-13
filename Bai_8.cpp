#include <bits/stdc++.h>
using namespace std;

class Hvuong{
	private:
		double canh;
	public:
		Hvuong(){
		}	
		double getCanh(){
			return canh;
		}
		void setCanh(double n){
			canh = n;
		}
		double chuVi(){
			return canh*4;
		}
		double dienTich(){
			return canh*canh;
		}
		void nhap(){
			do{
				cout << "Do dai canh hinh : "; cin >> canh;
			} while(canh == 0);
		}
		void in(){
			cout << "|" << setw(8) << setfill(' ') << canh;
			cout << "|" << setw(8) << setfill(' ') << chuVi();
			cout << "|" << setw(8) << setfill(' ') << dienTich() << "|\n";
		}
};

void inHinhvuong(Hvuong a[],int n){
	cout << "Danh sach hinh vuong : \n";
	cout << "|" << setw(8) << setfill(' ') << "Vi tri";
	cout << "|" << setw(8) << setfill(' ') << "Do dai";
			cout << "|" << setw(8) << setfill(' ') << "Chu vi";
			cout << "|" << setw(8) << setfill(' ') << "Dien tich "<< "|\n";
	for(int i=0;i<n;i++){
		cout << "|" << setw(8) << setfill(' ') << i+1;
		a[i].in();
	}
}

void nhapHV(Hvuong a[],int n){
	for(int i=0;i<n;i++){
		cout << "Hinh vuong " << i + 1 << ":\n";
		a[i].nhap();
	}
}

class Hcn : public Hvuong{
	private:
		double canh2;
	public:
		Hcn():Hvuong(){
		}
		double getCanh2(){
			return canh2;
		}
		void nhapCN(){
			double n;
			do{
				cout << "Do dai canh 1 : "; cin >> n; setCanh(n);
				cout << "Do dai canh 2 : "; cin >> canh2;
			} while(n == 0 || canh2 == 0);
		}
		double chuViCN(){
			return (getCanh()+canh2)*2;
		}
		double dienTichCN(){
			return getCanh()*canh2;
		}
		void inCN(){
				cout << "|" << setw(8) << setfill(' ') << getCanh();
				cout << "|" << setw(8) << setfill(' ') << canh2;
				cout << "|" << setw(8) << setfill(' ') << chuViCN();
				cout << "|" << setw(8) << setfill(' ') << dienTichCN() << "|\n";
		}
};

void inHCN(Hcn a[],int n){
	cout << "Danh sach hinh chu nhat :\n";
	cout << "|" << setw(8) << setfill(' ') << "Vi tri";
	cout << "|" << setw(8) << setfill(' ') << "Canh 1";
	cout << "|" << setw(8) << setfill(' ') << "Canh 2";
	cout << "|" << setw(8) << setfill(' ') << "Chu vi";
	cout << "|" << setw(8) << setfill(' ') << "Dien tich" << "|\n";
	for(int i=0;i<n;i++){
		cout << "|" << setw(8) << setfill(' ') << i+1;
		a[i].inCN();
	}
}

void nhapHCN(Hcn a[],int n){
	for(int i=0;i<n;i++){
		cout << "Hinh chu nhat " << i +1 << ":\n";
		a[i].nhapCN();
	}
}

void max(Hvuong a[],int n){
	Hvuong max = a[0];
	int idx =0;
	for(int i=1;i<n;i++){
		if(max.dienTich() < a[i].dienTich()){
			max = a[i];
			idx = i+1;
		}
	}
	cout << "Hinh vuong co dien tich lon nhat o vi tri " << idx << " voi dien tich : " << max.dienTich() << endl ;
}

bool cmp(Hcn a,Hcn b){
	return a.chuViCN() > b.chuViCN();
}

void sx(Hcn a[],int n){
	sort(a,a+n,cmp);
	inHCN(a,n);
}


int main(){
	while(1){
		cout << "-- Menu --\n";
		cout << "1. Hinh vuong\n";
		cout << "2. Hinh chu nhat\n";
		cout << "3. Thoat\n";
		int lc; cout << "Lua chon : "; cin >> lc;
		if(lc == 3) break;
		else if(lc == 1){
			int n;Hvuong a[100];
			cout << "Nhap so luong hinh vuong : "; cin >> n;
			nhapHV(a,n);
			inHinhvuong(a,n);
			max(a,n);
		}
		else if(lc == 2){
			int m; 	Hcn b[100];
			cout << "Nhap so luong hinh chu nhat : "; cin >> m;
			nhapHCN(b,m);
			inHCN(b,m);
			sx(b,m);
		}
		else cout << "Lua chon khong hop le !\n";
	}
}




















