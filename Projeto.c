#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define limparTela() printf("\033[H\033[J") // É uma forma de limpar a tela!

#define Max_Produtos 100 // número máximo de produtos que podem ser inseridos

void enter() {
    getchar();  
    printf("Pressione ENTER para continuar.\n");
    char enter = 0;
    while (enter != '\r' && enter != '\n') { enter = getchar();}
}

void sair() {
    printf("+-----------------------------------------+\n");
    printf("|              Encerrando...              |\n");
    printf("+-----------------------------------------+\n");
}

void menu() {
    printf("+-----------------------------------------+\n");
    printf("|--------- Gerenciador de estoque --------|\n");
    printf("|---------    Escolha uma Opcao   --------|\n");
    printf("|  1 - Inserir Produto                    |\n");
    printf("|  2 - Listar Produtos                    |\n");
    printf("|  3 - Atualizar Produto                  |\n");
    printf("|  4 - Remover Produto                    |\n");
    printf("|  5 - Sair                               |\n");
    printf("+-----------------------------------------+\n");
    printf("Escolha uma das opcoes acima: ");
}

typedef struct {
    char primeiroNome[10];
    char ultimoNome[10];
    int secao;
    int quantidade;
    float preco;
    int diaValidade, mesValidade, anoValidade;
    char categoria[20];
    char fornecedor[30];
    int diaEntrada, mesEntrada, anoEntrada;
} Produto;

Produto produtos[Max_Produtos]; // array que armazena os produtos
int contadorProdutos = 0;

void salvarProdutos() {
    FILE *arquivo = fopen("produtos.txt", "w");
    if (arquivo != NULL) {
        for (int i = 0; i < contadorProdutos; i++) {
            fprintf(arquivo, "%s %s %d %d %.2f %d/%d/%d %s %s %d/%d/%d\n",
                    produtos[i].primeiroNome, produtos[i].ultimoNome,
                    produtos[i].secao, produtos[i].quantidade, produtos[i].preco,
                    produtos[i].diaValidade, produtos[i].mesValidade, produtos[i].anoValidade,
                    produtos[i].categoria, produtos[i].fornecedor,
                    produtos[i].diaEntrada, produtos[i].mesEntrada, produtos[i].anoEntrada);
        }
        fclose(arquivo);
        printf("Dados salvos com sucesso!\n");
    } else {
        printf("Erro ao salvar os dados!\n");
    }
}

void carregarProdutos() {
    FILE *arquivo = fopen("produtos.txt", "r");
    if (arquivo != NULL) {
        contadorProdutos = 0;
        while (fscanf(arquivo, "%s %s %d %d %f %d/%d/%d %s %s %d/%d/%d",
                      produtos[contadorProdutos].primeiroNome, produtos[contadorProdutos].ultimoNome,
                      &produtos[contadorProdutos].secao, &produtos[contadorProdutos].quantidade, &produtos[contadorProdutos].preco,
                      &produtos[contadorProdutos].diaValidade, &produtos[contadorProdutos].mesValidade, &produtos[contadorProdutos].anoValidade,
                      produtos[contadorProdutos].categoria, produtos[contadorProdutos].fornecedor,
                      &produtos[contadorProdutos].diaEntrada, &produtos[contadorProdutos].mesEntrada, &produtos[contadorProdutos].anoEntrada) != EOF) {
            contadorProdutos++;
        }
        fclose(arquivo);
        printf("Dados carregados com sucesso | Total de produtos: %d\n", contadorProdutos);
    } else {
        arquivo = fopen("produtos.txt", "w"); 
        if (arquivo != NULL) {
            fclose(arquivo);
            printf("Arquivo produtos txt criado com sucesso.\n");
        } else {
            printf("Erro ao criar o arquivo produtos.txt!\n");
        }
    }
}

