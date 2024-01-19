#include<iostream>
#include<string>
#include<fstream>
#include "StudentManagement.h"
#include "Student.h"

using namespace std;
int checkint = 0; // 기존 file 유무 체크

void Run(StudentManagement stm,ifstream*myifilepointer,string argv) {
	int selection = 0; //switch 문 선택지
	string fileinput; // 기존 file에서 한 줄씩 읽어 저장

	if (checkint == 1) {
		while (!(*myifilepointer).eof()) {
			fileinput = "";
			getline((*myifilepointer), fileinput);
			Student* std = NULL;
			std = new Student;
			if (fileinput.size() == 0) break;
			(*std).set_name(fileinput.substr(0, 15)); // substring으로 잘라서 student의 각 member에 저장.
			(*std).set_StudentID(fileinput.substr(16, 10));
			(*std).set_BirthYear(fileinput.substr(27, 4));
			(*std).set_Department(fileinput.substr(32, 20)); //dept는 20자로 제한.
			(*std).set_Tel(fileinput.substr(53, 12));
			stm.insert(std); // stm stack에 기존 파일에 있던 학생들 모두 push.
		}
		(*myifilepointer).clear();
		(*myifilepointer).close();
	}
	ofstream myofile(argv, ios::out | ios::trunc); // 기존 파일을 다 읽고 (혹은 없다면) 새 파일 작성.
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


int main(int argc, char* argv[]) { //이렇게 하면 .exe가 있는 곳에 file.txt가 생성된다.
	ifstream myifile(argv[1]);
	ifstream* myifilepointer = &myifile; 
	if (myifile.is_open()) { // 기존 파일 있는지 확인
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
