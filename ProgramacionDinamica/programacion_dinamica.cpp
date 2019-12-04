// Mariana Hernandez
// 150845
// Analisis de algoritmos - Programacion dinamica
// g++ -std=c++11 programacion_dinamica.cpp -o programacion_dinamica

#include <iostream>
#include <stdio.h>
#include <chrono>
using namespace std;
using namespace chrono;

// ackermann recursivo
int ackermann(int m, int n){
	if (m ==0){
		return n+1;
	}
	else if (m>0 && n==0){
		return ackermann(m-1,1);
	}
	else if(m>0 && n>0){
		return ackermann(m-1,ackermann(m,n-1));
	}
	else
		return -1;

}

// codigo top down
int ackermann_top_down(int m, int n){

	int tabla[100][100];
	if (m ==0){
		tabla[m][n] = n+1;
	}
	else if (m>0 && n==0){
		if (tabla[m-1][1]){
			tabla[m][n] = tabla[m-1][1];
		}
		else tabla[m][n] = ackermann(m-1,1);
	}
	else if(m>0 && n>0){
		if (tabla[m][n-1]){
			if (tabla[m-1][tabla[m][n-1]]){
				tabla[m][n] = tabla[m-1][tabla[m][n-1]];
			}
			else 
				tabla[m][n] = ackermann(m-1,tabla[m][n-1]);			
		}
		else{
			tabla[m][n] = ackermann(m-1,ackermann(m,n-1));
		}
	}
	else
		tabla[m][n] = -1;

	return tabla[m][n];

}

// particion recursivo
int particion(int m, int n){
	if (m == 1 || n == 1){
		return 1;
	}
	else if (m<n){
		return particion(m,m);
	}
	else if (m==n){
		return 1+particion(m,m-1);
	}
	else if(m>n){
		return particion(m,n-1)+particion(m-n,n);
	}
	else
		return -1;
}

// particion top down
int particion_top_down(int m, int n){

	int tabla[100][100];
	if (m == 1 || n == 1){
		tabla[m][n] = 1;
	}
	else if (m<n){
		if (tabla[m][m]){
			tabla[m][n] = tabla[m][m];
		}
		else tabla[m][n] = particion(m,m);
	}
	else if (m==n){
		if (tabla[m][m-1]){
			tabla[m][n] = 1+tabla[m][m-1];
		}
		else tabla[m][n] = 1+particion(m,m-1);
	}
	else if(m>n){
		if (tabla[m][n-1] && tabla[m-n][n]){
			tabla[m][n] = tabla[m][n-1]+tabla[m-n][n];
		}
		else if (tabla[m][n-1] && tabla[m-n][n]==0){
			tabla[m][n] = tabla[m][n-1]+particion(m-n,n);
		}
		else if (tabla[m][n-1]==0 && tabla[m-n][n]){
			tabla[m][n] = particion(m,n-1)+tabla[m-n][n];
		}
		else tabla[m][n] = particion(m,n-1)+particion(m-n,n);
	}
	else
		tabla[m][n] = -1;

	return tabla[m][n];
}


int main(int argc, char const *argv[]){


	// prueba ackermann recursivo
    auto inicio = high_resolution_clock::now();

	double res_acker = ackermann(4,1);

    auto fin = high_resolution_clock::now();  
    auto duracion = duration_cast<microseconds>(fin-inicio);
    cout << "Resultado Ackerman recursivo: " << res_acker << endl;
    cout << "Tiempo de ejecucion: " << duracion.count() << endl;

    // prueba ackermann top down
    inicio = high_resolution_clock::now();

	double res_acker_td = ackermann_top_down(4,1);

	fin = high_resolution_clock::now();
	duracion = duration_cast<microseconds>(fin-inicio);
    cout << "Resultado Ackerman top down: " << res_acker_td << endl;
    cout << "Tiempo de ejecucion: " << duracion.count() << endl;

    // prueba particion recursivo
    inicio = high_resolution_clock::now();

    int res_part = particion(10,2);

    fin = high_resolution_clock::now();
	duracion = duration_cast<microseconds>(fin-inicio);
    cout << "Resultado Particion recursivo: " << res_part << endl;
    cout << "Tiempo de ejecucion: " << duracion.count() << endl;

    // prueba particion top down
    inicio = high_resolution_clock::now();

    int res_part_td = particion_top_down(10,2);

    fin = high_resolution_clock::now();
	duracion = duration_cast<microseconds>(fin-inicio);
    cout << "Resultado Particion top down: " << res_part_td << endl;
    cout << "Tiempo de ejecucion: " << duracion.count() << endl;

	return 0;
}










