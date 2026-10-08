#include <stdio.h>

#define MAX_NUM(a, b) ((a > b) ? (a) : (b))

int maxProfit(int *prices, int pricesSize) {
  int *last_price = prices + pricesSize - 1;
  int *best_selling_price = last_price;
  int result = 0;

  while ((--last_price) >= prices) {
    int curr_price = *last_price;
    if (curr_price < *best_selling_price) {
      result = MAX_NUM(result, *best_selling_price - curr_price);
    } else {
      best_selling_price = last_price;
    }
  }

  return result;
}
