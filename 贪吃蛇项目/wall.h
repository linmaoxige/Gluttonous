#pragma once
#ifndef _WALL_HEAD
#define _WALL_HEAD

#include<iostream>

using namespace std;

class Wall
{
public:
	enum
	{
		ROW = 26,
		COL = 26
	};
	//��ʼ��ǽ��
	void initWall();
	//��ǽ��
	void drawWall();

	//�����������ö�ά�����������
	void setWall(int x, int y, char c);

	//����������ȡ��ǰλ�õķ���
	char getWall(int x, int y);

private:
	char gameArray[ROW][COL];
};

#endif // !_WALL_HEAD