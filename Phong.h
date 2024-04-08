#pragma once
#include <string>
#include <iostream>

using namespace std;

class Phong
{
public:
	string tenphong = "0";
	string loaiphong = "0";
	int songuoitoida;
	int songuoihientai;
	Phong() {}
	~Phong() {}
	void themphong(string tenphong, string loaiphong, int songuoitoida);
	void xoaphong();
	void suaphong(string tenphong = "0", string loaiphong = "0", int songuoitoida = 0, int songuoihientai = 0);
	void xuathongtinphong();
};

void Phong::themphong(string tenphong, string loaiphong, int songuoitoida)
{
	this->tenphong = tenphong;
	this->loaiphong = loaiphong;
	this->songuoitoida = songuoitoida;
	this->songuoihientai = 0;
}

void Phong::xoaphong()
{
	this->tenphong = "0";
	this->loaiphong = "0";
	this->songuoitoida = 0;
	this->songuoihientai = 0;
}

void Phong::suaphong(string tenphong, string loaiphong, int songuoitoida, int songuoihientai)
{
	if
		(tenphong != "0")
	{
		this->tenphong = tenphong;
	}
	if
		(loaiphong != "0")
	{
		this->loaiphong = loaiphong;
	}
	if
		(songuoitoida != 0)
	{
		this->songuoitoida = songuoitoida;
	}
	if
		(songuoihientai != 0)
	{
		this->songuoihientai = songuoihientai;
	}
}

void Phong::xuathongtinphong()
{
	cout << "Ten phong : " << this->tenphong << "\n";
	cout << "Loai phong : " << this->loaiphong << "\n";
	cout << "So nguoi toi da : " << this->songuoitoida << "\n";
	cout << "So nguoi hien tai : " << this->songuoihientai << "\n\n";
}
