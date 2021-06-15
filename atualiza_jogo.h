#ifndef __ATUALIZA_JOGO_H_
#define __ATUALIZA_JOGO_H_

        #include "definicoes_jogo.h"

        // Master
        void atualizaJogo( JOGO* );

        // Controle de tempo
        void atualizarFlagsRedesenho( JOGO* );

        // Snake
        void atualizaPosSnake( SNAKE* );
        void atualizaSentidoSnake( JOGO* );
        void verificaPosSnake_limites( JOGO* );
        void verificaPosSnake_obstaculos( JOGO* );
        void verificaPosSnake_autoColisao( JOGO* );

        // Coletáveis
        void geraAlimento( JOGO* );
        void geraDinheiro( JOGO* );
        void coletarAlimento( JOGO* );
        void coletarDinheiro( JOGO* );

        // Portal
        void atualizaPortal( JOGO* );

        // Pause
        void atualizaPause( JOGO* );

        // Som
        void atualizarSom( JOGO* );

        // Extras
        void verificarFecharJogoTeclado( void );
        void salvaPontuac( JOGO* );
        void salvaHighScoresArquivo( JOGO* );
        char* coletarNomeJogador( JOGO* );


#endif // __ATUALIZA_JOGO_H_
