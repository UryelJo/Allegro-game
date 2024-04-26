//Include dos arquivos de cabeçalho
#include "Player.h"
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
ALLEGRO_TIMER *fps = NULL, *fpsImagem = NULL;
ALLEGRO_EVENT_QUEUE* filaEventos = NULL;

int delayAnimacao = 0;

Mapa mapa = Mapa();
Player player = Player(0, 0, 115, 72, 0, mapa.alturaTela - mapa.alturaTela, Moveset(), 0);

void inicializacao();
void encerramento();
void atualizarTela();
void limparTela();
void gravidade();

int main() {
	
	inicializacao();
	player.carregarImagemPersonagem(al_load_bitmap("Parado.png"));
	
	limparTela();
	atualizarTela();
	
	//Iniciar o Timer
	al_start_timer(fps);
	al_start_timer(fpsImagem);

	while (true)
	{
		ALLEGRO_EVENT evento;
		al_wait_for_event(filaEventos, &evento);

		if (evento.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
			break;
		}

		if (evento.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch(evento.keyboard.keycode) {
				case ALLEGRO_KEY_LEFT:
					player.movesetPlayer.movendoEsquerda = true;
					player.movesetPlayer.movendoDireita = false;
					player.flags = ALLEGRO_FLIP_HORIZONTAL;
					break;
				case ALLEGRO_KEY_RIGHT:
					player.movesetPlayer.movendoDireita = true;
					player.movesetPlayer.movendoEsquerda = false;
					player.flags = 0;
					break;
			}
		}

		gravidade();

		if (evento.keyboard.keycode == ALLEGRO_KEY_SPACE && !player.movesetPlayer.voando) {
			player.movesetPlayer.pulando = true;
			player.puloPersonagem();
		}
		
			player.movimentacaoDireita();
			player.movimentacaoEsquerda();
		
		

		if (evento.type == ALLEGRO_EVENT_KEY_UP) {
			switch (evento.keyboard.keycode) {
				case ALLEGRO_KEY_LEFT:
					player.movesetPlayer.movendoEsquerda = false;
					break;
				case ALLEGRO_KEY_RIGHT:
					player.movesetPlayer.movendoDireita = false;
					break;
			}
			player.imagemPersonagem = al_load_bitmap("Parado.png");
		}

		

		if (!player.movesetPlayer.movendoDireita && !player.movesetPlayer.movendoEsquerda && !player.movesetPlayer.pulando) {
			delayAnimacao++;
			if (delayAnimacao == 30) {
				if (player.frame_x < 115) {
					player.frame_x += 115;
				}
				else {
					player.frame_x = 0;
				}
				delayAnimacao = 0;
			}
			
		}
		
		limparTela();
		al_draw_bitmap_region(player.imagemPersonagem, player.frame_x, player.frame_y, player.alturaPlayer, player.larguraPlayer, player.posicao_x_tela, player.posicao_y_tela, player.flags);
		atualizarTela();
	}

	encerramento();
}

void inicializacao() {
	
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
	if (!telaGame) {
		al_show_native_message_box(telaGame, "ERRO", "ERRO", "Erro ao criar o display", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return;
	}

	//Inicialização do Timer do Game
	fps = al_create_timer(1.0 / mapa.fpsGame);
	if (!fps) {
		al_show_native_message_box(telaGame, "ERRO", "ERRO", "Erro ao criar o timer", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return;
	}

	//Inicialização do Timer do Sprite
	fpsImagem = al_create_timer(1.0 / player.fpsImagem);
	if (!fpsImagem) {
		al_show_native_message_box(telaGame, "ERRO", "ERRO", "Erro ao criar o timer da imagem", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return;
	}

	//Inicialização da Fila de Eventos
	filaEventos = al_create_event_queue();
	if (!filaEventos) {
		al_show_native_message_box(telaGame, "ERRO", "ERRO", "Erro ao criar a fila de eventos", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return;
	}

	//Registro de Eventos
	al_register_event_source(filaEventos, al_get_display_event_source(telaGame));
	al_register_event_source(filaEventos, al_get_timer_event_source(fps));
	al_register_event_source(filaEventos, al_get_timer_event_source(fpsImagem));
	al_register_event_source(filaEventos, al_get_keyboard_event_source());
}

void encerramento() {
	//Encerramento do Allegro
	al_destroy_display(telaGame);
	al_destroy_bitmap(player.imagemPersonagem);
	al_destroy_timer(fps);
	al_destroy_timer(fpsImagem);
	al_destroy_event_queue(filaEventos);
}

void atualizarTela() {
	al_flip_display();
}

void limparTela() {
	al_clear_to_color(al_map_rgb(255, 255, 255));
}

void gravidade() {
	if (player.posicao_y_tela < mapa.alturaTela - 90) {
		player.movesetPlayer.voando = true;
		player.posicao_y_tela += 2;
	}
	else {
		player.movesetPlayer.voando = false;
	}
}