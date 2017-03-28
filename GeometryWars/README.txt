Nume: DINU IOAN
Grupa: 333
Seria: CC

Utilizarea aplicatiei:
W - sus
A - stanga
S - jos 
D - dreapta
Click stanga - trage cu proiectil
R - Replay ( jocul o ia de la inceput ) .

Detalii de implementare:
	M-am folosit de laboratorul 3 avand translate, scale si rotate deja implementat. 

Bullet.cpp: este clasa proiectilului in care creez imaginea unui proiectil;
Inamic.cpp: clasa inamicilor in care creez imaginea unui inamic;
Object2D.cpp: este clasa navei in care creez imaginea navei;
Transform2D.cpp: clasa din laboratorul 3 ce contine Translate,Scale,Rotate.
MainClass.cpp: este clasa principala in care creez nava, inamicii, gloantele si toate comportamentele acestora.

	MainClass::Update() -> verific si afisez vietile navei, daca nava mai are vieti creez inamicii si ii pun intr-un vector ( la fel si cu gloantele) , inamicii urmaresc nava mea, la coliziunea cu aceasta pierde o viata, daca un glont se loveste cu un inamic acesta pierde viata.
	MainClass::OnInputUpdate() -> realizeaza miscarea navei.
	MainCLass::OnMouseBtnPressed()-> preiau coordonatele in momentul in care trag.

Probleme aparute:
	Probleme au fost la scalarea inamicului, cand il faceam mai mic aparea si disparea, la cursorului de catre nava deoarece trebuia aplicata formula corecta , la urmarirea cursorului de catre gloante deoarece mouseX si mouseY au punctul de referinte (0,0) in stanga sus .

Status implementare:
Am implementat toate punctele si 2 bonusuri facute de mine:
	La apasarea tastei "R" jocul se reseteaza si o ia de la inceput.
	Atunci cand nava pierde o viata sau doua dar omoara 20 de inamici castiga o viata la loc,insa daca nava pierde o viata scorule se reseteaza la 0. Dupa ce nava castiga o viata , limita de kill-uri pentru a putea castiga o viata noua va creste cu 20;