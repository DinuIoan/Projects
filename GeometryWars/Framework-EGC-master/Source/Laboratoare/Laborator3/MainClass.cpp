#include "MainClass.h"

#include <vector>
#include <iostream>

#include <Core/Engine.h>
#include "Transform2D.h"
#include "Object2D.h"
#include "Bullet.h"
#include "Inamic.h"
#include <gl\gl.h>                        
#include <gl\glu.h>     ]

using namespace std;

MainClass::MainClass()
{
}

MainClass::~MainClass()
{
}
float tx = 600; float ty = 350; int ok = 1; int rx = 400; int ry = 250; float scaleX=500; float scaleY=250; float ok2 = 1; float cx = 250; float cy = 125;
float f;
float squareSide;
glm::ivec2 resolution;
int numarGloante = 0;
int inamici = 0;
vector<Bullet*> gloante;
int tXglont, tYglont,vGlont;
bool trage = false;
float fGlont;
int i;
float unghi;
vector<Inamic*> inam;
int mx, my;
vector<int> elimInamic;
vector<int> elimBullet;
float time = 0;
Object2D nava = Object2D::Object2D(3);
Mesh* navaMesh;
bool GameOver = false;
int score = 0;
int scoreX = 1;
float timeX;

void MainClass::Init()
{
	resolution = window->GetResolution();
	camera->SetOrthographic(0, (float)resolution.x, 0, (float)resolution.y, 0.01f, 400);
	camera->SetPosition(glm::vec3(0, 0, 50));
	camera->SetRotation(glm::vec3(0, 0, 0));
	camera->Update();
	cameraInput->SetActive(false);

	vGlont = 0;
	i = 0;
	timeX = 0;

	glm::vec3 corner = glm::vec3(0, 0, 0);
	squareSide = 50;

	// compute coordinates of square center
	float cx = corner.x + squareSide / 2;
	float cy = corner.y + squareSide / 2;
	
	// initialize tx and ty (the translation steps)
	translateX = 0;
	translateY = 0;

	// initialize sx and sy (the scale factors)
	scaleX = 1;
	scaleY = 1;
	
	// initialize angularStep
	angularStep = 0;
	
	navaMesh = nava.CreateSquare("square1", corner, squareSide, glm::vec3(1, 0, 0), true);
	AddMeshToList(navaMesh);

	
	

}

void MainClass::FrameStart()
{
	// clears the color buffer (using the previously set color) and depth buffer
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glm::ivec2 resolution = window->GetResolution();
	// sets the screen area where to draw
	glViewport(0, 0, resolution.x, resolution.y);
}


