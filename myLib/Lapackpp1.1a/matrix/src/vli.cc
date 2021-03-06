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


#include "lafnames.h"
#include VECTOR_LONG_INT_H

 VectorLongInt::VectorLongInt(int n=0)
{                                                                      
    assert(n>=0);
    p = new vrefLongInt;
    p->sz = n;                                                          
    p->data = data = new long int[n]; 
    p->ref_count = 1;                        
}                                                                      


VectorLongInt::VectorLongInt( const VectorLongInt& m)
{
// old, deep copy semantics
#if 0
    int i, N = m.size();

    p = new vrefLongInt;
    p->sz = m.size();

    p->ref_count = 1;
    p->data = data = new long int[m.size()];
    for (i=0;i<N;i++) data[i] = m(i);
#endif

// shallow assignment semantics

    p = m.p;
    data = m.data;
    p->ref_count++;
}

 VectorLongInt::VectorLongInt(long int *d, int n)
{                                                                      
    p = new vrefLongInt;
    p->sz = n;                                                          
    p->ref_count = 2; 
    p-> data = data = d;                        
}                                                                      
                                                                       
                                                                       

 VectorLongInt::~VectorLongInt()
{

        if (--(p->ref_count) == 0)              // perform garbage col.
        {
           delete [] p->data;
           delete p;
        }
}

VectorLongInt::VectorLongInt(int n, long int scalar)
{                                                                      
    p = new vrefLongInt;
    p->sz = n;                                                          
    p->ref_count = 1;                        
    p->data = data = new long int[n]; 
    for (int i=0; i<n; i++)                                            
        data[i] = scalar;                                            
}                                                                      
                                                                       


// this actually frees memory first, then resizes it.  it reduces
// internal fragmentation of memory pool, and the resizing of
// matrices > 1/2 available memory.

int VectorLongInt::resize(int d)
{

    if (d<0)                // do nothing if invalid size
    {
        return size();
    }
    else
    {
        ref(VectorLongInt(0));  // possibilby free up destination
        if (d>0)
            ref(VectorLongInt(d));
    }
    return size();
}


VectorLongInt& VectorLongInt::inject( VectorLongInt& m)
{
    if (m.size() != size())
    {
          cerr << "VectorLongInt::inject(): vector sizes do not match.\n";
      return *this;
    }
    int N = size();
    for (int i=0; i<N; i++)
        (*this)(i) = m(i);

    return *this;
}


VectorLongInt& VectorLongInt::copy(const VectorLongInt &m)
{
#if 0
        if (null()) resize(m.size());

        if (size() != m.size())
           cerr << "VectorLongInt::copy(VectorLongInt &): incompatible vector \
                sizes : "<< size() << " vs. " << m.size() << ".\n";
        else
#endif // 0


#if 0
    resize(0);                  // free up destination

    int N = m.size();
    VectorLongInt tmp(N);

    for (int i=0; i<N; i++)     // should use memcpy() here...
       (*this)(i) = m(i);

    ref(tmp);
    return *this;

#endif
    int N = m.size();
    resize(N);

    for (int i=0; i<N; i++)
        data[i] = m.data[i];

    return *this;
}


ostream& operator<<(ostream& s, const VectorLongInt& m)
{
        if (m.p)
        {
                int n = m.size();
                for (int i=0; i<n; i++)
                        s << m(i) << "  ";
                s << "\n";
        }
        else s << "NULL VectorLongInt.\n";
    return s;
}



 VectorLongInt& VectorLongInt::operator=(long int scalar)
{
    for (int i=0; i<size(); i++)
            data[i] = scalar;
    return *this;
}
