#include <iostream>
#include <string>
#include <fstream>
#include "user.h"
using namespace std;

const int MAP_X = 5;
const int MAP_Y = 5;

// ����� ���� �Լ�
bool CheckXY(int user_x, int map_x, int user_y, int map_y);
void DisplayMap(int map[][MAP_X], int player1_x, int player1_y, int player2_x, int player2_y);
bool CheckGoal(int map[][MAP_X], int user_x, int user_y);
void CheckState(int map[][MAP_X], int user_x, int user_y, User* my_user);
void PrintMovement(int movement_x, int movement_y);
bool CheckUser(User* user);

//���� ��ü�� �����ϴ� ��ü������ 
User* current_user = nullptr;
// ����  �Լ�
int main() {
	// 0�� �� ����, 1�� ������, 2�� ��, 3�� ����, 4�� ������


	ifstream input("map.txt"); // ���� �ҷ����� 

	// ������ ������ ������� ���� �޼��� ���
	if (!input.is_open()) {
		cerr << "ERROR: map.txt ���Ͽ��¿� �����Ͽ����ϴ�." << endl;
		return 1;
	}

	// ���Ͽ��� ���� �о�� 2���� �迭�� ��ȯ
	int map[MAP_Y][MAP_X];
	for (int i = 0; i < MAP_Y; ++i) {
		for (int j = 0; j < MAP_X; ++j) {
			input >> map[i][j];
		}
	}


	// ������ ��ġ�� ������ ����
	int player1_x = 0, player1_y = 0;  //�÷��̾�1�� ��ǥ (0,0)
	int player2_x = 3, player2_y = 3;  //�÷��̾�2�� ��ǥ (3,3)

	int k = 0;  // ���ʸ� �����ϴ� ���� 0�̸� player1,1�̸� player2

	//������ ������  �����ϴ� ��ü

	Magician player1(player1_x, player1_y);
	Warrior player2(player2_x, player2_y);

	//���� ���� �˸��� �Բ� ���Ӿȳ�, ���� ��ġ, ���� ������ ���
	cout << endl << ("mud ������ �����մϴ�. ") << endl;
	cout << endl
		<< ("���� �¿�� �̵��Ҽ� ������ �̵��� ü���� 1 ���Դϴ�.") << endl;
	cout << endl << ("���� ������ ü���� 2 ���̰� ���� ������ ����մϴ�.") << endl;
	cout << endl
		<< ("�������� ����ų� ������ �Է��ΰ�� ���ڸ��� ���ƿɴϴ�.")
		<< endl;
	cout << endl
		<< ("������ �Է��ϸ� ���� ��ġ�� �ʻ�Ȳ�� �����ְ�, ���Ḧ �Է½� "
			"������ ����˴ϴ�.")
		<< endl;
	cout << "�� �÷��̾� �� �� ���� �������� �����ϸ� �����̸�," << endl
		<< "�� �÷��̾� �� �� ���̶� ü���� 0 ���ϸ� ������ ����˴ϴ�." << endl;
	cout << endl << ("������ �� ��Ȳ�Դϴ�. ������ ���ϴ�. ") << endl << endl;

	// ����ڿ��� �ʱ� �ʻ��¸�1 ȸ ����մϴ�.
	DisplayMap(map, player1.x, player1.y, player2.x, player2.y);

	// ���� ����
	while (1) {  // ����ڿ��� ��� �Է¹ޱ� ���� ���� �����������Ѵ�.

		switch (k % 2) {
		case 0:
			current_user = &player1;
			cout << "Player1(magician) �� �����Դϴ�.\n";
			break;
		case 1:
			current_user = &player2;
			cout << "Player2(warrior) �� �����Դϴ�.\n";
			break;
		}


		// ������� �Է��� ������ ����
		string user_input = "";


		cout << k + 1 << "�� player �� HP: " << current_user->GetHP() << endl
			<< "��ɾ �Է��ϼ��� (��,��,��,��,����,����): ";
		cin >> user_input;  // ����� �Է� �ޱ�

		//������� ��ǥ �̵� ó���ϱ�(��,��,��,�� �� �ϳ��ΰ�� )
		if (user_input == "��" || user_input == "��" || user_input == "��" ||
			user_input == "��") {
			//�������  ��ǥ�̵�  ó���ϱ�
			bool in_map;  //��ǥ ��ȿ�� �˻� ����� �����ϴ� ����
			int movement_x = 0,  // x��ǥ,y��ǥ�� �̵��� �ӽ÷� �����ϴ� ����
				movement_y = 0;  //����� �Է��� ���ö����� �ʱ�ȭ �ȴ�.

			//������� ��ǥ�� �Է��� ����, ������Ȳ�� �°�  checkXY �Լ� ȣ�� ��
			// movemntX,movementY���� �ʱ�ȭ
			if (user_input == "��") {
				in_map = CheckXY(current_user->x, MAP_X, current_user->y - 1, MAP_Y);
				movement_y--;
			}
			else if (user_input == "��") {
				in_map = CheckXY(current_user->x, MAP_X, current_user->y + 1, MAP_Y);
				movement_y++;
			}
			else if (user_input == "��") {
				in_map = CheckXY(current_user->x - 1, MAP_X, current_user->y,
					MAP_Y);  //��ǥ�� ��ȿ�� �˻� ����� inamp ������ ����
				movement_x--;
			}
			else {  // ������� �Է���"�� " �ΰ��
				in_map = CheckXY(current_user->x + 1, MAP_X, current_user->y, MAP_Y);
				movement_x++;
			}

			try {
				if (in_map == true) {  //������� ��ǥ�̵��� ��ȿ�� ��쿡�� �Ʒ� ������ �����Ѵ�.

			  //������� ��ǥ �̵�
					current_user->x += movement_x;
					current_user->y += movement_y;
					PrintMovement(movement_x, movement_y);
					current_user->DecreaseHP(1);  //����� �̵��� ü�� 1�� ����
					CheckState(map, current_user->x, current_user->y, current_user);
					DisplayMap(map, player1.x, player1.y, player2.x, player2.y);
				}
				else {  //������� ��ǥ�̵��� ��ȿ���� ������� ���
					throw invalid_argument("���� ������ϴ�.�ٽ� ���ư��ϴ�.");
				}
			}
			catch (exception& e) {
				cout << "����:" << e.what() << endl << endl;
				continue;
			}
		}

		else if (user_input ==
			"����") {  // ����ڰ� �̵��� �ƴ� "����"�ɼ��� �����Ѱ��
	 // TODO: ���� �����ֱ� �Լ� ȣ��
			DisplayMap(map, player1_x, player1_y, player2_x, player2_y);
			continue;
		}
		else if (user_input == "����") {  //����ڰ� ���Ḧ �Է��� ���
			cout << "�����մϴ�.";
			break;
		}
		else {  // �Է���ü�� �ɼǿ� ���� ���
			cout << "�߸��� �Է��Դϴ�.�ٽ� �Է����ּ���." << endl << endl;
			continue;
		}

		// �������� �����ߴ��� üũ
		bool finish = CheckGoal(map, current_user->x, current_user->y);
		if (finish == true) {  // �������� �����Ѱ�� ���
			cout << "�� �÷��̾� �� �Ѹ��� �������� �����߽��ϴ�! �����մϴ�!" << endl;
			cout << "������ �����մϴ�." << endl;
			break;
		}

		// hp�� 0 ���ϰ� �Ǹ� "����"�� �Է��ϰ� ����
		if (CheckUser(current_user) == false) {
			cout << "�� �÷��̾� �� �Ѹ��� HP�� 0 ���ϰ� �Ǿ����ϴ�. ���� �߽��ϴ�" << endl;
			cout << "������ �����մϴ�." << endl;
			break;
		}
		k++; // �ϳѱ�� 
	}

	return 0;
}

