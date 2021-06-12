
#include "definicoes_jogo.h"

///** \brief Emite beep quando usuário  utiliza as setas no menu
// *
// * \param void
// * \return void
// *
// */
//void som_seta_menu( void ){
//        system( "START /REALTIME /MIN Som/Beep_Seta.exe");
//}
////#####################################################
//
//
//
///** \brief Emite beep quando usuário  utiliza a tecla enter no menu
// *
// * \param void
// * \return void
// *
// */
//void som_enter_menu( void ){
//        system( "START /REALTIME /MIN Som/Beep_Enter.exe");
//}
////#####################################################
//
//
//
///** \brief Emite beep quando usuário  utiliza a tecla esc no menu
// *
// * \param void
// * \return void
// *
// */
//void som_esc_menu( void ){
//        system( "START /REALTIME /MIN Som/Beep_Esc.exe");
//}
////#####################################################



/** \brief Iniciar Programa Que Administra o Som Do Menu
 *
 * \param void
 * \return void
 *
 */
void iniciar_sistema_som_menu( void ){
        system( "START /REALTIME Som/som_menu.exe");
}
//#####################################################



/** \brief Fechar Programa Que Administra o Som Do Menu
 *
 * \param void
 * \return void
 *
 */
void fechar_sistema_som_menu( void ){
        system( "TASKKILL /IM som_menu.exe");
}
//#####################################################
