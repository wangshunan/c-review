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

	// Run
	_charimgdata->_playerimg.run[0] = LoadGraph("media\\unitychan\\run\\Unitychan_Run_1.png");
	_charimgdata->_playerimg.run[1] = LoadGraph("media\\unitychan\\run\\Unitychan_Run_2.png");
	_charimgdata->_playerimg.run[2] = LoadGraph("media\\unitychan\\run\\Unitychan_Run_3.png");
	_charimgdata->_playerimg.run[3] = LoadGraph("media\\unitychan\\run\\Unitychan_Run_4.png");
	_charimgdata->_playerimg.run[4] = LoadGraph("media\\unitychan\\run\\Unitychan_Run_5.png");
	_charimgdata->_playerimg.run[5] = LoadGraph("media\\unitychan\\run\\Unitychan_Run_6.png");
	_charimgdata->_playerimg.run[6] = LoadGraph("media\\unitychan\\run\\Unitychan_Run_7.png");
	_charimgdata->_playerimg.run[7] = LoadGraph("media\\unitychan\\run\\Unitychan_Run_8.png");

	// Wait
	_charimgdata->_playerimg.wait[0] = LoadGraph("media\\unitychan\\wait\\Unitychan_Idle_1.png");
	_charimgdata->_playerimg.wait[1] = LoadGraph("media\\unitychan\\wait\\Unitychan_Idle_2.png");
	_charimgdata->_playerimg.wait[2] = LoadGraph("media\\unitychan\\wait\\Unitychan_Idle_3.png");
	_charimgdata->_playerimg.wait[3] = LoadGraph("media\\unitychan\\wait\\Unitychan_Idle_4.png");

	// jump_up
	_charimgdata->_playerimg.jumpup[0] = LoadGraph("media\\unitychan\\jumpup\\Unitychan_Jump_Up_1.png");
	_charimgdata->_playerimg.jumpup[1] = LoadGraph("media\\unitychan\\jumpup\\Unitychan_Jump_Up_2.png");

	// jump_down
	_charimgdata->_playerimg.jumpdown[0] = LoadGraph("media\\unitychan\\fall\\Unitychan_Jump_Fall_1.png");
	_charimgdata->_playerimg.jumpdown[1] = LoadGraph("media\\unitychan\\fall\\Unitychan_Jump_Fall_2.png");


	_charimgdata->SetCharacterImageData(_charimgdata);
}

void LoadGameImage( ) {
	MapImageDataPtr _imagedata;
	_imagedata -> GetMapImageData(_imagedata);

	//font
	_imagedata->_middlefont = CreateFontToHandle("メイリオ", 42, -1, DX_FONTTYPE_ANTIALIASING);
	_imagedata->_largefont = CreateFontToHandle("メイリオ", 90, -1, DX_FONTTYPE_ANTIALIASING);

	// unitychan アニメーション
	LoadUnityChanImage();


	// マップイメージ
	_imagedata -> _imagehandles.block = LoadGraph( "media\\smp2_block.png" );
	_imagedata -> _imagehandles.bullet = LoadGraph( "media\\smp2_bullet.png" );
	_imagedata -> _imagehandles.knife = LoadGraph( "media\\smp2_knife.png" );
	_imagedata -> _imagehandles.title = LoadGraph( "media\\smp2_title.png" );

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