#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<algorithm>
#include "Student.h"

using namespace std;

class StudentManagement {
private:
	Student* studentList[100] = {}; //student list
	int selection=0; // switch 문 사용자 선택 입력값
	int top = 0; // student list top pointer
	string user_str; // 사용자 입력 string
	int user_int=0; // 사용자 입력 int
	int sortednumber = 0; // 사용자가 sort 했던 횟수

public:
	void insert(Student* student) {
		studentList[top] = student;
		top++;
	}
	
	Student* get_std(int top) {
		return studentList[top];
	}

	int get_top() {
		return top;
	}

	void insertion() {
		Student* student;
		student = new Student;
		string user_str = {};

		cout << "number of stored students : " << this->top << endl;
		cout << "\nName (up to 15digits) ?\n>_";
		getline(cin, user_str);
		if ((user_str.length() > 16) || (user_str.length() <= 0)) {
			cout << "wrong input!";
			return;
		}
		user_str.resize(15);
		(*student).set_name(user_str);
		
		cout << "Student ID (exactly 10 digits) ?\n>_";
		getline(cin, user_str);
		if ((user_str.length() != 10)) {
			cout << "wrong input!";
			return;
		}
		for (int i = 0; i < top; i++) { // if same id exists
			if ((*studentList[i]).get_ID().compare(user_str)==0) {
				cout << "Error : Already inserted";
				return;
			}
		}
		(*student).set_StudentID(user_str);

		cout << "BirthYear (exaclty 4 digits) ?\n>_";
		getline(cin, user_str);
		if (user_str.length() != 4) {
			cout << "wrong input!";
			return;
		}
		user_str.resize(4);
		(*student).set_BirthYear(user_str);

		cout << "Department (up to 20 character ?)\n>_";
		getline(cin, user_str);
		if (user_str.length() > 21) {
			cout << "wrong input!";
			return;
		}
		user_str.resize(20);
		(*student).set_Department(user_str);

		cout << "Tel ? (up to 12 digits)\n>_";
		getline(cin, user_str);
		if (user_str.length() > 13) {
			cout << "wrong input!\n";
			return;
		}
		user_str.resize(12);
		(*student).set_Tel(user_str);
		
		studentList[top] = student;
		top++;
		cout << "studentList[" << top << "]'s name is " << (*student).get_name() << endl;
	}

	void search() {
		cout << "\n- Search -\n1. Search by name\n2. Search by Student ID (10 numbers)\n3. Search by admission year (4 years)\n4. Search by department name\n5.List All\n>_";
		cin >> selection; cin.ignore();
		switch (selection) {
		case 1: // search by name
			cout << "Name (up to 15 digit) ?\n>_";
			getline(cin, user_str);
			user_str.resize(15);
			for (int i = 0; i < top; i++) {
				if ((*studentList[i]).get_name().compare(user_str)==0) {
					cout << "    Name       Student ID   Birth  Department          Tel\n";
					cout << (*studentList[i]).get_name() << " " << (*studentList[i]).get_ID() << " " << (*studentList[i]).get_bd() << " " << (*studentList[i]).get_dept() <<" " << (*studentList[i]).get_tel() << "\n";
					return;
				}
			}
			cout << "no matches\n";
			break;
		case 2: // search by id
			cout << "Student ID (10 digit) ?\n>_";
			getline(cin, user_str);
			for (int i = 0; i < top; i++) {
				if ((*studentList[i]).get_ID().compare(user_str)==0) {
					cout << "    Name       Student ID   Birth  Department          Tel\n";
					cout << (*studentList[i]).get_name() << " " << (*studentList[i]).get_ID() << " " << (*studentList[i]).get_bd() << " " << (*studentList[i]).get_dept()<<" " << (*studentList[i]).get_tel() << "\n";
					return;
				}
			}
			cout << "no matches\n";
			break;
		case 3: //search by adyear
			cout << "Addmission year (4 digit) ?\n>_";
			getline(cin, user_str);
			for (int i = 0; i < top; i++) {
				if ((*studentList[i]).get_ID().substr(0, 4).compare(user_str) == 0) { // student ID의 첫 4 digit이 admission year
					cout << "    Name       Student ID   Birth  Department          Tel\n";
					cout << (*studentList[i]).get_name() << " " << (*studentList[i]).get_ID() << " " << (*studentList[i]).get_bd() << " " << (*studentList[i]).get_dept() <<" " << (*studentList[i]).get_tel() << "\n";
					return;
				}
			}
			cout << "no matches\n";
			break;
		case 4: // search by dept
			cout << "Department (up to 20 digit) ?\n>_";
			getline(cin, user_str);
			user_str.resize(20);
			for (int i = 0; i < top; i++) {
				if ((*studentList[i]).get_dept().compare(user_str)==0) {
					cout << "    Name       Student ID   Birth  Department          Tel\n";
					cout << (*studentList[i]).get_name() << " " << (*studentList[i]).get_ID() << " " << (*studentList[i]).get_bd() << " " << (*studentList[i]).get_dept()<<" " << (*studentList[i]).get_tel() << "\n";
					return;
				}
			}
			cout << "no matches\n";
			break;
		case 5: // List all
			if (sortednumber == 0) {//sort by name if never sorted before
				Student* temp;
				string* unordered;
				unordered = new string[top];
				for (int i = 0; i < top; i++) {
					unordered[i] = (*studentList[i]).get_name();
				}
				std::sort(unordered, unordered + top);
				for (int i = 0; i < top; i++) {
					for (int j = 0; j < top; j++) {
						if (unordered[i].compare((*studentList[j]).get_name()) == 0) {
							temp = studentList[i];
							studentList[i] = studentList[j];
							studentList[j] = temp;
						}
					}
				}
			}
			cout << "                   - List All -\n";
			cout << "    Name       Student ID   Birth  Department          Tel\n";
			for (int i = 0; i < top; i++) {
				cout << (*studentList[i]).get_name() << " " << (*studentList[i]).get_ID() << " " << (*studentList[i]).get_bd() << " " << (*studentList[i]).get_dept()<<" " << (*studentList[i]).get_tel() << "\n";
			}
			break;
		default:
			cout << "wrong input!\n";
			break;
		}
	}

