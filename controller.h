#pragma once
#ifndef CONTROLLER_H
#define CONTROLLER_H

class controller
{
public:
	void Game();//һ��ѭ��
	void Start();//��ʼ����
	void Select();//ѡ���Ѷ�
	void DrawGame();//������Ϸ
	int PlayGame();//����ѭ��
	int Menu();//��ͣ�˵�
	void UpdateScore(int);
	void RewriteScore();
	int GameOver();//��Ϸ����
	
private:
	int score;
	int key;
	int speed;
	int mapkind;
};

#endif // CONTROLLER_H


