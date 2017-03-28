#include "Object2D.h"

#include <Core/Engine.h>



Mesh* Object2D::CreateSquare(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill)
{
	glm::vec3 corner = leftBottomCorner;

	std::vector<VertexFormat> vertices =
	{
		VertexFormat(corner + glm::vec3(-length / 2, -(length*sqrt(3)) / 2, 0), color),
		VertexFormat(corner , color),
		VertexFormat(corner + glm::vec3(length / 2, -(length*sqrt(3)) / 2, 0), color),
		VertexFormat(corner + glm::vec3(-length / 2, (length*sqrt(3)) / 2, 0), color),
		VertexFormat(corner + glm::vec3(length/2, (length*sqrt(3)) / 2,0), color)
		
	};

	Mesh* square = new Mesh(name);
	std::vector<unsigned short> indices = { 0, 1, 2, 4, 3,1 };
	
	if (!fill) {
		square->SetDrawMode(GL_LINE_LOOP);
	}
	else {
		// draw 2 triangles. Add the remaining 2 indices
		indices.push_back(0);
		indices.push_back(2);
	}

	square->InitFromData(vertices, indices);
	return square;
}

Object2D::Object2D(int lifes) {
	this->lifes = lifes;
}

void Object2D::loseLife() {
	Object2D::lifes--;
}

int Object2D::getLifes() {
	return Object2D::lifes;
}

void Object2D::setLifes(int life)
{
	Object2D::lifes = life;
}

Object2D::~Object2D()
{
}
