#ifndef DESIGN_H_INCLUDED
#define DESIGN_H_INCLUDED
#define MAX_CLIENTES 200
#define MAX_FUNCIONARIOS 20
#define MAX_SABORES 50
#define MAX_ELOREC 300
void clrscr();
void gotoxy(int x, int y);
void pintar(int cor);
void linha(int posicao);
void coluna(int posicao);
void cantoDirSup();
void cantoEsqSup();
void cantoDirInf();
void cantoEsqInf();
void cantoEsqT();
void cantoDirT();
void moldura();
void printfCenter(char *texto, int linha);
void printfNovo(char *texto, int linha);

#endif // DESIGN_H_INCLUDED
