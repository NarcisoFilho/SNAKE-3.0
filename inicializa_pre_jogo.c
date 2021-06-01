
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
}
//#####################################################



