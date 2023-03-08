/* script em C simulando uma porta digital
não aceita caracteres apenas numeros igual porta digital
caso erre 4 vezes sera bloqueado por 30 segundos
Feito por Eduardo Silva E-mail:eduardofox989@protonmail.com */

// Bibliotecas C
#include <stdio.h>      // Biblioteca de entrada e saida
#include <stdlib.h>     // Biblioteca do comando getchar
//#include <windows.h>  // Biblioteca do comando sleep para windows, descomente caso queria compilar no windows e comente a do Linux que esta abaixo
#include <unistd.h>     // Biblioteca do comando sleep para Linux,   descomente caso queria compilar no linux e comente a do windows que esta acima

// funcao do programa
int main(){
    int passwd = 123;                                                           // variavel inteira com a Senha da Porta
    int passwd_user;                                                            // variavel inteira que vai receber a senha do usuario
    int i = 0;                                                                  // Variavel inteira que vai receber o numero de tentativas do usuario 
	
    printf("Inicializado Sistema da Porta Digital, Aguarde Por Favor...\n");    // Inicia o programa com uma mensagem de introdução


    sleep(1.5);                                                                 // dormi por 1.5s para simular inicilização do sistema
    do{                                                                         // inicio loop do while
	printf("Digite a Senha: ");                                             // Mensagem pedindo a senha
        while(scanf("%d", &passwd_user) != 1){                                  // recebe a senha do usuario e testa se é apenas numeros, caso tiver char cai no loop
            printf("Caracteres Invalidos, Digite Apenas Numeros\n");            // mensagem alerta de caracteres invalido
            printf("Digite a Senha: ");                                         // mensagem perdindo a senha novamente
            while(getchar() != '\n');                                           // não sei o que este comando faz
		}

	if (i == 4){                                                            // testa para saber se o usuario tentou 4 vezes
            printf("Senha Invalida, Bloqueado por 30 Segundos\n");              // mensagem indicado que foi bloqueado
	    sleep(30);                                                          // simulando bloqueio do usuario
            i = 0;                                                              // apos 30s numero de tentativas sera resetado
        }
		
        if ( passwd_user == passwd){                                            // testando se a senha da porta é igual a senha que o usuario digitou
            printf("Senha Correta, Abrindo a Porta...\n");                      // se a senha for correta abre a porta
            printf("Desligando o Sistema\n");                                   // mensagem fechando o programa
            return 0;                                                           // finalizando o programa sem erros
        }
    
        else{                                                                   // se o usuario errou a senha
            printf("Senha Invalida\n");                                         // mensagem indicado que errou
            i++;                                                                // variavel i sendo incrementada
            continue;                                                           // continuando o loop
        }
    }while(i <= 10);                                                            // loop infinito para o usuario nunca sai do loop ate acerta a senha
}
