#include <stdio.h> //biblioteca de comunicacão com o usuário
#include <stdlib.h> //biblioteca de alocação de espaco em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsavel por cuidar das string

int registro() //Funcao responsavel por cadastrar os usuarios no sistema
{
	//inicio criacao de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da craicao de variaveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informacoes do usuario
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por criar os valores das strings
	
	FILE *file; //cria o arquivo 
	file = fopen(arquivo, "w"); //Cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //Salvo o valor da variavel
	fclose(file); //Fechar o arquivo
	
	file = fopen(arquivo, "a"); //Criar o arquivo e o "a" significa escrever
	fprintf(file,","); //Salvo o valor da variavel
	fclose(file); //Fechar o arquivo
	
	printf("digite o nome a ser cadastrado: "); //Coletando informacoes do usuario
	scanf("%s",nome); //refere-se a string
	
	file = fopen(arquivo, "a"); //criar o arquivo e o "a" significa escrever
	fprintf(file,nome); //Salvo no valor da variavel
	fclose(file); //fechar o arquivo
	
	file = fopen(arquivo, "a"); //criar o arquivo e o "a" signfica escrever
	fprintf(file,","); //salvo o valor da variavel
	fclose(file); //fechar o arquivo
	
	printf("digite o sobrenome a ser cadastrado: "); //coletando informacoes do usuario
	scanf("%s",sobrenome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //criar o arquivo e o "a" significa escrever
	fprintf(file,sobrenome); //salvo no valor da variavel
	fclose(file); //fechar o arquivo
	
	file = fopen(arquivo, "a"); //criar o arquivo e o "a" significa escrever
	fprintf(file,","); //salvo no valor da variavel
	fclose(file); //fechar o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informacoes do usuario
	scanf("%s",cargo); //refere-se a string
	
	file = fopen(arquivo, "a"); //criar o arquivo e o "a" significa escrever
	fprintf(file,cargo); //salvo no valor da variavel
	fclose(file); //fechar o arquivo
	
	system("pause"); //execultar o programa
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40]; 
	char conteudo[200];
	
	printf("digite o cpf a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file; //criando o arquivo
	file = fopen(cpf,"r"); //cria o arquivo e o "r" significa escrever
	
	if(file == NULL)
	{
		printf("Nao foi possivel abrir o arquivo, nao localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas sao as informacao do usuario: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
	
}

int deletar() //deletar arquivos
{
	char cpf[40];
	
	printf("Digite o CPF do usuario a ser deletado: "); //opcao de deletar arquivo
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O arquivo foi deletado!.\n");
		system("pause");
	}
	
}

int main()
	{
	int opcao=0; //definindo variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls"); //responsavel por limpar a tela
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cartorio da EBAC ###\n\n"); //inicio do menu
		printf("Escolha a opcao desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - sair do sistema\n\n");
		
		printf("Opcao: "); //fim do menu
	
		scanf("%d",&opcao); //armazenando a escolha do usuario
	
		system("cls");
		
		
		switch(opcao) //inicio da selecao do menu
		{
			case 1:
			registro(); //chamada de funcoes
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			
			default:
			printf("essa opcao nao esta disponivel!\n");
			system("pause");
			break;
			
		}

	}
}
