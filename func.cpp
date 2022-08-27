#include "headers.h"

int input_from_file(double *a, double *b, double *c, int *counter2){

    //INIT!!!
    FILE *input = NULL;
    input = fopen("input.txt", "rb");
    //check input valid

    if (input == NULL){

        printf("Can't use file\n");
        assert (0);
        //прервать программу
    }

    else{
    //estr = fgets(str , LEN, input);

    *counter2 += fscanf(input, "%lf %lf %lf", a, b, c);

    //fclose(input);

    return(*counter2);
    }
    fclose(input);
}

/*void input(double *a, double *b, double *c)
{
    int counter2 = 0;

    while (counter2 != 3)
    {
        printf("Enter a, b, c (separated by a space):");
        counter2 += scanf("%lf %lf %lf", a, b, c);

        while (getchar() != '\n')
            ;

        if (counter2 != 3)
        {
            printf("Enterned incorrectly coefficients\n");
            counter2 = 0;
        }

    }
}*/

int linear(double b, double c, double *x1, int *counter){
    if (is_zero(b) && is_zero(c)){
        *counter = INF;
        return (*counter);
    }
    else if (!(is_zero(b))){
        *x1 = -c / b;

        *counter = ONE_ROOT;
        return(*counter);
    }
}


int kvadratic(double a, double b, double c, double *x1, double *x2, int *counter){

    double discr = sqrt(b*b - 4*a*c);

    if (is_zero(discr) && !(is_zero(a)) && !(is_zero(b)) && !(is_zero(c))){
        *x1 = -b / (2*a);

        *counter = ONE_ROOT;
        return(*counter);
    }
    else if (!(discr >= 0)){
        *counter = ZERO;
        return(*counter);
    }


    if(is_zero(b)){
        if (-c / a > 0){
            double kvad_for_zero_b = sqrt(-c / a);

            *x1 = kvad_for_zero_b;
            *x2 = - kvad_for_zero_b;

            *counter = TWO_ROOTS;
            return(*counter);
        }
        else if (-c / a < 0){

            *counter = ZERO;
            return(*counter);
        }
        else{
            *x1 = 0;

            *counter = ONE_ROOT;
            return(*counter);
        }
    }
    else if (is_zero(c)){
        if (b != 0){
        *x1 = 0;
        assert(!(is_zero(a)));
        *x2 = -b / a;

        *counter = TWO_ROOTS;
        return(*counter);
        }
        else{
            *x1 = 0;

            *counter = ONE_ROOT;
            return(*counter);
        }
    }
    else{
        if (discr > 0){
            assert(!(is_zero(a)));
            *x1 = (-b + discr) / (2*a);
            *x2 = (-b - discr) / (2*a);

            *counter = TWO_ROOTS;
            return(*counter);
        }
    }
}


int solve(double a, double b, double c, double *x1, double *x2, int *counter, int counter2)
{
    //isfinite (a);
    //assert (x1 != nullptr);
    //if x1 == nullptr
    if (counter2 != 3){
        *counter = ERROR_ROOTS;
        return(*counter);
    }
    else if (isfinite(a) && isfinite(b) && isfinite(c)){
        if (is_zero(a))

            return (linear   (b, c, x1, counter));
        else

            return (kvadratic(a, b, c, x1, x2, counter));
    }
    else{
        *counter = ERROR_ROOTS;
        return(*counter);
    }
}

double compare_two(double num1, double num2){
    return (fabs(num1 - num2) < EPSILON);
}


int is_zero(double num)
{
    return (fabs(num) < EPSILON);
}


void output_in_file(int counter, double x1, double x2){

    FILE *output;
    output = fopen("output.txt", "wb");

    switch(counter){
        case ZERO:
            fprintf(output, "No solutions\n");
            break;
        case ONE_ROOT:
            fprintf(output, "Корень уравнения: x = %.2f\n", x1);
            break;
        case TWO_ROOTS:
            fprintf(output, "Корни уравнения: x1 = %.2f, x2 = %.2f\n", x1, x2);
            break;
        case INF:
            fprintf(output, "Any numbers\n");
            break;
        default:
            fprintf(output, "Enterned incorrectly coefficients\n");
    }
    fclose(output);
}
