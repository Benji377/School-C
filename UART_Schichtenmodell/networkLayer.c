#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/io.h>
#include <ctype.h>
#include "datalinkLayer.h"
#include "physikalLayer.h"
int main(int argc, char *argv[]){
	if(argc==4){
		//überprüft ob alle Argumente richtig übergeben wurden
		if((strcmp(argv[1],"-r")==0||strcmp(argv[1],"-w")==0)&&(strcmp(argv[2],"1")==0||strcmp(argv[2],"2")==0)){
			if(getuid()!=0){
				printf("Geben Sie bitte die root-Rechte dazu!\n");
				return -1;
			}
			//falls geschrieben werden soll
			if(strcmp(argv[1],"-w")==0){
				//File wird geöffnet, falls sie nicht exestiert wird das Programm beendet
				FILE *f = fopen(argv[3],"r");
				if(f==NULL){
					printf("Fehler beim Öffnen der Datei!\n");
					return -1;
				}
				//gibt dem Programm Zugriff auf dem jeweiligen Port zu lesen/schreiben
				switch(*(argv[2])-48){
					case 1:
						ioperm(0x03F8,8,1);
						break;
					case 2:
						ioperm(0x02F8,8,1);
						break;
				}
				unsigned char payload[300][256];
				int i=0;
				char counter=0;
				//liest den Text der übergebenen Datei ein und schreibt diesen in Frames
				for(char c=fgetc(f);c!=EOF;i++){
					payload[counter][255]=i;
					if(i<254){
						payload[counter][i]=c;
					}else{
						i=0;
						counter++;
						if(counter>=100){
                                                        printf("In der Text Datei sind zu viele Frames.\nEs werden nun alle möglichen Frames gesendet!\n");
                                                        break;
                                                }
						payload[counter][i]=c;
					}
					c=fgetc(f);
				}
				fclose(f);
				counter++;
				//ruft die writeFrame() Funktion mit dem richtigen Port auf
				for(i=0;i<counter;i++){
					switch (*(argv[2])-48){
						case 1:
							writeFrame(payload[i],payload[i][255],0x03F8);
							break;
						case 2:
							writeFrame(payload[i],payload[i][255],0x02F8);
							break;
					}	
				}
				//nimmt dem Programm Zugriff auf dem jeweiligen Port zu lesen/schreiben
				switch(*(argv[2])-48){
                                        case 1:
                                                ioperm(0x03F8,8,0);
                                                break;
                                        case 2:
                                                ioperm(0x02F8,8,0);
                                                break;
                                }
				printf("Das Schreiben war erfolgreich!\n");
			}
			//falls gelesen werden soll
			else{
				FILE *f = fopen(argv[3],"w");
				unsigned char payload[300][256];
				int i=0;
				//gibt dem Programm Zugriff auf dem jeweiligen Port zu lesen/schreiben
				switch(*(argv[2])-48){
                                        case 1:
                                                ioperm(0x03F8,8,1);
                                                break;
                                        case 2:
                                                ioperm(0x02F8,8,1);
                                                break;
                                }
				int abbruch=1;
				int j=0;
				int rueckgabe=0;
				//ruft die Methode readFrame solange auf bis es nichts mehr zu lesen gibt oder es eine Fehler beim Übertragen gegeben hat
				while(abbruch){
					switch(*(argv[2])-48){
						case 1:
							rueckgabe=readFrame(payload[i],&payload[i][255],0x03F8);
							break;
						case 2:
							rueckgabe=readFrame(payload[i],&payload[i][255],0x02F8);
							break;
					}
					if(rueckgabe!=-1){
						for(j=0;j<(payload[i][255]);j++);
						if(payload[i][255]<254){
							abbruch=0;
						}
					}else{
						printf("Es gab einen Fehler beim lesen der Datei!\n");
						return -1;
					}
					i++;
				}
				printf("Das Lesen war erfolgreich!\n");
				//nimmt dem Programm Zugriff auf dem jeweiligen Port zu lesen/schreiben
				switch(*(argv[2])-48){
                                        case 1:
                                                ioperm(0x03F8,8,0);
                                                break;
                                        case 2:
                                                ioperm(0x02F8,8,0);
                                                break;
                                }
				//schreibt die Frames in eine Textdatei
				for(int k=0;k<i;k++){
					for(int l=0;l<255;l++){
						if(payload[k][l]>31||payload[k][l]==10){
							fprintf(f,"%c",payload[k][l]);
						}
					}
				}
			}
		}else{
			printf("Die Argumente müssen folgende Form haben: ./UART -r/-w 1/2 NameDertxtFile\n");
		}
	}else{
			printf("Es müssen genau 4 Argumente übergeben werden!\n");
	}
}
