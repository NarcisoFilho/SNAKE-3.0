
#include "definicoes_jogo.h"


/** \brief Desenha a frase Game Over com mensagem extra
 *
 * \param JOGO
 * \return void
 *
 */
void desenFimJogo( JOGO jogo ){
        char msg_2[ 100 ] = "A persist\210ncia \202 o caminho do \210xito!";
        char msg_1[ 100 ];
        COR cor_texto_inicial;
        COR cor_texto_final;
        COR cor_fundo_texto;
        COR cor_fundo_moldura;

        // Definição da mensagem e das cores
        if( jogo.snake.viva ){  /* Caso tenha zerado o jogo */
                strcpy( msg_1 , " VITORIA! " );
                cor_texto_inicial = VERDE_BRILHANTE;
                cor_texto_final = VERDE_BRILHANTE;
                cor_fundo_texto = VERDE_ESCURO;
                cor_fundo_moldura = VERDE_MUSGO;

        }else{  /* Caso tenha morrido */
                strcpy( msg_1 , "GAME  OVER" );
                cor_texto_inicial = VERMELHO;
                cor_texto_final = BRANCO_BRILHANTE;
                cor_fundo_texto = MAROON;
                cor_fundo_moldura = VERMELHO;

                musica_game_over();
        }

        // Limpa a tela
        desenRetang( 1 , 1 , jogo.tela.cols , jogo.tela.lins , PRETO );

        // Mensagem 1
        printFonte( msg_1 , jogo.res.fonte_big , (PONTO){ jogo.tela.cols / 2 - 40 , jogo.tela.lins / 2 } , 3 , cor_texto_inicial , PRETO );

        // Mensagem 2
        printColoridoXY( msg_2 , ( jogo.tela.cols - strlen( msg_2 ) ) / 2 , jogo.tela.lins - 3 , BRANCO_BRILHANTE );

        // Efeito moldura
        defCorTxt_PRO( BRANCO_BRILHANTE , cor_fundo_moldura , PADRAO );
        int tempo_inicial = time( NULL );
        int x , y;
        int j , i;
        char c1 = 201;
        char c2 = 203;
        char l1 = 202;
        char l2 = 188;
        x = y = 0;
        j = i = 0;
        FLAG e , b;
        e = b = true;
        do{
                if( b ){
                        cursorXY( jogo.tela.cols / 2 - 40 - 4 + x , jogo.tela.lins / 2 - 1 + y );
                        printf("%c%c" , c1 , c2 );
                        cursorXY( jogo.tela.cols / 2 - 40 - 4 + 81 + 5 - j , jogo.tela.lins / 2 - 1 + jogo.res.fonte_big.altu - i );
                        printf("%c%c" , l1 , l2 );
                }

                if( e  &&  y < jogo.res.fonte_big.altu  ){
                        y++;
                        i++;
                        c1 = 186;
                        c2 = 186;
                        l1 = 186;
                        l2 = 186;
                        if( y == jogo.res.fonte_big.altu ) c1 = 200 , c2 = 202;
                        if( i == jogo.res.fonte_big.altu ) l1 = 203 , l2 = 187;
                        pausaMS( 30 );
                }else{
                        e = false;
                        if( b  &&  x < 81 + 2 ){
                                c1 = 205;
                                c2 = 205;
                                l1 = 205;
                                l2 = 205;
                                x += 2;
                                j += 2;
                                pausaMS( 30 );
                        }else{
                                if( b ){
                                        b = false;
                                        desenRetang( jogo.tela.cols / 2 - 40 - 4 + 2 , jogo.tela.lins / 2 - 1 + 1 , 84 , jogo.res.fonte_big.altu - 1 , cor_fundo_texto );
                                        printFonte( msg_1 , jogo.res.fonte_big , (PONTO){ jogo.tela.cols / 2 - 40 , jogo.tela.lins / 2 } , 3 ,  cor_texto_final , cor_fundo_texto  );
                                        pausaMS( 60 );
                                }

                        }
                }

        }while( time( NULL ) - tempo_inicial < DELAY_MSG_GAME_OVER );
}
//#####################################################



/** \brief Apresenta o novo level com efeito legal de entrada
 *
 * \param JOGO
 * \return void
 *
 */
void desenNovoLevel( JOGO jogo ){
        char msg[ 20 ];
        sprintf( msg , "Level %d" , jogo.snake.level );
        char nome[ 30 ];
        sprintf( nome ,  "Mapa: %s" , nomes_levels( jogo.snake.level ) );

        FONTE fonte = jogo.res.fonte_small;
        int esp = 4;
        int altu = fonte.altu;
        int tam = strlen_fonte( msg , fonte , esp );
        int tam_nome = strlen_fonte( nome , fonte , esp );
        int x_fim_msg = ( jogo.tela.cols - tam ) / 2;
        int x_fim_nome = ( jogo.tela.cols - tam_nome ) / 2;
        const int inc = 2;
        const int delay = 5;
        COR cor = 1;
        COR cor_nome = jogo.snake.level;
        COR cor_fundo_nome = PRETO;

        if( jogo.snake.level == 13 ) cor_nome = AMARELO , cor_fundo_nome = VERDE;
        if( jogo.snake.level == 14 ) cor_nome = LARANJA , cor_fundo_nome = CINZA_8;

        desenRetang( 1 , 1 , jogo.tela.cols , jogo.tela.lins , PRETO );

        printFonte( nome , fonte , (PONTO){ x_fim_nome , jogo.tela.lins / 2 + 1 } , esp , cor_nome , PRETO );

        if( !jogo.flag_modo_infinito ){
                for( int x = - tam ; x <= x_fim_msg ; x += inc ){
                        printFonte( msg , fonte , (PONTO){ x , jogo.tela.lins / 2 - altu } , esp , cor , PRETO );

                        pausaMS( delay );

                        printFonte( msg , fonte , (PONTO){ x , jogo.tela.lins / 2 - altu } , esp , PRETO , PRETO );

                        if( !( x % 5 ) ) cor++;
                }

                printFonte( msg , fonte , (PONTO){ x_fim_msg , jogo.tela.lins / 2 - altu } , esp , COR_APRESENTAR_LEVEL , PRETO );
        }

        if( jogo.snake.level == 13 ) desenRetang_R( (RETANG){ (PONTO){ x_fim_nome - 1 , jogo.tela.lins / 2 + 1 - 1 } , tam_nome + 2 , fonte.altu + 2 } , ' '  , VERDE , VERDE );
        if( jogo.snake.level == 14 ) desenRetang_R( (RETANG){ (PONTO){ x_fim_nome - 1 , jogo.tela.lins / 2 + 1 - 1 } , tam_nome + 2 , fonte.altu + 2 } , ' '  , CINZA_8 , CINZA_8 );

        printFonte( nome , fonte , (PONTO){ x_fim_nome , jogo.tela.lins / 2 + 1 } , esp , cor_nome , cor_fundo_nome );

        pausaS( DELAY_FIM_LEVEL );

}
//#####################################################



/** \brief Retorna o nome dos mapas
 *
 * \param int : Número do level
 * \return char* : Nome do mapa do respectivo level
 *
 */
char* nomes_levels( int level ){
        static char nome[][ 30 ] = {
                "Passeio no Parque",
                "Encruzilhada",
                "Chicago",
                "Manhatan",
                "Las Vegas",
                "Cairo",
                "S. Paulo",
                "Labirinto",
                "Apartamentos",
                "Porto Alegre",
                "Circuito Impresso",
                "Laranjeiras",
                "Brasil",
                "Carcara Flight"
        };

        return nome[ level - 1 ];
}
//#####################################################
