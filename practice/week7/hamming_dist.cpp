#include<iostream>
#include<string>
using namespace std;

int main() {
	string s1; //���ڿ� 1
	string s2; // ���ڿ� 2
	int count = 0; // �عְŸ��� �����ϴ� ���� 

	//���� �ΰ��� ���ڿ� �Է� 
	cout << "DNA1: ";
	cin >> s1;

	cout << "DNA2: ";
	cin >> s2;

	//�عְŸ� : �� ���ڿ��� ������ ��ġ�� Ʋ�� ���ڰ� ������� �������� ���� �Ÿ� 
	//���̰� �ٸ���� ���� �޽��� ���
	if (s1.length() != s2.length()) {
		cout << "���� : ���̰� �ٸ� " << endl;
	}
	else {  //���̰� ������쿡 ���� �۵� 
		for (int i = 0; i < s1.length(); i++) {
			if (s1[i] != s2[i]) // ���� �ε����� ���� �� 
				count += 1; //���̰� ������� count++	
		}
		cout << "�ع� �Ÿ��� " << count << endl;  // ����� �عְŸ� ��� 
	}
	
}

