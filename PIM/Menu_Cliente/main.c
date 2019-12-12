#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include "design.h"
float fechamento = 0;
char *fechaBebida;
char *fechaPizza;
char *mesa;
const char BLACK = 219;
char *arquivoPizza = "C:\\PIM\\pizzas.bin";
char *arquivoBebidas = "C:\\PIM\\bebidas.bin";
char *arquivoReclamacao = "C:\\PIM\\reclamacao.bin";
char *arquivoElogio = "C:\\PIM\\elogio.bin";
char *arquivoPromocao = "C:\\PIM\\promocao.bin";
//char *arquivoPedido = "C:\\Users\\André Rossner\\OneDrive\\Documentos\\PIM\\pedidos.bin";
char *arquivoPedTexto = "C:\\PIM\\pedidostexto.txt";

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

void ler();
void gravar();
void pedidoNovo();
void fechaConta();
void reclamacao();
void elogios();
void sair();

void main(){
    ler();
    pintar(124);
    clrscr();
    int op;
    do{
        moldura();
        printfCenter("BEM-VINDO AO SYSTEM PIZZAS",1);
        printfNovo("1 - Fazer Pedido ",3);
        printfNovo("2 - Fechar Conta",4);
        printfNovo("3 - Elogio",5);
        printfNovo("4 - Reclamacao",6);
        printfNovo("5 - Fechar Programa",7);
        printfNovo("Escolha uma opcao: ",8);
        scanf("%d", &op);

        switch (op) {
            case 1: clrscr();
                pedidoNovo();
            break;

            case 2: clrscr();
                 fechaConta();
            break;

            case 3: clrscr();
                elogios();
            break;

            case 4: clrscr();
                reclamacao();
            break;

            case 5: clrscr();
                sair();
                return 0;
            break;

            default:
                gotoxy(10,15);
                printf("Opcao invalida ");
                clrscr();
            break;
        }
    }while(op!=5);
    return 0;
}

