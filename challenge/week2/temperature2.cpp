#include <iostream>

using namespace std;

int main() {

	//���� ����
	double far; // ȭ��
	double cel;// ���� 


	// �����µ��� �Է¹޴´� 
	cout << "�����µ�:";
	cin >> cel;

	//���� ���� ���� ȭ�� �µ��� ���Ѵ�.
	far = (9.0 / 5.0* cel) +32;

	//����� ����Ѵ�.
	cout << endl;
	cout << "ȭ���µ� = " << far;
	return 0;
}