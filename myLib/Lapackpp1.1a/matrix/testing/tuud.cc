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
#include LA_UNIT_UPPER_TRIANG_MAT_DOUBLE_H


void mult2(double* v, int len)
{
    for (int i=0; i<len; i++)
        v[i] *= 2;
}

LaUnitUpperTriangMatDouble madd(const LaUnitUpperTriangMatDouble &A, 
    const LaUnitUpperTriangMatDouble &B)
{
if (A.debug())
{
    cout << ">>> madd(A,B) \n";
    cout << "    A: " << A.info() << endl;
    cout << "    B: " << B.info() << endl;
}

    if (A.size(0) != B.size(0) || A.size(1) != B.size(1))
    {
        cerr << "LaUnitUpperTriangMatDouble madd(LaUnitUpperTriangMatDouble &A, LaUnitUpperTriangMatDouble &B): \
            non-conformant arrays.\n";

        return LaUnitUpperTriangMatDouble(0,0);     // 0x0 matrix
    }

    int M= A.size(0);
    int N = A.size(1);
    int i, j;
    LaUnitUpperTriangMatDouble result(M,N);


    for (j=0; j<N; j++)
        for (i=j; i<M; i++)
            result(i,j) = A(i,j) + B(i,j);

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

    if (argc < 3)
    {
        cerr << "Usage:  " << argv[0] << " M N " << endl;
        exit(1);
    }
    M = atoi(argv[1]);
    N = atoi(argv[2]);
    
    double v[100]; // = {4.0};
    for (int k=0;k<100;k++) v[k] = 4.0;
    
    // Test constructors
    
    LaUnitUpperTriangMatDouble A;
    cout << endl << "null consturctor " << endl;
    cout << "A(): " << A.info() << endl;

    LaUnitUpperTriangMatDouble C(M,N);
    cout << endl << "(int, int) constructor " << endl;
    cout << "C(M,N): " << C.info() << endl;

    C = 0.0;
    cout << endl << "C = 0.0 " << endl;
    cout << "C:\n" << C << endl;

    LaUnitUpperTriangMatDouble D(C);        // D is also N,N
    cout << endl << "X(const &X) constructor " << endl;
    cout << "D(C) :" << D.info() << endl;


    LaUnitUpperTriangMatDouble F(v, 10, 10);        //create a 10x10 column-major
    cout << endl << "(double *, int , int) constructor" << endl;
    cout << "F(v,10,10): " << F.info() << endl;

    LaUnitUpperTriangMatDouble E(C);
    cout << endl << "X(const &X) constructor with submatrices " << endl;
    cout << "E(C): " << E.info() << endl;


    for (j=0;j<N; j++)
        for (i=0; i<M; i++)
            C(i,j) = i + j/100.0;

    cout << endl;   
    cout << "test operator(int, int)"  << endl;
    cout << "Initalize C(i,j) = i + j/100.0 " << endl;
    cout << "C: " << C.info() << endl;
    cout <<  C << endl;


    C(2,3) = 9.0;
    cout << endl;   
    cout << "test operator(int, int) assignment"  << endl;
    cout << "C(2,3) = 9.0\n" << C << endl;
    
    cout << endl;
    cout << "test debug and copy(): " << endl;
    D.debug(1);
    D.copy(C);
    D.debug(0);
    cout << endl;
    cout << "D.copy(C): " << D.info() << endl;
    cout << "D:\n" << D << endl;
    cout << "C:\n" << C << endl;

    E = 5.55;
    cout << endl;
    cout << "operator=(double) " << endl;
    cout << "E = 5.55 : " << E.info() << endl;

    D.ref(C);
    cout << endl;
    cout << "D.ref(C): " << D.info() << endl;
    cout << D << endl;

    cout << endl;
    cout << "test automatic destructuion of temporaries: " << endl;
    LaUnitUpperTriangMatDouble B;
    for (int c=0; c<10; c++)
    {
        B.ref(C);
        cout << "B.ref(C)): " << B.info() << endl;
    }

    C.ref(C);
    cout << endl;
    cout <<"test C.ref(C) case works correctly." << endl;
    cout << "C.ref(C) " << C.info() << endl;
}
