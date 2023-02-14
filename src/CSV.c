#include "stdhead.h"

struct Device {
    char *mac;
    char *FName;
    char *LName;
};

void readCSV(const char *fileName, struct Device devices[], int *count) {
    FILE *fp = fopen(fileName, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    char line[1024];
    int i = 0;
    while (fgets(line, 1024, fp) != NULL) {
        char *token = strtok(line, ",");
        devices[i].mac = strdup(token);
        token = strtok(NULL, ",");
        devices[i].FName = strdup(token);
        token = strtok(NULL, ",");
        devices[i].LName = strdup(token);
        i++;
    }
    *count = i;
    fclose(fp);
}