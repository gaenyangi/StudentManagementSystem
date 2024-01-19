#include<iostream>
#include<string>
#include<fstream>
#include "StudentManagement.h"
#include "Student.h"

using namespace std;
int checkint = 0; // ���� file ���� üũ

void Run(StudentManagement stm,ifstream*myifilepointer,string argv) {
	int selection = 0; //switch �� ������
	string fileinput; // ���� file���� �� �پ� �о� ����

	if (checkint == 1) {
		while (!(*myifilepointer).eof()) {
			fileinput = "";
			getline((*myifilepointer), fileinput);
			Student* std = NULL;
			std = new Student;
			if (fileinput.size() == 0) break;
			(*std).set_name(fileinput.substr(0, 15)); // substring���� �߶� student�� �� member�� ����.
			(*std).set_StudentID(fileinput.substr(16, 10));
			(*std).set_BirthYear(fileinput.substr(27, 4));
			(*std).set_Department(fileinput.substr(32, 20)); //dept�� 20�ڷ� ����.
			(*std).set_Tel(fileinput.substr(53, 12));
			stm.insert(std); // stm stack�� ���� ���Ͽ� �ִ� �л��� ��� push.
		}
		(*myifilepointer).clear();
		(*myifilepointer).close();
	}
	ofstream myofile(argv, ios::out | ios::trunc); // ���� ������ �� �а� (Ȥ�� ���ٸ�) �� ���� �ۼ�.
	ofstream* myofilepointer = &myofile;
	while (1) {
		cout << "\n1. Insertion\n2. Search\n3. Sorting Option\n4. Exit\n>_";
		selection = 0;
		cin >> selection; cin.ignore();
		switch (selection) {
		case 1:
			stm.insertion();
			break;
		case 2:
			stm.search();
			break;
		case 3:
			stm.sort();
			break;
		case 4:
			stm.filewrite(myofilepointer);
			cout << "filewrite complete!\n";
			myofile.close();
			return;
		default:
			cout << "Unkown input\n";
			break;
		}
	}
}


int main(int argc, char* argv[]) { //�̷��� �ϸ� .exe�� �ִ� ���� file.txt�� �����ȴ�.
	ifstream myifile(argv[1]);
	ifstream* myifilepointer = &myifile; 
	if (myifile.is_open()) { // ���� ���� �ִ��� Ȯ��
		checkint = 1;
		cout << "existing file opened!\n";
	}
	else cout << "new file opened!\n";

	StudentManagement stm;
	Student* std=NULL;
	std = new Student;

	Run(stm,myifilepointer,argv[1]); 
	cout << "run end" << endl;
	cout << "program ended successfully!\n";
	return 0;
}
