
#include "definicoes_jogo.h"

/** \brief Emite beep das setas
 *
 * \param void
 * \return void
 *
 */
void som_seta_menu( void ){
        system( "START /REALTIME /MIN Som/Beep_Seta.exe");
}
//#####################################################



/** \brief Emite beep da tecla enter
 *
 * \param void
 * \return void
 *
 */
void som_enter_menu( void ){
        system( "START /REALTIME /MIN Som/Beep_Enter.exe");
}
//#####################################################



/** \brief Emite beep da tecla esc
 *
 * \param void
 * \return void
 *
 */
void som_esc_menu( void ){
        system( "START /REALTIME /MIN Som/Beep_Esc.exe");
}
//#####################################################



/** \brief Reproduzir música de novo level
 *
 * \param void
 * \return void
 *
 */
void musica_novo_level( void ){
        system( "START /REALTIME /MIN Som/tema_hockey_charge.exe");
}
//#####################################################



/** \brief Reproduzir música do portal
 *
 * \param void
 * \return void
 *
 */
void musica_portal( void ){
        system( "START /REALTIME /MIN Som/tema_hockey_charge_final.exe");
}
//#####################################################



/** \brief Reproduzir música de game over
 *
 * \param void
 * \return void
 *
 */
void musica_game_over( void ){
        system( "START /REALTIME /MIN Som/tema_nokia.exe");
}
//#####################################################



/** \brief Reproduzir música de coleta de alimento
 * \param void
 * \return void
 *
 */
void musica_coleta_alimento( void ){
        system( "START /REALTIME /MIN Som/som_coleta_simples.exe");
}
//#####################################################



/** \brief Reproduzir música de coleta de dinheiro
 * \param void
 * \return void
 *
 */
void musica_coleta_dinheiro( void ){
        system( "START /REALTIME /MIN Som/som_coleta_dinheiro.exe");
}
//#####################################################



/** \brief Iniciar Programa Que Administra o Som Do Jogo
 *
 * \param void
 * \return void
 *
 */
void iniciar_sistema_som_jogo( void ){
        system( "start Som/sistema_som_snake.exe");
}
//#####################################################


/** \brief Fechar Programa Que Administra o Som Do JOGO
 *
 * \param void
 * \return void
 *
 */
void encerrar_sistema_som_jogo( void ){
        system( "TASKKILL /IM sistema_som_snake.exe /F");
}
//#####################################################



/** \brief Sincroniza o arquivo que armazena o modo de áudio ao jogo
 *
 * \param JOGO*
 * \return void
 *
 */
void sincronizarSomJogo( JOGO* jogo , char* modo ){
        strcpy( jogo->modo_som.modo_atual , modo );

        rewind( jogo->modo_som.arq_modo );
        for( int tam = 0 ; tam < strlen( jogo->modo_som.modo_atual ) ; tam++ )
                fputc( jogo->modo_som.modo_atual[ tam ] , jogo->modo_som.arq_modo );

}
//#####################################################

