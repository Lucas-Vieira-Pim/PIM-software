#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED

int menu();
void ler();
void gravar();

//1-menu pedidos
void pedidos();
void novoPedido();
void pedidoCliente();
void pedidoMesa();
void pedidoBalcao();
void pedidoPromo();
void excluirPedido();
void listarPedido();

//2-menu de pizzas
void pizzas();
void cadastrarPizza();
void listarPizza();
void alteraPizza();
void excluirPizza();

//3 Menu bebidas
void bebidas();
void cadastroBebida();
void listarBebida();
void alterarBebida();
void excluirBebida();

//4-menu promocoes
void promocoes();
void cadastrarPromo();
void listarPromo();
void excluirPromo();

//5-clientes
void menucliente();
void cadastroCliente();
void removerCliente();
void pesquisarCliente();
void listarCliente();

//6- Menu gerencial
void gerencial();
void estoque();
void relatorio();

//7-elogios e rec
void elogiosReclamacoes();
void cadastarElo();
void cadastarRec();
void listarElo();
void listarRec();

//8-Funcionarios//3-clientes
void menucliente();
void cadastroCliente();
void removerCliente();
void pesquisarCliente();
void listarCliente();
void funcionarios();
void cadastraFunc();
void excluirFunc();
void listarFunc();


#endif // MENUS_H_INCLUDED
