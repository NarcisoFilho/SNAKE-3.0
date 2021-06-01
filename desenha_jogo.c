

#include "definicoes_jogo.h"


/** \brief Gerencia as funções de desenho do jogo
 *
 * \param JOGO
 * \return void
 *
 */
void desenhaJogo( JOGO jogo ){

        // Atualização Constante
        desenhaSnake( jogo );

        // Desenho Único
        if( jogo.flag_level_desenho_unico ){
                desenhaAreaDoJogo( jogo );
                desenhaTituloSnake( jogo );
//                desenhaDEBUGGER( jogo );
        }

        // Desenho Esporádico
//        if( jogo.flag_level_desenho_esporadico ){
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



/** \brief Desenha DEBUGGER
 *
 * \param JOGO
 * \return void
 *
 */
void desenhaDEBUGGER( JOGO jogo ){
        defCorTxt_PRO( AZUL , BRANCO_BRILHANTE , SUBLINHADO );
        cursorXY( 10 , 42 );
        printf("TAM: %d " , jogo.snake.tam );
        RESET_PADRAO;
//        defCorTxt_PRO( AZUL , BRANCO_BRILHANTE , SUBLINHADO );
//        cursorXY( 10 , 42 );
//        printf("RESOLUCAO ATUAL: ( %d , %d )" , jogo.tela.resolucao.x , jogo.tela.resolucao.y );
//        cursorXY( 10 , 43 );
//        printf("ESCALA: ( %lf , %lf )" , jogo.tela.escalaX , jogo.tela.escalaY );
//        cursorXY( 10 , 44 );
//        printf("ESCALA: ( %d , %d )" , dtoi( jogo.tela.escalaX ) , dtoi( jogo.tela.escalaY ) );
//        cursorXY( 10 , 45 );
//        printf("QTD CASAS: ( %d , %d )" , jogo.tela.cols , jogo.tela.lins );
//        RESET_PADRAO;
//        defCorTxt( AMARELO_CLARO );
//        cursorXY( 3 , 3 );
//
//        if( jogo.snake.sentido == DIREITA )
//                printf("DIREITA_");
//
//        if( jogo.snake.sentido == ESQUERDA )
//                printf("ESQUERDA");
//
//        if( jogo.snake.sentido == BAIXO )//                printf("BAIXO___");
//
//        if( jogo.snake.sentido == CIMA )
//                printf("CIMA____");
//
//        cursorXY( 10 , 20 );
////        printf("cos = %d      |    sin = %d" , (int)cos( jogo.snake.sentido )  , (int)sin( jogo.snake.sentido ) );
//        cursorXY( 10 , 21 );
//        printf("DIR cos = %d      |    sin = %d" , (int)cos( 0 )  , (int)sin( 0 ) );
//        cursorXY( 10 , 22 );//        printf("CIM cos = %d      |    sin = %d" , (int)cos( PI / 2 )  , (int)sin( PI / 2 ) );
//        cursorXY( 10 , 23 );
//        printf("ESQ cos = %d      |    sin = %d" , (int)cos( PI )  , (int)sin( PI ) );
//        cursorXY( 10 , 24 );
//        printf("BAI cos = %d      |    sin = %d" , (int)cos( 3 * PI / 2 )  , (int)sin( 3 * PI / 2 ) );
//

//        cursorXY( 10 , 26 );
//        defCorTxt( ROSA_CHOQUE );
//        printf("POS ( %d , %d )" , jogo.snake.pos[ 0 ].x , jogo.snake.pos[ 0 ].y );
//        cursorXY( 10 , 27 );
//        defCorTxt( LARANJA );
//        printf("SENTIDO  %f " , jogo.snake.sentido );
//        RESET_PADRAO;
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
        printColoridoXY(
                "by Narciso Filho" ,
                47 + (int)( ( jogo.tela.cols - 44 ) / (float)2 )  ,
                8 ,
                COR_TEXTO_TITULO_PARTIDA
        );

        // Quadro do Level
        desenMoldura_R(
                (RETANG){ { jogo.area_do_jogo.ponto.x , 9 } , 12 , 3 } ,
                COR_MOLDURA_AREA_JOGO ,
                COR_MOLDURA_FUNDO_AREA_JOGO ,
                false
        );
        print_PRO( "LEVEL" , (PONTO){ jogo.area_do_jogo.ponto.x + 3 , 9 } , PADRAO , VERDE_LIMA , COR_MOLDURA_FUNDO_AREA_JOGO );

        // Quadro de Pontos
        desenMoldura_R(
                (RETANG){ { jogo.area_do_jogo.ponto.x + 12 , 9 } , 12 , 3 } ,
                COR_MOLDURA_AREA_JOGO ,
                COR_MOLDURA_FUNDO_AREA_JOGO ,
                false
        );
        print_PRO( "PONTOS" , (PONTO){ jogo.area_do_jogo.ponto.x + 15 , 9 } , PADRAO , VERDE_LIMA , COR_MOLDURA_FUNDO_AREA_JOGO );

        // Quinas
        putc_PRO( '\303' , (PONTO){ jogo.area_do_jogo.ponto.x , jogo.area_do_jogo.ponto.y } , COR_MOLDURA_AREA_JOGO , COR_MOLDURA_FUNDO_AREA_JOGO , PADRAO );
        putc_PRO( '\301' , (PONTO){ jogo.area_do_jogo.ponto.x + 11 , jogo.area_do_jogo.ponto.y } , COR_MOLDURA_AREA_JOGO , COR_MOLDURA_FUNDO_AREA_JOGO , PADRAO );
        putc_PRO( '\301' , (PONTO){ jogo.area_do_jogo.ponto.x + 12 , jogo.area_do_jogo.ponto.y } , COR_MOLDURA_AREA_JOGO , COR_MOLDURA_FUNDO_AREA_JOGO , PADRAO );
        putc_PRO( '\301' , (PONTO){ jogo.area_do_jogo.ponto.x + 23 , jogo.area_do_jogo.ponto.y } , COR_MOLDURA_AREA_JOGO , COR_MOLDURA_FUNDO_AREA_JOGO , PADRAO );
}
//#####################################################



