#include <stdio.h>

char board[3][3];  // Tabuleiro 3x3

/**
 * Inicializa o tabuleiro do jogo da velha. 
 * Define todas as células como vazias.
 */
void init_board() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

/**
 * Imprime o tabuleiro do jogo da velha.
 */
void print_board() {
    int i;
    printf("\n");
    printf("  1   2   3\n");
    for (i = 0; i < 3; i++) {
        printf("%d ", i + 1);
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        printf("\n");
        if (i != 2) {
            printf(" --- |---|---\n");
        }
    }
    printf("\n");
}

/**
 * Verifica o status do jogo.
 * Retorna:
 *   0 se o jogo ainda está em andamento.
 *   1 se algum jogador venceu.
 *  -1 se o jogo terminou em empate.
 */
int check_winner() {
    int i;

    // Verificar linhas
    for (i = 0; i < 3; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }

    // Verificar colunas
    for (i = 0; i < 3; i++) {
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return 1;
        }
    }

    // Verificar diagonais
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }

    // Verificar empate
    int count = 0;
    for (i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != ' ') {
                count++;
            }
        }
    }
    if (count == 9) {
        return -1;
    }

    return 0;
}

/**
 * Executa o jogo da velha. Solicita as jogadas dos jogadores, 
 * atualiza o tabuleiro e verifica o status do jogo até que haja 
 * um vencedor ou empate.
 */
void play_game() {
    int row, col;
    char player = 'X';
    int game_status = 0;

    init_board();

    while (game_status == 0) {
        print_board();

        // Obter a jogada do jogador
        printf("Jogador %c, faça a sua jogada (linha coluna): ", player);
        scanf("%d %d", &row, &col);

        // Verificar se a jogada é válida
        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
            printf("Jogada inválida! Tente novamente.\n");
            continue;
        }

        // Atualizar o tabuleiro com a jogada do jogador
        board[row - 1][col - 1] = player;

        // Verificar o status do jogo
        game_status = check_winner();

        // Alternar o jogador
        player = (player == 'X') ? 'O' : 'X';
    }

    print_board();

    // Exibir o resultado do jogo
    if (game_status == 1) {
        printf("Parabéns, jogador %c! Você venceu!\n", player);
    } else {
        printf("Empate! O jogo terminou empatado.\n");
    }
}

/**
 * Exibe uma mensagem de boas-vindas e chama a função 
 * play_game() para iniciar o jogo.
 */
int main() {
    printf("Bem-vindo ao Jogo da Velha!\n");
    play_game();
    return 0;
}
