#include <iostream>

using namespace std;

int main() {

	//���� ���� 
	int candy;
	int money;

	// ����� �Լ��� �̿��� ���� �Է� �޴´�. 
	cout << "���� ������ �ִ� ��:";
	cin >> money ;
	cout<< endl;
	cout << "ĵ���� ����:";
	cin >> candy;
	cout << endl;

	// �� ����(/) �� ������ ����(%) �� �̿��� ���� ���Ѵ�. 
	int result = money / candy;
	int change = money % candy;

	// ����� ����Ѵ�.
	cout << "�ִ�� �� �� �ִ� ĵ�� = " << result<<endl;
	cout << "ĵ�� ���� �� ���� �� = " << change << endl;



	return 0;
}