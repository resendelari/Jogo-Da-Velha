#include <iostream>
using namespace std;

#define tam 3 //tamanho do tabuleiro

bool estaVazia(const char &posicao) { //confere se a posição está vazia
	return (posicao == ' ');
}


void addValor(char jogador, char &posicao) { //adiciona o 'x' ou 'o' na posicao desejada 
	posicao = jogador;
}


bool ganhou(const char tabuleiro[tam][tam]) { //confere se o jogador ganhou
	
	int cola[tam][tam]; //auxiliar para ransformar a matriz de caracteres em uma matriz de inteiros
	int somalinha = 0, somacoluna = 0, somadp = 0, somads = 0; //somatórios auxiliares para conferir se o jogador ganhou
	
	for(int i = 0; i < tam; i++){ //inicializando a matriz cola com '0', '1' ou '-1' a partir dos valores da matriz tabuleiro
		for(int j = 0; j < tam; j++) {
		
			if(tabuleiro[i][j] == ' ') {
				cola[i][j] = 0;
			} else if (tabuleiro[i][j] == 'x') { //se 'x' ganhar, a soma da linha, coluna ou diagonal deve ser 3
				cola[i][j] = 1;
			} else if(tabuleiro[i][j] == 'o') { //se 'o' ganhar, a soma da linha, coluna ou diagonal deve ser -3
				cola[i][j] = -1;
			}
			
		}
	}
	
	for(int i = 0; i < tam; i++) { //somando as linhas
		somalinha = 0;
		for(int j = 0; j < tam; j++) {
			somalinha += cola[i][j];
						
			if(somalinha == 3 or somalinha == -3) { //conferindo se ganhou
				return true;
			}
		}
	}
	
	for(int i = 0; i < tam; i++) { //somando as colunas
		somacoluna = 0;
		for(int j = 0; j < tam; j++) {
			somacoluna += cola[j][i];
		}
		if(somacoluna == 3 or somacoluna == -3) { //conferindo se ganhou
			return true;
		}
	}
	
	for(int i = 0; i < tam; i++) { //somando a diagonal principal
		for (int j = 0; j < tam; j++) {
			if(i == j) {
				somadp += cola[i][j];
			}
		}
	}
	
	if(somadp == 3 or somadp == -3) { //conferindo se a diagonal principal ganhou
		return true;
	}
	
	for(int i = 0; i < tam; i++) { //somando a diagonal secundária
		for(int j = tam-1; j >= 0; j--) {
			somads += cola[i][j];
			i++;
		}
		
	}
	
	if(somads == 3 or somads ==-3) { //conferindo se a diagonal secundária ganhou
		return true;
	}
	
	return false; //se nenhuma soma foi igual a 3 ou -3, retorna falso
}
 

