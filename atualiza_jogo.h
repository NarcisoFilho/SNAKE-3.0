#ifndef __ATUALIZA_JOGO_H_
#define __ATUALIZA_JOGO_H_

        #include "definicoes_jogo.h"

        void atualizaJogo( JOGO* );
        void atualizaPosSnake( SNAKE* snake );
        void atualizaSentidoSnake( SNAKE* );

        void verificaPosSnake_limites( JOGO* );

        void atualizarFlagsRedesenho( JOGO* jogo );

#endif // __ATUALIZA_JOGO_H_
