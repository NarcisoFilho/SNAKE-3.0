
#include "definicoes_jogo.h"


/** \brief  Configura as funcionalidades do jogo e inicializa valores fixos
 *
 * \param JOGO*
 * \return void
 *
 */
void configurarPreJogo( JOGO* jogo ){

        configurarTela( &jogo->tela );     // Incializa a variável tela

        esconderCursorTec();       // Esconde o Cursor do Teclado

        desabilitarEdicaoRapida( jogo->tela.handle_janela );    // Desabilita o modo de edição rápida

        configurarAreaDoJogo( jogo );   // Configura a área do jogo

        carregarRecursos( jogo );       // Carrega as fontes

        carregarDadosLevels( jogo );    // Carrega os dados do level

        configurarJogabilidade( jogo );         // Configura a jogabilidade padrão

        ativarModoDeTeste( jogo );      // Ativa o modo de teste se tecla específica estiver pressionada

        configurarMenu( jogo );         // Configura o menu

        carregarHighscores( jogo );     // Carrega os highscores, de cada modo de jogo, do arquivo highscores.bin

        configurarSom( jogo );     // Configura o sistema de áudio
}
//#####################################################



/** \brief Configura a janela do jogo inicializando a variável tela
 *
 * \param TELA* : O endereço da variável tela
 * \return void
 *
 */
void configurarTela( TELA* tela ){
        // Resolução do Monitor
        tela->resolucao = ObterResolucaoMonitor();

        // Escala do Tamanho da Monitor
        tela->escalaX = tela->resolucao.x / (double)REF_RESOLUCAO_X;
        tela->escalaY = tela->resolucao.y / (double)REF_RESOLUCAO_Y;

        // Calcular tamanho da janela em casas
        tela->cols = REF_QTD_COLS * tela->escalaX;           // Calculando número de COLUNAS com base na resolução da tela e a de referência
        tela->lins = REF_QTD_LINS * tela->escalaY;        // Calculando número de LINHAS com base na resolução da tela e a de referência

        // Atribuir tamanho da janela em casas
        char comando[ 100 ] = { 0 };
        sprintf( comando , "mode con cols=%d lines=%d" , tela->cols , tela->lins);         // Montando comando a ser passado ao prompt
        system( comando );                                                                               // Efetuar comando

        // Título
        system("title SNAKE 3.0 by Narciso Filho ");

        // Ativar o modo tela cheia
        ativarTelaCheia();

        // Obter handle da janela
        tela->handle_janela = GetConsoleWindow();

        // Maximizar janela
        ShowWindow( tela->handle_janela , SW_MAXIMIZE );
}
//#####################################################


/** \brief Retorna a resolução do monitor em pixels. Largura e Altura
 *
 * \param void
 * \return PONTO : A resolução do monitor: x -> largura , y -> altura
 *
 */
PONTO ObterResolucaoMonitor( void ){
        PONTO resolucao;

        // Obter resolução do monitor
        resolucao.x = GetSystemMetrics( SM_CXSCREEN );
        resolucao.y = GetSystemMetrics( SM_CYSCREEN );

        // Retorno
        return resolucao;
}
//#####################################################



/** \brief Desabilita o modo de Edição Rápida
 *      O usuário não poderá selecionar texto com o mouse.
 *      Por outro lado, a execução não é pausada quando se clicka na tela com o mouse.
 *
 * \param HWND: O handle da tela
 * \return void
 *
 */
void desabilitarEdicaoRapida( HWND handle_janela ){
        HANDLE handle_stdin = GetStdHandle( STD_INPUT_HANDLE ); // Obtendo handle da entrada padrão
        DWORD modo_original;    // Variável para armazenar modo original da entrada

        // Obtendo Modo Original
        GetConsoleMode( handle_stdin , &modo_original );

        // Definir novo modo SEM ENABLE_QUICK_EDIT_MODE
        SetConsoleMode( handle_stdin , modo_original & ENABLE_EXTENDED_FLAGS );
}
//#####################################################


/** \brief Ativa a tela cheia
 *
 * \param void
 * \return void
 *
 */
