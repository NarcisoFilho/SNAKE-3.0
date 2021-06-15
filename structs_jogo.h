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
                BOOL viva;                      // Status de vida da snake
                COR cor;    // Cor da snake
                FLAG flag_level_finalizado;     // Flag que indica se level foi finalizado
        }SNAKE; /* Dados da snake, ou seja do jogador */

        typedef struct{
                FONTE fonte_big;
                FONTE fonte_small;
                FONTE fonte_starWars;
        }RES; /* Recursos do jogo */

        typedef struct{
                PONTO pos;
                BOOL ativo;
        }ALIMENTO; /* Alimento comum da SNAKE */

        typedef struct{
                PONTO pos;
                struct _timeb momento_geracao;
                long int tempo_decorrido;
                BOOL ativo;
        }DINHEIRO; /* Alimento BÔNUS da SNAKE */

        typedef struct{
                PONTO pos;
                BOOL ativo;
        }PORTAL; /* Portal de finalização do level */

        typedef struct{
                char matriz[ ALTU_AREA_DO_JOGO ][ LARG_AREA_DO_JOGO + 1 ];  // Cópia do desenho do mapa contido no arquivo txt
                int qtd_alimentos_coletados;        // Quantidade de alimentos já coletados naquele level
                PONTO origem_snake;        // Ponto incial da snake
        }LEVEL; /* Dados do level carregados de arquivo .txt*/

        typedef struct{
                char nome_jogador[ TAM_MAX_NOME + 1 ];
                int pontos;
        }HIGHSCORES; /* Registro das pontuações mais altas carregadas de arquivo .bin */

        typedef struct{
                FILE* arq_modo;         // Registro em disco do modo de áudio atual. Atualizado pelo jogo e lido pelo sistema de áudio
                char modo_atual[ 3 ];
                BOOL ativado;
        }MODO_SOM;

        typedef struct{
                // Tela
                TELA tela;                      // Tela do jogo
                RETANG area_do_jogo;        // A área do jogo onde a snake pode se movimentar

                // Menu
                DADOS_MENU menu;        // Menu do Jogo

                // Jogador
                SNAKE snake;                 // Dados da snake em jogo;

                //Items Coletáveis
                ALIMENTO alimento;             // Item de coleta comum
                DINHEIRO dinheiro;             // Item de coleta especial
                PORTAL portal;                    // Portal de finalização do level

                // Rescursos
                RES res;        // Recursos do jogo
                LEVEL level[ QTD_LEVELs + 1 ];  // Os leveis do jogo

                MODO_SOM modo_som;      // Administra o modo de som

                HIGHSCORES highscores[ QTD_LEVELs + 1 ][ QTD_HIGHSCORES ];     // Carrega os highscores, de cada modo de jogo, do arquivo highscores.bin
                // highscores[ 0 ] para modo campanha e highcores[ level ] para cada level no modo sobrevivência

                int dificuldade_escolhida;      // Dificuldade definida no menu ( padrão será NORMAL, podendo ser alterada para FÁCIL ou DIFÍCIL )

                // Flag's
                FLAG flag_level_desenho_unico;           // Flag que indica necessidade de desenhar elementos que só precisam ser desenhados uma única vez
                FLAG flag_level_desenho_esporadico;   // Flag que indica necessidade de desenhar elementos que só precisam ser desenhados esporadicamente
                FLAG flag_level_desenho_volatil;   // Flag que indica necessidade de desenhar elementos voláteis
                FLAG flag_modo_infinito;   // Flag que indica que partida foi iniciada em modo inifinito
                FLAG flag_modo_de_teste;   // Flag que indica que jogo foi iniciado em modo de teste
        }JOGO; /* Dados globais do jogo */

#endif // __STRUCTS_H_
