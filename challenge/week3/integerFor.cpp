#include <iostream>	

using namespace std;

int main() {

	
	// 정수입력을 받을수 있도록 변수 선언 
	int userInput;	
	
	//사용자의 입력을 받아 결과를 출력한다
	//for loop으로 이루어져 있기 때문에 
	//break 문이 없는 경우 10회 반복하면 종료한다. 
	cout << " 정수를 10번 입력하세요 (0을 입력하면 종료):";
	for (int i = 0; i < 10; i++) {

		cin >> userInput;
		cout << "입력값 : " << userInput << "횟수 : " << i << endl;
	}

	cout << "종료되었습니다."<< endl;
	return 0;

}