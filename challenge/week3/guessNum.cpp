#include <iostream>	
#include <time.h>

using namespace std;

int main() {
	
	srand(time(NULL));// random �Լ� �ʱ�ȭ

	//���� ����
	int answer = rand() % 100; //������ 0~99������ ������ ���ڷ� �ʱ�ȭ �Ѵ�. 
	int tries = 0; // �õ� Ƚ�� �����ϴ� ���� 0���� �ʱ�ȭ (������ �����ϱ� ���� )
	int guess; // ����� �Է� �����ϱ� ���� ���� 

	//������ ���⶧ ���� �ݺ��ϱ� ������ ������ true�� ����
	while (true) {
		cout<< "������ �����Ͽ� ���ÿ�:"<<endl;
		cin >> guess;
		if (guess > answer) {
			cout << " ������ �������� �����ϴ�. " << endl;
			tries++;
		}
		else if (guess < answer) {
			 cout << " ������ �������� �����ϴ�. " << endl;
			tries++;
		} 
		else  cout << " �����մϴ� " <<tries<< endl;
	}	

	return 0;

}