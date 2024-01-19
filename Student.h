#pragma once
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Student { // 개별 학생 클래스
private:
	string name;
	string StudentID;
	string BirthYear;
	string Department;
	string Tel;

public:
	void set_name(string name) {
		this->name = name;
	}
	void set_StudentID(string id) {
		this->StudentID = id;
	}
	void set_BirthYear(string bd) {
		this->BirthYear = bd;
	}
	void set_Department(string dept) {
		this->Department = dept;
	}
	void set_Tel(string tel) {
		this->Tel = tel;
	}

	string get_name() {
		return this->name;
	}
	string get_ID() {
		return this->StudentID;
	}
	string get_bd() {
		return this->BirthYear;
	}
	string get_dept() {
		return this->Department;
	}
	string get_tel() {
		return this->Tel;
	}
};