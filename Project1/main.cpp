#include<iostream>
#include<string>
#include<fstream>
#include"Car.h"
#include<stdio.h>
#define LENGTH 8

using namespace std;

Car car;
int dem_bubblesort = 0;
int dem_selectionsort = 0;
int i=0;
void login();
void menuchinh();
void menuR();
void menuD();
void menuP();
void menuN();
void selectionsort(int* arr, int n);
void bubblesort(int* arr, int n);
bool isNumber(const string& str);

int main()
{
	login();
	car.resetPassword();
	car.setspeedlevel();
	system("cls");
	menuchinh();
	return 0;
}

void login()
{
	cout << "BAN DANG O MAN HINH DANG NHAP" << endl;
	cout << "NHAP MA SO CA NHAN GOM 8 CHU SO: " << endl;			// nhap ma so ca nhan de khoi dong xe
	int MSCN[LENGTH];
	int* MSCN1 = MSCN;
	for (int i = 0; i < LENGTH; i++) {
		string maso;
		bool invalid = true;
		do {
			if (invalid) {
				cout << "SO THU " << i + 1 << " : ";
			}
			else {
				cout << "XIN HAY NHAP LAI SO THU " << i + 1 << " : ";
			}
			cin >> maso;
			if ((maso.length() != 1) || (!isNumber(maso)) || (stoi(maso) < 1) || (stoi(maso) > 9))
			{
				invalid = false;
				cout << "XIN VUI LONG CHI NHAP SO NGUYEN DUONG TU 1 DEN 9" << endl;
				continue;
			}
			else {
				invalid = true;
			}
			MSCN[i] = stoi(maso);
		} while (!invalid);
	}
	system("cls");
	int mscn[LENGTH];
	int mscna[LENGTH];
	int mscnb[LENGTH];
	
	for (int i = 0; i < LENGTH; i++)
	{
		mscn[i] = MSCN[i];
		mscna[i] = MSCN[i];
		mscnb[i] = MSCN[i];
	}
	cout << "MANG NHAP VAO TRUOC KHI SAP XEP: ";
	printarray(mscn, LENGTH);

	int* mscn1 = mscna;
	int* mscn2 = mscnb;
	selectionsort(mscn1, LENGTH);
	cout << endl;
	cout << "MANG NHAP VAO SAU KHI SAP XEP (SELECTION SORT): ";
	printarray(mscn1, LENGTH);
	cout << endl;
	cout << "MANG NHAP VAO SAU KHI SAP XEP (BUBBLE SORT): ";
	bubblesort(mscn2, LENGTH);
	printarray(mscn2, LENGTH);
	cout << endl;
	cout << "PASSWORD TRUOC KHI SAP XEP: ";
	int* passw = car.get_pass();
	int temp[LENGTH];
	int tempa[LENGTH];
	int tempb[LENGTH];
	for(int i= 0; i< LENGTH; i++)
	{
		temp[i] = passw[i];
		tempa[i] = passw[i];
		tempb[i] = passw[i];
	}
	printarray(temp, LENGTH);
	int* temp1 = tempa;
	int* temp2 = tempb;
	cout << endl;
	cout << "PASSWORD SAU KHI SAP XEP(BUBBLE SORT): ";
	bubblesort(temp1, LENGTH);
	printarray(temp1, LENGTH);
	cout << endl;
	cout << "PASSWORD SAU KHI SAP XEP(SELECTION SORT): ";
	selectionsort(temp2, LENGTH);
	printarray(temp2, LENGTH);
	car.set_pass(passw);
	cout << endl;
	cout << "-----------------------------------------------" << endl;
	cout << "SO BUOC THUC HIEN THOAT TOAN SELECTION SORT LA:" << dem_selectionsort << endl;
	cout << "SO BUOC THUC HIEN THUAT TOAN BUBBLE SORT LA: " << dem_bubblesort << endl;
	if (dem_selectionsort == dem_bubblesort)
	{
		cout << "2 THUAT TOAN CO TOC DO XU LY BANG NHAU" << endl;
	}
	else
	{
		if (dem_selectionsort > dem_bubblesort)
		{
			cout << "THUAT TOAN BUBBLE SORT CO TOC DO XU LY NHANH HON" << endl;
		}
		else
		{
			cout << "THUAT TOAN SELECTION SORT CO TOC DO XU LY NHANH HON" << endl;
		}
	}
	cout << "--------------------------------------------------" << endl;
	for (i = 0; i < LENGTH; i++)
	{
		if (mscna[i] == passw[i] && mscnb[i] == passw[i])  // so sanh mang nhap vao voi mang co san
		{
			if (i == LENGTH - 1)
			{
				cout << "---------------------XIN CHAO-------------------- " << endl;
			}
		}
		else
		{
			system("cls");
			cout << "MA SO NHAP VAO KHONG DUNG, XIN VUI LONG NHAP LAI MA SO" << endl;
			login();
		}
	}
}

