#ifndef __ROOM_M_SCENE_H__
#define __ROOM_M_SCENE_H__

#include "cocos2d.h"
#include "Constants.h"
#include "..\Hall\HallScene.h"
#include "..\..\Common\GUI\BaseGUI.h"
#include "..\..\Common\Action\BaseAction.h"

class RoomMScene : public cocos2d::CCLayer
{
private:
	CCSize visibleSize;
	CCPoint origin;
	CCSprite* pRoomBackground;
	CCSprite* pPoker;
/*	TexaPoker::BaseGUI::BaseArmatureButton* pFireButton;*/
	TexaPoker::BaseGUI::BaseArmatureButton* pHeartButton;
	TexaPoker::BaseGUI::BaseMoveButton* pRoomMGirlButton;

public:
	RoomMScene();
	~RoomMScene();
	virtual bool init();  
	CREATE_FUNC(RoomMScene);
	void onEnter();
	void onExit();
	void menuBackCallback(CCObject* pSender);
	void heartCallback(CCEvent* pEvent);
};

#endif