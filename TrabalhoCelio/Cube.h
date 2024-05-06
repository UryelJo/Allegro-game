#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>

class Cube
{
	public:
		ALLEGRO_BITMAP* imagemChao = NULL;

		int posicao_x_inicial = 0;
		int posicao_y_inicial = 0;

		int tamanho = 0;

		int flags = 0;

		Cube() {};
		Cube(int px, int py, int l, int flags) {
			this->posicao_x_inicial = px;
			this->posicao_y_inicial = py;
			this->tamanho = l;
			this->flags = flags;
		}

		void carregarImagemChao(ALLEGRO_BITMAP* imagemChao);
};

void Cube::carregarImagemChao(ALLEGRO_BITMAP* imagemChao) {
	this->imagemChao = imagemChao;
}


