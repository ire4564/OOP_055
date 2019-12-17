#ifndef BLOCK_H
#define BLOCK_H
#include <cstdlib>
#include <ctime>
#include <string>

class Block
{
public:
    enum Color 
    {
        BLANK,
        GRAY,
        RED,
        GREEN,
        BLUE
    };

    int ***block; //블럭으로 쓸 배열
    int color[5];
    int shape;
    int random;
    Color MYColor;

    Block();

    int get_color();
    std::string toString();
};

#endif