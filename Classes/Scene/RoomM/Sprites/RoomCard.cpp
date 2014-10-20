#include "RoomCard.h"

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
				CCActionInterval*  ActionBy = CCMoveBy::create(intervalTime, to);
			}

			CCPoint RoomCard::genInitPosition()
			{
				float X = CCDirector::sharedDirector()->getVisibleSize().width / 8 + std::rand() % ((int)CCDirector::sharedDirector()->getVisibleSize().width / 3 * 2);
				return ccp(X,CCDirector::sharedDirector()->getVisibleSize().height / 2);
			}
		}}}
