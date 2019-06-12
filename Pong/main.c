#include <stdio.h>
#include <math.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>// adicionar imagens
#include <allegro5/allegro_audio.h> //bibliotecas de audio
#include <allegro5/allegro_acodec.h>//bibliotecas de audio
#include <allegro5/allegro_primitives.h>//bibliotecas para circulos tiangulos retangulos
#include <allegro5/allegro_font.h> //para escrever
#include <allegro5/allegro_ttf.h>  // para escrever

// variaveis globais
const float FPS = 100;
const int telay = 300;
const int telax = 1124;

//variaveis globais
int r=255,g=255,b=20; // variaveis das cores
int distanciax=0; //usado para testede colisao entre circulos
int distanciay=0; //usado para testede colisao entre circulos
int cont=0;

enum TECLAS {direita, esquerda,cima, baixo}; //para movimentar o circulo
bool teclas[]= {false,false,false,false};
//variaveis do circulo 1
int cx1,cy1,raio1=10;
cx1=1024;
cy1=280;
int dir1 =1; // direcao do circulo 1
int velc1 =2;// velocidado do circulo 1
//variaveis do circulo 2
int cx2,cy2,raio2=10;
cx2=1024;
cy2=20;
int dir2 =1; // direcao do circulo 2
int velc2 =2;// velocidado do circulo 2
//variaveis do circulo 3
int cx3,cy3,raio3=10;
cx3=924;
cy3=10;
int dir3 =1; // direcao do circulo 3
int velc3 =1;// velocidado do circulo 3
//variaveis do circulo 4
int cx4,cy4,raio4=10;
cx4=562;
cy4=10;
int dir4 =1; // direcao do circulo 4
int velc4 =1;// velocidado do circulo 4
//variaveis do circulo 5
int cx5,cy5,raio5=10;
cx5=600;
cy5=10;
int dir5 =1; // direcao do circulo 5
int velc5 =2;// velocidado do circulo5
//variaveis do circulo 6
int cx6,cy6,raio6=10;
cx6=700;
cy6=290;
int dir6 =1; // direcao do circulo 6
int velc6 =1;// velocidado do circulo 6
//variaveis do circulo 7
int cx7,cy7,raio7=10;
cx7=800;
cy7=10;
int dir7 =1; // direcao do circulo 7
int velc7 =1;// velocidado do circulo 7
//variaveis do circulo 8
int cx8,cy8,raio8=10;
cx8=900;
cy8=290;
int dir8 =1; // direcao do circulo 8
int velc8 =1;// velocidado do circulo 8
//variaveis do circulo 9
int cx9,cy9,raio9=10;
cx9=900;
cy9=20;
int dir9 =1; // direcao do circulo 9
int velcy9 =1;// velocidado do circulo 9
int velcx9 =2;// velocidado do circulo 9
//variaveis do circulo 10
int cx10,cy10,raio10=10;
cx10=20;
cy10=20;
int dir10 =1; // direcao do circulo 10
int velc10 =2;// velocidado do circulo 10
//variaveis do circulo 11
int cx11,cy11,raio11=10;
cx11=1074;
cy11=10;
int dir11 =1; // direcao do circulo 11
int velc11 =3;// velocidado do circulo 11
//variaveis do circulo 12
int cx12,cy12,raio12=10;
cx12=20;
cy12=280;
int dir12 =1; // direcao do circulo 12
int velc12 =2;// velocidado do circulo 12
//variaveis do circulo 13
int cx13,cy13,raio13=10;
cx13=350;
cy13=10;
int dir13 =1; // direcao do circulo 13
int velc13 =1;// velocidado do circulo 13
//variaveis do circulo 14
int cx14,cy14,raio14=10;
cx14=80;
cy14=10;
int dir14 =1; // direcao do circulo 14
int velc14 =1;// velocidado do circulo 14
//variaveis do circulo 15
int cx15,cy15,raio15=10;
cx15=500;
cy15=10;
int dir15 =1; // direcao do circulo 15
int velc15 =2;// velocidado do circulo15
//variaveis do circulo 16
int cx16,cy16,raio16=10;
cx16=400;
cy16=290;
int dir16 =1; // direcao do circulo 16
int velc16 =1;// velocidado do circulo 16
//variaveis do circulo 17
int cx17,cy17,raio17=10;
cx17=300;
cy17=10;
int dir17 =1; // direcao do circulo 17
int velc17 =1;// velocidado do circulo 17
//variaveis do circulo 18
int cx18,cy18,raio18=10;
cx18=200;
cy18=290;
int dir18 =1; // direcao do circulo 18
int velc18 =1;// velocidado do circulo 18
//variaveis do circulo 18
int cx19,cy19,raio19=10;
cx19=1074;
cy19=186;
int dir19 =1; // direcao do circulo 19
int velc19 =3;// velocidado do circulo 19
// variaveis da moeda 1
int mx1,my1,raiom1=5;
mx1=550;
my1=150;
// variaveis da moeda 2
int mx2,my2,raiom2=5;
mx2=1000;
my2=40;
// variaveis da moeda 3
int mx3,my3,raiom3=5;
mx3=1000;
my3=260;