void menuchinh()
{
	cout << "XIN MOI LUA CHON" << endl;
	cout << endl;
	cout << "1. P" << endl;
	cout << "2. R" << endl;
	cout << "3. N" << endl;
	cout << "4. D" << endl;
	cout << "5. POWER OFF" << endl;
	string selectmenu;
	cin >> selectmenu;
	if ((selectmenu.length() > 1)||(!isNumber(selectmenu)) || (stoi(selectmenu) <= 0) || (stoi(selectmenu) > 5)) // kiem tra du lieu nhap vao co phai la so hay khong
	{
		system("cls");
		cout << "VUI LONG CHI NHAP SO NGUYEN DUONG TU 1 DEN 5" << endl;
		menuchinh();
	}
	switch (stoi(selectmenu)) // lenh switch cho menu chon can so
	{
	case 1:
	{
		if ((car.get_speedR() == 0) && (car.get_speedD() == 0)) // neu van toc bang 0km/h thi duoc vao so P
		{
			system("cls");
			menuP();
		}
		else
		{
			system("cls");
			cout << "DAM BAO VAN TOC BANG 0KM/H VA XE DA DUNG HAN" << endl;
			if (car.get_speedD() > 0)
			{
				cout << "BAN DANG O SO D, VUI LONG CHON LAI SO D DE CO THE GIAM TOC DO" << endl;
			}
			if (car.get_speedR() > 0)
			{
				cout << "BAN DANG O SO R, VUI LONG CHON LAI SO R DE CO THE GIAM TOC DO" << endl;
			}
			menuchinh();
		}
		break;
	}
	case 2:
	{
		if (car.get_speedD() == 0)
		{
			if (car.get_speedR() == 0)
			{
				system("cls");
				car.set_speedR(7);
				menuR();
			}
			else
			{
				system("cls");
				menuR();
			}
		}
		else //neu van toc lon hon 0km/h thi quay lai so D de giam toc do
		{

			system("cls");
			cout << "DAM BAO VAN TOC BANG 0KM/H TRUOC KHI VAO SO R" << endl;
			cout << "TRO LAI SO D DE GIAM TOC DO" << endl;
			menuD();
		}
		break;
	}
	case 3:
	{
		if ((car.get_speedR() == 0) && (car.get_speedD() == 0)) // neu van toc bang 0km/h thi duoc vao so N
		{
			system("cls");
			menuN();
		}
		else //neu van toc lon hon 0km/h thi dua ra thong bao giam toc do
		{
			system("cls");
			cout << "DAM BAO VAN TOC BANG 0KM/H VA XE DA DUNG HAN" << endl;
			if (car.get_speedD() > 0)
			{
				cout << "BAN DANG O SO D, VUI LONG CHON LAI SO D DE CO THE GIAM TOC DO" << endl;
			}
			if (car.get_speedR() > 0)
			{
				cout << "BAN DANG O SO R, VUI LONG CHON LAI SO R DE CO THE GIAM TOC DO" << endl;
			}
			menuchinh();
		}
		break;
	}
	case 4:
	{
		if (car.get_speedR() == 0)
		{
			if(car.get_speedD()==0)
			{
				system("cls");
				car.set_speedD(7);
				menuD();
			}
			else
			{
				system("cls");
				menuD();
			}
		}
		else
		{

			system("cls");
			cout << "DAM BAO VAN TOC BANG 0KM/H TRUOC KHI VAO SO D" << endl;
			cout << "TRO LAI SO R DE GIAM TOC DO" << endl;
			menuR();
		}
		break;
	}
	case 5:
	{
		system("cls");
		cout << "TAM BIET" << endl;
		break;
	}
	}
}

void menuP()
{
	cout << "DA VAO SO P" << endl;
	cout << "CHU Y SU DUNG PHANH TAY DE DAM BAO AN TOAN" << endl;
	menuchinh();
}

void menuN()
{
	cout << "DA VAO SO N" << endl;
	cout << "CHU Y SU DUNG PHANH TAY DE DAM BAO AN TOAN" << endl;
	menuchinh();
}

