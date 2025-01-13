#include <bits/stdc++.h>
using namespace std;

class Time {
private:
    int h, m, s;

public:
    // Hàm t?o không d?i
    Time() {
        h = m = s = 0;
    }

    // Hàm t?o có d?i
    Time(int n, int m, int l) {
        this->h = n;
        this->m = m;
        this->s = l;
    }

    // Hàm nh?p
    void nhap() {
        do {
            cout << "Gio : ";
            cin >> h;
            if (h >= 24 || h < 0)
                cout << "Vui long nhap dung! 0 <= h < 24 \n";
        } while (h >= 24 || h < 0);

        do {
            cout << "Phut : ";
            cin >> m;
            if (m >= 60 || m < 0)
                cout << "Vui long nhap dung! 0 <= m < 60 \n";
        } while (m >= 60 || m < 0);

        do {
            cout << "Giay : ";
            cin >> s;
            if (s >= 60 || s < 0)
                cout << "Vui long nhap dung! 0 <= s < 60 \n";
        } while (s >= 60 || s < 0);
    }

    // Hàm in
    void in() {
        cout << setw(2) << setfill('0') << h << ":"
             << setw(2) << setfill('0') << m << ":"
             << setw(2) << setfill('0') << s << endl;
    }

    // Toán t? tang ti?n t?
    Time operator++() {
        s += 1;
        if (s == 60) { // Khi giây vu?t quá 59
            s = 0;
            m += 1;
            if (m == 60) { // Khi phút vu?t quá 59
                m = 0;
                h += 1;
                if (h == 24) { // Khi gi? vu?t quá 23
                    h = 0;
                }
            }
        }
        return *this;
    }

    // Toán t? tang h?u t?
    Time operator++(int) {
        Time temp = *this;
        ++(*this); // G?i l?i toán t? ti?n t?
        return temp;
    }

	Time operator --(int){
		s -=1;
		if(s == -1){
			s = 59;
			m -= 1;
			if(m = -1){
				m = 59;
				h -=1;
				if(h == -1){
					h = 23;
				}
			}
		}
		return *this;
	}
    // Getter
    int getH() { return h; }
    int getM() { return m; }
    int getS() { return s; }
};

int main() {
    Time a;
    a.nhap();
    a--; // Tang 1 giây (h?u t?)
    a.in(); // In ra th?i gian sau khi tang
    
    return 0;
}

