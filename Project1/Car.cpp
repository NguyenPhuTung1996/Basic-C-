#include"Car.h"


int Car::speedR = 0;
int Car::speedD = 0;


Car::Car()
{
	if ((checkExists(passwordfile)) && (checkExists(safespeedfile))) {				// Kiem tra file nhi phan da co du lieu hay chua
		system("cls");
		cout << "HE THONG SE LAY PASSWORD DA DUOC CAI DAT TRUOC\n";
		ifstream file;
		file.open(passwordfile, ios::binary);
		file.read((char*)&password, sizeof(password));
		file.close();
		ifstream file_;
		file_.open(safespeedfile, ios::binary);
		file_.read((char*)&safe_distance, sizeof(safe_distance));
		file_.close();
	}
	else {
		cout << "CHAO BAN DAY LA LAN DAU TIEN DANG NHAP CUA BAN XIN HAY SET CAC THONG SO SAU:\n";
		cout << "CAI PASSWORD: \n";
		for (int i = 0; i < LENGTH; i++)		// nhap mang de cai dat mat khau, kiem tra du lieu nhap vao
		{
			string maso;
			bool isvalid = true;
			do {
				if (isvalid) {
					cout << "SO THU " << i + 1 << " : ";
				}
				else {
					cout << "XIN HAY NHAP LAI SO THU " << i + 1 << " : ";
				}
				cin >> maso;
				if ((!isNumber(maso)) || (stoi(maso) <= 0) ||(maso.length()>1))
				{
					isvalid = false;
					cout << "XIN VUI LONG CHI NHAP SO NGUYEN DUONG\n";
					continue;
				}
				else {
					isvalid = true;
				}
			} while (!isvalid);
			this->password[i] = stoi(maso);
		}
	}
	cout << "DA CAI DAT PASSWORD" << endl;
}

Car::~Car()
{
	ofstream file1;
	file1.open(passwordfile, ios::binary);
	file1.write((char*)&password, sizeof(password));
	file1.close();
	ofstream file1_;
	file1_.open(safespeedfile, ios::binary);
	file1_.write((char*)&safe_distance, sizeof(safe_distance));
	file1_.close();
}
bool Car::checkExists(string file)				//kiem tra file nhi phan 
{
	ifstream file_to_check(file.c_str());
	if (file_to_check.is_open())
		return true;
	return false;
	file_to_check.close();
}


void Car::savedata()		// xoa du lieu cu trong file nhi phan va ghi du lieu moi vao
{
	ofstream file1;
	file1.open(passwordfile, ios::binary);
	file1.write((char*)&password, sizeof(password));
	file1.close();
	ofstream file1_;
	file1_.open(safespeedfile, ios::binary);
	file1_.write((char*)&safe_distance, sizeof(safe_distance));
	file1_.close();
}

void Car::firstlogin()
{
	cout << "CAI PASSWORD: \n";
	for (int i = 0; i < LENGTH; i++)
	{
		string maso;
		bool isvalid = true;
		do
		{
			if (isvalid)
			{
				cout << "SO THU " << i + 1 << " : ";
			}
			else {
				cout << "XIN HAY NHAP LAI SO THU " << i + 1 << " : ";
			}
			cin >> maso;
			if ((!isNumber(maso)) || (stoi(maso) <= 0))
			{
				isvalid = false;
				cout << "XIN VUI LONG CHI NHAP SO NGUYEN DUONG" << endl;
				continue;
			}
			else
			{
				isvalid = true;
			}
		} while (!isvalid);
		this->password[i] = stoi(maso);
	}
	cout << "DA CAI DAT LAI PASSWORD" << endl;
	resetPassword();
}

int* Car::get_pass()		// nhan vao mang password
{							
	return this->password;
}

int Car::get_speedR()		// nhan vao toc do lui cua xe
{							
	return this->speedR;
}

int Car::get_speedD()		// nhan vao toc do tien cua xe
{
	return this->speedD;
}

void Car::set_pass(int* pass)		// cai mat khau cho xe
{					
	for (int i = 0; i < LENGTH; i++) {
		this->password[i] = pass[i];
	}
}

void Car::set_speedR(int sp)			// cai van toc lui cho xe
{					
	if (sp < 0) {
		cout << "invalid speed\n";
	}
	else {
		this->speedR = sp;
	}
}

void Car::set_speedD(int sp)			// cai van toc tien cho xe
{
	if (sp < 0) {
		cout << "invalid speed\n";
	}
	else {
		this->speedD = sp;
	}
}

void Car::setspeedlevel() {			// cai dat 3 muc van toc an toan theo quy dinh
	string tocdo;
	cout << "XIN MOI CAI DAT MUC TOC DO THEO LUAT GIAO THONG: " << endl;
	for (int i = 0; i < 3; i++) {
		bool isvalid = true;
		do {
			
			if (isvalid) {
				cout << "MUC TOC DO THU " << i + 1 << " : ";
			}
			else {
				cout << "XIN HAY NHAP LAI " << i + 1 << " : ";
			}
			cin >> tocdo;
			if ((!isNumber(tocdo)) || (stoi(tocdo) <= 0)) {
				isvalid = false;
				cout << "XIN VUI LONG CHI NHAP SO NGUYEN DUONG\n";
				continue;
			}
			else {
				isvalid = true;
			}
		} while (!isvalid);
		this->safe_distance[i] = stoi(tocdo);
	}
	bubblesort1(safe_distance, 3);
	resetSpeedlimit();

}

