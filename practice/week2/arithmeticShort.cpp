#include <iostream>

using namespace std;

int main() {

	// int�� ������ �����ϰ� ���� �����Ѵ�. 
	int two = 2;
	int eight = 8;
	int sum1 = 2;
	int sum2 = 2;

	

	// ���� ����� ����� ���������� , += �����ڸ� �̿��Ͽ� 
	// sum2 = sum2+eight; �� ������ ����ϰ� �ִ�.
	sum1 = sum1 + two;
	sum2 += eight;
	cout << "sum1 = " << sum1 << endl;
	cout << "sum2 = " << sum2 << endl;

	return 0;
}