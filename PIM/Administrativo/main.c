#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include "menus.h"
#include "design.h"

const char BLACK = 219;
char *arquivoCliente = "clientes.bin";
char *arquivoPizza = "pizzas.bin";
char *arquivoBebidas = "bebidas.bin";
char *arquivoFuncionario = "funcionarios.bin";
char *arquivoReclamacao = "reclamacao.bin";
char *arquivoElogio = "elogio.bin";
char *arquivoPromocao = "promocao.bin";
//char *arquivoPedido = "pedidos.bin";
char *arquivoPedTexto = "pedidostexto.txt";
char *arquivoPizzaTexto = "pizzasTexto.txt";
char *arquivoPromocaoTexto = "promocaotexto.txt";
char *arquivoBebidaTexto = "bebidasTexto.txt";

typedef struct sabores{
    char ingred[80];
    char sabor[14];
    float preco;
    float custo;
    struct Sabores *proximo;
}Sabores;
Sabores *inicioPizza = NULL;
int codSabor;

typedef struct promocao
{
    char nomePromo[60];
    float preco;
    float custo;
    struct Promocao *proximo;
}Promocao;
Promocao *inicioPro = NULL;
int codPromocoes;

typedef struct bebida{
    char saborBebida[80];
    float preco;
    float custo;
    struct Bebida *proximo;
}Bebida;
Bebida *inicioBebida = NULL;
int codBebida;

typedef struct rec
{
    char reclamacao[200];
    struct Rec *proximo;
}Rec;
Rec *inicioRec = NULL;

typedef struct elogio
{
    char elogi[200];
    struct Elogio *proximo;
}Elogio;
Elogio *inicioElo = NULL;

typedef struct cliente
{
    char nome[50];
    char telefone[20];
    char rua[50];
    char numero[10];
    char bairro[30];
    char cidade[20];
    char estado[10];
    struct Cliente *proximo;
}Cliente;
Cliente *inicioCli = NULL;
int codCliente;

typedef struct funcionario{
    char nomefun[50];
    char cargo[20];
    int codigo;
    struct funcionario *proximo;
}funcionario;
funcionario *iniciofun = NULL;
int codFuncionario;

typedef struct pedido
{
    char *saborPizza;
    char *nomeCliente;
    char *saborBebida;
    float total;
    struct Pedido *proximo;
}Pedido;
Pedido *inicioPedido = NULL;
int codPedido;

int main()
{
    ler();
    //setlocale(LC_ALL, "Portuguese");
    pintar(112);
    clrscr();
    //LOGIN
    char login [201];
    char senha[201];
    char chave[201];
    int iguais=1;
    int x=0;
    do{
        clrscr();
        moldura();
            //entrada do login do usuario
        printfCenter("LOGIN",1);
        strcpy(chave, "nonas");
        for(x=0;x<8;x++)
        {
            gotoxy(x+40,3);
            printf("%c",BLACK);
        }
        printfCenter("Entre com o login:", 3);
        fgets(login, sizeof(login), stdin);
        for(x=0; x<strlen(chave); x++)
        {
            if(login[x]!=chave[x])
            {
                iguais=0;
    	    }
            strcpy(chave, "admin");
                //entrada da senha
        for(x=0;x<8;x++)
            {
                gotoxy(x+40,5);
                printf("%c",BLACK);
            }
            printfCenter("Entre com a senha: ",5);
            fgets(senha, sizeof(senha), stdin);
            for(x=0; x<strlen(chave); x++)
            {
                if(senha[x]!=chave[x])
                {
                    iguais=0;
    	        }
   	        }
   	    }
            if(iguais){
                printfCenter("Acesso permitido",10);
                gotoxy(15,15);
                system("PAUSE");
                iguais = 0;
    	    }
            else{
                iguais = 1;
                printfCenter("Acesso negado",10);
                gotoxy(15,15);
                system("PAUSE");
    	    }
        }while(iguais!=0);
    clrscr();
    int op;
    do{
        clrscr();
        moldura();
        printfCenter("Bem vindo ao PizzaSystem  ", 1);
        printfCenter("Selecione o menu desejado. ",3);
        printfNovo("0 - Sair.",5);
        printfNovo("1 - Pedidos.",6);
        printfNovo("2 - Pizzas.",7);
        printfNovo("3 - Bebidas.",8);
        printfNovo("4 - Promocoes.",9);
        printfNovo("5 - Clientes.",10);
        printfNovo("6 - Gerencial.",11);
        printfNovo("7 - Elogios e reclamacoes.",12);
        printfNovo("8 - Funcionarios.",13);
        printfNovo("Digite a opcao: ",14);
        printf("%c", BLACK);
        gotoxy(18,14);
        scanf("%d", &op);
        getchar();
        switch(op)
        {
        case 0: gotoxy(2,16);
                gravar();
                system("C:\\PIM\\gerencial.xlsm");
                printf("Ate a proxima\n\n\n\n\n\n");
        break;
        case 1:
            clrscr();
            pedidos();
            break;
        case 2:
            clrscr();
            pizzas();

            break;
        case 3:
            clrscr();
            bebidas();
            break;
        case 4:
            clrscr();
            promocoes();
            break;
        case 5:
            clrscr();
            menucliente();
            break;
        case 6:
            clrscr();
            gerencial();
            break;
        case 7:
            clrscr();
            elogiosReclamacoes();
            break;
        case 8:
            clrscr();
            funcionarios();
            break;
        default: printfCenter("opcao invalida.",12);
            break;
        }
    }while (op!=0);
    return 0;
}

//Menu 1 PEDIDOS
void pedidos()
{
    int op;
    do{
        clrscr();
        moldura();
        printfCenter("Menu Pedidos",1);
        printfNovo("0 - voltar ao menu principal",3);
        printfNovo("1 - Novo pedido",4);
        printfNovo("2 - Listar Pedidos",5);
        printfNovo("3 - Excluir Pedido",6);
        gotoxy(2,7);
        printf("Digite a opcao: %c", BLACK);
        gotoxy(18,7);
        scanf("%d", &op);
        switch(op)
        {
            case 0: clrscr();
                break;
            case 1:
                    clrscr();
                    novoPedido();
                break;
            case 2:
                    clrscr();
                    listarPedido();
                break;
            case 3:
                    clrscr();
                    excluirPedido();
                break;
            default: printfCenter("Opcao invalida",12);
                break;
        }
    }while(op!=0);
}

//Novo Pedido 1.1
void novoPedido()
{
    int op;
    char promo;
    clrscr();
    moldura();
    printfCenter("NOVO PEDIDO",1);
    printfNovo("1 - Mesa",3);
    printfNovo("2 - Cliente",4);
    printfNovo("3 - Balcao",5);
    printfNovo("Digite a opcao desejada: ",6);
    gotoxy(27,6);
    printf("%c",BLACK);
    gotoxy(27,6);
    scanf("%d", &op);
    switch(op){
        case 1: pedidoMesa();
            break;
        case 2:do{
            clrscr();
            moldura();
            printfCenter("NOVO PEDIDO",1);
            printfNovo("Promocao?(s/n)",3);
            scanf(" %c", &promo);
            promo = tolower(promo);
            if(promo=='s'){
                pedidoPromo();
            }else if(promo=='n'){
                pedidoCliente();
            }else{
            printfNovo("Opcao invalida", 5);
            gotoxy(2,22);
            system("PAUSE");
            }
            }while((promo!='s')&&(promo!='n'));
            break;
        case 3: pedidoBalcao();
            break;
        default: printfCenter("Opcao invalida",12);
            break;
    }
}