void Car::set_safe_distance(int* arr_speed)			// cai dat 3 muc toc do an toan
{		
	for (int i = 0; i < 3; i++) {
		this->safe_distance[i] = arr_speed[i];
	}
}

int* Car::get_safe_distance()			// nhan gia tri 3 muc toc do an toan
{						
	return this->safe_distance;
}

void Car::resetPassword() {
	cout << "BAN CO MUON CAI DAT LAI PASSSWORD, NHAP y/n (hoac Y/N) de CHON CO HOAC KHONG\n";		// hoi nguoi dung co muon cai lai mat khau hay khong
	char yesno;
	string yesno1;
	bool isvalid = true;
	do {
		cin >> yesno1;
		if ((yesno1.length() > 1) || (isNumber(yesno1))) {			// chi duoc nhap vao 1 ky tu
			isvalid = false;
			system("cls");
			cout << "VUI LONG CHI NHAP y/n (hoac Y/N)" << endl;;
			continue;
		}
		if ((yesno1[0] >= 'A') && (yesno1[0] <= 'Z')) {
			yesno1[0] += 32;
			yesno = yesno1[0];
		}
		else {
			yesno = yesno1[0];
		}
		if (yesno == 'y') {
			system("cls");
			firstlogin();
		}
		else if (yesno == 'n') 
		{
			system("cls");
			cout << "HE THONG SE LAY PASSWORD DA DUOC CAI DAT TRUOC"<<endl;
			break;
		}
		else 
		{
			system("cls");
			cout << "VUI LONG NHAP 1 KI TU CHU CAI y/n" << endl;;
			isvalid = false;
		}
	} while (!isvalid);
}

void Car::resetSpeedlimit() 
{
	int limit[3];
	for (int i = 0; i < 3; i++) 
	{
		limit[i] = safe_distance[i];
	}
	int count = 0;
	cout << "BAN CO MUON SET LAI MUC TOC DO KHONG (enter y for Yes, or n for NO )\n";		// hoi nguoi dung co muon cai lai toc do an toan khong
	char yesno;
	string yesno1;
	bool isvalid = true;
	do {
		cin >> yesno1;
		if ((yesno1.length() > 1) || (isNumber(yesno1))) {			// chi duoc nhap vao 1 ky tu
			isvalid = false;
			system("cls");
			cout << "VUI LONG CHI NHAP y/n (hoac Y/N)" << endl;;
			continue;
		}
		if ((yesno1[0] >= 'A') && (yesno1[0] <= 'Z')) {
			yesno1[0] += 32;
			yesno = yesno1[0];
		}
		else {
			yesno = yesno1[0];
		}
		if (yesno == 'y') {
			system("cls");
			setspeedlevel();
		}
		else if (yesno == 'n')
		{
			system("cls");
			cout << "CAI DAT TOC DO THANH CONG" << endl;
			break;
		}
		else
		{
			system("cls");
			cout << "VUI LONG NHAP 1 KI TU CHU CAI y/n" << endl;;
			isvalid = false;
		}
	} while (!isvalid);
}



void Car::canhbao_khoangcach()			// hien thi khoang cach an toan doi voi tung moc van toc
{	
	if (((speedR > 0) && (speedR <= safe_distance[0])) || ((speedD > 0) && (speedD <= safe_distance[0])))
	{
		cout << "BAN CHU Y GIU KHOANG CACH TOI THIEU LA 20m" << endl;
	}
	else if (((speedR >= safe_distance[0]) && (speedR < safe_distance[1])) || ((speedD >= safe_distance[0]) && (speedD < safe_distance[1])))
	{
		cout << "BAN CHU Y GIU KHOANG CACH TOI THIEU LA 55m" << endl;
	}
	else if (((speedR >= safe_distance[1]) && (speedR < safe_distance[2]) || (speedD >= safe_distance[1]) && (speedD < safe_distance[2])))
	{
		cout << "BAN CHU Y GIU KHOANG CACH TOI THIEU LA 70m" << endl;
	}
	else if ((speedR >= safe_distance[2]) || (speedD >= safe_distance[2]))
	{
		cout << "BAN CHU Y GIU KHOANG CACH TOI THIEU LA 100m" << endl;
	}
}




void Car::tangtocR()		// hien thi khi chon tang toc o so R
{		
	speedR += 5;
}

void Car::tangtocD()		// hien thi khi chon tang toc o so D
{
	speedD += 5;
}


void Car::giamtocR()		// hien thi khi chon giam toc o so D
{
	if (speedR < 0)
	{
		speedR = 0;
}
	speedR -= 5;
}

void Car::giamtocD()		// hien thi khi chon giam toc o so D
{
	if (speedD < 0)
	{
		speedD = 0;
	}
	speedD -= 5;
}

void Car::phanh()
{
	speedR = 0;
	speedD = 0;
}

void printarray(int* arr, int size)  // ham in mang ra man hinh
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
}

void bubblesort1(int* arr, int n)		// sap xep cac phan tu trong mang bang thuat toan burble sort
{

	for (int i = 0; i < n - 1; i++)
	{
		int* p = arr;
		for (int j = i + 1; j < n; j++)
		{
			if (*(p + i) > *(p + j))
			{
				swap(*(p + i), *(p + j));
			}
		}
	}
}



