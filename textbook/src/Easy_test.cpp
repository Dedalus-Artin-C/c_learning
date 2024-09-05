#include <graphics.h>
#include <conio.h>
#include <time.h>
#include<iostream>
#include <windows.h>

#define MAXSTAR 2000 // 星星总数



struct STAR
{
    double x;
    int y;
    double step;
    int color;
};

STAR star[MAXSTAR];

// 初始化星星
void InitStar(int i)
{
    star[i].x = rand() % 1920;
    star[i].y = rand() % 1080;
    star[i].step = (rand() % 20000) / 1000.0 + 1;
    star[i].color = (int)(star[i].step * 255 / 6.0 + 0.5); // 速度越快，颜色越亮
    star[i].color = RGB(star[i].color, star[i].color, star[i].color);
}

// 移动星星
void MoveStar(int i)
{
    // 擦掉原来的星星
    putpixel((int)star[i].x, star[i].y, 0);

    // 计算新位置
    star[i].x += star[i].step;
    if (star[i].x > 1920)
        InitStar(i);

    // 画新星星
    putpixel((int)star[i].x, star[i].y, star[i].color);
}


// 主函数
int main()
{  
    SetConsoleOutputCP(CP_UTF8);
    std::cout << "你好";
    srand((unsigned)time(NULL)); // 随机种子
    initgraph(1920, 1080);         // 创建绘图窗口
    // 初始化所有星星
    for (int i = 0; i < MAXSTAR; i++)
    {
        InitStar(i);
        star[i].x = rand() % 1920;
    }

	settextcolor(RGB(255, 255, 255));
    LOGFONT str;
    gettextstyle(&str);
    str.lfHeight = 50;
    _tcscpy_s(str.lfFaceName, _T("宋体"));
    str.lfWeight = FW_BOLD;
    settextstyle(&str);
    TCHAR str_D[] = _T("Dedalus你好");
	outtextxy((1920/2-100),(1080/2), str_D);


    // 绘制星空，按任意键退出
    while (!_kbhit())
    {
        for (int i = 0; i < MAXSTAR; i++)
            MoveStar(i);
        Sleep(20);
    }
    closegraph(); // 关闭绘图窗口
    return 0;
}

