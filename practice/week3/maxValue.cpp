#include <iostream>

using namespace std;

int main() {

	//변수 a,b,c와 가장 큰값을 저장하는 largest 변수 선언
	int a, b, c, largest;

	// 입출력 문을 이용해 공백으로 구분된 사용자 입력을 받는다
	cout << "3개의 정수를 입력하시오 : ";
	cin >> a >> b >> c;


	//조건문을 통해 가장 큰 숫자를 찾는다. 

	if (a > b && a > c) //a 가 가장 큰경우 
		largest = a;
	else if (b > a && b > c) // b가 가장 큰경우 
		largest = b;
	else largest = c; // 그외. c가 가장 큰 경우 


	// 입출력문을 이용해 결과를 출력한다

	cout << "가장 큰 정수는 " << largest << endl;

	return 0;


}