	void sort() {
		Student* temp=nullptr;
		string* unordered=nullptr; //입력된 학생 수만큼 동적할당.
		cout << "\n- Sorting Option -\n1. Sort by name\n2. Sort by Student ID (10 numbers)\n3. Sort by admission year (4 digits)\n4. Sort by department name\n>_";
		cin >> selection;
		switch (selection) {
		case 1: // sort by name(default)
			unordered = new string [top];
			for (int i = 0; i < top; i++) {
				unordered[i] = (*studentList[i]).get_name();
			}
			std::sort(unordered,unordered+top);
			for (int i = 0; i < top; i++) {
				for (int j = 0; j < top; j++) {
					if (unordered[i].compare((*studentList[j]).get_name()) == 0) {
						temp = studentList[i];
						studentList[i] = studentList[j];
						studentList[j] = temp;
					}
				}
			}
			delete[] unordered;
			sortednumber++; //sorted 횟수 카운팅
			cout << "Sorting complete!\n";
			break;
		case 2: // sort by id
			unordered = new string[top];
			for (int i = 0; i < top; i++) {
				unordered[i] = (*studentList[i]).get_ID();
			}
			std::sort(unordered, unordered + top);
			for (int i = 0; i < top; i++) {
				for (int j = 0; j < top; j++) {
					if (unordered[i].compare((*studentList[j]).get_ID()) == 0) {
						temp = studentList[i];
						studentList[i] = studentList[j];
						studentList[j] = temp;
					}
				}
			}
			delete[] unordered;
			sortednumber++;
			cout << "Sorting complete!\n";
			break;
		case 3: //sort by adyear
			unordered = new string[top];
			for (int i = 0; i < top; i++) {
				unordered[i] = (*studentList[i]).get_ID().substr(0,4);
			}
			std::sort(unordered, unordered + top);
			for (int i = 0; i < top; i++) {
				for (int j = 0; j < top; j++) {
					if (unordered[i].compare((*studentList[j]).get_ID().substr(0,4)) == 0) {
						temp = studentList[i];
						studentList[i] = studentList[j];
						studentList[j] = temp;
					}
				}
			}
			delete[] unordered;
			sortednumber++;
			cout << "Sorting complete!\n";
			break;
		case 4: // sort by dept
			unordered = new string[top];
			for (int i = 0; i < top; i++) {
				unordered[i] = (*studentList[i]).get_dept();
			}
			std::sort(unordered, unordered + top);
			for (int i = 0; i < top; i++) {
				for (int j = 0; j < top; j++) {
					if (unordered[i].compare((*studentList[j]).get_dept()) == 0) {
						temp = studentList[i];
						studentList[i] = studentList[j];
						studentList[j] = temp;
					}
				}
			}
			delete[] unordered;
			sortednumber++;
			cout << "Sorting complete!\n";
			break;
		default:
			cout << "wrong input!\n";
			cin.ignore();
			return;
			break;
		}
	}

	void filewrite(ofstream* myfile) { // write stack data into file1.txt
		for (int i = 0; i < top;i++) {
			(*myfile) << (*studentList[i]).get_name() << " " << (*studentList[i]).get_ID() << " " << (*studentList[i]).get_bd() << " " << (*studentList[i]).get_dept() << " " << (*studentList[i]).get_tel() << "\n";
		}
		cout << top << endl;
		for (int i = 0; i < top; i++) { // memory delete
			delete studentList[i];
		}
	}
};
