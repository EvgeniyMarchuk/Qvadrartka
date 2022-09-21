#include "headers.h"

void all_job()
{
    int counter_of_str = string_counter();

    FILE *input = NULL;
    input = fopen("input.txt", "r");

    for(int i = 0; i < counter_of_str; i++){
        double a = NAN, b = NAN, c = NAN;

        int counter = 0, counter2 = 0;

        input_from_file(input, &a, &b, &c, &counter2);

        double x1 = NAN, x2 = NAN;
        solve(a, b, c, &x1, &x2, &counter, counter2);

        output_in_file(counter, x1, x2);
    }
    fclose(input);
}


int string_counter(){

    FILE *input = NULL;
    input = fopen("input.txt", "r");

    int counter_slash = 0;
    int ch = getc(input);

    while (ch != EOF){
        if (ch == '\n')
            counter_slash++;
        ch = getc(input);
    }

    fclose(input);

    return counter_slash + 1;
}

int input_from_file(FILE *input, double *a, double *b, double *c, int *counter2){


    if (input == NULL){

        printf("Can't use file\n");
        assert (0);
    }

    else{

        *counter2 += fscanf(input, "%lf %lf %lf", a, b, c);
        //printf("%lf %lf %lf", *a, *b, *c);

        return(*counter2);
    }
}



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

    double discr = (b*b - 4*a*c);

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
        if (!(is_zero(b))){
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
            discr = sqrt(discr);
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

/*double compare_two(double num1, double num2){
    return (fabs(num1 - num2) < EPSILON);
}*/


int is_zero(double num)
{
    return (fabs(num) < EPSILON);
}


void output_in_file(int counter, double x1, double x2){

    FILE *output;
    output = fopen("output.txt", "a");

    switch(counter){
        case ZERO:
            fprintf(output, "No solutions\n");
            break;
        case ONE_ROOT:
            fprintf(output, "The root of equatoin: x = %.2f\n", x1);
            break;
        case TWO_ROOTS:
            fprintf(output, "The roots of equation: x1 = %.2f, x2 = %.2f\n", x1, x2);
            break;
        case INF:
            fprintf(output, "Any numbers\n");
            break;
        default:
            fprintf(output, "Enterned incorrectly coefficients\n");
    }
    fclose(output);
}
