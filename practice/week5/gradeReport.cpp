#include <iostream>
#include <string>

using namespace std;
int main()
{
	/// <summary>
	/// 
	///	학생들의 성적 과목별 평균 구하기 프로그램 
	/// </summary>
	/// <returns></returns>
	/// 
	const int STUDENT = 5;// 학생들의 이름이 적힌 1차원 배열
	const int SUBJECT = 3; // 과목 이름이 적힌 1차원 배열
	int scores[STUDENT][SUBJECT]; // 성적을 저장하는 2차원 배열
	string studentNames[STUDENT] = { "영수", "영희", "철수", "미미", "쥬쥬" };
	string subjectNames[SUBJECT] = { "수학","영어", "CPP"};

	// 반복문을 통해 학생들의 성적을 하나씩 입력받도록 한다. 
	for (int i = 0; i < STUDENT; i++) {

		
		cout << studentNames[i]
			<< "의 성적을 하나씩 입력하세요. " << endl;

		// 각 학생의 성적을 각 과목의 점수를 저장하는 2차원 배열 score에 저장한다.
		for (int j = 0; j < SUBJECT; j++) {
			cout << subjectNames[j] << ":";
			cin >> scores[i][j];
		}
	}

	// 학생들의 과목별 평균을 구한다.
	for (int i = 0; i < STUDENT; i++) {
		cout << studentNames[i] << "의 평균 점수는";
		double sum = 0; // 점수의 합 
		double average = 0; //평균 성적 

		// 전과목의 점수 합을 구해 sum 변수에 저장 
		for (int j = 0; j < SUBJECT; j++) {

			sum += scores[i][j];
		}
		//평균 산출 
		average= sum / SUBJECT;

		//출력 
		cout << average << "입니다 . " << endl;
	}
	return 0;
}
