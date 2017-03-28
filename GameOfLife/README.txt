Nume: DINU IOAN
Grupa: 333CC

SERIAL
-> Pentru serial am salvat prima linie, ultima linie, prima coloana, ultima coloana, colturile pentru a putea borda matricea.
-> Dupa bordare am folosit blocul while pentru a numara iteratiile;

	-> In while, verific numarul de vecini morti si numarul de vecini vii in matricea nemodificata (matrix);

		-> Avand numarul de vecini morti si numarul de vecini vii verific conditiile lui Conway si modific matricea "matrice";
		-> Dupa verificarea tuturor veciniilor bordez matricea "matrice" cu noile borduri;
		-> La finalul iteratiei copiez matricea modificata la pasul curent "matrice" in matricea nemodificata de la pasul anterior "matrix" ;

PARALLEL
-> Existand mai multe declaratii "for" imbricate am folosit "collapse" urmat de numarul de for-uri ce trebuie paralelizate
-> Clauza "private(i,j)" aloca variabilele doar pentru fiecare thread in parte
-> Clauza "shared(matrix,matrice)" asigura partajarea matricilor intre thread-uri pentru a vedea fiecare modificarile facute .

-> Pentru o viteza mai buna am paralelizat si bordarea si copierea matricilor. 


!!!
In fisierul result.xlsx am masurat pentru o matrice de 1000 linii 1000 coloane si 1000 de iteratii.
