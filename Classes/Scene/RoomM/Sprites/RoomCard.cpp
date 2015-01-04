#include "RoomCard.h"
#include "..\..\..\Common\Util\BaseUtil.h"
#include "..\..\..\Common\Action\BaseAction.h"
#include "..\RoomMScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

namespace TexaPoker{
	namespace RoomM{
		namespace Sprites{
			RoomCard* RoomCard::createWithSpriteFrame(TexaPoker::RoomM::Controller::RollingOverManager* manager, int state, int cardNum, int cardType, int tag)
			{
				RoomCard *pobSprite = new RoomCard();
				pobSprite->tag = tag;
				pobSprite->num = cardNum;
				pobSprite->type = cardType;
				pobSprite->state = state;
				pobSprite->body = NULL;
				pobSprite->pMouseJoint = NULL;
				CC_SAFE_RETAIN(manager);
				pobSprite->name = (*(manager->getCardArrays() + manager->getCardArrayCount(cardNum, cardType))).c_str();
				pobSprite->pManager = manager;
				if(state == CARD_STATE_BACK)
				{
					cardNum = 0;
					cardType = 0;
				}
				const char * name = (*(manager->getCardArrays() + manager->getCardArrayCount(cardNum, cardType))).c_str();
				CCSpriteFrame *pSpriteFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(name);

				if (pSpriteFrame && pobSprite && pobSprite->initWithSpriteFrame(pSpriteFrame))
				{
					pobSprite->autorelease();
					return pobSprite;
				}
				CC_SAFE_DELETE(pobSprite);
				return NULL;
			}

			RoomCard::~RoomCard()
			{
				CC_SAFE_RELEASE(pManager);
			}

			void RoomCard::bindPhysicalBody(CCPoint to, float LinearDamp, float angrularDamp)
			{
				b2BodyDef bodyDef;
				bodyDef.type = b2_dynamicBody;
				//bodyDef.bullet = true;
				bodyDef.position.Set(to.x/PTM_RATIO, to.y/PTM_RATIO);

				body = ((TexaPoker::RoomM::Scene::RoomMScene*)pManager->getMScence())->getWorld()->CreateBody(&bodyDef);
				body->SetSleepingAllowed(true);
				body->SetLinearDamping(LinearDamp);
				body->SetAngularDamping(angrularDamp);;

				b2PolygonShape polygonShape;
				b2FixtureDef fixtureDef;
				polygonShape.SetAsBox(0.9, 1.2);

				fixtureDef.shape = &polygonShape;
				fixtureDef.density = num;
				fixtureDef.restitution = 0.8f;

				body->CreateFixture(&fixtureDef);
				body->SetUserData(this);
			}

			int RoomCard::getNum()
			{
				return num;
			}

			int RoomCard::getState()
			{
				return state;
			}

			void RoomCard::setState(int mState)
			{
				state = mState;
			}

			TexaPoker::RoomM::Controller::RollingOverManager* RoomCard::getManager()
			{
				return pManager;
			}

			void RoomCard::dealCard(CCPoint to, float intervalTime)
			{
				if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
				{
					CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(AUDIO_PATH_CONNECT(/deal_card.ogg));
				}else{
					CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(AUDIO_PATH_CONNECT(/deal_card.wav));
				}

				CCActionInterval*  actionTo = CCMoveTo::create(intervalTime, to);
				this->runAction(actionTo);
			}

			void RoomCard::dealCardShake(CCPoint to, float intervalTime)
			{
				if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
				{
					CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(AUDIO_PATH_CONNECT(/deal_card.ogg));
				}else{
					CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(AUDIO_PATH_CONNECT(/deal_card.wav));
				}
				this->bindPhysicalBody(to, LINEAER_DAMP, ANGULAR_DAMP);
				CCActionInterval*  actionTo = CCMoveTo::create(intervalTime, to);
				TexaPoker::BaseAction::ShakeAction* shake = TexaPoker::BaseAction::ShakeAction::create(99999999999, 1, 1);  //repeat forver
				this->runAction(CCSequence::create(actionTo, shake, NULL));  
			}

			void RoomCard::turnOverBack()
			{
				this->stopAllActions();
				CCActionInterval* turnAction = CCOrbitCamera::create(0.25f, 0, 1, 270, 90, 0, 0);
				this->runAction(CCSequence::create(turnAction, CCCallFunc::create(this, callfunc_selector(RoomCard::turnOverBackFinished)), NULL));
				this->state = CARD_STATE_FRONT;
				if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
				{
					CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(AUDIO_PATH_CONNECT(/card_turn_over.ogg));
				}else{
					CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(AUDIO_PATH_CONNECT(/card_turn_over.wav));
				}
			}

			void RoomCard::turnOverBackFinished()
			{
				CCSpriteFrame *pSpriteFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(name);
				this->setDisplayFrame(pSpriteFrame);
			}

