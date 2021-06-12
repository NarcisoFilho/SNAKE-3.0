#ifndef __DEFINICOES_JOGO_H_
#define __DEFINICOES_JOGO_H_


        /// Defines ═════════════════════════════════════════════════════════════════
        // TELA
        #define REF_RESOLUCAO_X 1366    // LARGURA do monitor de referência em pixels
        #define REF_RESOLUCAO_Y 768     // ALTURA do monitor de referência em pixels

        #define REF_QTD_COLS 172        // Quantidade de COLUNAS da tela de referência
        #define REF_QTD_LINS 49         // Quantidade de LINHAS da tela de referência

        // SNAKE
        #define TAM_MAX 300             // Tamanho máximo da snake
        #define INCREMENTO_TAM_ALIMENTO 2   // Tamanho adicionado à snake quando consome alimento

        // SENTIDOS
        #define PI 3.141592654

        #define DIREITA 0
        #define CIMA 90
        #define ESQUERDA 180
        #define BAIXO 270

        // CORES
        #define COR_SNAKE_PADRAO VERDE_BRILHANTE

        #define COR_FUNDO_TITULO_PARTIDA COR_FUNDO_AREA_EXTERNA
        #define COR_TEXTO_TITULO_PARTIDA VERDE_LIMA
        #define COR_TEXTO_PONTOS_LEVEL AMARELO
        #define COR_PONTOS_LEVEL AMARELO
        #define COR_FUNDO_LEVEL_PONTOS CINZA_9

        #define COR_FUNDO_AREA_EXTERNA PRETO
        #define COR_FUNDO_AREA_JOGO CAVEIRA
        #define COR_MOLDURA_AREA_JOGO CINZA_10
        #define COR_MOLDURA_FUNDO_AREA_JOGO CINZA_5

        #define COR_ALIMENTO AMARELO
        #define COR_ALIMENTO_FUNDO CINZA_7
        #define COR_DINHEIRO VERDE_LIMA
        #define COR_DINHEIRO_FUNDO CINZA_7

        #define COR_FUNDO_OBSTACULOS MAROON
        #define COR_OBSTACULOS BRANCO_BRILHANTE

        #define COR_FUNDO_PORTAL CINZA_5

        #define COR_APRESENTAR_LEVEL VERDE_AZULADO_ESCURO

        // ÁREA DO JOGO
        #define LARG_AREA_DO_JOGO 150
        #define ALTU_AREA_DO_JOGO 38

        // TEMPOS
        #define DELAY_CICLO_FACIL 140    // Latência de atualização da posição da snake ( em relação ao relógio global );
        #define DELAY_FIM_JOGO 2
        #define DELAY_INICIO_LEVEL 1
        #define DELAY_FIM_LEVEL 1
        #define DELAY_MSG_GAME_OVER 5
        #define DELAY_MSG_VITORIA 7
        #define DELAY_EFEITO_PORTAL 80
        #define DELAY_EFEITO_ALIMENTO 200
        #define TEMPO_MAX_DINHEIRO_FACIL 9000
        #define BONUS_TEMPO__DINHEIRO_LEVEL 370
        #define TEMPO_BRILHO_COLETA 25

        // ITEMS DE COLETA
        #define QTD_ALIMENTOS_FINALIZAR_LEVEL 12
        #define QTD_PONTOS_ALIMENTOS_FACIL 10
        #define QTD_PONTOS_PASSAR_LEVEL_POR_TAM_FACIL ( QTD_PONTOS_ALIMENTOS_FACIL / 2 )
        #define QTD_PONTOS_DINHEIRO_MAX_FACIL 350
        #define CARACTERE_ALIMENTO '\276'
        #define CARACTERE_DINHEIRO '$'
        #define TAXA_DECAIMENTO_DINHEIRO_TEMPO 2.7

        // PROBABILIDADES
        #define PROBABILIDADE_GERAR_DINHEIRO 20

        // LEVEL'S
        #define QTD_LEVELs 14

        // DIFICULDADES
        #define FACIL 1
        #define NORMAL 2
        #define DIFICIL 3

        // PORTAL
        #define QTD_CORES_FUNDO_PORTAL 7
        #define QTD_CORES_TEXTO_PORTAL 7
        #define QTD_CARACTERES_PORTAL 4

        // MODO DE TESTE
        #define TECLA_MODO_DE_TESTE VK_F2

        // MENU
        #define MENU_DELAY 40       // Latência de atualização do menu
        #define MENU_COR_FUNDO CAVEIRA
        #define MENU_COR_COMUM CINZA_5
        #define MENU_COR_SELECT VERDE_AZULADO_ESCURO
        #define MENU_COR_SUB_TITULO VERDE_MUSGO
        #define MENU_COR_TITULO VERDE_BRILHANTE
        #define MENU_QTD_ITEMS  5
        #define MENU_MAX_CARACTERES_NOME_ITEM  20

        // HIGHSCORES
        #define QTD_HIGHSCORES 5
        #define TAM_MAX_NOME 14

        // MACROS
        #define FIM_DE_JOGO ( checaGameOver( jogo )  ||  checaJogoZerado( jogo ) )
        #define _FIM_DE_JOGO ( checaGameOver( *jogo )  ||  checaJogoZerado( *jogo ) )
        #define _DIFICULDADE jogo->snake.dificuldade
        #define DIFICULDADE jogo.snake.dificuldade
        #define REDESENHA_MENU { LMPTELA ; jogo.menu.desenho_existente = 0 ; jogo.menu.item_alterado = 1; }

        /// Inlcudes ═════════════════════════════════════════════════════════════════
        // Nativos
        #include <stdio.h>
        #include <stdlib.h>
        #include <math.h>
        #include <time.h>
        #include <limits.h>

        // Windows
        #ifndef _WIN32_WINNT
                #define _WIN32_WINNT 0x0501
        #endif
        #include "windows.h"
        #include "sys/timeb.h"

        // Narconio
        #include "Narconio/narconio.h"
        #include "Narconio/estruturas_narconio.h"

        // Próprios
        #include "structs_jogo.h"
        #include "inicializa_pre_jogo.h"
        #include "inicializa_pre_partida.h"
        #include "inicializa_level.h"
        #include "atualiza_jogo.h"
        #include "desenha_jogo.h"
        #include "calculos.h"
        #include "status_jogo.h"
        #include "desenha_menu.h"
        #include "Narconio/menuPadrao.h"
        #include "som_jogo.h"

#endif // __DEFINICOES_JOGO_H_
