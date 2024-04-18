// bibliotecas allegro
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


//Variáveis globais do Allegro
ALLEGRO_DISPLAY* telaBaseDoGame = NULL;
ALLEGRO_TIMER* fps = NULL;
ALLEGRO_EVENT_QUEUE* filaEventos = NULL;
ALLEGRO_FONT* fonte = NULL;

//Variáveis globais do jogo
int larguraMonitor = 800;
int alturaMonitor = 600;

int main() {

	//Inicialização do Allegro e dos Addons
    al_init();
	al_init_font_addon();
	al_init_primitives_addon();
	al_init_image_addon();
	al_install_keyboard();
	al_install_mouse();

	//Criação de objetos do Allegro
	fonte = al_create_builtin_font();
	fps = al_create_timer(1.0 / 60);
    telaBaseDoGame = al_create_display(larguraMonitor, alturaMonitor);
	filaEventos = al_create_event_queue();

	al_set_window_position(telaBaseDoGame, 200, 200);
	al_set_window_title(telaBaseDoGame, "Trabalho de Computação Gráfica");

	al_register_event_source(filaEventos, al_get_display_event_source(telaBaseDoGame));
	al_register_event_source(filaEventos, al_get_timer_event_source(fps));
	al_register_event_source(filaEventos, al_get_keyboard_event_source());
	al_register_event_source(filaEventos, al_get_mouse_event_source());

	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_flip_display();

	al_start_timer(fps);

	//Loop do jogo
	while (true){

		ALLEGRO_EVENT evento;
		al_wait_for_event_timed(filaEventos, &evento, 0.01);

		//Método que para o game quando se clica no X da janela
		if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}

		al_clear_to_color(al_map_rgb(0, 0, 0));
		al_draw_text(fonte, al_map_rgb(255, 255, 255), 10, 10, 0, "Hello World");
		al_flip_display();
	}

	//Finalização do Allegro
	al_destroy_display(telaBaseDoGame);
	al_destroy_timer(fps);
	al_destroy_event_queue(filaEventos);

	return 0;
}