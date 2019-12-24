#include "food.h"

Food::Food(Wall& temWall):wall(temWall)
{
}

void Food::setFood()
{
	while (true)
	{
		foodX = rand() % (Wall::ROW - 2) + 1;
		foodY = rand() % (Wall::COL - 2) + 1;

		//����������λ������ͷ����������������

		if (wall.getWall(foodX, foodY) == ' ')
		{
			wall.setWall(foodX, foodY, '#');
			break;
		}
	}
	
}
