#include<DxLib.h>
#include"ImageLoad.h"

MapImageDataPtr MapImageData::_instance;
MapDataPtr MapData::_mapdata;
CharacterImageDataPtr CharacterImageData::_charimg;

MapImageData::MapImageData(){
}

MapImageData::~MapImageData() {

}

CharacterImageData::CharacterImageData() {

}

CharacterImageData::~CharacterImageData() {

}

MapData::MapData() {

}

MapData::~MapData() {

}


void MapImageData::SetMapImageData( const MapImageDataPtr &imagedata ) {
	_instance = imagedata;
}

void MapImageData::GetMapImageData( MapImageDataPtr &temp ) {
	if ( !_instance ) {
		_instance = MapImageDataPtr(new MapImageData);
	}

	temp = _instance;
}

void CharacterImageData::SetCharacterImageData(const CharacterImageDataPtr &temp) {
	_charimg = temp;
}

void CharacterImageData::GetCharacterImageData(CharacterImageDataPtr &temp) {
	if (!_charimg) {
		_charimg = CharacterImageDataPtr(new CharacterImageData);
	}
	temp = _charimg;
}

void LoadUnityChanImage() {
	CharacterImageDataPtr _charimgdata;
	_charimgdata->GetCharacterImageData(_charimgdata);
	MapImageDataPtr _mapdata;
	_mapdata->GetMapImageData(_mapdata);

	int imgtemp[256];
	// UnityChanImg
	LoadDivGraph("media\\UnityChan.png", 28, 7, 4, 64, 64, imgtemp);

	// Run
	_charimgdata->_playerimg.run[ 0 ] = imgtemp[ 7 ];
	_charimgdata->_playerimg.run[ 1 ] = imgtemp[ 8 ];
	_charimgdata->_playerimg.run[ 2 ] = imgtemp[ 9 ];
	_charimgdata->_playerimg.run[ 3 ] = imgtemp[ 10 ];
	_charimgdata->_playerimg.run[ 4 ] = imgtemp[ 14 ];
	_charimgdata->_playerimg.run[ 5 ] = imgtemp[ 15 ];
	_charimgdata->_playerimg.run[ 6 ] = imgtemp[ 16 ];
	_charimgdata->_playerimg.run[ 7 ] = imgtemp[ 17 ];

	// Wait
	_charimgdata->_playerimg.wait[ 0 ] = imgtemp[ 0 ];
	_charimgdata->_playerimg.wait[ 1 ] = imgtemp[ 1 ];

	// jump_up
	_charimgdata->_playerimg.jumpup[0] = imgtemp[ 21 ];
	_charimgdata->_playerimg.jumpup[1] = imgtemp[ 22 ];

	// jump_down
	_charimgdata->_playerimg.jumpdown[0] = imgtemp[ 26 ];
	_charimgdata->_playerimg.jumpdown[1] = imgtemp[ 27 ];


	_charimgdata->SetCharacterImageData(_charimgdata);
}

void LoadGameImage( ) {
	MapImageDataPtr _imagedata;
	_imagedata -> GetMapImageData(_imagedata);
	int imgtemp[256];

	//font
	_imagedata->_middlefont = CreateFontToHandle("メイリオ", 42, -1, DX_FONTTYPE_ANTIALIASING);
	_imagedata->_largefont = CreateFontToHandle("メイリオ", 90, -1, DX_FONTTYPE_ANTIALIASING);

	// unitychan アニメーション
	LoadUnityChanImage();


	// マップイメージ
	_imagedata -> _imagehandles.block = LoadGraph( "media\\smp2_block.png" );
	_imagedata -> _imagehandles.bullet = LoadGraph( "media\\smp2_bullet.png" );
	_imagedata -> _imagehandles.title = LoadGraph( "media\\smp2_title.png" );

	// BlockImg
	LoadDivGraph("media\\map\\Coin1.png", 3, 3, 1, 50, 50, imgtemp);

	_imagedata->_imagehandles.coin[0] = LoadGraph("media\\map\\Coin2.png");
	_imagedata->_imagehandles.coin[1] = imgtemp[1];
	_imagedata->_imagehandles.coin[2] = imgtemp[2];

	_imagedata -> SetMapImageData( _imagedata );
}

void MapData::GetMapData( MapDataPtr &temp ) {
	if (!_mapdata) {
		_mapdata = MapDataPtr(new MapData);
	}

	temp = _mapdata;
}

void MapData::SetMapData( const MapDataPtr &temp ) {
	_mapdata = temp;
}

void MapData::InitStage() {
	sprintf_s(buf, 256, "media\\stage1.txt", _stagedata.stagenum + 1);
	int fh = FileRead_open(buf);
	for (int y = 0; y < MAP_HEIGHT; y++) {
		FileRead_gets(_data[y], 256, fh);
	}
	FileRead_close(fh);
	_stagedata.mapwitdh = (int)strlen(_data[0]);
}