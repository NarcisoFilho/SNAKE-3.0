
#include "definicoes_jogo.h"


/** \brief Checa se tecla foi pressionada
 *
 * \param int : Tecla
 * \return BOOL : Pressionamento instant�neo
 *
 */
BOOL checaTecla_Pressionada( int tecla ){
        return ( ( GetAsyncKeyState( tecla ) & 0x8000 ) != 0 );
}
//#####################################################




/** \brief Checa se tecla est� sendo mantida pressionada
 *
 * \param int : Tecla
 * \return BOOL : Estado de acionamento
 *
 */
BOOL checaTecla_Down( int tecla ){
        return ( ( GetAsyncKeyState( tecla ) ) != 0 );
}
//#####################################################




/** \brief Checa se a tecla seta � a �nica mantida pressionada
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



/** \brief Converte valor de �ngulo em graus para radianos
 *
 * \param float : �ngulo em Graus
 * \return float : �ngulo em radianos
 *
 */
float gtor( float angulo ){
        return ( ( PI * angulo / 180.0 ) );
}
//#####################################################



/** \brief Realiza arredondamento cient�fico em n�mero double para inteiro
 *
 * \param double : N�mero
 * \return int : N�mero arredondado cientificamente para zero casas decimais depois da v�rgula
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



/** \brief Medir tempo de execu��o em millisegundos
 *
 * \param void
 * \return int : Tempo em millisegundo
 *
 */
int obterTempoExeMS( void ){
        return ( clock() / ( CLOCKS_PER_SEC / 1000 ) );
}
//#####################################################



/** \brief Gera n�mero rand�mico
 *
 * \param int : Valor M�nimo
 * \param int : Valor M�ximo
 * \return int : N�mero Rand�mico
 *
 */
int nmrRand( int nmr_min , int nmr_max ){
        return nmr_min + rand() % ( nmr_max + 1 - nmr_min ) ;
}
//#####################################################


/** \brief Calcula a quantidade de d�gitos de n�meros inteiros
 *
 * \param int : N�mero inteiro
 * \return int : Quantidade de d�gitos do N�mero
 *
 */
int qtd_dig( int nmr ){
        int qtd = 0;
        do{
                nmr /= 10;
                qtd++;
        }while( nmr );

        return qtd;
}
//#####################################################


/** \brief Pausa a execu��o por determinado tempo ou at� usu�rio pressionar tecla enter
 *
 * \param int : Tempo em milisegundos
 * \return void
 *
 */
void pausa_MS_ENTER( int tempo_milisegundos ){
        struct _timeb tempo_inicial;
        struct _timeb tempo_atual;
        _ftime( &tempo_inicial );

        do{
                _ftime( &tempo_atual );
        }while( tempo_atual.time * 1000 - tempo_inicial.time * 1000 + tempo_atual.millitm - tempo_inicial.millitm  <  tempo_milisegundos
               &&  !checaTecla_Pressionada( VK_RETURN ) );
}
//#####################################################


/** \brief Pausa a execu��o at� usu�rio pressionar um das teclas pertencentes ao  array teclas[]
 *
 * \param void
 * \return void
 *
 */
void pausaTecla( TECLA* teclas ){
        FLAG despausar = false;
        int i = 0;

        do{
                while( teclas[ i ] != 0 ){
                        if( checaTecla_Pressionada( teclas[ i ] ) ){
                                despausar = true;
                                break;
                        }else
                                i++;
                }
                i = 0;
        }while( !despausar );
}
//#####################################################


