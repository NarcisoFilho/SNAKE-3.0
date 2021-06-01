/**     Estruturas para narconio.h
 *              @brief Tipos de dados definidos para uso da biblioteca narconio.h
 *
 */


#ifndef __ESTRUTURAS_H_
#define __ESTRUTURAS_H_

        /// ESTRUTURAS SIMPLES ══════════════════════════════════════════════
        typedef int BOOL;
        #define true 1
        #define false 0

        /* Uma cor pré-definida */
        typedef int COR;

        /* Um estilo de texto pré-definido */
        typedef int ESTILO;

        /* Uma tecla pré-definida */
        typedef int TECLA;

        /* Define um ponto de coordenadas ( x , y ). x para coluna e y para linha */
        typedef struct{
                int x;          // Coordenada x do ponto
                int y;          // Coordenada y do ponto
        }PONTO;

        /* Define um retângulo através de um ponto, que é a quina superior esquerda
        , além da largura e da altura */
        typedef struct{
                PONTO ponto;            // Quina superior esquerda
                int larg;               // Largura do retângulo
                int altu;               // Altura do retângulo
        }RETANG;

        /* Define um retângulo através de um ponto, que é o centro do retângulo
        , além da largura e da altura */
        typedef struct{
                PONTO ponto;            // Centro
                int larg;               // Largura do retângulo
                int altu;               // Altura do retângulo
        }RETANG_CT;


        /// ESTRUTURAS COMPLEXAS ════════════════════════════════════════════

        #define MAX_LINHAS_FONTE 77
        #define MAX_COLUNAS_FONTE 1000
        typedef struct{
                FILE* ptr;
                char arq_fonte[ 35 ];
                int y0_letra[ 256 ];
                int x0_letra[ 256 ];
                int xf_letra[ 256 ];
                int larg[ 256 ];
                BOOL caracs_dispon[ 256 ];
                int altu;
                int qtd_caract;
                char matriz[ MAX_LINHAS_FONTE ][ 1000 ];
        }FONTE;



        typedef struct {
                FILE* ptrFile;
                char* nome;
                char* pasta;
                void* tipo;

                int lins;
                int cols;
        }METADADOS_ARQ;

        typedef struct {
                char* titulo;
                char* sub_titulo;
                char** items_menu;
                int qtd_items;
                int selec;
                int sair_loop;

                COR cor_comum;
                COR cor_select;
                COR cor_titulo;
                COR cor_sub_titulo;

                BOOL titulo_subl;
                RETANG tela;
        }DADOS_MENU;



#endif // __ESTRUTURAS_H_
