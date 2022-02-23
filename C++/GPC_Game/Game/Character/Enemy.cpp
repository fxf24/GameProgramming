#include "stdafx.h"
#include "Enemy.h"

void Enemy::Start()
{
	character.Content = "bulletman_idle";
	character.Length = { (144 / 6) * 2, 27 * 2 };
	character.Location = { 0, 0 };
	character.Repeatable = true;
	character.Duration = 1.0f;
	character.view = View::idle;
}

bool Enemy::Update()
{
	vector<2> direction;

	switch (character.view)
	{
	case View::idle:
		character.Content = "bulletman_idle";
		break;
	case View::back:
		character.Content = "bulletman_idle_back";
		break;
	}

	if (static_cast<int>(Time::Get::Elapsed()) % 2 == 0)
	{
		std::random_device rd;

		std::mt19937 gen(rd());

		std::uniform_int_distribution<int> dis(0, 99);

		switch (dis(gen) % 8)
		{
		case 0:
			character.view = View::idle;
			character.Content = "bulletman_run_left";
			direction[0] += 1000;
			character.direction = false;
			break;
		case 1:
			character.view = View::idle;
			character.Content = "bulletman_run_left";
			direction[0] -= 1000;
			character.direction = true;
			break;
		case 2:
			character.view = View::back;
			character.Content = "bulletman_run_back";
			direction[1] -= 1000;
			break;
		case 3:
			character.view = View::idle;
			character.Content = "bulletman_run_left";
			direction[1] += 1000;
			break;
		case 4:
			character.view = View::back;
			character.Content = "bulletman_run_back";
			direction[0] += 1000;
			direction[1] += 1000;
			break;
		case 5:
			character.view = View::back;
			character.Content = "bulletman_run_back";
			direction[0] -= 1000;
			direction[1] += 1000;
			break;
		case 6:
			character.view = View::idle;
			character.Content = "bulletman_run_left";
			direction[0] += 1000;
			direction[1] -= 1000;
			break;
		case 7:
			character.view = View::idle;
			character.Content = "bulletman_run_left";
			direction[0] -= 1000;
			direction[1] -= 1000;
			break;
		}
	}

	if (length(direction) != 0)
	{
		character.Location += normalize(direction) * 500 * Time::Get::Delta();
	}

	character.Draw();
	return false;
}

void Enemy::End()
{
}
