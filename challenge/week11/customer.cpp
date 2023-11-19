#include <iostream>
#include <string>
#include <vector>  //�����迭 ����ϱ� ����
using namespace std;

class Person {
 public:
  string name;
  int age;
  Person(string name, int age) {
    this->name = name;
    this->age = age;
  }
};
int main() {
  int max_people;
  // �ʱ�ȭ ���� ������ �迭 ������ �ȵǹǷ� ����� �ʱ�ȭ

  cout << "�� ���� ���� �Է��϶� : ";
  cin >> max_people;

  // ���� �迭 ����
  vector<Person> people;

  //���� ����
  string name;
  int age;

  // �ݺ����� ����¹��� ȥ���Ͽ� �迭�� ��� 1~3�� ������ �Է¹޴´�.
  for (int i = 0; i < max_people; i++) {
    cout << "���" << i + 1 << "�� �̸� : ";
    cin >> name;
    cout << "���" << i + 1 << "�� ���� : ";
    cin >> age;

    people.push_back(Person(name, age));
  }

  int age_threshold;  // �������� ������ ����� Ư�� ����
  cout << "Ư�� ���� �̻��� ����� ã������ ���̸� �Է��ϼ��� : ";

  cin >> age_threshold;  // Ư�� ���� �Է¹���
  cout << age_threshold << "�� �̻��� ����: \n";

  //������ �����ϴ� ����� ���� �Է¹޴� ���� ����
  int count = 0;

  //�ݺ����� ���� ������ �����ϴ� ����� ���� ī��Ʈ
  for (int i = 0; i < people.size(); i++) {
    if (people[i].age >= age_threshold) {
      count++;
    }
  }

  //ī��Ʈ�� 0���� ū��� �ش��ϴ� ������� �̸��� ���̸� ���
  //ī��Ʈ�� ���°�� Ư�� ���̺��� ���� ���� ���� �޽����� ����Ѵ�.
  if (count > 0) {
    for (int i = 0; i < count; i++) {
      if (people[i].age >= age_threshold) {
        cout << people[i].name << " (" << people[i].age << "��) " << endl;
      }
    }
  } else {
    cout << age_threshold << "�̻��� ���̸� ���� ���� �����ϴ�.";
  }
}
