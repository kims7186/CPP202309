#include <iostream>
using namespace std;

int main() {
	const int numCell = 3; // ������ �� ���̳� ���� ĭ�� ���� 
	char board[numCell][numCell]{}; //3*3�� ������ 2������ �迭 
	int x, y; //����ڿ��� �Է¹޴� x,y��ǥ�� ������ ���� ���� 

	//������ �ʱ�ȭ
	//�ݺ����� (x,y)���� ' ' ���� �ʱ�ȭ �Ͽ� �������� �ʱ�ȭ �Ѵ�.  
	for (x = 0; x < numCell; x++) {
		for (y = 0; y < numCell; y++) {
			board[x][y] = ' ';
		}
	}

	//�����ϴ� �ڵ�
	int k = 0; //���ʸ� üũ�ϱ� ���� ����
	char currentUser = 'x'; //���� ������ ���� �����ϱ� ���� ���ں���. 1�� �������ʰ� �����̹Ƿ� 'x' �ʱ�ȭ 
	while (true) {
		//1. ������ �������� ���
		// switch���� ������ ������  �̿��Ͽ� ���ʸ� ��� �ϰ� ����Ѵ�. 
		switch (k % 2) {
		case 0:
			cout << k % 2 + 1 << "�� ����(X)�� �����Դϴ� ->"; // ù ��° ������ ������ ��� ���
			currentUser = 'x';
			break;
		case 1:
			cout << k % 2 + 1 << "�� ����(0)�� �����Դϴ� ->"; // �� ��° ������ ������ ��� ��� 
			currentUser = 'o';
			break;
		}

		//2. ��ǥ �Է� �ޱ�
		cout << " (x,y)��ǥ�� �Է��ϼ���: ";
		cin >> x >> y; // �������� ���еǾ� �Է¹��� ��ǥ(x,y)���� ������ ������ �����Ѵ�. 

		//3. �Է¹��� ��ǥ�� ��ȿ�� üũ

		//3-1 .�Է� ���� ��ǥ�� ĭ�� ����°��� �ƴ��� üũ 		
		if (x >= numCell || y >= numCell) {
			cout << x << ", " << y << ": ";
			cout << " x�� y �� �� �ϳ��� ĭ�� ����ϴ�." << endl; // ���� �޽��� ���
			continue; // (x,y)��ǥ �ٽ� �Է� �ޱ� 
		}
		//3-2. �Է� ���� ��ǥ�� ���� ���ִ��� üũ 
		if (board[x][y] != ' ') {
			cout << x << ", " << y << ": �̹� ���� ���ֽ��ϴ�." << endl; // ���� �޽��� ���
			continue; //(x,y)whkvy �ٽ� �Է� �ޱ� 
		}

		//4. �Է¹��� ��ǥ�� ���� ������ �� ����(��ȿ�� �˻� ���)
		board[x][y] = currentUser;// �����ǿ� ���� ������ ������ 'x' �Ǵ� 'o"�� ǥ�� 

		//5. ���� ���� �� ���
		//������ ������Ʈ�� �Ϸ�Ǹ� ����� ����Ѵ�.
		// 2�� �ݺ����� �̿��Ͽ� �������� �׵θ��� ������ ǥ���Ѵ�. 
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

		//6. ��� ĭ�� �� á���� üũ 
		int checked = 0; // �������� �� á���� ���θ� üũ�ϴ� ���� 
		for (int i = 0; i < numCell; i++) {
			for (int j = 0; j < numCell; j++) {
				if (board[i][j] == ' ') { //��ĭ�� �ִ°��  üũ����+1 
					checked++;
				}
			}
		}
		if (checked == 0) { // ��ĭ�� ���°�� ���� ���� 
			cout << "��� ĭ�� ��  á���ϴ�. �����մϴ�. " << endl;
			break; // ���̻� ������� �Է��� ���� ���� 
		}

		// 7. ���� ���� ��� �� ����(����, ����,�밢��)
		//�ݺ����� ���� ���带 Ž���ϰ�, ���� �� �¸������� �����ϴ� ���  ���� ����� �������� 
		bool isWin = false;// ��� ����� �����ϴ� ����. ���ڰ� ��������� true, ���ڰ� ���°�� false(default)

		// 7.1. ����/���ε� üũ�ϱ�
		for (int i = 0; i < numCell; i++) {
			if (board[i][0] == currentUser && board[i][1] == currentUser && board[i][2] == currentUser) {
				cout << " ���ο� ��� ���� �������ϴ�!: "; 
				isWin = true; // ���� ���ϱ� (����)
			}
			if(board[0][i] == currentUser && board[1][i]==currentUser && board[3][i] == currentUser){
				cout << " ���ο� ��� ���� �������ϴ�!: ";
				isWin = true; // ���� ���ϱ� (����)
			}
		}

		// 7.2 �밢���� üũ�ϱ� 
		if (board[0][0] == currentUser && board[1][1] == currentUser && board[2][2] == currentUser) {
			cout << " ���� ������ ������ �Ʒ� �밢������ ��� ���� �������ϴ�!: ";
			isWin = true; //�������ϱ� (�밢��)
		}
		if (board[0][0] == currentUser && board[1][1] == currentUser && board[2][2] == currentUser) {
			cout << "������ ������ ���� �Ʒ� �밢������ ��� ���� �������ϴ�!";
			isWin = true;//�������ϱ� (�밢��) 
		}

		//���ڸ� ����ϱ�
		if (isWin == true ) {
			cout << k%2+1 <<" �� ����("<< currentUser<<")�� �¸��Դϴ�!"<<endl;
			cout << "�����մϴ�." << endl;
			break; // ���̻� ������� �Է��� ���� ����

		}

	}
	return 0;

}