// VARIAVEIS DA BOMBA
bool vira=false;// GIRA A BOMBA
int bx=40;// posicoes iniciais da bomba
int by=40;
int velb=1;//velocidade da bomba

void colisao_com_circulos(); //direcao ecolisao da bomba com os obstaculos
void colisao_horizontal();//direcao e colisao dos obstaculos com a tela em x
void colisao_vertical();//direcao e colisao dos obstaculos com a tela em y
void colisao_diagonal1();//direcao e colisao dos obstaculos com tela em x ou y
void colisao_diagonal2();//direcao e colisao dos obstaculos com tela em x ou y

int main(int argc, char **argv)
{
    ALLEGRO_DISPLAY *display = NULL; //declara o display
    ALLEGRO_FONT *fonte = NULL; // declara a fonte pra escrever
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;// os eventos
    ALLEGRO_TIMER *timer = NULL;// tempo para teclado mouse e eventos
    ALLEGRO_TTF_NO_KERNING;
    ALLEGRO_AUDIO_STREAM *musica= NULL;
    ALLEGRO_SAMPLE *sample =NULL;


    if(!al_init())  //OS IF's COM !...... INICIAM E TESTAM O FUNCINAMENTO DAS FUCOES INPLICITAS USADAS
    {
        fprintf(stderr, "failed to initialize allegro!\n");
        return -1;
    }
    al_init_font_addon(); // busca para iniciar as fontes
    if(!al_init_ttf_addon())   // testa se deu certo
    {
        fprintf(stderr, "falha na fonte ttf\n");
        return -1;
    }
    timer = al_create_timer(1.0 / FPS);
    if(!timer)
    {
        fprintf(stderr, "failed to create timer!\n");
        return -1;
    }

    bool redraw = true;
    al_set_new_display_flags(ALLEGRO_OPENGL | ALLEGRO_WINDOWED);
    display = al_create_display(telax, telay);
    if(!display)
    {
        fprintf(stderr, "failed to create display!\n");
        al_destroy_timer(timer);
        return -1;
    }

    if(!al_install_keyboard())
    {
        fprintf(stderr, "failed to initialize the keyboard!\n");
        return -1;
    }
    if(!al_install_audio())
    {
        fprintf(stderr, "failed to initialize the audio!\n");
        return -1;
    }
    if(!al_init_acodec_addon())
    {
        fprintf(stderr, "failed to initialize the codecs audio!\n");
        return -1;
    }
    if(!al_reserve_samples(1))
    {
        fprintf(stderr, "failed to alocar canais de audio!\n");
        return -1;
    }
    if(!al_init_image_addon())
    {
        fprintf(stderr, "failed to initialize the image addon!\n");
        return -1;
    }
    if(!al_init_primitives_addon())
    {
        fprintf(stderr, "failed to initialize the primitives addon!\n");
        return -1;
    }
    al_set_target_bitmap(al_get_backbuffer(display));
    event_queue = al_create_event_queue();
    if(!event_queue)
    {
        fprintf(stderr, "failed to create event_queue!\n");
        return-1;
    }
    fonte = al_load_ttf_font("arial.ttf",20,NULL); //CRIA A FONTE PARA CONTAR AS MORTES
    if(!fonte)
    {
        al_destroy_display(display);
        al_destroy_timer(timer);
        fprintf(stderr, "falha no carregar a fonte!\n");
        return -1;
    }
    musica= al_load_audio_stream("missao.ogg",4,1024);
    if(!musica)
    {
        fprintf(stderr, "falha no carregar a musica!\n");
    }

    ALLEGRO_BITMAP *menuinicial =NULL;  // cria os ponteiros das imagens
    ALLEGRO_BITMAP *bomba =NULL;
    ALLEGRO_BITMAP *fundo =NULL;
    ALLEGRO_BITMAP *gameover =NULL;

    menuinicial = al_load_bitmap("menuinicial.png");
    if(!menuinicial)
    {
        al_destroy_display(display);
        al_destroy_timer(timer);
        fprintf(stderr, "falha no carregar o menu inicial!\n");
        return -1;
    }
    bomba = al_load_bitmap("bomba.png");
    if(!bomba)
    {
        al_destroy_display(display);
        al_destroy_timer(timer);
        fprintf(stderr, "falha no carregar a bomba!\n");
        return -1;
    }
    fundo = al_load_bitmap("fundo.png");
    if(!fundo)
    {
        al_destroy_display(display);
        al_destroy_timer(timer);
        fprintf(stderr, "falha no carregar a imagem de fundo!\n");
        return -1;
    }
    gameover = al_load_bitmap("gameover.png");
    if(!gameover)
    {
        al_destroy_display(display);
        al_destroy_timer(timer);
        fprintf(stderr, "falha no carregar a imagem de fundo!\n");
        return -1;
    }
    // REGISTROS DOS EVENTOS E INICIALIZACAO
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_clear_to_color(al_map_rgb(200,200,200));
    al_attach_audio_stream_to_mixer(musica,al_get_default_mixer()); //inicia a musica do misssao impossivel
    al_set_audio_stream_playing(musica,false); // NAO TOCA A MUSICA DE FUNDO
    al_start_timer(timer); // inicia o tempo loop
    al_flip_display(); //atualiza a tela

    bool ganhou=false;
    bool inicio=false;
    bool moeda1=false,moeda2=false,moeda3=false;
    int i=0,aux=0;
    while(1)
    {
        ALLEGRO_EVENT ev; // INICIALIZA OS EVENTOS TIPO INTERRUPCAO
        al_wait_for_event(event_queue, &ev);

        al_draw_bitmap(menuinicial,0,0,0);
        al_draw_text(fonte, al_map_rgb(255, 255, 255), 1124/2, 270, ALLEGRO_ALIGN_CENTRE, "Press space to start");

        if(ev.keyboard.keycode==ALLEGRO_KEY_SPACE)
        {
            inicio=true;
        }

        while (inicio==true)
        {
            ALLEGRO_EVENT ev; // INICIALIZA OS EVENTOS TIPO INTERRUPCAO
            al_wait_for_event(event_queue, &ev);
            redraw = true;  //FUNCAO PARA REDESENAHR NO DIPLAY O QUE FOI ATUALIZADO

            if(ev.type == ALLEGRO_EVENT_TIMER)
            {
                al_set_audio_stream_playing(musica,true); //toca a musica de fundo deveria nao parar
                if (cont!=aux){
                moeda1=false;// se a pegar a moeda e morrer a moeda volta para a tela
                moeda2=false;
                moeda3=false;
                }
                aux=cont;
                if((bx+35>mx1-raiom1) && (bx<mx1+raiom1)) //se pegou a moeda1 pode ganhar
                {
                    if((by+33>my1-raiom1) && (by<my1+raiom1))
                    {
                        moeda1=true;
                    }
                }
                if((bx+35>mx2-raiom2) && (bx<mx2+raiom2)) //se pegou a moeda2 pode ganhar
                {
                    if((by+33>my2-raiom2) && (by<my2+raiom2))
                    {
                        moeda2=true;
                    }
                }
                if((bx+35>mx3-raiom3) && (bx<mx3+raiom3)) //se pegou a moeda3 pode ganhar
                {
                    if((by+33>my3-raiom3) && (by<my3+raiom3))
                    {
                        moeda3=true;
                    }
                }
                // detecta se chegou no fim da tela e se pegou a moeda
                if(bx+42>=telax && by>=(telay-50)/2 && by+33<=(telay+50)/2 && moeda1==true && moeda2==true && moeda3==true)
                {
                    ganhou=true;
                }
                //TESTE DE COLISAO DO CIRCULO SOLTO COM A TELA EM X E Y
                cx9+=velcx9;
                cy9+=velcy9;
                if(cx9+raio9>=telax-80)velcx9*=-1;   //DIREITA
                if(cy9+raio9>=telay) velcy9*=-1;    //BAIXO
                if(cx9-raio9<=80)  velcx9*=-1;     //ESQUERDA
                if(cy9-raio9<=0) velcy9*=-1;      //CIMA
//----------------------------------------------------------------------------------------
                if(bx+40<telax) // COLISAO DA BOMBA COM A TELA SE NAO COLIDE ELA MOVE
                    bx+=teclas[direita]*velb;
                if(by+36<=telay)
                    by+=teclas[baixo]*velb;
                if(bx>0)
                    bx-=teclas[esquerda]*velb;
                if(by+3>=0)
                    by-=teclas[cima]*velb;

//-------------------------------------------------------------------------------------
                // FAZ COM QUE O CIRCULO1  vermelho  - HORIZONTAL
                colisao_horizontal(&cx1,&velc1,&dir1,&telax,&raio1); //manda o circulo 1 para andar na horizontal
                colisao_horizontal(&cx2,&velc2,&dir2,&telax,&raio2);      // FAZ COM QUE O CIRCULO 2 verde fraco horizontal
                colisao_horizontal(&cx10,&velc10,&dir10,&telax,&raio10); //manda o circulo 1 para andar na horizontal
                colisao_horizontal(&cx12,&velc12,&dir12,&telax,&raio12);      // FAZ COM QUE O CIRCULO 2 verde fraco horizontal
                colisao_vertical(&cy18,&velc18,&dir18,&telay,&raio18);      // FAZ COM QUE O CIRCULO18 preto
                colisao_vertical(&cy11,&velc11,&dir11,&telay,&raio11);      // FAZ COM QUE O CIRCULO11 preto
                colisao_vertical(&cy8,&velc8,&dir8,&telay,&raio8);      // FAZ COM QUE O CIRCULO8 preto
                colisao_vertical(&cy5,&velc5,&dir5,&telay,&raio5);      // MOVIMENTO NA VERTICAL
                colisao_vertical(&cy6,&velc6,&dir6,&telay,&raio6);      // MOVIMENTO NA VERTICAL
                colisao_vertical(&cy7,&velc7,&dir7,&telay,&raio7);      // MOVIMENTO NA VERTICAL
                colisao_vertical(&cy15,&velc15,&dir15,&telay,&raio15);      // MOVIMENTO NA VERTICAL
                colisao_vertical(&cy16,&velc16,&dir16,&telay,&raio16);      // MOVIMENTO NA VERTICAL
                colisao_vertical(&cy17,&velc17,&dir17,&telay,&raio17);      // MOVIMENTO NA VERTICAL
                colisao_verticalmenos(&cy19,&velc19,&dir19,&telay,&raio19);      // FAZ COM QUE O CIRCULO11 preto
                colisao_diagonal1(&cy3,&cx3,&velc3,&dir3,&telay,&telax,&raio3); // FAZ COM QUE O CIRCULO3  azul  DIAGORNAL PRIMARIA
                colisao_diagonal1(&cy13,&cx13,&velc13,&dir13,&telay,&telax,&raio13); // FAZ COM QUE O CIRCULO3  azul  DIAGORNAL PRIMARIA
                colisao_diagonal2(&cy4,&cx4,&velc4,&dir4,&telay,&telax,&raio4); // FAZ COM QUE O CIRCULO 4 branco  DIAGONAL SECUNDARIA
                colisao_diagonal2(&cy14,&cx14,&velc14,&dir14,&telay,&telax,&raio14); // FAZ COM QUE O CIRCULO 4 branco  DIAGONAL SECUNDARIA
                // CONDICOES DE TROCA DE DIRECAO DOS CIRCULOS SEM ESSAS CONDICOES VAI ATE O FINAL PRA VOLTAR
                if(cy11+raio11>=(telay-50)/2) dir11=-1;
                if(cy19-raio19<=(telay+50)/2) dir19=-1;
                if(cy19+raio19>=telay) dir19=1;

                // TESTE DE COLISAO DA BOMBA COM Os CIRCULOs
                colisao_com_circulos(&bx,&by,&cx1,&cy1,&raio1);
                colisao_com_circulos(&bx,&by,&cx2,&cy2,&raio2);
                colisao_com_circulos(&bx,&by,&cx3,&cy3,&raio3);
                colisao_com_circulos(&bx,&by,&cx4,&cy4,&raio4);
                colisao_com_circulos(&bx,&by,&cx5,&cy5,&raio5);
                colisao_com_circulos(&bx,&by,&cx6,&cy6,&raio6);
                colisao_com_circulos(&bx,&by,&cx7,&cy7,&raio7);
                colisao_com_circulos(&bx,&by,&cx8,&cy8,&raio8);
                colisao_com_circulos(&bx,&by,&cx9,&cy9,&raio9);
                colisao_com_circulos(&bx,&by,&cx10,&cy10,&raio10);
                colisao_com_circulos(&bx,&by,&cx11,&cy11,&raio11);
                colisao_com_circulos(&bx,&by,&cx12,&cy12,&raio12);
                colisao_com_circulos(&bx,&by,&cx13,&cy13,&raio13);
                colisao_com_circulos(&bx,&by,&cx14,&cy14,&raio14);
                colisao_com_circulos(&bx,&by,&cx15,&cy15,&raio15);
                colisao_com_circulos(&bx,&by,&cx16,&cy16,&raio16);
                colisao_com_circulos(&bx,&by,&cx17,&cy17,&raio17);
                colisao_com_circulos(&bx,&by,&cx18,&cy18,&raio18);
                colisao_com_circulos(&bx,&by,&cx19,&cy19,&raio19);
            }//fim do evento de tempo

            // VERIFICADOR SE UMA TECLA FORI APERTADA
            else if(ev.type == ALLEGRO_EVENT_KEY_DOWN) // SE UMA TECLA ESTIVER APERTADA
            {
                switch(ev.keyboard.keycode) // LE QUAL TECLA FOI APERTADA
                {
                case ALLEGRO_KEY_RIGHT: // PARA A DIREITA
                    teclas[direita]=true;
                    vira=true;
                    break;
                case ALLEGRO_KEY_LEFT: // PARA A ESQUERDA
                    teclas[esquerda]=true;
                    vira=false;
                    break;
                case ALLEGRO_KEY_DOWN: // PARA BAIXO
                    teclas[baixo]=true;
                    break;
                case ALLEGRO_KEY_UP: // PARA CIMA
                    teclas[cima]=true;
                    break;

                case ALLEGRO_KEY_ESCAPE: //sai do jogo no esc
                    return 0;
                    break;
                }
            }
            else if(ev.type == ALLEGRO_EVENT_KEY_UP)// QUANDO SOLTA O TECLADO
            {
                // verifica se o botao foi solto
                switch(ev.keyboard.keycode)
                {
                case ALLEGRO_KEY_UP:// se nao estiver mais apertando a tecla para cima
                    teclas[cima]=false;
                    break;
                case ALLEGRO_KEY_DOWN:// se nao estiver mais apertando a tecla para baixo
                    teclas[baixo]=false;
                    break;
                case ALLEGRO_KEY_LEFT: // se nao estiver mais apertando a tecla para esquerda
                    teclas[esquerda]=false;
                    break;
                case ALLEGRO_KEY_RIGHT: // se nao estiver mais apertando a tecla para direita
                    teclas[direita]=false;
                    break;
                }
            }
//--------------------------------------------------------------------------------------------------------------------------------------
            while (ganhou==true)    //
            {
                ALLEGRO_EVENT ev; // INICIALIZA OS EVENTOS TIPO INTERRUPCAO
                al_wait_for_event(event_queue, &ev);
                for(i=0; i<4; i++) //desligar as teclas da bomba
                {teclas[i]=false;}
                al_draw_filled_rectangle(0,0,telax,telay, al_map_rgb(13,13,13));
                al_draw_bitmap(gameover,(telax-438)/2,0,0);
                al_draw_text(fonte, al_map_rgb(255, 255, 255),50,telay/2, ALLEGRO_ALIGN_LEFT, "PRESS ESC TO EXIT");
                al_draw_text(fonte, al_map_rgb(255, 255, 255),15,(telay+50)/2, ALLEGRO_ALIGN_LEFT, "PRESS SPACE TO RESTART");
                bx=40;
                by=40;
                if(ev.keyboard.keycode== ALLEGRO_KEY_ESCAPE)
                {
                    //sai do jogo no esc
                    moeda1=false;
                    moeda2=false;
                    moeda3=false;
                    inicio=false;
                    ganhou=false;
                    return 0;
                }
                if(ev.keyboard.keycode== ALLEGRO_KEY_SPACE)
                {
                    //sai do jogo no reinicia o jogo
                    moeda1=false;
                    moeda2=false;
                    moeda3=false;
                    inicio=true;
                    cont=0;
                    raio9=10;
                    ganhou=false;
                }
                al_flip_display(); // atualiza o display para aparecer o menu
            }// fim do while ganhou


            if(redraw && al_is_event_queue_empty(event_queue))// ATUALIZA O DISPLAY
            {

                redraw = false;
                al_draw_bitmap(fundo,0,0,0);
                if(moeda1==false) al_draw_filled_circle(mx1,my1,raiom1,al_map_rgb(255,255,20));  // DESENHA A MOEDA 1
                if(moeda2==false) al_draw_filled_circle(mx2,my2,raiom2,al_map_rgb(255,255,20));  // DESENHA A MOEDA 2
                if(moeda3==false) al_draw_filled_circle(mx3,my3,raiom3,al_map_rgb(255,255,20));  // DESENHA A MOEDA 3
                al_draw_bitmap(bomba,bx,by,vira);//DESENHA A BOMBA
                al_draw_textf(fonte, al_map_rgb(255,255,255), 10, 10,0, "MORTES %d",cont);  //escreve o numero de mortes da pessoa
                al_draw_filled_rectangle((telax-60),(telay-50)/2,telax,(telay+50)/2,al_map_rgb(0,220,0)); // DESENHA O retangulo de ganhar
                al_draw_filled_circle(cx1,cy1,raio1,al_map_rgb(255,0,0)); // DESENHA O CIRCULO1
                al_draw_filled_circle(cx2,cy2,raio2,al_map_rgb(255,0,0)); // DESENHA O CIRCULO2
                al_draw_filled_circle(cx3,cy3,raio3,al_map_rgb(0,0,255)); // DESENHA O CIRCULO3
                al_draw_filled_circle(cx4,cy4,raio4,al_map_rgb(255,255,255)); // DESENHA O CIRCULO4
                al_draw_filled_circle(cx5,cy5,raio5,al_map_rgb(0,255,255)); // DESENHA O CIRCULO5
                al_draw_filled_circle(cx6,cy6,raio6,al_map_rgb(0,255,0)); // DESENHA O CIRCULO6
                al_draw_filled_circle(cx7,cy7,raio7,al_map_rgb(0,255,0)); // DESENHA O CIRCULO7
                al_draw_filled_circle(cx8,cy8,raio8,al_map_rgb(0,255,0)); // DESENHA O CIRCULO8
                al_draw_filled_circle(cx9,cy9,raio9,al_map_rgb(255,255,0)); // DESENHA O CIRCULO8
                al_draw_filled_circle(cx10,cy10,raio10,al_map_rgb(255,0,0)); // DESENHA O CIRCULO10
                al_draw_filled_circle(cx11,cy11,raio11,al_map_rgb(255,255,0)); // DESENHA O CIRCULO11
                al_draw_filled_circle(cx12,cy12,raio12,al_map_rgb(255,0,0)); // DESENHA O CIRCULO12
                al_draw_filled_circle(cx13,cy13,raio13,al_map_rgb(0,0,255)); // DESENHA O CIRCULO13
                al_draw_filled_circle(cx14,cy14,raio14,al_map_rgb(255,255,255)); // DESENHA O CIRCULO14
                al_draw_filled_circle(cx15,cy15,raio15,al_map_rgb(0,255,255)); // DESENHA O CIRCULO15
                al_draw_filled_circle(cx16,cy16,raio16,al_map_rgb(0,255,0)); // DESENHA O CIRCULO16
                al_draw_filled_circle(cx17,cy17,raio17,al_map_rgb(0,255,0)); // DESENHA O CIRCULO17
                al_draw_filled_circle(cx18,cy18,raio18,al_map_rgb(0,255,0));  // DESENHA O CIRCULO18
                al_draw_filled_circle(cx19,cy19,raio19,al_map_rgb(255,255,0));  // DESENHA O CIRCULO19

                al_flip_display();
                al_clear_to_color(al_map_rgb(255,200,115));  // FUNDO DA TELA
            }
        }
        al_flip_display(); // atualiza o display para aparecer o menu
    }

    //FIM DAS ACOES DO JOGO
    al_destroy_timer(timer); // DESTROI O QUE FOI USADO NA MEMORIA
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);
    al_destroy_audio_stream(musica);
    al_destroy_sample(sample);
    al_destroy_font(fonte);
    al_destroy_bitmap(menuinicial);
    al_destroy_bitmap(bomba);
    al_destroy_bitmap(gameover);
    al_destroy_bitmap(fundo);

    return 0;
}

