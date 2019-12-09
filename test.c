#include <stdio.h>
#include <math.h>

void bla(double *x, double *y, double *z,double ang)
{
    double  x2;
    double  y2;
    double  z2;
    double  hm;

    hm = -(ang * M_PI / 180);
    y2 = *y * cos(hm) - *z * sin(hm);
    z2 = (*y * sin(hm)) + *z * cos(hm);
    *x = x2;
    *y = y2;
    *z = z2;
    printf("%f\t%f\t%f\n",*x, *y, *z);
}

int main()
{
    double  x = 0;
    double  y = 50;
    double  z = 0;
    printf("%f\t%f\t%f\n",x, y, z);
    bla (&x,&y,&z,90);
    bla (&x,&y,&z,90);
    bla (&x,&y,&z,90);
    bla (&x,&y,&z,90);

    return (0);

}