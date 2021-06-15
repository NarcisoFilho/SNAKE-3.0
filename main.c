
#include "Narconio/narconio.h"
#include "definicoes_jogo.h"

/// PROTÓTIPOS PRINCIPAIS
void campanha( JOGO* );
void modoSobrevivencia( JOGO* );
void dificuldade( JOGO* );
void highScores( JOGO* );
void sair( JOGO* );
void exibirHighScores( JOGO* , int );

/** \brief Função Master do jogo
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
        printf("\n\n\t");

        system( "Logo\\Abertura_Logo_ASCII.exe" );

        // MAIN MENU
        do{
                if( jogo.menu.item_alterado ) desenhar_menu( &jogo.menu );
                atualizar_menu( &jogo.menu );

                if( jogo.menu.selec ==  4 ) sincronizarSomJogo( &jogo , "mb" );
                else{
                        if( jogo.menu.selec == 0 ) sincronizarSomJogo( &jogo , "mj" );
                        else sincronizarSomJogo( &jogo , "mf" );
                }

                if( checaTecla_Pressionada( VK_RETURN ) ){
                        funcs[ jogo.menu.selec ]( &jogo );
                        REDESENHA_MENU;
                }
                pausaMS( MENU_DELAY );
                verificarFecharJogoTeclado();
        }while( !jogo.menu.sair_loop );

        finalizarJanela();
        encerrar_sistema_som_jogo();
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
                sincronizarSomJogo( jogo , "d" );
                musica_novo_level();
                inicializarNovoLevel( jogo );    // Reinicializa os dados do jogo para NOVO LEVEL
                desenNovoLevel( *jogo );
                do{
                        desenhaJogo( jogo );
                        atualizaJogo( jogo );
                }while( !_FIM_DE_JOGO  &&  !checaNovoLevel( *jogo ) );

                if( !_FIM_DE_JOGO ) jogo->snake.level++;    // Incrementar level
        }while( !_FIM_DE_JOGO  );

        sincronizarSomJogo( jogo ,"d" );

        desenFimJogo( *jogo );          // Desenha frase de fim de jogo

        salvaPontuac( jogo );   // Salvar Pontuação

        colorirTela( jogo , COR_FUNDO_AREA_EXTERNA );
        exibirHighScores( jogo , 0 );
        pausaMS( 100 );
        while( !( checaTecla_Pressionada( VK_RETURN )  ||  checaTecla_Pressionada( VK_SPACE )  ||  checaTecla_Pressionada( VK_ESCAPE ) ) );
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
        FLAG flag_voltar = false;
        int level = 1;

        colorirTela( jogo , COR_FUNDO_AREA_EXTERNA );
        printFonte("ESCOLHA O MAPA" , jogo->res.fonte_small , (PONTO){ ( jogo->tela.cols - strlen_fonte( "ESCOLHA DO MAPA" , jogo->res.fonte_small , 4 ) ) / 2  , 2 } , 4 , VERDE_LIMA , COR_FUNDO_AREA_EXTERNA );

        do{
                if( checaTecla_Pressionada( VK_ESCAPE ) ) flag_voltar = true;
                if( checaTecla_Pressionada( VK_DOWN )  &&  level < QTD_LEVELs + 1) level++;
                if( checaTecla_Pressionada( VK_UP )  &&  level > 1 ) level--;

                if( level == QTD_LEVELs ) sincronizarSomJogo( jogo , "eb");
                else sincronizarSomJogo( jogo , "ef");

                for( int i = 1 ; i <= QTD_LEVELs ; i++ )
                        print_PRO( nomes_levels( i ) , (PONTO){ ( jogo->tela.cols - strlen( nomes_levels( i ) ) ) / 2 , 2 + jogo->res.fonte_big.altu + jogo->res.fonte_small.altu + 2 * i } , PADRAO , i != level ? BRANCO : AMARELO , COR_FUNDO_AREA_EXTERNA );

                print_PRO( "VOLTAR AO MAIN MENU" , (PONTO){ ( jogo->tela.cols - strlen( "VOLTAR AO MAIN MENU" ) ) / 2 , 2 + jogo->res.fonte_big.altu + jogo->res.fonte_small.altu + 2 * 15 } , PADRAO , 15 != level ? BRANCO : AMARELO , COR_FUNDO_AREA_EXTERNA );

                pausaMS( MENU_DELAY );
        }while( !checaTecla_Pressionada( VK_RETURN )  &&  !flag_voltar );

        if( level == 15 )
                flag_voltar = true;
        else
                jogo->snake.level = level;

        if( !flag_voltar ){
                inicializarNovoLevel( jogo );    // Reinicializa os dados do jogo para NOVO LEVEL
                jogo->flag_modo_infinito = true;

                desenNovoLevel( *jogo );

                do{
                        desenhaJogo( jogo );
                        atualizaJogo( jogo );
                }while( !_FIM_DE_JOGO  );
                pausaS( DELAY_FIM_LEVEL );

                salvaPontuac( jogo );   // Salvar Pontuação

                colorirTela( jogo , COR_FUNDO_AREA_EXTERNA );
                exibirHighScores( jogo , level );
                pausaMS( 100 );
                while( !( checaTecla_Pressionada( VK_RETURN )  ||  checaTecla_Pressionada( VK_SPACE )  ||  checaTecla_Pressionada( VK_ESCAPE ) ) );
        }
}
//#####################################################



/** \brief (Item do MainMenu ) Abre menu secundário de escolha de dificuldade do jogo
 *
 * \param JOGO*
 * \return void
 *
 */