void ativarTelaCheia( void ){
        keybd_event( VK_MENU , 0x36 , 0 , 0 );                                         //Pressiona Alt
        keybd_event( VK_RETURN , 0x1C , 0 , 0 );                                     //Pressiona Enter
        keybd_event( VK_MENU , 0x1C , KEYEVENTF_KEYUP , 0 );             //Solta alt
        keybd_event( VK_RETURN , 0x38 , KEYEVENTF_KEYUP , 0 );          //Solta enter
}
//#####################################################



/** \brief Configura a área do jogo
 *
 * \param SNAKE*
 * \return void
 *
 */
void configurarAreaDoJogo( JOGO* jogo ){
        jogo->area_do_jogo.larg = LARG_AREA_DO_JOGO;
        jogo->area_do_jogo.altu = ALTU_AREA_DO_JOGO;
        jogo->area_do_jogo.ponto.x = ( jogo->tela.cols - jogo->area_do_jogo.larg ) / 2;
        jogo->area_do_jogo.ponto.y =  jogo->tela.lins - jogo->area_do_jogo.altu;
}
//#####################################################



/** \brief Configura a área do jogo
 *
 * \param SNAKE*
 * \return void
 *
 */
void carregarRecursos( JOGO* jogo ){
        jogo->res.fonte_big = carregarFonte("Fontes/big.txt");
        jogo->res.fonte_small = carregarFonte("Fontes/small.txt");
        jogo->res.fonte_starWars = carregarFonte("Fontes/starWars.txt");
}
//#####################################################



/** \brief Configura a jogabilidade padrão
 *
 * \param SNAKE*
 * \return void
 *
 */
void configurarJogabilidade( JOGO* jogo ){
        jogo->dificuldade_escolhida = NORMAL;
        jogo->flag_modo_infinito = false;
}
//#####################################################



/** \brief Ativa modo de teste se tecla TECLA_MODO_DE_TESTE for pressionada na inicialização
 *
 * \param JOGO*
 * \return void
 *
 */
void ativarModoDeTeste( JOGO* jogo ){
        if( checaTecla_Down( TECLA_MODO_DE_TESTE ) ){
                jogo->flag_modo_de_teste = true;
                printFonte(
                           " MODO DE TESTE " ,
                           jogo->res.fonte_starWars ,
                           (PONTO){ jogo->tela.cols / 2 - 80 , jogo->tela.lins / 2 } ,
                           5 ,
                           LARANJA ,
                           CINZA_7
                );
                pausaS( 2 );
                LMPTELA;
        }
        else jogo->flag_modo_de_teste = false;

}
//#####################################################



/** \brief Carregar os Dados dos level's
 *
 * \param JOGO*
 * \return void
 *
 */
void carregarDadosLevels( JOGO* jogo ){

        for( int i = 1 ; i <= QTD_LEVELs ; i++ ){
                char nome[ 20 ] = { 0 };

                sprintf( nome , "Levels/level%d.txt" , i );

                char texto_descartado[ 301 ];
                FILE* arq = fopen( nome , "r" );
                if( arq == NULL ) ErroFatal( FALHA_AUTORIZACAO_ABERTURA_ARQ );

                for( int y = 0 ; y <= ALTU_AREA_DO_JOGO ; y++ ){
                        fgets( jogo->level[ i ].matriz[ y ] , LARG_AREA_DO_JOGO + 1 , arq );
                        fgets( texto_descartado , 300 , arq );
                }

                for( int k = 1 ; k < ALTU_AREA_DO_JOGO - 1 ; k++ )
                        for( int j = 1 ; j < LARG_AREA_DO_JOGO - 1 ; j++ )
                                if( jogo->level[ i ].matriz[ k ][ j ] == 'o' )
                                        jogo->level[ i ].origem_snake = (PONTO){ j , k };

                fclose( arq );
        }
}
//#####################################################



/** \brief Carregar os HighScores
 *
 * \param JOGO*
 * \return void
 *
 */
