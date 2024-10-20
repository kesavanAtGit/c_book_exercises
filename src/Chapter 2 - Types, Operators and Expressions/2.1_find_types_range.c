#include <limits.h>
#include <stdio.h>
#include <float.h>

int main() {

    printf("unsigned char %d\n", UCHAR_MAX);
    printf("unsigned int %d\n", UINT_MAX);
    printf("unsigned short %d\n", USHRT_MAX);
    printf("unsigned long %ld\n", ULONG_MAX);

    printf("float min %f\n", FLT_MIN);
    printf("float max %f\n", FLT_MAX);

    printf("double min %f\n", DBL_MIN);
    printf("double max %f\n", DBL_MAX);

    printf("long double min %Lf\n", LDBL_MIN);
    printf("long double max %Lf\n", LDBL_MAX);

    printf("char min: %d\n", CHAR_MIN);
    printf("char max: %d\n", CHAR_MAX);

    printf("int min: %d\n", INT_MIN);
    printf("int max: %d\n", INT_MAX);

    printf("short min: %d\n", SHRT_MIN);
    printf("short max: %d\n", SHRT_MAX);

    printf("long min: %ld\n", LONG_MIN);
    printf("long max: %ld\n", LONG_MAX);

    return 0;
}