			void RoomCard::turnOverBackAndFadeOut()
			{
				if(this->state != CARD_STATE_FRONT)
				{
					this->stopAllActions();
					CCActionInterval* turnAction = CCOrbitCamera::create(0.25f, 0, 1, 270, 90, 0, 0);
					this->runAction(CCSequence::create(turnAction, CCCallFunc::create(this, callfunc_selector(RoomCard::turnOverBackFinished)), CCFadeOut::create(1.5), CCCallFunc::create(this, callfunc_selector(RoomCard::DestoryBody)), CCCallFunc::create(this, callfunc_selector(RoomCard::turnOverBackAndFadeOutFinished)), NULL));
					this->state = CARD_STATE_FRONT;
					if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
					{
						CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(AUDIO_PATH_CONNECT(/card_turn_over.ogg));
					}else{
						CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(AUDIO_PATH_CONNECT(/card_turn_over.wav));
					}
				}else{
					this->stopAllActions();
					this->runAction(CCSequence::create(CCFadeOut::create(1.5), CCCallFunc::create(this, callfunc_selector(RoomCard::DestoryBody)), CCCallFunc::create(this, callfunc_selector(RoomCard::turnOverBackAndFadeOutFinished)), NULL));
				}			
			}

			void RoomCard::turnOverBackAndFadeOutFinished()
			{
				pManager->turnOverAndFadeOutCardsFinished();
			}

			void RoomCard::DestoryBody()
			{
				if(body != NULL)
				{
					body->GetWorld()->DestroyBody(body);
				}
				CCDirector::sharedDirector()->getRunningScene()->removeChildByTag(this->getTag());
			}

			CCPoint RoomCard::genInitPosition()
			{
				//float x = TexaPoker::BaseUtil::Num::genRand(CCDirector::sharedDirector()->getVisibleSize().width / 8, CCDirector::sharedDirector()->getVisibleSize().width / 3 * 2);
				return ccp(CCDirector::sharedDirector()->getVisibleSize().width / 10, CCDirector::sharedDirector()->getVisibleSize().height / 10 * 9);
			}

			CCRect RoomCard::rect()
			{
				return CCRectMake( m_obPosition.x - m_obContentSize.width * m_obAnchorPoint.x,
					m_obPosition.y - m_obContentSize.height * m_obAnchorPoint.y,
					m_obContentSize.width, m_obContentSize.height);
			}

			bool RoomCard::ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)
			{
				CCPoint touchLocation= touch->getLocation();
				CCRect r = this->rect();
				if(r.containsPoint(touchLocation)){
					CCLOG("touch%d", body->GetPosition().y  * PTM_RATIO);
					if(state == CARD_STATE_BACK)
					{
						if(((TexaPoker::RoomM::Scene::RoomMScene*)(pManager->getMScence()))->getRoomStatus() == ROOM_STATUS_CARD_FLOAT){
							if(abs(body->GetPosition().y  * PTM_RATIO - 100) < 100)
							{
								turnOverBackAndFadeOut();
							}
						}else{
							turnOverBack();
						}			
					}else if(state == CARD_STATE_FRONT && ((TexaPoker::RoomM::Scene::RoomMScene*)(pManager->getMScence()))->getRoomStatus() == ROOM_STATUS_CARD_FLOW){
						b2MouseJointDef md;
						b2BodyDef bodyGroundDef;
						b2Body* m_groundBody = body->GetWorld()->CreateBody(&bodyGroundDef);
						((TexaPoker::RoomM::Scene::RoomMScene*)(pManager->getMScence()))->setGroundBody(m_groundBody);
						md.bodyA = m_groundBody;
						md.bodyB = body;
						md.target = b2Vec2(touchLocation.x/PTM_RATIO, touchLocation.y/PTM_RATIO);
						md.maxForce = 1000.0f * body->GetMass();
						pMouseJoint = (b2MouseJoint*)body->GetWorld()->CreateJoint(&md);
					}
				}	
				return true;
			}

			void RoomCard::ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)
			{
				if (pMouseJoint)
				{
					body->GetWorld()->DestroyJoint(pMouseJoint);
					pMouseJoint = NULL;
					body->GetWorld()->DestroyBody(((TexaPoker::RoomM::Scene::RoomMScene*)(pManager->getMScence()))->getGroundBody());
					((TexaPoker::RoomM::Scene::RoomMScene*)(pManager->getMScence()))->setGroundBody(NULL);
				}
			}

			void RoomCard::ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)
			{
				CCPoint touchLocation= touch->getLocation();
				CCRect r = this->rect();
				if(r.containsPoint(touchLocation)){						
					if (pMouseJoint)
					{
						pMouseJoint->SetTarget(b2Vec2(touchLocation.x/PTM_RATIO, touchLocation.y/PTM_RATIO));
					}
				}
			}

		}}}
