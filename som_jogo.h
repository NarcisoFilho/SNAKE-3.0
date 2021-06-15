#ifndef __SOM_JOGO_H_
#define __SOM_JOGO_H_

        void som_seta_menu( void );
        void som_enter_menu( void );
        void som_esc_menu( void );
        void iniciar_sistema_som_jogo( void );
        void encerrar_sistema_som_jogo( void );
        void sincronizarSomJogo( JOGO* , char* );

        void musica_novo_level( void );
        void musica_portal( void );
        void musica_game_over( void );
        void musica_coleta_alimento( void );
        void musica_coleta_dinheiro( void );

#endif // __SOM_JOGO_H_
