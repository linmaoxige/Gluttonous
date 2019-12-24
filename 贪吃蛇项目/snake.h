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

	//�ڵ�
	struct Point
	{
		int x;
		int y;
		Point* next;
	};
	//��ʼ����
	void initSnake();

	//���ٽڵ�
	void destroyPoint();

	//��ӽڵ�
	void addPiont(int x, int y);

	//ɾ���ڵ�
	void deletePoint();

	//���ƶ�����
	//����ֵ�����ƶ��Ƿ�ɹ�
	bool move(char key);

	//�趨�Ѷ�
	//��ȡˢ��ʱ��
	int getSleepTime();
	//��ȡ�����
	int countList();

	//��ȡ����
	int getScore();

	Point* pHead;
	Wall& wall;
	Food& food;

	bool isRool; //�ж�ѭ����ʾ
private:

};