void product() {
   if (contadorProdutos < Max_Produtos) {
    Produto p;
    
    printf("\n+-----------------------------------------+\n");
    printf("|          Cadastro de Novo Produto       |\n");
    printf("+-----------------------------------------+\n");

    printf("| Informe o primeiro nome do produto: ");
    scanf("%s", p.primeiroNome);
    printf("| Se o produto tiver apenas um nome digite 1 ponto final.\n");

    printf("| Informe o ultimo nome do produto: ");
    scanf("%s", p.ultimoNome);

    printf("| Insira a secao do produto: ");
    scanf("%d", &p.secao);

    printf("| Insira a quantidade do produto em estoque: ");
    scanf("%d", &p.quantidade);

    printf("| Insira o preco do produto: ");
    scanf("%f", &p.preco);

    printf("| Insira a data de validade (dd mm yyyy): ");
    scanf("%d %d %d", &p.diaValidade, &p.mesValidade, &p.anoValidade);

    if (p.diaValidade < 1 || p.diaValidade > 31 || p.mesValidade < 1 || p.mesValidade > 12) {
        printf("| Data de validade invalida. Tente novamente.\n");
        printf("+-----------------------------------------+\n");
        return;
    }

    printf("| Informe a categoria do produto: ");
    scanf("%s", p.categoria);

    printf("| Informe o fornecedor do produto: ");
    scanf("%s", p.fornecedor);

    printf("| Insira a data de entrada no estoque (dd mm yyyy): ");
    scanf("%d %d %d", &p.diaEntrada, &p.mesEntrada, &p.anoEntrada);

    if (p.diaEntrada < 1 || p.diaEntrada > 31 || p.mesEntrada < 1 || p.mesEntrada > 12) {
        printf("| Data de entrada invalida. Tente novamente.\n");
        printf("+-----------------------------------------+\n");
        return;
    }

    produtos[contadorProdutos] = p;  
    contadorProdutos++;               

    printf("\n+-----------------------------------------+\n");
    printf("| Produto cadastrado com sucesso!         |\n");
    printf("+-----------------------------------------+\n\n");
} else {
    printf("\n+-----------------------------------------+\n");
    printf("| Nao eh possivel cadastrar mais produtos  |\n");
    printf("| Capacidade maxima atingida!             |\n");
    printf("+-----------------------------------------+\n\n");
}
}

void listarProdutos() {
    if (contadorProdutos > 0) {
        printf("+-----------------------------------------+\n");
        printf("|            Listando Produtos            |\n");
        printf("+-----------------------------------------+\n");
        
        for (int i = 0; i < contadorProdutos; i++) {
            printf("\n+-----------------------------------------+\n");
            printf("| Produto %d: %s %s                      \n", i + 1, produtos[i].primeiroNome, produtos[i].ultimoNome);
            printf("+-----------------------------------------+\n");
            printf("| Secao           -> %d                   \n", produtos[i].secao);
            printf("| Quantidade      -> %d                   \n", produtos[i].quantidade);
            printf("| Validade        -> %02d/%02d/%04d       \n", produtos[i].diaValidade, produtos[i].mesValidade, produtos[i].anoValidade);
            printf("| Categoria       -> %s                   \n", produtos[i].categoria);
            printf("| Fornecedor      -> %s                   \n", produtos[i].fornecedor);
            printf("| Data de Entrada -> %02d/%02d/%04d       \n", produtos[i].diaEntrada, produtos[i].mesEntrada, produtos[i].anoEntrada);
            printf("+-----------------------------------------+\n");
        }
    } else {
        printf("\n+-----------------------------------------+\n");
        printf("| Nenhum produto cadastrado.              |\n");
        printf("+-----------------------------------------+\n");
    }
}

