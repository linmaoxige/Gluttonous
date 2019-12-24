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

		//如果随机数的位置是蛇头或蛇身则重新生成

		if (wall.getWall(foodX, foodY) == ' ')
		{
			wall.setWall(foodX, foodY, '#');
			break;
		}
	}
	
}
