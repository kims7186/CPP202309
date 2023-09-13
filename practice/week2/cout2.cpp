#include <iostream>
#include<string> // 문자열 사용을 위해 헤더를 추가하였다. 
using namespace std;

int main() {
	
	//각각의 자료형의 특성을 이해하여 그에 맞게 대입 한다.   
	char character = 'C';
	int integer = 100;
	double precision = 3.14159;
	bool is_true = true;
	string word = "Hello World";

	// 입출력 함수를 이용해 결과를 출력한다. 
	cout << "char : " << character << endl;
	cout << "int : " << integer << endl;
	cout << "double : " << precision << endl;
	cout << "bool : " <<is_true << endl;
	cout << "string: " << word << endl;



	return 0;
}