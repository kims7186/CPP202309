#include <iostream>
#include <string>

using namespace std;
int main()
{
	/// <summary>
	/// 
	///	�л����� ���� ���� ��� ���ϱ� ���α׷� 
	/// </summary>
	/// <returns></returns>
	/// 
	const int STUDENT = 5;// �л����� �̸��� ���� 1���� �迭
	const int SUBJECT = 3; // ���� �̸��� ���� 1���� �迭
	int scores[STUDENT][SUBJECT]; // ������ �����ϴ� 2���� �迭
	string studentNames[STUDENT] = { "����", "����", "ö��", "�̹�", "����" };
	string subjectNames[SUBJECT] = { "����","����", "CPP"};

	// �ݺ����� ���� �л����� ������ �ϳ��� �Է¹޵��� �Ѵ�. 
	for (int i = 0; i < STUDENT; i++) {

		
		cout << studentNames[i]
			<< "�� ������ �ϳ��� �Է��ϼ���. " << endl;

		// �� �л��� ������ �� ������ ������ �����ϴ� 2���� �迭 score�� �����Ѵ�.
		for (int j = 0; j < SUBJECT; j++) {
			cout << subjectNames[j] << ":";
			cin >> scores[i][j];
		}
	}

	// �л����� ���� ����� ���Ѵ�.
	for (int i = 0; i < STUDENT; i++) {
		cout << studentNames[i] << "�� ��� ������";
		double sum = 0; // ������ �� 
		double average = 0; //��� ���� 

		// �������� ���� ���� ���� sum ������ ���� 
		for (int j = 0; j < SUBJECT; j++) {

			sum += scores[i][j];
		}
		//��� ���� 
		average= sum / SUBJECT;

		//��� 
		cout << average << "�Դϴ� . " << endl;
	}
	return 0;
}
