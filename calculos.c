
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
//#####################################################



/** \brief Gera número randômico
 *
 * \param int : Valor Mínimo
 * \param int : Valor Máximo
 * \return int : Número Randômico
 *
 */
int nmrRand( int nmr_min , int nmr_max ){
        return nmr_min + rand() % ( nmr_max + 1 - nmr_min ) ;
}
//#####################################################


/** \brief Calcula a quantidade de dígitos de números inteiros
 *
 * \param int : Número inteiro
 * \return int : Quantidade de dígitos do Número
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


/** \brief Pausa a execução por determinado tempo ou até usuário pressionar tecla enter
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


/** \brief Pausa a execução até usuário pressionar um das teclas pertencentes ao  array teclas[]
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


