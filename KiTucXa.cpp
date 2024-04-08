#include "Phong.h"
#include "SinhVien.h"
#include <iostream>
#include <string>
#include <cstring>
#include <regex> 


using namespace std;

/// <summary>
/// Edit phong
/// </summary>
/// <param name="phong">Phong</param>
void suaphong(Phong& phong);
/// <summary>
/// Find and edit phong
/// </summary>
/// <param name="phong">Array of phong</param>
/// <param name="n">Size of array</param>
void timVaSua(Phong* phong, int& n);
/// <summary>
/// Initialize array of phong
/// </summary>
/// <param name="phong">Array of phong</param>
/// <param name="n">Number of phong to initialize</param>
void taophong(Phong* phong, int& n);
/// <summary>
/// Add phong to most right of array
/// </summary>
/// <param name="phong">Array of phong</param>
/// <param name="n">Size of array</param>
void themphong(Phong* phong, int& n);
/// <summary>
/// Print phong
/// </summary>
/// <param name="phong">Phong</param>
/// <param name="n">Size of array</param>
void xuatphong(Phong* phong, int n);
/// <summary>
/// Add sinh vien to most right of array
/// </summary>
/// <param name="sv"></param>
/// <param name="n"></param>
void themSinhVien(SinhVien* sv, const Phong* phong, const int& n);
/// <summary>
/// Find sinh vien by mssv
/// </summary>
/// <param name="sv"></param>
/// <param name="masv"></param>
/// <param name="m"></param>
/// <returns>SinhVien if found, new SinhVien if not found</returns>
SinhVien timSinhVien(const SinhVien* sv, string masv, const int& m);

int main() {
	// Create dynamic array of Phong[1000]
	Phong* phong = new Phong[1000];
	int n;
	taophong(phong, n);
	int chon;
	do {
		cout << "Ban muon lam gi? \n";
		cout << "1. Tim va sua phong\n";
		cout << "2. Xuat thong tin phong\n";
		cout << "3. Them phong\n";
		cout << "0. Thoat\n";
		cin >> chon;
		if (chon == 1) {
			timVaSua(phong, n);
		}
		else if (chon == 2) {
			xuatphong(phong, n);
		}
		else if (chon == 3) {
			themphong(phong, n);
		}
		else if (chon == 0) {
			break;
		}
		else
			cout << "Nhap sai, vui long nhap lai\n";
	} while (chon != 0);
	cout << "lmao";
	return 0;
}

SinhVien timSinhVien(const SinhVien* sv, string masv, const int& m) {
	for (int i = 0; i < m; i++) {
		if (sv[i].mssv == masv) {
			return sv[i];
		}
	}
	return SinhVien();
}

