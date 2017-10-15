#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>

#include <fstream>			//solo para grabar un file externo.
using namespace std;
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
void nombrar1_par2(char *name_space1,int par1){
  sprintf(name_space1,"start_%02d.00_01.val",par1);
return;
}



int main ()
{
  //------------------------------
  int N=10;				// N de la matriz de NxN.
  int P=20;				// % de no definidos deseado (de 0 a 100).
  //------------------------------

  srand (time(NULL));
  ofstream myfile;			//solo para grabar un file externo.
  char nombre_archivo1[50];
  nombrar1_par2(nombre_archivo1,P);	// start_INDEFINIDOS.00_ITERACION.val
  myfile.open (nombre_archivo1);	//solo para grabar un file externo.


  int contador=0;
  int contador_inde=0;
  int contador_A=0;
  int contador_B=0;
  double prop=0.0;
  double opinion_ini;
  int Total_inde = round(0.01*P*pow(N,2));	// Cantidad de indecisos.

//---------------------
std::vector<int> question_numbers;
for (unsigned int i = 1; i <= (N*N); ++i)			// genero un shuffle de un vector de [1 : N*N]
    question_numbers.push_back(i+1);
std::random_shuffle(question_numbers.begin(), question_numbers.end());
//cout << "* = " << question_numbers[10] << endl;
//---------------------

  for(int i=1;i<=(N*N);i++){ 
	 opinion_ini = pow(-1,rand()%2)*(rand() % (200) + 100) / 100.0;		// genera (-1)^rand * (algo entre 1 y 3).
	 while( (opinion_ini<=1) && (opinion_ini>=-1) ){			// Failsafe por si me voy del rango.
		opinion_ini = pow(-1,rand()%2)*(rand() % (200) + 100) / 100.0; 
	}

	for(int j=1;j<=Total_inde;j++){
		if( i==question_numbers[j] ){							// pongo a los no definidos.
			opinion_ini = pow(-1,rand()%2)*(rand() % (100)) / 100.0;		// Failsafe por si me voy del rango.
				while( (opinion_ini>=1) && (opinion_ini<=-1) ){
					opinion_ini = pow(-1,rand()%2)*(rand() % (100)) / 100.0; // genera (-1)^rand * (algo entre 0 y 1).
				}
		}
	}

 	// Cuento la cantidad de personas en los estados:
	if( (opinion_ini<=1) && (opinion_ini>=-1) ) {  contador_inde++;  }
	if(opinion_ini>1){ contador_B++; }
	if(opinion_ini<-1){ contador_A++; }

	myfile << opinion_ini << " ";			//solo para grabar un file externo.
	
	// Genero diferentes filas:
	contador++;
	if(contador==N){				//voy a otra fila.
		contador=0;
		myfile << endl;
	}
  }
//--------------------------------------------------
// Parte gráfica:
double P_A = 100*contador_A/pow(N,2);
double P_cero = 100*contador_inde/pow(N,2);
double P_B = 100*contador_B/pow(N,2);

std::cout << "----------------------------" << endl;
cout << "** Personas indecisas iniciales = " << Total_inde << endl;
std::cout << std::setprecision(4) << "Votantes A: " << contador_A << " (" << P_A << "%)" << endl;
std::cout << std::setprecision(4) << "Votantes 0: " << contador_inde << " (" << P_cero << "%)" << endl;
std::cout << std::setprecision(4) << "Votantes B: " << contador_B << " (" << P_B<< "%)" << endl;
std::cout << "----------------------------" << endl;
 
  return 0;
}
