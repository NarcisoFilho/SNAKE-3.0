#ifndef __CALCULOS_H_
#define __CALCULOS_H_

        #include "definicoes_jogo.h"

        BOOL checaTecla_Pressionada( int );
        BOOL checaTecla_Down( int );
        BOOL unicaSeta_Down( int tecla );
        float gtor( float angulo );
        int dtoi( double nmr );
        int obterTempoExeMS( void );
        int nmrRand( int nmr_min , int nmr_max );

#endif // __CALCULOS_H_
