#include "RoomMScene.h"
#include "Constants.h"
#include "CocoStudio\Armature\utils\CCArmatureDataManager.h"
#include "CocoStudio\Armature\CCArmature.h"
#include "..\..\Common\External\B2DebugDraw\B2DebugDrawLayer.h"
#include "..\..\Scene\RoomM\Sprites\RoomCard.h"
#include "SimpleAudioEngine.h"
#include "Controller\RollingOverManager.h"

USING_NS_CC;

namespace TexaPoker{
	namespace RoomM{
		namespace Scene{
			RoomMScene::RoomMScene()
				:visibleSize(CCDirector::sharedDirector()->getVisibleSize())
				,origin(CCDirector::sharedDirector()->getVisibleOrigin())
				,roomStatus(ROOM_STATUS_INIT)
				,pRManager(new TexaPoker::RoomM::Controller::RollingOverManager(this))
				,endLineParticle(CCParticleSystemQuad::create(ROOM_M_PARTICEL_PATH_CONNECT(/endLine/endLine.plist)))
				,gravityOn(false)
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

				//cocos2d::extension::CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo(ROOM_M_SPRITE_PATH_CONNECT(/heart/heart.png), ROOM_M_SPRITE_PATH_CONNECT(/heart/heart.plist), ROOM_M_SPRITE_PATH_CONNECT(/heart/heart.xml));
				CCSpriteFrameCache* cache = CCSpriteFrameCache::sharedSpriteFrameCache();  
				cache->addSpriteFramesWithFile(ROOM_M_SPRITE_PATH_CONNECT(/cards/img_cards.plist), ROOM_M_SPRITE_PATH_CONNECT(/cards/img_cards.png));

				if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
				{
					CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect(AUDIO_PATH_CONNECT(/deal_card.ogg));
					CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect(AUDIO_PATH_CONNECT(/card_turn_over.ogg));
					CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect(AUDIO_PATH_CONNECT(/card_fade_out.ogg));
					CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect(AUDIO_PATH_CONNECT(/button_turn_over.ogg));
				}else{
					CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect(AUDIO_PATH_CONNECT(/deal_card.wav));
					CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect(AUDIO_PATH_CONNECT(/card_turn_over.wav));
					CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect(AUDIO_PATH_CONNECT(/card_fade_out.wav));
					CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect(AUDIO_PATH_CONNECT(/button_turn_over.wav));
				}
			}

			RoomMScene::~RoomMScene()
			{
				this->unscheduleAllSelectors();
				if(pWorld != NULL)
				{
					for(b2Body* b = pWorld->GetBodyList(); b; b = b->GetNext())  
					{  
						if(b != NULL){
							pWorld->DestroyBody(b);
						}
					} 
					delete pWorld;
					pWorld = NULL;
				} 				
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

				initPhysics();

				//开启debug Draw
				this->addChild(TexaPoker::External::B2DebugDraw::B2DebugDrawLayer::create(pWorld, 32), 9999);

				//开启update()
				this->scheduleUpdateWithPriority(0);

				return true;
			}

