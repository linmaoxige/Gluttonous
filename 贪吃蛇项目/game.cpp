#include<iostream>
#include "wall.h"
#include "snake.h"
#include "food.h"
#include<ctime>
#include<conio.h>
#include<Windows.h>

using namespace std;

int main() {
	//添加随机种子
	srand((unsigned int)time(NULL));

	//标示是否死亡
	bool isDead = false;

	char preKey = NULL;

	Wall wall;
	wall.initWall();

	Food food(wall);
	food.setFood();

	Snake snake(wall,food);
	snake.initSnake();

	//snake.deletePoint();

	wall.drawWall();
	cout << "得分：" << snake.getScore() << "分" << endl;

	//接收用户输入
	while (!isDead)
	{
		char key = _getch();

		//判断 如果是第一次按了左键 才不能激活游戏
		//判断 上一次 移动方向
		if (preKey == NULL && key == snake.LEFT)
		{
			continue;
		}

		do
		{
			if (key == snake.UP || key == snake.DOWN || key == snake.LEFT || key == snake.RIGHT)
			{
				//判断本次按键 是否与上次冲突
				if ((key == snake.LEFT && preKey == snake.RIGHT) ||
					(key == snake.RIGHT && preKey == snake.RIGHT) ||
					(key == snake.UP && preKey == snake.DOWN) ||
					(key == snake.DOWN && preKey == snake.UP))
				{
					key = preKey;
				}
				else
				{
					preKey = key;  //不是冲突按键可以更新
				}
			
				if (snake.move(key) == true)
				{
					//移动成功
					system("cls");
					wall.drawWall();
					cout << "得分：" << snake.getScore() << "分" << endl;
					Sleep(snake.getSleepTime());
				}
				else
				{
					isDead = true;
					break;
				}
			}
			else
			{
				key = preKey; //强制将错误按键变为 上一次移动的方向
			}

			
		} while (!_kbhit()); //当没有键盘输入的时候 返回0

		
	}
	
	system("pause");
	return 0;
}