void pedidoNovo(){
    int count=0, x=6, opc, opcSabor, opcBebida;
    float precoPizza=0, precoBebida=0, total;
    char confirmaCliente, confirmaSabor, confirmaBebida, promo, entraBebida, *codMesa = malloc(10);
    Pedido *novoPe = (Pedido*) malloc(sizeof(Pedido));
    novoPe->proximo=NULL;
    Pedido *auxPedido = inicioPedido;
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
        mesa = codMesa;
        strtok(novoPe->nomeCliente, "\n");
        gotoxy(2,18);

        clrscr();
        moldura();
        printfCenter("NOVO PEDIDO",1);
        //Lista Promoção
        int z=4, y=1;
        Promocao *auxPro=inicioPro;
        printfCenter("Lista de Promocoes",1);
        printfNovo("Cod  Promocao\t\t\t\t\t\t\t\tPreco",3);
        while(auxPro != NULL){
        gotoxy(2,z);
        printf("%d",y);
        gotoxy(7,z);
        printf("%s",auxPro->nomePromo);
        gotoxy(72,z);
        printf("%0.2f",auxPro->preco);
        z++;
        y++;
        auxPro=auxPro->proximo;
        }
        gotoxy(2,21);
        printf("Promocao?(s/n)");
        scanf(" %c", &promo);
    if(promo!='s'){
        //listar pizza
        int x=5, y=1;
        clrscr();
        moldura();
        Sabores *auxSab=inicioPizza;
    printfCenter("Lista de sabores",1);
    gotoxy(2,3);
    printf("Cod  Sabor\t      Ingredientes\t\t\t\t\t Preco");
    while(auxSab != NULL){
        gotoxy(2,x);
        printf("%d",y);
        gotoxy(7,x);
        printf("%s",auxSab->sabor);
        gotoxy(22,x);
        printf("%s",auxSab->ingred);
        gotoxy(73,x);
        printf("%0.2f",auxSab->preco);
        x++;
        y++;
        auxSab=auxSab->proximo;
    }
        //Chama pizza
        do{
            gotoxy(2,21);
            printf("Digite o codigo da pizza [de 1 ate %d]: ", codSabor);
            scanf("%d", &opcSabor);
            clrscr();
            moldura();
            printfCenter("NOVO PEDIDO",1);
            gotoxy(2,3);
            printf("Cod  Sabor\t  Ingredientes\t\t\t\t\t\tPreco");
            x=4;
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
                    fechaPizza=novoPe->saborPizza;

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
                    fechaPizza=novoPe->saborPizza;
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
            //lista Bebida
            Bebida *aux = inicioBebida;
        x=4;
        y=1;
        clrscr();
        moldura();
        printfCenter("Lista de Bebidas",1);
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
            do{
                gotoxy(2,21);
                printf("Digite o codigo da Bebida [de 1 ate %d]: ", codBebida);
                scanf("%d", &opcBebida);
                clrscr();
                moldura();
                printfCenter("NOVO PEDIDO",1);
                gotoxy(2,3);
                printf("Cod  Bebida\t\t\t\t\t\t\t\tPreco");
                x=4;
                count=0;
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
                        fechaBebida=novoPe->saborBebida;
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
                        fechaBebida=novoPe->saborBebida;
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
        fechaBebida=novoPe->saborBebida;
        strtok(novoPe->saborBebida, "\n");
        }
            total = precoBebida+precoPizza;
            novoPe->total = total;
            fechamento = total;

    }else{
    //Chama promocao
        promocao();
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
    clrscr();
}

void promocao(){

    int count=0, x=6, opc, opcSabor, opcBebida;
    float precoPizza=0, precoBebida=0, total;
    char confirmaCliente, confirmaSabor, confirmaBebida, promo, entraBebida, *codMesa = malloc(10);
    Pedido *novoPe = (Pedido*) malloc(sizeof(Pedido));
    novoPe->proximo=NULL;
    Pedido *auxPedido = inicioPedido;
    Sabores *auxPizza = inicioPizza;
    Bebida *auxBebida = inicioBebida;
    Promocao *auxPromocao = inicioPro;

     do{
        novoPe->saborBebida = "-";
        fechaBebida=novoPe->saborBebida;
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
                    fechaBebida=novoPe->saborPizza;
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
                    fechaBebida=novoPe->saborPizza;
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

void fechaConta(){
    Pedido *conta = (Pedido*)malloc(sizeof(Pedido));
    Pedido *aux;
    aux=inicioPedido;
    clrscr();
    moldura();
    printfCenter("Fechamento",1);
    gotoxy(2,3);
    printf("Mesa: %s\n", mesa);
    gotoxy(2,4);
    printf("Pizza: %s\n", fechaPizza);
    gotoxy(2,5);
    printf("Bebida: %s\n", fechaBebida);
    gotoxy(2,6);
    printf("O total a pagar eh: %0.2f\n", fechamento);
    gotoxy(10,15);
    system("PAUSE");
    clrscr();
}

void elogios(){
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

void reclamacao(){
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

void sair(){
    gravar();
    clrscr();
    moldura();
    printfCenter("Obrigado e voltem sempre",10);
    return 0;
}

//Leitura de arquivos
void ler(){
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
    fclose(arqBebidas);
    fclose(arqPizza);
    fclose(arqElogio);
    fclose(arqReclamacao);
    fclose(arqPromocao);
}

//Gravar arquivos;
void gravar()
{
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
    if(inicioPedido != NULL){
        Pedido *auxPedTexto = inicioPedido;
        FILE *arqPedidoTexto = fopen(arquivoPedTexto,"a");
        if (arqPedidoTexto == NULL)
        {
            printf("Erro ao abrir arquivo\n");
            exit(1);
        }
        int x=1;
            fprintf(arqPedidoTexto,"Cod;");
            fprintf(arqPedidoTexto,"Cliente/Mesa;");
            fprintf(arqPedidoTexto,"Pizza/Promocao;");
            fprintf(arqPedidoTexto,"Bebida;");
            fprintf(arqPedidoTexto,"total;");
        while (auxPedTexto != NULL){
            fprintf(arqPedidoTexto,"%d;",x);
            fprintf(arqPedidoTexto,"%s;",auxPedTexto->nomeCliente);
            fprintf(arqPedidoTexto,"%s;",auxPedTexto->saborPizza);
            fprintf(arqPedidoTexto,"%s;",auxPedTexto->saborBebida);
            fprintf(arqPedidoTexto,"%0.2f;\n",auxPedTexto->total);
            auxPedTexto = auxPedTexto->proximo;
            x++;
        }
        fclose(arqPedidoTexto);
    }
}
