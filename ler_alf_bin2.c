#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(){

	FILE* arq = fopen( "alfabeto.bin" , "rb" );
	char ch[ 3 ]; 
	int pos;
	
	scanf( "%d" , &pos );

	do{	
		fseek( arq , pos - 1 , SEEK_SET );
		fread( ch , 2 * sizeof( char ) , 2 , arq );
		fputs( "\n  >" , stdout );
		puts( ch );
		fputs( "<\n\n" , stdout );
		scanf( "%d" , &pos );
	}while( !( GetAsyncKeyState( VK_HOME ) & 0X8000 ) );

	fclose( arq );
	return 0;
}
