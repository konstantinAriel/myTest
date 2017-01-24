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



#include <stdlib.h>
#include "lafnames.h"
#include LA_VECTOR_INT_H

void mult2(int* v, int len)
{
    for (int i=0; i<len; i++)
        v[i] *= 2;
}

LaVectorInt madd(const LaVectorInt &A, const LaVectorInt &B)
{
if (A.debug())
{
    cout << ">>> madd(A,B) \n";
    cout << "    A: " << A.info() << endl;
    cout << "    B: " << B.info() << endl;
}

    if (A.size() != B.size())
    {
        cerr << "LaVectorInt madd(LaVectorInt &A, LaVectorInt &B): \
            non-conformant arrays.\n";

        return LaVectorInt(0);      // 0x0 matrix
    }

    int i;
    LaVectorInt result(A.size());


        for (i=0; i<A.size(); i++)
             result(i) = A(i) + B(i);

if (A.debug())
{
    cout << "   A+B: " << result.info() << endl;
    cout << "<<< madd(A,B)\n";
}
    return result;

}
            
main(int argc, char *argv[])
{
    int N;

    if (argc < 2) exit(1);

    N = atoi(argv[1]);
    
    int v[100];
    int i;
    for (i=0; i<100; i++)
        v[i]=0;
    
    LaIndex I(2,4);
    
    cout << "Program Name: " << argv[0] << endl;
    // Test constructors
    //
    LaVectorInt A;
    cout << endl << "null consturctor " << endl;
    cout << "A(): " << A.info() << endl;

    LaVectorInt C(N);
    cout << endl << "(int) constructor " << endl;
    cout << "C(N) : " << C.info() << endl;

    LaVectorInt B(1,N);
    cout << endl ;
    cout << "(int, int) constructor " << endl;
    cout << "B(N) : " << B.info() << endl;

    LaVectorInt F(v, 10);
    cout << endl ;
    cout << "(int*, int) constructor " << endl;
    cout << "F(v,10): " << F.info() << endl;

    C=5;
    cout << endl;
    cout << "test operator=(int) " << endl;
    cout << "C = 5.5: " << C.info() << endl;
    cout << C << endl;

    C(I)=7;
    C(I);
    cout << endl;
    cout << "test C(const LaIndex&) constructor" << endl;
    cout << "C(I)=7 : " << C(I).info() << endl;
    cout << "C(I):\n" << C(I) << endl;
    cout << C << endl;

    cout << endl;
    cout << "test start(),inc(),end() " << endl;
    cout << "C.start(): " << C.start() << endl;
    cout << "C.inc(): " << C.inc() << endl;
    cout << "C.end(): " << C.end() << endl;

    A.ref(C);
    cout <<endl;
    cout << "test ref(const LaGenMatInt &)" << endl;
    cout << "A.ref(C): "<< A.info() << endl;
    cout << A << endl;

    C = 1;
    A.inject(C);
    cout <<endl;
    cout << "C = 1.1\n";
    cout << "test inject(const LaGenMatInt &)" << endl;
    cout << "A.inject(C): "<< A.info() << endl;
    cout << A << endl;

    A.copy(C);
    cout <<endl;
    cout << "test copy(const LaGenMatInt &)" << endl;
    cout << "A.copy(C): "<< A.info() << endl;
    cout << "       C : "<< C.info() << endl;
    cout << A << endl;


    LaVectorInt D(C);       // D is also N,N
    cout << endl << "test X(const &X) constructor " << endl;
    cout << "D(C) :" << D.info() << endl;

    LaVectorInt T;
    cout << endl;
    cout << "test call to madd()" << endl;
    cout << T.ref(madd(D,C)).info() << endl;
    cout << T << endl;
}
