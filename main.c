#include<stdio.h>
#include<math.h>
#include "functions.h"

int main()
{
    char restart, output_format;
    double a = 0, b = 0, c = 0;
    unsigned n = 0;
    do
        {
        printf("That program calculates perimeter, area, heights of the triangle, its medians and bisectors\n");
        printf("Allowable length is between 0.001 and 1000\n");

        a = get_side("a");
        b = get_side("b");
        c = get_side("c");

        if ((a + b <= c) || (a + c <= b) || (b + c <= a))
        {
            printf("Invalid input. Sum of two sides of a triangle must be greater than the third one\n");
            printf("Try again? (y/n)\n");
            scanf(" %c", &restart);
            fflush(stdin);

            if (restart == 'y' || restart == 'Y')
            {
                continue;
            }
            if (restart == 'n' || restart == 'N')
            {
                fflush(stdin);
                break;
            }
            printf("Invalid input");
            fflush(stdin);
            break;
        }

        n = get_decimal_places();

        printf("Choose output format: Standard (s) or Exponential (e)\n");
        scanf(" %c", &output_format);
        fflush(stdin);

        const double Perimeter = (a + b + c);
        const double p = Perimeter / 2.0;
        const double S = sqrt(p * (p - a) * (p - b) * (p - c));

        const double Ha = (2.0 * S) / a;
        const double Hb = (2.0 * S) / b;
        const double Hc = (2.0 * S) / c;

        const double Ma= 0.5 * sqrt(2.0 * pow(b, 2) + 2.0 * pow(c, 2) - pow(a, 2));
        const double Mb = 0.5 * sqrt(2.0 * pow(c, 2) + 2.0 * pow(a, 2) - pow(b, 2));
        const double Mc = 0.5 * sqrt(2.0 * pow(a, 2) + 2.0 * pow(b, 2) - pow(c, 2));

        const double Ba = (2.0 / (b + c)) * sqrt(b * c * p * (p - a));
        const double Bb = (2.0 / (a + c)) * sqrt(a * c * p * (p - b));
        const double Bc = (2.0 / (a + b)) * sqrt(a * b * p * (p - c));

        if (output_format == 's' || output_format == 'S')
        {
            printf("\nPerimeter: %.*lf\n", n, Perimeter);
            printf("\nArea: %.*lf\n", n, S);

            printf("\nHeight(a): %.*lf\n", n, Ha);
            printf("Height(b): %.*lf\n", n, Hb);
            printf("Height(c): %.*lf\n", n, Hc);

            printf("\nMedian(A): %.*lf\n", n, Ma);
            printf("Median(B): %.*lf\n", n, Mb);
            printf("Median(C): %.*lf\n", n, Mc);

            printf("\nBisector(A): %.*lf\n", n, Ba);
            printf("Bisector(B): %.*lf\n", n, Bb);
            printf("Bisector(C): %.*lf\n", n, Bc);
        }

        else if (output_format == 'e' || output_format == 'E')
        {
            printf("\nPerimeter: %.*e\n", n, Perimeter);
            printf("\nArea: %.*e\n", n, S);

            printf("\nHeight(a): %.*e\n", n, Ha);
            printf("Height(b): %.*e\n", n, Hb);
            printf("Height(c): %.*e\n", n, Hc);

            printf("\nMedian(A): %.*e\n", n, Ma);
            printf("Median(B): %.*e\n", n, Mb);
            printf("Median(C): %.*e\n", n, Mc);

            printf("\nBisector(A): %.*e\n", n, Ba);
            printf("Bisector(B): %.*e\n", n, Bb);
            printf("Bisector(C): %.*e\n", n, Bc);
        }

        printf("\nRestart the code? (y/n)\n");
        scanf(" %c", &restart);
        fflush(stdin);
    }

    while (restart == 'y' || restart == 'Y');
    if (restart == 'n' || restart == 'N')
    {
        printf("Program is finished\n");
        fflush(stdin);
        return 0;
    }
}
