#include <iostream>
#include <string>
#include <vector>  //동적배열 사용하기 위함
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
  // 초기화 되지 않으면 배열 선언이 안되므로 상수로 초기화

  cout << "총 고객의 수를 입력하라 : ";
  cin >> max_people;

  // 동적 배열 선언
  vector<Person> people;

  //변수 선언
  string name;
  int age;

  // 반복문과 입출력문을 혼합하여 배열에 사람 1~3의 정보를 입력받는다.
  for (int i = 0; i < max_people; i++) {
    cout << "사람" << i + 1 << "의 이름 : ";
    cin >> name;
    cout << "사람" << i + 1 << "의 나이 : ";
    cin >> age;

    people.push_back(Person(name, age));
  }

  int age_threshold;  // 문제에서 정의한 사람의 특정 나이
  cout << "특정 나이 이상인 사람을 찾으려면 나이를 입력하세요 : ";

  cin >> age_threshold;  // 특정 나이 입력받음
  cout << age_threshold << "세 이상인 고객들: \n";

  //조건을 충족하는 사람의 수를 입력받는 변수 선언
  int count = 0;

  //반복문을 통해 조건을 충족하는 사람의 수를 카운트
  for (int i = 0; i < people.size(); i++) {
    if (people[i].age >= age_threshold) {
      count++;
    }
  }

  //카운트가 0보다 큰경우 해당하는 사람들의 이름과 나이를 출력
  //카운트가 없는경우 특정 나이보다 많은 고객이 없는 메시지를 출력한다.
  if (count > 0) {
    for (int i = 0; i < count; i++) {
      if (people[i].age >= age_threshold) {
        cout << people[i].name << " (" << people[i].age << "세) " << endl;
      }
    }
  } else {
    cout << age_threshold << "이상의 나이를 가진 고객이 없습니다.";
  }
}
