
#include "definicoes_jogo.h"


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



/** \brief Reproduzir música de adios
 * \param void
 * \return void
 *
 */
void musica_adios( void ){
        system( "START /REALTIME /MIN Som/som_encerramento.exe");
}
//#####################################################



/** \brief Reproduzir música de vitória
 *      Reproduz versão da música de vitória do Ayrton Sena
 * \param void
 * \return void
 *
 */
void musica_vitoria( void ){
        system( "START /REALTIME /MIN Som/musica_ayrton_sena.exe");
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

