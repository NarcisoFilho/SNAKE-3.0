

#include "definicoes_jogo.h"



/** \brief Gerencia as funções de desenho do jogo
 *
 * \param JOGO
 * \return void
 *
 */
void desenhaJogo( JOGO* jogo ){
        // Desenho Único
        if( jogo->flag_level_desenho_unico ){
                desenhaAreaDoJogo( jogo );
                desenhaObstaculos( jogo );
                desenhaTituloSnake( jogo );
                desenhaIndicadorLevelAtual( jogo );
        }
        // Desenho Esporádico
        if( jogo->flag_level_desenho_esporadico ){
                desenhaQtdPontos( jogo );
                desenhaAlimento( jogo );
        }

        // Atualização Constante
        if( jogo->flag_level_desenho_volatil ){
                desenhaSnake( jogo );
                if( jogo->flag_modo_de_teste ) desenhaDEBUGGER( jogo );
        }

        // Atualização Independente
        desenhaPortal( jogo );
        desenhaDinheiro( jogo );
}
//#####################################################



/** \brief Desenha a SNAKE
 *
 * \param JOGO
 * \return void
 *
 */
void desenhaSnake( JOGO* jogo ){
        // BLOCO FRONTAL
        desenRetang( jogo->snake.pos[ 0 ].x , jogo->snake.pos[ 0 ].y, 2 , 1 , jogo->snake.cor );

        // APAGAR BLOCO FINAL
        desenRetang( jogo->snake.pos[ jogo->snake.tam - 1 ].x , jogo->snake.pos[ jogo->snake.tam - 1 ].y, 2 , 1 , COR_FUNDO_AREA_JOGO );

}
//#####################################################


/** \brief Desenha a moldura do jogo
 *
 * \param JOGO
 * \return void
 *
 */
void desenhaAreaDoJogo( JOGO* jogo ){
        desenRetang( 0 , 0 , jogo->tela.cols , jogo->tela.lins , COR_FUNDO_AREA_EXTERNA );        // Limpa Fundo
        desenRetang_R( jogo->area_do_jogo , ' ' , COR_FUNDO_AREA_JOGO , COR_FUNDO_AREA_JOGO );
        desenMoldura_R( jogo->area_do_jogo , COR_MOLDURA_AREA_JOGO , COR_MOLDURA_FUNDO_AREA_JOGO , false );
        desenRetang( jogo->area_do_jogo.ponto.x - 1 , jogo->area_do_jogo.ponto.y - 2 , 1 , jogo->area_do_jogo.altu + 2 , COR_MOLDURA_FUNDO_AREA_JOGO );
        desenRetang( jogo->area_do_jogo.ponto.x + jogo->area_do_jogo.larg , jogo->area_do_jogo.ponto.y , 1 , jogo->area_do_jogo.altu , COR_MOLDURA_FUNDO_AREA_JOGO );
}
//#####################################################



/** \brief Desenha os obstáculos do jogo
 *
 * \param JOGO
 * \return void
 *
 */
