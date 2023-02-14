#include "stdhead.h"
#include "src/CSV.c"

//string declaration
typedef char *string;

//Array of devices
struct Device devices[100];

//File Location
const char *CSVfileName = "C:/Users/Levim/Documents/Address.csv";
const char *TXTfileName = "C:/Users/Levim/Documents/Active.txt";

//Active Devices
unsigned int activeDevices = 0;
string activeDevice[50];
string activeNames[50];

//Variables
string CKname;
char Buff[100];
char FBuff[1000] = "";

//mac to name
string macToName(const char *mac, int count){
    char buffer[100] = "";
    string out;
    for(int i = 0; i < count; i++){
        if(strcmp(devices[i].mac, mac) == 0){
            strcat(buffer, devices[i].FName);
            strcat(buffer, devices[i].LName);
            out = strdup(buffer);
            return out;
        }
    }
}

//Clear print
void clearprint(){
    for(int i = 0; i < 1000; i++){
        FBuff[i] = '\0';
    }
}


//Get Active Devices
int getActiveDevices(const char *fileName, string active[], int *count){
    FILE *fp = fopen(fileName, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    char line[1024];
    int i = 0;
    //Read each line of the file
    while (fgets(line, 1024, fp) != NULL) {
        active[i] = strdup(line);
        i++;
    }
    *count = i;

    //remove the new line character
    for(int i = 0; i < *count; i++){
        active[i][strlen(active[i]) - 1] = '\0';
    }


    fclose(fp);
    return 0;
}

//Main function
int main(){

    /*Test Assignment
    activeDevices = 4;
    activeDevice[0] = "258.174.890";
    activeDevice[1] = "189.255.041";
    activeDevice[2] = "867.058.394";
    activeDevice[3] = "33.557.256.0";
    */

    

    /*Print out the devices
    for (int i = 0; i < count; i++) {
        printf("Device %d: %s, %s, %s", i, devices[i].mac, devices[i].FName, devices[i].LName);
    }*/
    int tett;

    

    //Main Loop
    while (true) {
        tett += 1;

        //Read CSV file
        int count = 0;
        readCSV(CSVfileName, devices, &count);


        //Get the active devices
        getActiveDevices(TXTfileName, activeDevice, &activeDevices);

        //Get the active devices names
        for (int i = 0; i < activeDevices; i++) {
            activeNames[i] = macToName(activeDevice[i], count);
        }

        //Check for duplicates
        for (int i = 0; i < activeDevices; i++) {
            CKname = activeNames[i];
            for (int j = 0; j < activeDevices; j++) {
                //Make sure to not check against it self
                if (i == j) {
                    continue;
                }
                //Checking
                if (strcmp(CKname, activeNames[j]) == 0) {
                    sprintf(Buff, "Name %s has 2 devices \n", CKname);
                    strcat(FBuff, Buff);
                }
            }
            strcmp(CKname, "");
        }


        //Print out the active devices
        printf("%s",FBuff);
        //sleep for 100 miliseconds
        Sleep(100);

        system("cls");
        clearprint();
        sprintf(Buff, "%d \n",tett);
        strcat(FBuff, Buff);
        sprintf(Buff, "Active Devices: %d \n", activeDevices);
        strcat(FBuff, Buff);
        for (int i = 0; i < activeDevices; i++) {
            sprintf(Buff, "Device %d: %s \n", i, activeDevice[i]);
            strcat(FBuff, Buff);
            sprintf(Buff, "Name %d: %s \n", i, activeNames[i]);
            strcat(FBuff, Buff);
        }

    }



    return 0;
}