#include "map.h"

vector<int> Top2D = {	2, 2, 3, 6, 3, 6, 4, 5, 4, 2, 5, 4, 5, 3, 6, 5,
						6, 1, 9, 2, 7, 2, 8, 5, 9, 5, 10, 3, 10, 4, 11,
						2, 11, 5, 12, 6, 12, 6, 13, 2 };
vector<int> Middle2D = {	2, 9, 3, 7, 3, 7, 4, 8, 4, 9, 5, 11, 5, 6, 6,
							10, 6, 10, 7, 8, 7, 8, 8, 9, 6, 7, 7, 6, 8, 6,
							9, 7, 10, 6, 9, 10, 9, 10, 8, 8, 11, 9, 10, 11,
							11, 8, 12, 7, 12, 7, 13, 9 };
vector<int> Bottom2D = {	2, 10, 3, 13, 3, 13, 4, 12, 5, 12, 6, 13, 6, 13,
							7, 11, 8, 11, 9, 13, 9, 13, 10, 12, 11, 12, 12,
							13, 12, 13, 13, 10 };


vector<float> Top3D = {	2.5, 2.5, 2.5, 3.5, 2.5, 4.5, 2.5, 5.5, 3.5, 
								5.5, 4.5, 2.5, 4.5, 3.5, 5.5, 3.5, 5.5, 4.5,
								6.5, 1.5, 7.5, 1.5, 7.5, 2.5, 7.5, 3.5, 7.5,
								4.5, 8.5, 1.5, 9.5, 3.5, 9.5, 4.5, 10.5, 2.5,
								10.5, 3.5, 11.5, 5.5, 12.5, 2.5, 12.5, 3.5,
								12.5, 4.5, 12.5, 5.5 };								//coordinates of the obstacles (divided into 3 for clarity)
vector<float> Middle3D = {	2.5, 7.5, 3.5, 7.5, 2.5, 8.5, 4.5, 10.5,
									4.5, 9.5, 5.5, 9.5, 5.5, 8.5, 5.5, 7.5, 5.5,
									6.5, 6.5, 6.5, 6.5, 8.5, 6.5, 9.5, 7.5, 8.5,
									8.5, 8.5, 8.5, 9.5, 9.5, 9.5, 9.5, 8.5, 9.5,
									7.5, 9.5, 6.5, 8.5, 6.5, 10.5, 9.5, 10.5,
									10.5, 11.5, 7.5, 12.5, 7.5, 12.5, 8.5 };
vector<float> Bottom3D = {	2.5, 10.5, 2.5, 11.5, 2.5, 12.5, 3.5, 12.5,
									5.5, 12.5, 6.5, 12.5, 6.5, 11.5, 8.5, 11.5,
									8.5, 12.5, 9.5, 12.5, 11.5, 12.5, 12.5, 12.5,
									12.5, 11.5, 12.5, 10.5 };

vector<float> border = { 0, 0, 15, 1, 15, 15, 14, 1, 0, 14, 15, 15, 1, 14, 0, 0 }; //coordinates of the border walls

Map::Map()
{
	squareSize = 50.0;
}

Map::~Map()
{

}

//Method to draw the floor of map
void Map::drawFloor3D()
{
    glPushMatrix();
    
    glColor3f(0, 0.2, 0.4);
    glTranslated(15.0/2*squareSize, 15.0/2*squareSize, -5);
    glScalef(1, 1, 0.01);
    glutSolidCube(squareSize*15);
    
    glPopMatrix();
}
//Method to draw the obstacle course and the walls
void Map::drawLabyrinth2D(){
	glColor3f(1.0, 1.0, 1.0);
	//Border
	for (int i = 0; i < border.size(); i = i + 4){
		glRectf(border.at(i) * squareSize, border.at(i + 1)*squareSize, border.at(i + 2)*squareSize, border.at(i + 3)*squareSize);
	}

	//Obstacles
	for (int j = 0; j < Bottom2D.size(); j = j + 4){
		glRectf(Bottom2D.at(j) * squareSize, Bottom2D.at(j + 1)*squareSize, Bottom2D.at(j + 2)*squareSize, Bottom2D.at(j + 3)*squareSize);
	}
	for (int k = 0; k < Middle2D.size(); k = k + 4){
		glRectf(Middle2D.at(k) * squareSize, Middle2D.at(k + 1)*squareSize, Middle2D.at(k + 2)*squareSize, Middle2D.at(k + 3)*squareSize);
	}
	for (int p = 0; p < Top2D.size(); p = p + 4){
		glRectf(Top2D.at(p) * squareSize, Top2D.at(p + 1)*squareSize, Top2D.at(p + 2)*squareSize, Top2D.at(p + 3)*squareSize);
	}
}

void Map::drawLabyrinth3D(){
	//Border1
	for (int i = 0; i < border.size(); i = i + 8)
	{
		glPushMatrix();
		glTranslatef((border.at(i)*squareSize + border.at(i + 2)*squareSize) / 2.0, (border.at(i + 1)*squareSize + border.at(i + 3)*squareSize) / 2.0, 25);
		glScalef(15, 1, 1); //Long x-axis cube
		glColor3f(1.0, 1.0, 1.0); glutSolidCube(50);
		glColor3f(0, 0, 0); glutWireCube(50);
		glPopMatrix();
	}
	//Border2
	for (int i = 4; i < border.size(); i = i + 8)
	{
		glPushMatrix();
		glTranslatef((border.at(i)*squareSize + border.at(i + 2)*squareSize) / 2.0, (border.at(i + 1)*squareSize + border.at(i + 3)*squareSize) / 2.0, 25);
        glScalef(1, 15, 1); //Long y-axis cube
		glColor3f(1.0, 1.0, 1.0); glutSolidCube(50);
		glColor3f(0, 0, 0); glutWireCube(50);
		glPopMatrix();
	}

	//Obstacles
	for (int j = 0; j < Bottom3D.size(); j = j + 2) {
		glPushMatrix();
		glTranslated(Bottom3D.at(j) * squareSize, Bottom3D.at(j + 1) * squareSize, 25);
		glColor3f(0, 0, 0);
		glutWireCube(50);
		glColor3f(1, 1, 1);
		glutSolidCube(50);
		glPopMatrix();

	}
	for (int k = 0; k < Middle3D.size(); k = k + 2) {
		glPushMatrix();
		glTranslated(Middle3D.at(k) * squareSize, Middle3D.at(k + 1) * squareSize, 25);
		glColor3f(0, 0, 0);
		glutWireCube(50);
		glColor3f(1, 1, 1);
		glutSolidCube(50);
		glPopMatrix();
	}

	for (int p = 0; p < Top3D.size(); p = p + 2)
	{
		glPushMatrix();
		glTranslatef(Top3D.at(p) * squareSize, Top3D.at(p + 1) * squareSize, 25);
		glColor3f(0, 0, 0);
		glutWireCube(50);
		glColor3f(1, 1, 1);
		glutSolidCube(50);
		glPopMatrix();
	}
}