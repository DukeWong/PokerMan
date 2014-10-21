#include "RoomCard.h"
#include "..\..\..\Common\Util\BaseUtil.h"

USING_NS_CC;

namespace TexaPoker{
	namespace RoomM{
		namespace Sprites{
			RoomCard* RoomCard::createWithSpriteFrame(TexaPoker::RoomM::Controller::RollingOverManager* manager, int state, int cardNum, int cardType, int tag)
			{
				const char * name = (*(manager->getCardArrays() + manager->getCardArrayCount(cardNum, cardType))).c_str();
				CCSpriteFrame *pSpriteFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(name);
				RoomCard *pobSprite = new RoomCard();
				pobSprite->tag = tag;
				pobSprite->num = cardNum;
				pobSprite->type = cardType;
				pobSprite->state = state;
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

			CCPoint RoomCard::genInitPosition()
			{
				float x = TexaPoker::BaseUtil::BaseUtil::genRand(CCDirector::sharedDirector()->getVisibleSize().width / 8, CCDirector::sharedDirector()->getVisibleSize().width / 3 * 2);
				return ccp(x,CCDirector::sharedDirector()->getVisibleSize().height / 10 * 9);
			}
		}}}
