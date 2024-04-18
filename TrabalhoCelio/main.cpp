#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>
#include<allegro5/allegro_color.h>
#include<allegro5/allegro_primitives.h>

ALLEGRO_DISPLAY* telaBaseDoGame;

int larguraMonitor = 800;
int alturaMonitor = 600;


int main() {
    al_init();
	al_init_primitives_addon();
    telaBaseDoGame = al_create_display(larguraMonitor, alturaMonitor);
	for (int i = 0; i < 10; i++) {
		al_clear_to_color(al_map_rgb(0, 0, 0));
		al_draw_filled_rectangle(10, 10, 100, 100, al_map_rgb(255, 0, 0));
		al_flip_display();
		al_rest(1);
	}

    al_flip_display();
    al_rest(10);
}