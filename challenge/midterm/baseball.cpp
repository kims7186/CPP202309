#include <iostream>
#include <string>
using namespace std;

int main() {
  int randomNum;  // ����� �ϴ� 3�ڸ����� ���� ���� ����
  int firstNum;   // ������ ù��° �ڸ���
  int secondNum;  // ������ �ι�° �ڸ���
  int thirdNum;   // ������ ����° �ڸ���

  while (1) {
    randomNum = rand() % 900 + 100;  // ������ 3�ڸ��� ����

    bool same = false;  // ��� ���� �ٸ� ��� true�� ���� ����

    // TODO 1: 3�ڸ� ������ �ڸ����� �����ϰ�, ��� ���� �ٸ��� üũ�ϴ�
    // �ڵ��� �ۼ�

    if (same == true) {
      break;
    }
  }

  int turn = 0;
  while (1) {
    cout << turn + 1 << "��° �õ��Դϴ�. " << endl;

    int userNumber;   // ����ڰ� �Է��� ���ڸ��� ���� ����
    int guessFirst;   // ������ ������ ù��° �ڸ���
    int guessSecond;  // ������ ������ �ι�° �ڸ���
    int guessThird;   // ������ ������ ����° �ڸ���

    // ����ڿ��� ���ڸ� ���� �Է¹޴� �ڵ� ���
    while (1) {
      cout << "���ڸ� ���� �Է����ּ���: ";
      cin >> userNumber;

      bool same = false;  // ��� ���� �ٸ� ��� true�� ���� ����
      // TODO 1: 3�ڸ� ������ �ڸ����� �����ϰ�, ��� ���� �ٸ��� üũ�ϴ�
      // �ڵ��� �ۼ�

      if (to_string(userNumber).length() != 3) {
        cout << "�Էµ� ���ڰ� 3�ڸ� ���� �ƴմϴ�. �ٽ� �Է��ϼ���." << endl;
        continue;
      }

      if (same == true) {
        break;
      }
    }

    int strike = 0;  // ��Ʈ����ũ ������ �����ϴ� ����
    int ball = 0;    // �� ������ �����ϴ� ����

    // TODO 2: ����� ������ ������ �ڸ����� ���ڸ� ���ϸ� ��Ʈ�� �ֱ� ����
    // �ڵ��� �ۼ�

    cout << userNumber << "�� ��� : " << strike << " ��Ʈ����ũ, " << ball
         << "�� �Դϴ�." << endl;

    if (strike == 3) {
      cout << "������ ������ϴ�. �����մϴ�.";
      break;
    }

    turn += 1;
  }

  return 0;
}
