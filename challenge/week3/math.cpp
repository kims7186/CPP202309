#include <iostream>	
#include<time.h>
using namespace std;

int main() {

	//���� ����
	int i=0; // ����Ƚ��. 0���� �ʱ�ȭ  
	int ans; // 
	int myans; // ������� ���
	cout << "��� ������ �ڵ����� �����մϴ�." << endl;

	while (true) {
		// �������� �ΰ��� ���ڸ� ������ ������ �����Ѵ�.
		int firstNum = rand() % 100;
		int seconNum = rand() % 100;		
		ans = firstNum + seconNum;

		// ������� ��� �Է¹ޱ�
		cin >> myans;

		//��
		if (myans == ans) {
			cout << "�¾ҽ��ϴ�." << endl;
			i++;
		}
		else cout << "Ʋ�Ƚ��ϴ�." << endl;
		
		//5�� ������ ����

		if (i == 5) break;


	}
	return 0;

}