#pragma once
#include "Canvas.h"
#include "SelectionMenu.h"
#include "allegro5\allegro_image.h"
#include "allegro5\allegro_font.h"
#include "allegro5\allegro_ttf.h"

Canvas *canvas;
SelectionMenu *selectionMenu;
ALLEGRO_DISPLAY *window;
ALLEGRO_EVENT_QUEUE *EQ;
bool running = true;

int main() {
	al_init();
	al_init_native_dialog_addon();
	al_init_primitives_addon();
	al_init_image_addon();
	al_init_ttf_addon();
	al_init_font_addon();
	al_install_mouse();
	al_install_keyboard();


	EQ = al_create_event_queue();
	//al_set_new_display_flags(ALLEGRO_RESIZABLE);
	window = al_create_display(1000, 700);
	al_set_window_title(window, "BareBones");
	al_register_event_source(EQ, al_get_display_event_source(window));
	ALLEGRO_TIMER *timer;
	timer = al_create_timer(1.0 / 50);
	al_register_event_source(EQ, al_get_timer_event_source(timer));
	canvas = new Canvas();
	selectionMenu = new SelectionMenu(0, 0, 0, canvas);
	canvas->setSelectionMenuPointer(selectionMenu);
	al_start_timer(timer);
	while (running) {
		while (!al_is_event_queue_empty(EQ)) {
			ALLEGRO_EVENT E;
			al_get_next_event(EQ, &E);
			if (E.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
				running = false;
			}
			else {
				if (E.type == ALLEGRO_EVENT_DISPLAY_SWITCH_OUT) {
					al_stop_timer(timer);
					std::cout << "left display" << std::endl;
				}
				else {
					if (E.type == ALLEGRO_EVENT_DISPLAY_SWITCH_IN) {
						al_start_timer(timer);
						std::cout << "entered display" << std::endl;
					}
					else {
						if (E.type == ALLEGRO_EVENT_TIMER) {
							canvas->draw();
							selectionMenu->tick();
							selectionMenu->draw();
							al_flip_display();

						}
					}
				}
			}
		}
	}
}