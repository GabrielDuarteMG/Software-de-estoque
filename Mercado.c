/*
        Trabalho primeiro periodo ADS-UNIPAC Uberlandia
        Professor:Diego Alves da Silva
        Alunos: Daniel, Arthur, Gabriel, Igor, Marcos e Allysom
        O trabalho consiste em implementar um software de estoque para uma empresa.
        O software possui:
            .Cadastro de Produto;
            .Alterar quantidade de produtos;
            .Listar produtos;
            .Buscar um produto por código de barras;
            .Os produtos possuem:
                -Descrição;
                -Código de barras;
                -Quantidade disponível;
                -Preço compra;
                -Preço de venda;
            .Controle de Caixa;
*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define QuantMax 200
int produtosCadastrados = 0;
int produtosEstoque[QuantMax];
int produtosCaixa[QuantMax];
int ContCaixa = 0;
void MenuDeEstoque();
void MenuDeCaixa();
void Quitar(int x);
void Limpar() {
  printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}
bool VerificarProduto(int val, int * arr, int Tamanho) {
  int i;
  for (i = 0; i < Tamanho; i++) {
    if (arr[i] == val)
      return true;
  }
  return false;
}
float Dinheiro = 22200.20;
struct produto {
  char nome[50];
  char descricao[144];
  int quantidade;
  float pcompra;
  float pvenda;
  int CodigoDeBarra;
};
struct produto Estoque[QuantMax];
struct produto EstoqueCaixa[QuantMax];
void main() {
  Limpar();
  int x;
  for (x = 0; x != QuantMax; x++) {
    strcpy(Estoque[x].nome, "Null");
    strcpy(Estoque[x].descricao, "Null");
    Estoque[x].quantidade = 0;
    Estoque[x].pcompra = 0;
    Estoque[x].pvenda = 0;
    Estoque[x].CodigoDeBarra = 0;
  }
  strcpy(Estoque[produtosCadastrados].nome, "Macarrao");
  strcpy(Estoque[produtosCadastrados].descricao, "Macarrao santa malha");
  Estoque[produtosCadastrados].quantidade = 500;
  Estoque[produtosCadastrados].pcompra = 2.90;
  Estoque[produtosCadastrados].pvenda = 4.35;
  Estoque[produtosCadastrados].CodigoDeBarra = 1;
  produtosEstoque[produtosCadastrados] = 1;
  produtosCadastrados++;

  for (x = 0; x != QuantMax; x++) {
    strcpy(EstoqueCaixa[x].nome, "Null");
    strcpy(EstoqueCaixa[x].descricao, "Null");
    EstoqueCaixa[x].quantidade = 0;
    EstoqueCaixa[x].pcompra = 0;
    EstoqueCaixa[x].pvenda = 0;
    EstoqueCaixa[x].CodigoDeBarra = 0;
  }
  MenuDeEstoque();
}
void Cadastrar() {
  char NomeDoProd[50];
  char DescricaoDoProd[144];
  long CodigoDeBarra;
  printf("           CADASTRO DE PRODUTOS");
  printf("\nDigite  o nome do produto: ");
  scanf(" %[^\n]s", NomeDoProd);
  printf("\nDigite sua descricao: ");
  scanf(" %[^\n]s", DescricaoDoProd);
  printf("\nDigite a quantidade: ");
  scanf("%i", &Estoque[produtosCadastrados].quantidade);
  printf("\nDigite o preco de compra: ");
  scanf("%f", &Estoque[produtosCadastrados].pcompra);
  printf("\nDigite o preco de venda: ");
  scanf("%f", &Estoque[produtosCadastrados].pvenda);
  strcpy(Estoque[produtosCadastrados].nome, NomeDoProd);
  strcpy(Estoque[produtosCadastrados].descricao, DescricaoDoProd);
  produtosCadastrados++;
  Estoque[produtosCadastrados - 1].CodigoDeBarra = produtosCadastrados;
  produtosEstoque[produtosCadastrados - 1] = produtosCadastrados;
  printf("\n\n\n%s cadastrado com sucesso!\n", NomeDoProd);
  int y;
  printf("\nDeseja cadastrar outro produto? Se sim digite 1, se nao 0: ");
  scanf("%i", &y);
  if (y == 1) {
    Limpar();
    Cadastrar();
  } else
    MenuDeEstoque();
}
void Listar() {
  printf("\n\nPRODUTOS REGISTRADOS NO ESTOQUE\n===========================================");
  int x;
  for (x = 0; x != produtosCadastrados; x++) {
    if (Estoque[x].CodigoDeBarra != 0)
      printf("\nNome: %s\nDescricao: %s\nQuantidade: %i\nPreco de compra: %.2f\nPreco de venda: %.2f\nCodigo do produto: %i\n===========================================", Estoque[x].nome, Estoque[x].descricao, Estoque[x].quantidade, Estoque[x].pcompra, Estoque[x].pvenda, Estoque[x].CodigoDeBarra);
  }
  printf("\n\n");
  MenuDeEstoque();
}
void ListarCaixa() {
  printf("\n\nPRODUTOS REGISTRADOS NO CAIXA\n");
  int x;
  for (x = 0; x != QuantMax; x++) {
    if (EstoqueCaixa[x].quantidade != 0)
      printf("\nNome: %s\nDescricao: %s\nQuantidade: %i\nPreco de compra: %.2f\nPreco de venda: %.2f\nCodigo do produto: %i\n\n", EstoqueCaixa[x].nome, EstoqueCaixa[x].descricao, EstoqueCaixa[x].quantidade, EstoqueCaixa[x].pcompra, EstoqueCaixa[x].pvenda, EstoqueCaixa[x].CodigoDeBarra);
  }
  MenuDeCaixa();
}
void AlterarCount() {
  int cod = 0;
  int contAntiga;
  printf("           EDITAR QUANTIDADE DE UM PRODUTO");
  printf("\n\nDigite  o codigo do produto: ");
  scanf("%i", &cod);
  if (VerificarProduto(cod, produtosEstoque, QuantMax) &&cod > 0) {
    printf("\nDigite a quantidade nova de %s: ", Estoque[cod - 1].nome);
    contAntiga = Estoque[cod - 1].quantidade;
    scanf("%i", &Estoque[cod - 1].quantidade);
    printf("\nQuantidade de %s alterado com sucesso, de %i para %i\n\n", Estoque[cod - 1].nome, contAntiga, Estoque[cod - 1].quantidade);
    int y;
    printf("\nDeseja alterar a quantidade de outro produto? Se sim digite 1, se nao 0: ");
    scanf("%i", &y);
    if (y == 1) {
      Limpar();
      AlterarCount();
    } else
      MenuDeEstoque();
  } else {
    Limpar();
    printf("\n\nCodigo do Produto nao encontrado no estoque\n");
    int y;
    printf("\nDeseja alterar a quantidade de outro produto? Se sim digite 1, se nao 0: ");
    scanf("%i", &y);
    if (y == 1) {
      Limpar();
      AlterarCount();
    } else
      MenuDeEstoque();
  }
}
void Buscarproduto() {
  int x = 0;
  printf("\n\nDigite  o codigo do produto: ");
  scanf("%i", &x);
  if (VerificarProduto(x, produtosEstoque, QuantMax)&&x > 0) {
    x = x - 1;
    printf("\nPRODUTO ENCONTRADO NO ESTOQUE");
    printf("\n===========================================");
    printf("\nNome: %s\nDescricao: %s\nQuantidade: %i\nPreco de compra: %.2f\nPreco de venda: %.2f\nCodigo do produto: %i", Estoque[x].nome, Estoque[x].descricao, Estoque[x].quantidade, Estoque[x].pcompra, Estoque[x].pvenda, Estoque[x].CodigoDeBarra);
    printf("\n===========================================\n\n");
    MenuDeEstoque();
  } else {
    printf("\n\nCodigo do Produto nao encontrado no estoque");
    int y;
    printf("\nDeseja buscar outro produto? Se sim digite 1, se nao 0: ");
    scanf("%i", &y);
    if (y == 1) {
      Limpar();
      Buscarproduto();
    } else
      MenuDeEstoque();
  }

}
void BuscarprodutoCaixa() {
  int x = 0;
  printf("\n\nDigite  o codigo do produto: ");
  scanf("%i", &x);
  if (VerificarProduto(x, produtosCaixa, QuantMax) &&EstoqueCaixa[x - 1].CodigoDeBarra > 0) {
    x = x - 1;
    printf("\nPRODUTO ENCONTRADO NO CAIXA");
    printf("\n===========================================");
    printf("\nNome: %s\nDescricao: %s\nQuantidade: %i\nPreco de compra: %.2f\nPreco de venda: %.2f\nCodigo do produto: %i", EstoqueCaixa[x].nome, EstoqueCaixa[x].descricao, EstoqueCaixa[x].quantidade, EstoqueCaixa[x].pcompra, EstoqueCaixa[x].pvenda, EstoqueCaixa[x].CodigoDeBarra);
    printf("\n===========================================\n\n");
    MenuDeCaixa();
  } else {
    printf("\n\nCodigo do Produto nao encontrado no estoque de caixa");
    int y;
    printf("\nDeseja buscar outro produto? Se sim digite 1, se nao 0: ");
    scanf("%i", &y);
    if (y == 1) {
      Limpar();
      BuscarprodutoCaixa();
    } else
      MenuDeCaixa();
  }
}
void Comprar() {
  int cod = 0;
  printf("\n\nDigite  o codigo do produto que deseja comprar: ");
  scanf("%i", &cod);
  if (cod - 1 > produtosCadastrados || cod <= 0) {
    printf("\n\nCodigo do Produto nao encontrado no estoque");
    int y;
    printf("\nDeseja comprar mais algum produto? Se sim digite 1, se nao 0: ");
    scanf("%i", &y);
    if (y == 1) {
      Limpar();
      Comprar();
    } else
      MenuDeCaixa();
  } else {
    int x, y;
    float conta;
    printf("\nDigite a quantidade de %s que deseja comprar: ", Estoque[cod - 1].nome);
    scanf("%i", &x);
    if (x <= Estoque[cod - 1].quantidade) {
      conta = Estoque[cod - 1].pcompra * x;
      printf("\nDeseja comprar %s no valor de %.2f? Se sim digite 1, se nao 0: ", Estoque[cod - 1].nome, conta);
      scanf("%i", &y);
      if (y == 1) {
        if (Dinheiro >= conta) {
          Dinheiro = Dinheiro - conta;
          int Index = cod - 1;
          Estoque[cod - 1].quantidade = Estoque[cod - 1].quantidade - x;
          strcpy(EstoqueCaixa[cod - 1].nome, Estoque[cod - 1].nome);
          strcpy(EstoqueCaixa[cod - 1].descricao, Estoque[cod - 1].descricao);
          EstoqueCaixa[cod - 1].quantidade = x + EstoqueCaixa[cod - 1].quantidade;
          EstoqueCaixa[cod - 1].pcompra = Estoque[cod - 1].pcompra;
          EstoqueCaixa[cod - 1].pvenda = Estoque[cod - 1].pvenda;
          EstoqueCaixa[cod - 1].CodigoDeBarra = Estoque[cod - 1].CodigoDeBarra;
          if (!VerificarProduto(Estoque[cod - 1].CodigoDeBarra, produtosCaixa, QuantMax)) {
            produtosCaixa[ContCaixa] = Estoque[cod - 1].CodigoDeBarra;
            ContCaixa++;
          }
          printf("\nCompra realizada com sucesso!");
          int y;
          printf("\nDeseja comprar mais algum produto? Se sim digite 1, se nao 0: ");
          scanf("%i", &y);
          if (y == 1) {
            Limpar();
            Comprar();
          } else
            MenuDeCaixa();
        } else {
          printf("\n\nVoce nao tem dinheiro suficiente! ");
          int y;
          printf("\nDeseja comprar mais algum produto? Se sim digite 1, se nao 0: ");
          scanf("%i", &y);
          if (y == 1) {
            Limpar();
            Comprar();
          } else
            MenuDeCaixa();
        }
      } else
        MenuDeCaixa();
    } else {
      printf("\n\nNao Existe essa quantidade de %s no estoque! ", Estoque[cod - 1].nome);
      int y;
      printf("\nDeseja comprar mais algum produto? Se sim digite 1, se nao 0: ");
      scanf("%i", &y);
      if (y == 1) {
        Limpar();
        Comprar();
      } else
        MenuDeCaixa();
    }
  }
}

void Vender() {
  int cod = 0;
  printf("\n\nDigite  o codigo do produto que deseja vender: ");
  scanf("%i", &cod);
  if (VerificarProduto(cod, produtosCaixa, QuantMax) == false || cod <= 0) {
    printf("\n\nCodigo do Produto nao encontrado no caixa");
    int y;
    printf("\nDeseja vender mais algum produto? Se sim digite 1, se nao 0: ");
    scanf("%i", &y);
    if (y == 1) {
      Limpar();
      Vender();
    } else
      MenuDeCaixa();
  } else {
    int x, y;
    float conta;
    printf("\nDigite a quantidade de %s que deseja vender: ", EstoqueCaixa[cod - 1].nome);
    scanf("%i", &x);
    if (x <= EstoqueCaixa[cod - 1].quantidade) {
      conta = EstoqueCaixa[cod - 1].pvenda * x;
      printf("\nDeseja vender %s no valor de %.2f? Se sim digite 1, se nao 0: ", EstoqueCaixa[cod - 1].nome, conta);
      scanf("%i", &y);
      if (y == 1) {
        Dinheiro = Dinheiro + conta;
        int Index = cod - 1;
        Estoque[cod - 1].quantidade = Estoque[cod - 1].quantidade + x;
        if (EstoqueCaixa[cod - 1].quantidade == x) {
          strcpy(EstoqueCaixa[cod - 1].nome, "Null");
          strcpy(EstoqueCaixa[cod - 1].descricao, "Null");
          EstoqueCaixa[cod - 1].quantidade = 0;
          EstoqueCaixa[cod - 1].pcompra = 0;
          EstoqueCaixa[cod - 1].pvenda = 0;
          EstoqueCaixa[cod - 1].CodigoDeBarra = 0;
        } else
          EstoqueCaixa[cod - 1].quantidade = EstoqueCaixa[cod - 1].quantidade - x;
        printf("\nVenda realizada com sucesso!");
        int y;
        printf("\nDeseja vender mais algum produto? Se sim digite 1, se nao 0: ");
        scanf("%i", &y);
        if (y == 1) {
          Limpar();
          Vender();
        } else
          MenuDeCaixa();
      } else
        MenuDeCaixa();
    } else {
      printf("\n\nNao Existe essa quantidade de %s no estoque de caixa! ", EstoqueCaixa[cod - 1].nome);
      int y;
      printf("\nDeseja vender mais algum produto? Se sim digite 1, se nao 0: ");
      scanf("%i", &y);
      if (y == 1) {
        Limpar();
        Vender();
      } else
        MenuDeCaixa();
    }
  }
}
void MenuDeEstoque() {
  int opcao;
  printf(" \n            Gerenciamento de produtos\n\n\n");
  printf("\nDigite 1 - Cadastro de produtos");
  printf("\nDigite 2 - Alterar quantidade de produtos");
  printf("\nDigite 3 - Listar produtos");
  printf("\nDigite 4 - Buscar um produto por código de barras");
  printf("\nDigite 5 - Controle de caixa");
  printf("\n\nEscolher: ");
  scanf("%d", &opcao);
  switch (opcao) {
  case 1:
    Limpar();
    Cadastrar();
    break;
  case 2:
    Limpar();
    AlterarCount();
    break;
  case 3:
    Limpar();
    Listar();
    break;
  case 4:
    Limpar();
    Buscarproduto();
    break;
  case 5:
    Limpar();
    MenuDeCaixa();
    break;
  default:
    Quitar(1);
    break;
  }
}
void MenuDeCaixa() {
  int opcao;
  printf(" \n            Caixa - Supermercado Carlota");
  printf(" \n            Dinheiro na conta - R$%.2f\n\n\n", Dinheiro);
  printf("\nDigite 1 - Vender produto");
  printf("\nDigite 2 - Comprar produto");
  printf("\nDigite 3 - Listar produtos do caixa");
  printf("\nDigite 4 - Buscar um produto por código de barras");
  printf("\nDigite 5 - Para menu de estoque");
  printf("\n\nEscolher: ");
  scanf("%d", &opcao);
  switch (opcao) {
  case 1:
    Limpar();
    Vender();
    break;
  case 2:

    Limpar();
    Comprar();
    break;
  case 3:
    Limpar();
    ListarCaixa();
    break;
  case 4:
    Limpar();
    BuscarprodutoCaixa();
    break;
  case 5:
    Limpar();
    MenuDeEstoque();
    break;
  default:
    Quitar(2);
    break;
  }

}

void Quitar(int x) {
  int y;
  printf("\nDeseja sair do programa? Se sim digite 1, se nao 0: ");
  scanf("%i", &y);
  if (y == 1) {
    return;
  } else {
    if (x == 1)
      MenuDeEstoque();
    else
      MenuDeCaixa();
  }
}
