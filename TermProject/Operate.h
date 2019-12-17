#ifndef OPERATE_H
#define OPERATE_H
#include <utility>
#include <string>
#include <iostream>
#include "Block.h"
#include <cstdlib>


class Operate : public Block
{
private:
    int recentX;
    int recentY;

    //각각의 좌표 표현
    int min_x;
    int min_y;
    int max_x;
    int max_y;

public:
  
    Color MyBlock;
    Color CheckBolck;
    Block ***window; //판 생성하기
    //실질적인 동작
    Operate();

    void setting();
    int explosion();
    void set(int x, int y);
    void deletes(int x, int y);
    void moves(int x, int y);
    bool checking();

    //move
    bool move(int x, int y);
    void rotaion();

    bool positionCheck(int x, int y);

    void print();
    bool isExplode();
    
};

#endif // OPERATE_H