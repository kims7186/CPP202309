#include <iostream>
using namespace std;

int main() {
	const int numCell = 3; // 보드판 한 행이나 열의 칸의 개수 
	char board[numCell][numCell]{}; //3*3의 보드판 2차워너 배열 
	int x, y; //사용자에게 입력받는 x,y좌표를 저장할 변수 선언 

	//보드판 초기화
	//반복문을 (x,y)값을 ' ' 으로 초기화 하여 보드판을 초기화 한다.  
	for (x = 0; x < numCell; x++) {
		for (y = 0; y < numCell; y++) {
			board[x][y] = ' ';
		}
	}

	//게임하는 코드
	int k = 0; //차례를 체크하기 위한 변수
	char currentUser = 'x'; //현재 유저의 돌을 저장하기 위한 문자변수. 1번 유저차례가 먼저이므로 'x' 초기화 
	while (true) {
		//1. 누구의 차례인지 출력
		// switch문과 나눗셈 연산을  이용하여 차례를 계산 하고 출력한다. 
		switch (k % 2) {
		case 0:
			cout << k % 2 + 1 << "번 유저(X)의 차례입니다 ->"; // 첫 번째 유저의 차례인 경우 출력
			currentUser = 'x';
			break;
		case 1:
			cout << k % 2 + 1 << "번 유저(0)의 차례입니다 ->"; // 두 번째 유저의 차례인 경우 출력 
			currentUser = 'o';
			break;
		}

		//2. 좌표 입력 받기
		cout << " (x,y)좌표를 입력하세요: ";
		cin >> x >> y; // 공백으로 구분되어 입력받은 좌표(x,y)값을 각각의 변수에 저장한다. 

		//3. 입력받은 좌표의 유효성 체크

		//3-1 .입력 받은 좌표가 칸을 벗어나는것은 아닌지 체크 		
		if (x >= numCell || y >= numCell) {
			cout << x << ", " << y << ": ";
			cout << " x와 y 둘 중 하나가 칸을 벗어납니다." << endl; // 오류 메시지 출력
			continue; // (x,y)좌표 다시 입력 받기 
		}
		//3-2. 입력 받은 좌표에 돌이 차있는지 체크 
		if (board[x][y] != ' ') {
			cout << x << ", " << y << ": 이미 돌이 차있습니다." << endl; // 오류 메시지 출력
			continue; //(x,y)whkvy 다시 입력 받기 
		}

		//4. 입력받은 좌표에 현재 유저의 돌 놓기(유효성 검사 통과)
		board[x][y] = currentUser;// 보드판에 현재 유저의 착수를 'x' 또는 'o"로 표기 

		//5. 현재 보드 판 출력
		//보드판 업데이트가 완료되면 결과를 출력한다.
		// 2중 반복문을 이용하여 보드판의 테두리를 적절히 표기한다. 
		for (int i = 0; i < numCell; i++) {
			cout << "---|---|---" << endl;
			for (int j = 0; j < numCell; j++) {
				cout << board[i][j];
				if (j == numCell - 1) {
					break;
				}
				cout << "  |";
			}
			cout << endl;
		}
		cout << "---|---|---" << endl;
		k++;

		//6. 모든 칸이 다 찼는지 체크 
		int checked = 0; // 보드판이 다 찼는지 여부를 체크하는 변수 
		for (int i = 0; i < numCell; i++) {
			for (int j = 0; j < numCell; j++) {
				if (board[i][j] == ' ') { //빈칸이 있는경우  체크변수+1 
					checked++;
				}
			}
		}
		if (checked == 0) { // 빈칸이 없는경우 게임 종료 
			cout << "모든 칸이 다  찼습니다. 종료합니다. " << endl;
			break; // 더이상 사용자의 입력을 받지 않음 
		}

		// 7. 빙고 승자 출력 후 종료(가로, 세로,대각선)
		//반복문을 통해 보드를 탐색하고, 만약 각 승리조건을 만족하는 경우  승자 출력후 게임종료 
		bool isWin = false;// 경기 결과를 저장하는 변수. 승자가 정해진경우 true, 승자가 없는경우 false(default)

		// 7.1. 가로/세로돌 체크하기
		for (int i = 0; i < numCell; i++) {
			if (board[i][0] == currentUser && board[i][1] == currentUser && board[i][2] == currentUser) {
				cout << " 가로에 모두 돌이 놓였습니다!: "; 
				isWin = true; // 승자 정하기 (가로)
			}
			if(board[0][i] == currentUser && board[1][i]==currentUser && board[3][i] == currentUser){
				cout << " 세로에 모두 돌이 놓였습니다!: ";
				isWin = true; // 승자 정하기 (세로)
			}
		}

		// 7.2 대각선돌 체크하기 
		if (board[0][0] == currentUser && board[1][1] == currentUser && board[2][2] == currentUser) {
			cout << " 왼쪽 위에서 오른쪽 아래 대각선으로 모두 돌이 놓였습니다!: ";
			isWin = true; //승자정하기 (대각선)
		}
		if (board[0][0] == currentUser && board[1][1] == currentUser && board[2][2] == currentUser) {
			cout << "오른쪽 위에서 왼쪽 아래 대각선으로 모두 돌이 놓였습니다!";
			isWin = true;//승자정하기 (대각선) 
		}

		//승자를 출력하기
		if (isWin == true ) {
			cout << k%2+1 <<" 번 유저("<< currentUser<<")의 승리입니다!"<<endl;
			cout << "종료합니다." << endl;
			break; // 더이상 사용자의 입력을 받지 않음

		}

	}
	return 0;

}