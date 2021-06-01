
#include "Narconio/narconio.h"
#include "definicoes_jogo.h"

/** \brief Função principal do jogo
 *
 * \param void
 * \return void
 *
 */
int main(){
        // Variáveis
        JOGO jogo;              // TELA + SNAKE

        // Inicialização
        inicializarJanela();            // Ativa modo janela ANSI, se necessário

        configurarPreJogo( &jogo );

        inicializarPrePartida( &jogo );    // Reinicializa os dados da SNAKE de da tela de partida

        do{
                desenhaJogo( jogo );
                atualizaJogo( &jogo );
                Sleep( 45 );
        }while( 1 );

        finalizarJanela();
        return 0;
}
//#####################################################




