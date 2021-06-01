/// Define todas as structs do jogo

#ifndef __STRUCTS_H_
#define __STRUCTS_H_

        #include "definicoes_jogo.h"

        typedef BOOL FLAG; /* Expressa uma flag */

        typedef struct{
                int lins;                       // N�mero de linhas da tela
                int cols;                      // N�mero de colunas da tela

                PONTO resolucao;        // Resolu��o do monitor

                double escalaX;           // Escala das dimens�es do monitor em rela��o  � resolu��o de refer�ncia
                double escalaY;           // Escala das dimens�es do monitor em rela��o  � resolu��o de refer�ncia

                HWND handle_janela;
        }TELA;

        typedef struct{
                PONTO pos[ TAM_MAX ];         // Posi��es dos quadrados da snake
                int tam;                        // Tamanho da snake
                int pontos;                    // Pontos j� ganhos
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
                RETANG area_do_jogo;        // A �rea do jogo onde a snake pode se movimentar

                // Rescursos
                RES res;        // Recursos do jogo

                // Flag's
                FLAG flag_level_desenho_unico;           // Flag que indica necessidade de desenhar elementos que s� precisam ser desenhados uma �nica vez
                FLAG flag_level_desenho_esporadico;   // Flag que indica necessidade de desenhar elementos que s� precisam ser desenhados esporadicamente
        }JOGO; /* Dados globais do jogo */

#endif // __STRUCTS_H_
