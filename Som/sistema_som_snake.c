#include "NotasMusicais.h"
#include <ctype.h>

SHORT checaTecla( int tecla ){
        if( GetAsyncKeyState( tecla) & 0x8000 )
                return 1;
        return 0;
}

// MACROS
#define BEEP_ENTER {\
        Beep( E5 , t * 20 );\
        Beep( F5 , t * 20 );\
}

#define BEEP_BACK {\
        Beep( F5 , t * 20 );\
        Beep( E5 , t * 20 );\
}

#define BEEP_SETAS_MENU {\
                Beep( D5S , t * 25 );\
}

#define INTRO_IMPERIAL_MARCH {\
	for( int bis = 3 ; bis ; bis-- ){\
		Beep( A5 , 40 * t );\
		Sleep( 4 * t );\
	}\
 \
	for( int bis = 2 ; bis ; bis-- ){\
		Beep( F5 , 27 * t );\
		Sleep( 5 * t );\
		Beep( C6 , 10 * t );\
		Beep( A5 , 25 * t );\
		Sleep( 25 * t );\
	}\
}

#define BEEP_ERRO INTRO_IMPERIAL_MARCH

int main(){
        FILE* arq = fopen( "Som/MODO_SOM_ATUAL.txt" , "r+" );
        char modo[ 3 ];

        if( arq == NULL ){
                arq = fopen( "MODO_SOM_ATUAL.txt" , "r+" );
                if( arq == NULL ){
                        BEEP_ERRO;
                        exit( 1 );
                }
        }

        do{
                // LEITURA
                rewind( arq );
                modo[ 0 ] = tolower( fgetc( arq ) );
                modo[ 1 ] = tolower( fgetc( arq ) );

                switch( modo[ 0 ] ){
                        // SOM DESATIVADO
                        case 'd':
                                break;

                        // SOM NO JOGO
                        case 'j':
                                if( modo[ 1 ] == 'm' ){
                                                Beep( C5 , 10 * t );
                                                fseek( arq , 1 , SEEK_SET );
                                                fputc( 'n' , arq );
                                        }

                                if( modo[ 1 ] == 'a' ){
                                                Beep( C6 , 20 * t );
                                                fseek( arq , 1 , SEEK_SET );
                                                fputc( 'n' , arq );
                                        }

                                if( modo[ 1 ] == 'd' ){
                                                Beep( C6 , 10 * t );
                                                Beep( C7 , 10 * t );
                                                fseek( arq , 1 , SEEK_SET );
                                                fputc( 'n' , arq );                                        }

                                break;

                        // SOM NO MAIN MENU
                        case 'm':
                                if( checaTecla( VK_UP )
                                ||  checaTecla( VK_DOWN ) )
                                        BEEP_SETAS_MENU;

                                if( checaTecla( VK_RETURN )
                                ||  checaTecla( VK_SPACE ) ){
                                        if( modo[ 1 ] == 'f' )
                                                BEEP_ENTER;
                                }

                                break;

                        // SOM NO HIGHSCORES
                        case 'h':
                                if( checaTecla( VK_ESCAPE ) )
                                        BEEP_BACK;

                                if( checaTecla( VK_UP )
                                ||  checaTecla( VK_DOWN )
                                ||  checaTecla( VK_LEFT )
                                ||  checaTecla( VK_RIGHT ) )
                                        BEEP_SETAS_MENU;

                                if( checaTecla( VK_RETURN )
                                ||  checaTecla( VK_SPACE ) ){
                                        if( modo[ 1 ] == 'f' )
                                                BEEP_ENTER;
                                        if( modo[ 1 ] == 'b' )
                                                BEEP_BACK;
                                }

                                break;

                        // SOM NO PAUSE
                        case 'p':
                                if( checaTecla( VK_ESCAPE )
                                ||  checaTecla( VK_SPACE )
                                ||  checaTecla( VK_RETURN ) )
                                        BEEP_ENTER;

                                break;

                        // SOM NO MENU DE ESCOLHA DE MAPA
                        case 'e':
                                if( checaTecla( VK_ESCAPE ) )
                                        BEEP_BACK;

                                if( checaTecla( VK_UP )
                                ||  checaTecla( VK_DOWN ) )
                                        BEEP_SETAS_MENU;

                                if( checaTecla( VK_RETURN )
                                ||  checaTecla( VK_SPACE ) ){
                                        if( modo[ 1 ] == 'f' )
                                                BEEP_ENTER;
                                        if( modo[ 1 ] == 'b' )
                                                BEEP_BACK;
                                }

                                break;
                }
        }while( modo[ 0 ] != 'z' );

        return 0;
}
