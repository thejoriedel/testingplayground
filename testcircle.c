#include <stdio.h>

int main() {
    double radius, circumference, area;
    double pi = 3.14159265;

    printf("Enter the radius: ");
    scanf("%lf", &radius);

    area = radius * radius * pi;
    circumference = 2.0 * radius * pi;

    printf("The radius is %lf.\n", radius);
    printf("The area is %lf.\n", area);
    printf("The circuference is %lf.\n", circumference);

    return 0;
}