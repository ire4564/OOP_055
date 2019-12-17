#ifndef MANAGER_H
#define MANAGER_H
#include "Operate.h"

class Manager : public Operate
{
private:
  int index;
  int blockState;

public:
  Manager();
  //  ~Manager();

  struct Position
  {
    int x = -1;
    int y = -1;
  };

  Position pos1, pos2, pos3, pos4, pos5, none;
  Position array[5];
  int randoms;

  void firstMake();
  void FirstSet();
  void Fold();
  void Tree();
  void Cross();
  void update();
  int get_shape();

  void left();
  void right();
  void down();
  void down_all();
  void moving();

  //check
  bool can_left(int x);
  bool can_right(int x);
  bool can_down(int x, int y);

  static bool cmp_left(const Position &p1, const Position &p2);
  static bool cmp_right(const Position &p1, const Position &p2);
  void print();
  void gameover();
};

#endif