//Pedido Cliente ok
void pedidoCliente()
{
    int count=0, x=6, opc, opcSabor, opcBebida;
    float precoPizza=0, precoBebida=0, total;
    char confirmaCliente, confirmaSabor, confirmaBebida, entraBebida, *nome = malloc(30), *pizzasabor = malloc(30), *bebidaSabor=malloc(30);
    Pedido *novoPe = (Pedido*) malloc(sizeof(Pedido));
    novoPe->proximo=NULL;
    Pedido *auxPedido = inicioPedido;
    Cliente *auxCliente = inicioCli;
    Sabores *auxPizza = inicioPizza;
    Bebida *auxBebida = inicioBebida;
    //Funcao chamaCliente
    do{
        clrscr();
        moldura();
        printfCenter("NOVO PEDIDO",1);
        gotoxy(2,3);
        printf("Digite o codigo do cliente [de 1 ate %d]: ", codCliente);
        scanf("%d", &opc);
            if(opc>0 && opc <= codCliente){
                if(opc==1){
                gotoxy(2,5);
                printf("Cod  Nome\t  Telefone\tRua\t\tNumero\t\tBairro");
                gotoxy(2,x);
                printf("%d", count+1);
                gotoxy(7,x);
                printf("%s",auxCliente->nome);
                gotoxy(18,x);
                printf("%s",auxCliente->telefone);
                gotoxy(32,x);
                printf("%s",auxCliente->rua);
                gotoxy(48,x);
                printf("%s",auxCliente->numero);
                gotoxy(64,x);
                printf("%s",auxCliente->bairro);
                //novoPe->nomeCliente = auxCliente->nome;
                nome = auxCliente->nome;
                novoPe->nomeCliente=nome;
                strtok(novoPe->nomeCliente, "\n");
            }else{
                Cliente *atual = inicioCli;
                opc--;
                for(count=0;count<opc;count++){
                    atual=atual->proximo;
                }
                gotoxy(2,5);
                printf("Cod  Nome\t  Telefone\tRua\t\tNumero\t\tBairro");
                gotoxy(2,x);
                printf("%d", count+1);
                gotoxy(7,x);
                printf("%s",atual->nome);
                gotoxy(18,x);
                printf("%s",atual->telefone);
                gotoxy(32,x);
                printf("%s",atual->rua);
                gotoxy(48,x);
                printf("%s",atual->numero);
                gotoxy(64,x);
                printf("%s",atual->bairro);
                //novoPe->nomeCliente = atual->nome;
                nome = atual->nome;
                novoPe->nomeCliente=nome;
                strtok(novoPe->nomeCliente, "\n");
            }
        }
            gotoxy(2,18);
            printf("Confirma o cliente selecionado?(s/n)");
            scanf(" %c", &confirmaCliente);
        }while(confirmaCliente!='s');
        //Funcao chama Pizza.
    do{
        clrscr();
        moldura();
        printfCenter("NOVO PEDIDO",1);
        gotoxy(2,3);
        printf("Digite o codigo da pizza [de 1 ate %d]: ", codSabor);
        scanf("%d", &opcSabor);
        gotoxy(2,5);
        printf("Cod  Sabor\t  Ingredientes\t\t\t\t\t\tPreco");
        if(opcSabor>0 && opcSabor <= codSabor){
            if(opcSabor==1){
                gotoxy(2,x);
                printf("%d", count+1);
                gotoxy(7,x);
                printf("%s",auxPizza->sabor);
                gotoxy(18,x);
                printf("%s",auxPizza->ingred);
                gotoxy(72,x);
                printf("%0.2f",auxPizza->preco);
                //novoPe->saborPizza = auxPizza->sabor;
                //novoPe->total=auxPizza->preco;
                pizzasabor = auxPizza->sabor;
                novoPe->saborPizza = pizzasabor;
                strtok(novoPe->saborPizza, "\n");
                precoPizza = auxPizza->preco;
                }else{
                    Sabores *atualPizza = inicioPizza;
                    opcSabor--;
                    for(count=0;count<opcSabor;count++){
                        atualPizza=atualPizza->proximo;
                    }
                    gotoxy(2,x);
                    printf("%d", count+1);
                    gotoxy(7,x);
                    printf("%s",atualPizza->sabor);
                    gotoxy(18,x);
                    printf("%s",atualPizza->ingred);
                    gotoxy(72,x);
                    printf("%0.2f",atualPizza->preco);
                    //novoPe->saborPizza = atualPizza->sabor;
                    precoPizza = atualPizza->preco;
                    pizzasabor = atualPizza->sabor;
                    novoPe->saborPizza = pizzasabor;
                    strtok(novoPe->saborPizza, "\n");
                }
        }
        gotoxy(2,18);
        printf("Confirma o Sabor selecionado?(s/n)");
        scanf(" %c", &confirmaSabor);
    }while(confirmaSabor!='s');

    //Funcao Chama bebida
    clrscr();
    moldura();
    printfCenter("NOVO PEDIDO",1);
    gotoxy(2,3);
    printf("deseja bebida?(s/n) %c", BLACK);
    gotoxy(22,3);
    scanf(" %c", &entraBebida);
    if(entraBebida=='s'){
        do{
            clrscr();
            moldura();
            printfCenter("NOVO PEDIDO",1);
            gotoxy(2,3);
            printf("Digite o codigo da Bebida [de 1 ate %d]: ", codBebida);
            scanf("%d", &opcBebida);
            gotoxy(2,5);
            printf("Cod  Sabor\t  Ingredientes\t\t\t\t\t\tPreco");
            if(opcBebida>0 && opcBebida <= codBebida){
                if(opcBebida==1){
                    gotoxy(2,x);
                    printf("%d", count+1);
                    gotoxy(7,x);
                    printf("%s",auxBebida->saborBebida);
                    gotoxy(72,x);
                    printf("%0.2f",auxBebida->preco);
                    //novoPe->saborBebida = auxBebida->saborBebida;
                    bebidaSabor = auxBebida->saborBebida;
                    novoPe->saborBebida=bebidaSabor;
                    strtok(novoPe->saborBebida, "\n");
                    precoBebida = auxBebida->preco;
                }else{
                    Bebida *atualBebida = inicioBebida;
                    opcBebida--;
                    for(count=0;count<opcBebida;count++){
                        atualBebida=atualBebida->proximo;
                    }
                    gotoxy(2,x);
                    printf("%d", count+1);
                    gotoxy(7,x);
                    printf("%s",atualBebida->saborBebida);
                    gotoxy(72,x);
                    printf("%0.2f",atualBebida->preco);
                    //novoPe->saborBebida = atualBebida->saborBebida;
                    bebidaSabor = atualBebida->saborBebida;
                    novoPe->saborBebida=bebidaSabor;
                    strtok(novoPe->saborBebida, "\n");
                    precoBebida = atualBebida->preco;
                }
            }
            gotoxy(2,18);
            printf("Confirma a bebida selecionada?(s/n)");
            scanf(" %c", &confirmaBebida);
            confirmaBebida = tolower(confirmaBebida);
        }while(confirmaBebida!='s');
    }else{
        novoPe->saborBebida = "-";
        strtok(novoPe->saborBebida, "\n");
    }
    total = precoBebida+precoPizza;
    novoPe->total = total;

    if(inicioPedido==NULL){
        inicioPedido = novoPe;
        codPedido = 1;
    }else{
        while(auxPedido->proximo!=NULL){
            auxPedido=auxPedido->proximo;
        }
        auxPedido->proximo = novoPe;
        codPedido++;
        }
    gotoxy(2,22);
    system("PAUSE");
}

void pedidoPromo(){
    int count=0, x=6, opc, opcSabor;
    char confirmaCliente, confirmaSabor;
    Pedido *novoPe = (Pedido*) malloc(sizeof(Pedido));
    novoPe->proximo=NULL;
    Pedido *auxPedido = inicioPedido;
    Cliente *auxCliente = inicioCli;
    Promocao *auxPromocao = inicioPro;
    do{
        novoPe->saborBebida = "-";
        strtok(novoPe->saborBebida, "\n");
        clrscr();
        moldura();
        printfCenter("NOVO PEDIDO",1);
        gotoxy(2,3);
        printf("Digite o codigo do cliente [de 1 ate %d]: ", codCliente);
        scanf("%d", &opc);
            if(opc>0 && opc <= codCliente){
                if(opc==1){
                    gotoxy(2,5);
                    printf("Cod  Nome\t  Telefone\tRua\t\tNumero\t\tBairro");
                    gotoxy(2,x);
                    printf("%d", count+1);
                    gotoxy(7,x);
                    printf("%s",auxCliente->nome);
                    gotoxy(18,x);
                    printf("%s",auxCliente->telefone);
                    gotoxy(32,x);
                    printf("%s",auxCliente->rua);
                    gotoxy(48,x);
                    printf("%s",auxCliente->numero);
                    gotoxy(64,x);
                    printf("%s",auxCliente->bairro);
                    novoPe->nomeCliente = auxCliente->nome;
                    strtok(novoPe->nomeCliente, "\n");
                }else{
                    Cliente *atual = inicioCli;
                    opc--;
                    for(count=0;count<opc;count++){
                        atual=atual->proximo;
                    }
                    gotoxy(2,5);
                    printf("Cod  Nome\t  Telefone\tRua\t\tNumero\t\tBairro");
                    gotoxy(2,x);
                    printf("%d", count+1);
                    gotoxy(7,x);
                    printf("%s",atual->nome);
                    gotoxy(18,x);
                    printf("%s",atual->telefone);
                    gotoxy(32,x);
                    printf("%s",atual->rua);
                    gotoxy(48,x);
                    printf("%s",atual->numero);
                    gotoxy(64,x);
                    printf("%s",atual->bairro);
                    novoPe->nomeCliente = auxCliente;
                    novoPe->nomeCliente = atual->nome;
                    strtok(novoPe->nomeCliente, "\n");
                }
            }
        gotoxy(2,18);
        printf("Confirma o cliente selecionado?(s/n)");
        scanf(" %c", &confirmaCliente);
        confirmaCliente = tolower(confirmaCliente);
    }while(confirmaCliente!='s');

    //Chama promocao
    do{
        clrscr();
        moldura();
        printfCenter("NOVO PEDIDO",1);
        gotoxy(2,3);
        printf("Digite o codigo da promocao [de 1 ate %d]: ", codPromocoes);
        scanf("%d", &opcSabor);
            gotoxy(2,5);
            printf("Cod  Promocao\t\t\t\t\t\tPreco");
            if(opcSabor>0 && opcSabor <= codSabor){
                if(opcSabor==1){
                    gotoxy(2,x);
                    printf("%d", count+1);
                    gotoxy(7,x);
                    printf("%s",auxPromocao->nomePromo);
                    gotoxy(72,x);
                    printf("%0.2f",auxPromocao->preco);
                    novoPe->saborPizza = auxPromocao->nomePromo;
                    strtok(novoPe->saborPizza, "\n");
                    novoPe->total=auxPromocao->preco;
                }else{
                    Sabores *atualPizza = inicioPizza;
                    opcSabor--;
                    for(count=0;count<opcSabor;count++){
                        atualPizza=atualPizza->proximo;
                    }
                    gotoxy(2,x);
                    printf("%d", count+1);
                    gotoxy(7,x);
                    printf("%s",atualPizza->sabor);
                    gotoxy(18,x);
                    printf("%s",atualPizza->ingred);
                    gotoxy(72,x);
                    printf("%0.2f",atualPizza->preco);
                    novoPe->saborPizza = atualPizza->sabor;
                    strtok(novoPe->saborPizza, "\n");
                    novoPe->total=atualPizza->preco;
                }
            }
        gotoxy(2,18);
        printf("Confirma o promocao selecionada?(s/n) %c", BLACK);
        gotoxy(40,18);
        scanf(" %c", &confirmaSabor);
        confirmaSabor = tolower(confirmaSabor);
    }while(confirmaSabor!='s');
        if(inicioPedido==NULL){
            inicioPedido = novoPe;
            codPedido = 1;
        }else{
            while(auxPedido->proximo!=NULL){
                auxPedido=auxPedido->proximo;
            }
            auxPedido->proximo = novoPe;
            codPedido++;
        }
    gotoxy(2,22);
    system("PAUSE");
}

