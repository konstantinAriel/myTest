//      LAPACK++ (V. 1.1 Beta)
//      (C) 1992-1996 All Rights Reserved.

#include "lafnames.h"
#include LA_LOWER_TRIANG_MAT_DOUBLE_H

double LaLowerTriangMatDouble::outofbounds_ = 0;// initialize outofbounds.

int LaLowerTriangMatDouble::debug_ = 0;  // initialize debug to off.

int* LaLowerTriangMatDouble::info_= new int;  // turn off info print flag.

LaLowerTriangMatDouble& LaLowerTriangMatDouble::copy(
        const LaLowerTriangMatDouble &ob)
{

  if (debug())
  {
      cout << " ob: " << ob.info() << endl;
  }


  int M = ob.size(0);
  int N = ob.size(1);
  int i,j;

  resize(ob);

  for (i=0; i<M; i++)
    for (j=0; j<N; j++)
      if (i>=j)
        (*this)(i,j) = ob(i,j);

  if (debug())
  {
    cout << " *this: " << this->info() << endl;
  }

  return *this;
}


ostream &operator<<(ostream &s, const LaLowerTriangMatDouble &ob)
{
  if (*(ob.info_))     // print out only matrix info, not actual values
  {
      *(ob.info_) = 0; // reset the flag
      s << "(" << ob.size(0) << "x" << ob.size(1) << ") " ;
      s << "Indices: " << ob.index(0) << " " << ob.index(1);
      s << " #ref: " << ob.ref_count() ;
      s << " sa:" << ob.shallow();
  }
  else
  {
    int M = ob.size(0);
    int N = ob.size(1);
    int i,j;

    for (i=0; i<M; i++)
    {
     for (j=0;j<N;j++)
     {
       if (i>=j)
       s << ob(i,j) << "  ";
     }
     s << endl;
    }
  }
  return s;
}

 LaLowerTriangMatDouble& LaLowerTriangMatDouble::operator=(double s)
{

  int M = (*this).size(0);
  int N = (*this).size(1);
  int i,j;
  
  for (j=0; j<N; j++)
    for (i=0; i<M; i++)
      if (i>=j)
        (*this)(i,j) = s;

  return *this;
}
     