bool xacminhemail(const string& email) {
	const regex pattern(
		"(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
	return regex_match(email, pattern);
}

bool xacminhtenphong(const string& tenphong, const Phong* phong, const int& n) {
	for (int i = 0; i < n; i++) {
		if (phong[i].tenphong == tenphong) {
			return true;
		}
	}
	return false;
}

void themSinhVien(SinhVien* sv, const Phong* phong, const int& n) {
	string tensv;
	string masv;
	bool gioitinh;
	string quequan;
	string email;
	string tenphong;
	do {
		cout << "Nhap ten sinh vien: ";
		cin >> tensv;
	} while (tensv == "");
	do {
		cout << "Nhap ma sinh vien: ";
		cin >> masv;
	} while (masv == "");
	do {
		cout << "Nhap gioi tinh:(nam, nu) ";
		string gt;
		cin >> gt;
		gioitinh = gt == "nam" ? true : false;
	} while (gioitinh != true && gioitinh != false);
	do {
		cout << "Nhap que quan: ";
		cin >> quequan;
	} while (quequan == "");
	do {
		cout << "Nhap email: ";
		cin >> email;
	} while (!xacminhemail(email));
	do {
		cout << "Nhap ten phong: ";
		cin >> tenphong;
	} while (!xacminhtenphong(tenphong, phong, n));
	sv->themsv(masv, tensv, gioitinh, quequan, email);
	sv->suasv(masv, tensv, gioitinh, quequan, email, tenphong);
	sv->xuatsinhvien();
}

void xuatphong(Phong* phong, int n) {
	for (int i = 0; i < n; i++) {
		phong[i].xuathongtinphong();
	}
}

void themphong(Phong* phong, int& n) {
	string tenphong;
	string loaiphong;
	int songuoitoida;
	int songuoihientai;
	cout << "Nhap ten phong: ";
	cin >> tenphong;
	cout << "Nhap loai phong: ";
	cin >> loaiphong;
	do {
		cout << "Nhap so nguoi toi da: ";
		cin >> songuoitoida;
	} while (songuoitoida < 0);
	do {
		cout << "Nhap so nguoi hien tai: ";
		cin >> songuoihientai;
	} while (songuoihientai < 0 || songuoihientai > songuoitoida);
	for (int i = 0; i <= n; i++) {
		if (phong[i].tenphong == "0") {
			phong[i].themphong(tenphong, loaiphong, songuoitoida);
			phong[i].suaphong(tenphong, loaiphong, songuoitoida, songuoihientai);
			n++;
			cout << "Da them phong thanh cong\n";
			break;
		}
		if (i == n) {
			cout << "Khong the them phong\n";
		}
	}

}

void timVaSua(Phong* phong, int& n) {
	string tenphong;
	cout << "Nhap ten phong can sua: ";
	cin >> tenphong;
	for (int i = 0; i < n; i++) {
		if (phong[i].tenphong == tenphong) {
			suaphong(phong[i]);
		}
	}
}

void taophong(Phong* phong, int& n) {
	int chon;
	do {
		cout << "Ban muon tao bao nhieu phong? ";
		cin >> n;
		if (n < 0) {
			cout << "Nhap sai, vui long nhap lai\n";
		}
	} while (n < 0);
	for (int i = 0; i < n; i++) {
		string tenphong;
		string loaiphong;
		int songuoitoida;
		int songuoihientai;
		cout << "Nhap ten phong: ";
		cin >> tenphong;
		cout << "Nhap loai phong: ";
		cin >> loaiphong;
		do {
			cout << "Nhap so nguoi toi da: ";
			cin >> songuoitoida;
		} while (songuoitoida < 0);
		do {
			cout << "Nhap so nguoi hien tai: ";
			cin >> songuoihientai;
		} while (songuoihientai < 0 || songuoihientai > songuoitoida);
		phong[i].themphong(tenphong, loaiphong, songuoitoida);
		phong[i].suaphong(tenphong, loaiphong, songuoitoida, songuoihientai);
	}
}

void suaphong(Phong& phong) {
	int chon = 10;
	do {
		cout << "Ban muon sua gi? \n";
		cout << "1. Sua ten phong\n";
		cout << "2. Sua loai phong\n";
		cout << "3. Sua so nguoi toi da\n";
		cout << "4. Sua so nguoi hien tai\n";
		cout << "0. Thoat\n";
		cin >> chon;
		if (chon == 1) {
			string tenphong;
			cout << "Nhap ten phong: ";
			cin >> tenphong;
			phong.suaphong(tenphong, phong.loaiphong, phong.songuoitoida, phong.songuoihientai);
			cout << "Da sua ten phong thanh cong\n";
			phong.xuathongtinphong();
		}
		else if (chon == 2) {
			string loaiphong;
			cout << "Nhap loai phong: ";
			cin >> loaiphong;
			phong.suaphong(phong.tenphong, loaiphong, phong.songuoitoida, phong.songuoihientai);
			cout << "Da sua ten phong thanh cong\n";
			phong.xuathongtinphong();
		}
		else if (chon == 3) {
			int songuoitoida;
			do {
				cout << "Nhap so nguoi toi da: ";
				cin >> songuoitoida;
			} while (songuoitoida < phong.songuoihientai);
			phong.suaphong(phong.tenphong, phong.loaiphong, songuoitoida, phong.songuoihientai);
			cout << "Da sua ten phong thanh cong\n";
			phong.xuathongtinphong();
		}
		else if (chon == 4) {
			int songuoihientai;
			do {
				cout << "Nhap so nguoi hien tai: ";
				cin >> songuoihientai;
			} while (songuoihientai > phong.songuoitoida);
			phong.suaphong(phong.tenphong, phong.loaiphong, phong.songuoitoida, songuoihientai);
			cout << "Da sua ten phong thanh cong\n";
			phong.xuathongtinphong();
		}
		else if (chon == 0) {
			break;
		}
		else
			cout << "Nhap sai, vui long nhap lai\n";
	} while (chon != 0);


}

