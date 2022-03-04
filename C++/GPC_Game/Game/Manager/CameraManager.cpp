#include "stdafx.h"
#include "CameraManager.h"

void CameraManager::Init(Rendering::Image::Component background, Rendering::Animation::Component* player, Rendering::Camera* camera)
{
	Background = background;
	Player = player;
	Camera = camera;
}

void CameraManager::DeInit()
{
	Player = nullptr;
	Camera = nullptr;
}

void CameraManager::CameraRange()
{
	if (Player->Angle != 0.0f and Background.Angle != 0.0f) return;
	
	vector<2> const min[2]
	{
		Player->Location - Player->Length / 2,
		Background.Location - Background.Length / 2,
	};

	vector<2> const max[2]
	{
		Player->Location + Player->Length / 2,
		Background.Location + Background.Length / 2,
	};

	if (min[0][0] <= min[1][0]) Player->Location[0] += 3.0f;
	if (min[0][1] <= min[1][1]) Player->Location[1] += 3.0f;
	if (max[0][0] >= max[1][0]) Player->Location[0] -= 3.0f;
	if (max[0][1] >= max[1][1]) Player->Location[1] -= 3.0f;
	
	if (Player->Location[0] <= min[1][0] + 640.0f) Camera->Location[0] = min[1][0] + 640.0f;
	if (Player->Location[1] <= min[1][1] + 360.0f) Camera->Location[1] = min[1][1] + 360.0f;
	if (Player->Location[0] >= max[1][0] - 640.0f) Camera->Location[0] = max[1][0] - 640.0f;
	if (Player->Location[1] >= max[1][1] - 360.0f) Camera->Location[1] = max[1][1] - 360.0f;

}
