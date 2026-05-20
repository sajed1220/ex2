#include <stdio.h>
#define BRANDS 4
#define TYPES 4
#define DAYS 5
int main() {
/* Name: Sajed
* ID: 325949089
*/
int cube[BRANDS][TYPES][DAYS];
for (int b = 0; b < BRANDS; b++) {
for (int t = 0; t < TYPES; t++) {
for (int d = 0; d < DAYS; d++) {
cube[b][t][d] = -1;
}
}
}
const char* brand_names[BRANDS] = {"Toyoga", "thereIsNoFurd", "VaGe", "Key-Yuh"};
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
choice = 0;
}
if (choice < 1 || choice > 7) {
printf("Please choose a valid option\n");
continue;
}
if (choice == 1) {
int brand_idx;
printf("Enter brand index (0-Toyoga, 1-thereIsNoFurd, 2-VaGe, 3-Key-Yuh):\n");
scanf("%d", &brand_idx);
if (brand_idx < 0 || brand_idx >= BRANDS) {
printf("Invalid brand index\n");
continue;
}
int day_idx;
printf("Enter day index (1-5):\n");
scanf("%d", &day_idx);
if (day_idx < 1 || day_idx > DAYS) {
printf("Invalid day index\n");
continue;
}
day_idx--;
printf("Enter sales for SUV, Sedan, Coupe, GT:\n");
for (int t = 0; t < TYPES; t++) {
scanf("%d", &cube[brand_idx][t][day_idx]);
}
} else if (choice == 2) {
int day_idx;
printf("Enter day index (1-5):\n");
scanf("%d", &day_idx);
if (day_idx < 1 || day_idx > DAYS) {
printf("Invalid day index\n");
continue;
}
day_idx--;
for (int b = 0; b < BRANDS; b++) {
printf("Enter sales for %s (SUV, Sedan, Coupe, GT):\n", brand_names[b]);
for (int t = 0; t < TYPES; t++) {
scanf("%d", &cube[b][t][day_idx]);
}
}
} else if (choice == 3) {
int day_idx;
printf("Enter day index (1-5) for stats:\n");
scanf("%d", &day_idx);
if (day_idx < 1 || day_idx > DAYS) {
printf("Invalid day index\n");
continue;
}
day_idx--;
int total_sales = 0;
int brand_totals[BRANDS] = {0};
int type_totals[TYPES] = {0};
for (int b = 0; b < BRANDS; b++) {
for (int t = 0; t < TYPES; t++) {
if (cube[b][t][day_idx] != -1) {
total_sales += cube[b][t][day_idx];
brand_totals[b] += cube[b][t][day_idx];
type_totals[t] += cube[b][t][day_idx];
}
}
}
printf("Total sales for day %d: %d\n", day_idx + 1, total_sales);
int max_brand = 0;
for (int b = 1; b < BRANDS; b++) {
if (brand_totals[b] > brand_totals[max_brand]) {
max_brand = b;
}
}
printf("Top selling brand for day %d: %s with %d sales\n", day_idx + 1, brand_names[max_brand], brand_totals[max_brand]);
int max_type = 0;
for (int t = 1; t < TYPES; t++) {
if (type_totals[t] > type_totals[max_type]) {
max_type = t;
}
}
printf("Top selling type for day %d: %s with %d sales\n", day_idx + 1, type_names[max_type], type_totals[max_type]);
} else if (choice == 4) {
for (int b = 0; b < BRANDS; b++) {
printf("Sales for %s:\n", brand_names[b]);
for (int d = 0; d < DAYS; d++) {
printf("Day %d- ", d + 1);
for (int t = 0; t < TYPES; t++) {
printf("%s: %d ", type_names[t], cube[b][t][d]);
}
printf("\n");
}
}
} else if (choice == 5) {
int overall_brand_totals[BRANDS] = {0};
int overall_type_totals[TYPES] = {0};
int overall_day_totals[DAYS] = {0};
for (int b = 0; b < BRANDS; b++) {
for (int t = 0; t < TYPES; t++) {
for (int d = 0; d < DAYS; d++) {
if (cube[b][t][d] != -1) {
overall_brand_totals[b] += cube[b][t][d];
overall_type_totals[t] += cube[b][t][d];
overall_day_totals[d] += cube[b][t][d];
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
printf("The best-selling brand overall is %s: %d\n", brand_names[best_brand], overall_brand_totals[best_brand]);
int best_type = 0;
for (int t = 1; t < TYPES; t++) {
if (overall_type_totals[t] > overall_type_totals[best_type]) {
best_type = t;
}
}
printf("The best-selling type of car is %s: %d\n", type_names[best_type], overall_type_totals[best_type]);
int best_day = 0;
for (int d = 1; d < DAYS; d++) {
if (overall_day_totals[d] > overall_day_totals[best_day]) {
best_day = d;
}
}
printf("The most profitable day was day number %d: %d\n", best_day + 1, overall_day_totals[best_day]);
} else if (choice == 6) {
for (int b = 0; b < BRANDS; b++) {
printf("Brand: %s\n", brand_names[b]);
for (int t = 0; t < TYPES; t++) {
float total_delta = 0;
int count = 0;
for (int d = 0; d < DAYS - 1; d++) {
if (cube[b][t][d] != -1 && cube[b][t][d+1] != -1) {
total_delta += (cube[b][t][d+1] - cube[b][t][d]);
count++;
}
}
if (count > 0) {
printf("  Type: %s, Average Delta: %.2f\n", type_names[t], total_delta / count);
} else {
printf("  Type: %s, Average Delta: N/A\n", type_names[t]);
}
}
}
} else if (choice == 7) {
printf("Goodbye!\n");
}
}
return 0;
}