void pedidoMesa(){

    int count=0, x=6, opc, opcSabor, opcBebida;
    float precoPizza=0, precoBebida=0, total;
    char confirmaCliente, confirmaSabor, confirmaBebida, promo, entraBebida, *codMesa = malloc(10);
    Pedido *novoPe = (Pedido*) malloc(sizeof(Pedido));
    novoPe->proximo=NULL;
    Pedido *auxPedido = inicioPedido;
    Cliente *auxCliente = inicioCli;
    Sabores *auxPizza = inicioPizza;
    Bebida *auxBebida = inicioBebida;
    Promocao *auxPromocao = inicioPro;
    //Funcao chamaCliente
    //do{
        clrscr();
        moldura();
        printfCenter("NOVO PEDIDO",1);
        gotoxy(2,3);
        printf("Digite o codigo da mesa: ");
        getchar();
        scanf("%s", codMesa);
        novoPe->nomeCliente = codMesa;
        strtok(novoPe->nomeCliente, "\n");
        gotoxy(2,18);

        clrscr();
        moldura();
        printfCenter("NOVO PEDIDO",1);
        gotoxy(2,3);
        printf("Promocao?(s/n)");
        scanf(" %c", &promo);
    if(promo!='s'){
        //Chama pizza
        do{
            clrscr();
            moldura();
            printfCenter("NOVO PEDIDO",1);
            gotoxy(2,3);
            printf("Digite o codigo da pizza [de 1 ate %d]: ", codSabor);
            scanf("%d", &opcSabor);
            gotoxy(2,5);
            printf("Cod  Sabor\t  Ingredientes\t\t\t\t\t\tPreco");
            if(opcSabor>0 && opcSabor <= codSabor){
                if(opcSabor==1){
                    gotoxy(2,x);
                    printf("%d", count+1);
                    gotoxy(7,x);
                    printf("%s",auxPizza->sabor);
                    gotoxy(18,x);
                    printf("%s",auxPizza->ingred);
                    gotoxy(72,x);
                    printf("%0.2f",auxPizza->preco);
                    novoPe->saborPizza = auxPizza->sabor;
                    strtok(novoPe->saborPizza, "\n");
                    //novoPe->total=auxPizza->preco;
                    precoPizza = auxPizza->preco;
                }else{
                    Sabores *atualPizza = inicioPizza;
                    opcSabor--;
                    for(count=0;count<opcSabor;count++){
                        atualPizza=atualPizza->proximo;
                    }
                    gotoxy(2,x);
                    printf("%d", count+1);
                    gotoxy(7,x);
                    printf("%s",atualPizza->sabor);
                    gotoxy(18,x);
                    printf("%s",atualPizza->ingred);
                    gotoxy(72,x);
                    printf("%0.2f",atualPizza->preco);
                    novoPe->saborPizza = atualPizza->sabor;
                    strtok(novoPe->saborPizza, "\n");
                    //novoPe->total=atualPizza->preco;
                    precoPizza = auxPizza->preco;
                }
            }
            gotoxy(2,18);
            printf("Confirma o Sabor selecionado?(s/n)");
            scanf(" %c", &confirmaSabor);
        }while(confirmaSabor!='s');
        //Funcao Chama bebida
        clrscr();
        moldura();
        printfCenter("NOVO PEDIDO",1);
        gotoxy(2,3);
        printf("deseja bebida?(s/n) %c", BLACK);
        gotoxy(22,3);
        scanf(" %c", &entraBebida);
        if(entraBebida=='s'){
            do{
                clrscr();
                moldura();
                printfCenter("NOVO PEDIDO",1);
                gotoxy(2,3);
                printf("Digite o codigo da Bebida [de 1 ate %d]: ", codBebida);
                scanf("%d", &opcBebida);
                gotoxy(2,5);
                printf("Cod  Sabor\t  Ingredientes\t\t\t\t\t\tPreco");
                if(opcBebida>0 && opcBebida <= codBebida){
                    if(opcBebida==1){
                        gotoxy(2,x);
                        printf("%d", count+1);
                        gotoxy(7,x);
                        printf("%s",auxBebida->saborBebida);
                        gotoxy(72,x);
                        printf("%0.2f",auxBebida->preco);
                        novoPe->saborBebida = auxBebida->saborBebida;
                        strtok(novoPe->saborBebida, "\n");
                        precoBebida = auxBebida->preco;
                    }else{
                        Bebida *atualBebida = inicioBebida;
                        opcBebida--;
                        for(count=0;count<opcBebida;count++){
                            atualBebida=atualBebida->proximo;
                        }
                        gotoxy(2,x);
                        printf("%d", count+1);
                        gotoxy(7,x);
                        printf("%s",atualBebida->saborBebida);
                        gotoxy(72,x);
                        printf("%0.2f",atualBebida->preco);
                        novoPe->saborBebida = atualBebida->saborBebida;
                        strtok(novoPe->saborBebida, "\n");
                        precoBebida = auxBebida->preco;
                    }
                }
                gotoxy(2,18);
                printf("Confirma a bebida selecionada?(s/n)");
                scanf(" %c", &confirmaBebida);
                confirmaBebida = tolower(confirmaBebida);
            }while(confirmaBebida!='s');
        }else{
        novoPe->saborBebida = "-";
        strtok(novoPe->saborBebida, "\n");
        }
            total = precoBebida+precoPizza;
            novoPe->total = total;
    }else{
    //Chama promocao
        do{
            novoPe->saborBebida = "-";
            strtok(novoPe->saborBebida, "\n");
            clrscr();
            moldura();
            printfCenter("NOVO PEDIDO",1);
            gotoxy(2,3);
            printf("Digite o codigo da promocao [de 1 ate %d]: ", codPromocoes);
            scanf("%d", &opcSabor);
            gotoxy(2,5);
            printf("Cod  Promocao\t\t\t\t\t\tPreco");
            if(opcSabor>0 && opcSabor <= codSabor){
                if(opcSabor==1){
                    gotoxy(2,x);
                    printf("%d", count+1);
                    gotoxy(7,x);
                    printf("%s",auxPromocao->nomePromo);
                    gotoxy(72,x);
                    printf("%0.2f",auxPromocao->preco);
                    novoPe->saborPizza = auxPromocao->nomePromo;
                    strtok(novoPe->saborPizza, "\n");
                    novoPe->total=auxPromocao->preco;
                }else{
                    Sabores *atualPizza = inicioPizza;
                    opcSabor--;
                    for(count=0;count<opcSabor;count++){
                        atualPizza=atualPizza->proximo;
                    }
                    gotoxy(2,x);
                    printf("%d", count+1);
                    gotoxy(7,x);
                    printf("%s",atualPizza->sabor);
                    gotoxy(18,x);
                    printf("%s",atualPizza->ingred);
                    gotoxy(72,x);
                    printf("%0.2f",atualPizza->preco);
                    novoPe->saborPizza = atualPizza->sabor;
                    strtok(novoPe->saborPizza, "\n");
                    novoPe->total=atualPizza->preco;
                }
            }
            gotoxy(2,18);
            printf("Confirma o promocao selecionada?(s/n) %c", BLACK);
            gotoxy(40,18);
            scanf(" %c", &confirmaSabor);
            confirmaSabor = tolower(confirmaSabor);
        }while(confirmaSabor!='s');
    }
    if(inicioPedido==NULL){
        inicioPedido = novoPe;
        codPedido = 1;
    }else{
        while(auxPedido->proximo!=NULL){
            auxPedido=auxPedido->proximo;
        }
        auxPedido->proximo = novoPe;
        codPedido++;
        }
    gotoxy(2,22);
    system("PAUSE");
}

//Pedido balcao
void pedidoBalcao(){
    char *nomeBalcao = malloc(30);
    int count=0, x=6, opc, opcSabor, opcBebida;
    float precoPizza=0, precoBebida=0, total;
    char confirmaCliente, confirmaSabor, confirmaBebida, entraBebida, promo;
    Pedido *novoPe = (Pedido*) malloc(sizeof(Pedido));
    novoPe->proximo=NULL;
    Pedido *auxPedido = inicioPedido;
    Cliente *auxCliente = inicioCli;
    Sabores *auxPizza = inicioPizza;
    Bebida *auxBebida = inicioBebida;
    Promocao *auxPromocao = inicioPro;

    do{
        clrscr();
        moldura();
        printfCenter("NOVO PEDIDO",1);
        gotoxy(2,3);
        printf("Digite um nome para retirada: ");
        scanf("%s", nomeBalcao);
        novoPe->nomeCliente = nomeBalcao;
        strtok(novoPe->nomeCliente, "\n");
        gotoxy(2,18);
        printf("Confirma o nome digitado selecionado?(s/n)");
        scanf(" %c", &confirmaCliente);
        }while(confirmaCliente!='s');
    clrscr();
    moldura();
    printfCenter("NOVO PEDIDO",1);
    gotoxy(2,3);
    printf("Promocao?(s/n)");
    scanf(" %c", &promo);
    if(promo!='s'){
        do{
            clrscr();
            moldura();
            printfCenter("NOVO PEDIDO",1);
            gotoxy(2,3);
            printf("Digite o codigo da pizza [de 1 ate %d]: ", codSabor);
            scanf("%d", &opcSabor);
            gotoxy(2,5);
            printf("Cod  Sabor\t  Ingredientes\t\t\t\t\t\tPreco");
            if(opcSabor>0 && opcSabor <= codSabor){
                if(opcSabor==1){
                    gotoxy(2,x);
                    printf("%d", count+1);
                    gotoxy(7,x);
                    printf("%s",auxPizza->sabor);
                    gotoxy(18,x);
                    printf("%s",auxPizza->ingred);
                    gotoxy(72,x);
                    printf("%0.2f",auxPizza->preco);
                    novoPe->saborPizza = auxPizza->sabor;
                    strtok(novoPe->saborPizza, "\n");
                    precoPizza = auxPizza->preco;
                }else{
                    Sabores *atualPizza = inicioPizza;
                    opcSabor--;
                    for(count=0;count<opcSabor;count++){
                        atualPizza=atualPizza->proximo;
                    }
                    gotoxy(2,x);
                    printf("%d", count+1);
                    gotoxy(7,x);
                    printf("%s",atualPizza->sabor);
                    gotoxy(18,x);
                    printf("%s",atualPizza->ingred);
                    gotoxy(72,x);
                    printf("%0.2f",atualPizza->preco);
                    novoPe->saborPizza = atualPizza->sabor;
                    strtok(novoPe->saborPizza, "\n");
                    precoPizza = auxPizza->preco;
                }
            }
            gotoxy(2,18);
            printf("Confirma o Sabor selecionado?(s/n)");
            scanf(" %c", &confirmaSabor);
        }while(confirmaSabor!='s');

        //Funcao Chama bebida
        clrscr();
        moldura();
        printfCenter("NOVO PEDIDO",1);
        gotoxy(2,3);
        printf("deseja bebida?(s/n) %c", BLACK);
        gotoxy(22,3);
        scanf(" %c", &entraBebida);
        if(entraBebida=='s'){
            do{
                clrscr();
                moldura();
                printfCenter("NOVO PEDIDO",1);
                gotoxy(2,3);
                printf("Digite o codigo da Bebida [de 1 ate %d]: ", codBebida);
                scanf("%d", &opcBebida);
                gotoxy(2,5);
                printf("Cod  Sabor\t  Ingredientes\t\t\t\t\t\tPreco");
                if(opcBebida>0 && opcBebida <= codBebida){
                    if(opcBebida==1){
                        gotoxy(2,x);
                        printf("%d", count+1);
                        gotoxy(7,x);
                        printf("%s",auxBebida->saborBebida);
                        gotoxy(72,x);
                        printf("%0.2f",auxBebida->preco);
                        novoPe->saborBebida = auxBebida->saborBebida;
                        strtok(novoPe->saborBebida, "\n");
                        precoBebida = auxBebida->preco;
                    }else{
                        Bebida *atualBebida = inicioBebida;
                        opcBebida--;
                        for(count=0;count<opcBebida;count++){
                            atualBebida=atualBebida->proximo;
                        }
                        gotoxy(2,x);
                        printf("%d", count+1);
                        gotoxy(7,x);
                        printf("%s",atualBebida->saborBebida);
                        gotoxy(72,x);
                        printf("%0.2f",atualBebida->preco);
                        novoPe->saborBebida = atualBebida->saborBebida;
                        strtok(novoPe->saborBebida, "\n");
                        precoBebida = auxBebida->preco;
                    }
                }
                gotoxy(2,18);
                printf("Confirma a bebida selecionada?(s/n)");
                scanf(" %c", &confirmaBebida);
                confirmaBebida = tolower(confirmaBebida);
            }while(confirmaBebida!='s');
        }else{
        novoPe->saborBebida = "-";
        strtok(novoPe->saborBebida, "\n");
        }
        total = precoBebida+precoPizza;
        novoPe->total = total;
        }else{
        //Chama promocao
            do{
                novoPe->saborBebida = "-";
                strtok(novoPe->saborBebida, "\n");
                clrscr();
                moldura();
                printfCenter("NOVO PEDIDO",1);
                gotoxy(2,3);
                printf("Digite o codigo da promocao [de 1 ate %d]: ", codPromocoes);
                scanf("%d", &opcSabor);
                gotoxy(2,5);
                printf("Cod  Promocao\t\t\t\t\t\tPreco");
                if(opcSabor>0 && opcSabor <= codSabor){
                    if(opcSabor==1){
                        gotoxy(2,x);
                        printf("%d", count+1);
                        gotoxy(7,x);
                        printf("%s",auxPromocao->nomePromo);
                        gotoxy(72,x);
                        printf("%0.2f",auxPromocao->preco);
                        novoPe->saborPizza = auxPromocao->nomePromo;
                        strtok(novoPe->saborPizza, "\n");
                        novoPe->total=auxPromocao->preco;
                    }else{
                        Sabores *atualPizza = inicioPizza;
                        opcSabor--;
                        for(count=0;count<opcSabor;count++){
                            atualPizza=atualPizza->proximo;
                        }
                        gotoxy(2,x);
                        printf("%d", count+1);
                        gotoxy(7,x);
                        printf("%s",atualPizza->sabor);
                        gotoxy(18,x);
                        printf("%s",atualPizza->ingred);
                        gotoxy(72,x);
                        printf("%0.2f",atualPizza->preco);
                        novoPe->saborPizza = atualPizza->sabor;
                        strtok(novoPe->saborPizza, "\n");
                        novoPe->total=atualPizza->preco;
                    }
                }
                gotoxy(2,18);
                printf("Confirma o promocao selecionada?(s/n) %c", BLACK);
                gotoxy(40,18);
                scanf(" %c", &confirmaSabor);
                confirmaSabor = tolower(confirmaSabor);
            }while(confirmaSabor!='s');
        }

    if(inicioPedido==NULL){
        inicioPedido = novoPe;
        codPedido = 1;
    }else{
        while(auxPedido->proximo!=NULL){
            auxPedido=auxPedido->proximo;
        }
        auxPedido->proximo = novoPe;
        codPedido++;
        }
    gotoxy(2,22);
    system("PAUSE");
}

