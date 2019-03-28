#include<stdlib.h>
#include<stdio.h>

struct _retire_info {
  int months;
  double contribution;
  double rate_of_return;
};
typedef struct _retire_info retire_info;

double printMonthlyReturn(int startAge, double initial, retire_info info) {
  for (int i = 0; i < info.months; i++) {
    int year = (startAge + i) / 12;
    int month = (startAge + i) % 12;
    printf("Age %3d month %2d you have $%.2lf\n", year, month, initial);
    initial *= 1 + info.rate_of_return;
    initial += info.contribution;
  }
  return initial;
}

void retirement(int startAge, double initial, retire_info working, retire_info retired) {
  initial = printMonthlyReturn(startAge, initial, working);
  printMonthlyReturn(startAge + working.months, initial, retired);
}

int main() {
  retire_info working;
  working.months = 489;
  working.contribution = 1000;
  working.rate_of_return = 0.045/12;

  retire_info retired;
  retired.months = 384;
  retired.contribution = -4000;
  retired.rate_of_return = 0.01/12;

  retirement(327, 21345, working, retired);
  return 0;
}
