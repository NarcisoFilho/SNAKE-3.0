#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COLS 500
#define LINS 30

int main(){
        FILE* arq = fopen( "StarWars3.txt" , "r+" );

        char mat[ LINS ][ COLS ];

        printf("leitura\n");
        for( int i = 0 ; i < LINS ; i ++ )
                fgets( mat[ i ] , COLS , arq );

        printf("operacao\n");
        for( int j = 0 ; j < COLS ; j ++ )
                if( mat[ 11 ][ j ] != ' ' )
                        for( int i = 11 ; i <= 18  ; i ++ )
                                for( int qtd = 0 ; qtd < 2 ; qtd++ )
                                        for( int x = 0 ; x < 500 - j ; x++ )
                                                mat[ i ][ j + x + 1 ] = mat[ i ][ j + x + 2 ];

        printf("gravacao\n");
        rewind( arq );
        for( int i = 0 ; i < LINS ; i ++ )
                fputs( mat[ i ] , arq );


        fclose( arq );

        return 0;
}
