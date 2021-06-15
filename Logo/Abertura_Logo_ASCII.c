/**             Programa que exibe o logo da Carcará Games na abertura do jogo
    *              @author Narciso Filho
    *              @date 15/06/2021
    *
    */

#include "../Narconio/narconio.h"

#define LARG_LOGO 128
#define ALTU_LOGO 40
#define COR_FUNDO_LOGO CINZA_1

int main(){
        FILE* arq = fopen( "Logo/Carcará_Logo.txt" , "r" );
        const int tela_larg = 172 * ( GetSystemMetrics( SM_CXSCREEN ) / 1366.00 );
        const int tela_altu = 49 * ( GetSystemMetrics( SM_CYSCREEN ) / 768.00 );
        int X0_LOGO = ( tela_larg - LARG_LOGO ) / 2;
        int Y0_LOGO = 2;
        int k = 0;
        int ch;
        COR cor_txt , cor_fundo;

        inicializarJanela();

        desenRetang( 0 , 0 , tela_larg , tela_altu , COR_FUNDO_LOGO );
        system("START Logo\\som_abertura.exe");

        while( !feof( arq ) ){
                ch = fgetc( arq );

                if( ch != EOF  &&  ch != '\n'  &&  ch != '\r' ){
                        switch( ch ){
                                case '1':
                                        ch = '\333';
                                        cor_txt = CAVEIRA;
                                        cor_fundo = CAVEIRA;
                                        break;

                                case '2':
                                        ch = '\262';
                                        cor_txt = CINZA_10;
                                        cor_fundo = CINZA_5;
                                        break;

                                case '3':
                                        ch = '\261';
                                        cor_txt = CINZA_10;
                                        cor_fundo = CINZA_13;
                                        break;

                                case '4':
                                        ch = '\260';
                                        cor_txt = CINZA_10;
                                        cor_fundo = CINZA_13;
                                        break;
                                case '5':
                                        ch = '\262';
                                        cor_txt = 166;
                                        cor_fundo = LARANJA;
                                        break;

                                case '6':
                                        ch = '\333';
                                        cor_txt = VERMELHO;
                                        cor_fundo = VERMELHO;
                                        break;

                                case '-':
                                        ch = ' ';
                                        cor_txt = BRANCO_BRILHANTE;
                                        cor_fundo = BRANCO_BRILHANTE;
                                        break;
                                case ' ':
                                        cor_txt = COR_FUNDO_LOGO;
                                        cor_fundo = COR_FUNDO_LOGO;
                                        break;
                                default:
                                        ch = '?';
                                        cor_txt = COR_FUNDO_LOGO;
                                        cor_fundo = COR_FUNDO_LOGO;
                        }

                        defCorTxt_PRO( cor_txt , cor_fundo , PADRAO );
                        cursorXY( X0_LOGO + k % LARG_LOGO , Y0_LOGO + k / LARG_LOGO );
                        printf( "%c" , ch );
                        k++;
                }
        }

        char carc[] = "CARCARA GAMES";
        FONTE fonte = carregarFonte( "Fontes/Small.txt" );
        int esp = 5;

        printFonte(
                carc ,
                fonte ,
                (PONTO){
                        ( tela_larg - strlen_fonte( carc , fonte , esp ) ) / 2 ,
                        tela_altu - ( fonte.altu + 1 )
                } ,
                esp ,
                LARANJA ,
                COR_FUNDO_LOGO
        );

        fclose( arq );
        pausaS( 2 );
}
//#####################################################
