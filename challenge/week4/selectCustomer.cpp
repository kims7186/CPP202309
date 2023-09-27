#include <iostream>
#include <string>
using namespace std;

int main() {

	const int maxPeople = 3;
	// 초기화 되지 않으면 배열 선언이 안되므로 상수로 초기화 
	// 
	//cout << "총 고객의 수를 입력하라";
	//cin >> maxPeople;
	string names[maxPeople];
	int ages[maxPeople];
	
	// 반복문과 입출력문을 혼합하여 배열에 사람 1~3의 정보를 입력받는다. 
	for (int i = 0; i < 3; i++) {
		cout << "사람" << i+1 << "의 이름 :";
		cin >> names[i];
		cout << "사람" << i << "의 나이 :"; 
		cin >> ages[i];
		
	}


	int ageThreshold; // 문제에서 정의한 사람의 특정 나이 
	cout << "특정 나이 이상인 사람을 찾으려면 나이를 입력하세요:";

	cin >> ageThreshold; // 특정 나이 입력받음 
	cout << ageThreshold << "세 이상인 고객들: \n";
	
	//조건을 충족하는 사람의 수를 입력받는 변수 선언 
	int count = 0;
	
	//반복문을 통해 조건을 충족하는 사람의 수를 카운트 
	for (int i = 0; i < 3; i++) {
		if (ages[i] >= ageThreshold) {
			count++;
		}
	}

	//카운트가 0보다 큰경우 해당하는 사람들의 이름과 나이를 출력 
	//카운트가 없는경우 특정 나이보다 많은 고객이 없는 메시지를 출력한다.
	if (count > 0) {
		for (int i = 0; i < count; i++) {
			if (ages[i] >= ageThreshold) {
				cout << names[i] << " (" << ages[i] << "세) " << endl;
			}
		}
	}
	else {
		cout << ageThreshold << "이상의 나이를 가진 고객이 없습니다.";
	}
}
