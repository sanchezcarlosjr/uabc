int generateRandomNumberBetween(int a, int b) {
    srand(time(NULL));
    return rand() % b + a;
}