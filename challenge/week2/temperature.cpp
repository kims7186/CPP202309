#include <iostream>
#include<string> // 문자열 사용을 위해 헤더를 추가하였다. 
using namespace std;

int main() {

	//변수 선언(연산을 위해 0으로 초기화 한다.)
	double far; // 화씨
	double cel;// 섭씨 

	
	// 화씨온도를 입력받는다 
	cout << "화씨온도:";
	cin >> far;

	//다음 식을 통해 섭씨 온도를 구한다.
	cel = (5.0 / 9.0) * (far - 32);

	//결과를 출력한다.
	cout<<endl;
	cout << "섭씨온도 = "<<cel;
	return 0;
}