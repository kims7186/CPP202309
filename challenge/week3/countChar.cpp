#include <iostream>	

using namespace std;

int main() {

	//변수 선언. 각각 모음과 자음의 갯수를 카운팅한다. 
	int vowel = 0;
	int consonant = 0;


	cout << " 영문자를 입력하고 ctrl+z를 치세요 " << endl;

	char ch; // 사용자 입력 저장하는 변수
	
	//문자 입력이 들어오는 동안 반복이 수행된다.
	//문자 입력이 들어온경우 switch 조건문을 통해 모음이 있는지 확인후 
	//모음이 아니라면 자음의 카운트를 증가시킨다. 
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

	//모음과 자음의 개수를 출력한다. 
	cout << "모음 : " << vowel << endl;
	cout << "자음 : " << consonant << endl;

	return 0;

}