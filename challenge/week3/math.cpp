#include <iostream>	
#include<time.h>
using namespace std;

int main() {

	//변수 선언
	int i=0; // 맞은횟수. 0으로 초기화  
	int ans; // 
	int myans; // 사용자의 답안
	cout << "산수 문제를 자동으로 출제합니다." << endl;

	while (true) {
		// 랜덤으로 두개의 숫자를 받은후 문제를 출제한다.
		int firstNum = rand() % 100;
		int seconNum = rand() % 100;		
		ans = firstNum + seconNum;

		// 사용자의 답안 입력받기
		cin >> myans;

		//평가
		if (myans == ans) {
			cout << "맞았습니다." << endl;
			i++;
		}
		else cout << "틀렸습니다." << endl;
		
		//5번 맞으면 종료

		if (i == 5) break;


	}
	return 0;

}