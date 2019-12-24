#include "snake.h"

Snake::Snake(Wall& tempWall, Food& tempFood):wall(tempWall), food(tempFood)
{
	pHead = NULL;
	isRool = false;
}

void Snake::initSnake()
{
	destroyPoint();

	addPiont(5, 3);
	addPiont(5, 4);
	addPiont(5, 5);
}

//�������нڵ�
void Snake::destroyPoint()
{
	Point* pCur = pHead;
	while (pHead != NULL)
	{
		pCur = pHead->next;
		delete(pHead);
		pHead = pCur;
	}
}

void Snake::addPiont(int x, int y)
{
	//�����½ڵ�
	Point* newPoint = new Point;
	newPoint->x = x;
	newPoint->y = y;
	newPoint->next = NULL;

	//���ԭ��ͷ��Ϊ�գ���Ϊ����
	if (pHead != NULL)
	{
		wall.setWall(pHead->x, pHead->y, '=');
	}
	
	newPoint->next = pHead;
	pHead = newPoint; //����ͷ��

	wall.setWall(pHead->x, pHead->y, '@');
}

//ɾ���ڵ�
void Snake::deletePoint()
{
	//�����ڵ����ϣ���ȥ��ɾ������
	if (pHead == NULL || pHead->next == NULL)
	{
		return;
	}

	Point* pCur = pHead->next;
	Point* pPre = pHead;

	while (pCur->next != NULL)
	{
		pPre = pPre->next;
		pCur = pCur->next;
	}
	//ɾ��β�ڵ�
	wall.setWall(pCur->x, pCur->y, ' ');
	delete pCur;
	pCur = NULL;
	pPre->next = NULL;

}

bool Snake::move(char key)
{
	int x = pHead->x;
	int y = pHead->y;

	switch (key)
	{
	case UP:
		--x;
		break;
	case DOWN:
		++x;
		break;
	case LEFT:
		--y;
		break;
	case RIGHT:
		++y;
		break;
	default:
		break;
	}

	//�ж� �����һ����β�ͣ���Ӧ������
	Point* pCur = pHead->next;
	Point* pPre = pHead;

	while (pCur->next != NULL)
	{
		pPre = pPre->next;
		pCur = pCur->next;
	}
	if (pCur->x == x && pCur->y == y)
	{
		//����β�� ѭ��
		isRool = true;
	}
	else
	{
		//�ж��û�Ҫ�ﵽ��λ���Ƿ�ɹ�
		if (wall.getWall(x, y) == '*' || wall.getWall(x, y) == '=')
		{
			addPiont(x, y);
			deletePoint();
			system("cls");
			wall.drawWall();
			cout << "�÷֣�" << getScore() << "��" << endl;
			cout << "GAME OVER!" << endl;
			return false;
		}
	}

	

	//�ƶ��ɹ� ������
	//�Ե�ʳ�� δ�Ե�ʳ��
	if (wall.getWall(x, y) == '#')
	{
		addPiont(x, y);

		//��������ʳ��
		food.setFood();
	}
	else
	{
		addPiont(x, y);
		deletePoint();
		if (isRool == true)
		{
			wall.setWall(x, y, '@');
		}
		
	}

	return true;
}

int Snake::getSleepTime()
{
	int sleepTime = 0;
	
	int size = countList();
	if (size < 5)
	{
		sleepTime = 300;
	}
	else if(size>=5 && size <=8)
	{
		sleepTime = 200;
	}
	else
	{
		sleepTime = 100;
	}
	return sleepTime;
}

int Snake::countList()
{
	int size = 0;
	Point* curPoint = pHead;
	while (curPoint != NULL)
	{
		size++;
		curPoint = curPoint->next;
	}
	return size;
}

int Snake::getScore()
{
	int size = countList();

	int score = (size - 3) * 100;
	return score;
}
