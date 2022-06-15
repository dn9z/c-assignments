#include <stdio.h>
#include "matrix.h"
#include "tools.h"
#include "escapesequenzen.h"

int const MaxRows = 5;
int const MaxColumns = 5;

//Funktionsdefinitonen//

int getNumberOfRows(int Row, int Col, int MatrixNo) //gibt mir die anzahl der zeilen 
{
	int n; //Dummy Varibale Testet ob der nutzer eine Zahl eingebeben hat.
	int Rows;

	do
	{

		POSITION(Row,Col);
		printf("Geben Sie bitte die Zeilenanzahl der %i. Matrix ein (1..%i):",MatrixNo, MaxRows);
		n=scanf("%i",&Rows);
		
		clearBuffer();
          
		if (n==0 || Rows>MaxRows || Rows <1)
		{
			printf("eingabe ist keine gültige zahl");
			n=0;
		}
	}while(!n);
	return Rows;
}

int getNumberOfColumns(int Row, int Col, int MatrixNo)     //gibt mir die anzahl der spalten
{
	int m; //Dummy Varibale Testet ob der nutzer eine Zahl eingebeben hat.
   int Cols;

	do
	{
		POSITION(Row,Col);
		printf("Geben Sie bitte die Spaltenanzahl der %i. Matrix ein (1..5):",MatrixNo);
		m=scanf("%i",&Cols);
		clearBuffer();
		if (m==0 || Cols>5 || Cols <1)
		{
			printf("eingabe ist keine gültige zahl");
			m=0;
		}
	}while(!m);
	return Cols;
}

 void getMatrix(int Row, int Col, int RowCount, int ColCount, int Matrix[MaxRows][MaxColumns])
 {
	int j,i, n, Zahl;
	
	POSITION(Row, Col);
	for(i=0; i<RowCount; i++) 
	{

		printf("| ");

		for(j=0; j<ColCount; j++) 
		{
			printf ("____ ");
		}
		printf ("|\n");
	}
	
	

	for(i=0; i<RowCount; i++) 
	{
		for(j=0; j<ColCount; j++) 
		{
			do
			{
				POSITION(Row + i, Col + j * 5 + 2);
				n = scanf("%i",&Zahl);
				clearBuffer();
				if (Zahl < -999 || Zahl > 9999 || n == 0)
				{
					n = 0;
					POSITION(Row + i, Col + j * 5 + 2);
					printf("____ ");
					// printf("eingabe ist keine gültige zahl oder liegt nicht im wertebereich -999 - 9999");
				}
			} while (!n);
			POSITION(Row + i, Col + j * 5 + 2);
			printf("%4i ", Zahl);
			Matrix[i][j] = Zahl;
		}
		printf ("|\n");
	}

}


void calcMatrix(int RowCount1, int ColCount1, int ColCount2, int M1[MaxRows][MaxColumns], int M2[MaxRows][MaxColumns], int MErg[MaxRows][MaxColumns])
{
	int i,j,k;
	for (i=0; i < RowCount1; i++)
	{
		for (j=0; j < ColCount2;j++)
		{
			MErg[i][j] = 0;
			
			for (k=0;k<ColCount1;k++)
			{
				MErg[i][j]+=M1[i][k]*M2[k][j];
			}
		}

	}
}

int getMaxWidth(int RowCount, int ColCount, int Matrix[MaxRows][MaxColumns])
{
	int i, j, b, max = 4, m;

	for (i = 0; i < RowCount; i++)
		for (j = 0; j < ColCount; j++)
		{
			b = 0;
			m = Matrix[i][j];
			if (m < 0)
			{
				m *= -1;
				b++;
			}
			while (m >= 1)
			{
				m /= 10;
				b++;
			}
			if (b > max)
				max = b;
		}
	return max;
}

void printMatrix(int Row, int Col, int RowCount, int ColCount, int Matrix[MaxRows][MaxColumns])
{
	int i,j;
	int breite = getMaxWidth(RowCount, ColCount, Matrix);

	for(i=0; i<RowCount; i++) 
	{
		POSITION(Row+i,Col);
		printf("| ");

		for(j=0; j<ColCount; j++) 
		{
			printf ("%*i ", breite, Matrix[i][j]);
		}
		printf ("|\n");
	}
	
}
