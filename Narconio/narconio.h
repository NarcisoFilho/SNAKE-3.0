/***-  narconio.h ════════════════════════════════╗
        *  @author Manoel Narciso Reis Soares Filho
        *  @date 26/05/2021
        *  @version 2.0
        *  ════════════════════════════════════════╝
        *       Sistemas Operacionais: Windows , Linux , MacOS
        *
        *       Fornece:
        *               # Funções de Controle de Execução
        *                       - Vários tipos de pausa portáveis
        *                       - Limpeza de buffer portável
        *                       - Sistema de Detecção de Erros
        *               # Funções de Design da Tela
        *                       - 256 cores pré-definidas
        *                       - Utilização de cores RGB
        *                       - Definição de estilos de texto: SUBLINHADO, NEGRITO, COR_NEGATIVA, etc
        *                       - Posicionamento do CURSOR
        *                       - Funções personalizadas
        *               # Desenho de Formas
        *                       - Desenho de formas geométricas
        *                       - Desenho de Molduras personalizáveis
        *
        *
        *
        */
#ifndef __NARCONIO_H_
#define __NARCONIO_H_

        #include <stdio.h>
        #include <stdlib.h>
        #include <time.h>
        #include <string.h>
        #include "estruturas_narconio.h"
        #include "windows_narconio.h"


///### INICIALIZAÇÃO ═══════════════════════════════════════════
        void inicializarJanela( void );           // Inicializa a janela ANSI
        void finalizarJanela( void );            // Finaliza a janela restaurando padrão


///### CONTROLE DE EXECUÇÃO ════════════════════════════════════
        void pausaMS( int tempoMS );                 // Pausa a execução. Tempo em millisegundos
        void pausaS( float tempoS );                  // Pausa a execução. Tempo em segundos
        void pausaE( void );                              // Pausa a execução até o usuário pressionar enter
        void pausaE_PRO( void );                     //Pausa a execução até o usuário pressionar enter, com limpeza prévia de buffer e pausa de no mínimo 0,5 s
        void limpaBuffer( void );                        // Limpa o buffer do teclado
        void limpaBuffer_PRO( void );              // Limpa o buffer do teclado com garantia de não alteração do cursor
        void ErroFatal( int cod );                        // Encerra sistema e exibe mensagem de erro

        // CODIGOS DE ERROS
        #define FALHA_AUTORIZACAO_ABERTURA_ARQ 100
        #define FALHA_ALOCACAO_MEM 101

        // Fomatos
        #define TIPO_CHAR 'c'
        #define TIPO_INT 'i'
        #define TIPO_FLOAT 'f'
        #define TAM_CHAR sizeof( char )
        #define TAM_INT sizeof( int )
        #define TAM_FLOAT sizeof( float )


