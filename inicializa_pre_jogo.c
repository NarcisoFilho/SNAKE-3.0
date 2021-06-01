
#include "definicoes_jogo.h"


/** \brief  Configura as funcionalidades do jogo e inicializa valores fixos
 *
 * \param JOGO*
 * \return void
 *
 */
void configurarPreJogo( JOGO* jogo ){
        configurarTela( &jogo->tela );     // Incializa a vari�vel tela

        esconderCursorTec();       // Esconde o Cursor do Teclado

//        desabilitarEdicaoRapida( jogo->tela.handle_janela );    // Desabilita o modo de edi��o r�pida

        configurarAreaDoJogo( jogo );   // Configura a �rea do jogo

        carregarRecursos( jogo );       // Carrega as fontes

        carregarDadosLevels( jogo );    // Carrega os dados do level

        configurarJogabilidade( jogo );         // Configura a jogabilidade padr�o

}
//#####################################################



/** \brief Configura a janela do jogo inicializando a vari�vel tela
 *
 * \param TELA* : O endere�o da vari�vel tela
 * \return void
 *
 */
void configurarTela( TELA* tela ){
        // Resolu��o do Monitor
        tela->resolucao = ObterResolucaoMonitor();

        // Escala do Tamanho da Monitor
        tela->escalaX = tela->resolucao.x / (double)REF_RESOLUCAO_X;
        tela->escalaY = tela->resolucao.y / (double)REF_RESOLUCAO_Y;

        // Calcular tamanho da janela em casas
        tela->cols = REF_QTD_COLS * tela->escalaX;           // Calculando n�mero de COLUNAS com base na resolu��o da tela e a de refer�ncia
        tela->lins = REF_QTD_LINS * tela->escalaY;        // Calculando n�mero de LINHAS com base na resolu��o da tela e a de refer�ncia

        // Atribuir tamanho da janela em casas
        char comando[ 100 ] = { 0 };
        sprintf( comando , "mode con cols=%d lines=%d" , tela->cols , tela->lins);         // Montando comando a ser passado ao prompt
        system( comando );                                                                               // Efetuar comando

        // T�tulo
        system("title SNAKE 3.0 by Narciso Filho ");

        // Ativar o modo tela cheia
        ativarTelaCheia();

        // Obter handle da janela
        tela->handle_janela = GetConsoleWindow();

        // Maximizar janela
        ShowWindow( tela->handle_janela , SW_MAXIMIZE );
}
//#####################################################


/** \brief Retorna a resolu��o do monitor em pixels. Largura e Altura
 *
 * \param void
 * \return PONTO : A resolu��o do monitor: x -> largura , y -> altura
 *
 */
PONTO ObterResolucaoMonitor( void ){
        PONTO resolucao;

        // Obter resolu��o do monitor
        resolucao.x = GetSystemMetrics( SM_CXSCREEN );
        resolucao.y = GetSystemMetrics( SM_CYSCREEN );

        // Retorno
        return resolucao;
}
//#####################################################



/** \brief Desabilita o modo de Edi��o R�pida
 *      O usu�rio n�o poder� selecionar texto com o mouse.
 *      Por outro lado, a execu��o n�o � pausada quando se clicka na tela com o mouse.
 *
 * \param HWND: O handle da tela
 * \return void
 *
 */
void desabilitarEdicaoRapida( HWND handle_janela ){
        HANDLE handle_stdin = GetStdHandle( STD_INPUT_HANDLE ); // Obtendo handle da entrada padr�o
        DWORD modo_original;    // Vari�vel para armazenar modo original da entrada

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



/** \brief Configura a �rea do jogo
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



/** \brief Configura a �rea do jogo
 *
 * \param SNAKE*
 * \return void
 *
 */
void carregarRecursos( JOGO* jogo ){
        jogo->res.fonte_big = carregarFonte("Fontes/big.txt");
        jogo->res.fonte_small = carregarFonte("Fontes/small.txt");
}
//#####################################################



/** \brief Configura a jogabilidade padr�o
 *
 * \param SNAKE*
 * \return void
 *
 */
void configurarJogabilidade( JOGO* jogo ){
        jogo->dificuldade_escolhida = NORMAL;
}
//#####################################################



/** \brief Carregar os Dados dos level's
 *
 * \param JOGO*
 * \return void
 *
 */
void carregarDadosLevels( JOGO* jogo ){

//        for( int i = 1 ; i <= QTD_LEVELs ; i++ ){
        for( int i = 1 ; i <= 2 ; i++ ){
                jogo->level[ i ].qtd_alimentos_coletados = 0;

                char nome[ 20 ] = { 0 };
                char texto_descartado[ 200 ];
                sprintf( nome , "Levels/level%d.txt" , i );
                FILE* arq = fopen( nome , "r" );

                if( arq == NULL ) ErroFatal( FALHA_AUTORIZACAO_ABERTURA_ARQ );

                for( int y = 0 ; y <= ALTU_AREA_DO_JOGO ; y++ ){
                        fgets( jogo->level[ i ].matriz[ y ] , LARG_AREA_DO_JOGO + 1 , arq );
                        fgets( texto_descartado , 300 , arq );
                }

                fclose( arq );
        }
}
//#####################################################






