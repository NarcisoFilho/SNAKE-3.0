
#include "Narconio/narconio.h"
#include "definicoes_jogo.h"

/// PROTÓTIPOS PRINCIPAIS
void campanha( JOGO* );
void modoSobrevivencia( JOGO* );
void dificuldade( JOGO* );
void highScores( JOGO* );
void sair( JOGO* );

/** \brief Função principal do jogo
 *
 * \param void
 * \return void
 *
 */
int main(){
        // Funções Do MainMenu
        void (*funcs[ MENU_QTD_ITEMS ] )( JOGO* ) = { campanha , modoSobrevivencia , dificuldade , highScores , sair };
        // Variáveis
        JOGO jogo;              // TELA + SNAKE

        // Inicialização
        inicializarJanela();            // Ativa modo janela ANSI, se necessário
        configurarPreJogo( &jogo );     // Configuração de definições do jogo e carregamento de recusrsos

        // Nova Partida
        do{
                if( jogo.menu.item_alterado ) desenhar_menu( &jogo.menu );
                atualizar_menu( &jogo.menu );

                if( checaTecla_Pressionada( VK_RETURN ) ){
                        funcs[ jogo.menu.selec ]( &jogo );
                        REDESENHA_MENU;
                }
                pausaMS( MENU_DELAY );
        }while( !jogo.menu.sair_loop );

        finalizarJanela();
        return 0;
}
//#####################################################



/** \brief (Item do MainMenu ) Inicia Modo Campanha
 *
 * \param JOGO*
 * \return void
 *
 */
void campanha( JOGO* jogo ){
        inicializarPrePartida( jogo );    // Reinicializa os dados do jogo para NOVA PARTIDA
        jogo->flag_modo_infinito = false;


        do{
                inicializarNovoLevel( jogo );    // Reinicializa os dados do jogo para NOVO LEVEL
                desenNovoLevel( *jogo );
                do{
                        desenhaJogo( jogo );
                        atualizaJogo( jogo );
                }while( !_FIM_DE_JOGO  &&  !checaNovoLevel( *jogo ) );

                if( _FIM_DE_JOGO )desenFimJogo( *jogo );
                else jogo->snake.level++;    // Incrementar level

        }while( !_FIM_DE_JOGO  );
}
//#####################################################



/** \brief (Item do MainMenu ) Inicia Modo Sobrevivência
 *
 * \param JOGO*
 * \return void
 *
 */
void modoSobrevivencia( JOGO* jogo ){
        inicializarPrePartida( jogo );    // Reinicializa os dados do jogo para NOVA PARTIDA
        jogo->snake.level = 14;
        inicializarNovoLevel( jogo );    // Reinicializa os dados do jogo para NOVO LEVEL
        jogo->flag_modo_infinito = true;

        desenNovoLevel( *jogo );

        do{
                desenhaJogo( jogo );
                atualizaJogo( jogo );
        }while( !_FIM_DE_JOGO  );
        pausaS( DELAY_FIM_LEVEL );
}
//#####################################################



/** \brief (Item do MainMenu ) Abre menu secundário de escolha de dificuldade do jogo
 *
 * \param JOGO*
 * \return void
 *
 */
