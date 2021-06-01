#ifndef __INICIALIZA_PRE_JOGO_H_
#define __INICIALIZA_PRE_JOGO_H_

        #include "definicoes_jogo.h"

        // PRÉ-JOGO
        void configurarPreJogo( JOGO* jogo );
        void configurarTela( TELA* );
        void desabilitarEdicaoRapida( HWND );
        void ativarTelaCheia( void );
        void configurarAreaDoJogo( JOGO* );
        void carregarRecursos( JOGO* jogo );
        PONTO ObterResolucaoMonitor( void );



#endif // __INICIALIZA_PRE_JOGO_H_
