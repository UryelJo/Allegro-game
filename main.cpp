//Classes Externas
#include "Player.h"

//bibliotecas allegro
#include<allegro5/allegro.h>
#include<allegro5/allegro_primitives.h>
#include<allegro5/allegro_audio.h>
#include<allegro5/allegro_font.h>
#include<allegro5/allegro_image.h>
#include<allegro5/allegro_color.h>
#include<allegro5/allegro_ttf.h>
#include<allegro5/allegro_acodec.h>
#include<allegro5/allegro_native_dialog.h>
#include<allegro5/allegro_memfile.h>
#include<allegro5/allegro_physfs.h>
#include<allegro5/allegro_video.h>

// bibliotecas c++
#include<iostream>


//Vari�veis globais do Allegro
ALLEGRO_DISPLAY *telaGame = NULL;
ALLEGRO_TIMER *fps = NULL;
ALLEGRO_EVENT_QUEUE *filaEventos = NULL;
ALLEGRO_BITMAP *sprite = NULL, *bg = NULL;


void contruirChao();
void atualizarTela();

//Vari�veis globais do jogo

const float fpsGame = 60;

bool movendoParaEsquerda = false;
bool movendoParaDireita = false;
bool agachadoDireita = false;
bool agachadoEsquerda = false;

bool agachar = false;

const int larguraMapa = 1920;
const int alturaMapa = 1080;

float frame = 0.f;
int larguraFrame = 78, alturaFrame = 72;
int posicao_x = 0, posicao_y = alturaMapa*0.3;
int current_frame_y = 0;
int cont = 0;
int cont2 = 0;


int main() {

	//Inicializa��o do Allegro e dos Addons
    al_init();
	al_init_font_addon();
	al_init_primitives_addon();
	al_init_image_addon();
	al_install_keyboard();
	al_install_mouse();

	//Cria��o de objetos do Allegro
	fps = al_create_timer(1.0 / fpsGame);
	sprite = al_load_bitmap("./ParadoF");
	bg = al_load_bitmap("./Background.jpg");

	al_set_new_display_flags(ALLEGRO_NOFRAME);
	telaGame = al_create_display(larguraMapa, alturaMapa);
	filaEventos = al_create_event_queue();
	
	al_register_event_source(filaEventos, al_get_timer_event_source(fps));
	al_register_event_source(filaEventos, al_get_keyboard_event_source());
	al_register_event_source(filaEventos, al_get_mouse_event_source());
	al_register_event_source(filaEventos, al_get_display_event_source(telaGame));

	al_clear_to_color(al_map_rgb(255, 255, 255));
	al_flip_display();

	al_start_timer(fps);

	//Loop do jogo
	while (true){

		ALLEGRO_EVENT evento;
		al_wait_for_event(filaEventos, &evento);
		

		//M�todo que para o game quando se clica no ESC da janela
		if (evento.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
			break;
		}
		if (evento.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (evento.keyboard.keycode) {
			case ALLEGRO_KEY_LEFT:
				movendoParaEsquerda = true;
				movendoParaDireita = false;
				agachadoEsquerda = true;
				larguraFrame = 96;
				sprite = al_load_bitmap("./andandoT.png");
				break;
			case ALLEGRO_KEY_RIGHT:
				movendoParaDireita = true;
				movendoParaEsquerda = false;
				agachadoDireita = true;
				larguraFrame = 96;
				sprite = al_load_bitmap("./andandoF.png");
				break;
			case ALLEGRO_KEY_DOWN:
				agachar = true;
				
				break;


			}
		}

		//Gravidade
		if(posicao_y < alturaMapa*0.61){
			posicao_y += 4.5;
		}

		if (movendoParaDireita) {
			posicao_x += 3;
			cont++;
			if (cont == 17) {
				frame += 96;
				if (frame == 384) {
					frame = 0;
				}
				cont = 0;
			}
		}
		if (movendoParaEsquerda) {
			posicao_x -= 3;
			cont++;
			if (cont == 17) {
				frame += 96;
				if (frame == 384) {
					frame = 0;
				}
				cont = 0;
			}
		}

		if (agachar) {
			//larguraFrame = 86;
		//	alturaFrame = 64;
		//	if (agachadoDireita) {
		//		sprite = al_load_bitmap("./agacharF.png");
		//		frame = 0;
			//}
			//if (agachadoEsquerda) {
			//	sprite = al_load_bitmap("./agacharT.png");
			//	frame = 86;
			//}
			frame = 0;
			larguraFrame = 86;
			alturaFrame = 128;
			sprite = al_load_bitmap("./agacharF.png");
			al_draw_bitmap_region(sprite, frame, current_frame_y, larguraFrame, alturaFrame, posicao_x, posicao_y, 0);
			atualizarTela();
		}

		if (evento.type == ALLEGRO_EVENT_KEY_UP) {
			switch (evento.keyboard.keycode) {
			case ALLEGRO_KEY_DOWN:
				agachar = false;
				break;
			case ALLEGRO_KEY_LEFT:
				movendoParaEsquerda = false;
				agachadoEsquerda = false;
				break;
			case ALLEGRO_KEY_RIGHT:
				movendoParaDireita = false;
				agachadoDireita = false;
				break;
			}
			larguraFrame = 78;
			alturaFrame = 72;
			sprite = al_load_bitmap("./Parado.png");
			al_draw_bitmap_region(sprite, frame, current_frame_y, larguraFrame, alturaFrame, posicao_x, posicao_y, 0);
		}

		al_clear_to_color(al_map_rgb(255, 255, 255));

		contruirChao();
		
		al_draw_bitmap_region(sprite, frame, current_frame_y, larguraFrame, alturaFrame, posicao_x, posicao_y, 0);
		
		atualizarTela();
	}

	//Finaliza��o do Allegro
	al_destroy_bitmap(bg);
	al_destroy_bitmap(sprite);
	al_destroy_display(telaGame);
	al_destroy_timer(fps);
	al_destroy_event_queue(filaEventos);
}

void contruirChao() {
	al_draw_filled_rectangle(0, alturaMapa*0.65, larguraMapa, alturaMapa, al_map_rgb(255, 0, 0));
}

void atualizarTela() {
	al_flip_display();
}