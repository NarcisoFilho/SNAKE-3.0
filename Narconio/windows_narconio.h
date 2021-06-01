#ifndef __WINDOWS_NARCONIO_
#define __WINDOWS_NARCONIO_

        #include <windows.h>
        #include <stdio.h>

        void ativar_es_ANSI_windows( void );    // Ativa as sequências de escape ANSI no SO windows
        void restaurar_padrao_windows( void );  // Restaura a saída padrão windows

#endif // __WINDOWS_NARCONIO_
