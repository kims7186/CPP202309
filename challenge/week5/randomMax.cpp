#include <iostream>
#include<stdlib.h>

using namespace std;

int main() {

    //����� �迭�� ��ġ�� ��Ÿ���� �� ���� 
	int const numcell = 10;
	int numList[numcell][numcell];


	// ������ �迭 �ʱ�ȭ 
	for (int i = 0; i < numcell;i++) {

		

		for (int j = 0; j < numcell;j++) {
			cout << i << ", ";
			cout << j<<" : ";
			numList[i][j] = rand() % 1000;
			cout << numList[i][j]<<endl;
		}
	}

	cout << endl; 
	int max = 0; // ū ���� ������ �ϱ� ���� ����. 0���� �ʱ�ȭ 
	int maxI = 0; //ū ���� �ִ� i�� �����ϱ� ���� ���� 
	int maxJ = 0; // ū ���� �ִ�j�� �����ϱ� ���� ���� 

	// 2���� �迭 �ȿ��� ���� ū�� Ž�� 
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


	cout << "���� ū ���� " << max << "�̰� ";
	cout << "i�� j�� ����" << maxI << ", " << maxJ << "�Դϴ�." << endl;
	cout << "���� ���: " << numList[maxI][maxJ] << endl;

	return 0; 

}