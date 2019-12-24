#include<iostream>
#include "wall.h"
#include "snake.h"
#include "food.h"
#include<ctime>
#include<conio.h>
#include<Windows.h>

using namespace std;

int main() {
	//����������
	srand((unsigned int)time(NULL));

	//��ʾ�Ƿ�����
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
	cout << "�÷֣�" << snake.getScore() << "��" << endl;

	//�����û�����
	while (!isDead)
	{
		char key = _getch();

		//�ж� ����ǵ�һ�ΰ������ �Ų��ܼ�����Ϸ
		//�ж� ��һ�� �ƶ�����
		if (preKey == NULL && key == snake.LEFT)
		{
			continue;
		}

		do
		{
			if (key == snake.UP || key == snake.DOWN || key == snake.LEFT || key == snake.RIGHT)
			{
				//�жϱ��ΰ��� �Ƿ����ϴγ�ͻ
				if ((key == snake.LEFT && preKey == snake.RIGHT) ||
					(key == snake.RIGHT && preKey == snake.RIGHT) ||
					(key == snake.UP && preKey == snake.DOWN) ||
					(key == snake.DOWN && preKey == snake.UP))
				{
					key = preKey;
				}
				else
				{
					preKey = key;  //���ǳ�ͻ�������Ը���
				}
			
				if (snake.move(key) == true)
				{
					//�ƶ��ɹ�
					system("cls");
					wall.drawWall();
					cout << "�÷֣�" << snake.getScore() << "��" << endl;
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
				key = preKey; //ǿ�ƽ����󰴼���Ϊ ��һ���ƶ��ķ���
			}

			
		} while (!_kbhit()); //��û�м��������ʱ�� ����0

		
	}
	
	system("pause");
	return 0;
}