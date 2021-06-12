#include "NotasMusicais.h"

SHORT checaTecla( int tecla ){
        if( GetAsyncKeyState( tecla) & 0x8000 )
                return 1;
        return 0;
}

int main(){
        for( ; ; ){
                if( checaTecla( VK_ESCAPE ) ){
                        Beep( F5 , t * 7 );
                        Beep( F5 , t * 2.5 );
                        Beep( E5 , t * 11 );
                }

                if( checaTecla( VK_RETURN ) ){
                        Beep( E5 , t * 12 );
                        Beep( F5 , t * 12 );
                }

                if( checaTecla( VK_UP )
                   ||  checaTecla( VK_DOWN )
                   ||  checaTecla( VK_LEFT )
                   ||  checaTecla( VK_RIGHT ) )
                        Beep( D5S , t * 25 );
        }

        return 0;
}
