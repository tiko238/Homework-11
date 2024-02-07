#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include "temp_functions.h"

int main(int argc, char *argv[]) {
    const char *filename = NULL;
    int month = -1;
    int option;

    
    while ((option = getopt(argc, argv, "hf:m:")) != -1) {
        switch (option) {
            case 'h':
                printf("Description of the application functionality:\n");
                printf("-h For select a file please write command -f <filename.csv>\n");
                printf("-f <filename.csv>\tInput csv file for processing\n");
                printf("-m <month number>\tDisplay statistics only for the specified month\n");
                return 0;
            case 'f':
                filename = optarg;
                break;
            case 'm':
                month = atoi(optarg);
                break;
            case '?': 
                if (optopt == 'f' || optopt == 'm') {
                    fprintf(stderr, "Option -%c requires an argument\n", optopt);
                }
                 else {
                    fprintf(stderr, "Unknown character in option '\\x%x'\n", optopt);
                }
                return 1;
            default:
                abort();
        }
    }

    
    if (argc == 1 || (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h')) {
        printf("Description of the application functionality:\n");
        printf("-h For select a file please write command -f <filename.csv>\n");
        printf("-f <filename.csv>\tInput csv file for processing\n");
        printf("-m <month number>\tDisplay statistics only for the specified month\n");
        return 0;
    }

    
    if (filename == NULL) {
        fprintf(stderr, "No input file specified (-f)\n");
        return 1;
    }

    
    if (month != -1) 
        calculate_monthly_statistics_for_month(filename, month);
     else {
        calculate_monthly_statistics(filename);
        calculate_monthly_statistics_min(filename);
        calculate_monthly_statistics_max(filename);
        calculate_yearly_statistics(filename);
        calculate_min_temperature(filename);
        }

    return 0;
}

 