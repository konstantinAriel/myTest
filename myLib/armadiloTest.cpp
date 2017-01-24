//
// Created by kosta on 15/01/17.
//
#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

int main()
{
    mat A(5, 5, fill::randu);
    double x = A(1,2);
    A.print("A:");
    cout << "x:=\n" << x << "\n";
    mat B = A + A;
    mat C = A * B;
    mat D = A % B;

    cx_mat X(A,B);
    X.print("X:");
    B.zeros();
    B.set_size(10,10);
    B.ones(5,6);

    B.print("B:");

    mat::fixed<5,6> F;

    double aux_mem[24];
    mat H(&aux_mem[0], 4, 6, false);  // use auxiliary memory
    return 0;
}

