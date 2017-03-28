#pragma once
#include <string>

#include <include/glm.h>
#include <Core/GPU/Mesh.h>
#include <vector>

using namespace std;

class Bullet
{
private:
	string nume;
	float viteza;
	float tx, ty;
	float dx, dy;
	float unghi;

public:
	Bullet();
	Bullet(string nume, float tx, float ty, float viteza, float dx, float dy,float unghi);
	string getNume();
	float getTx();
	float getTy();
	void setTx(float ty);
	void setTy(float tx);
	void setUnghi(float unghi);
	float getdx();
	float getdy();
	float getUnghi();
	~Bullet();
	Mesh* CreateBullet(string name, glm::vec3 leftBottomCorner, float lenght, glm::vec3 color);
};