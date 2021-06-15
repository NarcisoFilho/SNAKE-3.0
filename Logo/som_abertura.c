
#include "../Som/NotasMusicais.h"

int main(){
	for( int bis = 3 ; bis ; bis-- ){
		Beep( A5 , 15 * t );
		Beep( C5 , 15 * t );
		Beep( G5 , 15 * t );
		Beep( C5 , 15 * t );
	}
	Beep( A5 , 15 * t );
	Beep( G5 , 15 * t );
	Beep( E5 , 15 * t );
	Beep( C5 , 15 * t );
	Beep( D5 , 70 * t );

	return 0;
}