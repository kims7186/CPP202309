#include <iostream>	

using namespace std;

int main() {
	
	//���� ����
	int choice;

	// ����� �Լ��� �̿��� choice�� �Է� �޴´� .
	cout << "1. ���� ���� " << endl;
	cout << "2. ���� ���� �ݱ� " << endl;
	cout << "3. ����" << endl;
	cin >> choice;

	// switch ���ǹ��� �̿��� �Է� ���� ��ȣ�� �ش��ϴ� ����� ����Ѵ�
	switch (choice) {
	case 1:
		cout << "���� ������ �����߽��ϴ�." << endl;
		break;
	case 2:
		cout << "���� ���� �ݱ⸦ �����߽��ϴ�." << endl;
		break;
	case 3:
		cout << "���α׷��� �����մϴ�." << endl;
	default:
		cout << " �߸��� �����Դϴ�." << endl;
		break;
	}

	return 0;

}