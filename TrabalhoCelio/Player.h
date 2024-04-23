#include "Moveset.h"

#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>

class Player
{
	public:
		
		ALLEGRO_BITMAP* imagemPersonagem = NULL;

		int frame_x = 0;
		int frame_y = 0;

		int delayTrocaDeFrame = 0;

		int larguraPlayer = 0;
		int alturaPlayer = 0;

		float posicao_x_tela = 0.f;
		float posicao_y_tela = 0.f;

		Moveset movesetPlayer;

		Player() {};

		Player(int fx, int fy, int lp, int ap, float px, float py, Moveset ms) {
			this->frame_x = fx;
			this->frame_y = fy;
			this->larguraPlayer = lp;
			this->alturaPlayer = ap;
			this->posicao_x_tela = px;
			this->posicao_y_tela = py;
			this->movesetPlayer = ms;
		}

		void carregarImagemPersonagem(ALLEGRO_BITMAP* imagemPersonagem);
		void movimentacaoDireita();
		void movimentacaoEsquerda();
		void puloPersonagem();
		
};

void Player::carregarImagemPersonagem(ALLEGRO_BITMAP* imagemPersonagem) {
	this->imagemPersonagem = imagemPersonagem;
}

void Player::movimentacaoEsquerda() {
	
	if (this->movesetPlayer.movendoEsquerda) {
		this->imagemPersonagem = al_load_bitmap("AndandoT.png");
		this->posicao_x_tela -= 3;
		this->delayTrocaDeFrame++;
		if (this->delayTrocaDeFrame == 17) {
			this->frame_x += 96;
			if (this->frame_x == 384) {
				this->frame_x = 0;
			}
			this->delayTrocaDeFrame = 0;
		}
	}
}

void Player::movimentacaoDireita() {
	if(this->movesetPlayer.movendoDireita) {
		this->imagemPersonagem = al_load_bitmap("AndandoF.png");
		this->posicao_x_tela += 3;
		this->delayTrocaDeFrame++;
		if (this->delayTrocaDeFrame == 17) {
			this->frame_x += 96;
			if (this->frame_x == 384) {
				this->frame_x = 0;
			}
			this->delayTrocaDeFrame = 0;
		}
	}
}

void Player::puloPersonagem() {
	if (this->movesetPlayer.pulando) {
		for (int i = 0; i < 40; i++) {
			this->posicao_y_tela -= 2;
			this->delayTrocaDeFrame++;
			if (this->delayTrocaDeFrame == 2) {
				al_clear_to_color(al_map_rgb(255, 255, 255));
				al_draw_bitmap_region(al_load_bitmap("ParadoF.png"), this->frame_x, this->frame_y, this->alturaPlayer, this->larguraPlayer, this->posicao_x_tela, this->posicao_y_tela, 0);
				al_flip_display();
				this->delayTrocaDeFrame = 0;
			}
		}
		this->movesetPlayer.pulando = false;
	}
}

