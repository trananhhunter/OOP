#include <bits/stdc++.h>
using namespace std;

class ThiSinh {
private:
    string mts, hoten;
    double toan, ly, hoa;
public:
    ThiSinh() {}

    ThiSinh(string mts, string hoten, double toan, double ly, double hoa) {
        this->mts = mts;
        this->hoten = hoten;
        this->toan = toan;
        this->ly = ly;
        this->hoa = hoa;
    }

    void nhap() {
        cout << "Ma thi sinh : "; cin >> mts; cin.ignore();
        cout << "Ho ten : "; getline(cin, hoten);
        cout << "Toan : "; cin >> toan;
        cout << "Ly : "; cin >> ly;
        cout << "Hoa : "; cin >> hoa;
    }

    void in() {
        cout << setw(12) << mts
             << setw(50) << hoten
             << setw(6) << toan
             << setw(6) << ly
             << setw(6) << hoa << endl;
    }

    double tong() {
        return toan + ly + hoa;
    }

    double getToan() {
        return toan;
    }

    double getLy() {
        return ly;
    }

    double getHoa() {
        return hoa;
    }
};

void nhapThiSinh(ThiSinh* a, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nhap thi sinh thu " << i + 1 << ":\n";
        a[i].nhap();
    }
}

void inThiSinh(ThiSinh* a, int n) {
    cout << setw(12) << left << "Ma thi sinh"
         << setw(50) << "Ho ten"
         << setw(6) << "Toan"
         << setw(6) << "Ly"
         << setw(6) << "Hoa" << endl;
    for (int i = 0; i < n; i++) {
        a[i].in();
    }
}

void maxDiem(ThiSinh* a, int n) {
    ThiSinh* maxThiSinh = &a[0];
    for (int i = 1; i < n; i++) {
        if (a[i].tong() > maxThiSinh->tong()) {
            maxThiSinh = &a[i];
        }
    }
    cout << "Thi sinh co diem cao nhat la : ";
    maxThiSinh->in();
}

void tongDiem21(ThiSinh* a, int n) {
    cout << "Danh sach thi sinh co tong diem tu 21 va khong mon nao duoi 2\n";
    cout << setw(12) << left << "Ma thi sinh"
         << setw(50) << "Ho ten"
         << setw(6) << "Toan"
         << setw(6) << "Ly"
         << setw(6) << "Hoa" << endl;
    for (int i = 0; i < n; i++) {
        if (a[i].tong() >= 21 && a[i].getToan() >= 2 && a[i].getLy() >= 2 && a[i].getHoa() >= 2) {
            a[i].in();
        }
    }
}

int main() {
    int n;
    cout << "Nhap so luong thi sinh : ";
    cin >> n;

    // CAP PHAT BO NHO DONG
    ThiSinh* a = new ThiSinh[n];

    nhapThiSinh(a, n);
   //  inThiSinh(a, n);
    maxDiem(a, n);
    tongDiem21(a, n);

    // Giai phong bo nho
    delete[] a;

    return 0;
}

