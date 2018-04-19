#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100000
#define Ni 200
double DoubleRand(double _max, double _min)
    { 
        return _min + (double)(rand()) / RAND_MAX * (_max - _min); 
    }
    
int InCircle(double x, double y)
{
    if((x*x+y*y)<=1)
    return 1;
    return 0;
}
    
double Pi(int N)
    {
        double x, y;
        int cnt, i;
        srand(time(NULL));
        for(i=0;i<N; i++)
        {
           x=DoubleRand(1.0, 0.0);
           y=DoubleRand(1.0, 0.0);
           cnt+=InCircle(x, y);
        }
        return (double)cnt/N;
    }
    void Operation1()
    {
       int i, N=100000000;
       char FN[50]="a.txt";
       FILE *F;
       F=fopen(FN, "wb");
       for(i=10;i<=N;i*=3)
       fprintf(F," %i: %lf\n",i, Pi(i)*4); 
       fclose(F);
    }
int Dist(double V, double dv, double Vmin)
{
    double dif;
    int n;
    dif=V-Vmin;
    n=dif/dv;
    n=(int)n;
    if(n>=0 && n<Ni)
    return n;
    else if(n>=Ni)
    return Ni;
    else 
    return 0;
    
}
void Distr(double Mol[MAX], double Vel, int Dst[Ni])
    {
        int  i, cnt, interval1, interval2;
        double dE, Dem=0, E1 ,E2, V2, dv ;
        char FN[50]="b.txt";
        FILE *F;
        dv=20*Vel/Ni;
        srand(time(NULL));
        for(i=0; i<MAX; i++)
        {
             Mol[i]=Vel;
        }
       
        for(cnt=0;cnt<MAX*1000;cnt++)
        {
          i=rand()% MAX;
          V2=DoubleRand(-Vel, Vel);
          E1=Mol[i]*Mol[i];
          E2=(Mol[i]+V2)*(Mol[i]+V2);
          dE=E2-E1;
          if(dE<=0 || Dem>=dE)
          {
             
             Dem-=dE;
             interval1=Dist(Mol[i], dv, - 10 * Vel);
             Mol[i]+=V2;
             interval2=Dist(Mol[i], dv, - 10 * Vel);
             if(interval1!=interval2)
             {
                  
                 Dst[interval2]++;
                 Dst[interval1]--;
             }
                  
          }
        }
        printf("x\n");
        F=fopen(FN, "wb");
   
        for(i=0;i<Ni;i++)
        fprintf(F,"%i: %i\n ", i, Dst[i]);
        fclose(F);
        
    }
    void Operation2()
    {
        double Mol[MAX];
        int Dst[Ni], i, n;
        n=MAX/Ni;
        for(i=0;i<Ni;i++)
        Dst[i]=0;
        //Dst[9*Ni/20]=MAX/2;
        Dst[11*Ni/20]=MAX;
        Distr(Mol, 100, Dst);
    }
void main() 
{
    //Operation1();
    Operation2();
}
