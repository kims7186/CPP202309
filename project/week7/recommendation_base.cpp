#include <iostream>
using namespace std;

int main() {
	const int NUM_USERS = 3; // ������� �� 
	const int NUM_ITEMS = 3; // �׸��� �� 
	int userPreferences[NUM_USERS][NUM_ITEMS]; //������Ǽ�,�׸��Ǽ��� �Էµ� ��ȣ�� 2�����迭 

	//����ڿ� �׸� ���� ��ȣ���� �Է� �޾� 2���� �迭 �ʱ�ȭ 
	for (int i = 0; i < NUM_USERS; ++i) {
		cout << "����� " << (i + 1) << "�� ��ȣ���� �Է��ϼ��� (";
		cout << NUM_ITEMS << "���� �׸� ����):";
		for (int j = 0; j < NUM_ITEMS; ++j) {
			cin >> userPreferences[i][j];
		}
		
	}// ����� �Է� �Ϸ� 

	//�� ����ڿ� ���� ��õ�׸� ã�� 
	for (int i = 0; i < NUM_USERS; ++i) {
		int maxPreferenceIndex = 0; //����ڿ��� ��õ�� �׸��� �ε����� �����ϴ� ���� 
		for (int j = 1; j < NUM_ITEMS; ++j) {
			if (userPreferences[i][j] > userPreferences[i][maxPreferenceIndex]) { //��ȣ�ϴ� �׸� �� 
				maxPreferenceIndex = j; // ��õ�׸� �ε��� ������Ʈ 
			}
		}

		// ����ڿ��� ��õ�ϴ� �׸� ��� 
		cout << " " << (i + 1) << " ";
		cout << (maxPreferenceIndex + 1) << endl;  //�ε���+1 ������ �ؾ� ��õ �׸��� ��ȣ�� �ùٸ��� ���
	}
	return 0;
}