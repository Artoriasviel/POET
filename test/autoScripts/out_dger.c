#define max(a,b) (((a) < (b))? (b) : (a))
#define min(a,b) (((a) < (b))? (a) : (b))
#include <omp.h>

void dger(const int  M,const int  N,const double  alpha,const double*  X,const int  incX,const double*  Y,const int  incY,double*  A,const int  lda) 
{
   int  i;
   int  j;
   int j_par;
   int i_bk;
   int j_bk;
   int nest1_1_X_cp0;
   int X_buf_index;
   double* X_buf;
   double* _X_buf_fd_0;
   double _X_1_scalar_0;
   double* _X_1_scalar_fd_0;
   double _Y_2_scalar_0;
   double _Y_2_scalar_1;
   double* _Y_2_scalar_fd_0;
   omp_set_num_threads(2);
   #pragma omp  parallel  
    {
    #pragma omp  for private(_Y_2_scalar_fd_0,_Y_2_scalar_0,_Y_2_scalar_1,_X_1_scalar_fd_0,_X_1_scalar_0,_X_buf_fd_0,X_buf,X_buf_index,nest1_1_X_cp0,i_bk,j_bk,i,j_par,j)
    for (j_par=0; j_par<N; j_par+=256) 
      {
         X_buf=(double*)malloc(16*((15+M)/16) * sizeof(double));
         X_buf_index = 0;
         for (nest1_1_X_cp0=0; nest1_1_X_cp0<-15+M; nest1_1_X_cp0+=16) 
           for (i=nest1_1_X_cp0; i<16+nest1_1_X_cp0; i+=1) 
             X_buf[X_buf_index++] = X[i];
         if (nest1_1_X_cp0<M)  
           {
              for (i=nest1_1_X_cp0; i<M; i+=1) 
                X_buf[X_buf_index++] = X[i];
              X_buf_index = X_buf_index+(-M+(16+nest1_1_X_cp0));
              nest1_1_X_cp0 = nest1_1_X_cp0+16;
           }
         for (j_bk=0; j_bk<-15+min(256,N-j_par); j_bk+=16) 
           {
              _X_buf_fd_0 = X_buf;
              for (i_bk=0; i_bk<-15+M; i_bk+=16) 
                {
                   _Y_2_scalar_fd_0 = Y;
                   for (j=0; j<16; j+=2) 
                     {
                        _Y_2_scalar_0 = _Y_2_scalar_fd_0[j_par*incY+j_bk*incY];
                        _Y_2_scalar_1 = _Y_2_scalar_fd_0[j_par*incY+(incY+j_bk*incY)];
                        _X_1_scalar_fd_0 = _X_buf_fd_0;
                        for (i=0; i<16; i+=4) 
                          {
                             _X_1_scalar_0 = _X_1_scalar_fd_0[0];
                             A[i+(i_bk+(j_par*lda+(j_bk*lda+j*lda)))] = A[i+(i_bk+(j_par*lda+(j_bk*lda+j*lda)))]+_X_1_scalar_0*_Y_2_scalar_0;
                             A[i+(i_bk+(j_par*lda+(j_bk*lda+(lda+j*lda))))] = A[i+(i_bk+(j_par*lda+(j_bk*lda+(lda+j*lda))))]+_X_1_scalar_0*_Y_2_scalar_1;
                             _X_1_scalar_fd_0 = 1+_X_1_scalar_fd_0;
                             _X_1_scalar_0 = _X_1_scalar_fd_0[0];
                             A[j*lda+(j_bk*lda+(j_par*lda+(i_bk+(1+i))))] = A[j*lda+(j_bk*lda+(j_par*lda+(i_bk+(1+i))))]+_X_1_scalar_0*_Y_2_scalar_0;
                             A[j*lda+(lda+(j_bk*lda+(j_par*lda+(i_bk+(1+i)))))] = A[j*lda+(lda+(j_bk*lda+(j_par*lda+(i_bk+(1+i)))))]+_X_1_scalar_0*_Y_2_scalar_1;
                             _X_1_scalar_fd_0 = 1+_X_1_scalar_fd_0;
                             _X_1_scalar_0 = _X_1_scalar_fd_0[0];
                             A[j*lda+(j_bk*lda+(j_par*lda+(i_bk+(2+i))))] = A[j*lda+(j_bk*lda+(j_par*lda+(i_bk+(2+i))))]+_X_1_scalar_0*_Y_2_scalar_0;
                             A[j*lda+(lda+(j_bk*lda+(j_par*lda+(i_bk+(2+i)))))] = A[j*lda+(lda+(j_bk*lda+(j_par*lda+(i_bk+(2+i)))))]+_X_1_scalar_0*_Y_2_scalar_1;
                             _X_1_scalar_fd_0 = 1+_X_1_scalar_fd_0;
                             _X_1_scalar_0 = _X_1_scalar_fd_0[0];
                             A[j*lda+(j_bk*lda+(j_par*lda+(i_bk+(3+i))))] = A[j*lda+(j_bk*lda+(j_par*lda+(i_bk+(3+i))))]+_X_1_scalar_0*_Y_2_scalar_0;
                             A[j*lda+(lda+(j_bk*lda+(j_par*lda+(i_bk+(3+i)))))] = A[j*lda+(lda+(j_bk*lda+(j_par*lda+(i_bk+(3+i)))))]+_X_1_scalar_0*_Y_2_scalar_1;
                             _X_1_scalar_fd_0 = 1+_X_1_scalar_fd_0;
                          }
                        _Y_2_scalar_fd_0 = _Y_2_scalar_fd_0+2*incY;
                     }
                   _X_buf_fd_0 = _X_buf_fd_0+16;
                }
              if (i_bk<M)  
                {
                   _Y_2_scalar_fd_0 = Y;
                   for (j=0; j<16; j+=2) 
                     {
                        _Y_2_scalar_0 = _Y_2_scalar_fd_0[j_par*incY+j_bk*incY];
                        _Y_2_scalar_1 = _Y_2_scalar_fd_0[j_par*incY+(incY+j_bk*incY)];
                        _X_1_scalar_fd_0 = _X_buf_fd_0;
                        for (i=0; i<M-i_bk; i+=4) 
                          {
                             _X_1_scalar_0 = _X_1_scalar_fd_0[0];
                             A[i+(i_bk+(j_par*lda+(j_bk*lda+j*lda)))] = A[i+(i_bk+(j_par*lda+(j_bk*lda+j*lda)))]+_X_1_scalar_0*_Y_2_scalar_0;
                             A[i+(i_bk+(j_par*lda+(j_bk*lda+(lda+j*lda))))] = A[i+(i_bk+(j_par*lda+(j_bk*lda+(lda+j*lda))))]+_X_1_scalar_0*_Y_2_scalar_1;
                             _X_1_scalar_fd_0 = 1+_X_1_scalar_fd_0;
                             /*Unroll Check*/if (1+i<M-i_bk)  
                               {
                                  _X_1_scalar_0 = _X_1_scalar_fd_0[0];
                                  A[j*lda+(j_bk*lda+(j_par*lda+(i_bk+(1+i))))] = A[j*lda+(j_bk*lda+(j_par*lda+(i_bk+(1+i))))]+_X_1_scalar_0*_Y_2_scalar_0;
                                  A[j*lda+(lda+(j_bk*lda+(j_par*lda+(i_bk+(1+i)))))] = A[j*lda+(lda+(j_bk*lda+(j_par*lda+(i_bk+(1+i)))))]+_X_1_scalar_0*_Y_2_scalar_1;
                                  _X_1_scalar_fd_0 = 1+_X_1_scalar_fd_0;
                               }
                             /*Unroll Check*/if (2+i<M-i_bk)  
                               {
                                  _X_1_scalar_0 = _X_1_scalar_fd_0[0];
                                  A[j*lda+(j_bk*lda+(j_par*lda+(i_bk+(2+i))))] = A[j*lda+(j_bk*lda+(j_par*lda+(i_bk+(2+i))))]+_X_1_scalar_0*_Y_2_scalar_0;
                                  A[j*lda+(lda+(j_bk*lda+(j_par*lda+(i_bk+(2+i)))))] = A[j*lda+(lda+(j_bk*lda+(j_par*lda+(i_bk+(2+i)))))]+_X_1_scalar_0*_Y_2_scalar_1;
                                  _X_1_scalar_fd_0 = 1+_X_1_scalar_fd_0;
                               }
                             /*Unroll Check*/if (3+i<M-i_bk)  
                               {
                                  _X_1_scalar_0 = _X_1_scalar_fd_0[0];
                                  A[j*lda+(j_bk*lda+(j_par*lda+(i_bk+(3+i))))] = A[j*lda+(j_bk*lda+(j_par*lda+(i_bk+(3+i))))]+_X_1_scalar_0*_Y_2_scalar_0;
                                  A[j*lda+(lda+(j_bk*lda+(j_par*lda+(i_bk+(3+i)))))] = A[j*lda+(lda+(j_bk*lda+(j_par*lda+(i_bk+(3+i)))))]+_X_1_scalar_0*_Y_2_scalar_1;
                                  _X_1_scalar_fd_0 = 1+_X_1_scalar_fd_0;
                               }
                          }
                        _Y_2_scalar_fd_0 = _Y_2_scalar_fd_0+2*incY;
                     }
                   _X_buf_fd_0 = _X_buf_fd_0+16;
                }
           }
         if (j_bk<min(256,N-j_par))  
           {
              _X_buf_fd_0 = X_buf;
              for (i_bk=0; i_bk<-15+M; i_bk+=16) 
                {
                   _Y_2_scalar_fd_0 = Y;
                   for (j=0; j<min(256-j_bk,-j_bk+(N-j_par)); j+=2) 
                     {
                        _Y_2_scalar_0 = _Y_2_scalar_fd_0[j_par*incY+j_bk*incY];
                        _Y_2_scalar_1 = _Y_2_scalar_fd_0[j_par*incY+(incY+j_bk*incY)];
                        _X_1_scalar_fd_0 = _X_buf_fd_0;
                        for (i=0; i<16; i+=4) 
                          {
                             _X_1_scalar_0 = _X_1_scalar_fd_0[0];
                             A[i+(i_bk+(j_par*lda+(j_bk*lda+j*lda)))] = A[i+(i_bk+(j_par*lda+(j_bk*lda+j*lda)))]+_X_1_scalar_0*_Y_2_scalar_0;
                             /*Unroll Check*/if (1+j<min(256-j_bk,-j_bk+(N-j_par)))  
                               A[i+(i_bk+(j_par*lda+(j_bk*lda+(lda+j*lda))))] = A[i+(i_bk+(j_par*lda+(j_bk*lda+(lda+j*lda))))]+_X_1_scalar_0*_Y_2_scalar_1;
                             _X_1_scalar_fd_0 = 1+_X_1_scalar_fd_0;
                             _X_1_scalar_0 = _X_1_scalar_fd_0[0];
                             A[j*lda+(j_bk*lda+(j_par*lda+(i_bk+(1+i))))] = A[j*lda+(j_bk*lda+(j_par*lda+(i_bk+(1+i))))]+_X_1_scalar_0*_Y_2_scalar_0;
                             /*Unroll Check*/if (1+j<min(256-j_bk,-j_bk+(N-j_par)))  
                               A[j*lda+(lda+(j_bk*lda+(j_par*lda+(i_bk+(1+i)))))] = A[j*lda+(lda+(j_bk*lda+(j_par*lda+(i_bk+(1+i)))))]+_X_1_scalar_0*_Y_2_scalar_1;
                             _X_1_scalar_fd_0 = 1+_X_1_scalar_fd_0;
                             _X_1_scalar_0 = _X_1_scalar_fd_0[0];
                             A[j*lda+(j_bk*lda+(j_par*lda+(i_bk+(2+i))))] = A[j*lda+(j_bk*lda+(j_par*lda+(i_bk+(2+i))))]+_X_1_scalar_0*_Y_2_scalar_0;
                             /*Unroll Check*/if (1+j<min(256-j_bk,-j_bk+(N-j_par)))  
                               A[j*lda+(lda+(j_bk*lda+(j_par*lda+(i_bk+(2+i)))))] = A[j*lda+(lda+(j_bk*lda+(j_par*lda+(i_bk+(2+i)))))]+_X_1_scalar_0*_Y_2_scalar_1;
                             _X_1_scalar_fd_0 = 1+_X_1_scalar_fd_0;
                             _X_1_scalar_0 = _X_1_scalar_fd_0[0];
                             A[j*lda+(j_bk*lda+(j_par*lda+(i_bk+(3+i))))] = A[j*lda+(j_bk*lda+(j_par*lda+(i_bk+(3+i))))]+_X_1_scalar_0*_Y_2_scalar_0;
                             /*Unroll Check*/if (1+j<min(256-j_bk,-j_bk+(N-j_par)))  
                               A[j*lda+(lda+(j_bk*lda+(j_par*lda+(i_bk+(3+i)))))] = A[j*lda+(lda+(j_bk*lda+(j_par*lda+(i_bk+(3+i)))))]+_X_1_scalar_0*_Y_2_scalar_1;
                             _X_1_scalar_fd_0 = 1+_X_1_scalar_fd_0;
                          }
                        _Y_2_scalar_fd_0 = _Y_2_scalar_fd_0+2*incY;
                     }
                   _X_buf_fd_0 = _X_buf_fd_0+16;
                }
              if (i_bk<M)  
                {
                   _Y_2_scalar_fd_0 = Y;
                   for (j=0; j<min(256-j_bk,-j_bk+(N-j_par)); j+=2) 
                     {
                        _Y_2_scalar_0 = _Y_2_scalar_fd_0[j_par*incY+j_bk*incY];
                        _Y_2_scalar_1 = _Y_2_scalar_fd_0[j_par*incY+(incY+j_bk*incY)];
                        _X_1_scalar_fd_0 = _X_buf_fd_0;
                        for (i=0; i<M-i_bk; i+=4) 
                          {
                             _X_1_scalar_0 = _X_1_scalar_fd_0[0];
                             A[i+(i_bk+(j_par*lda+(j_bk*lda+j*lda)))] = A[i+(i_bk+(j_par*lda+(j_bk*lda+j*lda)))]+_X_1_scalar_0*_Y_2_scalar_0;
                             /*Unroll Check*/if (1+j<min(256-j_bk,-j_bk+(N-j_par)))  
                               A[i+(i_bk+(j_par*lda+(j_bk*lda+(lda+j*lda))))] = A[i+(i_bk+(j_par*lda+(j_bk*lda+(lda+j*lda))))]+_X_1_scalar_0*_Y_2_scalar_1;
                             _X_1_scalar_fd_0 = 1+_X_1_scalar_fd_0;
                             /*Unroll Check*/if (1+i<M-i_bk)  
                               {
                                  _X_1_scalar_0 = _X_1_scalar_fd_0[0];
                                  A[j*lda+(j_bk*lda+(j_par*lda+(i_bk+(1+i))))] = A[j*lda+(j_bk*lda+(j_par*lda+(i_bk+(1+i))))]+_X_1_scalar_0*_Y_2_scalar_0;
                                  /*Unroll Check*/if (1+j<min(256-j_bk,-j_bk+(N-j_par)))  
                                    A[j*lda+(lda+(j_bk*lda+(j_par*lda+(i_bk+(1+i)))))] = A[j*lda+(lda+(j_bk*lda+(j_par*lda+(i_bk+(1+i)))))]+_X_1_scalar_0*_Y_2_scalar_1;
                                  _X_1_scalar_fd_0 = 1+_X_1_scalar_fd_0;
                               }
                             /*Unroll Check*/if (2+i<M-i_bk)  
                               {
                                  _X_1_scalar_0 = _X_1_scalar_fd_0[0];
                                  A[j*lda+(j_bk*lda+(j_par*lda+(i_bk+(2+i))))] = A[j*lda+(j_bk*lda+(j_par*lda+(i_bk+(2+i))))]+_X_1_scalar_0*_Y_2_scalar_0;
                                  /*Unroll Check*/if (1+j<min(256-j_bk,-j_bk+(N-j_par)))  
                                    A[j*lda+(lda+(j_bk*lda+(j_par*lda+(i_bk+(2+i)))))] = A[j*lda+(lda+(j_bk*lda+(j_par*lda+(i_bk+(2+i)))))]+_X_1_scalar_0*_Y_2_scalar_1;
                                  _X_1_scalar_fd_0 = 1+_X_1_scalar_fd_0;
                               }
                             /*Unroll Check*/if (3+i<M-i_bk)  
                               {
                                  _X_1_scalar_0 = _X_1_scalar_fd_0[0];
                                  A[j*lda+(j_bk*lda+(j_par*lda+(i_bk+(3+i))))] = A[j*lda+(j_bk*lda+(j_par*lda+(i_bk+(3+i))))]+_X_1_scalar_0*_Y_2_scalar_0;
                                  /*Unroll Check*/if (1+j<min(256-j_bk,-j_bk+(N-j_par)))  
                                    A[j*lda+(lda+(j_bk*lda+(j_par*lda+(i_bk+(3+i)))))] = A[j*lda+(lda+(j_bk*lda+(j_par*lda+(i_bk+(3+i)))))]+_X_1_scalar_0*_Y_2_scalar_1;
                                  _X_1_scalar_fd_0 = 1+_X_1_scalar_fd_0;
                               }
                          }
                        _Y_2_scalar_fd_0 = _Y_2_scalar_fd_0+2*incY;
                     }
                   _X_buf_fd_0 = _X_buf_fd_0+16;
                }
           }
         free(X_buf);
      }
    }
   
}
