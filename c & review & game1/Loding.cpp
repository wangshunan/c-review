#include<Dxlib.h>
#include"Loding.h"
#include"DrawGraph.h"

ImageHandles _imagehandles;
int _middlefont;
int _largefont;

void LoadGameImage() {
	_imagehandles.player = LoadGraph( "media\\smp1_chara01.png" );
	_imagehandles.gametitleimg = LoadGraph( "media\\smp1_title.png" );
	_imagehandles.mapitem[ 0 ] = LoadGraph( "media\\smp1_back.png" );
	_imagehandles.mapitem[ 1 ] = LoadGraph( "media\\smp1_rock.png" );
	_imagehandles.mapitem[ 2 ] = LoadGraph( "media\\smp1_key.png" );
	_imagehandles.mapitem[ 3 ] = LoadGraph( "media\\smp1_goal.png" );
	_imagehandles.enemyholi = LoadGraph( "media\\smp1_chara02.png" );
	_imagehandles.dragon = LoadGraph( "media\\smp1_chara03.png" );
	_imagehandles.fire = LoadGraph( "media\\smp1_chara04.png" );
	_middlefont = CreateFontToHandle( "メイリオ", 42, -1, DX_FONTTYPE_ANTIALIASING );
	_largefont = CreateFontToHandle( "メイリオ", 90, -1, DX_FONTTYPE_ANTIALIASING );
}

BOOL LoadGameImageCheck() {
	if ( _imagehandles.player == -1 ) return FALSE;
	if ( _imagehandles.gametitleimg == -1 ) return FALSE;
	if ( _imagehandles.mapitem[0] == -1 ) return FALSE;
	if ( _imagehandles.mapitem[1] == -1 ) return FALSE;
	if ( _imagehandles.mapitem[2] == -1 ) return FALSE;
	if ( _imagehandles.mapitem[3] == -1 ) return FALSE;
	if ( _imagehandles.enemyholi == -1 ) return FALSE;
	if ( _imagehandles.dragon == -1 ) return FALSE;
	if ( _imagehandles.fire == -1 ) return FALSE;

	return TRUE;
}