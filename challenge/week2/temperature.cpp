#include <iostream>
#include<string> // ���ڿ� ����� ���� ����� �߰��Ͽ���. 
using namespace std;

int main() {

	//���� ����(������ ���� 0���� �ʱ�ȭ �Ѵ�.)
	double far; // ȭ��
	double cel;// ���� 

	
	// ȭ���µ��� �Է¹޴´� 
	cout << "ȭ���µ�:";
	cin >> far;

	//���� ���� ���� ���� �µ��� ���Ѵ�.
	cel = (5.0 / 9.0) * (far - 32);

	//����� ����Ѵ�.
	cout<<endl;
	cout << "�����µ� = "<<cel;
	return 0;
}