
#include "definicoes_jogo.h"


/** \brief Checa se ocorreu um game over
 *
 * \param JOGO
 * \return BOOL : True se fim de jogo , false se jogo continua
 *
 */
BOOL checaGameOver( JOGO jogo ){
        if( !jogo.snake.viva )
                return true;
        return false;
}
//#####################################################



/** \brief Checa se jogador zerou
 *
 * \param JOGO
 * \return BOOL : True se jogo zerado , false se jogo continua
 *
 */
BOOL checaJogoZerado( JOGO jogo ){
        if( jogo.snake.level > QTD_LEVELs )
                return true;
        return false;
}
//#####################################################



/** \brief Checa se jogador completou level
 *
 * \param JOGO
 * \return BOOL : True se leve finalizado , false se ainda não
 *
 */
BOOL checaNovoLevel( JOGO jogo ){
        if( jogo.snake.flag_level_finalizado )
                return true;

        return false;
}
//#####################################################
