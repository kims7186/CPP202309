#include <iostream>

using namespace std;

int main() {

	//���� a,b,c�� ���� ū���� �����ϴ� largest ���� ����
	int a, b, c, smallest;

	// ����� ���� �̿��� �������� ���е� ����� �Է��� �޴´�
	cout << "3���� ������ �Է��Ͻÿ� : ";
	cin >> a >> b >> c;


	//���ǹ��� ���� ���� ���� ���ڸ� ã�´�. 

	if (a < b && a < c) //a �� ���� ���� ��� 
		smallest = a;
	else if (b < a && b < c) // b�� ���� ���� ��� 
		smallest = b;
	else smallest = c; // �׿�. c�� ���� ���� ���  


	// ����¹��� �̿��� ����� ����Ѵ�

	cout << "���� ���� ������ " << smallest << endl;

	return 0;


}
