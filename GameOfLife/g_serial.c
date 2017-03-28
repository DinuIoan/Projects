#include<stdio.h>
#include<stdlib.h>
#include<string.h>




int main(int argc,char *argv[]){

	

	FILE *in = fopen(argv[1],"r");
	FILE *out = fopen(argv[3],"w");
	int numarColoane,numarLinii;
	int numarIteratii;
	numarIteratii = atoi(argv[2]);
	int count = 0;
	
	
	
	fscanf(in,"%d %d",&numarLinii,&numarColoane);
	int numarLinii2 = numarLinii;
	int numarColoane2 = numarColoane;
	int **matrix = malloc((numarLinii+2)*sizeof(int*));
	int i,j;
	int pL = 0,uL = 0 ,pC = 0 ,uC = 0;

	
	int *ultimaColoana = malloc(numarLinii * sizeof(int));
	int *primaColoana = malloc(numarLinii * sizeof(int));
	int *primaLinie = malloc(numarColoane * sizeof(int));
	int *ultimaLinie = malloc(numarColoane * sizeof(int));
	int coltStangaSus = 0;
	int coltDreaptaSus = 0;
	int coltStangaJos = 0;
	
	int coltDreaptaJos = 0;	
	for(i = 0; i <= numarLinii +1; i++)
	{			
		matrix[i] = calloc(numarColoane+2, sizeof(int));
		for(j = 0; j <= numarColoane + 1; j++)
		{
			matrix[i][j] = 0;
		}
	}

	for(i = 1; i <= numarLinii; i++)
	{			
		for(j = 1; j <= numarColoane; j++)
		{
			char c ;
			fscanf(in," %c",&c);
			if( c == 46){
				matrix[i][j] = 0;
			}
			else {
				matrix[i][j] = 1;
			}
			
			if( i == 1 ){
				primaLinie[pL] = matrix[i][j];
				pL++;
			}
			if( i == numarLinii){
				ultimaLinie[uL] = matrix[i][j];
				uL++;
			}
			if( j == 1 ){
				primaColoana[pC] = matrix[i][j];
				pC++;		
			}
			if(j == numarColoane){
				ultimaColoana[uC] = matrix[i][j];
				uC++;
			}
			if(i == 1 && j == 1) coltStangaSus = matrix[i][j];
			if(i == 1 && j == numarColoane) coltDreaptaSus = matrix[i][j];
			if(i == numarLinii && j == 1)  coltStangaJos = matrix[i][j];
			if(i == numarLinii && j == numarColoane) coltDreaptaJos = matrix[i][j];
			
		}
		
	}
	
	pL = 0;
	uL = 0;
	pC = 0;
	uC = 0;
	
	int **matrice = malloc((numarLinii+2)*sizeof(int*));
	for(i = 0; i <= numarLinii +1 ;i++)
		{
		matrice[i] = calloc(numarColoane+2,sizeof(int));
		
		for(j = 0 ; j <= numarColoane +1 ; j++)
		{
		}
	}
	
	matrice[0][0] = coltDreaptaJos;
	matrice[0][numarColoane+1] = coltStangaJos;
	matrice[numarLinii+1][0] = coltDreaptaSus;
	matrice[numarLinii+1][numarColoane+1] = coltStangaSus;
	
	for(i = 1; i <= numarLinii;i++)
	{
		matrice[i][0] = ultimaColoana[uC];
		uC++;
		matrice[i][numarColoane+1] = primaColoana[pC];
		pC++;
	} 	
	for(j = 1; j <= numarColoane;j++)
	{
		matrice[0][j] = ultimaLinie[uL];
		uL++;
		matrice[numarLinii+1][j] = primaLinie[pL];
		pL++; 
	}

	for(i = 1; i <= numarLinii ;i++)
		for(j = 1; j <= numarColoane ; j++)
			{
				matrice[i][j] = matrix[i][j];
			}


	
	
	for(i = 0; i <= numarLinii + 1;i++)
	{
		
		for(j = 0; j <= numarColoane + 1 ; j++)
			{
				matrix[i][j] = matrice[i][j];
			}
	}
		


	//inceput algoritm
	int numarVeciniVii ;
	int numarVeciniMorti ;
	while(count < numarIteratii)
	{
	for(i = 1; i <=	numarLinii; i++)
	{
		for(j = 1; j <= numarColoane; j++)
		{
			
			numarVeciniVii = 0;
			numarVeciniMorti = 0;
			
			if(matrix[i-1][j-1] == 0)
				numarVeciniMorti++;
			else 
				numarVeciniVii++;
			if(matrix[i][j-1] == 0)
				numarVeciniMorti++;
			else 
				numarVeciniVii++;
			if(matrix[i+1][j-1] == 0)
				numarVeciniMorti++;
			else 
				numarVeciniVii++;
			if(matrix[i-1][j] == 0)
				numarVeciniMorti++;
			else 
				numarVeciniVii++;
			if(matrix[i-1][j+1] == 0)
				numarVeciniMorti++;
			else 
				numarVeciniVii++;
			if(matrix[i][j+1] == 0)
				numarVeciniMorti++;
			else 
				numarVeciniVii++;
			if(matrix[i+1][j+1] == 0)
				numarVeciniMorti++;
			else 
				numarVeciniVii++;
			if(matrix[i+1][j] == 0)
				numarVeciniMorti++;
			else 
				numarVeciniVii++;
			
			if(matrix[i][j] == 1 && numarVeciniVii < 2)
				matrice[i][j] = 0;
			if(matrix[i][j] == 1)
				if(numarVeciniVii == 2 || numarVeciniVii ==3)
					matrice[i][j] = 1;
			if(matrix[i][j] == 0)
				if(numarVeciniVii == 3)
					matrice[i][j] = 1;
			if(matrix[i][j] == 1 && numarVeciniVii > 3)
				matrice[i][j] = 0;
			
			}
		
		}
	//BORDARE

	for(i = 0; i <= numarLinii + 1; i++)
		for(j = 0; j <= numarColoane + 1; j++)
		{
			if(i == 0 && j == 0)
				matrice[i][j] = matrice[numarLinii][numarColoane];

			if(i == 0)
				if( j > 0)
					if( j < numarColoane + 1)
						matrice[i][j] = matrice[numarLinii][j];	
	
			if(i == 0 && j == (numarColoane + 1) )
				matrice[i][j] = matrice[numarLinii][1];

			if(i > 0)
				if( i < numarLinii + 1)
					if( j == 0)
						matrice[i][j] = matrice[i][numarColoane];

			if(i == numarLinii + 1 )
				if( j == 0)
					matrice[i][j] = matrice[1][numarColoane];

			if(i == numarLinii + 1)
				if( j > 0)
					if( j < numarColoane + 1)
						matrice[i][j] = matrice[1][j];

			if(i == (numarLinii +1) && j == (numarLinii + 1) )
				matrice[i][j] = matrice[1][1];

			if(i > 0 )
				if( i < numarLinii +1)
					if( j == numarColoane +1)
						matrice[i][j] = matrice[i][1];
		}


	//COPIERE
	for(i = 0; i <= numarLinii + 1;i++)
	{
		
		for(j = 0; j <= numarColoane + 1 ; j++)
			{
				matrix[i][j] = matrice[i][j];
			}
	}
	
	
		
	
	count++;
	}
	
	for(i = 1 ; i <= numarLinii; i++)
	{
		for(j = 1; j <= numarColoane; j++){
			if(matrice[i][j] == 0)
				fprintf(out,"%s ",".");
			else if(matrice[i][j] == 1)
				fprintf(out,"%s ","X");
		}
	fprintf(out,"\n");
	}
	
	fclose(in);
	fclose(out);
	return 0;
}






