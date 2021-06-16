

#include "definicoes_jogo.h"


/** \brief Atualiza o jogo
 *
 * \param JOGO*
 * \return void
 *
 */
void atualizaJogo( JOGO* jogo ){
        // Atualização de Flags
        atualizarFlagsRedesenho( jogo );

        // SNAKE
        atualizaSentidoSnake( jogo );
        if( jogo->flag_level_desenho_volatil ){
                atualizaPosSnake( &jogo->snake );
                verificaPosSnake_limites( jogo );
                verificaPosSnake_obstaculos( jogo );
                verificaPosSnake_autoColisao( jogo );
        }

        // SOM
        atualizarSom( jogo );

        // ALIMENTO
        geraAlimento( jogo );
        coletarAlimento( jogo );
        coletarDinheiro( jogo );

        // PORTAL
        atualizaPortal( jogo );

        // PAUSE
        atualizaPause( jogo );
}
//#####################################################


/** \brief Atualiza a snake
 *
 * \param SNAKE*
 * \return void
 *
 */
void atualizaPosSnake( SNAKE* snake ){
        // Posição dos blocos do corpo ( Cada bloco ocupa a posição do bloco subsequente da snake )
        for( int i = snake->tam - 1 ;  i ; i-- ){
                snake->pos[ i ].x = snake->pos[ i - 1 ].x;
                snake->pos[ i ].y = snake->pos[ i - 1 ].y;
        }

        // Posição do bloco frontal
        snake->pos[ 0 ].x += 2 * dtoi( cos( gtor( snake->sentido ) ) );
        snake->pos[ 0 ].y -= dtoi( sin( gtor( snake->sentido ) ) );
}
//#####################################################


/** \brief Pausa e despausa o jogo
 *
 * \param JOGO*
 * \return void
 *
 */
void atualizaPause( JOGO* jogo ){
        if( checaTecla_Down( 0x50 )  ||  checaTecla_Down( VK_RETURN )  ||  checaTecla_Down( VK_ESCAPE ) ){
                TECLA teclas[ 10 ] = { VK_RETURN , 0x50 , 0 };
                FLAG f_d_obst = false;
                FLAG f_d_snake = false;
                FLAG f_d_alim = false;
                FLAG f_d_dinh = false;

                char msg[ 10 ] = "PAUSE";
                COR cor = AMARELO;
                int espac = 4;
                FONTE fonte = jogo->res.fonte_small;
                PONTO ponto;
                ponto.x = ( jogo->tela.cols - strlen_fonte( msg , fonte , espac ) ) / 2;
                ponto.y = jogo->tela.lins / 2;
                RETANG retang = { { ponto.x - 1 , ponto.y - 1 }  , strlen_fonte( msg , fonte , espac ) + 2 , fonte.altu + 2 };

                desenMoldura_R( retang , cor , COR_FUNDO_AREA_JOGO , true );
                printFonte( msg , fonte , ponto , espac , cor , COR_FUNDO_AREA_JOGO );
                pausaMS( 100 );
                pausaTecla( teclas );
                desenRetang_R( retang , ' ' , COR_FUNDO_AREA_JOGO , COR_FUNDO_AREA_JOGO );

                for( int i = retang.ponto.y ; i < retang.ponto.y + retang.altu ; i++ )
                        for( int j = retang.ponto.x ; j < retang.ponto.x + retang.larg ; j++ ){

                                if( jogo->level[ jogo->snake.level ].matriz[ i - jogo->area_do_jogo.ponto.y ][ j - jogo->area_do_jogo.ponto.x ] != ' '
                                   &&  jogo->level[ jogo->snake.level ].matriz[ i - jogo->area_do_jogo.ponto.y ][ j - jogo->area_do_jogo.ponto.x ] != 'o'
                                   &&  jogo->level[ jogo->snake.level ].matriz[ i - jogo->area_do_jogo.ponto.y ][ j - jogo->area_do_jogo.ponto.x ] != 'p' )
                                        f_d_obst = true;

                                if( jogo->alimento.pos.y == i )
                                        if( jogo->alimento.pos.x == j )
                                                f_d_alim = true;

                                if( jogo->dinheiro.pos.y == i )
                                        if( jogo->dinheiro.pos.x == j )
                                                f_d_dinh = true;

                                for( int bloco = 0 ; bloco < jogo->snake.tam ; bloco++ )
                                        if( jogo->snake.pos[ bloco ].y == i )
                                                if( jogo->snake.pos[ bloco ].x == j )
                                                        f_d_snake = true;
                        }

                if( f_d_obst ) desenhaObstaculos( jogo );
                if( f_d_snake ||  f_d_obst ) colorirSnake( jogo , COR_SNAKE_PADRAO );
                if( f_d_alim ||  f_d_obst) desenhaAlimento( jogo );
                if( f_d_dinh ||  f_d_obst ) desenhaDinheiro( jogo );

                pausaMS( 100 );
        }



}
//#####################################################


