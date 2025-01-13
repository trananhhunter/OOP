#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
	if(b == 0) return a;
	return gcd(b,a%b);
}

class Ps{
	private:
		int tu,mau;
	public:
		Ps(){
		}
		Ps(int n,int m){
			tu = n;
			mau = m;
		}
		int getTu(){
			return tu;
		}
		int getMau(){
			return mau;
		}
		void setTu(int n){
			tu = n;
		}
		void setMau(int m){
			mau = m;
		}
		void nhap(){
			cout << "Nhap tu so : "; cin >> tu;
			cout << "Nhap mau so : "; cin >> mau;
		}
		void rutgon(){
			int mc = gcd(tu,mau);
			tu /= mc;
			mau /=mc;
		}
		void in(){
			rutgon();
			if(mau == 1|| mau == 0){
				cout << tu;
			}
			else if(tu == 0) cout << tu;
			else cout << tu << "/" << mau;
		}
		Ps operator +(Ps a){
			Ps ok;
			ok.tu= tu*a.mau+ a.tu*mau;
			ok.mau = mau*a.mau;
			return ok;
		}
		Ps operator -(Ps a){
			Ps ok;
			ok.tu = tu*a.mau- a.tu*mau;
			ok.mau = mau*a.mau;
			return ok;
		}
		Ps operator *(Ps a){
			Ps ok;
			ok.tu = tu*a.tu;
			ok.mau = mau*a.mau;
			return ok;
		}
};

class Ps2 :public Ps{
	public:
		Ps2():Ps(){
		}
		Ps2 operator =(Ps2 a){
			this->setTu(a.getTu());
			this->setMau(a.getMau());
			return *this;
		}
		friend bool operator >(Ps2 a,Ps2 b){
			return a.getTu()*b.getMau() > b.getTu()*a.getMau();
		}
		friend bool operator <(Ps2 a,Ps2 b){
			return a.getTu()*b.getMau() < b.getTu()*a.getMau();
		}
};


void sapxep(Ps2 a[],int n){
	 for (int i = 0; i < n - 1; i++) {
        for(int j = i+1;j<n;j++){
        	if(a[i] > a[j]) swap(a[i],a[j]);
		}
        
    }
	for(int i=0;i<n-1;i++){
		a[i].in(); cout << ",";
	}
	a[n-1].in();
}

void minMax(Ps2 a[],int n){
	Ps2 min1 = a[0],max1 = a[0];
	for(int i=1;i<n;i++){
		if(min1 > a[i]) min1 = a[i];
		if(max1 < a[i]) max1 = a[i];
	}
	min1.in();cout << endl;
	 max1.in();
}

int main(){
//	Ps a,b,c,d,e;
//	a.nhap(); b.nhap();
//	 c = a+b; d = a- b; e = a*b;
//	c.in(); d.in(); e.in();
	int n; cin >> n;
	Ps2 a[100];
	for(int i=0;i<n;i++){
		a[i].nhap();
	}
	sapxep(a,n);
	cout << endl;
	minMax(a,n);
	
}























