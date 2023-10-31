#include <iostream>
using namespace std;

int main() {
	const int NUM_USERS = 3; // 사용자의 수 
	const int NUM_ITEMS = 3; // 항목의 수 
	int userPreferences[NUM_USERS][NUM_ITEMS]; //사용자의수,항목의수가 입력된 선호도 2차원배열 

	//사용자와 항목 간의 선호도를 입력 받아 2차원 배열 초기화 
	for (int i = 0; i < NUM_USERS; ++i) {
		cout << "사용자 " << (i + 1) << "의 선호도를 입력하세요 (";
		cout << NUM_ITEMS << "개의 항목에 대해):";
		for (int j = 0; j < NUM_ITEMS; ++j) {
			cin >> userPreferences[i][j];
		}
		
	}// 사용자 입력 완료 

	//각 사용자에 대한 추천항목 찾기 
	for (int i = 0; i < NUM_USERS; ++i) {
		int maxPreferenceIndex = 0; //사용자에게 추천할 항목의 인덱스를 저장하는 변수 
		for (int j = 1; j < NUM_ITEMS; ++j) {
			if (userPreferences[i][j] > userPreferences[i][maxPreferenceIndex]) { //선호하는 항목 비교 
				maxPreferenceIndex = j; // 추천항목 인덱스 업데이트 
			}
		}

		// 사용자에게 추천하는 항목 출력 
		cout << " " << (i + 1) << " ";
		cout << (maxPreferenceIndex + 1) << endl;  //인덱스+1 연산을 해야 추천 항목의 번호를 올바르게 출력
	}
	return 0;
}