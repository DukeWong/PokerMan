#include "RollingOverManager.h"
#include "..\Sprites\RoomCard.h"
#include "..\..\..\Common\Util\BaseUtil.h"
#include "..\RoomMScene.h"

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
				cardsArray[1] = CARD1C;
				cardsArray[2] = CARD2C;
				cardsArray[3] = CARD3C;
				cardsArray[4] = CARD4C;
				cardsArray[5] = CARD5C;
				cardsArray[6] = CARD6C;
				cardsArray[7] = CARD7C;
				cardsArray[8] = CARD8C;
				cardsArray[9] = CARD9C;
				cardsArray[10] = CARD10C;
				cardsArray[11] = CARD11C;
				cardsArray[12] = CARD12C;
				cardsArray[13] = CARD13C;
				cardsArray[14] = CARD1D;
				cardsArray[15] = CARD2D;
				cardsArray[16] = CARD3D;
				cardsArray[17] = CARD4D;
				cardsArray[18] = CARD5D;
				cardsArray[19] = CARD6D;
				cardsArray[20] = CARD7D;
				cardsArray[21] = CARD8D;
				cardsArray[22] = CARD9D;
				cardsArray[23] = CARD10D;
				cardsArray[24] = CARD11D;
				cardsArray[25] = CARD12D;
				cardsArray[26] = CARD13D;
				cardsArray[27] = CARD1H;
				cardsArray[28] = CARD2H;
				cardsArray[29] = CARD3H;
				cardsArray[30] = CARD4H;
				cardsArray[31] = CARD5H;
				cardsArray[32] = CARD6H;
				cardsArray[33] = CARD7H;
				cardsArray[34] = CARD8H;
				cardsArray[35] = CARD9H;
				cardsArray[36] = CARD10H;
				cardsArray[37] = CARD11H;
				cardsArray[38] = CARD12H;
				cardsArray[39] = CARD13H;
				cardsArray[40] = CARD1S;
				cardsArray[41] = CARD2S;
				cardsArray[42] = CARD3S;
				cardsArray[43] = CARD4S;
				cardsArray[44] = CARD5S;
				cardsArray[45] = CARD6S;
				cardsArray[46] = CARD7S;
				cardsArray[47] = CARD8S;
				cardsArray[48] = CARD9S;
				cardsArray[49] = CARD10S;
				cardsArray[50] = CARD11S;
				cardsArray[51] = CARD12S;
				cardsArray[52] = CARD13S;

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

			int RollingOverManager::getCardTag(int type, int num)
			{
				int tag = 0;
				if(0 == type){
					switch (num)
					{
					case 1:
						tag = CARD_CLUBS_TAG(1);
						break;
					case 2:
						tag = CARD_CLUBS_TAG(2);
						break;
					case 3:
						tag = CARD_CLUBS_TAG(3);
						break;
					case 4:
						tag = CARD_CLUBS_TAG(4);
						break;
					case 5:
						tag = CARD_CLUBS_TAG(5);
						break;
					case 6:
						tag = CARD_CLUBS_TAG(6);
						break;
					case 7:
						tag = CARD_CLUBS_TAG(7);
						break;
					case 8:
						tag = CARD_CLUBS_TAG(8);
						break;
					case 9:
						tag = CARD_CLUBS_TAG(9);
						break;
					case 10:
						tag = CARD_CLUBS_TAG(10);
						break;
					case 11:
						tag = CARD_CLUBS_TAG(11);
						break;
					case 12:
						tag = CARD_CLUBS_TAG(12);
						break;
					case 13:
						tag = CARD_CLUBS_TAG(13);
						break;
					default:
						break;
					}

				}else if(1 == type){
					switch (num)
					{
					case 1:
						tag = CARD_CLUBS_TAG(1);
						break;
					case 2:
						tag = CARD_CLUBS_TAG(2);
						break;
					case 3:
						tag = CARD_CLUBS_TAG(3);
						break;
					case 4:
						tag = CARD_CLUBS_TAG(4);
						break;
					case 5:
						tag = CARD_CLUBS_TAG(5);
						break;
					case 6:
						tag = CARD_CLUBS_TAG(6);
						break;
					case 7:
						tag = CARD_CLUBS_TAG(7);
						break;
					case 8:
						tag = CARD_CLUBS_TAG(8);
						break;
					case 9:
						tag = CARD_CLUBS_TAG(9);
						break;
					case 10:
						tag = CARD_CLUBS_TAG(10);
						break;
					case 11:
						tag = CARD_CLUBS_TAG(11);
						break;
					case 12:
						tag = CARD_CLUBS_TAG(12);
						break;
					case 13:
						tag = CARD_CLUBS_TAG(13);
						break;
					default:
						break;
					}
				}else if(2 == type){
					switch (num)
					{
					case 1:
						tag = CARD_CLUBS_TAG(1);
						break;
					case 2:
						tag = CARD_CLUBS_TAG(2);
						break;
					case 3:
						tag = CARD_CLUBS_TAG(3);
						break;
					case 4:
						tag = CARD_CLUBS_TAG(4);
						break;
					case 5:
						tag = CARD_CLUBS_TAG(5);
						break;
					case 6:
						tag = CARD_CLUBS_TAG(6);
						break;
					case 7:
						tag = CARD_CLUBS_TAG(7);
						break;
					case 8:
						tag = CARD_CLUBS_TAG(8);
						break;
					case 9:
						tag = CARD_CLUBS_TAG(9);
						break;
					case 10:
						tag = CARD_CLUBS_TAG(10);
						break;
					case 11:
						tag = CARD_CLUBS_TAG(11);
						break;
					case 12:
						tag = CARD_CLUBS_TAG(12);
						break;
					case 13:
						tag = CARD_CLUBS_TAG(13);
						break;
					default:
						break;
					}
				}else if(3 == type){
					switch (num)
					{
					case 1:
						tag = CARD_CLUBS_TAG(1);
						break;
					case 2:
						tag = CARD_CLUBS_TAG(2);
						break;
					case 3:
						tag = CARD_CLUBS_TAG(3);
						break;
					case 4:
						tag = CARD_CLUBS_TAG(4);
						break;
					case 5:
						tag = CARD_CLUBS_TAG(5);
						break;
					case 6:
						tag = CARD_CLUBS_TAG(6);
						break;
					case 7:
						tag = CARD_CLUBS_TAG(7);
						break;
					case 8:
						tag = CARD_CLUBS_TAG(8);
						break;
					case 9:
						tag = CARD_CLUBS_TAG(9);
						break;
					case 10:
						tag = CARD_CLUBS_TAG(10);
						break;
					case 11:
						tag = CARD_CLUBS_TAG(11);
						break;
					case 12:
						tag = CARD_CLUBS_TAG(12);
						break;
					case 13:
						tag = CARD_CLUBS_TAG(13);
						break;
					default:
						break;
					}
				}
				return tag;

			}
			void RollingOverManager::addCards(float time)
			{
				CCLog("hello");
				int type = CARD_TYPE(TexaPoker::BaseUtil::Num::genRand(0, 4));
				int num = CARD_TYPE(TexaPoker::BaseUtil::Num::genRand(1, 13));
				int tempTag = getCardTag(type, num);
				TexaPoker::RoomM::Sprites::RoomCard* pcard = TexaPoker::RoomM::Sprites::RoomCard::createWithSpriteFrame( ((TexaPoker::RoomM::Scene::RoomMScene*)this)->getPRManager() , CARD_STATE_BACK, num, type, tempTag);
				pcard->setPosition(pcard->genInitPosition());
				CCDirector::sharedDirector()->getRunningScene()->addChild(pcard, SCENE_Z_ORDER_FRONT);
				pcard->dealCard(ccp(300, 100), 3);

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