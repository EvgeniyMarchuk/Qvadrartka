#include "TXlib.h"
#include "headers.h"

                   //fseek
                   //ftell

int main()
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
    return 0;
}
