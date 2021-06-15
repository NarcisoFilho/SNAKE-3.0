
#include "NotasMusicais.h"

int main(){
	for( int bis = 2 ; bis ; bis-- ){
		Beep( E6 , 8 * t );
		Beep( F6 , 8 * t );
		Beep( G6 , 8 * t );
		Beep( F6 , 8 * t );
	}

	Beep( C7 , 8 * t );

	return 0;
}