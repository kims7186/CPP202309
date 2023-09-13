#include <iostream>

using namespace std;

int main() {

	//변수 선언 
	int candy;
	int money;

	// 입출력 함수를 이용해 값을 입력 받는다. 
	cout << "현재 가지고 있는 돈:";
	cin >> money ;
	cout<< endl;
	cout << "캔디의 가격:";
	cin >> candy;
	cout << endl;

	// 몫 연산(/) 과 나머지 연산(%) 을 이용해 값을 구한다. 
	int result = money / candy;
	int change = money % candy;

	// 결과를 출력한다.
	cout << "최대로 살 수 있는 캔디 = " << result<<endl;
	cout << "캔디 구입 후 남은 돈 = " << change << endl;



	return 0;
}