void dificuldade( JOGO* jogo ){
        FLAG flag_voltar = false;
        FLAG flag_voltar_liberado = false;
        FONTE fonte = jogo->res.fonte_small;
        const int esp = 4;
        char tit[] = "DIFICULDADE:";
        char setas[][ 5 ] = { "<-" , "->" };
        char difs[][ 20 ] = { "FACIL" , "NORMAL" , "DIFICIL" , };
        char voltar[] = "VOLTAR";
        int tam_tit = strlen_fonte( tit , fonte , esp );
        int tam_setas = strlen_fonte( setas[ 0 ] , fonte , esp);
        int tam_voltar = strlen_fonte( voltar , fonte , esp );
        int tam_difs[ 3 ];
        for( int i = 0 ; i < 3 ; i++) tam_difs[ i ] = strlen_fonte( difs[ i ] , fonte , esp);

        const PONTO centro_tela = { jogo->tela.cols / 2 , jogo->tela.lins / 2 };
        const int y_tit = centro_tela.y - fonte.altu - 3;
        const int y_setas = centro_tela.y + fonte.altu / 2;
        const int larg_espaco_dificuldades = tam_tit + 2;
        const int x_setas[ 2 ] = {
                centro_tela.x - larg_espaco_dificuldades / 2  - tam_setas,
                centro_tela.x + larg_espaco_dificuldades / 2
        };

        COR cor_setas = VERDE_AZULADO_ESCURO;
        COR cor_voltar = CINZA_5;
        int dif_atual = jogo->dificuldade_escolhida;

        desenRetang( 0 , 0 , jogo->tela.cols , jogo->tela.lins , COR_FUNDO_AREA_EXTERNA );
        printFonte( tit , fonte , (PONTO){ centro_tela.x - tam_tit / 2 , y_tit } , esp , VERDE_MUSGO , COR_FUNDO_AREA_EXTERNA );

        sincronizarSomJogo( jogo , "hf" );
        do{
                if( checaTecla_Pressionada( VK_RIGHT ) ){
                        desenRetang( centro_tela.x - tam_difs[ dif_atual - 1 ] / 2 , centro_tela.y , tam_difs[ dif_atual - 1 ] , fonte.altu , COR_FUNDO_AREA_EXTERNA );
                        jogo->dificuldade_escolhida++;
                }else
                        if( checaTecla_Pressionada( VK_LEFT ) ){
                                desenRetang( centro_tela.x - tam_difs[ dif_atual - 1 ] / 2 , centro_tela.y , tam_difs[ dif_atual - 1 ] , fonte.altu , COR_FUNDO_AREA_EXTERNA );
                                jogo->dificuldade_escolhida--;
                        }

                if( jogo->dificuldade_escolhida == 0 ) jogo->dificuldade_escolhida = DIFICIL;
                if( jogo->dificuldade_escolhida == 4 ) jogo->dificuldade_escolhida = FACIL;

                dif_atual = jogo->dificuldade_escolhida;

                for( int i = 2 ; i ; i-- )
                        printFonte(
                                setas[ i - 1 ] ,
                                fonte ,
                                (PONTO){
                                        x_setas[ i - 1 ] ,
                                        y_setas
                                } ,
                                esp ,
                                cor_setas ,
                                COR_FUNDO_AREA_EXTERNA
                        );

                printFonte(
                        difs[ dif_atual - 1 ] ,
                        fonte ,
                        (PONTO){
                                centro_tela.x - tam_difs[ dif_atual - 1 ] / 2 ,
                                centro_tela.y } ,
                        esp ,
                        cor_setas ,
                        COR_FUNDO_AREA_EXTERNA
                );

                printFonte(
                        voltar ,
                        fonte ,
                        (PONTO){
                                centro_tela.x - tam_voltar / 2 ,
                                jogo->tela.lins - fonte.altu - 1 } ,
                        esp ,
                        cor_voltar ,
                        COR_FUNDO_AREA_EXTERNA
                );

                if( !flag_voltar_liberado ){
                        if( checaTecla_Pressionada( VK_DOWN )
                           ||  checaTecla_Pressionada( VK_RETURN )
                           ||  checaTecla_Pressionada( VK_SPACE ) ){
                                cor_setas = CINZA_5;
                                cor_voltar = 172;
                                flag_voltar_liberado = true;
                                sincronizarSomJogo( jogo , "hb" );
                        }
                }else{
                        if( checaTecla_Pressionada( VK_RETURN )
                           ||  checaTecla_Pressionada( VK_SPACE ) )
                                flag_voltar = true;

                        if( checaTecla_Pressionada( VK_UP )
                           ||  checaTecla_Pressionada( VK_DOWN ) ){
                                flag_voltar_liberado = false;
                                cor_setas = VERDE_AZULADO_ESCURO;
                                cor_voltar = CINZA_5;
                                sincronizarSomJogo( jogo , "hf" );
                           }
                }

                if( checaTecla_Pressionada( VK_ESCAPE ) ) flag_voltar = true;

                pausaMS( MENU_DELAY );
                verificarFecharJogoTeclado();
        }while( !flag_voltar );
}
//#####################################################



