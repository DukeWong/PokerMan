#include "RoomCard.h"
#include "..\..\..\Common\Util\BaseUtil.h"
#include "..\..\..\Common\Action\BaseAction.h"
#include "..\RoomMScene.h"

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

			void RoomCard::bindPhysicalBody(CCPoint to)
			{
				b2BodyDef bodyDef;
				bodyDef.type = b2_dynamicBody;
				//bodyDef.bullet = true;
				bodyDef.position.Set(to.x/PTM_RATIO, to.y/PTM_RATIO);

				body = ((TexaPoker::RoomM::Scene::RoomMScene*)pManager->getMScence())->getWorld()->CreateBody(&bodyDef);
				body->SetSleepingAllowed(true);
				body->SetLinearDamping(LINEAER_DAMP);
				body->SetAngularDamping(ANGULAR_DAMP);;

				b2PolygonShape polygonShape;
				b2FixtureDef fixtureDef;
				polygonShape.SetAsBox(0.9, 1.2);

				fixtureDef.shape = &polygonShape;
				fixtureDef.density = num;
				fixtureDef.restitution = 0.8f;

				body->CreateFixture(&fixtureDef);
				body->SetUserData(this);
			}

			void RoomCard::dealCard(CCPoint to, float intervalTime)
			{
				CCActionInterval*  actionTo = CCMoveTo::create(intervalTime, to);
				this->runAction(actionTo);
			}

			void RoomCard::dealCardShake(CCPoint to, float intervalTime)
			{
				this->bindPhysicalBody(to);
				CCActionInterval*  actionTo = CCMoveTo::create(intervalTime, to);
				TexaPoker::BaseAction::ShakeAction* shake = TexaPoker::BaseAction::ShakeAction::create(99999999999, 1, 1);  //repeat forver
				this->runAction(CCSequence::create(actionTo, shake, NULL));  
			}

			void RoomCard::turnOverBack()
			{
				this->stopAllActions();
				CCActionInterval* turnAction = CCOrbitCamera::create(0.5f, 0, 1, 270, 90, 0, 0);
				this->runAction(CCSequence::create(turnAction, CCCallFunc::create(this, callfunc_selector(RoomCard::turnOverBackFinished)), NULL));
				this->state = CARD_STATE_FRONT;
			}

			void RoomCard::turnOverBackFinished()
			{
				CCSpriteFrame *pSpriteFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(name);
				this->setDisplayFrame(pSpriteFrame);
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
					if(state == CARD_STATE_BACK)
					{
						turnOverBack();
					}else{
						b2MouseJointDef md;
						md.bodyA = ((TexaPoker::RoomM::Scene::RoomMScene*)(pManager->getMScence()))->getGroundBody();
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
				}
			}

			void RoomCard::ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)
			{
				CCPoint touchLocation= touch->getLocation();
				CCRect r = this->rect();
				if(r.containsPoint(touchLocation)){	
					CCParticleSystemQuad *exploding_ring = CCParticleSystemQuad::create(ROOM_PARTICEL_PATH_CONNECT(/exploding_ring/exploding_ring.plist)); 
					exploding_ring->setBlendAdditive(true);//ÊÇ·ñ»ìºÏ 
					exploding_ring->setPosition(ccp(touchLocation.x/PTM_RATIO, touchLocation.y/PTM_RATIO));
					exploding_ring->setAutoRemoveOnFinish(true);
					addChild(exploding_ring, SCENE_Z_ORDER_FRONT);
					}
					if (pMouseJoint)
					{
						pMouseJoint->SetTarget(b2Vec2(touchLocation.x/PTM_RATIO, touchLocation.y/PTM_RATIO));
					}	
			}

		}}}
