#pragma once
#include <vector>
#include <string>
#include "Rendering.h"
#include "Imgui/imgui.h"
#include "Imgui/imconfig.h"
#include "Imgui/imgui_internal.h"
#include "Imgui/imstb_rectpack.h"
#include "Imgui/imstb_textedit.h"
#include "Imgui/imstb_truetype.h"

class TileMap
{
private :
	vector<2> EditTileSize;
	char	  Savefile[128];
	char	  Loadfile[128];
	unsigned ImageIndex;
	vector<2> Frame;
	int State;

	void ResetPosition(vector<2> from, vector<2> to);
	void ResetTiles(vector<2> from, vector<2> to);
	void DeleteTiles(vector<2> from, vector<2> to);

	void TileButton();
	void TileBrush();

public :
	std::vector<Rendering::Tile::Component> Images;
	vector<2> Scale;

	TileMap();
	~TileMap();

	void Start();
	void Update();
	void End();

	void Save(std::string file);
	void Load(std::string file);
};

