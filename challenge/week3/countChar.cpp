#include <iostream>	

using namespace std;

int main() {

	//���� ����. ���� ������ ������ ������ ī�����Ѵ�. 
	int vowel = 0;
	int consonant = 0;


	cout << " �����ڸ� �Է��ϰ� ctrl+z�� ġ���� " << endl;

	char ch; // ����� �Է� �����ϴ� ����
	
	//���� �Է��� ������ ���� �ݺ��� ����ȴ�.
	//���� �Է��� ���°�� switch ���ǹ��� ���� ������ �ִ��� Ȯ���� 
	//������ �ƴ϶�� ������ ī��Ʈ�� ������Ų��. 
	while (cin >> ch) {		
		switch (ch) {
		case 'a':
			vowel++;
			break;
		case 'e':
			vowel++;
			break;
		case 'i':
			vowel++;
			break;
		case 'o':
			vowel++;
			break;
		case 'u':
			vowel++;
			break;

		default:
			consonant++;

		}
	}

	//������ ������ ������ ����Ѵ�. 
	cout << "���� : " << vowel << endl;
	cout << "���� : " << consonant << endl;

	return 0;

}