#include "RollingOverManager.h"
#include "..\Sprites\RoomCard.h"

USING_NS_CC;

namespace TexaPoker{
	namespace RoomM{
		namespace Controller{

			RollingOverManager::RollingOverManager(CCLayer * c)
				:mScene(c)
			{
				initCardData();
			}

			void RollingOverManager::initCardData()
			{
				cardsArray[0] = CARDBACK;
				cardsArray[1] = CARDAC;
				cardsArray[2] = CARD2C;
				cardsArray[3] = CARD3C;
				cardsArray[4] = CARD4C;
				cardsArray[5] = CARD5C;
				cardsArray[6] = CARD6C;
				cardsArray[7] = CARD7C;
				cardsArray[8] = CARD8C;
				cardsArray[9] = CARD9C;
				cardsArray[10] = CARD10C;
				cardsArray[11] = CARDJC;
				cardsArray[12] = CARDQC;
				cardsArray[13] = CARDKC;
				cardsArray[14] = CARDAD;
				cardsArray[15] = CARD2D;
				cardsArray[16] = CARD3D;
				cardsArray[17] = CARD4D;
				cardsArray[18] = CARD5D;
				cardsArray[19] = CARD6D;
				cardsArray[20] = CARD7D;
				cardsArray[21] = CARD8D;
				cardsArray[22] = CARD9D;
				cardsArray[23] = CARD10D;
				cardsArray[24] = CARDJD;
				cardsArray[25] = CARDQD;
				cardsArray[26] = CARDKD;
				cardsArray[27] = CARDAH;
				cardsArray[28] = CARD2H;
				cardsArray[29] = CARD3H;
				cardsArray[30] = CARD4H;
				cardsArray[31] = CARD5H;
				cardsArray[32] = CARD6H;
				cardsArray[33] = CARD7H;
				cardsArray[34] = CARD8H;
				cardsArray[35] = CARD9H;
				cardsArray[36] = CARD10H;
				cardsArray[37] = CARDJH;
				cardsArray[38] = CARDQH;
				cardsArray[39] = CARDKH;
				cardsArray[40] = CARDAS;
				cardsArray[41] = CARD2S;
				cardsArray[42] = CARD3S;
				cardsArray[43] = CARD4S;
				cardsArray[44] = CARD5S;
				cardsArray[45] = CARD6S;
				cardsArray[46] = CARD7S;
				cardsArray[47] = CARD8S;
				cardsArray[48] = CARD9S;
				cardsArray[49] = CARD10S;
				cardsArray[50] = CARDJS;
				cardsArray[51] = CARDQS;
				cardsArray[52] = CARDKS;

				cardsPosition[0] = ccp(20, 20);
				cardsPosition[1] = ccp(50, 20);
				cardsPosition[2] = ccp(40, 20);

			}
			void RollingOverManager::initCards()
			{
				mScene->schedule(schedule_selector(RollingOverManager::addCards), 1.0f);  
				//CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
				//CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
				//int tempTag = CARD_CLUBS_TAG(10);
				//TexaPoker::RoomM::Sprites::RoomCard* pCard10c = TexaPoker::RoomM::Sprites::RoomCard::createWithSpriteFrame(this, CARD_STATE_BACK, 10, CARD_CLUBS, tempTag);
				//pCard10c->setPosition(pCard10c->genInitPosition());
				//CCDirector::sharedDirector()->getRunningScene()->addChild(pCard10c, SCENE_Z_ORDER_FRONT, tempTag);
				//pCard10c->dealCard(ccp(300, 100), 3);
				//
				//TexaPoker::RoomM::Sprites::RoomCard* pCard11c = TexaPoker::RoomM::Sprites::RoomCard::createWithSpriteFrame(this, CARD_STATE_BACK, 10, CARD_CLUBS, tempTag);
				//pCard11c->setPosition(pCard11c->genInitPosition());
				//CCDirector::sharedDirector()->getRunningScene()->addChild(pCard11c, SCENE_Z_ORDER_FRONT, 1987);
				//pCard11c->dealCard(ccp(300, 100), 3);
			}

			void RollingOverManager::addCards(float time)
			{
				CCLog("hello");
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