/// Define todas as structs do jogo

#ifndef __STRUCTS_H_
#define __STRUCTS_H_

        #include "definicoes_jogo.h"

        typedef BOOL FLAG; /* Expressa uma flag */

        typedef struct{
                int lins;                       // Número de linhas da tela
                int cols;                      // Número de colunas da tela

                PONTO resolucao;        // Resolução do monitor

                double escalaX;           // Escala das dimensões do monitor em relação  à resolução de referência
                double escalaY;           // Escala das dimensões do monitor em relação  à resolução de referência

                HWND handle_janela;
        }TELA;

        typedef struct{
                PONTO pos[ TAM_MAX ];         // Posições dos quadrados da snake
                int tam;                        // Tamanho da snake
                int pontos;                    // Pontos já ganhos
                int level;                      // O level atual
                float sentido;                      // Sentido atual
                int dificuldade;                // Dificuldade de jogo
        }SNAKE; /* Dados da snake, ou seja do jogador */

        typedef struct{
                FONTE fonte_big;
                FONTE fonte_small;
        }RES; /* Recursos do jogo */
        typedef struct{
                SNAKE snake;                 // Dados da snake em jogo;
                TELA tela;                      // Tela do jogo
                RETANG area_do_jogo;        // A área do jogo onde a snake pode se movimentar

                // Rescursos
                RES res;        // Recursos do jogo

                // Flag's
                FLAG flag_level_desenho_unico;           // Flag que indica necessidade de desenhar elementos que só precisam ser desenhados uma única vez
                FLAG flag_level_desenho_esporadico;   // Flag que indica necessidade de desenhar elementos que só precisam ser desenhados esporadicamente
                FLAG flag_level_desenho_volatil;   // Flag que indica necessidade de desenhar elementos voláteis
        }JOGO; /* Dados globais do jogo */

#endif // __STRUCTS_H_