//Listar Pedido 1.2
void listarPedido()
{
    clrscr();
    moldura();
    printfCenter("Relatorios",1);
    system("C:\\PIM\\solicitacoes.xlsm");
}

//Excluir pedidos 1.3
void excluirPedido()
{
    int op, x;
    moldura();
    printfCenter("Excluir Pedido", 1);
    gotoxy(2,3);
    printf("Digite [de 1 ate %d] do pedido que  deseja retirar: ", codPedido);
    scanf("%d", &op);
    if(op>0 && op <= codPedido){
        if(op==1){
            Pedido *aux= inicioPedido;
            inicioPedido = aux->proximo;
            codPedido--;
        }else{
            Pedido *atual = inicioPedido, *anterior=inicioPedido;
            for(x=1;x<op;x++){
                anterior=atual;
                atual=atual->proximo;
            }
            anterior->proximo=atual->proximo;
            codPedido--;
        }
    }else{
        printf("codigo de Pedido invalido");
    }
    if(inicioPedido==NULL){
        printfCenter("Lista esta vazia", 5);
        gotoxy(2,22);
        system("PAUSE");
        clrscr();
    }
}

//FIM do Menu PEDIDO;

//menu 2 PIZZAS
void pizzas()
{
    int op;
    do{
        clrscr();
        moldura();
        printfCenter("Menu Pizzas", 1);
        gotoxy(2,3);
        printf("0 - voltar ao menu principal");
        gotoxy(2,4);
        printf("1 - Cadastrar Pizza");
        gotoxy(2,5);
        printf("2 - Listar Pizzas");
        gotoxy(2,6);
        printf("3 - Alterar Pizza");
        gotoxy(2,7);
        printf("4 - Excluir Pizza");
        gotoxy(2,8);
        printf("Digite a opcao: %c", BLACK);
        gotoxy(18,8);
        scanf("%d", &op);
        switch(op)
        {
            case 0: clrscr();
                break;
            case 1: clrscr();
                cadastrarPizza();
                break;
            case 2: clrscr();
                listarPizza();
                break;
            case 3: clrscr();
                alteraPizza();
                break;
            case 4: clrscr();
                excluirPizza();
                break;
            default: printfCenter("Opcao invalida", 12);
                break;
        }
    }while(op!=0);
}

//Cadastrar Pizza 2.11
void cadastrarPizza()
{
    Sabores *aux;
    char op;
    int x;
    do{
        moldura();
        Sabores *novoSabor = (Sabores*)malloc(sizeof(Sabores));
        novoSabor->proximo=NULL;
        aux = inicioPizza;
        for(x=0;x<13;x++)
        {
            gotoxy(x+8,3);
            printf("%c",BLACK);
        }
        getchar();
        printfCenter("Cadastro de pizza", 1);
        printfNovo("Sabor:", 3);
        fgets(novoSabor->sabor,sizeof(novoSabor->sabor),stdin);
        strtok(novoSabor->sabor, "\n");
        for(x=0;x<50;x++)
        {
            gotoxy(x+22,5);
            printf("%c",BLACK);
        }
        printfNovo("Ingredientes da pizza:",5);
        fgets(novoSabor->ingred,sizeof(novoSabor->ingred),stdin);
        strtok(novoSabor->ingred, "\n");
        for(x=0;x<4;x++)
        {
            gotoxy(x+27,7);
            printf("%c",BLACK);
        }
        printfNovo("Infome o custo da pizza:",7);
        gotoxy(27,7);
        scanf("%f", &novoSabor->custo);
        for(x=0;x<4;x++)
        {
            gotoxy(x+27,9);
            printf("%c",BLACK);
        }
        printfNovo("Infome o preco da pizza:",9);
        gotoxy(27,9);
        scanf("%f", &novoSabor->preco);

        if(inicioPizza==NULL){
            inicioPizza = novoSabor;
            codSabor = 1;
        }else{
            while(aux->proximo!=NULL){
                aux=aux->proximo;
            }
            aux->proximo = novoSabor;
            codSabor++;
        }
        getchar();
        printfNovo("deseja cadastrar mais pizzas?: (s/n)", 18);
        scanf(" %c", &op);
        op = tolower(op);
        clrscr();
    }while(op!='n');
}

//Listar Pizza 2.2
void listarPizza()
{
    int count=0, x=5, y=5;
    clrscr();
    moldura();
    Sabores *aux=inicioPizza;
    printfCenter("Lista de sabores",1);
    gotoxy(2,3);
    printf("Cod  Sabor\t      Ingredientes\t\t\t\t\t Preco");
    while(aux != NULL){
        gotoxy(7,x);
        printf("%s",aux->sabor);
        gotoxy(22,x);
        printf("%s",aux->ingred);
        gotoxy(73,x);
        printf("%0.2f",aux->preco);
        x++;
        aux=aux->proximo;
    }
    for(count=0;count<codSabor;count++){
        gotoxy(2,y);
        printf("%d",count+1);
        y++;
    }
    gotoxy(2,22);
    system("PAUSE");
    clrscr();
}

//Alterar custos e valores da pizza 2.3
void alteraPizza()
{
    float novopreco, novocusto;
    int count=0, opc, x=5;
    char op;
    Sabores *aux = inicioPizza;
    do
    {
        clrscr();
        moldura();
        printfCenter("Alterando os custos e precos ",1);
        gotoxy(2,3);
        printf("Digite [de 1 ate %d] para alterar o preco da pizza: ", codSabor);
        scanf("%d", &opc);
        Sabores *atual = inicioPizza;
        if(opc>0 && opc <= codSabor){
            if(opc==1){
                gotoxy(3,x);
                printf("%s",aux->sabor);
                gotoxy(15,x);
                printf("%s",aux->ingred);
                gotoxy(70,x);
                printf("%0.2f",aux->preco);
            }else{
                opc--;
                for(count=0;count<opc;count++){
                    atual=atual->proximo;
                }
                gotoxy(3,x);
                printf("%s",atual->sabor);
                gotoxy(15,x);
                printf("%s",atual->ingred);
                gotoxy(70,x);
                printf("%0.2f",atual->preco);
            }
    }
        gotoxy(2,8);
        printf("Digite o novo custo da pizza: %c%c%c%c",BLACK,BLACK,BLACK,BLACK);
        gotoxy(32,8);
        scanf("%f", &novocusto);
        atual->custo = novocusto;
        gotoxy(2,9);
        printf("Digite o novo valor da pizza: %c%c%c%c", BLACK,BLACK,BLACK,BLACK);
        gotoxy(32,9);
        scanf("%f", &novopreco);
        atual->preco = novopreco;
        printfNovo("deseja fazer mais alguma ateracao?(s/n)",18);
        gotoxy(41,18);
        printf("%c", BLACK);
        gotoxy(41,18);
        scanf(" %c", &op);
        op = tolower(op);
    }while(op!='n');
}