void desenhaObstaculos( JOGO* jogo ){
        int caractere;

        defCorTxt_PRO( COR_OBSTACULOS , COR_FUNDO_AREA_JOGO , PADRAO );
        for( int i = 1 ; i < ALTU_AREA_DO_JOGO - 1 ; i++ )
                for( int j = 1 ; j < LARG_AREA_DO_JOGO - 1 ; j++ ){
                        switch( jogo->level[ jogo->snake.level ].matriz[ i ][ j ] ){
                                case ' ': caractere = ' '; break;
                                case 'h': caractere = '\315'; break;
                                case 'v': caractere = '\272'; break;
                                case 'q': caractere = '\311'; break;
                                case 'e': caractere = '\273'; break;
                                case 'z': caractere = '\310'; break;
                                case 'c': caractere = '\274'; break;
                                case 'w': caractere = '\313'; break;
                                case 'x': caractere = '\312'; break;
                                case 'y': caractere = '\316'; break;
                                case 'd': caractere = '\271'; break;
                                case 'a': caractere = '\314'; break;
                                case '-': caractere = ' '; break;
                                case '#': caractere = '#'; break;
                                case 'o': caractere = ' '; break;
                                default: caractere = '?';
                        }
                        if( caractere != ' ' ) defCorTxtFundo( COR_FUNDO_OBSTACULOS );

                        cursorXY( jogo->area_do_jogo.ponto.x + j , jogo->area_do_jogo.ponto.y + i );
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
void desenhaPortal( JOGO* jogo ){
        static COR cor_caractere;
//        static char caracteres_1[ ] = { '\337' , ' ' , ' ' , '\334' };
//        static char caracteres_2[ ] = { ' ' , '\337' , '\334' , ' ' };
        static char caracteres_1[ ] = { '\337' , '\334' , '\337' , '\334' };
        static char caracteres_2[ ] = { '\334' , '\337' , '\334' , '\337' };
        static int i;
        static struct _timeb tempo_anterior;
        struct _timeb tempo;
        _ftime( &tempo );

        if( jogo->portal.ativo ){
                defCorTxt_PRO(  cor_caractere  , COR_FUNDO_PORTAL , PADRAO );
                cursorXY( jogo->portal.pos.x ,  jogo->portal.pos.y );
                printf("%c%c" , caracteres_2[ i ] , caracteres_1[ i ] );

                // Incremento dos contadores
                if( ( tempo.time * 1000 + tempo.millitm ) - ( tempo_anterior.time * 1000 + tempo_anterior.millitm ) >= DELAY_EFEITO_PORTAL ){
                        cor_caractere++;
                        i++;
                        if( cor_caractere == 256 ) cor_caractere = 0;
                        if( i == QTD_CARACTERES_PORTAL ) i = 0;

                        _ftime( &tempo_anterior );
                }

        }

        if( jogo->flag_level_desenho_unico )
                _ftime( &tempo_anterior );
}
//#####################################################



/** \brief Desenha o dinheiro coletável pela snake
 *
 * \param JOGO
 * \return void
 *
 */
void desenhaDinheiro( JOGO* jogo ){
        static int i = 1;
        static struct _timeb tempo_anterior;
        struct _timeb tempo;
        _ftime( &tempo );

        if( jogo->flag_level_desenho_esporadico ) _ftime( &tempo_anterior );

        if( jogo->dinheiro.ativo == true ){
                if( ( tempo.time * 1000  + tempo.millitm ) - ( tempo_anterior.time * 1000 + tempo_anterior.millitm ) >= DELAY_EFEITO_ALIMENTO
                   ||  jogo->flag_level_desenho_esporadico ){

                        if( i ) defCorTxt_PRO( COR_DINHEIRO , COR_DINHEIRO_FUNDO , PADRAO );
                        else defCorTxt_PRO( COR_DINHEIRO_FUNDO , COR_DINHEIRO , PADRAO );

                        cursorXY( jogo->dinheiro.pos.x ,  jogo->dinheiro.pos.y );
                        printf("%c%c" , CARACTERE_DINHEIRO , CARACTERE_DINHEIRO );

                        // Atualiza Contador
                        i = i ? 0 : 1;

                        _ftime( &tempo_anterior );
                }
        }

}
//#####################################################



/** \brief Apaga o desenho do dinheiro
 *
 * \param JOGO
 * \return void
 *
 */
void apagarDinheiro( JOGO* jogo ){
        desenRetang( jogo->dinheiro.pos.x  ,  jogo->dinheiro.pos.y , 2 , 1 , COR_FUNDO_AREA_JOGO );
}
//#####################################################



/** \brief Desenha os alimentos da snake
 *
 * \param JOGO
 * \return void
 *
 */
void desenhaAlimento( JOGO* jogo ){
        if( jogo->alimento.ativo == true ){
                defCorTxt_PRO( COR_ALIMENTO , COR_ALIMENTO_FUNDO , PADRAO );
                cursorXY( jogo->alimento.pos.x ,  jogo->alimento.pos.y );
                printf("%c%c" , CARACTERE_ALIMENTO , CARACTERE_ALIMENTO );
        }
}
//#####################################################



/** \brief Desenha a quantidade de pontos do jogador
 *
 * \param JOGO
 * \return void
 *
 */
void desenhaQtdPontos( JOGO* jogo ){
        desenRetang( jogo->area_do_jogo.ponto.x + 12 + 1 , jogo->area_do_jogo.ponto.y - 1 , 10 , 1 , COR_FUNDO_LEVEL_PONTOS );
        cursorXY( jogo->area_do_jogo.ponto.x + 12 + ( 11 - qtd_dig( jogo->snake.pontos ) ) / 2 , jogo->area_do_jogo.ponto.y - 1 );
        defCorTxt_PRO( COR_PONTOS_LEVEL , COR_FUNDO_LEVEL_PONTOS , PADRAO );
        printf("%d" , jogo->snake.pontos );
        RESET_PADRAO;
}
//#####################################################



/** \brief Desenha o código do level atual
 *
 * \param JOGO
 * \return void
 *
 */
void desenhaIndicadorLevelAtual( JOGO* jogo ){
        desenRetang( jogo->area_do_jogo.ponto.x + 1 , jogo->area_do_jogo.ponto.y - 1 , 10 , 1 , COR_FUNDO_LEVEL_PONTOS );
        cursorXY( jogo->area_do_jogo.ponto.x + ( 11 - qtd_dig( jogo->snake.level ) ) / 2 , jogo->area_do_jogo.ponto.y - 1 );
        defCorTxt_PRO( COR_PONTOS_LEVEL , COR_FUNDO_LEVEL_PONTOS , PADRAO );
        printf("0%d" , jogo->snake.level );
        RESET_PADRAO;
}
//#####################################################



/** \brief Desenha o título do jogo na partida
 *
 * \param JOGO
 * \return void
 *
 */
void desenhaTituloSnake( JOGO* jogo ){

        // Título
        printFonte(
                "SNAKE" ,
                jogo->res.fonte_big ,
                (PONTO){ (int)( ( jogo->tela.cols - 44 ) / (float)2 ) , 3 } ,
                3 ,
                COR_TEXTO_TITULO_PARTIDA ,
                COR_FUNDO_TITULO_PARTIDA
        );

        // Autor
        print_PRO(
                "by Narciso Filho" ,
                (PONTO){ 47 + (int)( ( jogo->tela.cols - 44 ) / (float)2 )  , 8 } ,
                PADRAO ,
                COR_TEXTO_TITULO_PARTIDA ,
                COR_FUNDO_AREA_EXTERNA
        );

        // Quadro do Level
        desenMoldura_R(
                (RETANG){ { jogo->area_do_jogo.ponto.x , 9 } , 12 , 3 } ,
                COR_MOLDURA_AREA_JOGO ,
                COR_MOLDURA_FUNDO_AREA_JOGO ,
                false
        );
        print_PRO( "LEVEL" , (PONTO){ jogo->area_do_jogo.ponto.x + 3 , 9 } , PADRAO , COR_TEXTO_PONTOS_LEVEL , COR_MOLDURA_FUNDO_AREA_JOGO );

        // Quadro de Pontos
        desenMoldura_R(
                (RETANG){ { jogo->area_do_jogo.ponto.x + 12 , 9 } , 12 , 3 } ,
                COR_MOLDURA_AREA_JOGO ,
                COR_MOLDURA_FUNDO_AREA_JOGO ,
                false
        );
        print_PRO( "PONTOS" , (PONTO){ jogo->area_do_jogo.ponto.x + 15 , 9 } , PADRAO , COR_TEXTO_PONTOS_LEVEL , COR_MOLDURA_FUNDO_AREA_JOGO );

        // Quinas
        putc_PRO( '\303' , (PONTO){ jogo->area_do_jogo.ponto.x , jogo->area_do_jogo.ponto.y } , COR_MOLDURA_AREA_JOGO , COR_MOLDURA_FUNDO_AREA_JOGO , PADRAO );
        putc_PRO( '\301' , (PONTO){ jogo->area_do_jogo.ponto.x + 11 , jogo->area_do_jogo.ponto.y } , COR_MOLDURA_AREA_JOGO , COR_MOLDURA_FUNDO_AREA_JOGO , PADRAO );
        putc_PRO( '\301' , (PONTO){ jogo->area_do_jogo.ponto.x + 12 , jogo->area_do_jogo.ponto.y } , COR_MOLDURA_AREA_JOGO , COR_MOLDURA_FUNDO_AREA_JOGO , PADRAO );
        putc_PRO( '\301' , (PONTO){ jogo->area_do_jogo.ponto.x + 23 , jogo->area_do_jogo.ponto.y } , COR_MOLDURA_AREA_JOGO , COR_MOLDURA_FUNDO_AREA_JOGO , PADRAO );
}
//#####################################################



/** \brief Desenha DEBUGGER
 *
 * \param JOGO
 * \return void
 *
 */
void desenhaDEBUGGER( JOGO* jogo ){
        cursorXY( 2 , 2 );
        printf("delay: %d" , DELAY_CICLO_FACIL / _DIFICULDADE );
        cursorXY( 2 , 3 );
        printf("dific: %d" , _DIFICULDADE );
        cursorXY( 2 , 4 );
        printf("tam: %d" , jogo->snake.tam );
        cursorXY( 2 , 5 );
        printf("clk: %d" , jogo->flag_level_desenho_volatil );
        cursorXY( 2 , 6 );
        printf("portal ativo: %d" , jogo->portal.ativo );
        cursorXY( 2 , 7 );
        printf("qtd alim: %d" , jogo->level[ jogo->snake.level ].qtd_alimentos_coletados );

}
//#####################################################



/** \brief Colore a sanke fora do ciclo padrão de desenho volátil
 *
 * \param JOGO*
 * \param COR
 * \return void
 *
 */
void colorirSnake( JOGO* jogo , COR cor ){
        for( int bloco = 0 ; bloco < jogo->snake.tam - 1 ; bloco++ )
                desenRetang( jogo->snake.pos[ bloco ].x , jogo->snake.pos[ bloco ].y , 2 , 1 , jogo->snake.cor );
}
//#####################################################



/** \brief Colore a tela
 *
 * \param JOGO*
 * \param COR
 * \return void
 *
 */
void colorirTela( JOGO* jogo , COR cor ){
        desenRetang( 1 , 1 , jogo->tela.cols , jogo->tela.lins , cor );
}
//#####################################################