void MainClass::Update(float deltaTimeSeconds)
{

	Bullet *life1 = new Bullet("life1", tx, ty, 10, 0, 0, 90);
	Mesh* life1Mesh = life1->CreateBullet("life1", glm::vec3(0, 0, 0), squareSide, glm::vec3(1, 0, 0));
	AddMeshToList(life1Mesh);

	Bullet *life2 = new Bullet("life2", tx, ty, 10, 0, 0, 90);
	Mesh* life2Mesh = life2->CreateBullet("life2", glm::vec3(0, 0, 0), squareSide, glm::vec3(1, 0, 0));
	AddMeshToList(life2Mesh);

	Bullet *life3 = new Bullet("life3", tx, ty, 10, 0, 0, 90);
	Mesh* life3Mesh = life3->CreateBullet("life3", glm::vec3(0, 0, 0), squareSide, glm::vec3(1, 0, 0));
	AddMeshToList(life3Mesh);
	int deltaTimeColor = 0;
	
	if (nava.getLifes() == 3) {
		modelMatrix = glm::mat3(1);
		modelMatrix *= Transform2D::Translate(1200, 700);
		RenderMesh2D(meshes["life1"], shaders["VertexColor"], modelMatrix);
		modelMatrix = glm::mat3(1);
		modelMatrix *= Transform2D::Translate(1220, 700);
		RenderMesh2D(meshes["life2"], shaders["VertexColor"], modelMatrix);
		modelMatrix = glm::mat3(1);
		modelMatrix *= Transform2D::Translate(1240, 700);
		RenderMesh2D(meshes["life3"], shaders["VertexColor"], modelMatrix);
	}
	else if (nava.getLifes() == 2) {
		modelMatrix = glm::mat3(1);
		modelMatrix *= Transform2D::Translate(1220, 700);
		RenderMesh2D(meshes["life2"], shaders["VertexColor"], modelMatrix);
		modelMatrix = glm::mat3(1);
		modelMatrix *= Transform2D::Translate(1240, 700);
		RenderMesh2D(meshes["life3"], shaders["VertexColor"], modelMatrix);
	}
	else if (nava.getLifes() == 1) {
		modelMatrix = glm::mat3(1);
		modelMatrix *= Transform2D::Translate(1240, 700);
		RenderMesh2D(meshes["life3"], shaders["VertexColor"], modelMatrix);
	}
	else {
		GameOver = true;
		if (timeX < 1) {
			timeX = timeX + deltaTimeSeconds;
		}
			
		glClearColor(timeX, 0, 0, 0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
	
	
	if (GameOver == false) {
		modelMatrix = glm::mat3(1);
		modelMatrix *= Transform2D::Translate(tx, ty);
		modelMatrix *= Transform2D::Translate(0, 0);
		modelMatrix *= Transform2D::Rotate(f);
		modelMatrix *= Transform2D::Translate(0, 0);

		RenderMesh2D(meshes["square1"], shaders["VertexNormal"], modelMatrix);

		time += deltaTimeSeconds;
		int xTime = 2;
		if (xTime == 0.5) xTime = 0.5;
		else xTime -= 0.1;
		if (time > xTime)
		{

			inamici++;
			time = 0;
			string nume = "enemy" + to_string(inamici);
			float enX = tx - 500 + (rand() % (601));
			float enXX;
			if (enX > tx)
				enXX = enX - tx;
			else
				enXX = tx - enX;
			float enY = sqrt(500 * 500 - (enXX*enXX));
			int enYY = rand() % 2;
			if (enYY == 0)
				enY = ty - enY;
			else enY += ty;
			int vieti = rand() % 2;
			vieti++;
			int viteza = rand() % 2;
			
			viteza++;
			Inamic *inamic = new Inamic(nume, enX, enY, vieti, viteza, squareSide);
			inam.push_back(inamic);
			Mesh* enemy;
			if (vieti == 1)
			{
				enemy = inamic->CreateEnemy(nume, glm::vec3(1, 1, 1), squareSide, glm::vec3(0, 0, 1));
			}
			else
			{
				enemy = inamic->CreateEnemy(nume, glm::vec3(1, 1, 1), squareSide , glm::vec3(1, 1, 0));
			}
			AddMeshToList(enemy);
			modelMatrix = glm::mat3(1);
			modelMatrix *= Transform2D::Translate(enX, enY);
			RenderMesh2D(meshes[nume], shaders["VertexColor"], modelMatrix);


		}
		modelMatrix = glm::mat3(1);
		if (trage) {
			trage = false;
			string nume = "bullet" + to_string(gloante.size());
			float dx = abs(tx - mx);
			float dy = abs(ty - my);
			float dist = sqrt(dx*dx + dy*dy);
			float sin1 = dx / dist;
			float sin2 = dy / dist;
			sin1 = sin1 * 5;
			sin2 = sin2 * 5;
			if (mx < tx)
				sin1 = 0 - sin1;
			if (my < ty)
				sin2 = 0 - sin2;
			Bullet *bullet = new Bullet(nume, tx, ty, 10, sin1, sin2, fGlont);
			gloante.push_back(bullet);
			Mesh* blt = bullet->CreateBullet(nume, glm::vec3(0, 0, 0), squareSide, glm::vec3(1, 0, 0));
			AddMeshToList(blt);
			modelMatrix = glm::mat3(1);
			modelMatrix *= Transform2D::Translate(bullet->getTx(), bullet->getTy());
			modelMatrix *= Transform2D::Rotate(bullet->getUnghi());
			//modelMatrix *= Transform2D::Translate(0, 0);
			RenderMesh2D(meshes[nume], shaders["VertexColor"], modelMatrix);


		}
		for (int i = 0; i < inam.size(); i++)
		{
			float dX = abs(tx - inam[i]->getTx());
			float dY = abs(ty - inam[i]->getTy());
			float dist = sqrt(dX*dX + dY*dY);
			float sn = dX / dist;
			dX = sn * 2;
			sn = dY / dist;
			dY = sn * 2;

			if (ty > inam[i]->getTy())
				inam[i]->setTy(inam[i]->getTy() + dY);
			else
				inam[i]->setTy(inam[i]->getTy() - dY);

			if (tx > inam[i]->getTx())
				inam[i]->setTx(inam[i]->getTx() + dX);
			else
				inam[i]->setTx(inam[i]->getTx() - dX);
			if (sqrt((inam[i]->getTx() - tx)*(inam[i]->getTx() - tx) + (inam[i]->getTy() - ty)*(inam[i]->getTy() - ty)) <= squareSide)
			{
				nava.loseLife();
				score = 0;
				elimInamic.push_back(i);
			}
			else
			{
				float fe = -(M_PI - atan((ty - inam[i]->getTy()) / (tx - inam[i]->getTx())));
				modelMatrix = glm::mat3(1);
				modelMatrix *= Transform2D::Translate(inam[i]->getTx(), inam[i]->getTy());
				modelMatrix *= Transform2D::Rotate(fe);
				modelMatrix *= Transform2D::Translate(0, 0);
				RenderMesh2D(meshes[inam[i]->getNume()], shaders["VertexColor"], modelMatrix);
			}
			//cout << inam[i]->getNume() << "\n";
		}

		for (int i = 0; i < gloante.size(); i++)
		{
			gloante[i]->setTx(gloante[i]->getTx() + gloante[i]->getdx());
			gloante[i]->setTy(gloante[i]->getTy() + gloante[i]->getdy());
			int ok = 0;
			int ok2 = 0;
			for (int j = 0; j < inam.size(); j++)
			{
				if (ok2 == 1)
				{
					ok2 = 0;
					j--;
				}
				float ex = inam[j]->getTx();
				float ey = inam[j]->getTy();
				float bx = gloante[i]->getTx();
				float by = gloante[i]->getTy();
				if (sqrt((ex - bx)*(ex - bx) + (ey - by) * (ey - by)) <= squareSide)
				{
					elimInamic.push_back(j);
					ok = 1;
					
					if (inam[j]->getVieti() == 2)
					{
						inamici++;
						float fe = -(M_PI - atan((ty - ey) / (tx - ex)));
						string nume = "enemy" + to_string(inamici) ;
						Inamic *inamic = new Inamic(nume,ex, ey, 1, inam[j]->getViteza() * 2, 50 / 2);
						inam.push_back(inamic);
						Mesh* enemy2 = inamic->CreateEnemy(nume, glm::vec3(1, 1, 1), 50 / 2, glm::vec3(0, 1, 1));
						AddMeshToList(enemy2);
						modelMatrix = glm::mat3(1);
						modelMatrix *= Transform2D::Translate(ex, ey);
						modelMatrix *= Transform2D::Rotate(fe);
						RenderMesh2D(meshes[nume], shaders["VertexColor"], modelMatrix);
						j++;
						ok2 = 1;
					}
				}
			}
			if (ok == 1)
			{
				ok == 0;
				elimBullet.push_back(i);
			}
			else
			{
				modelMatrix = glm::mat3(1);
				modelMatrix *= Transform2D::Translate(gloante[i]->getTx(), gloante[i]->getTy());
				modelMatrix *= Transform2D::Rotate(gloante[i]->getUnghi());
				RenderMesh2D(meshes[gloante[i]->getNume()], shaders["VertexColor"], modelMatrix);
			}
		}

		for (int i = elimInamic.size() - 1; i >= 0; i--)
		{
			if (elimInamic[i] < inam.size())
				inam.erase(inam.begin() + elimInamic[i]);
		}

		elimInamic.clear();

		for (int i = elimBullet.size() - 1; i >= 0; i--)
		{
			if (elimBullet[i] < gloante.size())
				gloante.erase(gloante.begin() + elimBullet[i]);
		}
		elimBullet.clear();
	}
}

void MainClass::FrameEnd()
{

}

void MainClass::OnInputUpdate(float deltaTime, int mods)
{
	if (window->KeyHold(GLFW_KEY_W))
	{
		ty += 2;
		//tYglont = ty;
	}
	else if (window->KeyHold(GLFW_KEY_A))
	{
		tx -= 2;
		//tXglont = tx;
	}
	else if (window->KeyHold(GLFW_KEY_S))
	{
		ty -= 2;
		//tYglont = ty;
	}
	else if (window->KeyHold(GLFW_KEY_D))
	{
		tx += 2;
		//tXglont = tx;
	}
	else if (window->KeyHold(GLFW_KEY_F)) {
		trage = true;
	}
	else if (window->KeyHold(GLFW_KEY_R)) {
		GameOver =  false;
		timeX = 0;
		nava.setLifes(3);
	}
	
	
}

void MainClass::OnKeyPress(int key, int mods)
{
	// add key press event
};

void MainClass::OnKeyRelease(int key, int mods)
{
	// add key release event
};

void MainClass::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
	// add mouse move event
	mx = mouseX;
	my = resolution.y - mouseY;
	f = -(M_PI - atan((resolution.y - mouseY - ty) / (mouseX - tx)));
	

};

void MainClass::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
	// add mouse button press event
	if (button == 1) {
		trage = true;
		fGlont = f + M_PI / 2;
	}
	
	mx = mouseX;
	my = resolution.y - mouseY;
	

	
};

void MainClass::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
	// add mouse button release event
}

void MainClass::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}