int main() {
	
	char jogador = 'o'; //jogador pode assumir 'o' ou 'x'
	
	char tabuleiro [tam][tam];
	
	for(int i = 0; i < tam; i++){ //inicializando o tabuleiro 
		for(int j = 0; j < tam; j++) {
			tabuleiro[i][j] = ' '; 
		}
	}
	
	int jogadas = 0; //auxiliar do loop
	int posicao; //posicao que o jogador quer colocar o 'x' ou 'o'
	
	while(jogadas < 9 and ganhou(tabuleiro) == false) {
			
		for(int i = 0; i < 3; i++){ //mostra o tabuleiro para o jogador
			for(int j = 0; j < 2; j++){
				cout << "\t";
				cout << tabuleiro[i][j] << " \t| ";
			}
			cout << "\t";
			cout << tabuleiro[i][2];
			cout << endl;
			cout << "--------------------------------------------------";
			cout << endl;
		}
		
		
		if(jogador == 'x'){ //inverte o jogador
			jogador = 'o';
		} else {
			jogador = 'x';
		}
		
		cout << "Sua vez de jogar jogador " << jogador;
		cout << "\nDe 1 a 9, escolha sua posicao: ";
		cin >> posicao;
			
		switch (posicao) { //colocando o 'x' ou 'o' na posicao certa
			case 1:
				if (estaVazia(tabuleiro[0][0])) {
					addValor(jogador, tabuleiro[0][0]);
					jogadas++;
					ganhou(tabuleiro); 
				} else {
					cout << "Posicao ocupada." << endl;
					
					if(jogador == 'x'){ //aqui serve para que nao pule a vez do jogador que está jogando
						jogador = 'o';
					} else {
						jogador = 'x';
					}
				}
				break;
			
			case 2:
				if (estaVazia(tabuleiro[0][1])) {
					addValor(jogador, tabuleiro[0][1]);
					jogadas++;
					ganhou(tabuleiro);
				} else {
					cout << "Posicao ocupada." << endl;
					
					if(jogador == 'x'){
						jogador = 'o';
					} else {
						jogador = 'x';
					}
				}
				break;
	
			case 3:
				if (estaVazia(tabuleiro[0][2])) {
					addValor(jogador, tabuleiro[0][2]);
					jogadas++;
					ganhou(tabuleiro);
				} else {
					cout << "Posicao ocupada." << endl;
					
					if(jogador == 'x'){
						jogador = 'o';
					} else {
						jogador = 'x';
					}
				}
				break;
	
			case 4:
				if (estaVazia(tabuleiro[1][0])) {
					addValor(jogador, tabuleiro[1][0]);
					jogadas++;
					ganhou(tabuleiro);
				} else {
					cout << "Posicao ocupada." << endl;
					
					if(jogador == 'x'){
						jogador = 'o';
					} else {
						jogador = 'x';
					}
				}
				break;
	
			case 5:
				if (estaVazia(tabuleiro[1][1])) {
					addValor(jogador, tabuleiro[1][1]);
					jogadas++;
					ganhou(tabuleiro);
				} else {
					cout << "Posicao ocupada." << endl;
					
					if(jogador == 'x'){
						jogador = 'o';
					} else {
						jogador = 'x';
					}
				}
				break;
	
			case 6:
				if (estaVazia(tabuleiro[1][2])) {
					addValor(jogador, tabuleiro[1][2]);
					jogadas++;
					ganhou(tabuleiro);
				} else {
					cout << "Posicao ocupada." << endl;
					
					if(jogador == 'x'){
						jogador = 'o';
					} else {
						jogador = 'x';
					}
				}
				break;
	
			case 7:
				if (estaVazia(tabuleiro[2][0])) {
					addValor(jogador, tabuleiro[2][0]);
					jogadas++;
					ganhou(tabuleiro);
				} else {
					cout << "Posicao ocupada." << endl;
					
					if(jogador == 'x'){
						jogador = 'o';
					} else {
						jogador = 'x';
					}
				}
				break;
	
			case 8:
				if (estaVazia(tabuleiro[2][1])) {
					addValor(jogador, tabuleiro[2][1]);
					jogadas++;
					ganhou(tabuleiro);
				} else {
					cout << "Posicao ocupada." << endl;
					
					if(jogador == 'x'){
						jogador = 'o';
					} else {
						jogador = 'x';
					}
				}
				break;
	
			case 9:
				if (estaVazia(tabuleiro[2][2])) {
					addValor(jogador, tabuleiro[2][2]);
					jogadas++;
					ganhou(tabuleiro);
				} else {
					cout << "Posicao ocupada." << endl;
					
					if(jogador == 'x'){
						jogador = 'o';
					} else {
						jogador = 'x';
					}
				}
				break;
			default:
				cout << "Comando Invalido." << endl;
					
					if(jogador == 'x'){
						jogador = 'o';
					} else {
						jogador = 'x';
					}
		}
		
	if(ganhou(tabuleiro)) { //se o jogador ganhou
		cout << endl << "\tJogador " << jogador << " ganhou!" << endl << endl;
	}
		
	}
	
	for(int i = 0; i < 3; i++){ //imprime o tabuleiro pela ultima vez
		for(int j = 0; j < 2; j++){
			cout << "\t";
			cout << tabuleiro[i][j] << " \t| ";
		}
		cout << "\t";
		cout << tabuleiro[i][2];
		cout << endl;
		cout << "--------------------------------------------------";
		cout << endl;
	}
	
	if(!ganhou(tabuleiro)) { //se ninguem ganhou
		cout << endl << endl << "\tEmpate!";
	}
	
	return 0;
}