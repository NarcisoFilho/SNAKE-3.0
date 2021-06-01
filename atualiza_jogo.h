#ifndef __ATUALIZA_JOGO_H_
#define __ATUALIZA_JOGO_H_

        #include "definicoes_jogo.h"

        void atualizaJogo( JOGO* );

        void atualizaPosSnake( SNAKE* snake );

        void atualizaSentidoSnake( SNAKE* );

        void verificaPosSnake_limites( JOGO* );
        void verificaPosSnake_obstaculos( JOGO* jogo );

        void atualizarFlagsRedesenho( JOGO* );

        void geraAlimento( JOGO* );

#endif // __ATUALIZA_JOGO_H_
