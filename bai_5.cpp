#include <bits/stdc++.h>
using namespace std;

class date{
	private:
		int ngay,thang,nam;
	public:
		date(){
			ngay = thang = nam =0;
		}
		friend ostream& operator << (ostream& os,date a);
		friend istream& operator >> (istream& is,date& a);
		date operator ++(int);
		date operator --(int);
		int getD(){
			return ngay;
		}
		int getM(){
			return thang;
		}
		int getY(){
			return nam;
		}
};

ostream& operator << (ostream& os,date a){
	os << setfill('0') << setw(2) << a.ngay << "/"<<setfill('0') << setw(2) << a.thang << "/"  << setw(4) << setfill('0')<< a.nam << endl;
	return os;
}

istream& operator >> (istream& is,date& a){
	do{
		is >> a.ngay >> a.thang >> a.nam;
	} while((a.ngay < 0 || a.ngay > 32) || (a.thang < 0 || a.thang > 12));
	
	return is;
}

date date::operator ++(int){
	ngay += 1;
	if(thang == 4 || thang ==6 || thang ==9 || thang ==11){
		if(ngay == 31){
			ngay = 1;
			thang +=1;
		}
	}
	else if(thang == 1 || thang ==3 || thang ==5 || thang ==7||thang == 8||thang == 10||thang == 12){
		if(ngay == 32 && thang != 12){
			ngay = 1;
			thang +=1;
		}
		else if(ngay == 32 && thang == 12){
		ngay = 1;
		thang = 1;
		nam +=1;
	}
	}
	else if(thang == 2){
		if(nam % 4 ==0 && nam % 100 !=0){
			if(ngay = 30){
				ngay = 1;
				thang +=1;
			}
		}
		else{
			if(ngay == 29){
				ngay = 1;
				thang +=1;
			}
		}
	}
	return *this;
}

date date::operator --(int){
	ngay -=1;
	if(thang == 4 || thang ==6 || thang ==9 || thang ==11){
		if(ngay < 1){
			ngay = 31;
			thang -=1;
		}
	}
	else if(thang == 1 || thang ==3 || thang ==5 || thang ==7||thang == 8||thang == 10||thang == 12){
		if(ngay < 1){
			if(thang == 1){
				ngay = 31;
				thang = 12;
				nam -=1;
			}
			else if(thang == 3){
				if(nam % 4 ==0 && nam % 100 !=0){
					ngay = 29;
					thang -=1;
				}
			else{
					ngay = 28;
					thang-=1;
			}
		}
	}
	else{
		// thang 2
			if(ngay < 1){
				ngay = 31;
				thang -=1;
			}
	}
}
	return *this;
}

int main(){
	date a;
	cin >> a;
	cout << a--;
	return 0;
}
