			void RoomMScene::initPhysics()
			{
				b2Vec2 gravity;
				gravity.Set(0.0f, -1.0f);
				pWorld = new b2World(gravity);
				pWorld->SetAllowSleeping(true);
				pWorld->SetContinuousPhysics(true);
				pWorld->SetContactListener(this);

				b2BodyDef bodyDef;
				b2PolygonShape polygonShape;
				b2FixtureDef fixtureDef;

				bodyDef.type = b2_staticBody;
				bodyDef.position.Set(800/PTM_RATIO, 50/PTM_RATIO);
				b2Body *bodyDown = pWorld->CreateBody(&bodyDef);
				polygonShape.SetAsBox(14, 0.01);
				fixtureDef.shape = &polygonShape;
				bodyDown->CreateFixture(&fixtureDef);

				bodyDef.type = b2_staticBody;
				bodyDef.position.Set(360/PTM_RATIO, 700/PTM_RATIO);
				b2Body *bodyLeft = pWorld->CreateBody(&bodyDef);
				polygonShape.SetAsBox(0.01, 20);
				fixtureDef.shape = &polygonShape;
				bodyLeft->CreateFixture(&fixtureDef);

				bodyDef.type = b2_staticBody;
				bodyDef.position.Set(1250/PTM_RATIO, 700/PTM_RATIO);
				b2Body *bodyRight = pWorld->CreateBody(&bodyDef);
				polygonShape.SetAsBox(0.01, 20);
				fixtureDef.shape = &polygonShape;
				bodyRight->CreateFixture(&fixtureDef);

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
				CCDirector::sharedDirector()->getRunningScene()->addChild(pRoomMGirlButton, SCENE_Z_ORDER_FRONT, roomMGirlButtonTag);
				pRoomMGirlButton->moveBy(pRoomMGirlButton);

				CCMenuItemImage *pFireImage = CCMenuItemImage::create(
					ROOM_M_SPRITE_PATH_CONNECT(/fire.png),
					ROOM_M_SPRITE_PATH_CONNECT(/fire.png),
					this,
					NULL);
				TexaPoker::BaseGUI::BaseButton* pFireButton = TexaPoker::BaseGUI::BaseButton::create(0.7f, pFireImage, this, event_selector(RoomMScene::fireCallback));
				pFireButton->setAnchorPoint(ccp(0, 0));
				pFireButton->setPosition(ccp(visibleSize.width/50*43, visibleSize.height/10*9.3));
				CCDirector::sharedDirector()->getRunningScene()->addChild(pFireButton, SCENE_Z_ORDER_BUTTON, fireButtonTag);
				CCActionInterval* fireTurnAction = CCOrbitCamera::create(0.25f, 0, 1, 270, 90, 0, 0);
				pFireButton->runAction(fireTurnAction);

				CCMenuItemImage *pHeartImage = CCMenuItemImage::create(
					ROOM_M_SPRITE_PATH_CONNECT(/heart.png),
					ROOM_M_SPRITE_PATH_CONNECT(/heart.png),
					this,
					NULL);
				TexaPoker::BaseGUI::BaseButton* pHeartButton = TexaPoker::BaseGUI::BaseButton::create(0.7f, pHeartImage, this, event_selector(RoomMScene::heartCallback));
				pHeartButton->setAnchorPoint(ccp(0, 0));
				pHeartButton->setPosition(ccp(visibleSize.width/50*46, visibleSize.height/10*9.3));
				CCDirector::sharedDirector()->getRunningScene()->addChild(pHeartButton, SCENE_Z_ORDER_BUTTON, heartButtonTag);
				CCActionInterval* heartTurnAction = CCOrbitCamera::create(0.25f, 0, 1, 270, 90, 0, 0);
				pHeartButton->runAction(heartTurnAction);

				if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
				{
					CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(AUDIO_PATH_CONNECT(/button_turn_over.ogg));
				}else{
					CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(AUDIO_PATH_CONNECT(/button_turn_over.wav));
				}

				this->scheduleOnce(schedule_selector(RoomMScene::initCards),ROOM_INIT_INTERVAL_TIME + 0.2);

				this->setKeypadEnabled(true);

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

			void RoomMScene::fireCallback(CCEvent* pEvent)
			{
				CCActionInterval* turnAction = CCOrbitCamera::create(0.25f, 0, 1, 270, 90, 0, 0);
				((TexaPoker::BaseGUI::BaseButton*)(CCDirector::sharedDirector()->getRunningScene()->getChildByTag(fireButtonTag)))->runAction(CCSequence::create(turnAction, CCFadeOut::create(0.2),
					CCCallFuncND::create(this,  callfuncND_selector(RoomMScene::removeSprite), (void *)&fireButtonTag), CCCallFunc::create(pRManager, callfunc_selector(TexaPoker::RoomM::Controller::RollingOverManager::turnOverAndFadeOutCards)), NULL));
				if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
				{
					CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(AUDIO_PATH_CONNECT(/button_turn_over.ogg));
				}else{
					CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(AUDIO_PATH_CONNECT(/button_turn_over.wav));
				}
				if(roomStatus != ROOM_STATUS_CARD_FLOAT)
				{
					roomStatus = ROOM_STATUS_CARD_FLOAT;
				}
				checkSpritesStatus();
			}

			void RoomMScene::heartCallback(CCEvent* pEvent)
			{
				//pHeartButton->getAnimation()->playByIndex(0);
				CCActionInterval* turnAction = CCOrbitCamera::create(0.25f, 0, 1, 270, 90, 0, 0);
				((TexaPoker::BaseGUI::BaseButton*)(CCDirector::sharedDirector()->getRunningScene()->getChildByTag(heartButtonTag)))->runAction(CCSequence::create(turnAction, CCFadeOut::create(0.2), CCCallFuncND::create(this,  callfuncND_selector(RoomMScene::removeSprite), (void *)&heartButtonTag), NULL));
				if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
				{
					CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(AUDIO_PATH_CONNECT(/button_turn_over.ogg));
				}else{
					CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(AUDIO_PATH_CONNECT(/button_turn_over.wav));
				}
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
					//	((TexaPoker::BaseGUI::BaseArmatureButton*)(this->getChildByTag(heartButtonTag)))->getAnimation()->stop();
					//	((TexaPoker::BaseGUI::BaseArmatureButton*)(this->getChildByTag(heartButtonTag)))->resetScale();
					gravityOn = false;
				}else if(roomStatus == ROOM_STATUS_CARD_FLOW){
					pWorld->GetGravity().Set(0.0f, -1.0f);
					//	((TexaPoker::BaseGUI::BaseArmatureButton*)(this->getChildByTag(heartButtonTag)))->getAnimation()->playByIndex(0);
					//pRManager->stopAllCardsActions();
					this->unschedule(schedule_selector(TexaPoker::RoomM::Controller::RollingOverManager::addCards));
					gravityOn = true;
					//this->unscheduleAllSelectors();
					//this->scheduleUpdateWithPriority(0);
				}else if(roomStatus == ROOM_STATUS_CARD_FLOAT){
					gravityOn = false;
					pWorld->GetGravity().Set(0.0f, -10.0f);
					//pRManager->stopAllCardsActions();
					this->unschedule(schedule_selector(TexaPoker::RoomM::Controller::RollingOverManager::addCards));
					//pRManager->turnOverAndFadeOutCards();
				}

			}

