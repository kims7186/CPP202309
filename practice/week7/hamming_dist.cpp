#include<iostream>
#include<string>
using namespace std;

int main() {
	string s1; //문자열 1
	string s2; // 문자열 2
	int count = 0; // 해밍거리를 저장하는 변수 

	//비교할 두개의 문자열 입력 
	cout << "DNA1: ";
	cin >> s1;

	cout << "DNA2: ";
	cin >> s2;

	//해밍거리 : 두 문자열의 동일한 위치에 틀린 글자가 몇개인지를 바탕으로 계산된 거리 
	//길이가 다른경우 오류 메시지 출력
	if (s1.length() != s2.length()) {
		cout << "오류 : 길이가 다름 " << endl;
	}
	else {  //길이가 같은경우에 대해 작동 
		for (int i = 0; i < s1.length(); i++) {
			if (s1[i] != s2[i]) // 같은 인덱스의 문자 비교 
				count += 1; //차이가 있을경우 count++	
		}
		cout << "해밍 거리는 " << count << endl;  // 계산한 해밍거리 출력 
	}
	
}

