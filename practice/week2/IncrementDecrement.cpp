#include <iostream>
#include<string>
using namespace std;

int main() {
	// ���� ����� ����
	int x = 1;

	//++x �� x++ ������ ���� ��Ŀ� ���̰� �ִ�. 
	// ++x �� +1 ������ ���� �������, x++ �� ������ ������� ������ �����Ѵ�.
	// --x�� x--�� ���� ������� �۵��Ѵ�. 

	cout << "x = " << x++ << endl;
	cout << "x = " << x++ << endl;
	cout << "x = " << ++x << endl;
	cout << "x = " << x-- << endl;
	cout << "x = " << x-- << endl;
	cout << "x = " << --x << endl;

}