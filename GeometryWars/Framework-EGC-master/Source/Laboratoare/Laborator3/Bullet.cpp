#include "Bullet.h"

#include <Core/Engine.h>


Mesh* Bullet::CreateBullet(string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color)
{
	glm::vec3 corner = leftBottomCorner;

	std::vector<VertexFormat> vertices =
	{
		VertexFormat(corner + glm::vec3(-2.5, -5, 0), color),
		VertexFormat(glm::vec3(2.5, -5, 0), color),
		VertexFormat(glm::vec3(2.5, 10, 0), color),
		VertexFormat(glm::vec3(-2.5,10, 0), color)
	};

	Mesh* square = new Mesh(name);
	std::vector<unsigned short> indices = { 0, 1, 2, 3};
	
		// draw 2 triangles. Add the remaining 2 indices
		indices.push_back(0);
		indices.push_back(2);
	

	square->InitFromData(vertices, indices);
	return square;
}

Bullet::Bullet()
{
}


Bullet::~Bullet()
{
}

Bullet::Bullet(string nume, float tx, float ty,  float viteza, float dx, float dy,float unghi)
{
	this->nume = nume;
	this->tx = tx;
	this->ty = ty;
	this->viteza = viteza;
	this->dx = dx;
	this->dy = dy;
	this->unghi = unghi;
}

string Bullet::getNume()
{
	return this->nume;
}

float Bullet::getTx()
{
	return this->tx;
}

float Bullet::getTy()
{
	return this->ty;
}

void Bullet::setTx(float tx)
{
	this->tx = tx;
}

void Bullet::setTy(float ty)
{
	this->ty = ty;
}

float Bullet::getdx()
{
	return this->dx;
}

float Bullet::getdy()
{
	return this->dy;
}

void Bullet::setUnghi(float unghi){
	this->unghi = unghi;
}

float Bullet::getUnghi() {
	return this->unghi;
}