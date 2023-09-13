#include <iostream>

using namespace std;

int main() {

	// int형 변수를 선언하고 값을 대입한다. 
	int two = 2;
	int eight = 8;
	int sum1 = 2;
	int sum2 = 2;

	

	// 위의 연산과 비슷한 내용이지만 , += 연산자를 이용하여 
	// sum2 = sum2+eight; 의 연산을 축약하고 있다.
	sum1 = sum1 + two;
	sum2 += eight;
	cout << "sum1 = " << sum1 << endl;
	cout << "sum2 = " << sum2 << endl;

	return 0;
}