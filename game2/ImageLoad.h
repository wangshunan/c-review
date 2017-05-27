#pragma once
#include"smart_ptr.h"
#include<vector>

PTR( MapImageData );
PTR( MapData );
PTR( CharacterImageData );

class MapImageData{
public:
	MapImageData();
	virtual ~MapImageData();

	void GetMapImageData( MapImageDataPtr &temp );
	void SetMapImageData( const MapImageDataPtr &imagedata );
protected:
	struct ImageHandles{
		int block;
		int coin[3];
		int bullet;
		int title;
	};
	static MapImageDataPtr _instance;
public:
	ImageHandles _imagehandles;
	int _middlefont;
	int _largefont;
	const int CHIP_SIZE = 50;
};

class CharacterImageData {
public:
	CharacterImageData();
	virtual ~CharacterImageData();

	void GetCharacterImageData( CharacterImageDataPtr &temp );
	void SetCharacterImageData( const CharacterImageDataPtr &temp );
private:
	struct PlayerImageHandles {
		int wait[2];
		int run[8];
		int jumpup[2];
		int jumpdown[2];
		int damage[1];
		int dead[1];
	};

	static CharacterImageDataPtr _charimg;
public:
	PlayerImageHandles _playerimg;
	std::vector<int> _nowanim;
};
	

class MapData {
public:
	MapData();
	virtual ~MapData();

	void GetMapData( MapDataPtr &temp );
	void SetMapData( const MapDataPtr &temp );
	void InitStage();
	CONST static int MAP_HEIGHT = 15;
	CONST static int MAP_WIDTH = 800;
private:
	char buf[256];
	struct StageData {
		int stagenum;
		int mapwitdh;
	};
public:
	char _data[MAP_HEIGHT][MAP_WIDTH + 1];
	const int CHIP_SIZE = 50;
	static MapDataPtr _mapdata;
	StageData _stagedata;
};

void LoadUnityChanImage();
void LoadGameImage();
