#include <stdint.h>
#include <stdio.h>

void calculate_monthly_statistics(const char* filename);
void calculate_monthly_statistics_min(const char* filename);
void calculate_monthly_statistics_max(const char* filename);
void calculate_yearly_statistics(const char* filename);
void calculate_min_temperature(const char* filename);

void calculate_monthly_statistics_for_month(const char *filename, int month);