

#include "definicoes_jogo.h"


/** \brief Atualiza o jogo
 *
 * \param JOGO*
 * \return void
 *
 */
void atualizaJogo( JOGO* jogo ){
        // SNAKE
        atualizaSentidoSnake( &jogo->snake );

        atualizaPosSnake( &jogo->snake );

        verificaPosSnake_limites( jogo );

        if( checaTecla_Pressionada( VK_INSERT ) )
                jogo->snake.tam++;

        // Liberação de Redesenho
        atualizarFlagsRedesenho( jogo );
}
//#####################################################


/** \brief Atualiza a snake
 *
 * \param SNAKE*
 * \return void
 *
 */
void atualizaPosSnake( SNAKE* snake ){
        static long int delay_atualizacao = 0;    // Delay de atualizacao da snake


        // Incremento da posição
//        if( !delay_atualizacao ){
                // Posição dos blocos do corpo ( Cada bloco ocupa a posição do bloco subsequente da snake )
                for( int i = snake->tam - 1 ;  i ; i-- ){
                        snake->pos[ i ].x = snake->pos[ i - 1 ].x;
                        snake->pos[ i ].y = snake->pos[ i - 1 ].y;
                }

                // Posição do bloco frontal
                snake->pos[ 0 ].x += 2 * dtoi( cos( gtor( snake->sentido ) ) );
                snake->pos[ 0 ].y -= dtoi( sin( gtor( snake->sentido ) ) );

                delay_atualizacao = LATENCIA_ATUALIZACAO;
//        }

        // Decremento do delay
        delay_atualizacao--;
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


/** \brief Atualiza o sentido da  snake
 *
 * \param SNAKE*
 * \return void
 *
 */
void atualizaSentidoSnake( SNAKE* snake ){

        if( checaTecla_Pressionada( VK_UP ) )
                if( snake->sentido != BAIXO ){
//                        if( unicaSeta_Down( VK_UP ) ){
                                snake->sentido = CIMA;
                                return;
                        }

        if( checaTecla_Pressionada( VK_DOWN ) )
                if( snake->sentido != CIMA ){
//                        if( unicaSeta_Down( VK_DOWN ) ){
                                snake->sentido = BAIXO;
                                return;
                        }

        if( checaTecla_Pressionada( VK_LEFT ) )
                if( snake->sentido != DIREITA ){
//                                if( unicaSeta_Down( VK_LEFT ) ){
                                snake->sentido = ESQUERDA;
                                return;
                        }
        if( checaTecla_Pressionada( VK_RIGHT ) )
                if( snake->sentido != ESQUERDA ){
//                        if( unicaSeta_Down( VK_RIGHT ) ){
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
        if( jogo->flag_level_desenho_unico )
                jogo->flag_level_desenho_unico = false;
}
//#####################################################
