#include <iostream>
#include <string>
using namespace std;

const int mapX = 5;
const int mapY = 5;

//유저의 체력을 저장하는 변수 
int user_hp = 20;//초기값 20 

// 사용자 정의 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY);
void displayMap(int map[][mapX], int user_x, int user_y);
bool checkGoal(int map[][mapX], int user_x, int user_y);
void checkState(int map[][mapX], int user_x, int user_y);
void printMovement(int movementX, int movementY);

// 메인  함수
int main() {
	// 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
	int map[mapY][mapX] = { {0, 1, 2, 0, 4},
					{1, 0, 0, 2, 0},
					{0, 0, 0, 0, 0},
					{0, 2, 3, 0, 0},
					{3, 0, 0, 0, 2} };


	// 유저의 위치를 저장할 변수
	int user_x = 0; // 가로 번호
	int user_y = 0; // 세로 번호

	//게임 시작 알림과 함께 게임안내, 현재 위치, 맵의 정보를 출력 
	cout << endl << ("mud 게임을 시작합니다. ") << endl;
	cout << endl << ("상하 좌우로 이동할수 있으며 이동시 체력이 1 깎입니다.") << endl;
	cout << endl << ("적을 만나면 체력이 2 깎입니다.") << endl;
	cout << endl << ("보드판을 벗어나거나 비정상 입력인경우 제자리로 돌아옵니다.") << endl;
	cout << endl << ("지도를 입력하면 현재 위치와 맵상황을 보여주고, 종료를 입력시 게임이 종료됩니다.") << endl;
	cout << endl << ("현재의 맵 상황입니다. 건투를 빕니다. ") << endl << endl;


	displayMap(map, user_x, user_y); // 사용자에게 초기 맵상태를1 회 출력합니다. 

	// 게임 시작 
	while (1) { // 사용자에게 계속 입력받기 위해 무한 루프를시행한다. 

		// 사용자의 입력을 저장할 변수
		string user_input = "";

		cout << endl << "현재의 HP: " << user_hp << " 명령어를 입력하세요 (상,하,좌,우,지도,종료): ";
		cin >> user_input; // 사용자 입력 받기

		//사용자의 좌표 이동 처리하기(상,하,좌,우 중 하나인경우 ) 
		if (user_input == "상" || user_input == "하" || user_input == "좌" || user_input == "우") {

			//사용자의  좌표이동  처리하기 
			bool inMap;//좌표 유효성 검사 결과를 저장하는 변수 
			int movementX = 0, movementY = 0; // x좌표,y좌표의 이동을 임시로 저장하는 변수.사용자 입력이 들어올때마다 초기화 된다. 

			//사용자의 좌표의 입력을 통해, 각각상황에 맞게  checkXY 함수 호출 및 movemntX,movementY변수 초기화 
			if (user_input == "상") {
				inMap = checkXY(user_x, mapX, user_y - 1, mapY);
				movementY--;
			}
			else if (user_input == "하") {
				inMap = checkXY(user_x, mapX, user_y + 1, mapY);
				movementY++;
			}
			else if (user_input == "좌") {
				inMap = checkXY(user_x - 1, mapX, user_y, mapY); //좌표의 유효성 검사 결과를 inamp 변수에 저장 
				movementX--;
			}
			else { // 사용자의 입력이"하 " 인경우 
				inMap = checkXY(user_x + 1, mapX, user_y, mapY);
				movementX++;
			}

			if (inMap == true) { //사용자의 좌표이동이 유효한 경우에만 아래 과정을 수행한다. 

				//사용자의 좌표 이동 
				user_x += movementX;
				user_y += movementY;
				printMovement(movementX,movementY);
				user_hp--; //사용자 이동시 체력 1씩 감소 
				checkState(map, user_x, user_y);
				displayMap(map, user_x, user_y);
			}
			else {//사용자의 좌표이동이 유효하지 않은경우 출력 
				cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
			}
		}

		else if (user_input == "지도") { // 사용자가 이동이 아닌 "지도"옵션을 선택한경우 
			// TODO: 지도 보여주기 함수 호출
			displayMap(map, user_x, user_y);
		}
		else if (user_input == "종료") { //사용자가 종료를 입력한 경우 
			cout << "종료합니다.";
			break;
		}
		else {// 입력자체가 옵션에 없는 경우 
			cout << "잘못된 입력입니다." << endl;
			continue;
		}


		// 목적지에 도달했는지 체크
		bool finish = checkGoal(map, user_x, user_y);
		if (finish == true) { // 목적지에 도달한경우 출력 
			cout << "목적지에 도착했습니다! 축하합니다!" << endl;
			cout << "게임을 종료합니다." << endl;
			break;
		}

		//hp가 0 이하가 되면 "실패"를 입력하고 종료 
		if (user_hp <= 0) {
			cout << "HP가 0 이하가 되었습니다. 실패 했습니다" << endl;
			cout << "게임을 종료합니다." << endl;
			break;
		}




	}
	return 0;
}


// 지도와 사용자 위치 출력하는 함수
void displayMap(int map[][mapX], int user_x, int user_y) {
	for (int i = 0; i < mapY; i++) {
		//각 행이 바뀔때마다 보드의 테두리를 그린다. 
		cout << " --------------------------------- " << endl;
		cout << "|";
		for (int j = 0; j < mapX; j++) {
			if (i == user_y && j == user_x) {//해당좌표에 사용자가 있는경우 
				cout << " USER |"; // 양 옆 1칸 공백
			}
			else { //그외 동일하게 출력 
				int posState = map[i][j];
				switch (posState) {
				case 0:
					cout << "      |"; // 6칸 공백
					break;
				case 1:
					cout << "아이템|";
					break;
				case 2:
					cout << "  적  |"; // 양 옆 2칸 공백
					break;
				case 3:
					cout << " 포션 |"; // 양 옆 1칸 공백
					break;
				case 4:
					cout << "목적지|";
					break;
				}
			}
		}
		cout << endl;

	}
	cout << " ---------------------------------- " << endl;
}

// 이동하려는 곳이 유효한 좌표인지 체크하는 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY) {
	bool checkFlag = false;
	if (user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY) {
		checkFlag = true;
	}
	return checkFlag;
}

// 유저의 위치가 목적지인지 체크하는 함수
bool checkGoal(int map[][mapX], int user_x, int user_y) {
	// 목적지 도착하면
	if (map[user_y][user_x] == 4) {
		return true;
	}
	return false;
}

//현재 좌표의 상태를 나타내는 함수
void checkState(int map[][mapX], int user_x, int user_y) {
	int check = map[user_y][user_x];

	switch (check) {

	case 1:
		cout << "아이템이 있습니다" << endl;

		break;
	case 2:
		cout << "  적이 있습니다. HP가 2가 줄어듭니다." << endl;
		user_hp = user_hp - 2;
		break;
	case 3:
		cout << " 포션이 있습니다. HP가 2 늘어납니다." << endl;
		user_hp = user_hp + 2;
		break;
	}

}

//좌표이동결과를 출력 
void printMovement(int movementX, int movementY) {

	switch (10 * movementX + movementY) {
	case(-1): //상으로 한칸
		cout << "위로 한 칸 올라갑니다." << endl;
		break;
	case(1):///하로 한칸
		cout << "밑으로 한 칸 내려갑니다." << endl;
		break;
	case(-10): //좌로 한칸
		cout << "왼쪽으로 이동합니다." << endl;
		break;
	case(10): // 우로 한칸 
		cout << "오른쪽으로 이동합니다." << endl;
		break;
	}
}
