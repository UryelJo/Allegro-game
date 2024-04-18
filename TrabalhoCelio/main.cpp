#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>
#include<allegro5/allegro_color.h>
#include<allegro5/allegro_primitives.h>

ALLEGRO_DISPLAY* telaBaseDoGame;

int larguraMonitor = 800;
int alturaMonitor = 600;

ALLEGRO_COLOR corFundo = al_map_rgb(1, 1, 0);
ALLEGRO_COLOR corVermelha = al_map_rgb(255, 0, 0);
ALLEGRO_COLOR corAzul = al_map_rgb(0, 0, 255);
ALLEGRO_COLOR corVerde = al_map_rgb(0, 255, 0);
ALLEGRO_COLOR cor = al_map_rgb(0, 01, 0);

int main() {
    al_init();
	al_init_primitives_addon();
    telaBaseDoGame = al_create_display(larguraMonitor, alturaMonitor);
	for (int i = 0; i <= larguraMonitor; i+=10) {
		al_draw_filled_rectangle(0, alturaMonitor-10, i, alturaMonitor, corAzul);
		al_flip_display();
		al_rest(0.001);
	}

    al_flip_display();
    al_rest(10);
}