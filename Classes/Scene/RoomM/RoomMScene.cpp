#include "RoomMScene.h"
#include "Constants.h"
#include "CocoStudio\Armature\utils\CCArmatureDataManager.h"
#include "CocoStudio\Armature\CCArmature.h"

USING_NS_CC;

namespace TexaPoker{
	namespace RoomM{
		namespace Scene{
			RoomMScene::RoomMScene()
				:visibleSize(CCDirector::sharedDirector()->getVisibleSize())
				,origin(CCDirector::sharedDirector()->getVisibleOrigin())
				,roomStatus(ROOM_STATUS_INIT)
				,pRManager(new TexaPoker::RoomM::Controller::RollingOverManager(this))
				//,pPoker(CCSprite::create(ROOM_M_PATH_CONNECT(/card_back.png), CCRectMake(0,0,CCDirector::sharedDirector()->getVisibleSize().width,CCDirector::sharedDirector()->getVisibleSize().height)))
			{
				int temp_tag = ROOMM_SCENE_TAG(1);
				roomBackground1Tag = temp_tag;
				temp_tag = ROOMM_SCENE_TAG(2);
				roomBackground2Tag = temp_tag;
				temp_tag = ROOMM_SCENE_TAG(3);
				pokerTag = temp_tag;
				temp_tag = ROOMM_SCENE_TAG(4);
				heartButtonTag = temp_tag;
				temp_tag = ROOMM_SCENE_TAG(5);
				fireButtonTag = temp_tag;
				temp_tag = ROOMM_SCENE_TAG(6);
				roomMGirlButtonTag = temp_tag;

				cocos2d::extension::CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo(ROOM_M_SPRITE_PATH_CONNECT(/fire/fire.png), ROOM_M_SPRITE_PATH_CONNECT(/fire/fire.plist), ROOM_M_SPRITE_PATH_CONNECT(/fire/fire.xml));    
				cocos2d::extension::CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo(ROOM_M_SPRITE_PATH_CONNECT(/heart/heart.png), ROOM_M_SPRITE_PATH_CONNECT(/heart/heart.plist), ROOM_M_SPRITE_PATH_CONNECT(/heart/heart.xml));
				CCSpriteFrameCache* cache = CCSpriteFrameCache::sharedSpriteFrameCache();  
				cache->addSpriteFramesWithFile(ROOM_M_SPRITE_PATH_CONNECT(/cards/img_cards.plist), ROOM_M_SPRITE_PATH_CONNECT(/cards/img_cards.png));  
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
				TexaPoker::RoomM::Sprites::RoomBackground* pRoomBackground = TexaPoker::RoomM::Sprites::RoomBackground::create(ROOM_M_PATH_CONNECT(/room_bg.png), CCRectMake(0,0,CCDirector::sharedDirector()->getVisibleSize().width,CCDirector::sharedDirector()->getVisibleSize().height));
				pRoomBackground->getTexture()->setTexParameters(&params);
				pRoomBackground->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
				this->addChild(pRoomBackground, SCENE_Z_ORDER_BG, roomBackground1Tag);
				TexaPoker::RoomM::Sprites::RoomBackground* pRoomBackground2 = TexaPoker::RoomM::Sprites::RoomBackground::create(ROOM_M_PATH_CONNECT(/room_bg.png), CCRectMake(0,0,CCDirector::sharedDirector()->getVisibleSize().width,CCDirector::sharedDirector()->getVisibleSize().height));
				pRoomBackground2->getTexture()->setTexParameters(&params);
				pRoomBackground2->setPosition(ccp(visibleSize.width/2 + origin.x, - visibleSize.height/2 + origin.y));
				this->addChild(pRoomBackground2, SCENE_Z_ORDER_BG, roomBackground2Tag);

				return true;
			}