// ������ ����� ��ġ ����ϴ� �Լ�
void DisplayMap(int map[][MAP_X], int player1_x, int player1_y, int player2_x, int player2_y) {
	for (int i = 0; i < MAP_Y; i++) {
		//�� ���� �ٲ𶧸��� ������ �׵θ��� �׸���.
		cout << " --------------------------------- " << endl;
		cout << "|";
		for (int j = 0; j < MAP_X; j++) {
			// player1(magician) ��ġ Ȯ�� �� ���
			if (i == player1_y && j == player1_x) {
				cout << "  Mag |";
			}
			// player2(Warrior) ��ġ Ȯ�� �� ���
			else if (i == player2_y && j == player2_x) {
				cout << "  War |";
			}
			else {                           //�׿� �����ϰ� ���
				int pos_state = map[i][j];
				switch (pos_state) {
				case 0:
					cout << "      |";  // 6ĭ ����
					break;
				case 1:
					cout << "������|";
					break;
				case 2:
					cout << "  ��  |";  // �� �� 2ĭ ����
					break;
				case 3:
					cout << " ���� |";  // �� �� 1ĭ ����
					break;
				case 4:
					cout << "������|";
					break;
				}
			}
		}
		cout << endl;
	}
	cout << " ---------------------------------- " << endl << endl;
}

// �̵��Ϸ��� ���� ��ȿ�� ��ǥ���� üũ�ϴ� �Լ�
bool CheckXY(int user_x, int mapX, int user_y, int mapY) {
	bool check_flag = false;
	if (user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY) {
		check_flag = true;
	}
	return check_flag;
}

// ������ ��ġ�� ���������� üũ�ϴ� �Լ�
bool CheckGoal(int map[][MAP_X], int user_x, int user_y) {
	// ������ �����ϸ�
	if (map[user_y][user_x] == 4) {
		return true;
	}
	return false;
}

//���� ��ǥ�� ���¸� ��Ÿ���� �Լ�
void CheckState(int map[][MAP_X], int user_x, int user_y, User* current_user) {
	int check = map[user_y][user_x];

	switch (check) {
	case 1:
		cout << "�������� �ֽ��ϴ�" << endl;

		break;
	case 2:
		cout << "���� �ֽ��ϴ�. HP�� 2�� �پ��ϴ�." << endl;
		current_user->DecreaseHP(2);
		current_user->doAttack();
		break;
	case 3:
		cout << "������ �ֽ��ϴ�. HP�� 2 �þ�ϴ�." << endl;
		current_user->IncreaseHP(2);
		break;
	}
}

//��ǥ�̵������ ���
void PrintMovement(int movementX, int movementY) {
	switch (10 * movementX + movementY) {
	case (-1):  //������ ��ĭ
		cout << "���� �� ĭ �ö󰩴ϴ�." << endl;
		break;
	case (1):  ///�Ϸ� ��ĭ
		cout << "������ �� ĭ �������ϴ�." << endl;
		break;
	case (-10):  //�·� ��ĭ
		cout << "�������� �̵��մϴ�." << endl;
		break;
	case (10):  // ��� ��ĭ
		cout << "���������� �̵��մϴ�." << endl;
		break;
	}
}

bool CheckUser(User* user) {
	bool result;  //��ȯ�� ���
	if (user->GetHP() <= 0)
		result = false;
	else {
		result = true;
	}
	return result;
}
