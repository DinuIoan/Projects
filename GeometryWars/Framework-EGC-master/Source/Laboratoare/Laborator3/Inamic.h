#pragma once

#include <string>

#include <include/glm.h>
#include <Core/GPU/Mesh.h>
#include <vector>

using namespace std;

class Inamic
{
private:
	string nume;
	int vieti ;
	float viteza;
	float tx, ty;
	int squareSide;

public:
	Inamic();
	Inamic(string nume, float tx, float ty, int vieti, float viteza, int squareSide);
	string getNume();
	float getTx();
	float getTy();
	float getViteza();
	int getVieti();
	void setTx(float ty);
	void setTy(float tx);
	void setViteza(float viteza);
	void setNume(string nume);
	void setVieti(int viata);
	void pierdeViata();
	~Inamic();
	Mesh* CreateEnemy(string name, glm::vec3 leftBottomCorner, float lenght, glm::vec3 color);
};