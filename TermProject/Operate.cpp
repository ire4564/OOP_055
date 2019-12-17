//시스템 콜
//system("clear");
#include "Operate.h"
#include "Manager.h"

Operate::Operate()
{
}

void Operate::setting()
{
    window = new Block **[12]; //포인터 생성
    for (int i = 0; i < 12; i++)
    {
        window[i] = new Block *[12];
        for (int j = 0; j < 5; j++)
        {
            window[i][j] = new Block();
            window[i][j]->MYColor = Block::BLANK;
        }
    }
}

/*********동작 실행*********/
void Operate::print()
{
    int score = 0;
    std::cout << "score : 0" << std::endl;
    for (int i = 0; i < 12; i++)
    {
        for (int k = 0; k < 5; k++)
        {
            std::cout << window[i][k]->toString() << "  ";
        }
        std::cout << std::endl;
    }
}
//블럭 생성하기
void Operate::set(int x, int y)
{
    window[x][y] = new Block();
}
//블럭 없애기
void Operate::deletes(int x, int y)
{
    MyBlock = window[x][y]->MYColor;
    window[x][y]->MYColor = Block::BLANK;
}
//블럭 옮기기
void Operate::moves(int x, int y)
{
    window[x][y]->MYColor = MyBlock;
}
bool Operate::isExplode()
{
}

/*********실질적인 동작*********/
int Operate::explosion()
{
}

bool Operate::checking()
{
    return true;
}

/*********움직이는 동작*********/

bool Operate::move(int x, int y)
{
    CheckBolck = window[x + 1][y]->MYColor;
    if (CheckBolck != BLANK)
    {
        //빈공간이 아니면 움직일 중 없으므로
        return false;
    }
    else
    {
        return true;
    }
}
void Operate::rotaion()
{
}

/*********좌표 가지고 오기*********/
bool Operate::positionCheck(int x, int y)
{
    CheckBolck = window[x][y]->MYColor;
    if (CheckBolck != BLANK)
    {
        //빈공간이 아니면 움직일 중 없으므로
        return false;
    }
    else
    {
        return true;
    }
}
