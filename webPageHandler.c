
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//1 --> turn on lights
//0 --> turn off lights
//axxxx --> set alarm to turn on at time x
//x format hhmm (military time)
//d --> disable
//e --> enable

int main(int argc, char* argv[]){

        //name of status file is StatusFile.txt
        FILE *status;
        char cmd[5];


        time_t rawtime;
        struct tm * timeinfo;

        time (&rawtime);
        timeinfo = localtime (&rawtime);

        if(*argv[1] == '1'){
                //turn on the lights
                cmd[0] = '1';
                cmd[1] = '0';
                cmd[2] = '0';
                cmd[3] = '0';
                cmd[4] = '0';
        }

        else if (*argv[1] == '0') {
                //turn lights off
                cmd[0] = '0';
                cmd[1] = '0';
                cmd[2] = '0';
                cmd[3] = '0';
                cmd[4] = '0';

        }
        else if(*argv[1] == 'a'){
                //use argv[2] and argv[3] to set hour
                //use argv[4] and argv[5] to set minute
                cmd[0] = 'a';
                cmd[1] = *argv[2];
                cmd[2] = *argv[3];
                cmd[3] = *argv[4];
                cmd[4] = *argv[5];
        }
        else if(*argv[1] == 'd'){
                //update status file with info that puts IOT.c into
                //"stupid" mode
                cmd[0] = 'd';
                cmd[1] = '0';
                cmd[2] = '0';
                cmd[3] = '0';
                cmd[4] = '0';

        }
        else if(*argv[1] == 'e'){
                //update status file with info that puts IOT.c into
                //"smart" mode
                cmd[0] = 'e';
                cmd[1] = '0';
                cmd[2] = '0';
                cmd[3] = '0';
                cmd[4] = '0';

        }


        time (&rawtime);
        timeinfo = localtime (&rawtime);

        //delay until odd second
       while(timeinfo->tm_sec % 2 == 0){
                time (&rawtime);
                timeinfo = localtime (&rawtime);
        }

         status = fopen("StatusFile.txt","w");


        //if the file does not open correctly throw an error
        if(status == NULL){
                printf("Error opening file\r\n");
                exit(1);
        }

        fprintf(status, "%c%c%c%c%c", cmd[0],cmd[1],cmd[2],cmd[3],cmd[4]);

        fclose(status);

        return 0;
}
         