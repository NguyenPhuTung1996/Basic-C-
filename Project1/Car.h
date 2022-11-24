#ifndef CAR_H
#define CAR_H

#include<iostream>
#include<fstream>
#include <string>

#define LENGTH 8
#define passwordfile "AMS03.dat"
#define safespeedfile "safe_distance_speed.dat"

using namespace std;
class Car
{
public:
	Car();
	~Car();
	void loaddata();
	void savedata();
	static int speedR;
	static int speedD;
	void set_pass(int* pass);
	void set_speedR(int sp);
	void set_speedD(int sp);
	int* get_pass();
	int get_speedR();
	int get_speedD();
	void set_safe_distance(int* arr_speed);
	int* get_safe_distance();
	void tangtocR();
	void tangtocD();
	void giamtocR();
	void giamtocD();
	void phanh();
	void canhbao_khoangcach();
	void setspeedlevel();
	bool checkExists(string file);
	void resetPassword();
	void resetSpeedlimit();
	void firstlogin();
protected:
private:
	int password[LENGTH];
	int safe_distance[3];
};
bool isNumber(const string& str);
void printarray(int* arr, int size);
void bubblesort1(int* arr, int n);

#endif