#ifndef __DESENHA_JOGO_H_
#define __DESENHA_JOGO_H_

        #include "definicoes_jogo.h"

        // Master
        void desenhaJogo( JOGO* );

        // Desenho Din�mico
        void desenhaSnake( JOGO* );
        void desenhaDEBUGGER( JOGO* );

        // Desenho Espor�dico
        void desenhaAlimento( JOGO* );
        void desenhaQtdPontos( JOGO* );

        // Desenho �nico
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
        void colorirTela( JOGO* jogo , COR cor );

#endif // __DESENHA_JOGO_H_
