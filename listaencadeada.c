#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct endereco{
  char rua[50], num[10], comp[50], bai[50], cep[10], cid[50], estado[50], pais[50];
};

struct telefone{
  char ddd[2], numero[10];
};

struct data{
  char dia[2], mes[2], ano[4];
};
struct dados_pessoais{
  char nome[50], email[50], observacao[50];
};

struct cadastro {
	struct dados_pessoais pessoais;
	struct endereco Endereco;
	struct telefone Telefone;
	struct data Data;
	struct cadastro *prox;
};

typedef struct cadastro Cadastro;
Cadastro *primeiro;

void separador() {
	printf("=============================\n");
}

void adicionar() {
	Cadastro *user = malloc(sizeof(Cadastro));
  printf("Informe o nome:\n");
  gets(user->pessoais.nome);
  printf("\n");
  printf("Informe o e-mail:\n");
  gets(user->pessoais.email);
  printf("\n");
  printf("Rua: ");
  gets(user->Endereco.rua);
  printf("Número da casa: ");
  gets(user->Endereco.num);
  printf("Complemento: ");
  gets(user->Endereco.comp);
  printf("Bairro: ");
  gets(user->Endereco.bai);
  printf("CEP: ");
  gets(user->Endereco.cep);
  printf("Cidade: ");
  gets(user->Endereco.cid);
  printf("Estado: ");
  gets(user->Endereco.estado);
  printf("País: ");
  gets(user->Endereco.pais);
  printf("\n");
  printf("DDD: ");
  gets(user->Telefone.ddd);
  printf("Número: ");
  gets(user->Telefone.numero);
  printf("\n");
  printf("Dia: ");
  gets(user->Data.dia);
  printf("Mês: ");
  gets(user->Data.mes);
  printf("Ano: ");
  gets(user->Data.ano);
  printf("\n");
  printf("Adicione alguma observação:\n");
  gets(user->pessoais.observacao);
  	
	user->prox = primeiro;
    primeiro = user;
}

void imprimir(Cadastro *user) {
	if(user != NULL) {
		printf("\nNome: %s\n", user->pessoais.nome);
		printf("E-mail: %s\n", user->pessoais.email);
		printf("Endereco: Rua %s %s %s ", user->Endereco.rua, user->Endereco.num, user->Endereco.bai);
		printf("%s\n%s %s %s %s\n", user->Endereco.cep, user->Endereco.cid, user->Endereco.estado, 
		user->Endereco.pais, user->Endereco.comp);
		printf("Telefone: (%s) %s\n", user->Telefone.ddd, user->Telefone.numero);
		printf("Data de nascimento: %s/%s/%s\n", user->Data.dia, user->Data.mes, user->Data.ano);
		printf("Observacao: %s\n\n\n", user->pessoais.observacao);
		imprimir(user->prox);
	}
}

void procurar_nome(Cadastro *user, char p_nome[]) {
	if(user != NULL) {
		if(strcmp(p_nome, user->pessoais.nome) == 0) {
		printf("\nNome: %s\n", user->pessoais.nome);
		printf("E-mail: %s\n", user->pessoais.email);
		printf("Endereco: Rua %s %s %s ", user->Endereco.rua, user->Endereco.num, user->Endereco.bai);
		printf("%s\n%s %s %s %s\n", user->Endereco.cep, user->Endereco.cid, user->Endereco.estado, 
		user->Endereco.pais, user->Endereco.comp);
		printf("Telefone: (%s) %s\n", user->Telefone.ddd, user->Telefone.numero);
		printf("Data de nascimento: %s/%s/%s\n", user->Data.dia, user->Data.mes, user->Data.ano);
		printf("Observacao: %s\n\n\n", user->pessoais.observacao);
		}	
		procurar_nome(user->prox, p_nome);
	}
}

int main() {
	int opcao, aux;
  	char condicao, nome[80];
	
	do{
		separador();
		printf("\tMENU\n");
		separador();
		printf("[1] - Abrir agenda\n");
		printf("[2] - Sair");
		printf("\nSua opcao: ");
		scanf("%d", &opcao);
		switch(opcao) {
			case 1:
				do {
					separador();
					printf("[1] - Inserir contato no topo\n");
					printf("[2] - Ver todos os contatos\n");
					printf("[3] - Procurar contatos por nome\n");
					printf("[4] - Voltar\n");
					separador();
					printf("Sua opcao: ");
					scanf("%d", &opcao);
					switch(opcao) {
						case 1:
							condicao = 's';
            				while(condicao != 'n') {
            					adicionar ();
								fflush(stdin);
								printf("Deseja continuar [s / n] : ");
								scanf("%s", &condicao);
            				}
							break;
						case 2: 
							imprimir(primeiro);
							break;
						case 3:
							fflush(stdin);
							printf("Informe o nome desejado: ");
							scanf("%s", &nome);
							procurar_nome(primeiro, nome);
							break;
						case 4:
							aux = 2;
							break;
						default:
							printf("\n[ERRO] Opcao Invalida :(\n");
					}	
				} while(aux != 2);
				break;
			case 2:
				aux = 1;
				break;
			default:
				printf("\n[ERRO] Opcao Invalida :(\n");
		}
	} while(aux != 1);
	
	return 0;
}
