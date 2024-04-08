#pragma once
#include "Phong.h"
#include <string>

class SinhVien :
	public Phong
{
public:
	string mssv = "";
	string hoten = "";
	bool gioitinh = true; // 1: nam, 0: nu
	string quequan = "";
	string email = "";
	string tenphong = "";
public:
	SinhVien() {};
	~SinhVien() {
		mssv = "";
		hoten = "";
		gioitinh = 0;
		quequan = "";
		email = "";
		tenphong = "";
	};
	void themsv(string mssv, string hoten, bool gioitinh, string quequan, string email);
	void suasv(string mssv, string hoten, bool gioitinh, string quequan, string email, string tenphong);
	void xoasv();
	void xuatsinhvien();	
};

void SinhVien::themsv(string mssv, string hoten, bool gioitinh, string quequan, string email)
{
	this->mssv = mssv;
	this->hoten = hoten;
	this->gioitinh = gioitinh;
	this->quequan = quequan;
	this->email = email;
}

void SinhVien::suasv(string mssv, string hoten, bool gioitinh, string quequan, string email, string tenphong)
{
	this->mssv = mssv;
	this->hoten = hoten;
	this->gioitinh = gioitinh;
	this->quequan = quequan;
	this->email = email;
	this->tenphong = tenphong;
}

void SinhVien::xoasv()
{
	this->mssv = "";
	this->hoten = "";
	this->gioitinh = 0;
	this->quequan = "";
	this->email = "";
	this->tenphong = "";
}

void SinhVien::xuatsinhvien()
{
	cout << "MSSV: " << mssv << endl;
	cout << "Ho ten: " << hoten << endl;
	cout << "Gioi tinh: ";
	cout << (gioitinh == 1 ? "Nam" : "Nu") << endl;
	cout << "Que quan: " << quequan << endl;
	cout << "Email: " << email << endl;
	cout << "Ten phong: " << tenphong << endl;
}