#include "RoomMScene.h"
#include "Constants.h"
#include "CocoStudio\Armature\utils\CCArmatureDataManager.h"
#include "CocoStudio\Armature\CCArmature.h"

USING_NS_CC;

RoomMScene::RoomMScene()
	:visibleSize(CCDirector::sharedDirector()->getVisibleSize())
	,origin(CCDirector::sharedDirector()->getVisibleOrigin())
	,roomBackgroundTag(0x0001)
	,pokerTag(0x0010)
	,heartButtonTag(0x0011)
	,roomMGirlButtonTag(0x0111)
	//,pPoker(CCSprite::create(ROOM_M_PATH_CONNECT(/card_back.png), CCRectMake(0,0,CCDirector::sharedDirector()->getVisibleSize().width,CCDirector::sharedDirector()->getVisibleSize().height)))
{
	/*
	cocos2d::extension::CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo(ROOM_M_SPRITE_PATH_CONNECT(/fire/fire.png), ROOM_M_SPRITE_PATH_CONNECT(/fire/fire.plist), ROOM_M_SPRITE_PATH_CONNECT(/fire/fire.xml));    
	pFireButton = TexaPoker::BaseGUI::BaseArmatureButton::create(1, "fire", 5, NULL);*/
	cocos2d::extension::CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo(ROOM_M_SPRITE_PATH_CONNECT(/heart/heart.png), ROOM_M_SPRITE_PATH_CONNECT(/heart/heart.plist), ROOM_M_SPRITE_PATH_CONNECT(/heart/heart.xml));
}

RoomMScene::~RoomMScene()
{

}

bool RoomMScene::init()
{

	CCMenuItemImage *pBackItem = CCMenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		this,
		menu_selector(RoomMScene::menuBackCallback));

	pBackItem->setPosition(ccp(origin.x + visibleSize.width - pBackItem->getContentSize().width/2 ,
		origin.y + pBackItem->getContentSize().height/2));

	// create menu, it's an autorelease object
	CCMenu* pMenu = CCMenu::create(pBackItem, NULL);
	pMenu->setPosition(CCPointZero);
	this->addChild(pMenu, SCENE_Z_ORDER_FRONT);

	ccTexParams params = {GL_LINEAR,GL_LINEAR,GL_REPEAT,GL_REPEAT};
	CCSprite* pRoomBackground = CCSprite::create(ROOM_M_PATH_CONNECT(/room_bg.png), CCRectMake(0,0,CCDirector::sharedDirector()->getVisibleSize().width,CCDirector::sharedDirector()->getVisibleSize().height));
	pRoomBackground->getTexture()->setTexParameters(&params);
	pRoomBackground->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
	this->addChild(pRoomBackground, SCENE_Z_ORDER_BG, roomBackgroundTag);
	return true;
}

void RoomMScene::onEnter()
{
	CCMenuItemImage *pRoomMGirlImage = CCMenuItemImage::create(
		ROOM_M_SPRITE_PATH_CONNECT(/img_pokerlady.png),
		ROOM_M_SPRITE_PATH_CONNECT(/img_pokerlady.png),
		this,
		NULL);
	CCActionInterval*  pRoomMGirlActionBy = CCMoveBy::create(0.3, ccp(25,0));
	TexaPoker::BaseGUI::BaseMoveButton* pRoomMGirlButton = TexaPoker::BaseGUI::BaseMoveButton::create(1, pRoomMGirlImage, pRoomMGirlActionBy);
	pRoomMGirlButton->setTouchEnabled(false);
	pRoomMGirlButton->setPosition(ccp(visibleSize.width/8 + origin.x, visibleSize.height/3 + origin.y));
	this->addChild(pRoomMGirlButton, SCENE_Z_ORDER_FRONT, roomMGirlButtonTag);
	pRoomMGirlButton->moveBy(pRoomMGirlButton);

	TexaPoker::BaseGUI::BaseArmatureButton* pHeartButton = TexaPoker::BaseGUI::BaseArmatureButton::create(0.8f, "heart", 5, this, event_selector(RoomMScene::heartCallback));
	pHeartButton->getAnimation()->setAnimationScale(0.5f);
	pHeartButton->setAnchorPoint(ccp(0.5, 0.5));
	pHeartButton->setPosition(ccp(visibleSize.width/50*46, visibleSize.height/10*9));
	this->addChild(pHeartButton, SCENE_Z_ORDER_BUTTON, heartButtonTag);
	CCLayer::onEnter();
}

void RoomMScene::onExit()
{
	CCLayer::onExit();
}

/*(m_pListener->*m_pfnSelector)(this);*/
void RoomMScene::menuBackCallback(CCObject* pSender)
{
	CCScene *pScene = CCScene::create();
	HallScene *layer = HallScene::create();
	pScene->addChild(layer);
	CCDirector::sharedDirector()->replaceScene(pScene);
}

void RoomMScene::heartCallback(CCEvent* pEvent)
{
	//pHeartButton->getAnimation()->playByIndex(0);
	((TexaPoker::BaseGUI::BaseArmatureButton*)(this->getChildByTag(heartButtonTag)))->getAnimation()->playByIndex(0);
	/*
	pPoker->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
	this->addChild(pRoomBackground, SCENE_Z_ORDER_BG + 1);*/
}