//Excluir Pizza 2.4
void excluirPizza()
{
    int op,x=6,opcSabor, count=0;
    char confirmaSabor;
    Sabores *auxPizza = inicioPizza;

    do{
    clrscr();
    moldura();
    printfCenter("Removendo Pizza", 1);
    printfCenter("",1);
    gotoxy(2,3);
    printf("Digite o codigo da pizza que deseja excluir [de 1 ate %d]: ", codSabor);
    scanf("%d", &opcSabor);
    op =  opcSabor;
        gotoxy(2,5);
        printf("Cod  Sabor\t  Ingredientes\t\t\t\t\t\tPreco");
        if(opcSabor>0 && opcSabor <= codSabor){
            if(opcSabor==1){
            count = 0;
            gotoxy(2,x);
            printf("%d", count+1);
            gotoxy(7,x);
            printf("%s",auxPizza->sabor);
            gotoxy(18,x);
            printf("%s",auxPizza->ingred);
            gotoxy(72,x);
            printf("%0.2f",auxPizza->preco);
            }else{
                Sabores *atualPizza = inicioPizza;
                opcSabor--;
                for(count=0;count<opcSabor;count++){
                    atualPizza=atualPizza->proximo;
                }
                gotoxy(2,x);
                printf("%d", count+1);
                gotoxy(7,x);
                printf("%s",atualPizza->sabor);
                gotoxy(18,x);
                printf("%s",atualPizza->ingred);
                gotoxy(72,x);
                printf("%0.2f",atualPizza->preco);
            }
        }
        gotoxy(2,10);
        printf("Confirma o Sabor selecionado?(s/n)");
        scanf(" %c", &confirmaSabor);
        confirmaSabor = tolower(confirmaSabor);
    }while(confirmaSabor!='s');

    if(op>0 && op <= codSabor){
    if(op==1){
        Sabores *aux= inicioPizza;
        inicioPizza = aux->proximo;
        codSabor--;
    }else{
        Sabores *atual = inicioPizza, *anterior=inicioPizza;
        for(x=1;x<op;x++){
            anterior=atual;
            atual=atual->proximo;
        }
        anterior->proximo=atual->proximo;
        codSabor--;
        }
    }
    gotoxy(2,22);
    system("PAUSE");
}
//FIM DO MENU PIZZA;

//Menu 3 BEBIDAS
void bebidas()
{
    int op;
    do{
        clrscr();
        moldura();
        printfCenter("Menu Bebidas",1);
        printfNovo("0 - voltar ao menu principal",3);
        printfNovo("1 - Cadastrar Bebida",4);
        printfNovo("2 - Listar Bebidas",5);
        printfNovo("3 - Alterar Preco de bebida",6);
        printfNovo("4 - Excluir Bebida",7);
        gotoxy(2,8);
        printf("Digite a opcao: %c", BLACK);
        gotoxy(18,8);
        scanf("%d", &op);
        switch(op)
        {
            case 0: clrscr();
                break;
            case 1: clrscr();
                cadastroBebida();
                break;
            case 2: clrscr();
                listarBebida();
                break;
            case 3: clrscr();
                alterarBebida();
                break;
            case 4: clrscr();
                excluirBebida();
                break;
            default: printfCenter("Opcao invalida",18);
                break;
        }
    }while(op!=0);
}
//Cadastro Bebida 3.1
void cadastroBebida(){
    clrscr();
    char op;
    int x;
    Bebida *aux;
    do{
        Bebida *novaBebida = (Bebida*) malloc(sizeof(Bebida));
        novaBebida->proximo = NULL;
        aux = inicioBebida;
        clrscr();
        moldura();
        printfCenter("Casdastro bebidas", 1);
        for(x=0;x<30;x++)
        {
            gotoxy(x+18,3);
            printf("%c",BLACK);
        }
        getchar();
        printfNovo("Nome da bebida: ",3);
        fgets(novaBebida->saborBebida,sizeof(novaBebida->saborBebida),stdin);
        strtok(novaBebida->saborBebida, "\n");
        printfNovo("Custo da bebida: ",5);
        for(x=0;x<4;x++)
        {
            gotoxy(x+19,5);
            printf("%c",BLACK);
        }
        gotoxy(19,5);
        scanf("%f", &novaBebida->custo);
        printfNovo("Valor da bebida: ",7);
        for(x=0;x<4;x++)
        {
            gotoxy(x+19,7);
            printf("%c",BLACK);
        }
        gotoxy(19,7);
        scanf("%f", &novaBebida->preco);
        if(inicioBebida==NULL){
            inicioBebida = novaBebida;
            codBebida = 1;
        }else{
            while(aux->proximo!=NULL){
                aux=aux->proximo;
            }
            aux->proximo = novaBebida;
            codBebida++;
        }
        getchar();
        printfNovo("Deseja continuar cadastrando?(s/n)",18);
        scanf(" %c", &op);
        op = tolower(op);
    }while(op!='n');
}

//Listar Bebida 3.2
void listarBebida(){
    Bebida *aux = inicioBebida;
    int x=4,y=1;
    clrscr();
    moldura();
    printfCenter("Listagem de Bebidas",1);
    printfNovo("Cod  Bebida\t\t\t\t\t\t\t\tPreco",3);
    while(aux!=NULL){
        gotoxy(2,x);
        printf("%d", y);
        gotoxy(7,x);
        printf("%s",aux->saborBebida);
        gotoxy(72,x);
        printf("%0.2f",aux->preco);
        aux=aux->proximo;
        x++;
        y++;
    }
    gotoxy(2,22);
    system("PAUSE");
}

//Alteracao Bebida 3.3
void alterarBebida(){
    float novopreco, novocusto;
    int count=0, opc, x=5;
    char op;
    Bebida *aux = inicioBebida;
    do
    {
        clrscr();
        moldura();
        printfCenter("Alterando os custos e precos ",1);
        gotoxy(2,3);
        printf("Digite [de 1 ate %d] para alterar o preco da bebida: ", codBebida);
        scanf("%d", &opc);
        Bebida *atual = inicioBebida;
        if(opc>0 && opc <= codBebida){
            if(opc==1){
                gotoxy(2,x);
                printf("%s",aux->saborBebida);
                gotoxy(72,x);
                printf("%0.2f",aux->preco);
            }else{
                opc--;
                for(count=0;count<opc;count++){
                    atual=atual->proximo;
                }
                gotoxy(2,x);
                printf("%s",atual->saborBebida);
                gotoxy(72,x);
                printf("%0.2f",atual->preco);
            }
    }
        gotoxy(2,8);
        printf("Digite o novo custo da bebida: %c%c%c%c", BLACK,BLACK,BLACK,BLACK);
        gotoxy(33,8);
        scanf("%f", &novocusto);
        atual->custo = novocusto;
        gotoxy(2,9);
        printf("Digite o novo valor da bebida: %c%c%c%c", BLACK,BLACK,BLACK,BLACK);
        gotoxy(33,9);
        scanf("%f", &novopreco);
        atual->preco = novopreco;
        printfNovo("deseja fazer mais alguma ateracao?(s/n)",18);
        gotoxy(41,18);
        printf("%c", BLACK);
        gotoxy(41,18);
        scanf(" %c", &op);
        op = tolower(op);
    }while(op!='n');
}

//excluir Bebida 3.4
void excluirBebida(){
    int op,x=6,opc, count=0;
    char confirmaSabor;
    Bebida *aux = inicioBebida;

    do{
        clrscr();
        moldura();
        printfCenter("Removendo Pizza", 1);
        gotoxy(2,3);
        printf("Digite o codigo da bebida que deseja excluir [de 1 ate %d]: ", codBebida);
        scanf("%d", &opc);
        op =  opc;
        gotoxy(2,5);
        printf("Bebida\t\t\t\t\t\t\t\tPreco");
        Bebida *atual = inicioBebida;
        if(opc>0 && opc <= codBebida){
            if(opc==1){
                gotoxy(2,x);
                printf("%s",aux->saborBebida);
                gotoxy(72,x);
                printf("%0.2f",aux->preco);
            }else{
                opc--;
                for(count=0;count<opc;count++){
                    atual=atual->proximo;
                }
                gotoxy(2,x);
                printf("%s",atual->saborBebida);
                gotoxy(72,x);
                printf("%0.2f",atual->preco);
            }
        }
        gotoxy(2,10);
        printf("Confirma o Bebida selecionada?(s/n)");
        scanf(" %c", &confirmaSabor);
        confirmaSabor = tolower(confirmaSabor);
    }while(confirmaSabor!='s');

    if(op>0 && op <= codBebida){
    if(op==1){
        Bebida *auxBebida= inicioBebida;
        inicioBebida = auxBebida->proximo;
        codBebida--;
    }else{
        Bebida *atual = inicioBebida, *anterior=inicioBebida;
        for(x=1;x<op;x++){
            anterior=atual;
            atual=atual->proximo;
        }
        anterior->proximo=atual->proximo;
        codBebida--;
        }
    }
    gotoxy(2,22);
    system("PAUSE");
}
//Fim do menu Bebidas

//menu 4 PROMOÇÕES
void promocoes()
{
    int op;
    do{
        clrscr();
        moldura();
        printfCenter("Menu Promocao",1);
        gotoxy(2,3);
        printf("0 - voltar ao menu principal");
        gotoxy(2,4);
        printf("1 - Cadastrar promocao");
        gotoxy(2,5);
        printf("2 - Listar promocoes");
        gotoxy(2,6);
        printf("3 - Excluir promocao");
        gotoxy(2,7);
        printf("Digite a opcao: %c", BLACK);
        gotoxy(18,7);
        scanf("%d", &op);
        switch(op)
        {
            case 0:
                    clrscr();
                break;
            case 1:
                clrscr();
                cadastrarPromo();
                break;
            case 2:
                clrscr();
                listarPromo();
                break;
            case 3:
                clrscr();
                excluirPromo();
                break;
            default: printfCenter("Opcao invalida", 12);
                break;
        }
    }while(op!=0);
}

//Cadastrar Promoção 4.1
void cadastrarPromo()
{
    char op;
    int x;
    Promocao *aux;
    do{
        moldura();
        Promocao *novaPromocao = (Promocao*)malloc(sizeof(Promocao));
        novaPromocao->proximo=NULL;
        aux = inicioPro;
        for(x=0;x<40;x++)
        {
            gotoxy(x+19,3);
            printf("%c",BLACK);
        }
        getchar();
        printfCenter("Cadastro de promocao", 1);
        printfNovo("Nome da promocao:", 3);
        fgets(novaPromocao->nomePromo,sizeof(novaPromocao->nomePromo),stdin);
        strtok(novaPromocao->nomePromo, "\n");
        for(x=0;x<4;x++)
        {
            gotoxy(x+30,5);
            printf("%c",BLACK);
        }
        printfNovo("Infome o custo da Promocao:",5);
        gotoxy(30,5);
        scanf("%f", &novaPromocao->custo);
        for(x=0;x<4;x++)
        {
            gotoxy(x+30,7);
            printf("%c",BLACK);
        }
        printfNovo("Infome o preco da Promocao:",7);
        gotoxy(30,7);
        scanf("%f", &novaPromocao->preco);
        if(inicioPro==NULL){
            inicioPro = novaPromocao;
            codPromocoes = 1;
            }else{
                while(aux->proximo!=NULL){
                    aux=aux->proximo;
                }
                aux->proximo = novaPromocao;
                codPromocoes++;
            }
        getchar();
        printfCenter("deseja cadastrar mais promocoes?: (s/n)", 18);
        scanf(" %c", &op);
        op = tolower(op);
        clrscr();
    }while(op!='n');
}

