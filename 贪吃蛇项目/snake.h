#pragma once
#include<iostream>
#include "wall.h"
#include "food.h"

using namespace std;

class Snake
{
public:
	Snake(Wall& tempWall, Food& tempFood);

	enum
	{
		UP = 'w', DOWN = 's', LEFT = 'a', RIGHT = 'd'
	};

	//节点
	struct Point
	{
		int x;
		int y;
		Point* next;
	};
	//初始化蛇
	void initSnake();

	//销毁节点
	void destroyPoint();

	//添加节点
	void addPiont(int x, int y);

	//删除节点
	void deletePoint();

	//蛇移动操作
	//返回值代表移动是否成功
	bool move(char key);

	//设定难度
	//获取刷屏时间
	int getSleepTime();
	//获取蛇身段
	int countList();

	//获取分数
	int getScore();

	Point* pHead;
	Wall& wall;
	Food& food;

	bool isRool; //判断循环标示
private:

};