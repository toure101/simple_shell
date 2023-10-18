#include <stdio.h>

/**
 * Adds three numbers together.
 *
 * @num1: The first number to be added.
 * @num2: The second number to be added.
 * @num3: The third number to be added.
 *
 * @return: The added result.
 */
int add(int num1, int num2, int num3) {
    return num1 + num2 + num3;
}

int main() {
    int num1 = 5, num2 = 10, num3 = 15;

    int result = add(num1, num2, num3);

    printf("The sum of %d, %d, and %d is: %d\n", num1, num2, num3, result);

    return 0;
}

