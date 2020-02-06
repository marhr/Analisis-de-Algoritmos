// Problema de la mochila - programacion dinamica
// Mariana Hernandez 150845
// g++ -std=c++11 knapsack.cpp -o knapsack

#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;

void print(std::vector<int> vec){
	int dim = vec.size();
	for (int i = 0; i < dim; i++){
		cout << vec[i] << " ";
	}
}

void knapsack(int v[], int w[], int n, int W){

	int i,j;
	int T[n+1][W+1];

	

	// dar valores a matriz T
	for (i = 0; i <= n; i++) { 
        for (j = 0; j <= W; j++) { 
            if (i == 0 || j == 0){ 
                T[i][j] = 0; 
            }
            else if (w[i - 1] <= j){ 
                T[i][j] = max(v[i - 1]+T[i - 1][j - w[i - 1]], T[i - 1][j]); 
            }
            else{
                T[i][j] = T[i - 1][j]; 
            }
        } 
    }

    // resultado de la mochila
    int res = T[n][W]; 	

	vector<int> valores;
	vector<int> pesos;
	vector<int> items;
	int pesoMochila = 0;
    j = W; 
    for (i = n; i > 0 && res > 0; i--) { 
                
        if (res == T[i - 1][j]){  
            continue;   
        }      
        else { 
   			pesoMochila +=  w[i-1];
            pesos.push_back(w[i-1]);
            valores.push_back(v[i-1]);
            items.push_back(i);
             
            res = res - v[i - 1]; 
            j = j - w[i - 1]; 
        } 
    }

    cout << "peso: "<< pesoMochila << endl;
    cout << "valor maximo: "<< *max_element(valores.begin(), valores.end()) << endl;
    cout << "valor items: ";
    print(valores); 
    cout << "\nitems: ";
    print(items);

}

// funcion que devuelve el maximo de dos enteros
int max(int a, int b){
	return (a > b)? a : b; 
}


int main(int argc, char const *argv[])
{
	int v[] = {7,10,11,5,25,50,15,12,6,4,5,30};
	int w[] = {11,7,5,4,3,3,3,2,2,2,2,1};
	int n = 12;
	int W = 20;
	knapsack(v,w,n,W);

	return 0;
}