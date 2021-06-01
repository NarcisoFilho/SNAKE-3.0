

#include "definicoes_jogo.h"


/** \brief Atualiza o jogo
 *
 * \param JOGO*
 * \return void
 *
 */
void atualizaJogo( JOGO* jogo ){

        // Liberação de Redesenho
        atualizarFlagsRedesenho( jogo );

        // SNAKE
        atualizaSentidoSnake( &jogo->snake );
        if( jogo->flag_level_desenho_volatil ){
                atualizaPosSnake( &jogo->snake );
                verificaPosSnake_limites( jogo );
                verificaPosSnake_obstaculos( jogo );

                if( checaTecla_Pressionada( VK_INSERT ) )
                        jogo->snake.tam += 1;
        }

        // ALIMENTO
        geraAlimento( jogo );
}
//#####################################################


/** \brief Atualiza a snake
 *
 * \param SNAKE*
 * \return void
 *
 */
void atualizaPosSnake( SNAKE* snake ){
        // Posição dos blocos do corpo ( Cada bloco ocupa a posição do bloco subsequente da snake )
        for( int i = snake->tam - 1 ;  i ; i-- ){
                snake->pos[ i ].x = snake->pos[ i - 1 ].x;
                snake->pos[ i ].y = snake->pos[ i - 1 ].y;
        }

        // Posição do bloco frontal
        snake->pos[ 0 ].x += 2 * dtoi( cos( gtor( snake->sentido ) ) );
        snake->pos[ 0 ].y -= dtoi( sin( gtor( snake->sentido ) ) );
}
//#####################################################


/** \brief Verifica se a posição da snake ultrapassa os limites
 *
 * \param JOGO*
 * \return void
 *
 */
void verificaPosSnake_limites( JOGO* jogo ){
        // Limite Lateral DIREITO
        if( jogo->snake.pos[ 0 ].x  >= jogo->area_do_jogo.ponto.x + jogo->area_do_jogo.larg - 1 )
                jogo->snake.pos[ 0 ].x = jogo->area_do_jogo.ponto.x + 1;

        // Limite Lateral ESQUERDO
        if( jogo->snake.pos[ 0 ].x  <= jogo->area_do_jogo.ponto.x )
                jogo->snake.pos[ 0 ].x = jogo->area_do_jogo.ponto.x + jogo->area_do_jogo.larg - 3;

        // Limite INFERIOR
        if( jogo->snake.pos[ 0 ].y  >= jogo->area_do_jogo.ponto.y + jogo->area_do_jogo.altu - 1 )
                jogo->snake.pos[ 0 ].y = jogo->area_do_jogo.ponto.y + 1;

        // Limite SUPERIOR
        if( jogo->snake.pos[ 0 ].y  <= jogo->area_do_jogo.ponto.y )
                jogo->snake.pos[ 0 ].y = jogo->area_do_jogo.ponto.y + jogo->area_do_jogo.altu - 2;
}
//#####################################################


/** \brief Verifica se o bloco frontal da snake atinge obstáculo
 *
 * \param JOGO*
 * \return void
 *
 */
void verificaPosSnake_obstaculos( JOGO* jogo ){
        switch( dtoi( cos( gtor( jogo->snake.sentido ) ) ) ){
                case 1:         /*DIREITA*/
                        if( jogo->level[ jogo->snake.level ].matriz[ jogo->snake.pos[ 0 ].y - jogo->area_do_jogo.ponto.y ][ jogo->snake.pos[ 0 ].x + 1 - jogo->area_do_jogo.ponto.x ] != ' ' ){
                                pausaS(1);
                                jogo->snake.pos[ 0 ].x -= 2;
                        }
                        break;
                case -1:        /* ESQUERDA */
                        if( jogo->level[ jogo->snake.level ].matriz[ jogo->snake.pos[ 0 ].y - jogo->area_do_jogo.ponto.y ][ jogo->snake.pos[ 0 ].x - jogo->area_do_jogo.ponto.x ] != ' ' ){
                                pausaS(1);
                                jogo->snake.pos[ 0 ].x += 2;
                        }
                        break;
                case 0:
                        switch( dtoi( sin( gtor( jogo->snake.sentido ) ) ) ){
                                case 1:         /* CIMA */
                                        if( jogo->level[ jogo->snake.level ].matriz[ jogo->snake.pos[ 0 ].y - jogo->area_do_jogo.ponto.y ][ jogo->snake.pos[ 0 ].x - jogo->area_do_jogo.ponto.x ] != ' ' ){
                                                pausaS(1);
                                                jogo->snake.pos[ 0 ].y += 1;
                                        }
                                        break;
                                case -1:        /* BAIXO */
                                        if( jogo->level[ jogo->snake.level ].matriz[ jogo->snake.pos[ 0 ].y - jogo->area_do_jogo.ponto.y ][ jogo->snake.pos[ 0 ].x - jogo->area_do_jogo.ponto.x ] != ' ' ){
                                                pausaS(1);
                                                jogo->snake.pos[ 0 ].y -= 1;
                                        }
                                        break;
                        }

        }
}
//#####################################################


