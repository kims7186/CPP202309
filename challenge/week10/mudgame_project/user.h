#pragma once

#include <iostream>
#include "user.h"
using namespace std;

class User {
 public:
  int hp; // ���� ü�� 
  void DecreaseHP(int dec_hp);
  void IncreaseHP(int inc_hp);
  int GetHP();

};
