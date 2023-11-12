#include <iostream>
using namespace std;
const int numCell = 5;           // �������� ���� ���� ����
char board[numCell][numCell]{};  // �������� ��Ÿ���� 2���� �迭

bool isValid(int x, int y) {
  bool result = true;
  if (x >= numCell || y >= numCell) {  // ��ǥ ������ �����
    cout << x << "," << y << ": x�� y���� �ϳ��� ĭ�� ����ϴ�. " << endl;
    result = false;
    return result;
  }
  if (board[x][y] != ' ') {  // ��ǥ������ �Է°��� �ߺ��ɶ�
    cout << x << "," << y << ": �̹� ���� ���ֽ��ϴ�. " << endl;
    result = false;
    return result;
  }
  return result;
}
bool checkWin(char currentUser) {
  bool isWin = false;
  // TODO FUNC2: 6.1���� 6.2���� checkWin �Լ� ���� �� ȣ��
  // 6.1. ����/���� �� üũ�ϱ�
  for (int i = 0; i < numCell; i++) {
    for (int j = 0; j < numCell; j++) {
      if (board[i][j] != currentUser) {
        break;
      }
      if (j == numCell - 1) {
        cout << "���ο� ��� ���� �������ϴ�!!";
        isWin = true;
        return isWin;
      }
    }
    for (int j = 0; j < numCell; j++) {
      if (board[j][i] != currentUser) {
        break;
      }
      if (j == numCell - 1) {
        cout << "���ο� ��� ���� �������ϴ�!!";
        isWin = true;
        return isWin;
      }
    }
  }
  // TODO 1.3: numCell�� ���� �밢�� ���� üũ �ڵ�� Ȯ��
  // HINT: for ��
  bool leftToRightDiagonalWin = true;
  for (int i = 0; i < numCell; i++) {
    if (board[i][i] != currentUser) {
      leftToRightDiagonalWin = false;
      break;
    }
  }
  if (leftToRightDiagonalWin) {
    cout << "���� ������ ������ �Ʒ� �밢������ ��� ���� �������ϴ�!" << endl;
    isWin = true;
    return isWin;
  }

  // ������ ������ ���� �Ʒ� �밢�� üũ
  bool rightToLeftDiagonalWin = true;
  for (int i = 0; i < numCell; i++) {
    if (board[i][numCell - 1 - i] != currentUser) {
      rightToLeftDiagonalWin = false;
      break;
    }
  }
  if (rightToLeftDiagonalWin) {
    cout << "������ ������ ���� �Ʒ� �밢������ ��� ���� �������ϴ�!" << endl;
    isWin = true;
    return isWin;
  }
  return isWin;
}
int main() {
  // ������ �����ϴ� �� �ʿ��� ���� ����
  int k = 0;               // ���� �������� üũ�ϱ� ���� ����
  char currentUser = 'X';  // ���� ������ ���� �����ϱ� ���� ����
  int x = 0;
  int y = 0;  // ����ڿ��� xy��ǥ���� �Է¹ޱ� ���� ����

  // ������ �ʱ�ȭ
  for (int i = 0; i < numCell; i++) {
    for (int j = 0; j < numCell; j++) {
      board[i][j] = ' ';
    }
  }

  // ������ ���� �ݺ�
  while (true) {
    // 1. ���� �������� ���
    // TODO 1.1: 3�ο� �������� ����
    switch (k % 3) {
      case 0:
        currentUser = 'X';
        break;
      case 1:
        currentUser = 'O';
        break;
      case 2:
        currentUser = 'H';
        break;
    }
    cout << k % 3 + 1 << "�� ����(" << currentUser << ")�� �����Դϴ�. -> ";

    // 2. ��ǥ �Է� �ޱ�
    cout << "(x, y) ��ǥ�� �Է��ϼ���: ";
    int x, y;
    cin >> x >> y;

    // 3. �Է¹��� ��ǥ�� ��ȿ�� üũ
    // TODO FUNC 1: isValid �Լ� ���� �� ȣ��
    if (!isValid(x, y)) {
      continue;
    }

    // 4. �Է¹��� ��ǥ�� ���� ������ �� ����
    board[x][y] = currentUser;

    // 5. ���� ���� �� ���
    // TODO 1.2: numCell ���ڿ� ���� ������ ���
    for (int i = 0; i < numCell; i++) {
      for (int j = 0; j < numCell; j++) {
        cout << "---";
        if (j == numCell - 1) {
          cout << endl;
          break;
        } else {
          cout << "|";
        }
      }
      for (int j = 0; j < numCell; j++) {
        cout << board[i][j];
        if (j == numCell - 1) {
          break;
        }
        cout << "  |";
      }
      cout << endl;
    }
    for (int j = 0; j < numCell; j++) {
      cout << "---";
      if (j == numCell - 1) {
        cout << endl;
        break;
      } else {
        cout << "|";
      }
    }

    bool isWin = false;  // �¸� ����
    // TODO FUNC2: 6.1���� 6.2���� checkWin �Լ� ���� �� ȣ��
    // 6.1. ����/���� �� üũ�ϱ�
    // 6.2. �밢���� üũ�ϱ�
    // TODO 1.3: numCell�� ���� �밢�� ���� üũ �ڵ�� Ȯ��
    // HINT: for ��
    isWin = checkWin(currentUser);  //����/����, �밢�� ���ڸ� ����

    // �¸��ڰ� �����Ǿ����� �ش� �÷��̾ ����ϰ� ������ �����Ѵ�.
    if (isWin == true) {
      cout << k % 3 + 1 << "�� ����(" << currentUser << ")�� �¸��Դϴ�!"
           << endl;
      break;
    }

    // 7. ��� ĭ �� á���� üũ�ϱ�
    int checked = 0;
    for (int i = 0; i < numCell; i++) {
      for (int j = 0; j < numCell; j++) {
        if (board[i][j] == ' ') {
          checked++;
        }
      }
    }
    if (checked == 0) {
      cout << "��� ĭ�� �� á���ϴ�.  �����մϴ�. " << endl;
      break;
    }

    k++;
  }

  return 0;
}