//
//              LAPACK++ 1.1 Linear Algebra Package 1.1
//               University of Tennessee, Knoxvilee, TN.
//            Oak Ridge National Laboratory, Oak Ridge, TN.
//        Authors: J. J. Dongarra, E. Greaser, R. Pozo, D. Walker
//                 (C) 1992-1996 All Rights Reserved
//
//                             NOTICE
//
// Permission to use, copy, modify, and distribute this software and
// its documentation for any purpose and without fee is hereby granted
// provided that the above copyright notice appear in all copies and
// that both the copyright notice and this permission notice appear in
// supporting documentation.
//
// Neither the Institutions (University of Tennessee, and Oak Ridge National
// Laboratory) nor the Authors make any representations about the suitability 
// of this software for any purpose.  This software is provided ``as is'' 
// without express or implied warranty.
//
// LAPACK++ was funded in part by the U.S. Department of Energy, the
// National Science Foundation and the State of Tennessee.


//#include "lapack++.h"

#include <stdlib.h>
#define LA_BOUNDS_CHECK
#include "lafnames.h"
#include LA_LOWER_TRIANG_MAT_DOUBLE_H

void mult2(double* v, int len)
{
    for (int i=0; i<len; i++)
        v[i] *= 2;
}

LaLowerTriangMatDouble madd(const LaLowerTriangMatDouble &A, const LaLowerTriangMatDouble &B)
{
if (A.debug())
{
    cout << ">>> madd(A,B) \n";
    cout << "    A: " << A.info() << endl;
    cout << "    B: " << B.info() << endl;
}

    if (A.size(0) != B.size(0) || A.size(1) != B.size(1))
    {
        cerr << "LaLowerTriangMatDouble madd(LaLowerTriangMatDouble &A, LaLowerTriangMatDouble &B): \
            non-conformant arrays.\n";

        return LaLowerTriangMatDouble(0,0);     // 0x0 matrix
    }

    int i, j;
    LaLowerTriangMatDouble result(A.size(0), A.size(1));

    int M = A.size(0);
    int N = A.size(1);

    for (j=0; j<N; j++)
        for (i=j; i<M; i++)
            result(i,j) = 
                B(i,j) +
                A(i,j); 

if (A.debug())
{
    cout << "   A+B: " << result.info() << endl;
    cout << "<<< madd(A,B)\n";
}
    return result;

}
            
int main(int argc, char *argv[])
{
    int M, N;
    int i,j;

    if (argc < 3) exit(1);

    M = atoi(argv[1]);
    N = atoi(argv[2]);
    
    double v[100]; // = {4.0};
    for (int k=0;k<100;k++) v[k] = 4.0;
    
    cout << "Program Name: " << argv[0] << endl;
    
    // Test constructors
    //
    LaLowerTriangMatDouble A;
    cout << endl << "null consturctor " << endl;
    cout << "A(): " << A.info() << endl;

    LaLowerTriangMatDouble C(M,N);
    cout << endl << "(int, int) constructor " << endl;
    cout << "C(M,N): " << C.info() << endl;

    LaLowerTriangMatDouble D(C);        // D is also N,N
    cout << endl << "X(const &X) constructor " << endl;
    cout << "D(C) :" << D.info() << endl;

    cout << "D(i,j) = 3.3" << endl;

    for (j=0;j<N; j++)
        for (i=0; i<M; i++)
        {
            D(i,j) = 3.3;
        }

    LaLowerTriangMatDouble G;
    G.ref(D);       // D is also N,N
    cout << endl << "test ref and inject " << endl;
    cout << "G.ref(D) :" << G.info() << endl;
    cout << "G:\n" << G << endl;
    G = C;
    cout << endl << "G = C\n" << "G: " << G.info() << endl;
    cout << "G:\n" << G << endl;

    LaLowerTriangMatDouble F(v, 10, 10);    //create a 10x10 column-major
    cout << endl << "(double *, int , int) constructor" << endl;
    cout << "F(v,10,10): " << F.info() << endl;

    LaLowerTriangMatDouble E(C);
    cout << endl << "X(const &X) constructor " << endl;
    cout << "E(C): " << E.info() << endl;


    cout << endl << "test INDEX_CHK\n";
    for (j=0;j<N; j++)
        for (i=0; i<M; i++)
            C(i,j) = i + j/100.0;

    cout << endl;   
    cout << "test operator(int, int)"  << endl;
    cout << "Initalize C(i,j) = i + j/100.0 " << endl;
    cout << "C:\n" << C.info() << endl;
    cout <<  C << endl;

    cout << endl;
    C.debug(1);
    cout << "test C.debug(int): " << endl;
    cout << "C: " << C << endl;
    C.debug(0);

    cout << endl;
    cout << "test outofbounds check\n";
    cout << "double tmp = C(1,3)\n";
    double tmp = C(1,3);
    cout << "tmp: " << tmp << endl;

    E = 5.55;
    cout << endl;
    cout << "operator=(double) " << endl;
    cout << "E = 5.55 : " << E.info() << endl;
    cout << "E:\n" << endl;
    cout <<  E << endl;

    D.copy(C);
    cout << endl;
    cout << " D.copy(C): " << D.info() << endl;
    cout << "D:\n" << endl;
    cout << D << endl;

    D.ref(C);
    cout << endl;
    cout << " D.ref(C): " << D.info() << endl;
    cout << D << endl;

    cout << endl;
    cout << "test automatic destructuion of temporaries: " << endl;
    LaLowerTriangMatDouble B;
    for (int c=0; c<10; c++)
    {
        B.ref(C);
        cout << "B.ref(C)): " << B.info() << endl;
    }

    C.ref(C);
    cout << endl;
    cout <<"test C.ref(C) case works correctly." << endl;
    cout << "C.ref(C) " << C.info() << endl;

    return 0;
}
