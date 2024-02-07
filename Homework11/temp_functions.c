#include <stdio.h>
#include <limits.h>
#define MAX_MONTHS 12

void calculate_monthly_statistics(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open file\n");
        return;
    }

    int monthly_temperature_sum[MAX_MONTHS] = {0};    
    int monthly_temperature_count[MAX_MONTHS] = {0}; 

    char line[100];
    while (fgets(line, sizeof(line), file)) {
        int year, month, day, hour, minute, temperature;
        sscanf(line, "%d;%d;%d;%d;%d;%d", &year, &month, &day, &hour, &minute, &temperature);
        
        int month_index = month - 1;  
        monthly_temperature_sum[month_index] += temperature;
        monthly_temperature_count[month_index]++;
    }

    fclose(file);

    printf("Monthly statistics:\n");
    for (int i = 0; i < MAX_MONTHS; i++) {
        if (monthly_temperature_count[i] > 0) {
            float average_temperature = (float)monthly_temperature_sum[i] / monthly_temperature_count[i];
            printf("Month %d: Average temperature = %.2f\n", i + 1, average_temperature);
        } else {
            printf("Month %d: No data available\n", i + 1);
        }
    }
}


void calculate_monthly_statistics_min(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open file\n");
        return;
    }

    int current_month = 0;                 
    int current_month_min_temperature = 0; 
    int min_temperature_set = 0;           

    char line[100];
    while (fgets(line, sizeof(line), file)) {
        int year, month, day, hour, minute, temperature;
        sscanf(line, "%d; %d; %d; %d;%d; %d", &year, &month, &day, &hour, &minute, &temperature);
        
        if (month != current_month) {
            if (current_month > 0) {
                printf("Month %d: Minimum temperature = %d\n", current_month, current_month_min_temperature);
            }
            
            current_month = month;
            current_month_min_temperature = temperature;
            min_temperature_set = 1;
        } else {
            if (!min_temperature_set || temperature < current_month_min_temperature) {
                current_month_min_temperature = temperature;
                min_temperature_set = 1;
            }
        }
    }
    
    if (current_month > 0) {
        printf("Month %d: Minimum temperature = %d\n", current_month, current_month_min_temperature);
    }

    fclose(file);
}

void calculate_monthly_statistics_max(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open file\n");
        return;
    }

    int current_month = 0;                 
    int current_month_max_temperature = 0; 
    int max_temperature_set = 0;           

    char line[100];
    while (fgets(line, sizeof(line), file)) {
        int year, month, day, hour, minute, temperature;
        sscanf(line, "%d; %d; %d; %d;%d; %d", &year, &month, &day, &hour, &minute, &temperature);
        
        if (month != current_month) {
            if (current_month > 0) {
                printf("Month %d: Maximum temperature = %d\n", current_month, current_month_max_temperature);
            }
            
            current_month = month;
            current_month_max_temperature = temperature;
            max_temperature_set = 1;
        } else {
            if (!max_temperature_set || temperature > current_month_max_temperature) {
                current_month_max_temperature = temperature;
                max_temperature_set = 1;
            }
        }
    }
    
    if (current_month > 0) {
        printf("Month %d: Maximum temperature = %d\n", current_month, current_month_max_temperature);
    }

    fclose(file);
}

void calculate_yearly_statistics(const char* filename) {
    int total_temperature_sum = 0;
    int total_temperature_count = 0;

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open file\n");
        return;
    }

    char line[100];
    while (fgets(line, sizeof(line), file)) {
        int year, month, day, hour, minute, temperature;
        sscanf(line, "%d; %d; %d; %d;%d; %d", &year, &month, &day, &hour, &minute, &temperature);
        
        total_temperature_sum += temperature;
        total_temperature_count++;
    }
    
    fclose(file);

    float overall_average_temperature = total_temperature_sum / (float)total_temperature_count;
    printf("Overall Average temperature = %.2f\n", overall_average_temperature);
}

void calculate_min_temperature(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open file\n");
        return;
    }

    int min_temperature = INT_MAX;
    int year, month, day, hour, minute, temperature;
    int min_year, min_month, min_day;
    
    char line[100];
    fgets(line, sizeof(line), file);  
    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%d; %d; %d; %d;%d; %d", &year, &month, &day, &hour, &minute, &temperature);
        
        if (temperature < min_temperature) {
            min_temperature = temperature;
            min_year = year;
            min_month = month;
            min_day = day;
        }
    }
    
    fclose(file);

    printf("Minimum temperature for the year: %d\n", min_temperature);
    
}


void calculate_monthly_statistics_for_month(const char *filename, int month) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Unable to open file.\n");
        return;
    }

    int temperatures[MAX_MONTHS] = {0};
    int count[MAX_MONTHS] = {0};

    int year, month_from_file, day, hour, minute, temperature;
    while (fscanf(file, "%d;%d;%d;%d;%d;%d", &year, &month_from_file, &day, &hour, &minute, &temperature) == 6) {
        if (month_from_file == month) {
            temperatures[month - 1] += temperature;
            count[month - 1]++;
        }
    }

    fclose(file);

    printf("Statistics for the month %d:\n", month);
    if (count[month - 1] > 0) {
        printf("Average monthly temperature: %.2f\n", (float) temperatures[month - 1] / count[month - 1]);
    } else {
        printf("No temperature data for the specified month.\n");
    }
}