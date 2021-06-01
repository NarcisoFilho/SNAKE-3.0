
#include "definicoes_jogo.h"


/** \brief Inicializa a partida
 *
 * \param JOGO*
 * \return void
 *
 */
void inicializarPrePartida( JOGO* jogo ){

        inicializarSnake( jogo );       // Reinicializa os dados da SNAKE

        jogo->flag_level_desenho_unico = true;
        jogo->flag_level_desenho_esporadico = true;
}
//#####################################################


/** \brief Reinicializa a variável SNAKE
 *
 * \param SNAKE*
 * \return void
 *
 */
void inicializarSnake( JOGO* jogo ){
        jogo->snake.level = 0;
        jogo->snake.pontos = 0;
        jogo->snake.pos[ 0 ].x = jogo->area_do_jogo.ponto.x + 9;
        jogo->snake.pos[ 0 ].y = jogo->area_do_jogo.ponto.y + ( jogo->area_do_jogo.altu ) / 2;
        jogo->snake.sentido = DIREITA;
        jogo->snake.tam = 5;
        jogo->snake.dificuldade = 1;
}
//#####################################################



