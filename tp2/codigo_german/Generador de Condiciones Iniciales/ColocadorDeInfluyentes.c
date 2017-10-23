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
/*void nombrar1_par2(char *name_space1,int par1){
  sprintf(name_space1,"start_%03d_01.val",par1);
return;
}
*/

void nombrar1_par2(char *name_space1,int par1,int par2,int par3){
  sprintf(name_space1,"start_%02d.%02d_%02d.val",par1,par2,par3);
return;
}


int main (){
  srand (time(NULL));			// FUERA DEL FOR PRINCIPAL

for(int rd=0;rd<=8;rd++){ 		//Para generar todos los archivos
  int indefinidos=10+rd*10;

for(int rk=0;rk<=(8-rd);rk++){ 		//Para generar todos los archivos
  int influyentes=10+rk*10;

  //------------------------------
  int N=10;				// N de la matriz de NxN
  int digitos=3;			// grado de precisión (usar 3)
//  int indefinidos=20;			// Cantidad de influidos
//  int influyentes=20;			// Cantidad de influyent
  //------------------------------

for(int rr=1;rr<=10;rr++){ 

  ofstream myfile;				//solo para grabar un file externo.
 
  char nombre_archivo1[50];
  nombrar1_par2(nombre_archivo1,indefinidos,influyentes,rr);	// start_INDEFINIDOS.INFLUYENTES_ITERACION.val

  myfile.open (nombre_archivo1);		//solo para grabar un file externo.
  int Nidos=indefinidos;
  int Nyentes=influyentes;
  int contador_yentes_par=Nyentes/2;
  int contador_yentes=0;
  int contador=0;
  int contador2=0;
  int contador_inde=0;
  int contador_A=0;
  int contador_B=0;
  int signo=1;

  double opinion_ini;
  int Total_inde = Nidos+Nyentes;		// Cantidad de influs.
  int print=0;
//---------------------
std::vector<int> question_numbers;
for (unsigned int i = 1; i <= (N*N); ++i)			// genero un shuffle de un vector de [1 : N*N]
    question_numbers.push_back(i+1);
std::random_shuffle(question_numbers.begin(), question_numbers.end());
//cout << "* = " << question_numbers[10] << endl;
//---------------------

  for(int i=1;i<=(N*N);i++){ 
	 opinion_ini = pow(-1,rand()%2)*(rand() % (300)+100) / 100.0;			// genera (-1)^rand * (algo entre 1 y 3).
	 while( (fabs(opinion_ini)>=2.8) ){				
		 opinion_ini = pow(-1,rand()%2)*(rand() % (300)+100) / 100.0;		// Dejo sólo los que están en (-2.8;-1)U(1;2.8).
	}
	//cout << "* = " << opinion_ini << endl;

  for(int j=1;j<=Total_inde;j++){						// Pongo a los que quedan (indefinidos/influyentes).
	if( i==question_numbers[j] ){							

		int RandNum = 1 + (rand() % 2);					// Veo si pongo influyentes o indefinidos.
		if( (Nidos<=0) && (Nyentes>0) ) RandNum=2;			// Si ya puse todos los indefinidos, pongo sólo influyentes.
		if( (Nidos>0) && (Nyentes<=0) ) RandNum=1;			// Si ya puse todos los influyentes, pongo sólo indefinidos.


		//Pongo los indefinidos:
		if( (RandNum==1) && (Nidos>0) ){
			opinion_ini = pow(-1,rand()%2)*(rand() % (100)) / 100.0;
			 while( (fabs(opinion_ini)>1) ){				
				opinion_ini = pow(-1,rand()%2)*(rand() %(100)) / 100.0; // genera (-1)^rand * (algo entre 0 y 1).
			}
		Nidos--;
		//cout << "* = " << opinion_ini << endl;
		}


		//Pongo los influyentes:
		if( (RandNum==2) && (Nyentes>0) ){
			if(contador_yentes_par>=Nyentes){
				signo=-1;
			}
			opinion_ini = signo*(rand() % (100) + 200) / 100.0;
			while( (fabs(opinion_ini)<2.8)  ){
				opinion_ini = signo*(rand() % (100) + 200) / 100.0;
			}
		Nyentes--;
		//cout << "* = " << opinion_ini << endl;
		}



	myfile << "(" << contador << ","  << contador2 << ",0)=" << std::setprecision(digitos) << opinion_ini << endl;
	print=1;	
	}
 }


	if(print<1) myfile << "(" << contador << ","  << contador2 << ",0)=" << std::setprecision(digitos+1) << opinion_ini << endl;
	print=0;	
	contador++;
	if(contador==N){				//voy a otra fila.
		contador=0;
		contador2++;
		//myfile << endl;
	}


	//-------------------------------------------------------------------
	// (extra)Cuento la cantidad de personas en los estados:

	if( (opinion_ini<=1) && (opinion_ini>=-1) ) {  contador_inde++;  }
	if(opinion_ini>1){ contador_B++; }
	if(opinion_ini<-1){ contador_A++; }

	if((opinion_ini>=2.8) || (opinion_ini<=-2.8) ){ contador_yentes++; }


  }
//--------------------------------------------------
myfile << endl;
double P_A = 100*contador_A/pow(N,2);
double P_cero = 100*contador_inde/pow(N,2);
double P_B = 100*contador_B/pow(N,2);

std::cout << "----------------------------" << endl;
cout << "** Cantidad de influyentes total = " << contador_yentes << endl;
std::cout << std::setprecision(4) << "Votantes iniciales A: " << contador_A << " (" << P_A << "%)" << endl;
std::cout << std::setprecision(4) << "Votantes iniciales 0: " << contador_inde << " (" << P_cero << "%)" << endl;
std::cout << std::setprecision(4) << "Votantes iniciales B: " << contador_B << " (" << P_B<< "%)" << endl;
std::cout << "----------------------------" << endl;
}
}} //rd y rk 
  return 0;
}
