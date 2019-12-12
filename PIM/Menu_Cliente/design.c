#include <windows.h>

void clrscr(){
    system("cls");
}

void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void pintar(int cor){
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, cor);
}

const int COLUNA=80;
const int LINHA=20;

void moldura(){
    int x;

    gotoxy(0,0);
    for(x=0;x<COLUNA;x++){
        printf("%c",205);
    }

    gotoxy(0,2);
    for(x=0;x<COLUNA;x++){
        printf("%c",205);
    }

    gotoxy(0,20);
    for(x=0;x<COLUNA;x++){
        printf("%c",205);
    }

    //gotoxy(0,0);
    for(x=0;x<=LINHA;x++){
        gotoxy(0,x);
        printf("%c",186);
    }

    //gotoxy(80,0);
    for(x=0;x<=LINHA;x++){
        gotoxy(80,x);
        printf("%c",186);
    }

    gotoxy(0,2);
    printf("%c", 204);
    gotoxy(80,2);
    printf("%c", 185);
    gotoxy(80,20);
    printf("%c", 188);
    gotoxy(0,20);
    printf("%c", 200);
    gotoxy(0,0);
    printf("%c", 201);
    gotoxy(80,0);
    printf("%c", 187);
}

void printfCenter(char *texto, int linha){
	int coluna = (COLUNA / 2) - strlen(texto);
	gotoxy(coluna, linha);
	printf("%s", texto);
}
void printfNovo(char *texto, int linha){
	gotoxy(2, linha);
	printf("%s", texto);
}
