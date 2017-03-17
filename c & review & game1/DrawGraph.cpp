#include<DxLib.h>
#include"PlayerController.h"
#include"DrawGraph.h"
#include"Loding.h"
#include"MapData.h"
#include"enemies.h"

void DrawMainGame() {
	DrawMap();
	DrawPlayerGraph();
	DrawEnemyGraph();
	DrawDragonFire();
}

void DrawMap() {
	for ( int y = 0; y < MAP_HITGHT; y++ ) {
		for ( int x = 0; x < MAP_WIDTH; x++ ) {
			DrawGraph( x * IMG_CHIPSIZE, y * IMG_CHIPSIZE, _imagehandles.mapitem[ 0 ], TRUE );
			DrawGraph( x * IMG_CHIPSIZE, y * IMG_CHIPSIZE, _imagehandles.mapitem[ _mapdata[y][x] ], TRUE );
		}
	}
}

void DrawPlayerGraph() {
	DrawGraph( _playerstatus.posx * IMG_CHIPSIZE, _playerstatus.posy * IMG_CHIPSIZE, _imagehandles.player, TRUE );
	
}

void DrawTitleGraph() {
	DrawBox( 0, 0, 800, 600, GetColor(255, 255, 255), TRUE );
	DrawGraph( 0, 0, _imagehandles.gametitleimg, TRUE );
	//テキスト
	DrawStringToHandle( 100, 400, "Zキーでゲームスタート", GetColor( 255, 0, 255 ), _middlefont );
	DrawStringToHandle( 100, 460, "カーソルキーで移動", GetColor( 0, 0, 0 ), _middlefont );
}

void DrawEnemyGraph() {
	for( int i = 0; i < ENEMY_MAX; i++ ) {
		if ( _enemystatus[i].type == MT_HOLI ) {
			DrawGraph( _enemystatus[i].posx * IMG_CHIPSIZE, _enemystatus[i].posy * IMG_CHIPSIZE, _imagehandles.enemyholi, _enemystatus[i].living );
		}
		if ( _enemystatus[i].type == MT_DRAGON ) {
			DrawGraph( _enemystatus[i].posx * IMG_CHIPSIZE, _enemystatus[i].posy * IMG_CHIPSIZE, _imagehandles.dragon, TRUE );
		}
	}
}

void DrawDragonFire() {
	for( int i = 0; i < FIRE_MAX; i++ ) {
		if ( _firedata[i].activation == TRUE ) {
			DrawGraph( _firedata[i].posx * IMG_CHIPSIZE, _firedata[i].posy * IMG_CHIPSIZE, _imagehandles.fire, TRUE );
		}
	}
}

void DrawGameOverUpdata() {
	DrawStringToHandle( 100, 400, "ゲームオーバー", GetColor( 255, 0, 0 ), _largefont );
}

void DrawGameClearUpdata() {
	DrawBox( 0, 0, 800, 600, GetColor( 255, 255, 255 ), TRUE );
	DrawStringToHandle( 100, 200, "ゲームクリア", GetColor( 80, 128, 255 ), _largefont );
}