			void RoomMScene::onEnter()
			{
				CCMenuItemImage *pRoomMGirlImage = CCMenuItemImage::create(
					ROOM_M_SPRITE_PATH_CONNECT(/img_pokerlady.png),
					ROOM_M_SPRITE_PATH_CONNECT(/img_pokerlady.png),
					this,
					NULL);
				CCActionInterval*  pRoomMGirlActionBy = CCMoveBy::create(ROOM_INIT_INTERVAL_TIME, ccp(25,0));
				TexaPoker::BaseGUI::BaseMoveButton* pRoomMGirlButton = TexaPoker::BaseGUI::BaseMoveButton::create(1, pRoomMGirlImage, pRoomMGirlActionBy);
				pRoomMGirlButton->setTouchEnabled(false);
				pRoomMGirlButton->setPosition(ccp(visibleSize.width/8 + origin.x, visibleSize.height/3 + origin.y));
				this->addChild(pRoomMGirlButton, SCENE_Z_ORDER_FRONT, roomMGirlButtonTag);
				pRoomMGirlButton->moveBy(pRoomMGirlButton);

				TexaPoker::BaseGUI::BaseArmatureButton* pFireButton = TexaPoker::BaseGUI::BaseArmatureButton::create(0.7f, "fire", 5, this, NULL);
				pFireButton->getAnimation()->setAnimationScale(0.5f);
				pFireButton->setAnchorPoint(ccp(0, 0));
				pFireButton->setPosition(ccp(visibleSize.width/50*43, visibleSize.height/10*9));
				this->addChild(pFireButton, SCENE_Z_ORDER_BUTTON, fireButtonTag);

				TexaPoker::BaseGUI::BaseArmatureButton* pHeartButton = TexaPoker::BaseGUI::BaseArmatureButton::create(0.7f, "heart", 5, this, event_selector(RoomMScene::heartCallback));
				pHeartButton->getAnimation()->setAnimationScale(0.5f);
				pHeartButton->setAnchorPoint(ccp(0, 0));
				pHeartButton->setPosition(ccp(visibleSize.width/50*46, visibleSize.height/10*9));
				this->addChild(pHeartButton, SCENE_Z_ORDER_BUTTON, heartButtonTag);

				this->scheduleOnce(schedule_selector(RoomMScene::initCards),ROOM_INIT_INTERVAL_TIME);

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
				CCDirector::sharedDirector()->getTouchDispatcher()->removeAllDelegates();
				CCDirector::sharedDirector()->replaceScene(pScene);
			}

			void RoomMScene::heartCallback(CCEvent* pEvent)
			{
				//pHeartButton->getAnimation()->playByIndex(0);
				if(roomStatus != ROOM_STATUS_CARD_FLOW){
					roomStatus = ROOM_STATUS_CARD_FLOW;
				}else{
					roomStatus = ROOM_STATUS_INIT;
				}
				/*
				pPoker->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
				this->addChild(pRoomBackground, SCENE_Z_ORDER_BG + 1);*/
				checkSpritesStatus();
			}

			void RoomMScene::checkSpritesStatus()
			{
				if(roomStatus == ROOM_STATUS_INIT){
					((TexaPoker::BaseGUI::BaseArmatureButton*)(this->getChildByTag(heartButtonTag)))->getAnimation()->stop();
					((TexaPoker::BaseGUI::BaseArmatureButton*)(this->getChildByTag(heartButtonTag)))->resetScale();
					this->unscheduleUpdate();
				}else if(roomStatus == ROOM_STATUS_CARD_FLOW){
					((TexaPoker::BaseGUI::BaseArmatureButton*)(this->getChildByTag(heartButtonTag)))->getAnimation()->playByIndex(0);
					this->scheduleUpdateWithPriority(0);
				}

			}

			void RoomMScene::update(float data)
			{
				((TexaPoker::RoomM::Sprites::RoomBackground*)(this->getChildByTag(roomBackground1Tag)))->moveOn();
				((TexaPoker::RoomM::Sprites::RoomBackground*)(this->getChildByTag(roomBackground2Tag)))->moveOn();
			}

			void RoomMScene::initCards(float data)
			{
				pRManager->initCards();
			}

			TexaPoker::RoomM::Controller::RollingOverManager* RoomMScene::getPRManager()
			{
				return pRManager;
			}
		}}}