void updateProduct() {
    int index;
    
    if (contadorProdutos > 0) {
        listarProdutos();  
        
        printf("\n+-----------------------------------------+\n");
        printf("| Digite o numero do produto que deseja  |\n");
        printf("| atualizar: ");
        scanf("%d", &index);
        index--;  

        if (index >= 0 && index < contadorProdutos) {
            printf("\n+-----------------------------------------+\n");
            printf("| Atualizando produto -> %s %s\n", produtos[index].primeiroNome, produtos[index].ultimoNome);
            printf("+-----------------------------------------+\n");

            printf("| Informe o novo nome do produto: ");
            scanf("%s", produtos[index].primeiroNome);
            printf("| Se o produto tiver apenas um nome, digite apenas 1 ponto final.\n");
            
            printf("| Informe o novo ultimo nome do produto: ");
            scanf("%s", produtos[index].ultimoNome);

            printf("| Atualize a Secao do produto: ");
            scanf("%d", &produtos[index].secao);

            printf("| Atualize a Quantidade do produto em estoque: ");
            scanf("%d", &produtos[index].quantidade);

            printf("| Atualize o Preco do produto: ");
            scanf("%f", &produtos[index].preco);

            printf("| Atualize a Data de validade (dd mm yyyy): ");
            scanf("%d %d %d", &produtos[index].diaValidade, &produtos[index].mesValidade, &produtos[index].anoValidade);
            
            if (produtos[index].diaValidade < 1 || produtos[index].diaValidade > 31 || 
                produtos[index].mesValidade < 1 || produtos[index].mesValidade > 12) {
                printf("| Data de validade invalida. Tente novamente.\n");
                return;
            }

            printf("| Atualize a Categoria do produto: ");
            scanf("%s", produtos[index].categoria);

            printf("| Atualize o Fornecedor do produto: ");
            scanf("%s", produtos[index].fornecedor);

            printf("| Atualize a Data de entrada (dd mm yyyy): ");
            scanf("%d %d %d", &produtos[index].diaEntrada, &produtos[index].mesEntrada, &produtos[index].anoEntrada);
            
            if (produtos[index].diaEntrada < 1 || produtos[index].diaEntrada > 31 || 
                produtos[index].mesEntrada < 1 || produtos[index].mesEntrada > 12) {
                printf("| Data de entrada invalida. Tente novamente.\n");
                return;
            }
            
            printf("\n+-----------------------------------------+\n");
            printf("| Produto atualizado com sucesso!         |\n");
            printf("+-----------------------------------------+\n");
        } else {
            printf("\n+-----------------------------------------+\n");
            printf("| Produto nao encontrado.                 |\n");
            printf("+-----------------------------------------+\n");
        }
    } else {
        printf("\n+-----------------------------------------+\n");
        printf("| Nenhum produto cadastrado.              |\n");
        printf("+-----------------------------------------+\n");
    }
}

void removerProduto() {
    int index;

    if (contadorProdutos > 0) {
        listarProdutos();
        
        printf("\n+-----------------------------------------+\n");
        printf("| Digite o numero do produto que deseja  |\n");
        printf("| remover: ");
        scanf("%d", &index);
        index--;

        if (index >= 0 && index < contadorProdutos) {
            // Remover o produto deslocando os elementos
            for (int i = index; i < contadorProdutos - 1; i++) {
                produtos[i] = produtos[i + 1];
            }
            contadorProdutos--;  

            printf("\n+-----------------------------------------+\n");
            printf("| Produto removido com sucesso!          |\n");
            printf("+-----------------------------------------+\n");
        } else {
            printf("\n+-----------------------------------------+\n");
            printf("| Produto nao encontrado.                 |\n");
            printf("+-----------------------------------------+\n");
        }
    } else {
        printf("\n+-----------------------------------------+\n");
        printf("| Nenhum produto cadastrado.              |\n");
        printf("+-----------------------------------------+\n");
    }
}

int main() {
    carregarProdutos();

    int opcao;
    do {
        limparTela();
        menu();
        scanf("%d", &opcao);
        limparTela();

        switch (opcao) {
            case 1:
                product();
                salvarProdutos();
                enter();
                break;
            case 2:
                listarProdutos();
                enter();
                break;
            case 3:
                updateProduct();
                salvarProdutos();
                enter();
                break;
            case 4:
                removerProduto();
                salvarProdutos();
                enter();
                break;
            case 5:
                sair();
                break;
            default:
                printf("Opcao invalida Tente novamente\n");
        }
        
    } while (opcao != 5);

    return 0;
}
