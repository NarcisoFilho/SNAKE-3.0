#ifndef __DESENHA_JOGO_H_
#define __DESENHA_JOGO_H_

        #include "definicoes_jogo.h"

        // Master
        void desenhaJogo( JOGO* );

        // Desenho Dinâmico
        void desenhaSnake( JOGO* );
        void desenhaDEBUGGER( JOGO* );

        // Desenho Esporádico
        void desenhaAlimento( JOGO* );
        void desenhaQtdPontos( JOGO* );

        // Desenho Único
        void desenhaAreaDoJogo( JOGO* );
        void desenhaObstaculos( JOGO* );
        void desenhaTituloSnake( JOGO* );
        void desenhaIndicadorLevelAtual( JOGO* );

        // Desenho Independente
        void desenhaPortal( JOGO* );
        void desenhaDinheiro( JOGO* );

        // Extras
        void apagarDinheiro( JOGO* );
        void colorirSnake( JOGO* , COR );

#endif // __DESENHA_JOGO_H_
