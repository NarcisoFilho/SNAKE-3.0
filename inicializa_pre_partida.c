
#include "definicoes_jogo.h"


/** \brief Inicializa a partida
 *
 * \param JOGO*
 * \return void
 *
 */
void inicializarPrePartida( JOGO* jogo ){

        inicializarSnake_PrePartida( jogo );       // Reinicializa os dados da SNAKE
        srand( time( NULL ) );          // Reinicia semente do gerador randômico
}
//#####################################################



/** \brief Reinicializa a variável SNAKE para nova partida
 *
 * \param SNAKE*
 * \return void
 *
 */
void inicializarSnake_PrePartida( JOGO* jogo ){
        jogo->snake.viva = true;
        jogo->snake.pos[ 0 ].x = jogo->area_do_jogo.ponto.x + 10;
        jogo->snake.pos[ 0 ].y = jogo->area_do_jogo.ponto.y + jogo->area_do_jogo.altu / 2;
        jogo->snake.pontos = 0;
        jogo->snake.dificuldade = jogo->dificuldade_escolhida;
        jogo->snake.cor = COR_SNAKE_PADRAO;
        jogo->snake.level = 1;
}
//#####################################################



