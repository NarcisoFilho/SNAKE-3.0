/** @brief  MENU PADRÃO
 * @author Narciso Filho
 * @date 14-05-2021
 *
 *      Funções para o desenho de um menu interativo simples e multi-uso.
 *      obs.: Utiliza biblioteca narconio.h
 */


#ifndef __MENUPADRAO_H_
#define __MENUPADRAO_H_

        #include "narconio.h"
        #include <windows.h>

        void desenhar_menu( DADOS_MENU* );
        void atualizar_menu( DADOS_MENU* );
        void atualizaSelSetas( DADOS_MENU* );

        // Extras
        void alteraMenuEmExecucao( DADOS_MENU* menu );

#endif // __MENUPADRAO_H_
