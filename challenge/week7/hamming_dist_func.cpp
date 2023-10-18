#include<iostream>
#include<string>
using namespace std;

string toLowerStr(string str) {
	string result;
	for (char& c : str) {
		c = tolower(c);
	}
	return result;
}

string toUpperStr(string str) {
	string result;
	for (char& c : str) {
		c = toupper(c);
	}
	return result;
}

int calcHammingDist(string s1, string s2) {

	int count = 0; // �عְŸ��� �����ϴ� ���� 

	for (int i = 0; i < s1.length(); i++) {

		if (s1[i] != s2[i]) {// ���� �ε����� ���� �� 
			count += 1; //���̰� ������� count++	
		}

	}
	return count;
}


int main() {
	string s1; //���ڿ� 1
	string s2; // ���ڿ� 2	

	//���̰� ���� ���ڿ��� �Է��Ҷ� ���� �Է¿�û �ݺ� 
	while (1) {
		//���� �ΰ��� ���ڿ� �Է� 
		cout << "DNA1: ";
		cin >> s1;

		cout << "DNA2: ";
		cin >> s2;

		//�عְŸ� : �� ���ڿ��� ������ ��ġ�� Ʋ�� ���ڰ� ������� �������� ���� �Ÿ� 
		//���̰� �ٸ���� ���� �޽��� ���		
		if (s1.length() != s2.length()) {
			cout << "���� : ���̰� �ٸ� " << endl; // ���� �޽��� 
			continue; //�Է� �ٽ� ���� 
		}
		break;
	}
	
	//�� ���ڿ� ��� lower ��ȯ�� ���� ��ҹ��� ������ ���� 
	s1 = toLowerStr(s1);
	s2 = toLowerStr(s2);
	
	//���̰� ������쿡 ���� �۵� 	
	int count = calcHammingDist(s1, s2);
	cout << "�ع� �Ÿ��� " << count << endl;  // ����� �عְŸ� ��� 
}

