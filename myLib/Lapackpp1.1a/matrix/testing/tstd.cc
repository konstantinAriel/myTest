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


//#define LA_VECTOR_DEBUG

#include <stdlib.h>
#include "lafnames.h"
#include LA_SYMM_TRIDIAG_MAT_DOUBLE_H 


int main(int argc, char *argv[])
{
    int N;
    int i,j;

    if (argc < 2)
    {
        cerr << "Usage:  " << argv[0] << "N " << endl;
        exit(1);
    }

    N = atoi(argv[1]);

    // Test constructors
    //
    LaSymmTridiagMatDouble A;
    cout << endl << "null consturctor " << endl;
    cout << "A:\n" << A.info() << endl;

    cout << endl;
    LaSymmTridiagMatDouble C(N);
    cout << endl << "(int, int) constructor " << endl;
    cout << "C(N):\n" << C.info() << endl;

    cout << endl;
    cout << " &C(0,0): " << &C(0,0) << endl;

    cout << endl;
    LaSymmTridiagMatDouble D(C);        // D is also N,N
    cout << endl << "X(const &X) constructor " << endl;
    cout << "D(C):\n" << D.info() << endl;

    cout << endl;
    cout << "test A.ref(C)\n";
    A.ref(C);
    cout << "A:\n" << A.info() << endl;

    cout << "D(i,i) = 3.3" << endl;

    for (j=0;j<N; j++)
        for (i=0; i<N; i++)
        {
            D(i,i) = 3.3;
        }
    cout << endl;
    cout << "D:\n" << D << endl;

    cout << "D(3,2) = 9.0" << endl;
    D(3,2) = 9.0;

    cout << endl;
    cout << "test A.copy(D)\n";
    A.copy(D);
    cout << "A:\n" << A.info() << endl;
    cout << "A:\n" << A << endl;
    

    LaVectorDouble E;
    E.ref(D.diag(0));
    cout << endl;
    cout << "test E.ref(D.diag(0))\n";
    cout << "E:\n" << E << endl;
    cout << endl;
    cout << "D:\n" << D.info() << endl;

    cout << "test error message: E.ref(D.diag(2))\n";
    cout << endl;
    E.ref(D.diag(2));
    
}