/** \brief Verifica se a posição da snake ultrapassa os limites
 *
 * \param JOGO*
 * \return void
 *
 */
void verificaPosSnake_limites( JOGO* jogo ){
        // Limite Lateral DIREITO
        if( jogo->snake.pos[ 0 ].x  >= jogo->area_do_jogo.ponto.x + jogo->area_do_jogo.larg - 1 )
                jogo->snake.pos[ 0 ].x = jogo->area_do_jogo.ponto.x + 1;

        // Limite Lateral ESQUERDO
        if( jogo->snake.pos[ 0 ].x  <= jogo->area_do_jogo.ponto.x )
                jogo->snake.pos[ 0 ].x = jogo->area_do_jogo.ponto.x + jogo->area_do_jogo.larg - 3;

        // Limite INFERIOR
        if( jogo->snake.pos[ 0 ].y  >= jogo->area_do_jogo.ponto.y + jogo->area_do_jogo.altu - 1 )
                jogo->snake.pos[ 0 ].y = jogo->area_do_jogo.ponto.y + 1;

        // Limite SUPERIOR
        if( jogo->snake.pos[ 0 ].y  <= jogo->area_do_jogo.ponto.y )
                jogo->snake.pos[ 0 ].y = jogo->area_do_jogo.ponto.y + jogo->area_do_jogo.altu - 2;
}
//#####################################################


/** \brief Verifica se o bloco frontal da snake atinge obstáculo
 *
 * \param JOGO*
 * \return void
 *
 */
void verificaPosSnake_obstaculos( JOGO* jogo ){
        switch( dtoi( cos( gtor( jogo->snake.sentido ) ) ) ){
                case 1:         /*DIREITA*/
                        if( jogo->level[ jogo->snake.level ].matriz[ jogo->snake.pos[ 0 ].y - jogo->area_do_jogo.ponto.y ][ jogo->snake.pos[ 0 ].x + 1 - jogo->area_do_jogo.ponto.x ] != ' '
                          && jogo->level[ jogo->snake.level ].matriz[ jogo->snake.pos[ 0 ].y - jogo->area_do_jogo.ponto.y ][ jogo->snake.pos[ 0 ].x + 1 - jogo->area_do_jogo.ponto.x ] != 'o' ){
                                jogo->snake.viva = false;
                                jogo->snake.pos[ 0 ].x -= 2;
                        }
                        break;
                case -1:        /* ESQUERDA */
                        if( jogo->level[ jogo->snake.level ].matriz[ jogo->snake.pos[ 0 ].y - jogo->area_do_jogo.ponto.y ][ jogo->snake.pos[ 0 ].x - jogo->area_do_jogo.ponto.x ] != ' '
                        &&  jogo->level[ jogo->snake.level ].matriz[ jogo->snake.pos[ 0 ].y - jogo->area_do_jogo.ponto.y ][ jogo->snake.pos[ 0 ].x - jogo->area_do_jogo.ponto.x ] != 'o' ){
                                jogo->snake.viva = false;
                                jogo->snake.pos[ 0 ].x += 2;
                        }
                        break;
                case 0:
                        switch( dtoi( sin( gtor( jogo->snake.sentido ) ) ) ){
                                case 1:         /* CIMA */
                                        if( jogo->level[ jogo->snake.level ].matriz[ jogo->snake.pos[ 0 ].y - jogo->area_do_jogo.ponto.y ][ jogo->snake.pos[ 0 ].x - jogo->area_do_jogo.ponto.x ] != ' '
                                        &&  jogo->level[ jogo->snake.level ].matriz[ jogo->snake.pos[ 0 ].y - jogo->area_do_jogo.ponto.y ][ jogo->snake.pos[ 0 ].x - jogo->area_do_jogo.ponto.x ] != 'o' ){
                                                jogo->snake.viva = false;
                                                jogo->snake.pos[ 0 ].y += 1;
                                        }
                                        break;
                                case -1:        /* BAIXO */
                                        if( jogo->level[ jogo->snake.level ].matriz[ jogo->snake.pos[ 0 ].y - jogo->area_do_jogo.ponto.y ][ jogo->snake.pos[ 0 ].x - jogo->area_do_jogo.ponto.x ] != ' '
                                        &&  jogo->level[ jogo->snake.level ].matriz[ jogo->snake.pos[ 0 ].y - jogo->area_do_jogo.ponto.y ][ jogo->snake.pos[ 0 ].x - jogo->area_do_jogo.ponto.x ] != 'o' ){
                                                jogo->snake.viva = false;
                                                jogo->snake.pos[ 0 ].y -= 1;
                                        }
                                        break;
                        }

        }
}
//#####################################################


