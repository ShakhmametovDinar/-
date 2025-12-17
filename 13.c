#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double y1(double t) {
    return exp(-2.0 * t * t * t / 3.0);
}
double* y2(double x0, double h, int n) {
    double* x = (double*)malloc((n+1) * sizeof(double));
    double t = 0;
    x[0] = x0;
    for (int i = 0; i < n; i++) {
        x[i+1] = x[i]*(1 - 2 * t * t * h);
        t += h;
    }
    return x;
}
double* y3(double x0, double h, int n) {
    double* x = (double*)malloc((n+1) * sizeof(double));
    double t = 0;
    x[0] = x0;
    for (int i = 0; i < n; i++) {
        double t1 += h;
        x[i+1] = x[i] / (1 + 2 * h * t1 * t1);
    }
    return x;
}
int main() {
    double x0=1.0,t = 0;
    double* stable = y2(x0, 0.01, 400); double* nstable = y3(x0, 0.01, 400);
    for (int i = 0; i <= 400; i+=100){
        printf("%lf  Аналитически: %lf   Уст: %lf Er: %lf    НеУст: %lf Er: %lf\n",t,y1(t),stable[i],fabs(stable[i]-y1(t)),nstable[i],fabs(nstable[i]-y1(t)));
        t+=1;
    }
    free(stable);free(nstable);t = 0;
    printf("\n\n");
    double* stable1 = y2(x0, 1, 4); double* nstable1 = y3(x0, 1, 4);
    for (int i = 0; i <= 4; i++){
        printf("%lf  Аналитически: %lf   Уст: %lf Er: %lf    НеУст: %lf Er: %lf\n",t,y1(t),stable1[i],fabs(stable1[i]-y1(t)),nstable1[i],fabs(nstable1[i]-y1(t)));
        t+=1;
    }
    free(stable1);free(nstable1);
    return 0;

}
