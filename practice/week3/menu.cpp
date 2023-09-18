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

	// switch 조건문을 이용해 입력 받은 번호에 해당하는 결과를 출력한다
	switch (choice) {
	case 1:
		cout << "파일 저장을 선택했습니다." << endl;
		break;
	case 2:
		cout << "저장 없이 닫기를 선택했습니다." << endl;
		break;
	case 3:
		cout << "프로그램을 종료합니다." << endl;
	default:
		cout << " 잘못된 선택입니다." << endl;
		break;
	}

	return 0;

}