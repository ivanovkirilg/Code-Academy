/* 1. Първата функция да калкулира най-малко общо кратно на две положителни числа. */

int lowestCommonDenominator(int a, int b) {
    if (a<0 || b<0) return -1;
    
    if (b % a == 0) return b;

    int i = 0;
    while (++i) {
        if (a * i % b == 0) return a * i;
    }
}

/*  2. Втората функция връща абсолютна стойност на числата (положителната стойност на числата).
    a. Трябва да може да приеме като параметър float и да върне float.
    b. Тествайте с инт и float. */

float absoluteValue(float number) {
    if (number < 0) return -number;
    else return number;
}

/*  3. Напишете функция, която калкулира корен квадратен от число.
    a. Проверете дали резултатът е отрицателно число и върнете -1.
    b. Използвайте втората си функция, за да обърнете числото в положително 
    и да намерите корен квадратен от него */

float findSquareRoot(float number) {
    if (number < 0) return -1;

    /* Slow method, but I wanted to implement something I understand */
    int iterations = 22; /* lower number -> less precision, but faster */
    int i;
    float low = 0, mid = number/2, high = number; /* we start at half of x */
    for (i = 0; i < iterations; i++) {
        if (mid*mid == number) return mid; /* if our estimate is exact, return it */

        else if (mid*mid > number) { /* if it is too high, set it as the new high value */
            high = mid;
            mid = (low+mid)/2; /* and move estimate towards low value by averaging */
        }
        else {
            low = mid;  /* if estimate is too low, set it as new low value */
            mid = (high+mid)/2; /* and move estimate towards high value */
        }
    }
    return mid;
}