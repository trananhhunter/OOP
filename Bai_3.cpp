#include <bits/stdc++.h>
using namespace std;

class Dathuc{
	private:
		int bac;
		int a[100];
	public:
		Dathuc(){
			
		}
		int getBac(){
			return bac;
		}
		int getA(int i){
			return a[i];
		}
		void nhap(){
			cout << "Nhap bac cua da thuc : "; cin >> bac;
			for(int i=bac;i>=0;i--){
				cout << "a[" << i << "]= ";
				cin >> a[i];
			}
		}
		void in(){
			for(int i=bac;i>0;i--){
				if(a[i] != 0){
					if(a[i] > 0 && i != bac) {
						cout << "+";
					}
					cout << a[i] << "x^" << i;
				}
			}
			if(a[0] != 0){
				if(a[0] > 0) {
						cout << "+";
					}
					cout << a[0];
			}
			
		}
		Dathuc operator +(Dathuc x){
			Dathuc sum;
			if(this->bac > x.bac){
				sum.bac = this->bac;
				for(int i=0;i<=x.bac;i++){
					sum.a[i] = a[i] + x.a[i];
				}
				for(int i =this->bac ; i > x.bac;i-- ){
					sum.a[i] = a[i];
				}
			}
			else{
				sum.bac = x.bac;
				for(int i=0;i<=this->bac;i++){
					sum.a[i] = a[i] + x.a[i];
				}
				for(int i =x.bac ; i >this->bac;i-- ){
					sum.a[i] = x.a[i];
				}
			}
			return sum;
		}
			Dathuc operator -(Dathuc x){
			Dathuc sum;
			if(this->bac > x.bac){
				sum.bac = this->bac;
				for(int i=0;i<=x.bac;i++){
					sum.a[i] = a[i] - x.a[i];
				}
				for(int i =this->bac ; i > x.bac;i-- ){
					sum.a[i] = a[i];
				}
			}
			else{
				sum.bac = x.bac;
				for(int i=0;i<=this->bac;i++){
					sum.a[i] = a[i] - x.a[i];
				}
				for(int i =x.bac ; i >this->bac;i-- ){
					sum.a[i] = x.a[i];
				}
			}
			return sum;
		}
		
};

int main(){
	Dathuc a,b,c,d;
	a.nhap(); b.nhap(); 
	a.in(); cout << endl;
	b.in(); cout << endl;
	c = a+ b; c.in(); cout << endl;
	d = a-b; d.in();
}


















