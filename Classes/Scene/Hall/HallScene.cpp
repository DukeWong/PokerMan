#include "HallScene.h"
#include "Constants.h"
#include "CocoStudio\Armature\utils\CCArmatureDataManager.h"
#include "CocoStudio\Armature\CCArmature.h"

USING_NS_CC;

CCScene* HallScene::scene()
{
	// 'scene' is an autorelease object
	CCScene *scene = CCScene::create();

	// 'layer' is an autorelease object
	HallScene *layer = HallScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

HallScene::HallScene()
	:pHallBackground(CCSprite::create(HALL_PATH_CONNECT(/hall_function_bg.png)))
	,pHallFace(CCSprite::create(HALL_PATH_CONNECT(/men_head.png)))
	,pHallCoins(CCSprite::create(HALL_PATH_CONNECT(/hall_function_coin.png)))
	,pUserName(CCLabelTTF::create("Poker Face", "Arial", 26))
	,pCoinNum(CCLabelTTF::create("22512", "Arial", 24))
	,pHallGameBg(CCSprite::create(HALL_PATH_CONNECT(/hall_function_houdong_gallery_bg.png)))
	,HallButtonBlue2Status(0)
{
	cocos2d::extension::CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo(HALL_SPRITE_PATH_CONNECT(/girl/hall_girl.png), HALL_SPRITE_PATH_CONNECT(/girl/hall_girl.plist), HALL_SPRITE_PATH_CONNECT(/girl/hall_girl.xml));    
	pHallGirl = cocos2d::extension::CCArmature::create("hallGirl_blink");

	cocos2d::extension::CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo(HALL_SPRITE_PATH_CONNECT(/button_red/button.png), HALL_SPRITE_PATH_CONNECT(/button_red/button.plist), HALL_SPRITE_PATH_CONNECT(/button_red/button.xml));
	pHallButtonRed = TexaPoker::BaseGUI::BaseArmatureButton::create(0.8f, "hallButton_red_blink", 5, this, event_selector(HallScene::redButonCallback));

	CCMenuItemImage *pHallButtonBlue1Image = CCMenuItemImage::create(
		HALL_PATH_CONNECT(/hall_function_halllist.png),
		HALL_PATH_CONNECT(/hall_function_halllist.png),
		this,
		NULL);    
	pHallButtonBlue1 = TexaPoker::BaseGUI::BaseButton::create(0.8f, pHallButtonBlue1Image);

	CCMenuItemImage *pHallButtonBlue2Image = CCMenuItemImage::create(
		HALL_PATH_CONNECT(/hall_function_happy_square.png),
		HALL_PATH_CONNECT(/hall_function_happy_square.png),
		this,
		menu_selector(HallScene::pHallButtonBlue2Touched));
	CCActionInterval*  pHallButtonBlue2ActionBy = CCMoveBy::create(0.1, ccp(265,0));
	pHallButtonBlue2 = TexaPoker::BaseGUI::BaseMoveButton::create(0.8f, pHallButtonBlue2Image, pHallButtonBlue2ActionBy);

	CCMenuItemImage * pHallButtonBlue2BehindImage = CCMenuItemImage::create(
		HALL_PATH_CONNECT(/hall_function_happy_square_bg.png),
		HALL_PATH_CONNECT(/hall_function_happy_square_bg.png),
		this,
		NULL);
	CCActionInterval*  pHallButtonBlue2BehindActionBy = CCMoveBy::create(0.1, ccp(-65,0));
	pHallButtonBlue2Behind = TexaPoker::BaseGUI::BaseMoveButton::create(0.8f, pHallButtonBlue2BehindImage, pHallButtonBlue2BehindActionBy);
	CC_SAFE_RETAIN(pHallButtonBlue2Behind);

	CCMenuItemImage * pHallButtonBlue2Behind1Image = CCMenuItemImage::create(
		HALL_PATH_CONNECT(/hall_function_match_icon.png),
		HALL_PATH_CONNECT(/hall_function_match_icon.png),
		this,
		NULL);
	CCActionInterval*  pHallButtonBlue2BehindActionBy1 = CCMoveBy::create(0.1, ccp(-65,0));
	pHallButtonBlue2Behind1 = TexaPoker::BaseGUI::BaseMoveButton::create(0.75f, pHallButtonBlue2Behind1Image, pHallButtonBlue2BehindActionBy1);
	CC_SAFE_RETAIN(pHallButtonBlue2Behind1);

	CCMenuItemImage * pHallButtonBlue2Behind2Image = CCMenuItemImage::create(
		HALL_PATH_CONNECT(/hall_function_tigermachine_icon.png),
		HALL_PATH_CONNECT(/hall_function_tigermachine_icon.png),
		this,
		NULL);
	CCActionInterval*  pHallButtonBlue2BehindActionBy2 = CCMoveBy::create(0.1, ccp(-65,0));
	pHallButtonBlue2Behind2 = TexaPoker::BaseGUI::BaseMoveButton::create(0.75f, pHallButtonBlue2Behind2Image, pHallButtonBlue2BehindActionBy2);
	CC_SAFE_RETAIN(pHallButtonBlue2Behind2);

	CCMenuItemImage * pHallButtonBlue2Behind3Image = CCMenuItemImage::create(
		HALL_PATH_CONNECT(/happy_square_facetoface_play.png),
		HALL_PATH_CONNECT(/happy_square_facetoface_play.png),
		this,
		NULL);
	CCActionInterval*  pHallButtonBlue2BehindActionBy3 = CCMoveBy::create(0.1, ccp(-65,0));
	pHallButtonBlue2Behind3 = TexaPoker::BaseGUI::BaseMoveButton::create(0.75f, pHallButtonBlue2Behind3Image, pHallButtonBlue2BehindActionBy3);
	CC_SAFE_RETAIN(pHallButtonBlue2Behind3);


	CCMenuItemImage *pHallButtonRectGoldImage = CCMenuItemImage::create(
		HALL_PATH_CONNECT(/hall_function_recharge_center_icon.png),
		HALL_PATH_CONNECT(/hall_function_recharge_center_icon.png),
		this,
		NULL);   
	pHallButtonRectGold = TexaPoker::BaseGUI::BaseButton::create(0.8f, pHallButtonRectGoldImage);

	CCMenuItemImage *pHallButtonRectBlueImage = CCMenuItemImage::create(
		HALL_PATH_CONNECT(/hall_function_daily_task_icon.png),
		HALL_PATH_CONNECT(/hall_function_daily_task_icon.png),
		this,
		NULL);   
	pHallButtonRectBlue = TexaPoker::BaseGUI::BaseButton::create(0.8f, pHallButtonRectBlueImage);
}

HallScene::~HallScene()
{

}

// on "init" you need to initialize your instance
bool HallScene::init()
{
	//////////////////////////////
	// 1. super init first
	if ( !CCLayer::init() )
	{
		return false;
	}

	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

	/////////////////////////////
	// 2. add a menu item with "X" image, which is clicked to quit the program
	//    you may modify it.

	// add a "close" icon to exit the progress. it's an autorelease object
	CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		this,
		menu_selector(HallScene::menuCloseCallback));

	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
		origin.y + pCloseItem->getContentSize().height/2));

	// create menu, it's an autorelease object
	CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
	pMenu->setPosition(CCPointZero);
	this->addChild(pMenu, SCENE_Z_ORDER_FRONT);


	pHallBackground->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
	this->addChild(pHallBackground, SCENE_Z_ORDER_BG);

	pHallGirl->getAnimation()->setAnimationScale(0.5f);
	pHallGirl->getAnimation()->playByIndex(0);
	pHallGirl->setPosition(ccp(visibleSize.width/7 * 3 + origin.x, visibleSize.height/2 + origin.y));
	this->addChild(pHallGirl, SCENE_Z_ORDER_FRONT);

	pHallButtonRed->getAnimation()->setAnimationScale(0.3f);
	pHallButtonRed->setScale(0.8f);
	pHallButtonRed->getAnimation()->playByIndex(0);
	pHallButtonRed->setPosition(ccp(visibleSize.width/2 + visibleSize.width/3, visibleSize.height/2 + visibleSize.height/3));
	this->addChild(pHallButtonRed, SCENE_Z_ORDER_BUTTON);

	pHallButtonBlue1->setPosition(ccp(visibleSize.width/2 + visibleSize.width/3, visibleSize.height/2 + visibleSize.height/12));
	pHallButtonBlue1->setAnchorPoint(ccp(0, 0));
	this->addChild(pHallButtonBlue1, SCENE_Z_ORDER_BUTTON);

	pHallButtonBlue2->setPosition(ccp(visibleSize.width/2 + visibleSize.width/3, visibleSize.height/2 - visibleSize.height/6));
	pHallButtonBlue2->setAnchorPoint(ccp(0, 0));
	this->addChild(pHallButtonBlue2, SCENE_Z_ORDER_BUTTON);

	pHallFace->setScale(0.32f);
	pHallFace->setPosition(ccp(origin.x + visibleSize.width/15, origin.y + visibleSize.height/12 * 11));
	this->addChild(pHallFace, SCENE_Z_ORDER_BG + 1);

	pHallCoins->setScale(0.8f);
	pHallCoins->setPosition(ccp(origin.x + visibleSize.width/8, origin.y + visibleSize.height/8 * 7));
	this->addChild(pHallCoins, SCENE_Z_ORDER_BG + 1);

	pUserName->setPosition(ccp(origin.x + visibleSize.width/6, origin.y + visibleSize.height/15 * 14));
	this->addChild(pUserName, SCENE_Z_ORDER_BG + 1);

	pCoinNum->setColor(ccc3(COLOR_YELLOW));
	pCoinNum->setPosition(ccp(origin.x + visibleSize.width/6, origin.y + visibleSize.height/8 * 7));
	this->addChild(pCoinNum, 1);

	pHallButtonRectGold->setPosition(ccp(origin.x + visibleSize.width/12, visibleSize.height/2 + visibleSize.height/5));
	pHallButtonRectGold->setAnchorPoint(ccp(0, 0));
	this->addChild(pHallButtonRectGold, 1);

	pHallButtonRectBlue->setPosition(ccp(origin.x + visibleSize.width/5, visibleSize.height/2 + visibleSize.height/5));
	pHallButtonRectBlue->setAnchorPoint(ccp(0, 0));
	this->addChild(pHallButtonRectBlue, 1);

	pHallGameBg->setScale(0.82f);
	pHallGameBg->setPosition(ccp(origin.x + visibleSize.width/7, visibleSize.height/2 - visibleSize.height/10));
	this->addChild(pHallGameBg, 1);

	return true;
}


