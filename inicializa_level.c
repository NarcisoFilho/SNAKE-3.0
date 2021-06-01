

#include "definicoes_jogo.h"

/** \brief Incializa novo level
 *
 * \param JOGO*
 * \return void
 *
 */
void inicializarNovoLevel( JOGO* jogo ){
        inicializarSnake_NovoLevel( jogo );
        inicializarFlags_NovoLevel( jogo );
        inicializarItemsDeColeta_NovoLevel( jogo );
}
//#####################################################



/** \brief Reinicializa a variável SNAKE para novo level
 *
 * \param SNAKE*
 * \return void
 *
 */
void inicializarSnake_NovoLevel( JOGO* jogo ){
        jogo->snake.pos[ 0 ].x = jogo->area_do_jogo.ponto.x + 9;
        jogo->snake.pos[ 0 ].y = jogo->area_do_jogo.ponto.y + ( jogo->area_do_jogo.altu ) / 2;
        jogo->snake.sentido = DIREITA;
        jogo->snake.tam = 5;
}
//#####################################################



/** \brief Reinicializa as FLAGS para novo level
 *
 * \param SNAKE*
 * \return void
 *
 */
void inicializarFlags_NovoLevel( JOGO* jogo ){
        jogo->flag_level_desenho_unico = true;
        jogo->flag_level_desenho_esporadico = true;
        jogo->snake.tam = 5;
}
//#####################################################



/** \brief Reinicializa os ITEMS COLETÁVEIS para novo level
 *
 * \param SNAKE*
 * \return void
 *
 */
void inicializarItemsDeColeta_NovoLevel( JOGO* jogo ){
        jogo->alimento.ativo = false;
}
//#####################################################
