

#include "definicoes_jogo.h"


/** \brief Gerencia as funções de desenho do jogo
 *
 * \param JOGO
 * \return void
 *
 */
void desenhaJogo( JOGO jogo ){

        // Atualização Constante
        if( jogo.flag_level_desenho_volatil ){
                desenhaSnake( jogo );
                desenhaDEBUGGER( jogo );
        }

        // Desenho Único
        if( jogo.flag_level_desenho_unico ){
                limpaTela_PRO( COR_FUNDO_AREA_EXTERNA );
                desenhaAreaDoJogo( jogo );
                desenhaObstaculos( jogo );
                desenhaTituloSnake( jogo );
        }

        // Desenho Esporádico
//        if( jogo.flag_level_desenho_esporadico ){
        desenhaAlimento( jogo );
//                jogo.flag_level_desenho_esporadico = false;
//        }

}
//#####################################################



/** \brief Desenha a SNAKE
 *
 * \param JOGO
 * \return void
 *
 */
void desenhaSnake( JOGO jogo ){
        // BLOCO FRONTAL
        desenRetang( jogo.snake.pos[ 0 ].x , jogo.snake.pos[ 0 ].y, 2 , 1 , VERDE_BRILHANTE );

        // APAGAR BLOCO FINAL
        desenRetang( jogo.snake.pos[ jogo.snake.tam - 1 ].x , jogo.snake.pos[ jogo.snake.tam - 1 ].y, 2 , 1 , COR_FUNDO_AREA_JOGO );

}
//#####################################################


/** \brief Desenha a moldura do jogo
 *
 * \param JOGO
 * \return void
 *
 */
void desenhaAreaDoJogo( JOGO jogo ){
        desenRetang_R( jogo.area_do_jogo , ' ' , COR_FUNDO_AREA_JOGO , COR_FUNDO_AREA_JOGO );
        desenMoldura_R( jogo.area_do_jogo , COR_MOLDURA_AREA_JOGO , COR_MOLDURA_FUNDO_AREA_JOGO , false );
        desenRetang( jogo.area_do_jogo.ponto.x - 1 , jogo.area_do_jogo.ponto.y - 2 , 1 , jogo.area_do_jogo.altu + 2 , COR_MOLDURA_FUNDO_AREA_JOGO );
        desenRetang( jogo.area_do_jogo.ponto.x + jogo.area_do_jogo.larg , jogo.area_do_jogo.ponto.y , 1 , jogo.area_do_jogo.altu , COR_MOLDURA_FUNDO_AREA_JOGO );
}
//#####################################################



/** \brief Desenha os obstáculos do jogo
 *
 * \param JOGO
 * \return void
 *
 */
void desenhaObstaculos( JOGO jogo ){
        int caractere;

        defCorTxt_PRO( COR_OBSTACULOS , COR_FUNDO_AREA_JOGO , PADRAO );
        for( int i = 1 ; i < ALTU_AREA_DO_JOGO - 1 ; i++ )
                for( int j = 1 ; j < LARG_AREA_DO_JOGO - 1 ; j++ ){
                        switch( jogo.level[ jogo.snake.level ].matriz[ i ][ j ] ){
                                case ' ': caractere = ' '; break;
                                case 'h': caractere = '\315'; break;
                                case 'v': caractere = '\272'; break;
                                case 'q': caractere = '\311'; break;
                                case 'e': caractere = '\273'; break;
                                case 'z': caractere = '\310'; break;
                                case 'c': caractere = '\274'; break;
                                case 'w': caractere = '\313'; break;
                                case 'x': caractere = '\312'; break;
                                default: caractere = '?';
                        }
                        if( caractere != ' ' ) defCorTxtFundo( COR_FUNDO_OBSTACULOS );

                        cursorXY( jogo.area_do_jogo.ponto.x + j , jogo.area_do_jogo.ponto.y + i );
                        printf("%c" , caractere );

                        if( caractere != ' ' ) defCorTxtFundo( COR_FUNDO_AREA_JOGO );
                }
}
//#####################################################