/** \brief Verifica se o bloco frontal da snake atinge outro bloco da snake
 *
 * \param JOGO*
 * \return void
 *
 */
void verificaPosSnake_autoColisao( JOGO* jogo ){
        for( int bloco = 1 ; bloco < jogo->snake.tam ; bloco++ )
                if( jogo->snake.pos[ bloco ].x == jogo->snake.pos[ 0 ].x )
                        if( jogo->snake.pos[ bloco ].y == jogo->snake.pos[ 0 ].y )
                                jogo->snake.viva = false;
}
//#####################################################


/** \brief Atualiza o sentido da  snake
 *
 * \param JOGO*
 * \return void
 *
 */
void atualizaSentidoSnake( JOGO* jogo ){
        SNAKE* snake = &jogo->snake;

        if( checaTecla_Pressionada( VK_UP ) )
                if( snake->pos[ 1 ].y != snake->pos[ 0 ].y - 1  )
                        if( snake->sentido != CIMA )
                                if( snake->sentido != BAIXO ){
                                        snake->sentido = CIMA;
                                        return;
                                }

        if( checaTecla_Pressionada( VK_DOWN ) )
                if( snake->pos[ 1 ].y != snake->pos[ 0 ].y + 1  )
                        if( snake->sentido != BAIXO )
                                if( snake->sentido != CIMA ){
                                        snake->sentido = BAIXO;
                                        return;
                                }

        if( checaTecla_Pressionada( VK_LEFT ) )
                if( snake->pos[ 1 ].x != snake->pos[ 0 ].x - 2  )
                        if( snake->sentido != ESQUERDA )
                                if( snake->sentido != DIREITA ){
                                        snake->sentido = ESQUERDA;
                                        return;
                                }
        if( checaTecla_Pressionada( VK_RIGHT ) )
                if( snake->pos[ 1 ].x != snake->pos[ 0 ].x + 2  )
                        if( snake->sentido != DIREITA )
                                if( snake->sentido != ESQUERDA ){
                                        snake->sentido = DIREITA;
                                        return;
                                }}
//#####################################################



/** \brief Atualiza as flags de redesenho
 *      Aciona o redesenho do elementos de atualização esporádica quando necessário
 *
 * \param JOGO*
 * \return void
 *
 */
void atualizarFlagsRedesenho( JOGO* jogo ){
        struct _timeb tempo;
        static struct _timeb tempo_anterior;
        _ftime( &tempo );

        if( jogo->flag_level_desenho_unico ){
                jogo->flag_level_desenho_unico = false;
                _ftime( &tempo_anterior );
        }

        if( jogo->flag_level_desenho_esporadico )
                jogo->flag_level_desenho_esporadico = false;

        if( ( ( tempo.time * 1000 + tempo.millitm ) - ( tempo_anterior.time * 1000 + tempo_anterior.millitm ) >= ( DELAY_CICLO_FACIL / (float) _DIFICULDADE ) ) ){
                jogo->flag_level_desenho_volatil = true;
                _ftime( &tempo_anterior );
        }
        else
                jogo->flag_level_desenho_volatil = false;

}
//#####################################################