/** \brief (Item do MainMenu ) Exibe HighScores
 *
 * \param JOGO*
 * \return void
 *
 */
void highScores( JOGO* jogo ){
        const COR cor_tit = VERDE_LIMA;
        const COR cor_fundo = PRETO;
        const COR cor_item_ns = BRANCO_BRILHANTE;
        const COR cor_item_s = AMARELO;
        int sel = 0;
        FLAG flag_sair = false;

        colorirTela( jogo , cor_fundo );
        do{
                printFonte("HIGHSCORE" , jogo->res.fonte_big , (PONTO){ ( jogo->tela.cols - strlen_fonte( "HIGHSCORES" , jogo->res.fonte_big , 4 ) ) / 2  , 2 } , 4 , cor_tit , cor_fundo );
                printFonte("CAMPANHA" , jogo->res.fonte_small , (PONTO){ jogo->tela.cols / 2 - strlen_fonte( "CAMPANHA" , jogo->res.fonte_small , 4 ) - 6  , jogo->tela.lins / 2 - jogo->res.fonte_small.altu } , 4 , ( ( sel == 0 ) ? cor_item_s : cor_item_ns ) , cor_fundo );
                printFonte("SOBREVIV." , jogo->res.fonte_small , (PONTO){ jogo->tela.cols / 2 + 6  , jogo->tela.lins / 2 - jogo->res.fonte_small.altu } , 4 , ( ( sel == 1 ) ? cor_item_s : cor_item_ns ) , cor_fundo );
                printFonte("VOLTAR" , jogo->res.fonte_small , (PONTO){ ( jogo->tela.cols - strlen_fonte( "VOLTAR" , jogo->res.fonte_small , 4 ) ) / 2  , jogo->tela.lins - jogo->res.fonte_small.altu - 1 } , 4 , ( ( sel == 2 ) ? cor_item_s : cor_item_ns ) , cor_fundo );
                cursorXY( 30 , 10 );

                if( checaTecla_Down( VK_RIGHT ) ) sel++;
                if( checaTecla_Down( VK_LEFT ) ) sel--;
                if( checaTecla_Down( VK_DOWN ) ) sel = 2;
                if( checaTecla_Down( VK_UP ) ) sel = 0;
                if( sel == - 1 ) sel = 2;
                if( sel == 3 ) sel = 0;

                if( sel == 2 ) sincronizarSomJogo( jogo , "hb" );
                else sincronizarSomJogo( jogo , "hf" );

                if( checaTecla_Pressionada( VK_RETURN ) ){
                        int level = 1;
                        FLAG flag_voltar = false;
                        if( sel < 2 ){
                                if( sel == 0 )
                                        level = 0;
                                else{
                                        colorirTela( jogo , cor_fundo );
                                        printFonte("HIGHSCORE" , jogo->res.fonte_big , (PONTO){ ( jogo->tela.cols - strlen_fonte( "HIGHSCORES" , jogo->res.fonte_big , 4 ) ) / 2  , 2 } , 4 , cor_tit , cor_fundo );
                                        printFonte("MAPAS" , jogo->res.fonte_small , (PONTO){ ( jogo->tela.cols - strlen_fonte( "MAPAS" , jogo->res.fonte_small , 4 ) ) / 2  , 2 + jogo->res.fonte_big.altu } , 4 , VERDE_AZULADO_ESCURO , cor_fundo );
                                        pausaMS( 10 );

                                        do{
                                                if( checaTecla_Pressionada( VK_ESCAPE ) ) flag_voltar = true;
                                                if( checaTecla_Pressionada( VK_DOWN )  &&  level< QTD_LEVELs + 1 ) level++;
                                                if( checaTecla_Pressionada( VK_UP )  &&  level > 1 ) level--;

                                                if( level == QTD_LEVELs ) sincronizarSomJogo( jogo , "eb");
                                                else sincronizarSomJogo( jogo , "ef");

                                                for( int i = 1 ; i <= QTD_LEVELs ; i++ ){
                                                        cursorXY( ( jogo->tela.cols - strlen( nomes_levels( i ) ) ) / 2 , 2 + jogo->res.fonte_big.altu + jogo->res.fonte_small.altu + 2 * i );
                                                        defCorTxt_PRO( i != level ? BRANCO : AMARELO , cor_fundo , PADRAO );
                                                        printf( "%s :\t%s > %d" , nomes_levels( i ) , jogo->highscores[ i ][ 0 ].nome_jogador , jogo->highscores[ i ][ 0 ].pontos );
                                                }

                                                print_PRO( "VOLTAR AO MAIN MENU" , (PONTO){ ( jogo->tela.cols - strlen( "VOLTAR AO MAIN MENU" ) ) / 2 , 2 + jogo->res.fonte_big.altu + jogo->res.fonte_small.altu + 2 * 15 } , PADRAO , 15 != level ? BRANCO : AMARELO , COR_FUNDO_AREA_EXTERNA );

                                                pausaMS( MENU_DELAY / 3 );
                                        }while( !checaTecla_Pressionada( VK_RETURN )  &&  !flag_voltar );
                                }
                                if( level == 15 )
                                        flag_voltar = true;

                                if( !flag_voltar ){
                                        colorirTela( jogo , cor_fundo );
                                        exibirHighScores( jogo , level );
                                        pausaMS( 100 );
                                        while( !( checaTecla_Pressionada( VK_RETURN )  ||  checaTecla_Pressionada( VK_SPACE )  ||  checaTecla_Pressionada( VK_ESCAPE ) ) )
                                                sincronizarSomJogo( jogo , "p" );
                                }
                                colorirTela( jogo , cor_fundo );
                        }else
                                flag_sair = true;
                }

                if( checaTecla_Pressionada( VK_ESCAPE ) )
                        flag_sair = true;

                pausaMS( MENU_DELAY / 3 );
                sincronizarSomJogo( jogo , "h" );
        }while( !flag_sair );
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



/** \brief Exibe as maiores pontuações em determinado mapa. Se sel ==0 no modo campanha
 *
 * \param JOGO*
 * \param int
 * \return void
 *
 */
void exibirHighScores( JOGO* jogo , int sel ){
        COR cor_tit = VERDE_LIMA;
        COR cor_fundo = COR_FUNDO_AREA_EXTERNA;

        if( sel == 0 )
                printFonte("HIGHSCORE - CAMPANHA" , jogo->res.fonte_small , (PONTO){ ( jogo->tela.cols - strlen_fonte( "HIGHSCORE - CAMPANHA" , jogo->res.fonte_small , 4 ) ) / 2  , 2 } , 4 , cor_tit , cor_fundo );
        else{
                char titulo[ 30 ];
                sprintf( titulo , "MAPA: %s" , nomes_levels( sel ) );
                printFonte( titulo , jogo->res.fonte_small , (PONTO){ ( jogo->tela.cols - strlen_fonte( titulo , jogo->res.fonte_small , 3 ) ) / 2  , 2 } , 3 , cor_tit , cor_fundo );
        }
        printFonte("NOME" , jogo->res.fonte_small , (PONTO){ jogo->tela.cols / 2 - strlen_fonte( "NOME" , jogo->res.fonte_small , 4 ) - 25  , 2 + jogo->res.fonte_big.altu } , 4 , VERDE_AZULADO_ESCURO , cor_fundo );
        printFonte("PTS" , jogo->res.fonte_small , (PONTO){ jogo->tela.cols / 2 + 25  , 2 + jogo->res.fonte_big.altu } , 4 , VERDE_AZULADO_ESCURO , cor_fundo );

        for( int i = 0 ; i < QTD_HIGHSCORES ; i++ ){
                char pontos[ 50 ] = "\0";
                itoa( jogo->highscores[ sel ][ i ].pontos , pontos , 10 );
                printFonte( jogo->highscores[ sel ][ i ].nome_jogador , jogo->res.fonte_small , (PONTO){ jogo->tela.cols / 2 - strlen_fonte( "NOME" , jogo->res.fonte_small , 4 ) - 25 - 4 , 2 + jogo->res.fonte_big.altu + jogo->res.fonte_small.altu + 2 + ( jogo->res.fonte_small.altu + 1 ) * i } , 4 , BRANCO_BRILHANTE , cor_fundo );
                printFonte( pontos , jogo->res.fonte_small , (PONTO){ jogo->tela.cols / 2 + 25 - 2 , 2 + jogo->res.fonte_big.altu + jogo->res.fonte_small.altu + 2 + ( jogo->res.fonte_small.altu + 1 ) * i } , 4 , BRANCO_BRILHANTE , cor_fundo );
        }
}
//#####################################################



