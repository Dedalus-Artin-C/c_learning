// A function that implements the MineCleaner function

#include <SL.hpp>
#include <iostream>
#include <time.h> 

using namespace std;
MineCleaner::MineCleaner()
{
    cout << L"请问是否指定棋盘大小，如果不指定大小的话，那么棋盘将会是默认大小10*10？[y/n] " << endl;
    char ch;
    cin >> ch;
    if (ch == 'y' || ch == 'Y')
    {
        cout << "请输入棋盘的大小：";
        int size; // 可以直接删掉节省空间
        cin >> size;
        this->size += 2; // 棋盘大小
    }
    else
    {
        this->size = 12;
    }
    system("cls"); // 清屏
    cout << L"请问是否指定棋盘的地雷密度，如果不指定的话那么将会是默认地雷密度30%？[y/n]  ";
    cin >> ch;
    if (ch == 'y' || ch == 'Y')
    {
        cout << "请输入0-100(不包括0和100)之间的地雷密度数，这将影响游戏的难度：";
        int density;
        cin >> density;
        while (density >= 100 || density <= 0)
        {
            cout << "输入的数据不正确，请重新输入：";
            cin >> density;
        }
        this->density = density;
    }
    else
    {
        this->density = 30;
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            this->matrix[i][j] = 0;
            this->matrix_probe[i][j] = 0;
        }
    }
    for (int j = 0; j < this -> size; j++){
        this ->matrix_probe[0][j] = 1; // 边界
        this ->matrix_probe[this -> size - 1][j] = 1; // 边界
        this ->matrix_probe[j][this -> size -1] = 1;
        this ->matrix_probe[j][0] = 1;
    }
    system("cls");
    this -> score = 0;
    init_chessboard();
}