			void RoomMScene::update(float data)
			{
				//	((TexaPoker::RoomM::Sprites::RoomBackground*)(this->getChildByTag(roomBackground1Tag)))->moveOn();
				//	((TexaPoker::RoomM::Sprites::RoomBackground*)(this->getChildByTag(roomBackground2Tag)))->moveOn();
				if(gravityOn == true)
				{
					pWorld->Step(data, VELOCITY_ITERATIONS, POSITION_ITERATIONS); 

					if(pWorld != NULL)
					{
						for(b2Body* b = pWorld->GetBodyList(); b; b = b->GetNext())  
						{  
							if(b!= NULL && b->GetUserData() != NULL)  
							{  
								CCSprite* sprite = (CCSprite*)b->GetUserData();  
								//CCLOG("x%f,y%f", b->GetPosition().x, b->GetPosition().y);
								sprite->setPosition(ccp(b->GetPosition().x * PTM_RATIO, b->GetPosition().y * PTM_RATIO)); 
								sprite->setRotation(-1 * CC_RADIANS_TO_DEGREES(b->GetAngle()));
							}  
						} 
					} 
				}
			}

			void RoomMScene::initCards(float data)
			{
				pRManager->initCards();
			}

			TexaPoker::RoomM::Controller::RollingOverManager* RoomMScene::getPRManager()
			{
				return pRManager;
			}

			b2World* RoomMScene::getWorld()
			{
				return pWorld;
			}

			b2Body* RoomMScene::getGroundBody()
			{
				return m_groundBody;
			}

			void RoomMScene::setGroundBody(b2Body* b)
			{
				m_groundBody = b;
			}

			CCParticleSystemQuad* RoomMScene::getEndLine()
			{
				return endLineParticle;
			}

			void RoomMScene::keyBackClicked()
			{
				menuBackCallback(NULL);
			}

			void RoomMScene::BeginContact(b2Contact* contact)
			{
				b2Body *bodyA = contact->GetFixtureA()->GetBody();
				b2Body *bodyB = contact->GetFixtureB()->GetBody();

				TexaPoker::RoomM::Sprites::RoomCard *spriteA = reinterpret_cast<TexaPoker::RoomM::Sprites::RoomCard *>(bodyA->GetUserData());
				TexaPoker::RoomM::Sprites::RoomCard *spriteB = reinterpret_cast<TexaPoker::RoomM::Sprites::RoomCard *>(bodyB->GetUserData());

				if(spriteA != NULL && spriteB != NULL)
				{
					TexaPoker::RoomM::Sprites::RoomCard* sprite = spriteA->getNum() >= spriteB->getNum() ? spriteB : spriteA;
					b2Body* body = spriteA->getNum() >= spriteB->getNum() ? bodyB : bodyA;
					if(sprite->getState()== CARD_STATE_FRONT)
					{
						sprite->setState(CARD_STATE_DELETE);
						CCFiniteTimeAction* pFadeOut = CCSequence::create(CCFadeOut::create(2), CCCallFuncND::create(sprite,  callfuncND_selector(RoomMScene::finishFadeOutAction), (void *)body), NULL);
						sprite->runAction(pFadeOut);

						if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
						{
							CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(AUDIO_PATH_CONNECT(/card_fade_out.ogg));
						}else{
							CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(AUDIO_PATH_CONNECT(/card_fade_out.wav));
						}
					}
				}


			}

			void RoomMScene::finishFadeOutAction(CCNode* pSender, void * data)
			{
				TexaPoker::RoomM::Sprites::RoomCard *sprite = dynamic_cast<TexaPoker::RoomM::Sprites::RoomCard *>(pSender);

				std::vector <int> TagArray = sprite->getManager()->getCardsTagArray();
				std::vector <int>::iterator it = TagArray.begin();
				CCLOG("%d sizebefore", TagArray.size());
				for(; it!=TagArray.end(); ++it){
					if(*it == sprite->getTag())
					{
						it=TagArray.erase(it);
					}						
				}
				sprite->getManager()->setCardsTagArray(TagArray);

				b2Body *body = reinterpret_cast<b2Body *>(data);
				if(sprite != NULL)
				{
					CCDirector::sharedDirector()->getRunningScene()->removeChildByTag(sprite->getTag());
				}
				if(body != NULL)
				{
					body->GetWorld()->DestroyBody(body);
				}
			}

			void RoomMScene::removeSprite(CCNode* pSender, void * data)
			{
				int * tag = reinterpret_cast<int *>(data);
				CCDirector::sharedDirector()->getRunningScene()->removeChildByTag(*tag);
			}

			void RoomMScene::PreSolve(b2Contact* contact, const b2Manifold* oldManifold)
			{

			}

			int RoomMScene::getRoomStatus()
			{
				return roomStatus;
			}

		}}}
