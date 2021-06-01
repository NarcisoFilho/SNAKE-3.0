#ifndef __DEFINICOES_JOGO_H_
#define __DEFINICOES_JOGO_H_


        /// Defines ═════════════════════════════════════════════════════════════════
        // TELA
        #define REF_RESOLUCAO_X 1366    // LARGURA do monitor de referência em pixels
        #define REF_RESOLUCAO_Y 768     // ALTURA do monitor de referência em pixels

        #define REF_QTD_COLS 172        // Quantidade de COLUNAS da tela de referência
        #define REF_QTD_LINS 49         // Quantidade de LINHAS da tela de referência

        // SNAKE
        #define TAM_MAX 100             // Tamanho máximo da snake
        #define LATENCIA_ATUALIZACAO 72   // Latência de atualização da posição da snake ( em relação ao relógio global );

        // SENTIDOS
        #define PI 3.141592654

        #define DIREITA 0
        #define CIMA 90
        #define ESQUERDA 180
        #define BAIXO 270

        // CORES
        #define COR_FUNDO_TITULO_PARTIDA COR_FUNDO_AREA_EXTERNA
        #define COR_TEXTO_TITULO_PARTIDA VERDE_LIMA

        #define COR_FUNDO_AREA_EXTERNA PRETO
        #define COR_FUNDO_AREA_JOGO CAVEIRA
        #define COR_MOLDURA_AREA_JOGO CINZA_10
        #define COR_MOLDURA_FUNDO_AREA_JOGO CINZA_5


        // ÁREA DO JOGO
        #define LARG_AREA_DO_JOGO 150
        #define ALTU_AREA_DO_JOGO 38

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

        // Narconio
        #include "Narconio/narconio.h"
        #include "Narconio/estruturas_narconio.h"

        // Próprios
        #include "structs_jogo.h"
        #include "inicializa_pre_jogo.h"
        #include "inicializa_pre_partida.h"
        #include "atualiza_jogo.h"
        #include "desenha_jogo.h"
        #include "calculos.h"

#endif // __DEFINICOES_JOGO_H_
