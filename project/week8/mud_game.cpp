#include <iostream>
#include <string>
using namespace std;

const int mapX = 5;
const int mapY = 5;

//������ ü���� �����ϴ� ���� 
int user_hp = 20;//�ʱⰪ 20 

// ����� ���� �Լ�
bool checkXY(int user_x, int mapX, int user_y, int mapY);
void displayMap(int map[][mapX], int user_x, int user_y);
bool checkGoal(int map[][mapX], int user_x, int user_y);
void checkState(int map[][mapX], int user_x, int user_y);
void printMovement(int movementX, int movementY);

// ����  �Լ�
int main() {
	// 0�� �� ����, 1�� ������, 2�� ��, 3�� ����, 4�� ������
	int map[mapY][mapX] = { {0, 1, 2, 0, 4},
					{1, 0, 0, 2, 0},
					{0, 0, 0, 0, 0},
					{0, 2, 3, 0, 0},
					{3, 0, 0, 0, 2} };


	// ������ ��ġ�� ������ ����
	int user_x = 0; // ���� ��ȣ
	int user_y = 0; // ���� ��ȣ

	//���� ���� �˸��� �Բ� ���Ӿȳ�, ���� ��ġ, ���� ������ ��� 
	cout << endl << ("mud ������ �����մϴ�. ") << endl;
	cout << endl << ("���� �¿�� �̵��Ҽ� ������ �̵��� ü���� 1 ���Դϴ�.") << endl;
	cout << endl << ("���� ������ ü���� 2 ���Դϴ�.") << endl;
	cout << endl << ("�������� ����ų� ������ �Է��ΰ�� ���ڸ��� ���ƿɴϴ�.") << endl;
	cout << endl << ("������ �Է��ϸ� ���� ��ġ�� �ʻ�Ȳ�� �����ְ�, ���Ḧ �Է½� ������ ����˴ϴ�.") << endl;
	cout << endl << ("������ �� ��Ȳ�Դϴ�. ������ ���ϴ�. ") << endl << endl;


	displayMap(map, user_x, user_y); // ����ڿ��� �ʱ� �ʻ��¸�1 ȸ ����մϴ�. 

	// ���� ���� 
	while (1) { // ����ڿ��� ��� �Է¹ޱ� ���� ���� �����������Ѵ�. 

		// ������� �Է��� ������ ����
		string user_input = "";

		cout << endl << "������ HP: " << user_hp << " ��ɾ �Է��ϼ��� (��,��,��,��,����,����): ";
		cin >> user_input; // ����� �Է� �ޱ�

		//������� ��ǥ �̵� ó���ϱ�(��,��,��,�� �� �ϳ��ΰ�� ) 
		if (user_input == "��" || user_input == "��" || user_input == "��" || user_input == "��") {

			//�������  ��ǥ�̵�  ó���ϱ� 
			bool inMap;//��ǥ ��ȿ�� �˻� ����� �����ϴ� ���� 
			int movementX = 0, movementY = 0; // x��ǥ,y��ǥ�� �̵��� �ӽ÷� �����ϴ� ����.����� �Է��� ���ö����� �ʱ�ȭ �ȴ�. 

			//������� ��ǥ�� �Է��� ����, ������Ȳ�� �°�  checkXY �Լ� ȣ�� �� movemntX,movementY���� �ʱ�ȭ 
			if (user_input == "��") {
				inMap = checkXY(user_x, mapX, user_y - 1, mapY);
				movementY--;
			}
			else if (user_input == "��") {
				inMap = checkXY(user_x, mapX, user_y + 1, mapY);
				movementY++;
			}
			else if (user_input == "��") {
				inMap = checkXY(user_x - 1, mapX, user_y, mapY); //��ǥ�� ��ȿ�� �˻� ����� inamp ������ ���� 
				movementX--;
			}
			else { // ������� �Է���"�� " �ΰ�� 
				inMap = checkXY(user_x + 1, mapX, user_y, mapY);
				movementX++;
			}

			if (inMap == true) { //������� ��ǥ�̵��� ��ȿ�� ��쿡�� �Ʒ� ������ �����Ѵ�. 

				//������� ��ǥ �̵� 
				user_x += movementX;
				user_y += movementY;
				printMovement(movementX,movementY);
				user_hp--; //����� �̵��� ü�� 1�� ���� 
				checkState(map, user_x, user_y);
				displayMap(map, user_x, user_y);
			}
			else {//������� ��ǥ�̵��� ��ȿ���� ������� ��� 
				cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;
			}
		}

		else if (user_input == "����") { // ����ڰ� �̵��� �ƴ� "����"�ɼ��� �����Ѱ�� 
			// TODO: ���� �����ֱ� �Լ� ȣ��
			displayMap(map, user_x, user_y);
		}
		else if (user_input == "����") { //����ڰ� ���Ḧ �Է��� ��� 
			cout << "�����մϴ�.";
			break;
		}
		else {// �Է���ü�� �ɼǿ� ���� ��� 
			cout << "�߸��� �Է��Դϴ�." << endl;
			continue;
		}


		// �������� �����ߴ��� üũ
		bool finish = checkGoal(map, user_x, user_y);
		if (finish == true) { // �������� �����Ѱ�� ��� 
			cout << "�������� �����߽��ϴ�! �����մϴ�!" << endl;
			cout << "������ �����մϴ�." << endl;
			break;
		}

		//hp�� 0 ���ϰ� �Ǹ� "����"�� �Է��ϰ� ���� 
		if (user_hp <= 0) {
			cout << "HP�� 0 ���ϰ� �Ǿ����ϴ�. ���� �߽��ϴ�" << endl;
			cout << "������ �����մϴ�." << endl;
			break;
		}




	}
	return 0;
}


