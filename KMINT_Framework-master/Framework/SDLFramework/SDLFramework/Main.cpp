#include <iostream>
#include <vector>
#include "Config.h"
#include "FWApplication.h"
#include <SDL_events.h>
#include "SDL_timer.h"
#include <time.h>
#include "Bird.h"
#include "ExampleGameObject.h"
#include "Globals.h"
#include "Graph.h"
#include "Background.h"

using namespace std;

int main(int args[])
{
	//auto window = Window::CreateSDLWindow();
	auto application = new FWApplication();
	if (!application->GetWindow())
	{
		LOG("Couldn't create window...");
		return EXIT_FAILURE;
	}

	application->SetTargetFPS(60);
	Background* background = new Background();
	application->AddRenderable(background);

	std::vector<Bird*>* birds = new vector<Bird*>;
	int lastId = 0;

	for (int i = AMOUNT_OF_BIRDS; i > 0; i--) {
		Bird* bird = new Bird(i, birds);
		birds->push_back(bird);
		application->AddRenderable(bird);
		lastId++;
	}

	// maak de graph + 4 pillen + 4 ghosts en 1 pacman
#pragma region graph init
	//auto graph = Graph();
	auto graph = Graph(application);
	auto vertex104 = new Vertex(34, 120);
	graph.addVertex(vertex104);
	auto vertex105 = new Vertex(136, 117);
	graph.addVertex(vertex105);
	auto vertex106 = new Vertex(136, 45);
	graph.addVertex(vertex106);
	auto vertex107 = new Vertex(261, 45);
	graph.addVertex(vertex107);
	auto vertex108 = new Vertex(261, 114);
	graph.addVertex(vertex108);
	auto vertex109 = new Vertex(320, 114);
	graph.addVertex(vertex109);
	auto vertex110 = new Vertex(320, 45);
	graph.addVertex(vertex110);
	auto vertex111 = new Vertex(437, 42);
	graph.addVertex(vertex111);
	auto vertex112 = new Vertex(437, 114);
	graph.addVertex(vertex112);
	auto vertex113 = new Vertex(544, 117);
	graph.addVertex(vertex113);
	auto vertex115 = new Vertex(544, 170);
	graph.addVertex(vertex115);
	auto vertex116 = new Vertex(439, 173);
	graph.addVertex(vertex116);
	auto vertex117 = new Vertex(376, 173);
	graph.addVertex(vertex117);
	auto vertex118 = new Vertex(376, 114);
	graph.addVertex(vertex118);
	auto vertex119 = new Vertex(197, 117);
	graph.addVertex(vertex119);
	auto vertex120 = new Vertex(197, 170);
	graph.addVertex(vertex120);
	auto vertex121 = new Vertex(258, 173);
	graph.addVertex(vertex121);
	auto vertex122 = new Vertex(258, 229);
	graph.addVertex(vertex122);
	auto vertex123 = new Vertex(320, 226);
	graph.addVertex(vertex123);
	auto vertex124 = new Vertex(320, 173);
	graph.addVertex(vertex124);
	auto vertex125 = new Vertex(378, 229);
	graph.addVertex(vertex125);
	auto vertex126 = new Vertex(439, 285);
	graph.addVertex(vertex126);
	auto vertex127 = new Vertex(381, 285);
	graph.addVertex(vertex127);
	auto vertex128 = new Vertex(194, 232);
	graph.addVertex(vertex128);
	auto vertex129 = new Vertex(136, 176);
	graph.addVertex(vertex129);
	auto vertex130 = new Vertex(34, 176);
	graph.addVertex(vertex130);
	auto vertex131 = new Vertex(133, 285);
	graph.addVertex(vertex131);
	auto vertex132 = new Vertex(197, 288);
	graph.addVertex(vertex132);
	auto vertex133 = new Vertex(200, 346);
	graph.addVertex(vertex133);
	auto vertex134 = new Vertex(381, 344);
	graph.addVertex(vertex134);
	auto vertex135 = new Vertex(439, 400);
	graph.addVertex(vertex135);
	auto vertex136 = new Vertex(544, 400);
	graph.addVertex(vertex136);
	auto vertex137 = new Vertex(504, 456);
	graph.addVertex(vertex137);
	auto vertex138 = new Vertex(504, 512);
	graph.addVertex(vertex138);
	auto vertex139 = new Vertex(439, 512);
	graph.addVertex(vertex139);
	auto vertex140 = new Vertex(439, 456);
	graph.addVertex(vertex140);
	auto vertex141 = new Vertex(376, 458);
	graph.addVertex(vertex141);
	auto vertex142 = new Vertex(320, 400);
	graph.addVertex(vertex142);
	auto vertex143 = new Vertex(381, 397);
	graph.addVertex(vertex143);
	auto vertex144 = new Vertex(320, 456);
	graph.addVertex(vertex144);
	auto vertex145 = new Vertex(261, 402);
	graph.addVertex(vertex145);
	auto vertex146 = new Vertex(197, 400);
	graph.addVertex(vertex146);
	auto vertex147 = new Vertex(133, 400);
	graph.addVertex(vertex147);
	auto vertex148 = new Vertex(34, 400);
	graph.addVertex(vertex148);
	auto vertex149 = new Vertex(77, 458);
	graph.addVertex(vertex149);
	auto vertex150 = new Vertex(77, 509);
	graph.addVertex(vertex150);
	auto vertex151 = new Vertex(138, 506);
	graph.addVertex(vertex151);
	auto vertex152 = new Vertex(136, 456);
	graph.addVertex(vertex152);
	auto vertex153 = new Vertex(200, 456);
	graph.addVertex(vertex153);
	auto vertex154 = new Vertex(200, 512);
	graph.addVertex(vertex154);
	auto vertex155 = new Vertex(258, 514);
	graph.addVertex(vertex155);
	auto vertex156 = new Vertex(258, 565);
	graph.addVertex(vertex156);
	auto vertex158 = new Vertex(34, 512);
	graph.addVertex(vertex158);
	auto vertex159 = new Vertex(320, 565);
	graph.addVertex(vertex159);
	auto vertex160 = new Vertex(320, 514);
	graph.addVertex(vertex160);
	auto vertex161 = new Vertex(378, 512);
	graph.addVertex(vertex161);
	auto vertex163 = new Vertex(544, 514);
	graph.addVertex(vertex163);
	auto vertex224 = new Vertex(261, 456);
	graph.addVertex(vertex224);

	// spawn 4 pillen
	auto vertex243 = new Vertex(34, 82);
	graph.addVertex(vertex243);
	graph.addPill(new Powerpill(vertex243->x, vertex243->y));
	auto vertex244 = new Vertex(541, 80);
	graph.addVertex(vertex244);
	graph.addPill(new Powerpill(vertex244->x, vertex244->y));
	auto vertex245 = new Vertex(544, 456);
	graph.addVertex(vertex245);
	graph.addPill(new Powerpill(vertex245->x, vertex245->y));
	auto vertex246 = new Vertex(34, 456);
	graph.addVertex(vertex246);
	graph.addPill(new Powerpill(vertex246->x, vertex246->y));

	// spawn spookjes
	auto vertex103 = new Vertex(34, 48);
	graph.addVertex(vertex103);
	for (int x = 0; x < 25; x++) {
		graph.addGhost(new Ghost(vertex103->x, vertex103->y));
	}
	auto vertex114 = new Vertex(541, 45);
	graph.addVertex(vertex114);
	for (int x = 0; x < 25; x++) {
		graph.addGhost(new Ghost(vertex114->x, vertex114->y));
	}
	auto vertex157 = new Vertex(37, 562);
	graph.addVertex(vertex157);
	for (int x = 0; x < 25; x++) {
		graph.addGhost(new Ghost(vertex157->x, vertex157->y));
	}
	auto vertex162 = new Vertex(541, 568);
	graph.addVertex(vertex162);
	for (int x = 0; x < 25; x++) {
		graph.addGhost(new Ghost(vertex162->x, vertex162->y));
	}

	// Spawn pacman
	auto vertex250 = new Vertex(290, 345);
	graph.addVertex(vertex250);
	graph.addPacman(new Pacman(vertex250->x, vertex250->y));

	graph.addEdge(new Edge(vertex103, vertex106));
	graph.addEdge(new Edge(vertex106, vertex107));
	graph.addEdge(new Edge(vertex107, vertex108));
	graph.addEdge(new Edge(vertex108, vertex119));
	graph.addEdge(new Edge(vertex119, vertex120));
	graph.addEdge(new Edge(vertex120, vertex121));
	graph.addEdge(new Edge(vertex121, vertex122));
	graph.addEdge(new Edge(vertex122, vertex123));
	graph.addEdge(new Edge(vertex123, vertex124));
	graph.addEdge(new Edge(vertex124, vertex117));
	graph.addEdge(new Edge(vertex117, vertex118));
	graph.addEdge(new Edge(vertex118, vertex109));
	graph.addEdge(new Edge(vertex109, vertex108));
	graph.addEdge(new Edge(vertex109, vertex110));
	graph.addEdge(new Edge(vertex110, vertex111));
	graph.addEdge(new Edge(vertex112, vertex111));
	graph.addEdge(new Edge(vertex114, vertex111));
	graph.addEdge(new Edge(vertex113, vertex112));
	graph.addEdge(new Edge(vertex115, vertex113));
	graph.addEdge(new Edge(vertex112, vertex116));
	graph.addEdge(new Edge(vertex116, vertex115));
	graph.addEdge(new Edge(vertex116, vertex126));
	graph.addEdge(new Edge(vertex126, vertex127));
	graph.addEdge(new Edge(vertex127, vertex125));
	graph.addEdge(new Edge(vertex125, vertex123));
	graph.addEdge(new Edge(vertex122, vertex128));
	graph.addEdge(new Edge(vertex128, vertex132));
	graph.addEdge(new Edge(vertex132, vertex131));
	graph.addEdge(new Edge(vertex131, vertex129));
	graph.addEdge(new Edge(vertex129, vertex105));
	graph.addEdge(new Edge(vertex105, vertex106));
	graph.addEdge(new Edge(vertex105, vertex104));
	graph.addEdge(new Edge(vertex104, vertex130));
	graph.addEdge(new Edge(vertex130, vertex129));
	graph.addEdge(new Edge(vertex131, vertex147));
	graph.addEdge(new Edge(vertex147, vertex148));
	graph.addEdge(new Edge(vertex149, vertex150));
	graph.addEdge(new Edge(vertex150, vertex158));
	graph.addEdge(new Edge(vertex158, vertex157));
	graph.addEdge(new Edge(vertex157, vertex156));
	graph.addEdge(new Edge(vertex156, vertex155));
	graph.addEdge(new Edge(vertex155, vertex154));
	graph.addEdge(new Edge(vertex154, vertex153));
	graph.addEdge(new Edge(vertex153, vertex152));
	graph.addEdge(new Edge(vertex152, vertex151));
	graph.addEdge(new Edge(vertex151, vertex150));
	graph.addEdge(new Edge(vertex152, vertex147));
	graph.addEdge(new Edge(vertex147, vertex146));
	graph.addEdge(new Edge(vertex146, vertex133));
	graph.addEdge(new Edge(vertex133, vertex132));
	graph.addEdge(new Edge(vertex133, vertex250));
	graph.addEdge(new Edge(vertex250, vertex134));
	graph.addEdge(new Edge(vertex134, vertex127));
	graph.addEdge(new Edge(vertex126, vertex135));
	graph.addEdge(new Edge(vertex135, vertex136));
	graph.addEdge(new Edge(vertex135, vertex143));
	graph.addEdge(new Edge(vertex143, vertex134));
	graph.addEdge(new Edge(vertex143, vertex142));
	graph.addEdge(new Edge(vertex142, vertex144));
	graph.addEdge(new Edge(vertex144, vertex141));
	graph.addEdge(new Edge(vertex144, vertex224));
	graph.addEdge(new Edge(vertex224, vertex153));
	graph.addEdge(new Edge(vertex224, vertex145));
	graph.addEdge(new Edge(vertex145, vertex146));
	graph.addEdge(new Edge(vertex141, vertex140));
	graph.addEdge(new Edge(vertex140, vertex135));
	graph.addEdge(new Edge(vertex140, vertex139));
	graph.addEdge(new Edge(vertex139, vertex138));
	graph.addEdge(new Edge(vertex138, vertex137));
	graph.addEdge(new Edge(vertex138, vertex163));
	graph.addEdge(new Edge(vertex163, vertex162));
	graph.addEdge(new Edge(vertex162, vertex159));
	graph.addEdge(new Edge(vertex159, vertex160));
	graph.addEdge(new Edge(vertex160, vertex161));
	graph.addEdge(new Edge(vertex161, vertex141));
	graph.addEdge(new Edge(vertex159, vertex156));
	graph.addEdge(new Edge(vertex105, vertex119));
	graph.addEdge(new Edge(vertex118, vertex112));
	graph.addEdge(new Edge(vertex103, vertex243));
	graph.addEdge(new Edge(vertex243, vertex104));
	graph.addEdge(new Edge(vertex114, vertex244));
	graph.addEdge(new Edge(vertex244, vertex113));
	graph.addEdge(new Edge(vertex148, vertex246));
	graph.addEdge(new Edge(vertex246, vertex149));
	graph.addEdge(new Edge(vertex136, vertex245));
	graph.addEdge(new Edge(vertex245, vertex137));
#pragma endregion

	application->AddRenderable(graph.getPacman());

	for each (auto g in graph.getGhosts())
	{
		application->AddRenderable(g);
	}

	for each (auto p in graph.getPills())
	{
		application->AddRenderable(p);
	}

	while (application->IsRunning())
	{
		application->StartTick();
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				application->Quit();
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym) {
					
				default:
					break;
				}
				break;
			case SDL_MOUSEBUTTONDOWN:
				/*if (event.button.button == 1) {
					int mouseX = 0;
					int mouseY = 0;
					SDL_GetMouseState(&mouseX, &mouseY);
	
					Bird* bird = new Bird(lastId + 1, birds, mouseX, mouseY);
					birds->push_back(bird);
					application->AddRenderable(bird);
					lastId++;
				}*/
				break;
			}
		}

		//// For the background
		application->SetColor(Color(255, 255, 255, 255));

		application->UpdateGameObjects();
		application->RenderGameObjects();
		application->EndTick();
	}

	for each (Bird* var in *birds)
	{
		delete var;
	}
	delete birds;
	return EXIT_SUCCESS;
}