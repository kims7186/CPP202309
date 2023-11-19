#pragma once

#include <iostream>

#include "user.h"
using namespace std;

class User {
 private:
  int hp;  // 유저 체력
 public:
  void DecreaseHP(int dec_hp);
  void IncreaseHP(int inc_hp);
  int GetHP();
  User();
};
