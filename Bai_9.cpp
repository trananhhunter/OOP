#include <bits/stdc++.h>
using namespace std;

class Diem{
	private:
		int x,y;
	public:
		Diem(){
		}
		int getX(){
			return x;
		}
		int getY(){
			return y;
		}
		void nhap(){
			cout << "x = "; cin >> x;
			cout << "y = "; cin >> y;
		}
		friend ostream& operator << (ostream& os,Diem a){
			os << "(" << a.x << "," << a.y << ")";
			return os;
		}
		double kc( Diem other)  {
	        return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
	    }
		
};

class TamGiac{
	private:
		Diem a,b,c;
		double c1,c2,c3;
	public:
		TamGiac(){
		}
		void nhap1(){
			cout << "Diem a : \n"; a.nhap();
			cout << "Diem b : \n"; b.nhap();
			cout << "Diem c : \n"; c.nhap();
			 c1 = a.kc(b);
		    c2 = a.kc(c);
		    c3 = b.kc(c);
		}
		void in(){
			cout << a << " " << b << " " << c << " " << c1 << " " << c2 << " " << c3 << " " ;
		}
		double getC1(){
			return c1;
		}
		double getC2(){
			return c2;
		}
		double getC3(){
			return c3;
		}
};

void check(TamGiac a){
	if(a.getC1() > 0 && a.getC2() > 0 && a.getC3() > 0 && ((a.getC1() < a.getC2() + a.getC3()) || (a.getC1() + a.getC2() > a.getC3())||(a.getC2() < a.getC1()+a.getC3()))){
		// deu
		if(a.getC1() == a.getC2() && a.getC2() == a.getC3()){
			a.in(); cout << "Tam giac deu \n";
		}
		else if((a.getC1()*a.getC1() + a.getC2()*a.getC2() == a.getC3()*a.getC3())||(a.getC1()*a.getC1() == a.getC2()*a.getC2() + a.getC3()*a.getC3())||(a.getC1()*a.getC1() + a.getC3()*a.getC3() == a.getC2()*a.getC2()))
		{
			if(a.getC1() == a.getC2() || a.getC1() == a.getC3() || a.getC2() == a.getC3()){
				a.in(); cout << "Tam giac vuong can\n";
			}
			else{
				a.in(); cout << "Tam giac vuong \n";
			}
		}
		else if(a.getC1() == a.getC2() || a.getC1() == a.getC3() || a.getC2() == a.getC3()){
			a.in(); cout << "Tam giac can\n";
		}
		else{
			a.in(); cout << "Tam giac thuong\n";
		}
	}
	else cout << "Khong phai tam giac!\n";
}


int main(){
	TamGiac a;
	a.nhap1();
	check(a);
}






















