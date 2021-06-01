
#include "definicoes_jogo.h"


/** \brief Checa se tecla foi pressionada
 *
 * \param int : Tecla
 * \return BOOL : Pressionamento instantâneo
 *
 */
BOOL checaTecla_Pressionada( int tecla ){
        return ( ( GetAsyncKeyState( tecla ) & 0x8000 ) != 0 );
}
//#####################################################




/** \brief Checa se tecla está sendo mantida pressionada
 *
 * \param int : Tecla
 * \return BOOL : Estado de acionamento
 *
 */
BOOL checaTecla_Down( int tecla ){
        return ( ( GetAsyncKeyState( tecla ) ) != 0 );
}
//#####################################################




/** \brief Checa se a tecla seta é a única mantida pressionada
 *
 * \param int : Tecla
 * \return BOOL : Estado de exclusividade acionamento
 *
 */
BOOL unicaSeta_Down( int tecla ){
        if( !checaTecla_Down( VK_UP )  ||  tecla == VK_UP )
                if( !checaTecla_Down( VK_DOWN )  ||  tecla == VK_DOWN )
                        if( !checaTecla_Down( VK_LEFT )  ||  tecla == VK_LEFT )
                                if( !checaTecla_Down( VK_RIGHT )  ||  tecla == VK_RIGHT )
                                                return true;
        return false;
}
//#####################################################



/** \brief Converte valor de ângulo em graus para radianos
 *
 * \param float : Ângulo em Graus
 * \return float : Ângulo em radianos
 *
 */
float gtor( float angulo ){
        return ( ( PI * angulo / 180.0 ) );
}
//#####################################################



/** \brief Realiza arredondamento científico em número double para inteiro
 *
 * \param double : Número
 * \return int : Número arredondado cientificamente para zero casas decimais depois da vírgula
 *
 */
int dtoi( double nmr ){
        double delta_sup = ceil( nmr ) - nmr;
        double delta_inf = nmr - floor( nmr );

        if( delta_sup < delta_inf )
                return (int)( ceil( nmr ) );
        else
                return (int)( floor( nmr ) );
}
//#####################################################



/** \brief Medir tempo de execução em millisegundos
 *
 * \param void
 * \return int : Tempo em millisegundo
 *
 */
int obterTempoExeMS( void ){
        return ( clock() / ( CLOCKS_PER_SEC / 1000 ) );
}
