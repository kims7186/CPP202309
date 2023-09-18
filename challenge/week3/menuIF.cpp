#include <iostream>	

using namespace std;

int main() {

	//변수 선언
	int choice;

	// 입출력 함수를 이용해 choice를 입력 받는다 .
	cout << "1. 파일 저장 " << endl;
	cout << "2. 저장 없이 닫기 " << endl;
	cout << "3. 종료" << endl;
	cin >> choice;

	// if else조건문을 이용해 입력 받은 번호에 해당하는 결과를 출력한다

	if (choice == 1) { // 입력이 1인경우 
		cout << "파일 저장을 선택했습니다." << endl;
	}
	else if (choice == 2) { // 입력이 2인경우
		cout << "저장 없이 닫기를 선택했습니다." << endl;
	}
	else if (choice == 3) { //입력이 3인경우 
		cout << "프로그램을 종료합니다." << endl;
	}
	else cout << " 잘못된 선택입니다." << endl; //입력이 1,2,3중 하나가 아닌경우 출력 
	return 0;

}
