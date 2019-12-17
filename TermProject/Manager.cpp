#include "Manager.h"
#include "getch.h"
#include <algorithm>

Operate opr;

Manager::Manager()
{
}

void Manager::firstMake()
{
    opr.setting();
    FirstSet();
}

void Manager::FirstSet()
{
    int isShape = get_shape();
    blockState = isShape; //현재 블록 상태
    switch (isShape)
    {
    case 1: //fold
        Fold();
        gameover();
        break;
    case 2: //tree
        Tree();
        gameover();
        break;
    case 3: //cross
        Cross();
        gameover();
        break;
    default: //cross
        Cross();
        gameover();
        break;
    }

    index = 0;
    while (array[index].x != -1)
    {
        if (index == 4)
        {
            opr.set(array[index].x, array[index].y);
            break;
        }
        //std::cout << array[index].y << std::endl;
        opr.set(array[index].x, array[index].y);
        index++;
    }
    opr.print();
}

/********블럭 생성하기*********/
void Manager::Fold()
{

    pos1.x = 1;
    pos1.y = 2;

    pos2.x = 1;
    pos2.y = 1;

    pos3.x = 0;
    pos3.y = 2;

    array[0] = pos1;
    array[1] = pos2;
    array[2] = pos3;
    array[3] = none;
    array[4] = none;
}
void Manager::Tree()
{

    pos1.x = 2;
    pos1.y = 2;

    pos2.x = 1;
    pos2.y = 2;

    pos3.x = 0;
    pos3.y = 2;

    array[0] = pos1;
    array[1] = pos2;
    array[2] = pos3;
    array[3] = none;
    array[4] = none;
}
void Manager::Cross()
{

    pos1.x = 2;
    pos1.y = 2;

    pos2.x = 1;
    pos2.y = 3;

    pos3.x = 1;
    pos3.y = 2;

    pos4.x = 1;
    pos4.y = 1;

    pos5.x = 0;
    pos5.y = 2;

    array[0] = pos1;
    array[1] = pos2;
    array[2] = pos3;
    array[3] = pos4;
    array[4] = pos5;
}

void Manager::update()
{
    index = 0;
    //작은 순대로 소트해서 밑에 체크하기
    std::sort(array, array + 5, cmp_right);
    while (index != 5)
    {
        if (array[index].x != -1 && array[index].x != 11)
        {
            bool check = opr.move(array[index].x, array[index].y);
            //밑에가 공백이면
            if (check == true)
            {
                //밑으로 계속 내리기
                while (true)
                {
                    if (array[index].x == 11)
                    {
                        break;
                    }
                    if (array[index].x != 11)
                    {
                        bool checks = opr.move(array[index].x, array[index].y);
                        if (checks == false)
                        {
                            break;
                        }
                        else
                        {
                            opr.deletes(array[index].x, array[index].y);
                            array[index].x++;
                            opr.moves(array[index].x, array[index].y);
                        }
                    }
                }
            }
        }
        index++;
    }
}

int Manager::get_shape()
{
    //1부터 3까지의 난수
    // 1: flod , 2: tree , 3:cross
    randoms = rand() % 3 + 1;
    return randoms;
}

//오른쪽으로 이동, y좌표를 +1
//왼쪽으로 이동, y좌표를 -1
//아래로 이동, x 좌표를 +1

bool Manager::cmp_left(const Position &p1, const Position &p2)
{
    if (p1.y < p2.y)
    {
        return true;
    }
    //x 순으로 정렬하고 x값이 값으면 y순으로 오름차순 정렬
    else if (p1.y == p2.y)
    {
        return p1.x < p2.x;
    }
    else
    {
        return false;
    }
}

bool Manager::cmp_right(const Position &p1, const Position &p2)
{
    if (p1.y > p2.y)
    {
        return true;
    }
    //x 순으로 정렬하고 x값이 값으면 y순으로 오름차순 정렬
    else if (p1.y == p2.y)
    {
        return p1.x > p2.x;
    }
    else
    {
        return false;
    }
}

void Manager::print()
{
    std::cout << "print()" << std::endl;
    index = 0;
    while (array[index].x != -1)
    {
        if (index == 5)
        {
            break;
        }
        else if (array[index].x != -1)
        {
            std::cout << array[index].y << std::endl;
            std::cout << array[index].x + "position 출력 " + array[index].y << std::endl;
            index++;
        }
    }
}

void Manager::moving()
{
    while (true)
    {
        //키보드 입력 처리
        int c = getch();
        // std::cout << c << std::endl;
        if (c == 's')
        {
            down();
            system("clear");
            opr.print();
        }
        else if (c == 'a')
        {
            left();
            system("clear");
            opr.print();
        }
        else if (c == 'd')
        {
            right();
            system("clear");
            opr.print();
        }
    }
    //A: 97 -> left
    //W: 119 -> all down
    //D: 100 -> right
    //S: 115 -> down
}
void Manager::left()
{
    index = 0;
    std::sort(array, array + 5, cmp_left);
    while (index != 5)
    {
        if (array[index].x != -1)
        {
            //std::cout << "left index 값 : " << array[index].y << std::endl;
            if (can_left(array[index].y) == false)
            {
                break;
            }
            else
            {
                opr.deletes(array[index].x, array[index].y);
                array[index].y--;
                opr.moves(array[index].x, array[index].y);
            }
        }
        index++;
    }
}
void Manager::right()
{
    index = 0;
    std::sort(array, array + 5, cmp_right);

    while (index != 5)
    {
        if (array[index].x != -1)
        {
            //std::cout << "right index 값 : " << array[index].y << std::endl;
            if (can_right(array[index].y) == false)
            {
                break;
            }
            else
            {
                opr.deletes(array[index].x, array[index].y);
                array[index].y++;
                opr.moves(array[index].x, array[index].y);
            }
        }
        index++;
    }
}
void Manager::down()
{
    index = 0;
    std::sort(array, array + 5, cmp_right);
    while (index != 5)
    {
        if (array[index].x != -1)
        {
            //std::cout << "down index 값 : " << array[index].x << std::endl;
            if (can_down(array[index].x, array[index].y) == false)
            {
                update();
                FirstSet();
            }
            else
            {
                opr.deletes(array[index].x, array[index].y);
                array[index].x++;
                opr.moves(array[index].x, array[index].y);
            }
        }
        index++;
    }
}
void Manager::down_all()
{
}

/*********체크하기 동작*********/
bool Manager::can_left(int x)
{
    if (x == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}
bool Manager::can_right(int x)
{
    if (x == 4)
    {
        return false;
    }
    else
    {
        return true;
    }
}
bool Manager::can_down(int x, int y)
{
    if (x == 11)
    {
        return false;
    }
    else if (opr.move(x, y) == false)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void Manager::gameover()
{
    index = 0;
    //1: fold 2: tree 3:cross 4:cross

    while (index != 5)
    {
        if (array[index].x != -1)
        {
            bool checkThis = opr.positionCheck(array[index].x, array[index].y);
            if (checkThis == false)
            {
                std::cout << "GAME OVER" << std::endl;
                exit(0);
            }
        }
        index++;
    }
}