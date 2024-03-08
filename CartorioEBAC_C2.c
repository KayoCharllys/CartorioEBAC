#include <stdio.h> //biblioteca de comunicacao com o usuario
#include <stdlib.h> //biblioteca de alocacao de espaco em memoria
#include <locale.h> //biblioteca de alocacoes de texto por regiao
#include <string.h> //biblioteca responsavel por cuidar das string

int registro()
{
    char arquivo[40];
	char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    
    printf("Digite o CPF a ser cadastrado: "); //Interface pro usu�rio
    scanf("%s", cpf);
    
    strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
    
    FILE *file; //Cria o arquivo
    file = fopen(arquivo, "w"); //Escreve no arquivo
    fprintf(file,cpf); //Salva o valor da variavel
    fclose(file); //Fecha o arquivo
    
    file = fopen(arquivo, "a"); // Adcionar caracter
    fprintf(file, ", Nome:"); //O caracter desejado
    fclose(file); //Fechar novamente o arquivo
    
    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);
    
    file = fopen(arquivo, "a");
    fprintf(file, nome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file,", Sobrenome:");
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file, sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file,", Cargo:");
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file, cargo);
    fclose(file);
    
    system("pause");
}

int consulta()
{
    setlocale(LC_ALL, "portuguese"); //Definindo a linguagem
    
	char cpf[40]; //Localizar o arquivo
    char conteudo[200];
    
    printf("Digite o CPF a ser consultado: "); //Interface de Consulta pro usu�rio
    scanf("%s", cpf);
    
    FILE *file; //Abrindo o arquivo
    file = fopen(cpf, "r"); //Lendo o arquivo
    
    if(file == NULL) //Caso o Usu�rio digite um CPF n�o cadastrado
    {
    	printf("N�o foi possivel localizar o CPF consultado!.\n");
	}
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: CPF:"); //Resposta para o Usu�rio
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	fclose(file);
}

int deletar()
{
	
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: "); //Interface pro usu�rio
	scanf("%s", cpf); //Pedindo o CPF
	
	remove(cpf); //Removendo o CPF
	
	FILE *file; //Abrindo local de arquivo
	file = fopen(cpf,"r"); //Abrindo o arquivo e lendo
	fclose(file);
	
	if(file == NULL); //Caso o CPF seja Nulo
	{
		printf("O CPF foi deletado com sucesso!.\n "); //Resposta ao usu�rio
		system("pause");
	}
	
}



int main()
{
	int opcao=0;
	int x=1;
	
	for(x=1;x=1;) //Operador de repeti��o
	{
		system("cls");
	
	
	
	
       setlocale(LC_ALL, "portuguese"); //Definindo a linguagem
	
	   printf("\t---|Cart�rio da EBAC|--- \n\n"); //inicio do menu
	   printf("*Escolha a op��o desejada do menu: \n\n");
	   printf("\t1 - Registrar nomes \n");
	   printf("\t2 - Consultar nomes \n");
	   printf("\t3 - Deletar nomes \n\n"); 
	   printf("op��o:");//fim do menu
	
       scanf("%d", &opcao); //armazenando a escolha do usu�rio
    
       system("cls");
       
        switch(opcao)
        {
		   case 1: //Inicio da sele��o
		   registro();
    	   break;
    	   
    	   case 2:
		   consulta();
		   break;
		   
		   case 3:
		   deletar();
		   break;
		   
		   default:
		   printf("Essa op��o est� indisponivel\n"); //Op��o n�mero 4 "indisponivel"
		   system("pause");
	 	   break; //fim da sele��o
		}		
    }
}