//Listar Promoção 4.2
void listarPromo()
{
    int x=4, y=1;
    clrscr();
    moldura();
    Promocao *aux=inicioPro;
    printfCenter("Lista de Promocoes",1);
    printfNovo("Cod  Promocao\t\t\t\t\t\t\t\tPreco",3);
    while(aux != NULL){
        gotoxy(2,x);
        printf("%d",y);
        gotoxy(7,x);
        printf("%s",aux->nomePromo);
        gotoxy(72,x);
        printf("%0.2f",aux->preco);
        x++;
        y++;
        aux=aux->proximo;
    }
    gotoxy(2,22);
    system("PAUSE");
    clrscr();
}
//Excluir Promoção 4.3
void excluirPromo()
{
    int op, x;
    clrscr();
    Promocao *remover = inicioPro;
    moldura();
    printfCenter("Excluir promocao", 1);
    gotoxy(2,3);
    printf("Digite [de 1 ate %d] da Promocao que  deseja retirar: ", codPromocoes);
    scanf("%d", &op);
    if(op>0 && op <= codPromocoes){
    if(op==1){
        Promocao *aux= inicioPro;
        inicioPro = aux->proximo;
        codPromocoes--;
    }else{
        Promocao *atual = inicioPro, *anterior=inicioPro;
        for(x=1;x<op;x++){
            anterior=atual;
            atual=atual->proximo;
        }
        anterior->proximo=atual->proximo;
        codPromocoes--;
        }
    }else{
        printf("codigo de Promocao invalido");
    }
    gotoxy(2,22);
    system("PAUSE");
}
//Fim do MENU PROMOÇOES

//MENU 5 Clientes
void menucliente()
{
    int op;
    do{
        clrscr();
        moldura();
        printfCenter("Menu Cliente",1);
        printfNovo("0 - voltar ao menu principal",3);
        printfNovo("1 - Cadastro de Clientes",4);
        printfNovo("2 - Pesquisar Clientes",5);
        printfNovo("3 - Listar Clientes",6);
        printfNovo("4 - Excluir Clientes",7);
        gotoxy(2,8);
        printf("Digite a opcao: %c",BLACK);
        gotoxy(18,8);
        scanf("%d", &op);
        switch(op)
        {
        case 0: clrscr();
            break;
        case 1:
            clrscr();
            cadastroCliente();
            break;
        case 2:
            clrscr();
            pesquisarCliente();
            break;
        case 3:
            clrscr();
            listarCliente();
            break;
        case 4:
            clrscr();
            removerCliente();
            break;
        default: printfCenter("opcao invalida",12);
            break;
        }
    }while (op!=0);
}
//Cadastrar Cliente 5.1
void cadastroCliente()
{
    Cliente *aux;
    char op;
    int x;
    do{
        clrscr();
        moldura();
        Cliente *novoCliente = (Cliente*)malloc(sizeof(Cliente));
        novoCliente->proximo=NULL;
        aux = inicioCli;
        printfCenter("Cadastro de Cliente",1);
        for(x=0;x<25;x++)
        {
            gotoxy(x+7,3);
            printf("%c",BLACK);
        }
        getchar();
        printfNovo("Nome:",3);
        fgets(novoCliente->nome,sizeof(novoCliente->nome),stdin);
        strtok(novoCliente->nome, "\n");
         for(x=0;x<25;x++)
        {
            gotoxy(x+11,5);
            printf("%c",BLACK);
        }
        printfNovo("Telefone:",5);
        fgets(novoCliente->telefone,sizeof(novoCliente->telefone),stdin);
        strtok(novoCliente->telefone, "\n");
        for(x=0;x<25;x++)
        {
            gotoxy(x+9,7);
            printf("%c",BLACK);
        }
        printfNovo("Rua/Av:",7);
        fgets(novoCliente->rua,sizeof(novoCliente->rua),stdin);
        strtok(novoCliente->rua, "\n");
        for(x=0;x<25;x++)
        {
            gotoxy(x+9,9);
            printf("%c",BLACK);
        }
        printfNovo("Numero:",9);
        fgets(novoCliente->numero,sizeof(novoCliente->numero),stdin);
        strtok(novoCliente->numero, "\n");
        for(x=0;x<25;x++)
        {
            gotoxy(x+9,11);
            printf("%c",BLACK);
        }
        printfNovo("Bairro:",11);
        fgets(novoCliente->bairro,sizeof(novoCliente->bairro),stdin);
        strtok(novoCliente->bairro, "\n");
        for(x=0;x<25;x++)
        {
            gotoxy(x+9,13);
            printf("%c",BLACK);
        }
        printfNovo("Cidade:",13);
        fgets(novoCliente->cidade,sizeof(novoCliente->cidade),stdin);
        strtok(novoCliente->cidade, "\n");
        for(x=0;x<25;x++)
        {
            gotoxy(x+9,15);
            printf("%c",BLACK);
        }
        printfNovo("Estado:",15);
        fgets(novoCliente->estado,sizeof(novoCliente->estado),stdin);
        strtok(novoCliente->estado, "\n");
        if(inicioCli==NULL){
            inicioCli = novoCliente;
            codCliente = 1;
        }else{
            while(aux->proximo!=NULL){
                aux=aux->proximo;
            }
            aux->proximo = novoCliente;
            codCliente++;
        }
        printfNovo("Deseja continuar cadastrando?(s/n)",18);
        scanf(" %c", &op);
        op = tolower(op);
    }while (op!='n');
}

//Pesquisar Cliente 5.2
void pesquisarCliente()
{
    int count=0, opc, x=7;
    char op;
    Cliente *aux = inicioCli;
    do
    {
        clrscr();
        moldura();
        printfCenter("Pesquisa de cliente",1);
        gotoxy(2,3);
        printf("Digite [de 1 ate %d] para pesquisar o Cliente: ", codCliente);
        scanf("%d", &opc);
        if(opc>0 && opc <= codCliente){
            if(opc==1){
            gotoxy(2,6);
            printf("Cod  Nome\t  Telefone\tRua\t\tNumero\t\tBairro");
            gotoxy(2,x);
            printf("%d", count+1);
            gotoxy(7,x);
            printf("%s",aux->nome);
            gotoxy(18,x);
            printf("%s",aux->telefone);
            gotoxy(32,x);
            printf("%s",aux->rua);
            gotoxy(48,x);
            printf("%s",aux->numero);
            gotoxy(64,x);
            printf("%s",aux->bairro);
            }else{
                Cliente *atual = inicioCli;
                opc--;
                for(count=0;count<opc;count++){
                    atual=atual->proximo;
                }
                gotoxy(2,6);
                printf("Cod  Nome\t  Telefone\tRua\t\tNumero\t\tBairro");
                gotoxy(2,x);
                printf("%d", count+1);
                gotoxy(7,x);
                printf("%s",atual->nome);
                gotoxy(18,x);
                printf("%s",atual->telefone);
                gotoxy(32,x);
                printf("%s",atual->rua);
                gotoxy(48,x);
                printf("%s",atual->numero);
                gotoxy(64,x);
                printf("%s",atual->bairro);
            }
    }
        gotoxy(2,22);
        system("PAUSE");
        printfCenter("Deseja continuar pesquisando?(s/n)", 18);
        scanf(" %c", &op);
        op = tolower(op);
    }while (op!='n');
}

//listar Cliente 5.3
void listarCliente()
{
    int count=0,y=3,x=3;
    clrscr();
    moldura();
    Cliente *aux = inicioCli;
    printfCenter("Listagem de clientes",1);
    while(aux != NULL){
        gotoxy(4,x);
        printf("%s",aux->nome);
        gotoxy(15,x);
        printf("%s",aux->telefone);
        gotoxy(25,x);
        printf("%s",aux->rua);
        gotoxy(40,x);
        printf("%s",aux->numero);
        gotoxy(45,x);
        printf("%s",aux->bairro);
        x++;
        aux=aux->proximo;
    }
    for(count=0 ; count < codCliente ; count++){
        gotoxy(2,y);
        printf("%d", count+1);
        y++;
    }
    gotoxy(2,22);
    system("PAUSE");
    clrscr();
}

//Excluir Cliente 5.4
void removerCliente()
{
    //Cliente *remover = inicioCli;
    int op, x;
    moldura();
    printfCenter("Removendo cliente", 1);
    gotoxy(2,3);
    printf("Digite [de 1 ate %d] do cliente que  deseja retirar: ", codCliente);
    scanf("%d", &op);
    if(op>0 && op <= codCliente){
        if(op==1){
            Cliente *aux= inicioCli;
            inicioCli = aux->proximo;
            codCliente--;
        }else{
            Cliente *atual = inicioCli, *anterior=inicioCli;
            for(x=1;x<op;x++){
                anterior=atual;
                atual=atual->proximo;
            }
            anterior->proximo=atual->proximo;
            codCliente--;
        }
    }else{
        printf("codigo de cliente invalido");
        }
        if(inicioCli==NULL){
            printfCenter("Lista esta vazia", 5);
            gotoxy(2,22);
            system("PAUSE");
            clrscr();
        }
}

//FIM DO MENU CLIENTE;

//Menu 6 gerencial
void gerencial()
{
    int op;
    do{
        clrscr();
        moldura();
        printfCenter("Menu gerencial",1);
        gotoxy(2,3);
        printf("0 - voltar ao menu principal");
        gotoxy(2,4);
        printf("1 - Estoque");
        gotoxy(2,5);
        printf("2 - Relatorio");
        gotoxy(2,6);
        printf("Digite a opcao: %c", BLACK);
        gotoxy(18,6);
        scanf("%d", &op);
        switch(op)
        {
            case 0: clrscr();
                break;
            case 1: estoque();
                break;
            case 2: relatorio();
                break;
            default: printfCenter("Opcao invalida", 12);
                break;
        }
    }while(op!=0);
}


//Menu Estoque 5.1
void estoque()
{
    clrscr();
    moldura();
    printfCenter("Estoque",1);
    system("C:\\PIM\\estoque.xlsm");

}

//Abre Relatorio 5.2;
void relatorio()
{
    clrscr();
    moldura();
    printfCenter("Relatorios",1);
    system("C:\\PIM\\gerencial.xlsm");

}

//FIM DO MENU GERENCIAL;

