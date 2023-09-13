#include <iostream>

using namespace std;

int main() {

	//변수 선언
	double far; // 화씨
	double cel;// 섭씨 


	// 섭씨온도를 입력받는다 
	cout << "섭씨온도:";
	cin >> cel;

	//다음 식을 통해 화씨 온도를 구한다.
	far = (9.0 / 5.0* cel) +32;

	//결과를 출력한다.
	cout << endl;
	cout << "화씨온도 = " << far;
	return 0;
}