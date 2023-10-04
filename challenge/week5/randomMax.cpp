#include <iostream>
#include<stdlib.h>

using namespace std;

int main() {

    //상수로 배열의 위치를 나타내는 값 선언 
	int const numcell = 10;
	int numList[numcell][numcell];


	// 난수로 배열 초기화 
	for (int i = 0; i < numcell;i++) {

		

		for (int j = 0; j < numcell;j++) {
			cout << i << ", ";
			cout << j<<" : ";
			numList[i][j] = rand() % 1000;
			cout << numList[i][j]<<endl;
		}
	}

	cout << endl; 
	int max = 0; // 큰 값을 저장을 하기 위한 변수. 0으로 초기화 
	int maxI = 0; //큰 값이 있는 i를 저장하기 위한 변수 
	int maxJ = 0; // 큰 값이 있는j를 저장하기 위한 변수 

	// 2차원 배열 안에서 가장 큰값 탐색 
	for (int i = 0; i < numcell; i++) {	
		int j = 0;
		for (int value :numList[i]) {	
			int value = numList[i][j];
			if (value > max) {
				max = value;
				maxI = i;
				maxJ = j;
			}
			j++;
		}
	}


	cout << "가장 큰 값은 " << max << "이고 ";
	cout << "i와 j는 각각" << maxI << ", " << maxJ << "입니다." << endl;
	cout << "검증 결과: " << numList[maxI][maxJ] << endl;

	return 0; 

}