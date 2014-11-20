#include "RoomCard.h"
#include "..\..\..\Common\Util\BaseUtil.h"
#include "..\..\..\Common\Action\BaseAction.h"

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

			void RoomCard::dealCard(CCPoint to, float intervalTime)
			{
				CCActionInterval*  actionTo = CCMoveTo::create(intervalTime, to);
				this->runAction(actionTo);
			}

			void RoomCard::dealCardShake(CCPoint to, float intervalTime)
			{
				CCActionInterval*  actionTo = CCMoveTo::create(intervalTime, to);
				TexaPoker::BaseAction::ShakeAction* shake = TexaPoker::BaseAction::ShakeAction::create(99999999999, 1, 1);  //repeat forver
				this->runAction(CCSequence::create(actionTo, shake, NULL));  
			}

			void RoomCard::turnOverBack()
			{
				this->stopAllActions();
				auto turnAction = CCOrbitCamera::create(0.5f, 0, 1, 270, 90, 0, 0);
				this->runAction(turnAction);
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
					turnOverBack();
				}	
				return true;
			}

			void RoomCard::ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)
			{

			}
		}}}