void HallScene::menuCloseCallback(CCObject* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
	CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
#endif
}

void HallScene::pHallButtonBlue2Touched(CCObject* pSender)
{
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
	pHallButtonBlue2Behind->setPosition(ccp(visibleSize.width/2 + visibleSize.width/5 * 2, visibleSize.height/2 - visibleSize.height/6));
	pHallButtonBlue2Behind->setAnchorPoint(ccp(0, 0));
	pHallButtonBlue2Behind->setTouchEnabled(false);

	pHallButtonBlue2Behind1->setPosition(ccp(visibleSize.width/2 + visibleSize.width/5 * 2 - 135 , visibleSize.height/2 - visibleSize.height/6));
	pHallButtonBlue2Behind1->setAnchorPoint(ccp(0, 0));

	pHallButtonBlue2Behind2->setPosition(ccp(visibleSize.width/2 + visibleSize.width/5 * 2 - 50, visibleSize.height/2 - visibleSize.height/6));
	pHallButtonBlue2Behind2->setAnchorPoint(ccp(0, 0));

	pHallButtonBlue2Behind3->setPosition(ccp(visibleSize.width/2 + visibleSize.width/5 * 2 + 35 , visibleSize.height/2 - visibleSize.height/6));
	pHallButtonBlue2Behind3->setAnchorPoint(ccp(0, 0));
	if(HallButtonBlue2Status ==0)
	{
		pHallButtonBlue2->moveBy(pHallButtonBlue2);
		this->addChild(pHallButtonBlue2Behind, SCENE_Z_ORDER_BG);
		this->addChild(pHallButtonBlue2Behind1, SCENE_Z_ORDER_BUTTON - 1);
		this->addChild(pHallButtonBlue2Behind2, SCENE_Z_ORDER_BUTTON - 1);
		this->addChild(pHallButtonBlue2Behind3, SCENE_Z_ORDER_BUTTON - 1);
		pHallButtonBlue2Behind->moveBy(pHallButtonBlue2Behind);
		pHallButtonBlue2Behind1->moveBy(pHallButtonBlue2Behind1);
		pHallButtonBlue2Behind2->moveBy(pHallButtonBlue2Behind2);
		pHallButtonBlue2Behind3->moveBy(pHallButtonBlue2Behind3);
		HallButtonBlue2Status = 1;
	}else{
		pHallButtonBlue2->moveByReverse(pHallButtonBlue2);
		this->removeChild(pHallButtonBlue2Behind);
		this->removeChild(pHallButtonBlue2Behind1);
		this->removeChild(pHallButtonBlue2Behind2);
		this->removeChild(pHallButtonBlue2Behind3);
		HallButtonBlue2Status = 0;
	}
}

void HallScene::redButonCallback(CCEvent* pEvent)
{
	CCScene *pScene = CCScene::create();
	TexaPoker::RoomM::Scene::RoomMScene *layer = TexaPoker::RoomM::Scene::RoomMScene::create();
	pScene->addChild(layer);
	CCDirector::sharedDirector()->getTouchDispatcher()->removeAllDelegates();
	CCDirector::sharedDirector()->replaceScene(pScene);
}


