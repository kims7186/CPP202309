#include "user.h"
User::User() { this->hp = 20; };
void User::DecreaseHP(int dec_hp) { hp = hp - dec_hp; }
void User::IncreaseHP(int inc_hp) { hp = hp + inc_hp; }
int User::GetHP() { return hp; }