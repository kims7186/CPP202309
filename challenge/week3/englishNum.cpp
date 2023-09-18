#include <iostream>	

using namespace std;

int main() {

	//변수 선언
	int number;

	// 입출력 함수를 이용해 choice를 입력 받는다 .
	cout << "숫자를 입력하시오  " << endl;	
	cin >> number;

	// if else조건문을 이용해 입력 받은 번호에 해당하는 결과를 출력한다
	if (number == 0) { //입력이 0인경우 
		cout << "zero\n" << endl;
	}
	else if (number== 1) { // 입력이 1인경우
		cout << "one\n" << endl;
	}
	else cout << " many\n" << endl; //입력이 0또는 1이 아닌경우 출력 

	return 0;

}