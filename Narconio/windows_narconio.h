#ifndef __WINDOWS_NARCONIO_
#define __WINDOWS_NARCONIO_

        #include <windows.h>
        #include <stdio.h>

        void ativar_es_ANSI_windows( void );    // Ativa as sequ�ncias de escape ANSI no SO windows
        void restaurar_padrao_windows( void );  // Restaura a sa�da padr�o windows

#endif // __WINDOWS_NARCONIO_
