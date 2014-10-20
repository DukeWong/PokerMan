#ifndef __ROOM_M_SCENE_H__
#define __ROOM_M_SCENE_H__

#include "cocos2d.h"
#include "Constants.h"
#include "..\Hall\HallScene.h"
#include "Sprites\RoomBackground.h"
#include "Controller\RollingOverManager.h"
#include "..\..\Common\GUI\BaseGUI.h"
#include "..\..\Common\Action\BaseAction.h"

#define ROOM_STATUS_INIT 0
#define ROOM_STATUS_CARD_FLOW 1

#define ROOM_INIT_INTERVAL_TIME 0.3F

class RoomMScene : public cocos2d::CCLayer
{
private:
	CCSize visibleSize;
	CCPoint origin;
	int roomBackground1Tag;
	int roomBackground2Tag;
	int pokerTag;
	int heartButtonTag;
	int fireButtonTag;
	int roomMGirlButtonTag;
	int roomStatus;
	TexaPoker::RoomM::Controller::RollingOverManager* pRManager;
	void checkSpritesStatus();


public:
	RoomMScene();
	~RoomMScene();
	virtual bool init();  
	CREATE_FUNC(RoomMScene);
	void onEnter();
	void onExit();
	void menuBackCallback(CCObject* pSender);
	void heartCallback(CCEvent* pEvent);
	void update(float data);
	void initCards(float data);
};

#endif