//JOGO DA FORCA
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

//prot�tipo
void desenhaForca (int erros);
void pegaNomePalavra (char nome[20], char palavra[27]);
int existe (char letra, char colecao[], int maximo);
int verificaVencedor (int tamanhoPalavra, char palavra[], char tentativas[], int tentativaAtual);
char jogarNovamente ();

//fun��o main
void main (){

	do{
		system ("cls");
		printf ("\t\tJOGO DA FORCA");
	
		char nome[20], palavra[27];
		pegaNomePalavra (nome, palavra); //fun��o que pede o nome e a palavra
	
		int tamanhoPalavra = strlen (palavra); //conta quantos caracteres tem na palavra
		int tentativaAtual = 0; //guarda a quantidade de tentativas que ja entraram
		char tentativas [50];
		int erros = 0;
		int i;
		int vencedor = 0; //se ainda � ou n�o vencedor
		
		while (erros <= 6){ 
			system ("cls");
			
			printf ("\t\tJOGO DA FORCA");
			printf ("\n\n%s, adivinhe a palavra: \n\n\n", nome); //fulano, adivinhe a palavra	
			
			int i;
			for (i = 0; i < tamanhoPalavra; i++){
				char letraAtual = palavra[i]; //guarda a letra atual na posi��o da palavra
				int e = existe(letraAtual, tentativas, tentativaAtual); //"e" recebe o resultado da execu��o da fun��o existe, passando a letraAtual para procurar no array(tentativas) at� a posi��o tentativa atual!
				
				if (e == 1){ //verifica se � verdadeiro ou falso, se 1(V) printa a letra. Sen�o se 0(F) printa somente o anderline.
					printf ("%c ", palavra[i]);
				}else{
					printf ("_ ");				
				}
	
			}
			printf ("\n\n");
			
			printf ("Tentativas:  ");	
			for (i = 0; i < tentativaAtual; i++){
				printf ("%c ", tentativas[i]); //imprime na tela todas as letras(tentativas) que ja foram tecladas at� a ultima(Atual)
			}
	
			printf ("\n");
			desenhaForca (erros); //fun��o que desenha a forca!!!!
		
			if (erros >= 6 || vencedor == 1){ //para ter somente 6 erros, e n�o pedir a s�tima tentativa. encerra o while quando for ganhador ou acabar as tentativas =(
				break;
			}
			
			printf ("\n\nTecle uma tentativa: ");
			char tent = getch(); //le do teclado e guarda dentro de tent!
			int e = existe (tent, palavra, tamanhoPalavra); //verifica se a tecla digitada existe na palavra
			tentativas[tentativaAtual] = tent; //joga a letra digitada dentro da cole�ao de tentativas na posi��o de tentativaAtual!!
			tentativaAtual++; //incrementa
			if (e == 0){ //se n�o existe a letra, incrementa o erro!!
				erros++;			
			}else{ //sen�o, vamos verificar se a pessoa ja venceu
				vencedor = verificaVencedor(tamanhoPalavra, palavra, tentativas, tentativaAtual); //criei uma variavel que recebe a execu��o de verificaVencedor :D
			}
	
		}
		
		printf ("\nFIM do Jogo!"); //ahhh :(
		if (vencedor == 1){
			printf ("\n\nParab\202ns!! Voce Venceu!!!"); //G�nio!!!!
		}else{
			printf ("\nVoce Perdeu =( !!!"); 
		}
		
		printf ("\n\nPalavra: %s\n", palavra); //printa a palavra do jogo
		printf ("Acertos: ");
		for (i = 0; i < tamanhoPalavra; i++){
			int e = existe (palavra[i], tentativas, tentativaAtual);
			if (e == 1){ //se ele acertou a letra, aparece S em baixo =D
				printf ("S");
			}else{ //sen�o, aparace N =(
				printf ("N");
			}
		}	
		
	}while(jogarNovamente() == 'S'); // recebe o resultado de jogarNovamente e compara. Se S, repete do inicio. Se N sai do 'do while' :)
	
	printf ("\n\n\tTchau tchau, obrigada por jogar =D"); 
}

//implementa��o
void desenhaForca (int erros){
	
	printf ("_____"); //forca
	printf ("\n|   |"); //forca
	printf ("\n|   |"); //forca
	printf ("\n|  _|_"); //forca
	
	printf ("\n|   "); //forca
	if (erros >= 1){
		printf ("%c", 001); //cabe�a
	}
	printf ("\n|  "); //forca
	if (erros >= 3){
		printf ("/"); //bra�o esquerdo
	}else{
		printf (" ");
	}
	if (erros >= 2){
		printf ("|"); //tronco
	}
	if (erros >= 4){
		printf ("\\"); //bra�o direito - precisa de duas (\\) pois uma espera um comando, como por exemplo \n!!
	}
	printf ("\n|  ");
	if (erros >=5){
		printf ("/ "); //perna esquerda
	}
	if (erros >=6){
		printf ("\\"); //perna direita
	}
	printf ("\n| "); //forca
}

void pegaNomePalavra (char nome[20], char palavra[27]){
	printf ("\n\nDigite seu nome: ");
	gets (nome);
	
	printf ("Digite uma palavra de at\202 26 letras: ");
	gets (palavra);
}

int existe (char letra, char colecao[], int maximo){ //a fun��o existe procura uma letra em um array(cole��o) e vai at� seu maximo
	int i;
	for(i = 0; i < maximo; i++){
		if (letra == colecao[i]){ //se a letra existir na cole��o, ent�o
			return 1; //achou a letra, retorna 1
		}
	}
	return 0; //n�o achou em nenhuma das posi��es at� max. N�o necessita do else pois se existir, para no return 1 =D
}

int verificaVencedor (int tamanhoPalavra, char palavra[], char tentativas[], int tentativaAtual){ //verifica se a pessoa vai ser ou n�o vencedora
	int acc = 0; //acumulativo
	int i;
	for (i = 0; i < tamanhoPalavra; i++){
		int e = existe (palavra[i], tentativas, tentativaAtual); //se as letras digitadas do teclado existem no array de tentativas at� a tentativaAtual(no maximo)!
		if(e == 1) {
			acc++;
		}
	}
	if (acc == tamanhoPalavra){ //se o acumulativo tiver o mesmo tamanho da palavra, quer dizer que ele acertou todas as letras da palavra e � vencedor =DD
		return 1;
	}else{
		return 0; //se n�o, n�o n� =((
	}
}

char jogarNovamente (){ //fun��o que pergunta ao jogador se ele quer jogar novamente
	char continuar;
	printf ("\n\nDeseja jogar novamente? [S/N]");
	continuar = toupper (getch());
	
	while (continuar != 'S' && continuar != 'N'){ //se a op�ao for diferente ele avisa que s� � invalido, s� serve S ou N, sim ou n�o!!!
		printf ("\nOpcao Invalida!!!\n");
		printf ("Deseja jogar novamente? [S/N] ");
		continuar = toupper (getch());
	}
	return continuar; 
}

