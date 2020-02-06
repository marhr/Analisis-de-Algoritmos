// Simplex
// Mariana Hernandez 150845
// g++ -std=c++11 simplex.cpp -o simplex

#include <iostream>
#include <vector>
#include <eigen3/Eigen/Dense>
using namespace std;
using Eigen::MatrixXd;
using Eigen::MatrixXf;
using Eigen::VectorXd;
using Eigen::VectorXf;
using Eigen::ArrayXXf;

void simplex(MatrixXd inicial){	

	int n = inicial.rows(); //num. renglones
	int m = inicial.cols(); //num. columnas
	MatrixXd nueva(n,m);

	MatrixXd comprobracion = inicial.row(n-1);
	bool f = (comprobracion.array() <= 0).all();
	while(f){
		
		// obtener columna pivote
		MatrixXd last = inicial.row(n-1);
		MatrixXf::Index minRow, minCol;
	  	float min = last.minCoeff(&minRow, &minCol);
		// obtener fila pivote
		VectorXd division(n);
		for(int i=0; i<n; i++){
			division[i] = int(inicial.col(m-1)[i]/inicial.col(minCol)[i]);	
		}
		MatrixXf::Index filaPivote;
		float pivote = division.segment(0,n-1).minCoeff(&filaPivote);
		double valorPivote = inicial(filaPivote,minCol);
		// reemplazar variables de holgura
		VectorXd holgura = (1/valorPivote)*inicial.row(filaPivote);
		nueva.row(filaPivote) = holgura;
		// calcular nuevos coeficientes
		
		for (int i = 0; i < n; i++){
			cout << "i: " << i << endl;
				
			if (i==filaPivote){
				//i++;
			}
			else{
				VectorXd a=inicial.row(i).transpose();
				VectorXd b=inicial(i,minCol)*holgura;
				VectorXd dummy = a-b;
				nueva.row(i) = dummy;
				cout << nueva << endl;
			}
		}
		comprobracion = nueva.row(n-1);
		f = (comprobracion.array() <= 0).all();
	}
		// se detiene 
		VectorXd res = nueva.col(m-1);
		cout << "res: " << res << endl;
	
}
	


int main(int argc, char const *argv[])
{
	MatrixXd prueba(4,6);
	prueba << 2,3,1,0,0,25,
			  4,1,0,1,0,32,
			  2,9,0,0,1,54,
			  -21,-31,0,0,0,0;
	
	MatrixXd prueba1(3,6);
	prueba1 << 6,3,3,1,0,1500,
			   2,3,4,0,1,2000,
			   -15,-17,-19,0,0,0;
	simplex(prueba);
	return 0;
}


