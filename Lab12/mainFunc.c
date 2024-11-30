#include <stdio.h>

int strcmp(const char *firstString, const char *secondString) {
    while (*firstString && (*firstString == *secondString)) {
        firstString++;
        secondString++;
    }
    return *(unsigned char *)firstString - *(unsigned char *)secondString;
}

int main() {
    // First input
    char firstInputOne[] = "gfg";
    char firstInputTwo[] = "gfg";
    int firstResult = strcmp(firstInputOne, firstInputTwo);
    printf("First option - \"%s\" and \"%s\"\n", firstInputOne, firstInputTwo);
    if (firstResult == 0)
        printf("Strings are equal\n");
    else
        printf("Strings are unequal\n");
    printf("Value returned by strcmp() is: %d\n\n", firstResult);

    // Second input
    char secondInputOne[] = "gFg";
    char secondInputTwo[] = "gfg";
    int secondResult = strcmp(secondInputOne, secondInputTwo);
    printf("Second option - \"%s\" and \"%s\"\n", secondInputOne, secondInputTwo);
    if (secondResult == 0)
        printf("Strings are equal\n");
    else
        printf("Strings are unequal\n");
    printf("Value returned by strcmp() is: %d\n\n", secondResult);

    // Third input
    char thirdInputOne[] = "gfg";
    char thirdInputTwo[] = "gFg";
    int thirdResult = strcmp(thirdInputOne, thirdInputTwo);
    printf("Third option - \"%s\" and \"%s\"\n", thirdInputOne, thirdInputTwo);
    if (thirdResult == 0)
        printf("Strings are equal\n");
    else
        printf("Strings are unequal\n");
    printf("Value returned by strcmp() is: %d\n\n", thirdResult);

}
