#pragma once
#ifndef CONTROLLER_H
#define CONTROLLER_H

class controller
{
public:
	void Game();//一级循环
	void Start();//开始界面
	void Select();//选择难度
	void DrawGame();//绘制游戏
	int PlayGame();//二级循环
	int Menu();//暂停菜单
	void UpdateScore(int);
	void RewriteScore();
	int GameOver();//游戏结束
	
private:
	int score;
	int key;
	int speed;
	int mapkind;
};

#endif // CONTROLLER_H


