#include <iostream>
#include <string>
using namespace std;

int main() {

	const int maxPeople = 3;
	// �ʱ�ȭ ���� ������ �迭 ������ �ȵǹǷ� ����� �ʱ�ȭ 
	// 
	//cout << "�� ���� ���� �Է��϶�";
	//cin >> maxPeople;
	string names[maxPeople];
	int ages[maxPeople];
	
	// �ݺ����� ����¹��� ȥ���Ͽ� �迭�� ��� 1~3�� ������ �Է¹޴´�. 
	for (int i = 0; i < 3; i++) {
		cout << "���" << i+1 << "�� �̸� :";
		cin >> names[i];
		cout << "���" << i << "�� ���� :"; 
		cin >> ages[i];
		
	}


	int ageThreshold; // �������� ������ ����� Ư�� ���� 
	cout << "Ư�� ���� �̻��� ����� ã������ ���̸� �Է��ϼ���:";

	cin >> ageThreshold; // Ư�� ���� �Է¹��� 
	cout << ageThreshold << "�� �̻��� ����: \n";
	
	//������ �����ϴ� ����� ���� �Է¹޴� ���� ���� 
	int count = 0;
	
	//�ݺ����� ���� ������ �����ϴ� ����� ���� ī��Ʈ 
	for (int i = 0; i < 3; i++) {
		if (ages[i] >= ageThreshold) {
			count++;
		}
	}

	//ī��Ʈ�� 0���� ū��� �ش��ϴ� ������� �̸��� ���̸� ��� 
	//ī��Ʈ�� ���°�� Ư�� ���̺��� ���� ���� ���� �޽����� ����Ѵ�.
	if (count > 0) {
		for (int i = 0; i < count; i++) {
			if (ages[i] >= ageThreshold) {
				cout << names[i] << " (" << ages[i] << "��) " << endl;
			}
		}
	}
	else {
		cout << ageThreshold << "�̻��� ���̸� ���� ���� �����ϴ�.";
	}
}
