#include "Block.h"
#include <utility>
#include <string>

//생성자
Block::Block()
{
    MYColor = static_cast<Color>(get_color()); //타입캐스팅
}

std::string Block::toString()
{
    switch (MYColor)
    {
    case BLANK:
        return "·";
        break;
    case GRAY:
        return "■";
        break;
    case RED:
        return "\033[31m■\033[0m";
        break;
    case GREEN:
        return "\033[32m■\033[0m";
        break;
    case BLUE:
        return "\033[34m■\033[0m";
        break;
    }
}

int Block::get_color()
{
    //std::srand((unsigned int)time(0));
    //1부터 4까지의 난수
    random = rand() % 3 + 1;
    return random;
}

