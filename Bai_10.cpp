#include <bits/stdc++.h>
using namespace std;

class Tamgiac{
	private:
		double c1,c2,c3;
	public:
		Tamgiac(){
		}
		void nhap(){
			do{
				cout << "Canh 1: "; cin >> c1;
				cout << "Canh 2: "; cin >> c2;
				cout << "Canh 3: "; cin >> c3;
				 if (c1 <= 0 || c2 <= 0 || c3 <= 0) {
			            cout << "Canh tam giac phai lon hon 0. Vui long nhap lai\n";
			        } else if (c1 + c2 <= c3 || c1 + c3 <= c2 || c2 + c3 <= c1) {
			            cout << "Tong 2 canh phai lon hon canh con lai. Vui long nhap lai.\n";
			        }
			} while(c1 <= 0 || c2 <= 0 || c3 <= 0 || (c1 + c2 <= c3 || c1 + c3 <= c2 || c2 + c3 <= c1));
		}
		double chuVi(){
			return c1+c2+c3;
		}
		double dienTich(){
			double p = (c1+c2+c3)/2;
			return sqrt(p*(p-c1)*(p-c2)*(p-c3));
		}
		void in(){
			cout << "|" << setw(8) << setfill(' ') << left << c1;
			cout << "|" << setw(8) << setfill(' ') << left << c2;
			cout << "|" << setw(8) << setfill(' ') << left << c3;
			cout << "|" << setw(8) << setfill(' ') << left << chuVi();
			cout << "|" << setw(8) << setfill(' ') << left << dienTich() << "|\n";
		}
};

void nhapTamGiac(vector<Tamgiac> &v,int n){
	for(int i=0;i<n;i++){
		cout << "Tam giac " << i +1 << ":\n";
		Tamgiac a;
		a.nhap();
		v.push_back(a);
	}
}

void inTamGiac(vector<Tamgiac> &v){
	cout << "Danh sach tam giac la :\n";
	cout << "|" << setw(5) << setfill(' ') << left << "STT";
	cout << "|" << setw(8) << setfill(' ') << left << "Canh 1";
			cout << "|" << setw(8) << setfill(' ') << left << "Canh 2";
			cout << "|" << setw(8) << setfill(' ') << left << "Canh 3";
			cout << "|" << setw(8) << setfill(' ') << left << "Chu vi";
			cout << "|" << setw(8) << setfill(' ') << left << "Dien tich" << "|\n";
	for(int i=0;i<v.size();i++){
		cout << "|" << setw(5) << setfill(' ') << left << i+1;
		v[i].in();
	}		
}

bool cmp(Tamgiac a,Tamgiac b){
	return a.dienTich() < b.dienTich();
}

void sx(vector<Tamgiac> &v){
	sort(v.begin(),v.end(),cmp);
	inTamGiac(v);
}

int main(){
	int n; cout << "Nhap so tam giac : "; cin >> n;
	vector<Tamgiac> v;
	nhapTamGiac(v,n);
	inTamGiac(v);
	cout << endl;
	sx(v);
}