void colisao_com_circulos(int *bx, int *by,int *cir_x,int *cir_y,int *raio)  //testa a colisao dos circulos
{
    if((*bx)+35 > (*cir_x) - (*raio) && (*bx) < (*cir_x)+(*raio))                       // com a bomba
    {
        if((*by)+33 > (*cir_y) - (*raio) && (*by) < (*cir_y)+(*raio))
        {
            *bx=40; // faz a bomba voltar para a posicao inicial
            *by=40;
            cont++; //conta uma morte
            if(cont%10==0 && cont!=0 && raio9<=16)// o raio do circulo solto aumenta em 2p a cada 10 mortes e limita em 24p
                raio9+=2;
        }
    }
}

void colisao_horizontal(int *cx,int *velc,int *dir, int *telax,int *raio)   // de pont a ponta
{
    (*cx)+=((*velc) * (*dir));
    if((*cx)+(*raio)>=((*telax)-80)) (*dir)=-1;
    if((*cx)<=(*raio)+80) (*dir)=1;
}

void colisao_vertical(int *cy,int *velc,int *dir,int *telay,int *raio)   // de ponta a ponta
{
    (*cy)+= ((*velc) * (*dir));
    if((*cy)+(*raio)>=(*telay)) *dir=-1;
    if((*cy)<=(*raio)) *dir=1;
}
void colisao_verticalmenos(int *cy,int *velc,int *dir,int *telay,int *raio)   // de ponta a ponta
{
    (*cy)-= ((*velc) * (*dir));
    if((*cy)+(*raio)>=(*telay)) *dir=1;
    if((*cy)<=(*raio)) *dir=-1;
}

void colisao_diagonal1(int *cy,int *cx,int *velc,int *dir,int *telay,int *telax,int *raio)  // ate a metade
{
    (*cy)+=((*velc) * (*dir));
    (*cx)-=((*velc) * (*dir));
    if(((*cy)-(*raio)==0) || ((*cx)+(*raio)==((*telax)))) (*dir)=1;
    if(((*cy)+(*raio)==(*telay)) ||(*cx)==(*raio)) (*dir)=-1;
}

void colisao_diagonal2(int *cy,int *cx,int *velc,int *dir,int *telay,int *telax,int *raio)
{
    (*cy)+=((*velc) * (*dir));
    (*cx)+=((*velc) * (*dir));
    if(((*cy)-(*raio)==0) || ((*cx)-(*raio)==((*telax)))) (*dir)=1; //parte de cima da tela
    if(((*cy)+(*raio)==(*telay)) ||(*cx)==(*raio)) (*dir)=-1;// meio da tela pode mudar so tira o =/2=
}
