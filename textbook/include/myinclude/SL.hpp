// SL.hpp

#ifndef SL_HPP_
#define SL_HPP_

#define MaxSize 100

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define MAXSIZE 100

typedef struct stack {
	int coord[MAXSIZE][2];   //用于记录坐标数据
	int top,bottom;          //栈底和栈顶
}*st;


void init_stack(st s) {
	for (int i = 0; i < MAXSIZE; i++) {
		for (int j = 0; j < 2; j++) {
			s->coord[i][j] = 0;
		}
	}
	s->top= -1;
	s->bottom = -1;
}
//判断这个栈是否为空，如果为空返回0，不为空返回1
int empty(st s) {
	if (s->top == s->bottom)
		//这是一个空栈
		return 0;
	else
		//这不是一个空栈
		return 1;
}
//入栈
int push(st s,int x,int y) {
	s->top++;
	if (s->top == MAXSIZE) {
		//栈满，不可以在添加元素了
		s->top--;
		cout << "栈已经满了，不可以再将数据入栈";
		return 1;
	}
	s->coord[s->top][0] = x;
	s->coord[s->top][1] = y;
	return 0;
}
//出栈
int pop(st s,int b[2]) {
	b[0] = s->coord[s->top][0]; 
	b[1] = s->coord[s->top][1];
	s->top--;
	return 0;
}



class MineCleaner
{
private:
    int matrix[MaxSize][MaxSize];
    int matrix_probe[MaxSize][MaxSize];
    int size;
    int density;
    int score;

public:
    MineCleaner();
    MineCleaner(int size, int density);
    ~MineCleaner();
    void print_blank();
    void print_bottom();
    void print_col_info();
    void print_main_info(int x, int y);
    void print();
    void init_chessboard();
    void add_score();
    int get_x();
    int get_y();
    int get_size();
    int move();
    int move(int x, int y);
    void game_over_print();
    void uncover(int x, int y);
    int if_win();
    void win_print();
    int get_matrix(int x, int y);
    int get_matrix_probe(int x, int y);
};

#endif