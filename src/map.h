#ifndef _MAP_H
#define _MAP_H

#pragma comment(lib, "glut32.lib")

#include <vector>
#include <glut.h>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

class Map
{
private:
	float squareSize;

	vector<float> border;
	vector<float> obstaclesTop;
	vector<float> obstaclesMiddle;
	vector<float> obstaclesBottom;

public:
	vector<vector<bool>> bitmap; // 2d image of which squares are blocked and which are clear for pacman to move in

public: 
	int level; //It should be public because it should be referenced in main.

	Map();
	~Map();

	void mapInit2();
	void mapInit3();

	//Method to draw the obstacle course, the floor and the walls
	void drawLabyrinth();
    void drawFloor();
};
#endif
