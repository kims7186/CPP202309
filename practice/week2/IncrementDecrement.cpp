#include <iostream>
#include<string>
using namespace std;

int main() {
	// 변수 선언및 대입
	int x = 1;

	//++x 와 x++ 연산은 저장 방식에 차이가 있다. 
	// ++x 는 +1 연산을 한후 변수사용, x++ 는 변수를 사용한후 연산을 수행한다.
	// --x와 x--도 같은 방식으로 작동한다. 

	cout << "x = " << x++ << endl;
	cout << "x = " << x++ << endl;
	cout << "x = " << ++x << endl;
	cout << "x = " << x-- << endl;
	cout << "x = " << x-- << endl;
	cout << "x = " << --x << endl;

}