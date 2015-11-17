#include <iostream>
#include <cmath>

using namespace std;


void print(double* p, const int N, const double dx,
           const double xmin)
{
   for(int i=0; i<N; i++)
       cout << i*dx + xmin << "\t" << p[i] << endl;
}

 void arrayfilling(double* p, double dx,double xmin, const int N)
 {
   for (int i = 0; i < N; i++) 
   {
     p[i] = exp(-pow(i*dx + xmin,2));
   }
 }    

 void derivatearray(double* p, double dx, double xmax, double xmin, const int N) 
 {
   double temp2, temp1 = p[0];
   p[0] = p[1]/(2*dx);
   for (int i = 1; i < N-1; i++) 
   {
     temp2 = p[i];
     p[i] = (p[i+1]-temp1)/(2*dx);
     temp1 = temp2;
   }
   p[N-1] = temp2/(2*dx); 
   
 }
   
   
   
   
   
   
int main(){
  const int N = 256;
  double p[N];
  const double xmax = 15;
  const double xmin = -15;
  const double dx = (xmax-xmin)/(N-1);

  // call to function which fills array p here
  arrayfilling(p, dx, xmin, N);
  // call to functio which calculates the derivative
  derivatearray(p, dx, xmax, xmin, N);
    print(p,N,dx,xmin);
  
  
  return 0;
}
