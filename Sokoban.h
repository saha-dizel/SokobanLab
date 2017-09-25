#pragma once

class Sokoban
{
private:
	unsigned short int lvl;

public:
	Sokoban();

	void setLVL(unsigned short int);
	int getLVL();
	void changeLVL();
	void setBox(int);
	
	void menu();

	class tile
	{
	private:
		bool box;
		bool playerPos;
		bool wall;
		bool winPlace;

	public:
		tile();

		bool getBox();
		bool getPlayerPos();
		bool getWall();
		bool getWinPlace();

		void setBox(bool);
		void setPlayerPos(bool);
		void setWall(bool);
		void setWinPlace(bool);

		void lvlGen();
	};
};