/** \brief Gera os alimentos da SNAKE
 *
 * \param JOGO* jogo
 * \return void
 *
 */
void geraAlimento( JOGO* jogo ){
        FLAG pos_valida;

        if( jogo->alimento.ativo == false )
                if( jogo->level[ jogo->snake.level ].qtd_alimentos_coletados < QTD_ALIMENTOS_FINALIZAR_LEVEL  ||  jogo->flag_modo_infinito  ){
                        do{
                                jogo->alimento.pos.x = nmrRand( jogo->area_do_jogo.ponto.x + 1 , jogo->area_do_jogo.ponto.x + jogo->area_do_jogo.larg - 2 );
                                jogo->alimento.pos.y = nmrRand( jogo->area_do_jogo.ponto.y + 1 , jogo->area_do_jogo.ponto.y + jogo->area_do_jogo.altu - 2 );

                                pos_valida = true;

                                // Verificando Distanciamento do ponto de geração do alimento à Snake
                                for( int bloco = 0 ; bloco < jogo->snake.tam ; bloco++ )
                                        if( jogo->alimento.pos.y == jogo->snake.pos[ bloco ].y )
                                                if( abs( jogo->alimento.pos.x - jogo->snake.pos[ bloco ].x ) < 2 )
                                                        pos_valida = false;

                                // Verificando Não Sobreposição com obstáculo
                                if( jogo->level[ jogo->snake.level ]
                                   .matriz[ jogo->alimento.pos.y - jogo->area_do_jogo.ponto.y ]
                                   [ jogo->alimento.pos.x - jogo->area_do_jogo.ponto.x ] != ' ' )
                                                pos_valida = false;

                                // Confirmando Paridade da coordenada x
                                if( jogo->alimento.pos.x % 2  !=  ( jogo->area_do_jogo.ponto.x + 1 ) % 2 )  // Paridade de x deve ser igual ao primeiro x da area de jogo
                                        pos_valida = false;

                        }while( pos_valida == false );

                        jogo->alimento.ativo = true;
                        jogo->flag_level_desenho_esporadico = true;

                        geraDinheiro( jogo ); // Função decide randômicamente se liberará dinheiro
                }
}
//#####################################################



/** \brief Libera, esporadicamente, dinheiro, que é como um alimento especial
 *              O dinheiro fornece mais pontos. Em compesação possuem
 *      curta duração. Quanto maior o intervalo de sua geração até sua coleta menor
 *      a pontuação fornecida. No limite de tempo o dinheiro some sem fornecer
 *      pontuação.
 *
 * \param JOGO* jogo
 * \return void
 *
 */
void geraDinheiro( JOGO* jogo ){
        FLAG pos_valida;
        int nmr_sorteado;

        nmr_sorteado = nmrRand( 0 , dtoi( 100.00 / PROBABILIDADE_GERAR_DINHEIRO - 1 ) );

        if( jogo->dinheiro.ativo == false  &&  !nmr_sorteado ){
                do{
                        jogo->dinheiro.pos.x = nmrRand( jogo->area_do_jogo.ponto.x + 1 , jogo->area_do_jogo.ponto.x + jogo->area_do_jogo.larg - 2 );
                        jogo->dinheiro.pos.y = nmrRand( jogo->area_do_jogo.ponto.y + 1 , jogo->area_do_jogo.ponto.y + jogo->area_do_jogo.altu - 2 );

                        pos_valida = true;

                        // Verificando Distanciamento do ponto de geração do dinheiro à Snake
                        for( int bloco = 0 ; bloco < jogo->snake.tam ; bloco++ )
                                if( jogo->dinheiro.pos.y == jogo->snake.pos[ bloco ].y )
                                        if( abs( jogo->dinheiro.pos.x - jogo->snake.pos[ bloco ].x ) < 2 )
                                                pos_valida = false;

                        // Verificando Não Sobreposição com obstáculo
                        if( jogo->level[ jogo->snake.level ]
                           .matriz[ jogo->dinheiro.pos.y - jogo->area_do_jogo.ponto.y ]
                           [ jogo->dinheiro.pos.x - jogo->area_do_jogo.ponto.x ] != ' ' )
                                        pos_valida = false;

                        // Confirmando Paridade da coordenada x
                        if( jogo->dinheiro.pos.x % 2  !=  ( jogo->area_do_jogo.ponto.x + 1 ) % 2 )  // Paridade de x deve ser igual ao primeiro x da area de jogo
                                pos_valida = false;

                }while( pos_valida == false );

                jogo->dinheiro.ativo = true;
                _ftime( &jogo->dinheiro.momento_geracao );
        }

        // Impidir geração no início
        if( jogo->level[ jogo->snake.level ].qtd_alimentos_coletados == 0 )
                jogo->dinheiro.ativo = false;
}
//#####################################################



