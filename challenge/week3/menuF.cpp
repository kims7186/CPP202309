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

	// if else���ǹ��� �̿��� �Է� ���� ��ȣ�� �ش��ϴ� ����� ����Ѵ�

	if (choice == 1) { // �Է��� 1�ΰ�� 
		cout << "���� ������ �����߽��ϴ�." << endl;
	}
	else if (choice == 2) { // �Է��� 2�ΰ��
		cout << "���� ���� �ݱ⸦ �����߽��ϴ�." << endl;
	}
	else if (choice == 3) { //�Է��� 3�ΰ�� 
		cout << "���α׷��� �����մϴ�." << endl;
	}
	else cout << " �߸��� �����Դϴ�." << endl; //�Է��� 1,2,3�� �ϳ��� �ƴѰ�� ��� 
	return 0;

}