void carregarHighscores( JOGO* jogo ){
        FILE* arq = fopen( "HighScores/highscores.bin" , "rb" );
        if( arq == NULL ) ErroFatal( FALHA_AUTORIZACAO_ABERTURA_ARQ );

        for( int i = 0 ; i <= QTD_LEVELs ; i++ )
                for( int j = 0 ; j < 5 ; j++ )
                        fread( &jogo->highscores[ i ][ j ] , sizeof( HIGHSCORES ) , 1 , arq );
        fclose( arq );
}
//#####################################################



/** \brief Configura o sistema de áudio
 *
 * \param JOGO*
 * \return void
 *
 */
void configurarSom( JOGO* jogo ){
        FILE* arq = fopen( "Som/MODO_SOM_ATUAL.txt" , "w" );
        if( arq == NULL ) ErroFatal( FALHA_AUTORIZACAO_ABERTURA_ARQ );

        jogo->modo_som.arq_modo = arq;
        jogo->modo_som.ativado = true;
        sincronizarSomJogo( jogo , "mf");
        iniciar_sistema_som_jogo();
}
//#####################################################



/** \brief Configura o menu
 *
 * \param JOGO*
 * \return void
 *
 */
void configurarMenu( JOGO* jogo ){
        // Cores
        jogo->menu.cor_comum = MENU_COR_COMUM;
        jogo->menu.cor_select = MENU_COR_SELECT;
        jogo->menu.cor_sub_titulo = MENU_COR_SUB_TITULO;
        jogo->menu.cor_titulo = MENU_COR_TITULO;
        jogo->menu.cor_fundo = MENU_COR_FUNDO;

        // Items
        char items[][ MENU_MAX_CARACTERES_NOME_ITEM ] = {
                "Campanha" ,
                "Sobrevivencia" ,
                "Dificuldade" ,
                "HighScores" ,
                "Sair"
        };

        jogo->menu.qtd_items = MENU_QTD_ITEMS;
        jogo->menu.items_menu = (char**)malloc( jogo->menu.qtd_items * sizeof( char* ) );
        for( int i = 0 ; i < jogo->menu.qtd_items ; i++ ){
                jogo->menu.items_menu[ i ] =
                (char*)malloc( ( strlen( items[ i ] ) + 1 ) * sizeof( char ) );

                strcpy( jogo->menu.items_menu[ i ] , items[ i ] );
        }

        jogo->menu.espacamento_items.x = 4;
        jogo->menu.espacamento_items.y = 5;

        jogo->menu.deslocamento_items.x = 0;
        jogo->menu.deslocamento_items.y = -3;

        // Título
        char titulo[] = "SNAKE 3.0";
        jogo->menu.titulo =
        (char*)malloc( ( strlen( titulo ) + 1 ) *sizeof( char ) );

        strcpy( jogo->menu.titulo , titulo );

        jogo->menu.espacamento_titulo.x = 7;
        jogo->menu.espacamento_titulo.y = 4;

        // Sub-Título
        char sub_titulo[] = "by Narciso Filho";
        jogo->menu.sub_titulo =
        (char*)malloc( ( strlen( sub_titulo ) + 1 )  *sizeof( char ) );

        strcpy( jogo->menu.sub_titulo , sub_titulo );
        jogo->menu.sub_titulo_subl = false;
        jogo->menu.espacamento_sub_titulo.x = 3;
        jogo->menu.espacamento_sub_titulo.y = 0;

        // Reinicializar Flags
        jogo->menu.sair_loop = false;
        jogo->menu.item_alterado = true;
        jogo->menu.selec = 0;
        jogo->menu.ativar_fonte_items = true;
        jogo->menu.ativar_fonte_sub_titulo = false;
        jogo->menu.ativar_fonte_titulo = true;

        // Tela
        jogo->menu.tela.ponto.x = 0;
        jogo->menu.tela.ponto.y = 0;
        jogo->menu.tela.larg = jogo->tela.cols;
        jogo->menu.tela.altu = jogo->tela.lins;

        // Fontes
        jogo->menu.fonte_items = jogo->res.fonte_small;
        jogo->menu.fonte_sub_titulo = jogo->res.fonte_small;
        jogo->menu.fonte_titulo = jogo->res.fonte_big;
}
//#####################################################