//MENU 7 Elogios e reclamçoes;
void elogiosReclamacoes()
{
    int op;
    do{
        clrscr();
        moldura();
        printfCenter("Menu Elogio e Reclamacoes",1);
        gotoxy(2,3);
        printf("0 - voltar ao menu principal");
        gotoxy(2,4);
        printf("1 - Cadastrar Elogio");
        gotoxy(2,5);
        printf("2 - Cadastrar Reclamcao");
        gotoxy(2,6);
        printf("3 - Listar Elogios");
        gotoxy(2,7);
        printf("4 - Listar Reclamacoes");
        gotoxy(2,8);
        printf("Digite a opcao: %c", BLACK);
        gotoxy(18,8);
        scanf("%d", &op);
        switch(op)
        {
            case 0: clrscr();
                break;
            case 1:
                clrscr();
                cadastarElo();
                break;
            case 2:
                clrscr();
                cadastarRec();
                break;
            case 3:
                clrscr();
                listarElo();
                break;
            case 4:
                clrscr();
                listarRec();
                break;
            default: printf("\n\t\t\tOpcao invalida\n");
                break;
        }
    }while(op!=0);
}
//Novo Elogio 7.1;
void cadastarElo()
{
    clrscr();
    moldura();
    Elogio *aux = inicioElo;
    Elogio *novoElo = (Elogio*) malloc(sizeof(Elogio));
    novoElo->proximo=NULL;
    getchar();
    gotoxy(2,1);
    printf("Descreva para nos sua experiencia positiva: ");
    gotoxy(2,3);
    fgets(novoElo->elogi,200,stdin);
    strtok(novoElo->elogi, "\n");

    if(inicioElo==NULL){
        inicioElo=novoElo;
    }else{
         while(aux->proximo!=NULL){
            aux=aux->proximo;
         }
         aux->proximo=novoElo;
    }
}

//Nova Reclamção 7.2;
void cadastarRec()
{
    clrscr();
    moldura();
    Rec *aux = inicioRec;
    Rec *novoRec = (Rec*) malloc(sizeof(Rec));
    novoRec->proximo=NULL;
    getchar();
    gotoxy(2,1);
    printf("Descreva para nos sua experiencia negativa: ");
    gotoxy(2,3);
    fgets(novoRec->reclamacao,200,stdin);
    strtok(novoRec->reclamacao, "\n");
    if(inicioRec==NULL){
        inicioRec=novoRec;
    }else{
         while(aux->proximo!=NULL){
            aux=aux->proximo;
         }
         aux->proximo=novoRec;
    }
}

//Listar Elogios 7.3;
void listarElo()
{
    int x=3;
    clrscr();
    moldura();
    Elogio *aux=inicioElo;
    printfCenter("todos os elogios: ",1);
        while(aux!=NULL){
        gotoxy(4,x);
        printf("%s", aux->elogi);
        x++;
        aux=aux->proximo;
    }
    gotoxy(2,22);
    system("PAUSE");
    clrscr();
}
//Listar Reclamações 7.4;
void listarRec()
{
    int x=3;
    clrscr();
    moldura();
    Rec *aux=inicioRec;
    printfCenter("todos os elogios: ",1);
    while(aux!=NULL){
        gotoxy(4,x);
        printf("%s", aux->reclamacao);
        x++;
        aux=aux->proximo;
    }
    gotoxy(2,22);
    system("PAUSE");
    clrscr();
}
//FIM Do MENU Elogios e Reclamações

//Menu 8 de funcionario
void funcionarios()
{
    clrscr();
    int op;
    do{
        clrscr();
        moldura();
        printfCenter("Menu Funcionarios", 1);
        printfNovo("0 - voltar ao menu principal",3);
        printfNovo("1 - Cadastro de Funcionarios",4);
        printfNovo("2 - Listar Funcionarios",5);
        printfNovo("3 - Excluir Funcionarios",6);
        gotoxy(2,7);
        printf("Digite a opcao: %c",BLACK);
        gotoxy(18,7);
        scanf("%d", &op);
        switch(op)
        {
            case 0: clrscr();
                break;
            case 1:
                clrscr();
                cadastraFunc();
                break;
            case 2:
                clrscr();
                listarFunc();
                break;
            case 3:
                clrscr();
                excluirFunc();
                break;
            default: printf("\n\t\t\tOpcao invalida");
                break;
        }
    }while(op!=0);
}

//Cadastro de Funcionario 8.1
void cadastraFunc()
{
    char op;
    int x=0;
    printfCenter("Cadastro de Funcionario\n",1);
    funcionario *aux;
    do{
        clrscr();
        moldura();
        funcionario *novofunc = (funcionario*)malloc(sizeof(funcionario));
        novofunc->proximo=NULL;
        aux = iniciofun;
        for(x=0;x<10;x++){
            gotoxy(x+8,3);
            printf("%c", BLACK);
        }
        getchar();
        printfNovo("Nome: ",3);
        fgets(novofunc->nomefun,sizeof(novofunc->nomefun),stdin);
        strtok(novofunc->nomefun, "\n");
        for(x=0;x<15;x++){
            gotoxy(x+16,5);
            printf("%c", BLACK);
        }
        printfNovo("Cargo/Funcao: ",5);
        fgets(novofunc->cargo,sizeof(novofunc->cargo),stdin);
        strtok(novofunc->cargo, "\n");
            if(iniciofun==NULL){
                iniciofun = novofunc;
                codFuncionario = 0;
            }else{
                while(aux->proximo!=NULL){
                    aux=aux->proximo;
                }
                aux->proximo = novofunc;
            }
            codFuncionario++;
        printfNovo("deseja cadastrar mais algum funcionario?: (s/n)",18);
        scanf(" %c", &op);
    }while(op!='n');
}

//Listagem de Funcionario 8.2
void listarFunc()
{
    int x=5, y=1;
    clrscr();
    moldura();
    printfCenter("Lista de funcionarios",1);
    printfNovo("Cod  Nome\t\t\tFuncao",3);
    funcionario *aux=iniciofun;
        while(aux!=NULL){
        gotoxy(2,x);
        printf("%d", y);
        gotoxy(7,x);
        printf("%s", aux->nomefun);
        gotoxy(32,x);
        printf("%s", aux->cargo);
        x++;
        y++;
        aux=aux->proximo;
    }
    gotoxy(2,22);
    system("PAUSE");
    clrscr();
}


//Excluir Funcionario 8.3
void excluirFunc()
{
    clrscr();
    moldura();
    printfCenter("Removendo Funcionario", 1);
    int opt,x;
    gotoxy(2,3);
    printf("Digite [de 1 ate %d] do funcionario que  deseja retirar: ", codFuncionario);
    scanf("%d", &opt);
    if(opt>0 && opt <= codFuncionario){
        if(opt==1){
            funcionario *aux = iniciofun;
            iniciofun = aux->proximo;
            codFuncionario--;
            }else{
                funcionario *atual = iniciofun, *anterior=iniciofun;
                for(x=1 ; x < opt ; x++){
                    anterior=atual;
                    atual=atual->proximo;
                }
            anterior->proximo=atual->proximo;
            codFuncionario--;
            }
    }else{
        gotoxy(2,10);
        printf("Elemento invalido\n\n");
        gotoxy(2,22);
        system("PAUSE");
    }
    clrscr();
}

//Leitura de arquivos
void ler(){
    //Leitura struct Cliente;
    Cliente *cliente;
    FILE *arqCliente = fopen(arquivoCliente,"r+b");

    if (arqCliente == NULL)
    {
        printf("Erro ao abrir arquivo\n");
        return;
    }

    while (!feof(arqCliente))
    {
        cliente  = (Cliente*) malloc(sizeof(Cliente));
        int qtd = fread(cliente,sizeof(Cliente),1,arqCliente);
        if(qtd > 0){
            if(inicioCli == NULL){
                inicioCli = cliente;
                cliente->proximo = NULL;
                codCliente=1;
            }
            else{
                Cliente *aux = inicioCli;
                cliente->proximo = aux;
                inicioCli = cliente;
                codCliente++;
            }
        }
    }
    //Leitura struct Sabores
    Sabores *sabores;
    FILE *arqPizza = fopen(arquivoPizza,"r+b");
    if (arqPizza == NULL)
    {
        printf("Erro ao abrir arquivo\n");
        return;
    }
    while (!feof(arqPizza)){

        sabores  = (Sabores*) malloc(sizeof(Sabores));
        int qtdPizza = fread(sabores,sizeof(Sabores),1,arqPizza);
        if(qtdPizza > 0){
            if(inicioPizza == NULL){
                inicioPizza = sabores;
                sabores->proximo = NULL;
                codSabor=1;
            }
            else{
                Sabores *auxPizz = inicioPizza;
                sabores->proximo = auxPizz;
                inicioPizza = sabores;
                codSabor++;
            }
        }
    }

    //Leitura struct Bebidas;
    Bebida *bebida;
    FILE *arqBebidas = fopen(arquivoBebidas,"r+b");
    if (arqBebidas == NULL)
    {
        printf("Erro ao abrir arquivo\n");
        return;
    }
    while (!feof(arqBebidas)){

        bebida  = (Bebida*) malloc(sizeof(Bebida));
        int qtdBebidas = fread(bebida,sizeof(Bebida),1,arqBebidas);
        if(qtdBebidas > 0){
            if(inicioBebida == NULL){
                inicioBebida = bebida;
                bebida->proximo = NULL;
                codBebida=1;
            }
            else{
                Bebida *aux = inicioBebida;
                bebida->proximo = aux;
                inicioBebida = bebida;
                codBebida++;
            }
        }
    }

    //leitura de funcionario
    funcionario *funci;
    FILE *arqFuncionario = fopen(arquivoFuncionario,"r+b");
    if (arqFuncionario == NULL)
    {
        printf("Erro ao abrir arquivo\n");
        return;
    }
    while (!feof(arqFuncionario)){
        funci  = (funcionario*) malloc(sizeof(funcionario));
        int qtdfunciorios = fread(funci,sizeof(funcionario),1,arqFuncionario);
        if(qtdfunciorios > 0){
            if(iniciofun == NULL){
                iniciofun = funci;
                funci->proximo = NULL;
                codFuncionario=1;
            }
            else{
                funcionario *aux = iniciofun;
                funci->proximo = aux;
                iniciofun = funci;
                codFuncionario++;
            }
        }
    }

    //leitura de elogio
    Elogio *elogio;
    FILE *arqElogio = fopen(arquivoElogio,"r+b");
    if (arqElogio == NULL)
    {
        printf("Erro ao abrir arquivo\n");
        return;
    }
    while (!feof(arqElogio)){
        elogio  = (Elogio*) malloc(sizeof(Elogio));
        int qtdElogios = fread(elogio,sizeof(Elogio),1,arqElogio);
        if(qtdElogios > 0){
            if(inicioElo == NULL){
                inicioElo = elogio;
                elogio->proximo = NULL;
            }
            else{
                Elogio *aux = inicioElo;
                elogio->proximo = aux;
                inicioElo = elogio;
            }
        }
    }

    //leitura da Reclamação

    Rec *rec;
    FILE *arqReclamacao = fopen(arquivoReclamacao,"r+b");
    if (arqReclamacao == NULL)
    {
        printf("Erro ao abrir arquivo\n");
        return;
    }
    while (!feof(arqReclamacao)){
        rec  = (Rec*) malloc(sizeof(Rec));
        int qtdReclamacao = fread(rec,sizeof(Rec),1,arqReclamacao);
        if(qtdReclamacao > 0){
            if(inicioRec == NULL){
                inicioRec = rec;
                rec->proximo = NULL;
            }
            else{
                Rec *aux = inicioRec;
                rec->proximo = aux;
                inicioRec = rec;
            }
        }
    }

    //leitura da Promocao
    Promocao *promocao;
    FILE *arqPromocao = fopen(arquivoPromocao,"r+b");
    if (arqPromocao == NULL)
    {
        printf("Erro ao abrir arquivo\n");
        return;
    }
    while (!feof(arqPromocao)){
        promocao  = (Promocao*) malloc(sizeof(Promocao));
        int qtdPromocao = fread(promocao,sizeof(Promocao),1,arqPromocao);
        if(qtdPromocao > 0){
            if(inicioPro == NULL){
                inicioPro = promocao;
                promocao->proximo = NULL;
                codPromocoes = 1;
            }
            else{
                Promocao *aux = inicioPro;
                promocao->proximo = aux;
                inicioPro = promocao;
                codPromocoes++;
            }
        }
    }
    //leitura de pedidos
    /*Pedido *pedido;
    FILE *arqPedido = fopen(arquivoPedido,"r+b");
    if (arqPedido == NULL)
    {
        printf("Erro ao abrir arquivo\n");
        return;
    }
    while (!feof(arqPedido)){

        pedido  = (Pedido*) malloc(sizeof(Pedido));
        int qtdPedido = fread(pedido,sizeof(Pedido),1,arqPedido);
        if(qtdPedido > 0){
            if(inicioPedido == NULL){
                inicioPedido = pedido;
                pedido->proximo = NULL;
                codPedido=1;
            }
            else{
                Pedido *auxPedido = inicioPedido;
                pedido->proximo = auxPedido;
                inicioPedido = pedido;
                codPedido++;
            }
        }
    }*/
    fclose(arqBebidas);
    fclose(arqCliente);
    fclose(arqPizza);
    fclose(arqFuncionario);
    fclose(arqElogio);
    fclose(arqReclamacao);
    fclose(arqPromocao);
    //fclose(arqPedido);
}

