#include <stdio.h>
#include <complex.h>

int main() {
    double complex a = 3 + 2*I;
    printf("a = %.2lf + %.2lfi\n", creal(a), cimag(a));
    double complex b = csin(a);
    printf("csin(a) = %.2lf + %.2lfi\n", creal(b), cimag(b));
    return 0;
}