MineCleaner::MineCleaner(int size, int density) {
	this->size = size + 2;
	this->density = density;
	for (int i = 0; i < this->size; i++) {
		for (int j = 0; j < this->size; j++) {
			this->matrix[i][j] = 0;  //初始化棋盘
			this->matrix_probe[i][j] = 0;//一开始都是初始化没有被探索过
		}
	}
	for (int j = 0; j < this->size; j++) {
		//将边框变为可见，为ai做准备
		this->matrix_probe[0][j] = 1;
		this->matrix_probe[this->size - 1][j] = 1;
		this->matrix_probe[j][this->size - 1] = 1;
		this->matrix_probe[j][0] = 1;
	}
	//system("cls");
	this->score = 0;//初始化分数
	init_chessboard();//初始化棋盘信息
}
MineCleaner::~MineCleaner(){}
void MineCleaner::add_score() {
	this->score++;
}
void MineCleaner::print_blank() {
	cout << "                      ";
}
void MineCleaner::print_bottom() {
	cout << endl;
	print_blank();
	cout << "    ";
	for (int i = 1; i < this->size - 1; i++) {
		cout << " ---";
	}
	cout << endl;
}
void MineCleaner::print_col_info() {
	print_blank();
	cout << "     ";
	for (int i = 1; i < this->size - 1; i++) {
		cout <<" "<< i << "  ";
	}
}
void MineCleaner::print_main_info(int x,int y) {
	//先查看matrix_probe数组，如果是0表示没有翻开，什么都不显示，如果是1就显示内容
	//如果是2就插旗子表示有可能有地雷
	if (this->matrix_probe[x][y] == 0) {
		//这表示没有翻开格子
		cout << "   |";
	}
	else if (this->matrix_probe[x][y] == 2) {
		//这表示插旗判断可能有地雷
		cout << " @ |";
	}
	else {
		//如果翻开了就显示这个格子本来的信息
		if (this->matrix[x][y] == 5) {
			cout << " * |";
		}
		else if (this->matrix[x][y] == 0) {
			cout << " 0 |";
		}
		else {
			cout << " " << this->matrix[x][y] << " |";
		}
	}
}
//打印棋盘，调试成功
void MineCleaner::print() {
	cout << endl;
	cout << endl;
	cout << endl;
	print_col_info();
	print_bottom();
	for (int i = 1; i < this->size - 1; i++) {
		//行信息，每一行开始的时候都要空行并且打印行标
		if (i < 10) {
			print_blank();
			cout << i << "   |";
		}
		else {
			print_blank();
			cout << i << "  |";
		}
		for (int j = 1; j < this->size - 1; j++) {
			//列信息
			print_main_info(i,j);
		}
		cout <<"  "<< i;//结束的时候打印行信息
		print_bottom();
	}
	//最后再打印列信息
	print_col_info();
	cout << endl;
	print_blank();
	cout << "当前得分是：" <<this->score;
	cout << endl;
}
int MineCleaner::get_size() {
	return this->size;
}
//初始化棋盘信息
void MineCleaner::init_chessboard() {
	int num_of_total = (this->size-2)*(this->size-2);   //这是显示出来的棋盘的总数量
	float des = (float)this->density / 100;
	int x, y;
	int num_of_mine = des * num_of_total;  //这是地雷的总数
	//埋雷
	while (num_of_mine != 0) {
		//如果地雷数量不为0的话就要继续埋雷
		srand((unsigned)time(NULL));
		x = rand() % (this->size - 1) + 1;  //范围是从1-（size-1）
		y = rand() % (this->size - 1) + 1;
		while (this->matrix[x][y] == 5 || x == this->size-1 || y==this->size-1) {
			//如果这个地方已经有雷了，就重新找一个地方埋雷
			x = rand() % (this->size - 1) + 1;  //范围是从1-（size-1）
			y = rand() % (this->size - 1) + 1;
		}
		this->matrix[x][y] = 5;    //埋雷
		num_of_mine--;
	}
	//接下来要循环遍历整个棋盘的每个坐标，写下雷周围的数字
	for (int i = 1; i < this->size - 1; i++) {
		for (int j = 1; j < this->size - 1; j++) {
			if (this->matrix[i][j] != 5) {
				//如果这个坐标不是雷区才进行判断
				if (this->matrix[i - 1][j] == 5) this->matrix[i][j]++;
				if (this->matrix[i + 1][j] == 5) this->matrix[i][j]++;
				if (this->matrix[i][j - 1] == 5) this->matrix[i][j]++;
				if (this->matrix[i][j + 1] == 5) this->matrix[i][j]++;
			}
		}
	}
}
int MineCleaner::get_x() {
	print_blank();
	cout << "请输入要探索的横坐标（行）：";
	int x;
	cin >> x;
	while (x < 0 || x > this->size - 1) {
		print_blank();
		cout << "输入的坐标超出允许的范围，请重新输入：";
		cin >> x;
	}
	return x;
}
int MineCleaner::get_y() {
	print_blank();
	cout << "请输入要探索的纵坐标（列）：";
	int y;
	cin >> y;
	while (y < 0 || y > this->size - 1) {
		print_blank();
		cout << "输入的坐标超出允许的范围，请重新输入：";
		cin >> y;
	}
	return y;
}
//走棋
int MineCleaner::move() {
	//先接收要走棋的坐标位置
	//system("cls");
	print();
	int x, y;
	x = get_x();
	y = get_y();
	while (this->matrix_probe[x][y] == 1) {
		print_blank();
		cout << "该坐标已被探索过，请重新输入";
		x = get_x();
		y = get_y();
	}
	if (this->matrix[x][y] == 5) {
		game_over_print();
		return 0;
	}
	else if (this->matrix[x][y] == 0) {
		//如果这是个没有信息的区域，则要将一片连续的没有信息的区域都揭开
		uncover(x,y);
		if (if_win()) {
			return 0;
		}
		return 1;
	}
	else {
		this->matrix_probe[x][y] = 1; //表示已经探索过了
		add_score();
		return 1;
	}
}
//0是胜利，-1是失败
int MineCleaner::move(int x, int y) {
	system("cls");
	print();
	if (this->matrix[x][y] == 5) {
		game_over_print();
		return -1;
	}
	else if (this->matrix[x][y] == 0) {
		//如果这是个没有信息的区域，则要将一片连续的没有信息的区域都揭开
		uncover(x, y);
		this->matrix_probe[x][y] = 1;
		if (if_win()) {
			return 0;
		}
		return 1;
	}
	else {
		this->matrix_probe[x][y] = 1; //表示已经探索过了
		add_score();
		if (if_win()) {
			return 0;
		}
		return 1;
	}
 
 
}
void MineCleaner::uncover(int x,int y) {
	st s = (stack *)malloc(sizeof(stack));
	init_stack(s);
	int b[2] = { x,y };
	push(s, x,y);//先将当前坐标入栈
	//循环效验当前坐标的上下左右坐标
	while (empty(s)) {
		//cout << "开始循环效验未探索区域"<<endl;
		//如果栈不空的话,就弹栈然后循环验证周围是否有为0的坐标
		pop(s, b);//出栈，这个时候b[0]为xb[1]为y
		//探索上面的格子
		if (this->matrix_probe[b[0] - 1][b[1]] == 0 && this->matrix[b[0] - 1][b[1]] == 0) {
			//cout << "探索上面的格子，这个格子也是0" << endl;
			//如果没有探索并且是没有信息的坐标的话
			if (b[0] - 1 > 0) {
				//如果不是边上的坐标的话
				this->matrix_probe[b[0] - 1][b[1]] = 1;//表示探索过了
				push(s, b[0] - 1, b[1]);
				add_score();
			}
		}
		//探索下面的格子
		if (this->matrix_probe[b[0] + 1][b[1]] == 0 && this->matrix[b[0] + 1][b[1]] == 0) {
			//cout << "探索下面的格子，这个格子也是0" << endl;
			//如果没有探索并且是没有信息的坐标的话
			if (b[0] + 1 < this->size-1) {
				//如果不是边上的坐标的话
				this->matrix_probe[b[0] + 1][b[1]] = 1;//表示探索过了
				push(s, b[0] + 1, b[1]);
				add_score();
			}
		}
		//探索左边的坐标
		if (this->matrix_probe[b[0]][b[1] - 1] == 0 && this->matrix[b[0]][b[1] - 1] == 0) {
			//cout << "探索左边的格子，这个格子也是0" << endl;
			//如果没有探索并且是没有信息的坐标的话
			if (b[1] - 1 > 0) {
				this->matrix_probe[b[0]][b[1] - 1] = 1;//表示探索过了
				push(s, b[0], b[1] - 1);
				add_score();
			}
		}
		//探索右边的坐标
		if (this->matrix_probe[b[0]][b[1] + 1] == 0 && this->matrix[b[0]][b[1] + 1] == 0) {
			//cout << "探索右边的格子，这个格子也是0" << endl;
			//如果没有探索并且是没有信息的坐标的话
			if (b[1] + 1 < this->size-1) {
				this->matrix_probe[b[0]][b[1] + 1] = 1;//表示探索过了
				push(s, b[0], b[1] + 1);
				add_score();
			}
		}
	}
	//经过循环之后就把连续的没有探索过并且没有坐标的点都探索了
}
void MineCleaner::game_over_print() {
	for (int i = 1; i < this->size - 1; i++) {
		for (int j = 1; j < this->size - 1; j++) {
			this->matrix_probe[i][j] = 1;//全部变成已经探索过了
		}
	}
	system("cls");
	print();
	print_blank();
	cout << "游戏结束，总得分为：" << this->score;
	cout << endl;
	print_blank();
}
//判断是否赢了，赢了返回1，没有赢返回0
int MineCleaner::if_win() {
	//如果所有没有探索过的格子都是地雷的话就赢了
	for (int i = 1; i < this->size - 1; i++) {
		for (int j = 1; j < this->size - 1; j++) {
			if (this->matrix_probe[i][j] == 0) {
				if (this->matrix[i][j] == 5) {
					return 1;
				}
			}
		}
	}
	return 0;
}
void MineCleaner::win_print() {
	for (int i = 1; i < this->size - 1; i++) {
		for (int j = 1; j < this->size - 1; j++) {
			this->matrix_probe[i][j] = 1;//全部变成已经探索过了
		}
	}
	system("cls");
	print_blank();
	cout << "victory！";
	print();
}
int MineCleaner::get_matrix(int x, int y) {
	return this->matrix[x][y];
}
int MineCleaner::get_matrix_probe(int x,int y) {
	return this->matrix_probe[x][y];
}