//Gravar arquivos;
void gravar()
{
    if(inicioCli != NULL){
        Cliente *aux = inicioCli;
        FILE *arqCliente = fopen(arquivoCliente,"wb");
        if (arqCliente == NULL)
        {
            printf("Erro ao abrir arquivo\n");
            exit(1);
        }
        while (aux != NULL){
            //printf("\n-> %s, %s", aux->nome, aux->fone);
            fwrite(aux,sizeof(Cliente),1,arqCliente);
            aux = aux->proximo;
        }
        fclose(arqCliente);
    }

    if(inicioPizza != NULL){
        Sabores *auxPizza = inicioPizza;
        FILE *arqPizza = fopen(arquivoPizza,"wb");
        if (arqPizza == NULL)
        {
            printf("Erro ao abrir arquivo\n");
            exit(1);
        }
        while (auxPizza != NULL){

            fwrite(auxPizza,sizeof(Sabores),1,arqPizza);
            auxPizza = auxPizza->proximo;
        }
        fclose(arqPizza);
    }

    if(inicioBebida != NULL){
        Bebida *auxBebida = inicioBebida;
        FILE *arqBebidas = fopen(arquivoBebidas,"wb");
        if (arqBebidas == NULL)
        {
            printf("Erro ao abrir arquivo\n");
            exit(1);
        }
        while (auxBebida != NULL){

            fwrite(auxBebida,sizeof(Bebida),1,arqBebidas);
            auxBebida = auxBebida->proximo;
        }
        fclose(arqBebidas);
    }

    //funcionario
    if(iniciofun != NULL){
        funcionario *auxFuncionario = iniciofun;
        FILE *arqFuncionario = fopen(arquivoFuncionario,"wb");
        if (arqFuncionario == NULL)
        {
            printf("Erro ao abrir arquivo\n");
            exit(1);
        }
        while (auxFuncionario != NULL){

            fwrite(auxFuncionario,sizeof(Bebida),1,arqFuncionario);
            auxFuncionario = auxFuncionario->proximo;
        }
        fclose(arqFuncionario);
    }

    if(inicioElo != NULL){
        Elogio *auxElogio = inicioElo;
        FILE *arqElogio = fopen(arquivoElogio,"wb");
        if (arqElogio == NULL)
        {
            printf("Erro ao abrir arquivo\n");
            exit(1);
        }
        while (auxElogio != NULL){

            fwrite(auxElogio,sizeof(Elogio),1,arqElogio);
            auxElogio = auxElogio->proximo;
        }
        fclose(arqElogio);
    }

    if(inicioRec != NULL){
        Rec *auxRec = inicioRec;
        FILE *arqReclamacao = fopen(arquivoReclamacao,"wb");
        if (arqReclamacao == NULL)
        {
            printf("Erro ao abrir arquivo\n");
            exit(1);
        }
        while (auxRec != NULL){

            fwrite(auxRec,sizeof(Rec),1,arqReclamacao);
            auxRec = auxRec->proximo;
        }
        fclose(arqReclamacao);
    }

    if(inicioPro != NULL){
        Promocao *auxPromocao = inicioPro;
        FILE *arqPromocao = fopen(arquivoPromocao,"wb");
        if (arqPromocao == NULL)
        {
            printf("Erro ao abrir arquivo\n");
            exit(1);
        }
        while (auxPromocao != NULL){
            fwrite(auxPromocao,sizeof(Promocao),1,arqPromocao);
            auxPromocao = auxPromocao->proximo;
        }
        fclose(arqPromocao);
    }
/*
    if(inicioPedido != NULL){
        Pedido *auxPedido = inicioPedido;
        FILE *arqPedido = fopen(arquivoPedido,"wb");
        if (arqPedido == NULL)
        {
            printf("Erro ao abrir arquivo\n");
            exit(1);
        }
        while (auxPedido != NULL){
            fwrite(auxPedido,sizeof(Pedido),1,arqPedido);
            auxPedido = auxPedido->proximo;
        }
        fclose(arqPedido);
    }*/

    if(inicioPedido != NULL){
        Pedido *auxPedTeste = inicioPedido;
        FILE *arqPedidoTeste = fopen(arquivoPedTexto,"a");
        if (arqPedidoTeste == NULL)
        {
            printf("Erro ao abrir arquivo\n");
            exit(1);
        }
        int x=1;
        fprintf(arqPedidoTeste,"cod;");
        fprintf(arqPedidoTeste,"Cliente/Mesa;");
        fprintf(arqPedidoTeste,"Pizza/Promocao;");
        fprintf(arqPedidoTeste,"Bebida;");
        fprintf(arqPedidoTeste,"Total;\n");
        while (auxPedTeste != NULL){
            fprintf(arqPedidoTeste,"%d;",x);
            fprintf(arqPedidoTeste,"%s;",auxPedTeste->nomeCliente);
            fprintf(arqPedidoTeste,"%s;",auxPedTeste->saborPizza);
            fprintf(arqPedidoTeste,"%s;",auxPedTeste->saborBebida);
            fprintf(arqPedidoTeste,"%0.2f;\n",auxPedTeste->total);
            auxPedTeste = auxPedTeste->proximo;
            x++;
        }
        fclose(arqPedidoTeste);
    }

    if(inicioPizza != NULL){
        Sabores *auxPizzaTexto = inicioPizza;
        FILE *arqPizzaTexto = fopen(arquivoPizzaTexto,"w");
        if (arqPizzaTexto == NULL)
        {
            printf("Erro ao abrir arquivo\n");
            exit(1);
        }
        int x=1;
        fprintf(arqPizzaTexto,"cod;");
        fprintf(arqPizzaTexto,"sabor;");
        fprintf(arqPizzaTexto,"Ingredientes;");
        fprintf(arqPizzaTexto,"custo;");
        fprintf(arqPizzaTexto,"preco venda;\n");
        while (auxPizzaTexto != NULL){
            fprintf(arqPizzaTexto,"%d;",x);
            fprintf(arqPizzaTexto,"%s;",auxPizzaTexto->sabor);
            fprintf(arqPizzaTexto,"%s;",auxPizzaTexto->ingred);
            fprintf(arqPizzaTexto,"%0.2f;",auxPizzaTexto->custo);
            fprintf(arqPizzaTexto,"%0.2f;\n",auxPizzaTexto->preco);
            auxPizzaTexto = auxPizzaTexto->proximo;
            x++;
        }
        fclose(arqPizzaTexto);
    }
    //salva bebida txt
        if(inicioBebida != NULL){
        Bebida *auxBebidaTexto = inicioBebida;
        FILE *arqBebidaTexto = fopen(arquivoBebidaTexto,"w");
        if (arqBebidaTexto == NULL)
        {
            printf("Erro ao abrir arquivo\n");
            exit(1);
        }
        int x=1;
        fprintf(arqBebidaTexto,"cod;");
        fprintf(arqBebidaTexto,"Bebida;");
        fprintf(arqBebidaTexto,"custo;");
        fprintf(arqBebidaTexto,"preco venda;\n");
        while (auxBebidaTexto != NULL){
            fprintf(arqBebidaTexto,"%d;",x);
            fprintf(arqBebidaTexto,"%s;",auxBebidaTexto->saborBebida);
            fprintf(arqBebidaTexto,"%0.2f;",auxBebidaTexto->custo);
            fprintf(arqBebidaTexto,"%0.2f;\n",auxBebidaTexto->preco);
            auxBebidaTexto = auxBebidaTexto->proximo;
            x++;
        }
        fclose(arqBebidaTexto);
    }
    //Salva promocao txt
    if(inicioPro != NULL){
        Promocao *auxPromoTexto = inicioPro;
        FILE *arqPromoTexto = fopen(arquivoPromocaoTexto,"w");
        if (arqPromoTexto == NULL)
        {
            printf("Erro ao abrir arquivo\n");
            exit(1);
        }
        int x=1;
        fprintf(arqPromoTexto,"cod;");
        fprintf(arqPromoTexto,"Promocao;");
        fprintf(arqPromoTexto,"custo;");
        fprintf(arqPromoTexto,"preco venda;\n");
        while (auxPromoTexto != NULL){
            fprintf(arqPromoTexto,"%d;",x);
            fprintf(arqPromoTexto,"%s;",auxPromoTexto->nomePromo);
            fprintf(arqPromoTexto,"%0.2f;",auxPromoTexto->custo);
            fprintf(arqPromoTexto,"%0.2f;\n",auxPromoTexto->preco);
            auxPromoTexto = auxPromoTexto->proximo;
            x++;
        }
        fclose(arqPromoTexto);
    }
}