void menuR() // man hinh hien thi khi vao so R
{
	if (car.speedR < 0)
	{
		car.speedR = 0;
	}

	cout << "DA VAO SO R" << endl;
	cout << "TOC DO HIEN TAI: " << car.get_speedR() << "km/h" << endl;
	car.canhbao_khoangcach(); // canh bao khoang cach an toan khi lui xe
	if (car.get_speedR() >= 20)
	{
		cout << "TOC DO KHI LUI XE NGUY HIEM, BAN NEN GIAM TOC DO" << endl;
	}
	cout << " " << endl;
	cout << "1. TANG TOC" << endl;
	cout << "2. GIAM TOC" << endl;
	cout << "3. PHANH" << endl;
	cout << "4. TRO LAI MENU" << endl;
	string selectmenuR;
	cin >> selectmenuR;
	if ((selectmenuR.length() > 1)||(!isNumber(selectmenuR)) || (stoi(selectmenuR) <= 0) || (stoi(selectmenuR) > 4)) // kiem tra du lieu nhap vao co phai la so hay khong
	{
		system("cls");
		cout << "VUI LONG CHI NHAP SO NGUYEN DUONG TU 1 DEN 5" << endl;
		menuR();

	}
	switch (stoi(selectmenuR)) // lenh switch dung cho menu R
	{
		case 1: //tang toc
		{
			system("cls");
			car.tangtocR();
			menuR();
			break;
		}
		case 2: //giamtoc
		{
			system("cls");
			car.giamtocR();
			menuR();
			break;
		}
		case 3: //phanh 
		{
			system("cls");
			car.phanh();
			menuR();
			break;
		}
		case 4:  //tro lai menu chon can so
		{
			system("cls");
			menuchinh();
			break;
		}
	}
}

void menuD() // man hinh hien thi khi vao so D
{
	if (car.speedD < 0)
	{
		car.speedD = 0;
	}

	cout << "DA VAO SO D" << endl;
	cout << "TOC DO HIEN TAI: " << car.get_speedD() << "km/h" << endl;
	car.canhbao_khoangcach(); // canh bao khoang cach an toan khi lai xe
	if (car.get_speedD() >= 60)
	{
		cout << "TOC DO NGUY HIEM, BAN NEN GIAM TOC DO" << endl;
	}
	cout << " " << endl;
	cout << "1. TANG TOC" << endl;
	cout << "2. GIAM TOC" << endl;
	cout << "3. PHANH" << endl;
	cout << "4. TRO LAI MENU" << endl;
	string selectmenuD;
	cin >> selectmenuD;
	if ((selectmenuD.length() > 1)||(!isNumber(selectmenuD)) || (stoi(selectmenuD) <= 0) || (stoi(selectmenuD) > 4)) // kiem tra du lieu nhap vao co phai la so hay khong
	{
		system("cls");
		cout << "VUI LONG CHI NHAP SO NGUYEN DUONG TU 1 DEN 5" << endl;
		menuD();
	}
	switch (stoi(selectmenuD)) // lenh switch dung cho menu D
	{
	case 1://tang toc
	{
		system("cls");
		car.tangtocD();
		menuD();
		break;
	}
	case 2://giam toc
	{
		system("cls");
		car.giamtocD();
		menuD();
		break;
	}
	case 3://phanh
	{
		system("cls");
		car.phanh();
		menuD();
		break;
	}
	case 4://tro lai man hinh chon can so
	{
		system("cls");
		menuchinh();
		break;
	}
	}
}

bool isNumber(const string& str)			// kiem tra du lieu nhap vao la so hay khong
{
	for (char const& c : str) {
		if (std::isdigit(c) == 0) return false;
	}
	return true;
}

void selectionsort(int* arr, int n)			// sap xep cac phan tu trong mang theo thuat toan selection sort
{
	for (int i = 0; i < n - 1; i++)
	{
		int* p = arr;
		int min = i;
		for (int j = i + 1; j < LENGTH; j++)
		{
			if (*(p + j) < *(p + i))
			{
				min = j;
				swap(*(p + i), *(p + j));
				dem_selectionsort++;
			}
		}
	}
}

void bubblesort(int* arr, int n)		// sap xep cac phan tu trong mang bang thuat toan burble sort
{
	int* p = arr;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (*(p + i) > *(p + j))
			{
				swap(*(p + i), *(p + j));
				dem_bubblesort++;
			}
		}
	}
}
