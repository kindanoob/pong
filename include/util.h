#ifndef UTIL_H_
#define UTIL_H_

int GetRandomInt(int a, int b) {
    int modulo = b - a + 1;
    int temp = rand() % modulo;
    return temp;
}

#endif // UTIL_H_
