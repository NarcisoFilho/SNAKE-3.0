
#include "Narconio/narconio.h"
#include "definicoes_jogo.h"

/** \brief Fun��o principal do jogo
 *
 * \param void
 * \return void
 *
 */
int main(){
        // Vari�veis
        JOGO jogo;              // TELA + SNAKE

        // Inicializa��o
        inicializarJanela();            // Ativa modo janela ANSI, se necess�rio

        configurarPreJogo( &jogo );

        inicializarPrePartida( &jogo );    // Reinicializa os dados da SNAKE de da tela de partida

        do{
                desenhaJogo( jogo );
                atualizaJogo( &jogo );
        }while( 1 );

        finalizarJanela();
        return 0;
}
//#####################################################




