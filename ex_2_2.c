#include <stdio.h>
#define BRANDS 5
#define TYPES 4
#define DAYS 365
int main() {
/* Name: Sajed
* ID: 325949089
*/
int cube[DAYS][BRANDS][TYPES];
int brand_counters[DAYS][BRANDS];
int current_day = 0;
for (int d = 0; d < DAYS; d++) {
for (int b = 0; b < BRANDS; b++) {
brand_counters[d][b] = 0;
for (int t = 0; t < TYPES; t++) {
cube[d][b][t] = -1;
}
}
}
const char* brand_names[BRANDS] = {"Toyoga", "HyunNight", "Mazduh", "FolksVegan", "Key-Yuh"};
const char* type_names[TYPES] = {"SUV", "Sedan", "Coupe", "GT"};
int choice = 0;
while (choice != 7) {
printf("Welcome to the Cars Data Cube! What would you like to do?\n");
printf("1.Enter Daily Data For A Brand\n");
printf("2.Populate A Day Of Sales For All Brands\n");
printf("3.Provide Daily Stats\n");
printf("4.Print All Data\n");
printf("5.Provide Overall (simple) Insights\n");
printf("6.Provide Average Delta Metrics\n");
printf("7.exit\n");
if (scanf("%d", &choice) != 1) {
scanf("%*s");
printf("Invalid input\n");
choice = 0;
continue;
}
if (choice < 1 || choice > 7) {
printf("Invalid input\n");
continue;
}
if (choice == 1) {
int brand_idx;
scanf("%d", &brand_idx);
if (brand_idx < 0 || brand_idx >= BRANDS) {
printf("This brand is not valid\n");
continue;
}
for (int t = 0; t < TYPES; t++) {
scanf("%d", &cube[current_day][brand_idx][t]);
}
} else if (choice == 2) {
int done_brands = 0;
while (done_brands < BRANDS) {
printf("No data for brands");
for (int b = 0; b < BRANDS; b++) {
if (brand_counters[current_day][b] == 0) {
printf(" %s", brand_names[b]);
}
}
printf("\nPlease complete the data\n");
int input_brand;
if (scanf("%d", &input_brand) != 1) {
scanf("%*s");
printf("This brand is not valid\n");
continue;
}
if (input_brand < 0 || input_brand >= BRANDS || brand_counters[current_day][input_brand] == 1) {
printf("This brand is not valid\n");
int dummy;
for (int t = 0; t < TYPES; t++) {
scanf("%d", &dummy);
}
continue;
}
for (int t = 0; t < TYPES; t++) {
scanf("%d", &cube[current_day][input_brand][t]);
}
brand_counters[current_day][input_brand] = 1;
done_brands++;
}
current_day++;
} else if (choice == 3) {
int target_day;
printf("What day would you like to analyze?\n");
while (1) {
if (scanf("%d", &target_day) != 1) {
scanf("%*s");
printf("Please enter a valid day.\nWhat day would you like to analyze?\n");
continue;
}
if (target_day < 1 || target_day > current_day) {
printf("Please enter a valid day.\nWhat day would you like to analyze?\n");
continue;
}
break;
}
int d_idx = target_day - 1;
int total_sales = 0;
int brand_totals[BRANDS] = {0};
int type_totals[TYPES] = {0};
for (int b = 0; b < BRANDS; b++) {
for (int t = 0; t < TYPES; t++) {
if (cube[d_idx][b][t] != -1) {
total_sales += cube[d_idx][b][t];
brand_totals[b] += cube[d_idx][b][t];
type_totals[t] += cube[d_idx][b][t];
}
}
}
printf("In day number %d:\n", target_day);
printf("The sales total was %d\n", total_sales);
int max_brand = 0;
for (int b = 1; b < BRANDS; b++) {
if (brand_totals[b] > brand_totals[max_brand]) {
max_brand = b;
}
}
printf("The best sold brand with %d sales was %s\n", brand_totals[max_brand], brand_names[max_brand]);
int max_type = 0;
for (int t = 1; t < TYPES; t++) {
if (type_totals[t] > type_totals[max_type]) {
max_type = t;
}
}
printf("The best sold type with %d sales was %s\n", type_totals[max_type], type_names[max_type]);
} else if (choice == 4) {
printf("\n");
for (int b = 0; b < BRANDS; b++) {
printf("Sales for %s:\n", brand_names[b]);
for (int d = 0; d < current_day; d++) {
printf("Day %d- ", d + 1);
for (int t = 0; t < TYPES; t++) {
printf("%s: %d ", type_names[t], cube[d][b][t]);
}
printf("\n");
}
}
printf("\n");
} else if (choice == 5) {
int overall_brand_totals[BRANDS] = {0};
int overall_type_totals[TYPES] = {0};
int overall_day_totals[DAYS] = {0};
for (int d = 0; d < current_day; d++) {
for (int b = 0; b < BRANDS; b++) {
for (int t = 0; t < TYPES; t++) {
if (cube[d][b][t] != -1) {
overall_brand_totals[b] += cube[d][b][t];
overall_type_totals[t] += cube[d][b][t];
overall_day_totals[d] += cube[d][b][t];
}
}
}
}
int best_brand = 0;
for (int b = 1; b < BRANDS; b++) {
if (overall_brand_totals[b] > overall_brand_totals[best_brand]) {
best_brand = b;
}
}
printf("The best-selling brand overall is %s: %d$\n", brand_names[best_brand], overall_brand_totals[best_brand]);
int best_type = 0;
for (int t = 1; t < TYPES; t++) {
if (overall_type_totals[t] > overall_type_totals[best_type]) {
best_type = t;
}
}
printf("The best-selling type of car is %s: %d$\n", type_names[best_type], overall_type_totals[best_type]);
int best_day = 0;
for (int d = 1; d < current_day; d++) {
if (overall_day_totals[d] > overall_day_totals[best_day]) {
best_day = d;
}
}
printf("The most profitable day was day number %d: %d$\n", best_day + 1, overall_day_totals[best_day]);
} else if (choice == 6) {
for (int b = 0; b < BRANDS; b++) {
float total_delta = 0;
int count = 0;
for (int d = 0; d < current_day - 1; d++) {
int current_day_sum = 0;
int next_day_sum = 0;
for (int t = 0; t < TYPES; t++) {
current_day_sum += cube[d][b][t];
next_day_sum += cube[d+1][b][t];
}
total_delta += (next_day_sum - current_day_sum);
count++;
}
if (count > 0) {
printf("Brand: %s, Average Delta: %f\n", brand_names[b], total_delta / count);
} else {
printf("Brand: %s, Average Delta: 0.000000\n", brand_names[b]);
}
}
} else if (choice == 7) {
printf("Goodbye!\n");
}
}
return 0;
}
