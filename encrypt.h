#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>


int Ferramenta(const char *arquiv){ 

	FILE *abrir;
	FILE *escrever;
	long tamanho;
	char *supor;
	int i = 0;
	
	abrir = fopen(arquivo, "rb");
	
	fseek(abrir, 0, SEEK_END);
	
	tamanho = ftell(abrir);
	fclose(abrir);
	char texto[tamanho];

	abrir = fopen(arquivo, "rb");
	fread(texto, sizeof texto, 1, abrir);
	printf("%s", texto);
	fclose(abrir);

	texto[1] = 9;

	escrever = fopen(arquiv, "wb");
	fwrite(texto, sizeof texto, 1, escrever);
	fclose(escrever);

	

return 1;
}