/** \brief Coleta os alimentos da SNAKE quando esta passa por cima de algum
 *
 * \param JOGO* jogo
 * \return void
 *
 */
void coletarAlimento( JOGO* jogo ){
        if( jogo->alimento.ativo )
                if( jogo->snake.pos[ 0 ].x == jogo->alimento.pos.x
                   || jogo->snake.pos[ 0 ].x + 1 == jogo->alimento.pos.x )
                        if( jogo->snake.pos[ 0 ].y == jogo->alimento.pos.y ){
                                jogo->alimento.ativo = false;
                                jogo->level[ jogo->snake.level ].qtd_alimentos_coletados++;
                                jogo->snake.pontos += QTD_PONTOS_ALIMENTOS_FACIL * _DIFICULDADE;
                                jogo->snake.tam += INCREMENTO_TAM_ALIMENTO;

                                for( int i = INCREMENTO_TAM_ALIMENTO ; i ; i-- )
                                        jogo->snake.pos[ jogo->snake.tam - i ] = jogo->snake.pos[ jogo->snake.tam - ( i + 1 ) ];

                                jogo->flag_level_desenho_esporadico = true;

                                sincronizarSomJogo( jogo , "ja" );
                                return;
                        }
}
//#####################################################



/** \brief Coleta o dinheiro da SNAKE quando esta passa por cima de algum
 *
 * \param JOGO* jogo
 * \return void
 *
 */
void coletarDinheiro( JOGO* jogo ){
        static int flag_brilho_coleta = 0;

        if( jogo->dinheiro.ativo ){
                struct _timeb tempo;
                _ftime( &tempo );

                jogo->dinheiro.tempo_decorrido = tempo.time * 1000 - jogo->dinheiro.momento_geracao.time * 1000
                + tempo.millitm - jogo->dinheiro.momento_geracao.millitm;

                if( jogo->dinheiro.tempo_decorrido  >  ( TEMPO_MAX_DINHEIRO_FACIL + ( jogo->snake.level - 1 ) * BONUS_TEMPO__DINHEIRO_LEVEL )
                                                                                                                        / _DIFICULDADE ){
                        jogo->dinheiro.ativo = false;
                        apagarDinheiro( jogo );
                        return;
                }

                if( jogo->snake.pos[ 0 ].x == jogo->dinheiro.pos.x
                   || jogo->snake.pos[ 0 ].x + 1 == jogo->dinheiro.pos.x )
                        if( jogo->snake.pos[ 0 ].y == jogo->dinheiro.pos.y ){
                                jogo->dinheiro.ativo = false;

                                int tempo_max = ceil( ( TEMPO_MAX_DINHEIRO_FACIL + ( jogo->snake.level - 1 ) * BONUS_TEMPO__DINHEIRO_LEVEL ) / (float)_DIFICULDADE );

                                float percentual_dinheiro = ( tempo_max - jogo->dinheiro.tempo_decorrido ) / (float)tempo_max;
                                percentual_dinheiro = pow( percentual_dinheiro , TAXA_DECAIMENTO_DINHEIRO_TEMPO );

                                float taxa_dificuldade;
                                switch( _DIFICULDADE ){
                                        case FACIL: taxa_dificuldade = .75; break;
                                        case NORMAL: taxa_dificuldade = 1.9; break;
                                        case DIFICIL: taxa_dificuldade = 3.3; break;
                                }
                                int pontos_max
                                 = ceil( QTD_PONTOS_DINHEIRO_MAX_FACIL * taxa_dificuldade );

                                int pontos_ganhos = ceil( pontos_max * percentual_dinheiro );

                                jogo->snake.pontos += pontos_ganhos;

                                jogo->snake.tam += INCREMENTO_TAM_ALIMENTO;

                                for( int i = INCREMENTO_TAM_ALIMENTO ; i ; i-- )
                                        jogo->snake.pos[ jogo->snake.tam - i ] = jogo->snake.pos[ jogo->snake.tam - ( i + 1 ) ];

                                flag_brilho_coleta = TEMPO_BRILHO_COLETA;

                                jogo->flag_level_desenho_esporadico = true;

                                sincronizarSomJogo( jogo , "jd" );
                        }
        }

        if( flag_brilho_coleta >= 1 )
                if( jogo->flag_level_desenho_volatil ){
                        if( flag_brilho_coleta > 1 )
                                jogo->snake.cor = jogo->snake.cor == COR_SNAKE_PADRAO ? BRANCO_BRILHANTE : COR_SNAKE_PADRAO;
                        else
                                jogo->snake.cor = COR_SNAKE_PADRAO;

                        colorirSnake( jogo , jogo->snake.cor );
                        flag_brilho_coleta--;
                }
}
//#####################################################



