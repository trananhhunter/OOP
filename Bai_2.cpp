#include <bits/stdc++.h>
using namespace std;

class SoPhuc{
	private:
		int thuc,ao;
	public:
		SoPhuc(){
		}
		SoPhuc(int n,int m){
			thuc = n;
			ao = m;
		}
		//~SoPhuc();
		friend istream& operator >> (istream& is,SoPhuc& a){
			cout << "Phan thuc : "; is >> a.thuc;
			cout << "Phan ao : "; is >> a.ao;
			return is;
		}
		friend ostream& operator << (ostream& os,SoPhuc a){
			if(a.ao < 0) os << a.thuc << a.ao << "i";
			else os << a.thuc << "+" << a.ao << "i";
			return os; 
		}
		double modul(){
			return (double)(sqrt(pow(thuc,2)+pow(ao,2)));
		}
		SoPhuc operator+( SoPhuc a)  {
		    return SoPhuc(thuc + a.thuc, ao + a.ao);
		}
		
		SoPhuc operator-( SoPhuc a)  {
		    return SoPhuc(thuc - a.thuc, ao - a.ao);
		}
		
		SoPhuc operator*( SoPhuc a)  {
		    int thucMoi = thuc * a.thuc - ao * a.ao;
		    int aoMoi = thuc * a.ao + ao * a.thuc;
		    return SoPhuc(thucMoi, aoMoi);
		}
		
		SoPhuc operator/( SoPhuc& other)  {
		    double mau = other.thuc * other.thuc + other.ao * other.ao; // M?u s?
		    double thucMoi = (thuc * other.thuc + ao * other.ao) / mau; // Ph?n th?c
		    double aoMoi = (ao * other.thuc - thuc * other.ao) / mau;   // Ph?n ?o
		    return SoPhuc((int)thucMoi, (int)aoMoi); // Ép ki?u v? int n?u c?n
		}
		int getThuc(){
			return thuc;
		}
		int getAo(){
			return ao;
		}
		void setThuc(int n){
			thuc = n;
		}
		void setAo(int n){
			ao = n;
		}
};

class SoPhuc1 : public SoPhuc{
	public:
		SoPhuc1() : SoPhuc(){
		}
	SoPhuc1& operator =(SoPhuc1& a) {
        this->setThuc(a.getThuc());
        this->setAo(a.getAo());
        return *this;
    }
		friend bool operator>( SoPhuc1 a, SoPhuc1 b) {
        return a.modul() > b.modul();
    }

    friend bool operator<( SoPhuc1 a,  SoPhuc1 b) {
        return a.modul() < b.modul();
    }

    friend bool operator==( SoPhuc1 a,  SoPhuc1 b) {
        return a.modul() == b.modul();
    }

};

bool cmp1(SoPhuc1 a,SoPhuc1 b){
	return a > b;
}

bool cmp2(SoPhuc1 a,SoPhuc1 b){
	return a < b;
}

void sx(SoPhuc1 a[],int n){
	sort(a,a+n,cmp1);
	for(int i=0;i<n-1;i++) cout << a[i] << ",";
	cout << a[n-1];
	cout << endl;
	sort(a,a+n,cmp2);
	for(int i=0;i<n-1;i++) cout << a[i] << ",";
	cout << a[n-1];
}

void minMax(SoPhuc1 a[],int n){
	SoPhuc1 min = a[0],max=a[0];
	for(int i=1;i<n;i++){
		if(min > a[i]) min = a[i];
		if(max < a[i]) max = a[i];
	}
	cout << "Max : " << max << " Min : " << min << endl;
}

int main(){
//	int n; cin >> n;
//	SoPhuc1 a[n];
//	for(int i=0;i<n;i++) cin >> a[i];
//	for(int i=0;i<n-1;i++) cout << a[i] << ",";
//	cout << a[n-1];
//	cout << endl;
//	sx(a,n);
//	cout << endl;
//	minMax(a,n);
	SoPhuc a,b;
	cin >> a >> b;
	cout << a+b << endl; 
	cout << a-b << endl;
	cout << a*b << endl;
	cout << a/b << endl;
}



















