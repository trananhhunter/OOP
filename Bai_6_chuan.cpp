#include <bits/stdc++.h>
using namespace std;

class Matrix{
	private:
		int** a;
		int n,m;
	public:
		Matrix(int n1,int m1): n(n1),m(m1){
			a = new int*[n];
			for(int i=0;i<n;i++){
				a[i] = new int[m]{0};
			}
		}
		int getN(){
			return n;
		}
		void setN(int n1){
			n = n1;
		}
		void setM(int m1){
			m = m1;
		}
		int getM(){
			return m;
		}
		int getA(int i,int j){
			return a[i][j];
		}
		void nhap(){
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					cout << "a[" << i << "][" << j << "]= "; cin >> a[i][j];
				}
			}
		}
		void in(){
			cout << "Ma tran " << n << "x" << m << ":\n";
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					cout << a[i][j] << " ";
				}
				cout << endl;
			}
		}
		Matrix operator +(Matrix& x){
			if(n == x.n && m == x.m){
				Matrix sum(n,m);
				for(int i=0;i<n;i++){
					for(int j=0;j<m;j++){
						sum.a[i][j] = x.a[i][j] + a[i][j];
					}
				}
				return sum;
			}
		}
		Matrix operator -(Matrix& x){
			if(n == x.n && m == x.m){
				Matrix sum(n,m);
				for(int i=0;i<n;i++){
					for(int j=0;j<m;j++){
						sum.a[i][j] =  a[i][j]- x.a[i][j];
					}
				}
				return sum;
			}
		}
};

void tongk(Matrix& x){
	int k; cout << "Nhap k : "; cin >> k;
	int sum1 =0,sum2 =0;
	for(int i=0;i<x.getN();i++){
		sum1 += x.getA(i,k-1);
	}
	for(int i=0;i<x.getM();i++){
		sum2 += x.getA(k-1,i);
	}
	cout << "Tong hang " << k << "= " << sum2 << endl;
	cout << "Tong cot " << k << "= " << sum1 << endl;
}


void tong4vien(Matrix& x){
	int sum =0;
	for(int i=0;i<x.getN();i++){
		for(int j=0;j<x.getM();j++){
			if(i == x.getN() || j == x.getM() || i ==0 || j ==0) sum += x.getA(i,j);
		}
	}
	cout << "Tong 4 vien = " << sum << endl;
}


void maTranVuong(Matrix& x){
	while (x.getN() != x.getM()) {
        cout << "Ma tran khong hop le! Ma tran vuong can co n = m.\n";
        cout << "Vui long nhap lai!\n";
        
        int n1, m1;
        cout << "Nhap nxm: ";
        cin >> n1 >> m1;

        x = Matrix(n1, m1);
        x.nhap();
    }
	x.in();
	int sum1=0,sum2 =0;
	int idx = x.getN();
	for(int i=0;i<idx;i++){
		for(int j=0;j<idx;j++){
			if(i == j) sum1 += x.getA(i,j);
		}
	}
	for(int i=0;i<idx;i++){
		for(int j=0;j<idx;j++){
			if(i+j == idx -1) sum2 += x.getA(i,j);
		}
	}
	cout << "Tong duong cheo chinh = " << sum1 << endl;
	cout << "Tong duong cheo phu = " << sum2 << endl;
}


int main(){
	int n,m; cout << "Nhap kich co ma tran nxm :"; cin >> n >> m;
	Matrix a(n,m),b(n,m);
	a.nhap(); b.nhap();
	a.in(); b.in();
	Matrix c(n,m); c= a+b; c.in();
	Matrix d(n,m); d= a-b; d.in();
	tongk(a);
	tong4vien(a);
	maTranVuong(a);
}
