/** \brief Atualiza o status do portal
 *
 * \param JOGO* jogo
 * \return void
 *
 */
void atualizaPortal( JOGO* jogo ){
        if( jogo->flag_modo_infinito ) return;

        if( jogo->level[ jogo->snake.level ].qtd_alimentos_coletados >= QTD_ALIMENTOS_FINALIZAR_LEVEL )
                jogo->portal.ativo = true;

        if( jogo->portal.ativo )
                if( jogo->snake.pos[ 0 ].x == jogo->portal.pos.x
                   || jogo->snake.pos[ 0 ].x + 1 == jogo->portal.pos.x )
                        if( jogo->snake.pos[ 0 ].y == jogo->portal.pos.y ){

                                // Efeito de entrada no portal
                                struct _timeb tempo_inicial;
                                struct _timeb tempo;
                                _ftime( &tempo_inicial );

                                int tam = jogo->snake.tam;

                                musica_portal();
                                do{
                                        _ftime( &tempo );
                                        atualizarFlagsRedesenho( jogo );
                                        if( jogo->flag_level_desenho_volatil  &&  tam ){
                                                jogo->flag_level_desenho_esporadico = true;
                                                jogo->snake.pontos +=  QTD_PONTOS_PASSAR_LEVEL_POR_TAM_FACIL * _DIFICULDADE;
                                                tam--;
                                        }

                                        desenhaJogo( jogo );

                                        if( jogo->flag_level_desenho_volatil ){
                                                atualizaPosSnake( &( jogo->snake ) );
                                                jogo->snake.pos[ 0 ] = jogo->portal.pos;
                                        }

                                }while( tempo.time * 1000 - tempo_inicial.time * 1000 + tempo.millitm - tempo_inicial.millitm
                                       < jogo->snake.tam * ( DELAY_CICLO_FACIL / _DIFICULDADE )  +  DELAY_FIM_LEVEL * 1000 );

                                jogo->snake.flag_level_finalizado = true;
                        }
}
//#####################################################



/** \brief Verificar se Usuário Está solicitando o fechamento do jogo
 *      Aborta o jogo se usuário pressionar ctrl + f4
 *
 * \param void
 * \return void
 *
 */
void verificarFecharJogoTeclado( void ){
        if( checaTecla_Pressionada( VK_CONTROL ) )
                if( checaTecla_Pressionada( VK_F4 ) )
                        exit( 2 );
}
//#####################################################



/** \brief Salvar pontuação em HighScores ( Se pontuação for suficiente )
 *
 * \param void
 * \return void
 *
 */
void salvaPontuac( JOGO* jogo ){
        int level = jogo->flag_modo_infinito  ?  jogo->snake.level  :  0 ;

        for( int i = 0 ; i < QTD_HIGHSCORES ; i++ )
                if( jogo->snake.pontos > jogo->highscores[ level ][ i ].pontos ){
                        for( int j = QTD_HIGHSCORES - 1 ; j > i ; j-- ){
                                jogo->highscores[ level ][ j ].pontos = jogo->highscores[ level ][ j - 1 ].pontos;
                                strcpy( jogo->highscores[ level ][ j ].nome_jogador , jogo->highscores[ level ][ j - 1 ].nome_jogador );
                        }

                        jogo->highscores[ level ][ i ].pontos = jogo->snake.pontos;
                        strcpy( jogo->highscores[ level ][ i ].nome_jogador , coletarNomeJogador( jogo ) );
                        salvaHighScoresArquivo( jogo );
                        return;
                }
}
//#####################################################



