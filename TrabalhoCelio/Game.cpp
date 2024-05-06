//Include dos arquivos de cabeçalho
#include "Entity.h"
#include "Mapa.h"

//Include das bibliotecas do Allegro
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_video.h>

//Include das bibliotecas C++
#include <iostream>

ALLEGRO_DISPLAY *telaGame = NULL;
ALLEGRO_TIMER *fps = NULL;
ALLEGRO_EVENT_QUEUE* filaEventos = NULL;
ALLEGRO_SAMPLE* music = NULL;

int delayAnimacao = 0;

Mapa mapa = Mapa();
Entity player = Entity(0, 0, 115, 72, 0, mapa.alturaTela - mapa.alturaTela, Moveset(), 0);

void inicializacao();
void encerramento();
void atualizarLimparDesenharGame();
void inicializarAudio();

void testeColisao(int representacaoMapa[24][44]);

int main()
{
	inicializacao();

	player.carregarImagemPersonagem(al_load_bitmap("Assets/Images/Parado.png"));
	mapa.carregarBackground(al_load_bitmap("Assets/Images/background.jpg"));
	mapa.chao.carregarImagemChao(al_load_bitmap("Assets/Images/Tile_02.png"));
	
	al_clear_to_color(al_map_rgb(255, 255, 255));
	al_flip_display();
	
	//Iniciar o Timer
	al_start_timer(fps);

	while (true)
	{
		ALLEGRO_EVENT evento;
		al_wait_for_event(filaEventos, &evento);

		if (evento.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
		{
			break;
		}

		if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (evento.keyboard.keycode)
			{
			case ALLEGRO_KEY_LEFT:
				player.movesetPlayer.movendoEsquerda = true;
				player.movesetPlayer.movendoDireita = false;
				player.flags = ALLEGRO_FLIP_HORIZONTAL;
				player.frame_x = 0;
				break;
			case ALLEGRO_KEY_RIGHT:
				player.movesetPlayer.movendoDireita = true;
				player.movesetPlayer.movendoEsquerda = false;
				player.flags = 0;
				player.frame_x = 0;
				break;
			case ALLEGRO_KEY_D:
				player.movesetPlayer.movendoDireita = true;
				player.movesetPlayer.movendoEsquerda = false;
				player.flags = 0;
				player.frame_x = 0;
				break;
			case ALLEGRO_KEY_A:
				player.movesetPlayer.movendoEsquerda = true;
				player.movesetPlayer.movendoDireita = false;
				player.flags = ALLEGRO_FLIP_HORIZONTAL;
				player.frame_x = 0;
				break;
			}
		}

		player.movimentacao();
		testeColisao(mapa.representacaoMapa);

		if (evento.type == ALLEGRO_EVENT_KEY_UP) 
		{
			switch (evento.keyboard.keycode) 
			{
				case ALLEGRO_KEY_LEFT:
					player.movesetPlayer.movendoEsquerda = false;
					player.delayTrocaDeFrame = 0;
					break;
				case ALLEGRO_KEY_RIGHT:
					player.movesetPlayer.movendoDireita = false;
					player.delayTrocaDeFrame = 0;
					break;
				case ALLEGRO_KEY_D:
					player.movesetPlayer.movendoDireita = false;
					player.delayTrocaDeFrame = 0;
					break;
				case ALLEGRO_KEY_A:
					player.movesetPlayer.movendoEsquerda = false;
					player.delayTrocaDeFrame = 0;
					break;
			}
			player.imagemPersonagem = al_load_bitmap("Assets/Images/Parado.png");
		}
		player.movimentacaoParado();

		atualizarLimparDesenharGame();
	}
	encerramento();
}

void inicializacao() 
{
	//Inicialização do Allegro e dos Addons
	al_init();
	al_init_font_addon();
	al_init_primitives_addon();
	al_init_image_addon();
	al_init_acodec_addon();
	al_install_audio();
	al_init_ttf_addon();
	al_install_keyboard();
	al_install_mouse();
	al_init_native_dialog_addon();
	al_init_video_addon();

	//Inicialização do Display
	al_set_new_display_flags(ALLEGRO_NOFRAME);
	telaGame = al_create_display(mapa.larguraTela, mapa.alturaTela);
	if (!telaGame) 
	{
		al_show_native_message_box(telaGame, "ERRO", "ERRO", "Erro ao criar o display", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return;
	}

	//Inicialização do Timer do Game
	fps = al_create_timer(1.0 / mapa.fpsGame);
	if (!fps) {
		al_show_native_message_box(telaGame, "ERRO", "ERRO", "Erro ao criar o timer", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return;
	}

	//Inicialização da Fila de Eventos
	filaEventos = al_create_event_queue();
	if (!filaEventos) 
	{
		al_show_native_message_box(telaGame, "ERRO", "ERRO", "Erro ao criar a fila de eventos", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return;
	}

	//Registro de Eventos
	al_register_event_source(filaEventos, al_get_display_event_source(telaGame));
	al_register_event_source(filaEventos, al_get_timer_event_source(fps));
	al_register_event_source(filaEventos, al_get_keyboard_event_source());

	//Inicialização do Audio
	inicializarAudio();
}

void encerramento() 
{
	//Encerramento do Allegro
	al_destroy_display(telaGame);
	al_destroy_bitmap(player.imagemPersonagem);
	al_destroy_bitmap(mapa.backgroundTela);
	al_destroy_bitmap(mapa.chao.imagemChao);
	al_destroy_sample(music);
	al_destroy_timer(fps);
	al_destroy_event_queue(filaEventos);
}

void atualizarLimparDesenharGame()
{
	al_clear_to_color(al_map_rgb(255, 255, 255));
	al_draw_scaled_bitmap(mapa.backgroundTela, 0, 0, 1920, 1080, 0, 0, mapa.larguraTela, mapa.alturaTela, 0);
	mapa.construirMapa(mapa.representacaoMapa, mapa.larguraTela, mapa.alturaTela);
	al_draw_bitmap_region(player.imagemPersonagem, player.frame_x, player.frame_y, player.alturaPlayer, player.larguraPlayer, player.posicao_x_tela, player.posicao_y_tela, player.flags);
	al_flip_display();
}

void inicializarAudio() {
	music = al_load_sample("Assets/audio/8bit.ogg");
	if (!music) {
		al_show_native_message_box(telaGame, "ERRO", "ERRO", "Erro ao carregar o audio", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return;
	}

	// Play the sound file
	al_reserve_samples(1);
	al_play_sample(music, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, 0);
}

void testeColisao(int representacaoMapa[24][44])
{
	player.posicao_y_tela += 10;
    for (int y = 0; y <= (mapa.alturaTela / mapa.chao.tamanho); y++)
    {
        for (int x = 0; x <= (mapa.larguraTela / mapa.chao.tamanho); x++)
        {
            if (representacaoMapa[y][x] == 1)
            {
				if ((player.posicao_x_tela+46) > (x*mapa.chao.tamanho)) 
				{
					if ((player.posicao_y_tela + player.alturaPlayer) > (y * mapa.chao.tamanho)) 
					{
						player.posicao_y_tela = (y * mapa.chao.tamanho) - player.alturaPlayer;
					}
				}
            }
        }
    }
}