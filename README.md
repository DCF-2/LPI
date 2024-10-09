---

 Gerenciador de Estoque em C

Este projeto é um **Gerenciador de Estoque** escrito em C. Ele permite que o usuário insira, liste, atualize e remova produtos de um inventário, além de salvar e carregar os dados em um arquivo de texto. O sistema foi projetado para ser simples e eficiente, funcionando por meio de um menu interativo no terminal.

## Funcionalidades

- **Inserir Produto:** Adiciona um novo produto ao estoque com informações como nome, quantidade, seção, preço, validade, fornecedor, entre outros.
- **Listar Produtos:** Exibe uma lista de todos os produtos cadastrados, mostrando seus detalhes.
- **Atualizar Produto:** Permite a atualização das informações de um produto existente.
- **Remover Produto:** Exclui um produto específico do estoque.
- **Salvar/Carregar Produtos:** Salva os dados em um arquivo (`produtos.txt`) e carrega os dados automaticamente ao iniciar o programa.
  
## Estrutura do Produto

Cada produto possui os seguintes campos:

- **Nome do Produto:** Primeiro e último nome (sem espaços entre as palavras)
- **Seção:** Um número inteiro representando a seção onde o produto está localizado
- **Quantidade:** A quantidade disponível do produto em estoque
- **Preço:** Valor do produto
- **Data de Validade:** Data em que o produto expira (dd/mm/yyyy)
- **Categoria:** Tipo de produto (por exemplo, eletrônico, alimento, etc.)
- **Fornecedor:** Nome do fornecedor
- **Data de Entrada:** Data em que o produto foi adicionado ao estoque (dd/mm/yyyy)

## Validações

O código possui algumas validações básicas para garantir a integridade dos dados:

- **Data de validade e data de entrada:** Verifica se os dias estão entre 1 e 31 e os meses entre 1 e 12.
- **Limite de produtos:** O programa só permite cadastrar até 100 produtos, e, caso atinja esse limite, o usuário é notificado.

## Funcionalidades futuras

- Melhoria nas validações de datas para levar em conta meses com menos de 31 dias.
- Suporte a mais tipos de validação de entrada, como garantir que a quantidade e o preço sejam números positivos.

## Como Executar

1. Clone este repositório.
2. Compile o código utilizando um compilador de C (como `gcc`):
   ```bash
   gcc gerenciador_estoque.c -o gerenciador_estoque
   ```
3. Execute o programa:
   ```bash
   ./gerenciador_estoque
   ```
4. Siga as instruções no menu para inserir, listar, atualizar ou remover produtos.

---