void dificuldade( JOGO* jogo ){
        char tit[ 20 ] = "DIFICULDADE :";
        char dif_o[ 40 ] = "<-______________->";
        char dif[ 40 ] = "<-______________->";
        int px_o =  ( jogo->tela.cols - strlen_fonte( dif , jogo->res.fonte_small , 3 ) ) / 2 ;
        int px =  ( jogo->tela.cols - strlen_fonte( dif , jogo->res.fonte_small , 3 ) ) / 2 ;
        desenRetang( 0 , 0 , jogo->tela.cols , jogo->tela.lins , COR_FUNDO_AREA_EXTERNA );
        printFonte( tit , jogo->res.fonte_small  ,  (PONTO){ ( jogo->tela.cols - strlen_fonte( tit , jogo->res.fonte_small , 3 ) ) / 2 , ( 1.0 / 3 ) * jogo->tela.lins } , 4 , VERDE_MUSGO , COR_FUNDO_AREA_EXTERNA );
        printFonte( dif , jogo->res.fonte_small  ,  (PONTO){  px , ( 1.0 / 3 ) * jogo->tela.lins + 2 * jogo->res.fonte_small.altu } , 4 , VERDE_BRILHANTE , COR_FUNDO_AREA_EXTERNA );

        strcpy( dif , "______________" );
        int lret =  strlen_fonte( dif , jogo->res.fonte_small , 3 );
        strcpy( dif , "<-" );
        px += strlen_fonte( "<-" , jogo->res.fonte_small , 3 );
        desenRetang( px , ( 1.0 / 3 ) * jogo->tela.lins + 2 * jogo->res.fonte_small.altu , lret , jogo->res.fonte_small.altu , COR_FUNDO_AREA_EXTERNA );

        do{
                switch( jogo->dificuldade_escolhida ){
                        case FACIL: strcpy( dif , "FACIL" ); break;
                        case NORMAL: strcpy( dif , "NORMAL" ); break;
                        case DIFICIL: strcpy( dif , "DIFICIL" ); break;
                }
                printFonte( dif , jogo->res.fonte_small  ,  (PONTO){ ( jogo->tela.cols - strlen_fonte( dif , jogo->res.fonte_small , 3 ) ) / 2 , ( 1.0 / 3 ) * jogo->tela.lins + 2 * jogo->res.fonte_small.altu } , 4 , VERDE_AZULADO_ESCURO , COR_FUNDO_AREA_EXTERNA );

                if( checaTecla_Pressionada( VK_LEFT ) ){
                        desenRetang( px , ( 1.0 / 3 ) * jogo->tela.lins + 2 * jogo->res.fonte_small.altu , lret , jogo->res.fonte_small.altu , COR_FUNDO_AREA_EXTERNA );
                        jogo->dificuldade_escolhida--;
                }

                if( checaTecla_Pressionada( VK_RIGHT ) ){
                        desenRetang( px , ( 1.0 / 3 ) * jogo->tela.lins + 2 * jogo->res.fonte_small.altu , lret , jogo->res.fonte_small.altu , COR_FUNDO_AREA_EXTERNA );
                        jogo->dificuldade_escolhida++;
                }

                if( checaTecla_Pressionada( VK_DOWN ) ){
                        printFonte( dif_o , jogo->res.fonte_small  ,  (PONTO){  px_o , ( 1.0 / 3 ) * jogo->tela.lins + 2 * jogo->res.fonte_small.altu } , 4 , CINZA_8 , COR_FUNDO_AREA_EXTERNA );
                        desenRetang( px , ( 1.0 / 3 ) * jogo->tela.lins + 2 * jogo->res.fonte_small.altu , lret , jogo->res.fonte_small.altu , COR_FUNDO_AREA_EXTERNA );
                        jogo->dificuldade_escolhida++;
                }

                if( jogo->dificuldade_escolhida == 0 ) jogo->dificuldade_escolhida = DIFICIL;
                if( jogo->dificuldade_escolhida == 4 ) jogo->dificuldade_escolhida = FACIL;
                pausaMS( MENU_DELAY );
        }while( 1 );
}
//#####################################################



/** \brief (Item do MainMenu ) Exibe HighScores
 *
 * \param JOGO*
 * \return void
 *
 */
void highScores( JOGO* jogo ){
        printf("_________________HIGHSCORES------------------------------");
}
//#####################################################



/** \brief (Item do MainMenu ) Ativa flag para fechar menu
 *
 * \param JOGO*
 * \return void
 *
 */
void sair( JOGO* jogo ){
        jogo->menu.sair_loop = true;
}
//#####################################################


