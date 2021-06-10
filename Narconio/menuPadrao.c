
#include "menuPadrao.h"


/** \brief Atualiza a seleção pelo teclado ou mouse
 *
 * \param int* : Endereço da variável inteira correspondente à seleção
 * \return void
 *
 */

void atualizar_menu( DADOS_MENU* menu ){
        /// Pelo Teclado -----------------------------------
        atualizaSelSetas( menu );

        /// Recursos De Desenvolvedor
        alteraMenuEmExecucao( menu );

}
//###########################################################



/** \brief Desenha o menu
 *
 * \param DADOS_MENU* : Dados do menu
 * \return void
 *
 */

void desenhar_menu( DADOS_MENU* menu ){
        COR cor;
        int estilo;
        int centroY = centraMatrizYTela ( 2 * menu->qtd_items , menu->tela ) + menu->tela.altu / 9;
        static int item_anterior = 0;
        const int espY_titulo = ( menu->ativar_fonte_titulo )  ?  menu->fonte_titulo.altu  :  1;

        if( !menu->desenho_existente ){
                // Fundo
                desenRetang_R( menu->tela , ' ' , menu->cor_fundo , menu->cor_fundo );

                // Título
                if( menu->ativar_fonte_titulo ){
                        printFonte(
                                menu->titulo ,
                                menu->fonte_titulo,
                                (PONTO){
                                        (  menu->tela.larg - strlen_fonte( menu->titulo , menu->fonte_titulo , menu->espacamento_titulo.x ) ) / 2 ,
                                        menu->espacamento_titulo.y }
                                ,
                                menu->espacamento_titulo.x ,
                                menu->cor_titulo ,
                                menu->cor_fundo
                        );
                }else{
                        print_PRO(
                                menu->titulo ,
                                (PONTO){
                                        centraTxtXTela( menu->titulo ,  menu->tela ) ,
                                        menu->espacamento_titulo.y
                                } ,
                                PADRAO ,
                                menu->cor_titulo ,
                                menu->cor_fundo
                        );
                }

                // Sub-Título
                if( menu->ativar_fonte_sub_titulo ){
                        printFonte(
                                menu->sub_titulo ,
                                menu->fonte_sub_titulo,
                                (PONTO){
                                        (  menu->tela.larg - strlen_fonte( menu->sub_titulo , menu->fonte_sub_titulo , menu->espacamento_sub_titulo.x ) ) / 2 ,
                                        menu->espacamento_titulo.y+ espY_titulo + menu->espacamento_sub_titulo.y }
                                ,
                                menu->espacamento_sub_titulo.x ,
                                menu->cor_sub_titulo ,
                                menu->cor_fundo
                        );
                }else{
                        estilo = menu->sub_titulo_subl ? SUBLINHADO : PADRAO;
                        print_PRO( menu->sub_titulo , (PONTO){ centraTxtXTela( menu->sub_titulo , menu->tela ) , menu->espacamento_titulo.y+ menu->fonte_titulo.altu + menu->espacamento_sub_titulo.y } , estilo , menu->cor_sub_titulo , menu->cor_fundo );
                }

                // Items
                for( int i = 0 ; i < menu->qtd_items ; i++ ){
                        if( i == menu->selec ) cor = menu->cor_select;
                        else cor = menu->cor_comum;

                        if( menu->ativar_fonte_items ){
                                printFonte(
                                        menu->items_menu[ i ] ,
                                        menu->fonte_items ,
                                        (PONTO){
                                                menu->deslocamento_items.x + (  menu->tela.larg - strlen_fonte( menu->items_menu[ i ] , menu->fonte_items , menu->espacamento_items.x ) ) / 2 ,
                                                menu->deslocamento_items.y + centroY + menu->espacamento_items.y * i }
                                        ,
                                        menu->espacamento_items.x ,
                                        cor ,
                                        menu->cor_fundo
                                );
                        }else{
                                printColoridoXY( menu->items_menu[ i ] , centraTxtXTela( menu->items_menu[ i ] , menu->tela ) , centroY + 4 * i , cor );
                        }
                }

                menu->desenho_existente = true;
        }else{
                for( int i = 0 ; i < menu->qtd_items ; i++ )
                        if( i == item_anterior  ||  i == menu->selec ){
                                if( i == menu->selec ) cor = menu->cor_select;
                                else cor = menu->cor_comum;

                                if( menu->ativar_fonte_items ){
                                        printFonte(
                                                menu->items_menu[ i ] ,
                                                menu->fonte_items ,
                                                (PONTO){
                                                        menu->deslocamento_items.x + (  menu->tela.larg - strlen_fonte( menu->items_menu[ i ] , menu->fonte_items , menu->espacamento_items.x ) ) / 2 ,
                                                        menu->deslocamento_items.y + centroY + menu->espacamento_items.y * i }
                                                ,
                                                menu->espacamento_items.x ,
                                                cor ,
                                                menu->cor_fundo
                                        );
                                }else{
                                        printColoridoXY( menu->items_menu[ i ] , centraTxtXTela( menu->items_menu[ i ] , menu->tela ) , centroY + 4 * i , cor );
                                }

                        }
        }

        item_anterior = menu->selec;
        menu->item_alterado = false;
}
//###########################################################



/** \brief Atualiza variável de seleção pelas teclas setas
 *
 * \param DADOS_MENU* :
 * \param int : Limite INFERIOR do valor da variável de seleção
 * \param int : Limite SUPERIOR do valor da variável de seleção
 * \return void
 *
 */
 void atualizaSelSetas( DADOS_MENU* menu ){

        if( GetAsyncKeyState( VK_DOWN ) & 0x8000 )
                if( menu->selec < menu->qtd_items - 1 ){
                        menu->selec += 1;
                        menu->item_alterado = true;
                }

        if( GetAsyncKeyState( VK_UP ) & 0x8000 )
                if( menu->selec > 0 ){
                        menu->selec -= 1;
                        menu->item_alterado = true;
                }
}
//#####################################################



/** \brief Altera dados do menu com programa em execução
 *
 * \param DADOS_MENU*
 * \return void
 *
 */
 #define _REDESENHA_MENU { LMPTELA ; menu->desenho_existente = 0 ; menu->item_alterado = 1; }
void alteraMenuEmExecucao( DADOS_MENU* menu ){

        if( GetAsyncKeyState( VK_F5 ) ){ _REDESENHA_MENU};

        if( GetAsyncKeyState( VK_F6 ) ){
           menu->ativar_fonte_titulo ^= 1;
           _REDESENHA_MENU;
        }

        if( GetAsyncKeyState( VK_F7 ) ) {
                menu->ativar_fonte_sub_titulo ^= 1;
                _REDESENHA_MENU;
        }

        if( GetAsyncKeyState( VK_F8 ) ){
                menu->ativar_fonte_items ^= 1;
                _REDESENHA_MENU;
        }

        if( GetAsyncKeyState( VK_F4 ) ){
                menu->cor_fundo = rand() % 256;
                _REDESENHA_MENU;
        }

        if( GetAsyncKeyState( VK_F9 ) ){
                menu->cor_titulo = rand() % 256;
                _REDESENHA_MENU;
        }

        if( GetAsyncKeyState( VK_F10 ) ){
                menu->cor_sub_titulo = rand() % 256;
                _REDESENHA_MENU;
        }

        if( GetAsyncKeyState( VK_F11 ) ){
                menu->cor_select = rand() % 256;
                _REDESENHA_MENU;
        }

        if( GetAsyncKeyState( VK_F12 ) ){
                menu->cor_comum = rand() % 256;
                _REDESENHA_MENU;
        }

}
//#####################################################




