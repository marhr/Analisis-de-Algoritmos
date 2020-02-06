// Analisis de algoritmos - Tarea 2
// 
// g++ -std=c++11 insercionYmezcla.cpp -o insercionYmezcla

#include <iostream>
#include <eigen3/Eigen/Dense>
#include <chrono>
#include <vector>
#include <fstream>
using namespace std; 
using namespace chrono;
using Eigen::VectorXd;
using Eigen::MatrixXd;

// funcion que genera los vectores con valores aleatorios
VectorXd generaVector(int n){
    srand((int)time(0));
    int i = 0;
    VectorXd v(n); // vector<int> v;
    while(i < n){
        int r = (rand()%n)+1;
        v[i] = r; // v.push_back(r);
        i++;
    }
    return v;

}
  
// insertion sort
VectorXd insercion(VectorXd arreglo, int n){  
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
    return arreglo; 
}  

// mezcla directa
VectorXd mergeSort(VectorXd datos){
        
        int i, j, ca, cb;
        bool flag, fa, fb;
      
        VectorXd a(datos.size());
        VectorXd b(datos.size());

        i = 1;
        while(i < datos.size()){
            flag = true;
            ca = 0;
            cb = 0;
            j = 0;
            while(j < datos.size()){
                if(flag){
                    a[ca++] = datos[j++];
                    if (ca%i == 0)
                        flag = !flag;
                }
                else{
                    b[cb++] = datos[j++];
                    if (cb%i == 0)
                        flag = !flag;
                }
            }
            
            fa = true;
            fb = true;
            ca = 0;
            cb = 0;
            j = 0;
            while(j < datos.size()){
                if(fa && fb){
                    if(a[ca] < b[cb]){
                        datos[j++] = a[ca++];
                        if(ca%i == 0)
                            fa = false;
                    }
                    else{
                        datos[j++] = b[cb++];
                        if((cb%i == 0) || ( ca/i*i+i+cb == datos.size() ))
                            fb = false;
                    }
                }
                else if(fa){
                    datos[j++] = a[ca++];
                    if(ca%i == 0)
                        fa = false;
                }
                else if(fb){
                    datos[j++] = b[cb++];
                    if(cb%i == 0)
                        fb = false;
                }
                else{
                    fa = true;
                    if(datos.size() - (ca+cb) > i)
                        fb = true;
                }
            }
            i*=2;
        }
        return datos;
    }
 
int main(int argc, char const *argv[]){

cout << "GENERADOR ALEATORIO" << endl;
VectorXd v = generaVector(100);
// cout << v << endl; // vector desordenado


// // tiempo antes de ejecucion
//    auto inicio = high_resolution_clock::now();
// VectorXd res1 = insercion(v,v.size());
// // tiempo despues de ejecucion
//    auto fin = high_resolution_clock::now();      
// // cout << res1 << endl; // vector ordenado
//    auto duracion = duration_cast<microseconds>(fin-inicio);
//    cout << "Tiempo de ejecucion: " << duracion.count() << endl;

    
    
// tiempo antes de ejecucion
auto inicio = high_resolution_clock::now();
VectorXd res2 = mergeSort(v);
// tiempo despues de ejecucion
auto fin = high_resolution_clock::now();      
cout << res2 << endl; // vector ordenado
auto duracion = duration_cast<microseconds>(fin-inicio);
cout << "Tiempo de ejecucion: " << duracion.count() << endl;


    // datos para generar la grafica
    // primero se hicieron las pruebas y los resultados se 
    // agregaron manualmente a la matriz datos
    MatrixXd datos(2,13); // en segundos
    datos << 1,2,3,4,5,6,7,8,9,10,50,75,100,
    		 0.050800, 0.185132, 0.415685, 0.738069,
    		 1.141982, 1.664431, 2.225634, 2.918499,
    		 3.647581, 4.501887, 112.419743, 254.296452,
    		 448.730720;
    // codigo que manda los datos al archivo datos.txt
    // para graficar con gnuplot
    ofstream myfile;
    myfile.open ("datos.txt");
    myfile << datos.transpose();
    myfile.close();

    MatrixXd datos1(2,14); // en milisegundos
    datos1 << 1,2,3,4,5,6,7,8,9,10,50,75,100,1000,
    		  0007.356,0015.175,0019.303,0025.219,
    		  0031.672,0036.790,0042.439,0048.692,
    		  0057.821,0062.273,0335.390,0525.583,
    		  0700.871,8300.458;
    // codigo que manda los datos al archivo datos.txt
    // para graficar con gnuplot
    myfile.open ("datos1.txt");
    myfile << datos1.transpose();
    myfile.close();
	

	return 0;
}