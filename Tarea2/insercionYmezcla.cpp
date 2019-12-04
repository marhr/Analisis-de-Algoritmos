// Analisis de algoritmos - Tarea 2
// g++ -std=c++11 insercionYmezcla.cpp -o insercionYmezcla
// https://es.wikibooks.org/wiki/Simulaci%C3%B3n_de_algoritmos/Ordenamiento/Externo/Mezcla_Equilibrada

#include <iostream>
#include <Users/mariana/Eigen/Dense>
#include <chrono>
#include <vector>
using namespace std; 
using namespace chrono;

using Eigen::VectorXd;

// funcion que genera los vectores con valores aleatorios
vector<int> generaVector(){
    srand((int)time(0));
    int i = 0;
    vector<int> v;
    while(i++ < 1000000){
        int r = (rand()%1000000)+1;
        v.push_back(r);
    }
    return v;

}
  
// insertion sort
void insercion(VectorXd arreglo, int n){  
    int i, aux, k;  
    for (i = 1; i < n; i++){ 

        aux = arreglo[i];  
        k = i-1;  
  
        while (k >= 0 && arreglo[k] > aux){  

            arreglo[k+1] = arreglo[k];  
            k = k-1;  

        }  
        arreglo[k+1] = aux;  
    }  
}  

// // merge sort
// void divide(VectorXd arreglo, int salto){
	
// 	VectorXd F1;
// 	VectorXd F2;

// 	for (int i = 0; i < arreglo.size()-1; i+salto){
// 		cout << "i: " << i << endl;
// 		F1 = arreglo.segment(i,salto);
// 		i+=salto;
// 		F2 = arreglo.segment(i,salto);
// 	}
// 	cout << F1 << endl;
// 	cout << F2 << endl;
// 	// combina(F1,F2,salto)
// }

// void mezcla(VectorXd arreglo){

//     divide(arreglo, 1);

// } 

void combina(VectorXd F1, VectorXd F2, int salto){

	int n1 = F1.size();
	int n2 = F2.size();
	int min;
	int longitud;
	VectorXd aux1(salto);
	VectorXd aux2(salto);
	VectorXd arreglo(n1+n2);

	if (n1<n2)
		min = n1;
	else
		min = n2;
	longitud = int(min/salto);

	// fusion
	int i;
	for (i = 0; i < longitud; i++){
		aux1 << F1.segment(i,salto);
		aux2 << F2.segment(i,salto);
		ordena(aux1,aux2)
	}
	// ordena la ultima parte del arreglo
	ordena(F1.segment(i,n1-i),F2.segment(i,n2-i));
}

// seccion del codigo que ordena
VectorXd ordena(VectorXd aux1, VectorXd aux2){
	
	int n = aux1.size()+aux2.size();
	VectorXd arreglo(n);
	int i = 0;
	int j = 0;
	int k = 0;

	while(i<aux1.size() && j<aux2.size()){
		if (aux1[i]<aux2[j]){
			arreglo[k++] = aux1[i++];
		}
		else
			arreglo[k++] = aux2[j++];
	}
	while(i < aux1.size()){
		arreglo[k++] = aux1[i++];
	}
	while(j < aux2.size()){
		arreglo[k++] = aux2[j++]
	}
	return arreglo
}

 
int main(int argc, char const *argv[]){

	cout << "GENERADOR ALEATORIO" << endl;
    vector<int> v = generaVector(); 
    for (int i=0; i < v.size(); i++) 
        cout << v[i] << " ";

	VectorXd p(15);
	p << 9,75,14,68,29,17,31,25,4,5,13,18,72,46,61;

	VectorXd F1(8);
	VectorXd F2(7);
	// particion longitud 4
	F1 << 9,14,68,75,4,5,13,18;
	F2 << 17,25,29,31,46,61,72;

	// tiempo antes de ejecucion
    auto inicio = high_resolution_clock::now();
	ordena(F1,F2);
	// cout <<  << endl;

    // tiempo despues de ejecucion
    auto fin = high_resolution_clock::now();  
    auto duracion = duration_cast<microseconds>(fin-inicio);
    cout << "Tiempo de ejecucion: " << duracion.count() << endl;

//  int arr[] = { 12, 11, 13, 5, 6 };  
//  int n = sizeof(arr) / sizeof(arr[0]);  
   

	return 0;
}