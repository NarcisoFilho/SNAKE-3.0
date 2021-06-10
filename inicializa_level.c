

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
        inicializarPortal( jogo );
}
//#####################################################



/** \brief Reinicializa a vari�vel SNAKE para novo level
 *
 * \param SNAKE*
 * \return void
 *
 */
void inicializarSnake_NovoLevel( JOGO* jogo ){
        jogo->snake.sentido = DIREITA;
        jogo->snake.tam = 5;
        jogo->snake.flag_level_finalizado = false;
        for( int j = 0 ; j < jogo->snake.tam ; j++ )
                jogo->snake.pos[ j ].x = jogo->area_do_jogo.ponto.x + jogo->level[ jogo->snake.level ].origem_snake.x - 2 * j;

        for( int i = 0 ; i < jogo->snake.tam ; i++ )
                jogo->snake.pos[ i ].y = jogo->area_do_jogo.ponto.y + jogo->level[ jogo->snake.level ].origem_snake.y;
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



/** \brief Reinicializa os ITEMS COLET�VEIS para novo level
 *
 * \param SNAKE*
 * \return void
 *
 */
void inicializarItemsDeColeta_NovoLevel( JOGO* jogo ){
        jogo->alimento.ativo = false;
        jogo->dinheiro.ativo = false;
        jogo->level[ jogo->snake.level ].qtd_alimentos_coletados = 0;
}
//#####################################################



/** \brief Reinicializa o portal do level
 *
 * \param JOGO*
 * \return void
 *
 */
void inicializarPortal( JOGO* jogo ){
        // Definir portal intaivo. S� � liberado ap�s a coleta de QTD_ALIMENTOS_LIBERAR alimentos
        jogo->portal.ativo = false;

        // Definir posi��o rand�mica no mapa
        FLAG pos_valida;
        do{
                pos_valida = true;

                // Atribuir Posi��o Rand�mica
                jogo->portal.pos.x = nmrRand( jogo->area_do_jogo.ponto.x + 1 , jogo->area_do_jogo.ponto.x + jogo->area_do_jogo.larg - 2 );
                jogo->portal.pos.y = nmrRand( jogo->area_do_jogo.ponto.y + 1 , jogo->area_do_jogo.ponto.y + jogo->area_do_jogo.altu - 2 );

                // Testar Validade em rela��o aos obst�culos
                if( jogo->level[ jogo->snake.level ].
                   matriz[ jogo->portal.pos.y - jogo->area_do_jogo.ponto.y  ][ jogo->portal.pos.x - jogo->area_do_jogo.ponto.x  ] != ' ' )
                        pos_valida = false;

                // Testar Validade em rela��o � pr�pria snake
                for( int bloco = 0 ; bloco < jogo->snake.tam ; bloco++ )
                        if( abs( jogo->snake.pos[ bloco ].x - jogo->portal.pos.x ) < 2 )
                                if( abs( jogo->snake.pos[ bloco ].y - jogo->portal.pos.y ) < 2 )
                                        pos_valida = false;

                // Testar Validade em rela��o � paridade do bloco
                if( jogo->portal.pos.x % 2  !=  ( jogo->area_do_jogo.ponto.x + 1) % 2 )
                                pos_valida = false;


        }while( pos_valida == false);
}
//#####################################################
