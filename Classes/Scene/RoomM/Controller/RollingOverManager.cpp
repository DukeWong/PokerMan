#include "RollingOverManager.h"
#include "..\Sprites\RoomCard.h"

USING_NS_CC;

namespace TexaPoker{
	namespace RoomM{
		namespace Controller{

			RollingOverManager::RollingOverManager()
			{
				cardsArray[0] = "card_back.png";
				cardsArray[36] = "card_10_c.png";
				cardsArray[49] = "card_10_d.png";
			}
			void RollingOverManager::initCards()
			{
				CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
				CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
				int tempTag = CARD_CLUBS_TAG(10);
				TexaPoker::RoomM::Sprites::RoomCard* pCard10c = TexaPoker::RoomM::Sprites::RoomCard::createWithSpriteFrame(this, CARD_STATE_BACK, 10, CARD_CLUBS, tempTag);
				pCard10c->setPosition(ccp(visibleSize.width/8 + origin.x, visibleSize.height/3 + origin.y));
				CCDirector::sharedDirector()->getRunningScene()->addChild(pCard10c, SCENE_Z_ORDER_FRONT, tempTag);
			}

			int RollingOverManager::getCardArrayCount(int num, int type)
			{
				return num + type * 13;
			}

			std::string * RollingOverManager::getCardArrays()
			{
				return this->cardsArray;
			}
		}
	}
}