#pragma once

#include <string>

#include <include/glm.h>
#include <Core/GPU/Mesh.h>
using namespace std;

class Object2D
{
private:
	int lifes;
public:
	Object2D(int lifes);
	Mesh* CreateSquare(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill = false);
	void loseLife();
	int getLifes();
	void setLifes(int life);
	~Object2D();
	
};