/** \brief Desenha os alimentos da snake
 *
 * \param JOGO
 * \return void
 *
 */
void desenhaAlimento( JOGO jogo ){
        if( jogo.alimento.ativo == true )
                putcColoridoXY( CARACTERE_ALIMENTO , jogo.alimento.pos.x ,  jogo.alimento.pos.y , COR_ALIMENTO );
}
//#####################################################



/** \brief Desenha o título do jogo na partida
 *
 * \param JOGO
 * \return void
 *
 */
void desenhaTituloSnake( JOGO jogo ){

        // Título
        printFonte(
                "SNAKE" ,
                jogo.res.fonte_big ,
                (PONTO){ (int)( ( jogo.tela.cols - 44 ) / (float)2 ) , 3 } ,
                3 ,
                COR_TEXTO_TITULO_PARTIDA ,
                COR_FUNDO_TITULO_PARTIDA
        );

        // Autor
        print_PRO(
                "by Narciso Filho" ,
                (PONTO){ 47 + (int)( ( jogo.tela.cols - 44 ) / (float)2 )  , 8 } ,
                PADRAO ,
                COR_TEXTO_TITULO_PARTIDA ,
                COR_FUNDO_AREA_EXTERNA
        );

        // Quadro do Level
        desenMoldura_R(
                (RETANG){ { jogo.area_do_jogo.ponto.x , 9 } , 12 , 3 } ,
                COR_MOLDURA_AREA_JOGO ,
                COR_MOLDURA_FUNDO_AREA_JOGO ,
                false
        );
        print_PRO( "LEVEL" , (PONTO){ jogo.area_do_jogo.ponto.x + 3 , 9 } , PADRAO , COR_TEXTO_PONTOS_LEVEL , COR_MOLDURA_FUNDO_AREA_JOGO );

        // Quadro de Pontos
        desenMoldura_R(
                (RETANG){ { jogo.area_do_jogo.ponto.x + 12 , 9 } , 12 , 3 } ,
                COR_MOLDURA_AREA_JOGO ,
                COR_MOLDURA_FUNDO_AREA_JOGO ,
                false
        );
        print_PRO( "PONTOS" , (PONTO){ jogo.area_do_jogo.ponto.x + 15 , 9 } , PADRAO , COR_TEXTO_PONTOS_LEVEL , COR_MOLDURA_FUNDO_AREA_JOGO );

        // Quinas
        putc_PRO( '\303' , (PONTO){ jogo.area_do_jogo.ponto.x , jogo.area_do_jogo.ponto.y } , COR_MOLDURA_AREA_JOGO , COR_MOLDURA_FUNDO_AREA_JOGO , PADRAO );
        putc_PRO( '\301' , (PONTO){ jogo.area_do_jogo.ponto.x + 11 , jogo.area_do_jogo.ponto.y } , COR_MOLDURA_AREA_JOGO , COR_MOLDURA_FUNDO_AREA_JOGO , PADRAO );
        putc_PRO( '\301' , (PONTO){ jogo.area_do_jogo.ponto.x + 12 , jogo.area_do_jogo.ponto.y } , COR_MOLDURA_AREA_JOGO , COR_MOLDURA_FUNDO_AREA_JOGO , PADRAO );
        putc_PRO( '\301' , (PONTO){ jogo.area_do_jogo.ponto.x + 23 , jogo.area_do_jogo.ponto.y } , COR_MOLDURA_AREA_JOGO , COR_MOLDURA_FUNDO_AREA_JOGO , PADRAO );
}
//#####################################################



/** \brief Desenha DEBUGGER
 *
 * \param JOGO
 * \return void
 *
 */
void desenhaDEBUGGER( JOGO jogo ){
        cursorXY( 2 , 2 );
        printf("delay: %d" , LATENCIA_ATUALIZACAO );
        cursorXY( 2 , 3 );
        printf("dific: %d" , jogo.snake.dificuldade );
        cursorXY( 2 , 4 );
        printf("tam: %d" , jogo.snake.tam );
}
//#####################################################




