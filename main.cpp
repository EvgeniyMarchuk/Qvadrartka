#include "TXlib.h"
#include "headers.h"

                   //fseek
                   //ftell

int main()
{

    FILE *input = NULL;
    input = fopen("input.txt", "rb");

    /*while (1) {

        if (fscanf ("%lg %lg %lg") != 3) {

            if (fgets () == NULL)
                break;
    }*/
    printf("here");
    int counter_slash = 0;
    //while((int c = fgets(mas, LEN, input)) != NULL){
    //    while ((char g = fgets(mas, LEN, input)) != "\n"){
    while (int c = fgetc(input) != EOF){
        if (c = "\n"){
            counter_slash++;
        }
    }
    fclose(input);

    for(int i = 0; i < counter_slash; i++){
        double a = NAN, b = NAN, c = NAN;

        int counter = 0, counter2 = 0;

        input_from_file(&a, &b, &c, &counter2);

        double x1 = 0, x2 = 0;
        solve(a, b, c, &x1, &x2, &counter, counter2);

        output_in_file(counter, x1, x2);
    }
    return 0;
}
