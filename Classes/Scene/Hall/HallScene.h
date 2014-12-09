#ifndef __HALL_SCENE_H__
#define __HALL_SCENE_H__

#include "cocos2d.h"
#include "Constants.h"
#include "..\RoomM\RoomMScene.h"
#include "..\..\Common\GUI\BaseGUI.h"
#include "..\..\Common\Action\BaseAction.h"

#define SCENE_Z_ORDER_BUTTON SCENE_Z_ORDER_BG + 2

class HallScene : public cocos2d::CCLayer
{

private:
	CCSprite* pHallBackground;
	cocos2d::extension::CCArmature* pHallGirl;
	TexaPoker::BaseGUI::BaseArmatureButton* pHallButtonRed;
	TexaPoker::BaseGUI::BaseButton  * pHallButtonBlue1;
	TexaPoker::BaseGUI::BaseMoveButton  * pHallButtonBlue2;
	TexaPoker::BaseGUI::BaseMoveButton  * pHallButtonBlue2Behind;
	TexaPoker::BaseGUI::BaseMoveButton  * pHallButtonBlue2Behind1;
	TexaPoker::BaseGUI::BaseMoveButton  * pHallButtonBlue2Behind2;
	TexaPoker::BaseGUI::BaseMoveButton  * pHallButtonBlue2Behind3;
	CCNode * heartParticle;
	CCSprite* pHallFace;
	CCSprite* pHallCoins;
	CCLabelTTF* pUserName;
	CCLabelTTF* pCoinNum;
	TexaPoker::BaseGUI::BaseButton  * pHallButtonRectGold;
	TexaPoker::BaseGUI::BaseButton  * pHallButtonRectBlue;
	CCSprite* pHallGameBg;
	int HallButtonBlue2Status; //0 ³õÊ¼×´Ì¬ 1»¹Ô­×´Ì¬
	virtual void keyBackClicked();//Android ·µ»Ø¼ü

public:
	HallScene();

	~HallScene();
	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();  

	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::CCScene* scene();

	// a selector callback
	void menuCloseCallback(CCObject* pSender);

	// implement the "static node()" method manually
	CREATE_FUNC(HallScene);

	void pHallButtonBlue2Touched(CCObject* pSender);

	void redButonCallback(CCEvent* pEvent);


};

#endif
