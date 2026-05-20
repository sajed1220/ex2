#include <stdio.h>
int main() {
/* Name: Sajed
* ID: 325949089
*/
int option = 0;
while (option != 7) {
printf("Choose an option:\n");
printf("\t1. Happy Face\n");
printf("\t2. Balanced Number\n");
printf("\t3. Generous Number\n");
printf("\t4. Circle Of Joy\n");
printf("\t5. Happy Numbers\n");
printf("\t6. Festival Of Laughter\n");
printf("\t7. Exit\n");
if (scanf("%d", &option) != 1) {
scanf("%*s");
option = 0;
}
if (option == 1) {
char eye, nose, mouth;
int size;
printf("Enter symbols for the eyes, nose, and mouth:\n");
scanf(" %c %c %c", &eye, &nose, &mouth);
printf("Enter face size:\n");
scanf("%d", &size);
while (size <= 0 || size % 2 == 0) {
printf("The face's size must be an odd and positive number, please try again:\n");
scanf("%d", &size);
}
printf("%c", eye);
for (int i = 0; i < size; i++) {
printf(" ");
}
printf("%c\n", eye);
for (int i = 0; i < (size / 2) + 1; i++) {
printf(" ");
}
printf("%c\n", nose);
printf("/");
for (int i = 0; i < size; i++) {
printf("%c", mouth);
}
printf("\\n");
} else if (option == 2) {
long long num;
printf("Enter a number:\n");
scanf("%lld", &num);
while (num <= 0) {
printf("Only positive number is allowed, please try again:\n");
scanf("%lld", &num);
}
long long temp = num;
int digits = 0;
while (temp > 0) {
digits++;
temp /= 10;
}
int half = digits / 2;
long long left_sum = 0, right_sum = 0;
temp = num;
for (int i = 0; i < digits; i++) {
int digit = temp % 10;
if (digits % 2 == 0) {
if (i < half) {
right_sum += digit;
} else {
left_sum += digit;
}
} else {
if (i < half) {
right_sum += digit;
} else if (i > half) {
left_sum += digit;
}
}
temp /= 10;
}
if (left_sum == right_sum) {
printf("This number is balanced and brings harmony!\n");
} else {
printf("This number isn't balanced and destroys harmony.\n");
}
} else if (option == 3) {
int num;
printf("Enter a number:\n");
scanf("%d", &num);
while (num <= 0) {
printf("Only positive number is allowed, please try again:\n");
scanf("%d", &num);
}
int sum = 0;
for (int i = 1; i <= num / 2; i++) {
if (num % i == 0) {
sum += i;
}
}
if (sum > num) {
printf("This number is generous!\n");
} else {
printf("This number does not share.\n");
}
} else if (option == 4) {
int num;
printf("Enter a number:\n");
scanf("%d", &num);
while (num <= 0) {
printf("Only positive number is allowed, please try again:\n");
scanf("%d", &num);
}
int is_prime1 = 1;
if (num <= 1) is_prime1 = 0;
for (int i = 2; i * i <= num; i++) {
if (num % i == 0) {
is_prime1 = 0;
break;
}
}
int temp = num;
int rev = 0;
while (temp > 0) {
rev = rev * 10 + (temp % 10);
temp /= 10;
}
int is_prime2 = 1;
if (rev <= 1) is_prime2 = 0;
for (int i = 2; i * i <= rev; i++) {
if (rev % i == 0) {
is_prime2 = 0;
break;
}
}
if (is_prime1 && is_prime2) {
printf("This number completes the circle of joy!\n");
} else {
printf("The circle remains incomplete.\n");
}
} else if (option == 5) {
int n;
printf("Enter a number:\n");
scanf("%d", &n);
while (n <= 0) {
printf("Only positive number is allowed, please try again:\n");
scanf("%d", &n);
}
printf("Between 1 and %d only these numbers bring happiness: ", n);
for (int i = 1; i <= n; i++) {
int slow = i, fast = i;
do {
int sum = 0, t = slow;
while (t > 0) {
int d = t % 10;
sum += d * d;
t /= 10;
}
slow = sum;
sum = 0; t = fast;
while (t > 0) {
int d = t % 10;
sum += d * d;
t /= 10;
}
t = sum; sum = 0;
while (t > 0) {
int d = t % 10;
sum += d * d;
t /= 10;
}
fast = sum;
} while (slow != fast && slow != 1);
if (slow == 1) {
printf("%d ", i);
}
}
printf("\n");
} else if (option == 6) {
int smile = 0, cheer = 0;
int valid_format = 0;
printf("Enter a smile and cheer number:\n");
while (!valid_format) {
int scan_res = scanf(" smile: %d , cheer: %d", &smile, &cheer);
if (scan_res == 2 && smile > 0 && cheer > 0 && smile != cheer) {
valid_format = 1;
} else {
scan_res = scanf(" cheer: %d , smile: %d", &cheer, &smile);
if (scan_res == 2 && smile > 0 && cheer > 0 && smile != cheer) {
valid_format = 1;
} else {
printf("Only 2 different positive numbers in the given format are allowed for the festival, please try again:\n");
scanf("%*[^\n]");
scanf("%*c");
}
}
}
int max_num;
printf("Enter maximum number for the festival:\n");
scanf("%d", &max_num);
while (max_num <= 0) {
printf("Only positive maximum number is allowed, please try again:\n");
scanf("%d", &max_num);
}
for (int i = 1; i <= max_num; i++) {
if (i % smile == 0 && i % cheer == 0) {
printf("Festival!\n");
} else if (i % smile == 0) {
printf("Smile!\n");
} else if (i % cheer == 0) {
printf("Cheer!\n");
} else {
printf("%d\n", i);
}
}
} else if (option == 7) {
printf("Thank you for your journey through Numeria!\n");
} else {
printf("This option is not available, please try again.\n");
}
}
return 0;
}
