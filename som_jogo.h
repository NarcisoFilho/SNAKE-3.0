#ifndef __SOM_JOGO_H_
#define __SOM_JOGO_H_

        void iniciar_sistema_som_jogo( void );
        void encerrar_sistema_som_jogo( void );
        void sincronizarSomJogo( JOGO* , char* );

        void musica_novo_level( void );
        void musica_portal( void );
        void musica_game_over( void );
        void musica_coleta_alimento( void );
        void musica_adios( void );
        void musica_vitoria( void );

#endif // __SOM_JOGO_H_
