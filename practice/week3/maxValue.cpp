#include <iostream>

using namespace std;

int main() {

	//���� a,b,c�� ���� ū���� �����ϴ� largest ���� ����
	int a, b, c, largest;

	// ����� ���� �̿��� �������� ���е� ����� �Է��� �޴´�
	cout << "3���� ������ �Է��Ͻÿ� : ";
	cin >> a >> b >> c;


	//���ǹ��� ���� ���� ū ���ڸ� ã�´�. 

	if (a > b && a > c) //a �� ���� ū��� 
		largest = a;
	else if (b > a && b > c) // b�� ���� ū��� 
		largest = b;
	else largest = c; // �׿�. c�� ���� ū ��� 


	// ����¹��� �̿��� ����� ����Ѵ�

	cout << "���� ū ������ " << largest << endl;

	return 0;


}
