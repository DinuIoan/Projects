#include "Inamic.h"

Mesh* Inamic::CreateEnemy(string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color)
{
	glm::vec3 corner = leftBottomCorner;

	std::vector<VertexFormat> vertices =
	{
		VertexFormat(corner + glm::vec3(-length / 2, -length*sqrt(3) / 2, 0), color),
		VertexFormat(corner, color),
		VertexFormat(corner + glm::vec3(length / 2, -length*sqrt(3) / 2, 0), color),
		VertexFormat(corner + glm::vec3(-length / 2, length*sqrt(3) / 2, 0), color),
		VertexFormat(corner + glm::vec3(length / 2, length*sqrt(3) / 2, 0), color)
	};

	Mesh* square = new Mesh(name);
	std::vector<unsigned short> indices = { 0, 1, 2, 4, 3, 1 };

	square->InitFromData(vertices, indices);
	return square;
}

Inamic::Inamic()
{
}


Inamic::~Inamic()
{
}

Inamic::Inamic(string nume, float tx, float ty, int vieti, float viteza, int squareSide)
{
	this->nume = nume;
	this->tx = tx;
	this->ty = ty;
	this->viteza = viteza;
	this->vieti = vieti;
	this->squareSide = squareSide;
}

void Inamic::setVieti(int vieti) {
	Inamic::vieti = vieti;
}

string Inamic::getNume()
{
	return this->nume;
}

float Inamic::getTx()
{
	return this->tx;
}

float Inamic::getTy()
{
	return this->ty;
}

void Inamic::setTx(float tx)
{
	this->tx = tx;
}

void Inamic::setTy(float ty)
{
	this->ty = ty;
}

int Inamic::getVieti() {
	return this->vieti;
}

float Inamic::getViteza() {
	return Inamic::viteza;
}

void Inamic::setViteza(float viteza) {
	Inamic::viteza = viteza;
}

void Inamic::pierdeViata()
{
	Inamic::vieti - 1;
}

void Inamic::setNume(string nume) {
	Inamic::nume = nume;
}
