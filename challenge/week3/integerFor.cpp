#include <iostream>	

using namespace std;

int main() {

	
	// �����Է��� ������ �ֵ��� ���� ���� 
	int userInput;	
	
	//������� �Է��� �޾� ����� ����Ѵ�
	//for loop���� �̷���� �ֱ� ������ 
	//break ���� ���� ��� 10ȸ �ݺ��ϸ� �����Ѵ�. 
	cout << " ������ 10�� �Է��ϼ��� (0�� �Է��ϸ� ����):";
	for (int i = 0; i < 10; i++) {

		cin >> userInput;
		cout << "�Է°� : " << userInput << "Ƚ�� : " << i << endl;
	}

	cout << "����Ǿ����ϴ�."<< endl;
	return 0;

}