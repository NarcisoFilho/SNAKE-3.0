
#include "definicoes_jogo.h"


/** \brief Inicializa a partida
 *
 * \param JOGO*
 * \return void
 *
 */
void inicializarPrePartida( JOGO* jogo ){

        inicializarSnake_PrePartida( jogo );       // Reinicializa os dados da SNAKE
}
//#####################################################



/** \brief Reinicializa a variável SNAKE para nova partida
 *
 * \param SNAKE*
 * \return void
 *
 */
void inicializarSnake_PrePartida( JOGO* jogo ){
        jogo->snake.level = 2;
        jogo->snake.pontos = 0;
        jogo->snake.dificuldade = jogo->dificuldade_escolhida;
}
//#####################################################



