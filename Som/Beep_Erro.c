#include "NotasMusicais.h"

int main(){
	for( int bis = 3 ; bis ; bis-- ){
		Beep( A5 , 40 * t );
		Sleep( 4 * t );
	}
	
	for( int bis = 2 ; bis ; bis-- ){
		Beep( F5 , 27 * t );
		Sleep( 5 * t );
		Beep( C6 , 10 * t );
		Beep( A5 , 25 * t );
		Sleep( 25 * t );
	}
}