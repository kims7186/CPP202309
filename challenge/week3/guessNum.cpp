#include <iostream>	
#include <time.h>

using namespace std;

int main() {
	
	srand(time(NULL));// random 함수 초기화

	//변수 선언
	int answer = rand() % 100; //정답을 0~99사이의 무작위 숫자로 초기화 한다. 
	int tries = 0; // 시도 횟수 저장하는 변수 0으로 초기화 (연산을 수행하기 위함 )
	int guess; // 사용자 입력 저장하기 위한 변수 

	//정답을 맞출때 까지 반복하기 때문에 조건을 true로 설정
	while (true) {
		cout<< "정답을 추측하여 보시오:"<<endl;
		cin >> guess;
		if (guess > answer) {
			cout << " 제시한 정수보다 높습니다. " << endl;
			tries++;
		}
		else if (guess < answer) {
			 cout << " 제시한 정수보다 낮습니다. " << endl;
			tries++;
		} 
		else  cout << " 축하합니다 " <<tries<< endl;
	}	

	return 0;

}