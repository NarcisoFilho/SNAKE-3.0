
#include "NotasMusicais.h"

void refr( void ){
		Beep( E6 , 15 * t );
        	Beep( E6 , 15 * t );
	        Beep( D6 , 80 * t );
		Sleep( 15 * t );

	        Beep( D6 , 15 * t );
        	Beep( D6 , 15 * t );
	        Beep( C6 , 80 * t );
		Sleep( 15 * t );
}

int main(){
 	for( int bis = 2 ; bis ; bis-- )
		refr();
	Sleep( 30 * t );
        Beep( E5 , 80 * t );	
	Sleep( 40 * t );

        Beep( E5 , 20 * t );	
	Sleep( 15 * t );
        Beep( F5 , 15 * t );	
        Beep( G5 , 30 * t );	
	Sleep( 15 * t );
        Beep( F5 , 15 * t );	
        Beep( E5 , 15 * t );	
        Beep( D5 , 40 * t );	
	Sleep( 40 * t );

	Beep( F5 , 20 * t );	
	Sleep( 15 * t );
        Beep( G5 , 20 * t );	
	Sleep( 15 * t );
        Beep( A5 , 20 * t );	
	Sleep( 15 * t );
        Beep( F5 , 20 * t );	
	Sleep( 15 * t );
        Beep( D5 , 80 * t );	
	Sleep( 40 * t );

	Beep( D5 , 20 * t );	
	Sleep( 15 * t );
        Beep( E5 , 15 * t );	
        Beep( F5 , 30 * t );	
	Sleep( 15 * t );
        Beep( E5 , 15 * t );	
        Beep( D5 , 15 * t );	
        Beep( D5 , 30 * t );	
	Sleep( 40 * t );
	Beep( E5 , 20 * t );
	Sleep( 15 * t );
	Beep( C5 , 20 * t );
	Sleep( 15 * t );
	Beep( C6 , 80 * t );
	




        Beep( A5 , 20 * t );	
	Sleep( 15 * t );
        Beep( B5 , 15 * t );	
        Beep( C6 , 30 * t );	
	Sleep( 15 * t );
        Beep( B5 , 15 * t );	
        Beep( A5 , 15 * t );	
        Beep( B5 , 80* t );	
	Sleep( 40 * t );

	Beep( G5 , 20 * t );	
	Sleep( 15 * t );
        Beep( A5 , 15 * t );	
        Beep( B5 , 30 * t );	
	Sleep( 15 * t );
        Beep( A5 , 15 * t );	
        Beep( G5 , 15 * t );	
        Beep( A5 , 80 * t );	
	Sleep( 40 * t );

	Beep( F5 , 20 * t );	
	Sleep( 15 * t );
        Beep( G5 , 15 * t );	
        Beep( A5 , 30 * t );	
	Sleep( 15 * t );
        Beep( G5 , 15 * t );	
        Beep( F5 , 15 * t );	
        Beep( E5 , 40 * t );	
	Sleep( 40 * t );
	Beep( E5 , 40 * t );	
	Sleep( 15 * t );

        Beep( F5 , 40 * t );	
	Sleep( 15 * t );
        Beep( G5 , 40 * t );	
	Sleep( 15 * t );
	Beep( A5 , 80 * t );
	Sleep( 15 * t );



	Beep( A5 , 20 * t );	
	Sleep( 15 * t );
        Beep( B5 , 15 * t );	
        Beep( C6 , 30 * t );	
	Sleep( 15 * t );
        Beep( D6 , 15 * t );	
        Beep( C6 , 15 * t );	
	Sleep( 15 * t );
        Beep( D6 , 40* t );	
	Sleep( 40 * t );
        Beep( E6 , 40* t );

	Beep( E6 , 20 * t );	
	Sleep( 15 * t );
        Beep( F6 , 15 * t );	
        Beep( G6 , 30 * t );	
	Sleep( 15 * t );
        Beep( F6 , 15 * t );	
        Beep( E6 , 15 * t );	
        Beep( D6 , 80 * t );	
	Sleep( 40 * t );
	
	Beep( A5 , 15 * t );	
        Sleep( 15 * t );
	Beep( C6 , 40 * t );	
	Sleep( 15 * t );
        Beep( B5 , 45 * t );	
        
	for( int bis = 2 ; bis ; bis-- )
		refr();

	return 0;
}
