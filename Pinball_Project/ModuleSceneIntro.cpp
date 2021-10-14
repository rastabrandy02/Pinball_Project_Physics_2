#include "Globals.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModuleSceneIntro.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "ModulePhysics.h"

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
	circle = box = rick = NULL;
	ray_on = false;
	sensed = false;
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;
	// TODO: Homework - create a sensor
	App->renderer->camera.x = App->renderer->camera.y = 0;

	circle = App->textures->Load("pinball/wheel.png"); 
	box = App->textures->Load("pinball/crate.png");
	rick = App->textures->Load("pinball/rick_head.png");
	bonus_fx = App->audio->LoadFx("pinball/bonus.wav");


	//load UI elements
	game_icon = App->textures->Load("pinball/UI_elements/icon.png");
	audio_icon = App->textures->Load("pinball/UI_elements/audio_icon.png");
	bestscore = App->textures->Load("pinball/UI_elements/bestscore.png");
	bg_menu = App->textures->Load("pinball/UI_elements/bg_menu.png");
	but_credits = App->textures->Load("pinball/UI_elements/but_credits.png");
	but_exit = App->textures->Load("pinball/UI_elements/but_exit.png");
	but_fullscreen = App->textures->Load("pinball/UI_elements/but_fullscreen.png");
	but_home = App->textures->Load("pinball/UI_elements/but_home.png");
	but_no = App->textures->Load("pinball/UI_elements/but_no.png");
	but_yes = App->textures->Load("pinball/UI_elements/but_yes.png");
	but_play = App->textures->Load("pinball/UI_elements/but_play.png");
	but_restart = App->textures->Load("pinball/UI_elements/but_restart.png");
	but_settings = App->textures->Load("pinball/UI_elements/but_settings.png");
	but_start = App->textures->Load("pinball/UI_elements/but_start.png");
	credits_panel = App->textures->Load("pinball/UI_elements/credits_panel.png");
	ctl_logo = App->textures->Load("pinball/UI_elements/ctl_logo.png");
	extra_ball = App->textures->Load("pinball/UI_elements/extra_ball.png");
	hand_anim = App->textures->Load("pinball/UI_elements/hand_anim.png");
	keys = App->textures->Load("pinball/UI_elements/keys.png");
	msg_box = App->textures->Load("pinball/UI_elements/msg_box.png");
	progress_bar = App->textures->Load("pinball/UI_elements/progress_bar.png");
	score_panel = App->textures->Load("pinball/UI_elements/score_panel.png");
	star = App->textures->Load("pinball/UI_elements/star.png");

	//load pinball elements
	pinball_bg = App->textures->Load("pinball/pinball_elements/pinball_bg.png");
	arrow_light_0 = App->textures->Load("pinball/pinball_elements/arrow_light_0.png");
	arrow_light_1 = App->textures->Load("pinball/pinball_elements/arrow_light_1.png");
	arrow_start = App->textures->Load("pinball/pinball_elements/arrow_start.png");
	ball = App->textures->Load("pinball/pinball_elements/ball.png");
	bumper = App->textures->Load("pinball/pinball_elements/bumper.png");
	bumper_button = App->textures->Load("pinball/pinball_elements/bumper_button.png");
	button_light_0 = App->textures->Load("pinball/pinball_elements/button_light_0.png");
	button_light_1 = App->textures->Load("pinball/pinball_elements/button_light_1.png");
	button_light_2 = App->textures->Load("pinball/pinball_elements/button_light_2.png");
	button_light_3 = App->textures->Load("pinball/pinball_elements/button_light_3.png");
	button_light_4 = App->textures->Load("pinball/pinball_elements/button_light_4.png");
	button_light_5 = App->textures->Load("pinball/pinball_elements/button_light_5.png");
	capsule_0 = App->textures->Load("pinball/pinball_elements/capsule_0.png");
	capsule_1 = App->textures->Load("pinball/pinball_elements/capsule_1.png");
	capsule_2 = App->textures->Load("pinball/pinball_elements/capsule_2.png");
	capsule_3 = App->textures->Load("pinball/pinball_elements/capsule_3.png");
	curve_light_button = App->textures->Load("pinball/pinball_elements/curve_light_button.png");
	curve_tunnel = App->textures->Load("pinball/pinball_elements/curve_tunnel.png");
	eye = App->textures->Load("pinball/pinball_elements/eye.png");
	flipper = App->textures->Load("pinball/pinball_elements/flipper.png");
	flipper_bumper = App->textures->Load("pinball/pinball_elements/flipper_bumper.png");
	gate = App->textures->Load("pinball/pinball_elements/gate.png");
	hole = App->textures->Load("pinball/pinball_elements/hole.png");
	jackpot = App->textures->Load("pinball/pinball_elements/jackpot.png");
	jumper = App->textures->Load("pinball/pinball_elements/jumper.png");
	letter_P = App->textures->Load("pinball/pinball_elements/letter_0.png");
	letter_I = App->textures->Load("pinball/pinball_elements/letter_1.png");
	letter_N = App->textures->Load("pinball/pinball_elements/letter_2.png");
	letter_B = App->textures->Load("pinball/pinball_elements/letter_3.png");
	letter_A = App->textures->Load("pinball/pinball_elements/letter_4.png");
	letter_L0 = App->textures->Load("pinball/pinball_elements/letter_5.png");
	letter_L1 = App->textures->Load("pinball/pinball_elements/letter_6.png");
	light_indicator_0 = App->textures->Load("pinball/pinball_elements/light_indicator_0.png");
	light_indicator_1 = App->textures->Load("pinball/pinball_elements/light_indicator_1.png");
	light_indicator_2 = App->textures->Load("pinball/pinball_elements/light_indicator_2.png");
	logo = App->textures->Load("pinball/pinball_elements/logo.png");
	multiplier_light = App->textures->Load("pinball/pinball_elements/multiplier_light.png");
	multiplier_toggle_light = App->textures->Load("pinball/pinball_elements/multiplier_toggle_light.png");
	router_light_0 = App->textures->Load("pinball/pinball_elements/router_light_0.png");
	router_light_1 = App->textures->Load("pinball/pinball_elements/router_light_1.png");
	router_light_2 = App->textures->Load("pinball/pinball_elements/router_light_2.png");
	router_light_3 = App->textures->Load("pinball/pinball_elements/router_light_3.png");
	router_light_4 = App->textures->Load("pinball/pinball_elements/router_light_4.png");
	router_light_5 = App->textures->Load("pinball/pinball_elements/router_light_5.png");
	router_light_6 = App->textures->Load("pinball/pinball_elements/router_light_6.png");
	safe_pin = App->textures->Load("pinball/pinball_elements/safe_pin.png");
	shield = App->textures->Load("pinball/pinball_elements/shield.png");
	spring = App->textures->Load("pinball/pinball_elements/spring.png");
	start_platform = App->textures->Load("pinball/pinball_elements/start_platform.png");
	tunnel_start = App->textures->Load("pinball/pinball_elements/tunnel_start.png");


	//adapt walls to screen size

	for (int i = 0; i < 102; i++)
	{
		mainWalls[i] *= SCREEN_SIZE;
	}
	
	for (int i = 0; i < 16; i++)
	{
		leftWall[i] *= SCREEN_SIZE;
	}
	
	for (int i = 0; i < 16; i++)
	{
		rightWall[i] *= SCREEN_SIZE;
	}

	for (int i = 0; i < 12; i++)
	{
		leftRedIsland[i] *= SCREEN_SIZE;
	}
	for (int i = 0; i < 12; i++)
	{
		rightRedIsland[i] *= SCREEN_SIZE;
	}
	for (int i = 0; i < 24; i++)
	{
		bigIsland[i] *= SCREEN_SIZE;
	}
	for (int i = 0; i < 18; i++)
	{
		littleIsland[i] *= SCREEN_SIZE;
	}

	//Create all the walls
	
	walls.add(App->physics->CreateStaticChain(0, 0, mainWalls, 102));
	walls.add(App->physics->CreateStaticChain(0, 0, leftWall, 16));
	walls.add(App->physics->CreateStaticChain(0, 0, rightWall, 16));
	walls.add(App->physics->CreateStaticChain(0, 0, leftRedIsland, 12));
	walls.add(App->physics->CreateStaticChain(0, 0, rightRedIsland, 12));
	walls.add(App->physics->CreateStaticChain(0, 0, bigIsland, 24));
	walls.add(App->physics->CreateStaticChain(0, 0, littleIsland, 18));

	r_arrow_light_0[0] = { 0,0,230 / 2,140 };
	r_arrow_light_0[1] = { 230 / 2,0,230,140 };
	r_arrow_light_1[0] = { 0,0,230 / 2,140 };
	r_arrow_light_1[1] = { 230 / 2,0,230,140 };
	r_arrow_start[0] = { 0,0,148 / 2,67 };
	r_arrow_start[1] = { 148 / 2,0,148,67 };

	for (int i = 0; i < 7; i++)
	{
		r_bumper[i] = { 1218 / 7 * i,0,1218 / 7 * (i + 1),348 / 2 };
	}
	for (int i = 0; i < 7; i++)
	{
		r_bumper[i + 7] = { 1218 / 7 * i,348 / 2,1218 / 7 * (i + 1),348 };
	}

	r_bumper_button[0] = { 0,0,46 / 2,74 };
	r_bumper_button[1] = { 46 / 2,0,46,74 };
	r_button_light_0[0] = { 0,0,188 / 2,94 };
	r_button_light_0[1] = { 188 / 2,0,188,94 };
	r_button_light_1[0] = { 0,0,188 / 2,94 };
	r_button_light_1[1] = { 188 / 2,0,188,94 };
	r_button_light_2[0] = { 0,0,188 / 2,94 };
	r_button_light_2[1] = { 188 / 2,0,188,94 };
	r_button_light_3[0] = { 0,0,188 / 2,94 };
	r_button_light_3[1] = { 188 / 2,0,188,94 };
	r_button_light_4[0] = { 0,0,188 / 2,94 };
	r_button_light_4[1] = { 188 / 2,0,188,94 };
	r_button_light_5[0] = { 0,0,188 / 2,94 };
	r_button_light_5[1] = { 188 / 2,0,188,94 };
	r_capsule_0[0] = { 0,0, 268 / 2,198 };
	r_capsule_0[1] = { 268 / 2,0,268,198 };
	r_capsule_1[0] = { 0,0, 268 / 2,198 };
	r_capsule_1[1] = { 268 / 2,0,268,198 };
	r_capsule_2[0] = { 0,0, 268 / 2,198 };
	r_capsule_2[1] = { 268 / 2,0,268,198 };
	r_capsule_3[0] = { 0,0, 268 / 2,198 };
	r_capsule_3[1] = { 268 / 2,0,268,198 };
	r_curve_light_button[0] = { 0,0, 234 / 2,107 };
	r_curve_light_button[1] = { 234 / 2,0,234,107 };
	r_flipper_bumper[0] = { 0,0, 256 / 2,264 };
	r_flipper_bumper[1] = { 256 / 2,0,256,264 };
	r_jackpot[0] = { 0,0, 230 / 2,197 };
	r_jackpot[1] = { 230 / 2,0,230,197 };
	r_jumper[0];
	r_jumper[1];
	r_letter_P[0] = { 0,0, 200 / 2,100 };
	r_letter_P[1] = { 200 / 2,0,200,100 };
	r_letter_I[0] = { 0,0, 200 / 2,100 };
	r_letter_I[1] = { 200 / 2,0,200,100 };
	r_letter_N[0] = { 0,0, 200 / 2,100 };
	r_letter_N[1] = { 200 / 2,0,200,100 };
	r_letter_B[0] = { 0,0, 200 / 2,100 };
	r_letter_B[1] = { 200 / 2,0,200,100 };
	r_letter_A[0] = { 0,0, 200 / 2,100 };
	r_letter_A[1] = { 200 / 2,0,200,100 };
	r_letter_L0[0] = { 0,0, 200 / 2,100 };
	r_letter_L0[1] = { 200 / 2,0,200,100 };
	r_letter_L1[0] = { 0,0, 200 / 2,100 };
	r_letter_L1[1] = { 200 / 2,0,200,100 };
	r_light_indicator_0[0] = { 0,0, 314 / 2,139 };
	r_light_indicator_0[1] = { 314 / 2,0,314,139 };
	r_light_indicator_1[0] = { 0,0, 314 / 2,139 };
	r_light_indicator_1[1] = { 314 / 2,0,314,139 };
	r_light_indicator_2[0] = { 0,0, 314 / 2,139 };
	r_light_indicator_2[1] = { 314 / 2,0,314,139 };
	r_logo[0] = { 0,0, 816 / 2,310 };
	r_logo[1] = { 816 / 2,0,816,310 };
	r_bultiplier_light[0] = { 0,0, 314 / 2,139 };
	r_bultiplier_light[1] = { 314 / 2,0,314,139 };
	r_multiplier_toggle_light[0] = { 0,0, 226 / 2,110 };
	r_multiplier_toggle_light[1] = { 226 / 2,0,226,110 };
	r_router_light_0[0] = { 0,0, 236 / 2,118 };
	r_router_light_0[1] = { 236 / 2,0,236,118 };
	r_router_light_1[0] = { 0,0, 236 / 2,118 };
	r_router_light_1[1] = { 236 / 2,0,236,118 };
	r_router_light_2[0] = { 0,0, 236 / 2,118 };
	r_router_light_2[1] = { 236 / 2,0,236,118 };
	r_router_light_3[0] = { 0,0, 236 / 2,118 };
	r_router_light_3[1] = { 236 / 2,0,236,118 };
	r_router_light_4[0] = { 0,0, 236 / 2,118 };
	r_router_light_4[1] = { 236 / 2,0,236,118 };
	r_router_light_5[0] = { 0,0, 236 / 2,118 };
	r_router_light_5[1] = { 236 / 2,0,236,118 };
	r_router_light_6[0] = { 0,0, 236 / 2,118 };
	r_router_light_6[1] = { 236 / 2,0,236,118 };
	r_shield[0] = { 0,0, 80 / 2,40 };
	r_shield[1] = { 80 / 2,0,80,40 };

	r_audio_icon[0] = { 0,0,184 / 2,100 };
	r_audio_icon[1] = { 184 / 2,0,184,100 };
	
	r_but_fullscreen[0] = { 0,0,184 / 2,100 };
	r_but_fullscreen[1] = { 184 / 2,0,184,100 };
	r_hand_anim[0] = { 0,0,1010 / 5,554 / 2 };
	r_hand_anim[0] = { 1010 / 5,0,1010 / 5 * 2,554 / 2 };

	for (int i = 0; i < 5; i++)
	{
		r_hand_anim[i] = { 1010 / 5 * i,0,1010 / 5 * (i+1),554 / 2 };
	}
	for (int i = 0; i < 5; i++)
	{
		r_hand_anim[i + 5] = { 1010 / 5 * i,554 / 2,1010 / 5 * (i + 1),554 };
	}



	// TODO: Homework - create a sensor


	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