// ������ ����� ��ġ ����ϴ� �Լ�
void displayMap(int map[][mapX], int user_x, int user_y) {
	for (int i = 0; i < mapY; i++) {
		//�� ���� �ٲ𶧸��� ������ �׵θ��� �׸���. 
		cout << " --------------------------------- " << endl;
		cout << "|";
		for (int j = 0; j < mapX; j++) {
			if (i == user_y && j == user_x) {//�ش���ǥ�� ����ڰ� �ִ°�� 
				cout << " USER |"; // �� �� 1ĭ ����
			}
			else { //�׿� �����ϰ� ��� 
				int posState = map[i][j];
				switch (posState) {
				case 0:
					cout << "      |"; // 6ĭ ����
					break;
				case 1:
					cout << "������|";
					break;
				case 2:
					cout << "  ��  |"; // �� �� 2ĭ ����
					break;
				case 3:
					cout << " ���� |"; // �� �� 1ĭ ����
					break;
				case 4:
					cout << "������|";
					break;
				}
			}
		}
		cout << endl;

	}
	cout << " ---------------------------------- " << endl;
}

// �̵��Ϸ��� ���� ��ȿ�� ��ǥ���� üũ�ϴ� �Լ�
bool checkXY(int user_x, int mapX, int user_y, int mapY) {
	bool checkFlag = false;
	if (user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY) {
		checkFlag = true;
	}
	return checkFlag;
}

// ������ ��ġ�� ���������� üũ�ϴ� �Լ�
bool checkGoal(int map[][mapX], int user_x, int user_y) {
	// ������ �����ϸ�
	if (map[user_y][user_x] == 4) {
		return true;
	}
	return false;
}

//���� ��ǥ�� ���¸� ��Ÿ���� �Լ�
void checkState(int map[][mapX], int user_x, int user_y) {
	int check = map[user_y][user_x];

	switch (check) {

	case 1:
		cout << "�������� �ֽ��ϴ�" << endl;

		break;
	case 2:
		cout << "  ���� �ֽ��ϴ�. HP�� 2�� �پ��ϴ�." << endl;
		user_hp = user_hp - 2;
		break;
	case 3:
		cout << " ������ �ֽ��ϴ�. HP�� 2 �þ�ϴ�." << endl;
		user_hp = user_hp + 2;
		break;
	}

}

//��ǥ�̵������ ��� 
void printMovement(int movementX, int movementY) {

	switch (10 * movementX + movementY) {
	case(-1): //������ ��ĭ
		cout << "���� �� ĭ �ö󰩴ϴ�." << endl;
		break;
	case(1):///�Ϸ� ��ĭ
		cout << "������ �� ĭ �������ϴ�." << endl;
		break;
	case(-10): //�·� ��ĭ
		cout << "�������� �̵��մϴ�." << endl;
		break;
	case(10): // ��� ��ĭ 
		cout << "���������� �̵��մϴ�." << endl;
		break;
	}
}