/** \brief Atualiza o sentido da  snake
 *
 * \param SNAKE*
 * \return void
 *
 */
void atualizaSentidoSnake( SNAKE* snake ){

        if( checaTecla_Pressionada( VK_UP ) )
                if( snake->pos[ 1 ].y != snake->pos[ 0 ].y - 1  )
                        if( snake->sentido != BAIXO ){
                                        snake->sentido = CIMA;
                                        return;
                        }

        if( checaTecla_Pressionada( VK_DOWN ) )
                if( snake->pos[ 1 ].y != snake->pos[ 0 ].y + 1  )
                        if( snake->sentido != CIMA ){
                                        snake->sentido = BAIXO;
                                        return;
                        }

        if( checaTecla_Pressionada( VK_LEFT ) )
                if( snake->pos[ 1 ].x != snake->pos[ 0 ].x - 1  )
                        if( snake->sentido != DIREITA ){
                                        snake->sentido = ESQUERDA;
                                        return;
                        }
        if( checaTecla_Pressionada( VK_RIGHT ) )
                if( snake->pos[ 1 ].x != snake->pos[ 0 ].x + 1  )
                        if( snake->sentido != ESQUERDA ){
                                        snake->sentido = DIREITA;
                                        return;
                        }}
//#####################################################



/** \brief Atualiza as flags de redesenho
 *      Aciona o redesenho do elementos de atualização esporádica quando necessário
 *
 * \param JOGO*
 * \return void
 *
 */
void atualizarFlagsRedesenho( JOGO* jogo ){
        struct _timeb tempo;
        _ftime( &tempo );

        if( !( ( tempo.time * 1000 + tempo.millitm ) % DELAY_CICLO_MAXIMO ) ){
                jogo->flag_level_desenho_volatil = true;
        }else
                jogo->flag_level_desenho_volatil = false;

        if( jogo->flag_level_desenho_unico )
                jogo->flag_level_desenho_unico = false;


}
//#####################################################



/** \brief Gera os alimentos da SNAKE
 *
 * \param JOGO* jogo
 * \return void
 *
 */
void geraAlimento( JOGO* jogo ){
        FLAG pos_liberada;

        if( jogo->alimento.ativo == false )
                if( jogo->level[ jogo->snake.level ].qtd_alimentos_coletados < QTD_ALIMENTOS_FINALIZAR_LEVEL ){
                        do{
                                jogo->alimento.pos.x = nmrRand( jogo->area_do_jogo.ponto.x + 1 , jogo->area_do_jogo.ponto.x + jogo->area_do_jogo.larg - 2 );
                                jogo->alimento.pos.y = nmrRand( jogo->area_do_jogo.ponto.y + 1 , jogo->area_do_jogo.ponto.y + jogo->area_do_jogo.altu - 2 );

                                pos_liberada = true;

                                // Verificando Distanciamento do ponto de geração do alimento à Snake
                                for( int bloco = 0 ; bloco < jogo->snake.tam ; bloco++ )
                                        if( jogo->alimento.pos.y == jogo->snake.pos[ bloco ].y )
                                                if( abs( jogo->alimento.pos.x - jogo->snake.pos[ bloco ].x ) < 2 )
                                                        pos_liberada = false;
                                // Verificando Não Sobreposição com obstáculo
                                if( jogo->level[ jogo->snake.level ]
                                   .matriz[ jogo->alimento.pos.y - jogo->area_do_jogo.ponto.y ]
                                   [ jogo->alimento.pos.x - jogo->area_do_jogo.ponto.x ] != ' ' )
                                                pos_liberada = false;

                        }while( pos_liberada == false );

                        jogo->alimento.ativo = true;
                }

}
