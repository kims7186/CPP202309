#include <iostream>	

using namespace std;

int main() {

	//���� ����
	int number;

	// ����� �Լ��� �̿��� choice�� �Է� �޴´� .
	cout << "���ڸ� �Է��Ͻÿ�  " << endl;	
	cin >> number;

	// if else���ǹ��� �̿��� �Է� ���� ��ȣ�� �ش��ϴ� ����� ����Ѵ�
	if (number == 0) { //�Է��� 0�ΰ�� 
		cout << "zero\n" << endl;
	}
	else if (number== 1) { // �Է��� 1�ΰ��
		cout << "one\n" << endl;
	}
	else cout << " many\n" << endl; //�Է��� 0�Ǵ� 1�� �ƴѰ�� ��� 

	return 0;

}