// Update: draw background
update_status ModuleSceneIntro::Update()
{
	//if not paused not update elements but still draw them 
	//if (!gamePaused)
	

		if (App->input->GetKey(SDL_SCANCODE_SPACE) == KEY_DOWN)
		{
			ray_on = !ray_on;
			ray.x = App->input->GetMouseX();
			ray.y = App->input->GetMouseY();
		}

		if (App->input->GetKey(SDL_SCANCODE_1) == KEY_DOWN)
		{
			circles.add(App->physics->CreateCircle(App->input->GetMouseX(), App->input->GetMouseY(), 25));
			// TODO 8: Make sure to add yourself as collision callback to the circle you creates
		}

		if (App->input->GetKey(SDL_SCANCODE_2) == KEY_DOWN)
		{
			boxes.add(App->physics->CreateRectangle(App->input->GetMouseX(), App->input->GetMouseY(), 100, 50));
		}

		if (App->input->GetKey(SDL_SCANCODE_3) == KEY_DOWN)
		{
			// Pivot 0, 0
			int rick_head[64] = {
				14, 36,
				42, 40,
				40, 0,
				75, 30,
				88, 4,
				94, 39,
				111, 36,
				104, 58,
				107, 62,
				117, 67,
				109, 73,
				110, 85,
				106, 91,
				109, 99,
				103, 104,
				100, 115,
				106, 121,
				103, 125,
				98, 126,
				95, 137,
				83, 147,
				67, 147,
				53, 140,
				46, 132,
				34, 136,
				38, 126,
				23, 123,
				30, 114,
				10, 102,
				29, 90,
				0, 75,
				30, 62
			};

			ricks.add(App->physics->CreateChain(App->input->GetMouseX(), App->input->GetMouseY(), rick_head, 64));
		}

		// Prepare for raycast ------------------------------------------------------

		fPoint mouse;
		mouse.x = App->input->GetMouseX();
		mouse.y = App->input->GetMouseY();
		float ray_hit = ray.DistanceTo(mouse);

		fVector normal(0.0f, 0.0f);
	
		// All draw functions ------------------------------------------------------
		p2List_item<PhysBody*>* c = circles.getFirst();

		App->renderer->Blit(pinball_bg, 0, 0, nullptr);

		//the elements under will not appear correctly, but we dont need them :)

		while (c != NULL)
		{
			int x, y;
			c->data->GetPosition(x, y);
			if (c->data->Contains(App->input->GetMouseX(), App->input->GetMouseY()))
				App->renderer->Blit(circle, x, y, NULL, 1.0f, c->data->GetRotation());
			c = c->next;
		}

		c = boxes.getFirst();

		while (c != NULL)
		{
			int x, y;
			c->data->GetPosition(x, y);
			App->renderer->Blit(box, x, y, NULL, 1.0f, c->data->GetRotation());
			if (ray_on)
			{
				int hit = c->data->RayCast(ray.x, ray.y, mouse.x, mouse.y, normal.x, normal.y);
				if (hit >= 0)
					ray_hit = hit;
			}
			c = c->next;
		}

		c = ricks.getFirst();

		while (c != NULL)
		{
			int x, y;
			c->data->GetPosition(x, y);
			App->renderer->Blit(rick, x, y, NULL, 1.0f, c->data->GetRotation());
			c = c->next;
		}

		// ray -----------------
		if (ray_on == true)
		{
			fVector destination(mouse.x - ray.x, mouse.y - ray.y);
			destination.Normalize();
			destination *= ray_hit;

			App->renderer->DrawLine(ray.x, ray.y, ray.x + destination.x, ray.y + destination.y, 255, 255, 255);

			if (normal.x != 0.0f)
				App->renderer->DrawLine(ray.x + destination.x, ray.y + destination.y, ray.x + destination.x + normal.x * 25.0f, ray.y + destination.y + normal.y * 25.0f, 100, 255, 100);
		}
		//right: 726  left: 326  y: 1706		
		App->renderer->Blit(flipper, 326, 1076, nullptr, 1, 0, NULL, NULL, SDL_FLIP_HORIZONTAL);
		App->renderer->Blit(flipper, 726, 1076, nullptr, 1, 0, NULL, NULL, SDL_FLIP_NONE);

		
		//right: 840  left: 240  y: 1460
		App->renderer->Blit(flipper_bumper, 240, 1460, &r_flipper_bumper[1], 1, 0, NULL, NULL, SDL_FLIP_HORIZONTAL);
		App->renderer->Blit(flipper_bumper, 840, 1460, &r_flipper_bumper[1], 1, 0, NULL, NULL, SDL_FLIP_NONE);


	return UPDATE_CONTINUE;
}

// TODO 8: Now just define collision callback for the circle and play bonus_fx audio