///### TELA ════════════════════════════════════════════════════════
        /// DESIGN --------------------------------------------------------------------------------------
        void defCorTxt_OLD( COR cor );                        // Define cor de saída do texto, compatível com pcs muito antigos
        void defCorTxtFundo_OLD( COR cor );                  // Define cor de saída do fundo do texto, compatível com pcs muito antigos
        void defCorTxt( COR cor );                                 // Define cor de saída do texto
        void defCorTxtFundo( COR cor );                        // Define cor de saída do fundo do texto
        void defEstiloTxt( ESTILO estilo_de_texto );               // Define o estilo de saída do texto
        void defCorTxt_PRO( COR cor_texto , COR cor_fundo , ESTILO estilo );        // Definição PRO de estilo de texto

        void putcXY( char caractere , int x , int y  );                                  // Saída de caractere nas coordenadas ( x , y )
        void putcColorido( char caractere , COR cor );                                  // Saída de caractere colorido
        void putcColoridoXY( char caractere , int x , int y , COR cor );           // Saída de caractere colorido nas coordenadas ( x , y )
        void putc_PRO( char caractere , PONTO ponto ,COR cor_text ,  COR cor_fundo , int estilo  );           // Saída de caractere PRO

        void printXY( char* texto , int x , int y  );                                 // Saída de texto nas coordenadas ( x , y )
        void printColorido( char* texto , COR cor );                                    // Saída de texto colorido
        void printColoridoXY( char* texto , int x , int y , COR cor );          // Saída de texto colorido na posição ( x , y )
        void printSublinhado( char* texto );                                            // Saída de texto sublinhado
        void printSublinhadoXY( char* texto , int x , int y );                      // Saída de texto sublinhado em posição ( x , y )
        void printSubliColorXY( char* texto , int x , int y , COR cor );        // Saída de texto sublinhado  e colorido em posição ( x , y )
        void print_PRO( char* texto , PONTO ponto , ESTILO estilo , COR cor_text , COR cor_fundo );        // Saída de texto PRO

        void limpaTela( void );                                                                 // Limpa toda a tela
        void limpaTela_PRO( COR cor );                                                    // Limpa toda a Tela com uma cor
        void limpaLinha( int linha );                                                          // Limpa uma linha

        // CORES
        #define PRETO 0
        #define VERMELHO 1
        #define VERDE_MUSGO 2
        #define CASTANHO_CLARO 3
        #define AZUL_MARINHO 4
        #define AZUL AZUL_MARINHO
        #define VIOLETA_ESCURO 5
        #define CIANO 6
        #define BRANCO 7
        #define CINZA 8
        #define ROSA 9
        #define VERDE_LIMA 10
        #define VERDE VERDE_LIMA
        #define BEGE_CLARO 11
        #define AZUL_CLARO 12
        #define VIOLETA_CLARO 13
        #define CIANO_BRILHANTE 14
        #define BRANCO_BRILHANTE 15
        #define CAVEIRA 16
        #define AZUL_0 17
        #define AZUL_1 18
        #define AZUL_2 19
        #define AZUL_3 20
        #define AZUL_4 21
        #define VERDE_BRILHANTE 46
        #define MAROON 52
        #define ROSA_CHOQUE 200
        #define LARANJA 202
        #define AMARELO_CLARO 190
        #define AMARELO 226
        #define CINZA_0 232
        #define CINZA_1 233
        #define CINZA_2 234
        #define CINZA_3 235
        #define CINZA_4 236
        #define CINZA_5 237
        #define CINZA_6 238
        #define CINZA_7 239
        #define CINZA_8 240
        #define CINZA_9 241
        #define CINZA_10 242
        #define CINZA_11 243
        #define CINZA_12 244
        #define CINZA_13 245
        #define CINZA_14 246
        #define CINZA_15 247
        #define CINZA_16 248
        #define CINZA_17 249
        #define CINZA_18 250
        #define CINZA_19 251
        #define CINZA_20 252
        #define CINZA_21 253
        #define CINZA_22 254
        #define CINZA_23 255

        // ESTILOS DE TEXTO
        #define PADRAO 0
        #define NEGRITO 1
        #define ITALICO 3
        #define SUBLINHADO 4
        #define COR_NEGATIVA 7

        // MACROS
        #define RESET_PADRAO printf("\x1b[0m")         // Reinicia estilo e cor para o padrão do terminal
        #define LMPTELA printf("\x1b[2J")                    // Limpa Tela e reinicia posição do cursor para o inicio

        /// CURSOR -------------------------------------------------------------------------------------
        void cursorXY( int x , int y );                         // Posiciona o cursor nas coordenadas ( x , y )
        void cursorP( PONTO ponto );                        // Posiciona o cursor no ponto
        void cursorHome( void );                              // Posiciona o cursor no ponto incial ( 0 , 0 )
        void avancarCursorLins( int qtd_lins );           // Avança o cursor um número de linhas sem alterar coluna
        void avancarCursorCols( int qtd_cols );         // Avança o cursor um número de colunas sem alterar linha

        void salvarPosCursor( void );                        // Salva Posicão do cursor
        void carregarPosCursor( void );                    // Posiciona o cursor na posição salva anteriormente com o comando salvarPosCursor

        void esconderCursorTec( void );                    // Torna o cursor do teclado INVISÍVEL
        void exibirCursorTec( void );                         // Torna o cursor do teclado VISÍVEL
        PONTO obterCursorTec( void );                     // Retorna posição do cursor do teclado

        // MACROS
        #define S_CURSOR salvarPosCursor()               // Salva Posicão do cursor
        #define C_CURSOR carregarPosCursor()            // Posiciona o cursor na posição salva anteriormente com o comando salvarPosCursor

        /// FONTES --------------------------------------------------------------------------------------------
        FONTE carregarFonte( char* nome );                                                                                          // Carrega uma Fonte
       void printFonte( char* texto , FONTE fonte , PONTO ponto , int espacamento , COR cor_text , COR cor_fundo );              // Desenha um texto na tela com fonte personalizada

///### STRINGS ════════════════════════════════════════════════════════
        int centraTxtXTela( char* texto , RETANG tela );                    // Retorna coordenada de inserção de string para centralização horizontal
        int centraMatrizYTela( int qtd_elementos , RETANG tela );         // Retorna coordenada de inserção de conjunto de arrays para centralização vertical


///### ARRAYS / MATRIZES ═══════════════════════════════════════════════
        int pertence( float elemento , int qtd_elementos , VOID* array_generico , char tipo );    // Retorna verdadeiro se elemento pertence ao array


///### FORMAS  ════════════════════════════════════════════════════════
        /// FORMAS MACIÇAS -------------------------------------------------------------------------------
        void desenRetang( int x , int y , int larg , int altu , COR cor );            // Desenha retângulo
        void desenRetang_R( RETANG retang , char caractere , COR cor_texto , COR cor_fundo );        // Desenha retângulo a partir de RETANG
        void desenRetang_RCT( RETANG_CT retang , char caractere , COR cor_texto , COR cor_fundo );        // Desenha retângulo a partir de RETANG_CT

        /// MOLDURAS ---------------------------------------------------------------------------------------
        void desenMolduraLinear( int x , int y , int larg , int altu , COR cor );            // Desenha moldura retângular
        void desenMoldura_R( RETANG retang , COR cor_texto , COR cor_fundo , BOOL duplo );            // Desenha moldura retângular a partir de RETANG
        void desenMoldura_RCT( RETANG_CT retang , COR cor_texto , COR cor_fundo , BOOL duplo );            // Desenha moldura retângular a partir de RETANG_CT
        void desenMoldura_EX( RETANG retang , int espessura , char caratere , COR cor_texto , COR cor_fundo );            // Desenha moldura retângular com caractere personalizável e espessura variável
        void desenMoldura_PRO( RETANG retang , int espessura , char* sequen_carateres , COR cor_texto , COR cor_fundo );            // Desenha moldura retângular com sequências de caracteres
        void desenMoldura_PRO_CT( RETANG_CT retang , int espessura , char* sequen_carateres , COR cor_texto , COR cor_fundo );            // Desenha moldura retângular com sequências de caracteres ( RETANG_CT )

#endif // __NARCONIO_H_