/** \brief Salvar os HighScores no arquivo
 *
 * \param JOGO*
 * \return void
 *
 */
void salvaHighScoresArquivo( JOGO* jogo ){
        FILE* arq = fopen( "HighScores/highscores.bin" , "wb" );
        if( arq == NULL ) return;

        for( int i = 0 ; i <= QTD_LEVELs ; i++ )
                for( int j = 0 ; j < 5 ; j++ )
                        fwrite( &jogo->highscores[ i ][ j ] , sizeof( HIGHSCORES ) , 1 , arq );
        fclose( arq );
}
//#####################################################



/** \brief Atualiza o som
 *
 * \param JOGO*
 * \return void
 *
 */
void atualizarSom( JOGO* jogo ){
        char ch;
        FILE* arq = jogo->modo_som.arq_modo;
        rewind( arq );
        ch = fgetc( arq );
        ch = fgetc( arq );

        if( ch != 'a'  &&  ch != 'd'  &&  ch != 'm' )
                sincronizarSomJogo( jogo , "jn" );
}
//#####################################################



/** \brief Coleta o nome do jogador para salvar no highscores
 *
 * \param JOGO*
 * \return char* : Nome colefontetado
 *
 */
char* coletarNomeJogador( JOGO* jogo ){
        static char nome[ 100 ];
        strcpy( nome , "\0" );
        FONTE fonte = jogo->res.fonte_small;

        colorirTela( jogo , COR_FUNDO_AREA_EXTERNA );

        printFonte(
                "Seu Nome:",
                fonte,
                (PONTO){
                        ( jogo->tela.cols - strlen_fonte( "Seu nome" , fonte , 3 ) ) / 2 ,
                        jogo->tela.lins / 2 - fonte.altu - 5
                },
                4,
                BRANCO_BRILHANTE,
                COR_FUNDO_AREA_EXTERNA
        );

        desenMoldura_R( (RETANG){ { ( jogo->tela.cols - 117 ) / 2 , ( jogo->tela.lins - fonte.altu ) / 2 - 1 } , 117 , fonte.altu + 2 } , BRANCO_BRILHANTE , COR_FUNDO_AREA_EXTERNA , true );

        #include <conio.h>
        char ch;
        while( kbhit() ) ch = getch();

        do{
                sincronizarSomJogo( jogo , "tn" );
                if( !checaTecla_Pressionada( VK_RETURN ) ){
                        ch = getch();
                        if( ch != '\n'  &&  ch != '\r' ){
                                printFonte(
                                        nome ,
                                        fonte ,
                                        (PONTO){
                                                ( jogo->tela.cols - strlen_fonte( nome , fonte , 4 ) - 1 ) / 2 ,
                                                ( jogo->tela.lins - fonte.altu ) / 2
                                        } ,
                                        4 ,
                                        COR_FUNDO_AREA_EXTERNA ,
                                        COR_FUNDO_AREA_EXTERNA
                                );

                                if( ch == '\b' ){
                                        nome[ strlen( nome ) - 1 ] = '\0';
                                        sincronizarSomJogo( jogo , "te" );
                                }
                                else
                                        if( strlen( nome ) < TAM_MAX_NOME ){
                                                nome[ strlen( nome ) + 1 ] = '\0';
                                                nome[ strlen( nome ) ] = ch;
                                                sincronizarSomJogo( jogo , "tl" );
                                        }

                                if( strlen( nome ) ){
                                        printFonte(
                                                nome ,
                                                fonte ,
                                                (PONTO){
                                                        ( jogo->tela.cols - strlen_fonte( nome , fonte , 4 ) ) / 2 ,
                                                        ( jogo->tela.lins - fonte.altu ) / 2
                                                } ,
                                                4 ,
                                                VERDE_BRILHANTE ,
                                                COR_FUNDO_AREA_EXTERNA
                                        );
                                }
                        }
                }
        }while( !checaTecla_Pressionada( VK_RETURN ) );


        return nome;
}
//#####################################################
