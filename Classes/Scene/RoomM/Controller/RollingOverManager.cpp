#include "RollingOverManager.h"
#include "..\Sprites\RoomCard.h"
#include "..\..\..\Common\Util\BaseUtil.h"
#include "..\RoomMScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

namespace TexaPoker{
	namespace RoomM{
		namespace Controller{

			RollingOverManager::RollingOverManager(CCLayer * c)
				:mScene(c)
				,cardPositionSize(0)
				,currentCardPosition(0)
				,flowPositionSize(0)
				,currentFlowPosition(0)
				,currentFlowTurnOverCountPosition(0)
			{
				CC_SAFE_RETAIN(c);
				initCardData();
			}

			RollingOverManager::~RollingOverManager()
			{
				CC_SAFE_RELEASE(mScene);
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

				cardsPosition[0] = ccp(440, 100);
				cardsPosition[1] = ccp(530, 100);
				cardsPosition[2] = ccp(620, 100);
				cardsPosition[3] = ccp(710, 100);
				cardsPosition[4] = ccp(800, 100);
				cardsPosition[5] = ccp(890, 100);
				cardsPosition[6] = ccp(980, 100);
				cardsPosition[7] = ccp(1070, 100);
				cardsPosition[8] = ccp(1160, 100);
				cardsPosition[9] = ccp(440, 211);
				cardsPosition[10] = ccp(530, 211);
				cardsPosition[11] = ccp(620, 211);
				cardsPosition[12] = ccp(710, 211);
				cardsPosition[13] = ccp(800, 211);
				cardsPosition[14] = ccp(890, 211);
				cardsPosition[15] = ccp(980, 211);
				cardsPosition[16] = ccp(1070, 211);
				cardsPosition[17] = ccp(1160, 211);
				cardsPosition[18] = ccp(440, 322);
				cardsPosition[19] = ccp(530, 322);
				cardsPosition[20] = ccp(620, 322);
				cardsPosition[21] = ccp(710, 322);
				cardsPosition[22] = ccp(800, 322);
				cardsPosition[23] = ccp(890, 322);
				cardsPosition[24] = ccp(980, 322);
				cardsPosition[25] = ccp(1070, 322);
				cardsPosition[26] = ccp(1160, 322);
				cardsPosition[27] = ccp(440, 433);
				cardsPosition[28] = ccp(530, 433);
				cardsPosition[29] = ccp(620, 433);
				cardsPosition[30] = ccp(710, 433);
				cardsPosition[31] = ccp(800, 433);
				cardsPosition[32] = ccp(890, 433);
				cardsPosition[33] = ccp(980, 433);
				cardsPosition[34] = ccp(1070, 433);
				cardsPosition[35] = ccp(1160, 433);
				cardsPosition[36] = ccp(440, 544);
				cardsPosition[37] = ccp(530, 544);
				cardsPosition[38] = ccp(620, 544);
				cardsPosition[39] = ccp(710, 544);
				cardsPosition[40] = ccp(800, 544);
				cardsPosition[41] = ccp(890, 544);
				cardsPosition[42] = ccp(980, 544);
				cardsPosition[43] = ccp(1070, 544);
				cardsPosition[44] = ccp(1160, 544);

				cardPositionSize = sizeof(cardsPosition)/sizeof(cardsPosition[0]);

				flowPosition[0] = ccp(630, 650);
				flowPosition[1] = ccp(830, 650);
				flowPosition[2] = ccp(1032, 650);
				flowPosition[3] = ccp(432, 650);
				flowPosition[4] = ccp(877, 650);
				flowPosition[5] = ccp(1060, 650);
				flowPosition[6] = ccp(510, 650);
				flowPosition[7] = ccp(830, 650);

				flowPositionSize = sizeof(flowPosition)/sizeof(flowPosition[0]);

			}
			void RollingOverManager::initCards()
			{
				if(cardsTagArray.size() > 0){
					cardsTagArray.clear();
				}
				mScene->schedule(schedule_selector(RollingOverManager::addCards), 0.15f);  
			}

			void RollingOverManager::initFlowCards()
			{
				CCParticleSystemQuad* endLineParticle = ((TexaPoker::RoomM::Scene::RoomMScene*)mScene)->getEndLine();
				endLineParticle->setBlendAdditive(true);//是否混合 
				endLineParticle->setPosition(ccp( 800, 125));
				CCDirector::sharedDirector()->getRunningScene()->addChild(endLineParticle, SCENE_Z_ORDER_BG + 1);
				b2Body* mBody = ((TexaPoker::RoomM::Scene::RoomMScene*)mScene)->getWorld()->GetBodyList();
				int count = ((TexaPoker::RoomM::Scene::RoomMScene*)mScene)->getWorld()->GetBodyCount();
				while(mBody){
					b2Body* mBodyNext = mBody->GetNext();
					((TexaPoker::RoomM::Scene::RoomMScene*)mScene)->getWorld()->DestroyBody(mBody);
					mBody = mBodyNext;
				}
				CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic(AUDIO_PATH_CONNECT(/card_flow_bg.mp3));
				mScene->schedule(schedule_selector(RollingOverManager::flowCards), 1.2f);  
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
						tag = CARD_DIAMONDS_TAG(1);
						break;
					case 2:
						tag = CARD_DIAMONDS_TAG(2);
						break;
					case 3:
						tag = CARD_DIAMONDS_TAG(3);
						break;
					case 4:
						tag = CARD_DIAMONDS_TAG(4);
						break;
					case 5:
						tag = CARD_DIAMONDS_TAG(5);
						break;
					case 6:
						tag = CARD_DIAMONDS_TAG(6);
						break;
					case 7:
						tag = CARD_DIAMONDS_TAG(7);
						break;
					case 8:
						tag = CARD_DIAMONDS_TAG(8);
						break;
					case 9:
						tag = CARD_DIAMONDS_TAG(9);
						break;
					case 10:
						tag = CARD_DIAMONDS_TAG(10);
						break;
					case 11:
						tag = CARD_DIAMONDS_TAG(11);
						break;
					case 12:
						tag = CARD_DIAMONDS_TAG(12);
						break;
					case 13:
						tag = CARD_DIAMONDS_TAG(13);
						break;
					default:
						break;
					}
				}else if(2 == type){
					switch (num)
					{
					case 1:
						tag = CARD_HEARTS_TAG(1);
						break;
					case 2:
						tag = CARD_HEARTS_TAG(2);
						break;
					case 3:
						tag = CARD_HEARTS_TAG(3);
						break;
					case 4:
						tag = CARD_HEARTS_TAG(4);
						break;
					case 5:
						tag = CARD_HEARTS_TAG(5);
						break;
					case 6:
						tag = CARD_HEARTS_TAG(6);
						break;
					case 7:
						tag = CARD_HEARTS_TAG(7);
						break;
					case 8:
						tag = CARD_HEARTS_TAG(8);
						break;
					case 9:
						tag = CARD_HEARTS_TAG(9);
						break;
					case 10:
						tag = CARD_HEARTS_TAG(10);
						break;
					case 11:
						tag = CARD_HEARTS_TAG(11);
						break;
					case 12:
						tag = CARD_HEARTS_TAG(12);
						break;
					case 13:
						tag = CARD_HEARTS_TAG(13);
						break;
					default:
						break;
					}
				}else if(3 == type){
					switch (num)
					{
					case 1:
						tag = CARD_SPADE_TAG(1);
						break;
					case 2:
						tag = CARD_SPADE_TAG(2);
						break;
					case 3:
						tag = CARD_SPADE_TAG(3);
						break;
					case 4:
						tag = CARD_SPADE_TAG(4);
						break;
					case 5:
						tag = CARD_SPADE_TAG(5);
						break;
					case 6:
						tag = CARD_SPADE_TAG(6);
						break;
					case 7:
						tag = CARD_SPADE_TAG(7);
						break;
					case 8:
						tag = CARD_SPADE_TAG(8);
						break;
					case 9:
						tag = CARD_SPADE_TAG(9);
						break;
					case 10:
						tag = CARD_SPADE_TAG(10);
						break;
					case 11:
						tag = CARD_SPADE_TAG(11);
						break;
					case 12:
						tag = CARD_SPADE_TAG(12);
						break;
					case 13:
						tag = CARD_SPADE_TAG(13);
						break;
					default:
						break;
					}
				}
				return tag;

			}

			//this 不再是 rollingOverManager
			void RollingOverManager::addCards(float time)
			{
				int currentCardPosition = ((TexaPoker::RoomM::Scene::RoomMScene*)this)->getPRManager()->getCurrentCardPosition();
				int cardPositionSize = ((TexaPoker::RoomM::Scene::RoomMScene*)this)->getPRManager()->getCardPositionSize();
				//CCLog("--- currentP %d SIze %d", currentCardPosition, cardPositionSize);
				if(currentCardPosition >= cardPositionSize)
				{
					//CCDirector::sharedDirector()->getScheduler()->unscheduleAll();
					//CCLOG("return");
					return;
				}
				CCPoint* positionArray = ((TexaPoker::RoomM::Scene::RoomMScene*)this)->getPRManager()->getCardPositionArray();
				//CCLog("x %d y %d", (positionArray + currentCardPosition)->x, (positionArray + currentCardPosition)->y);
				int tempTag = 0;
				int type = 0;
				int num = 0;
				//保证卡牌tag不一致
				for(;;)
				{
					type = CARD_TYPE(TexaPoker::BaseUtil::Num::genRand(0, 4));
					num = CARD_TYPE(TexaPoker::BaseUtil::Num::genRand(1, 13));
					tempTag = getCardTag(type, num);
					vector<int>::iterator ret;
					ret = std::find(((TexaPoker::RoomM::Scene::RoomMScene*)this)->getPRManager()->cardsTagArray.begin(), ((TexaPoker::RoomM::Scene::RoomMScene*)this)->getPRManager()->cardsTagArray.end(), tempTag);
					if(ret == ((TexaPoker::RoomM::Scene::RoomMScene*)this)->getPRManager()->cardsTagArray.end())
						break;
				}
				((TexaPoker::RoomM::Scene::RoomMScene*)this)->getPRManager()->cardsTagArray.push_back(tempTag);
				TexaPoker::RoomM::Sprites::RoomCard* pcard = TexaPoker::RoomM::Sprites::RoomCard::createWithSpriteFrame( ((TexaPoker::RoomM::Scene::RoomMScene*)this)->getPRManager() , CARD_STATE_BACK, num, type, tempTag);
				pcard->setPosition(pcard->genInitPosition());
				CCDirector::sharedDirector()->getRunningScene()->addChild(pcard, SCENE_Z_ORDER_FRONT, tempTag);
				CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(pcard, 0, false);
				pcard->dealCardShake(ccp((positionArray + currentCardPosition)->x, (positionArray + currentCardPosition)->y), 0.1);
				((TexaPoker::RoomM::Scene::RoomMScene*)this)->getPRManager()->setCurrentCardPosition(currentCardPosition + 1);
			}

			void RollingOverManager::flowCards(float dt)
			{
				((TexaPoker::RoomM::Scene::RoomMScene*)this)->gravityOn = true;
				int currentFlowPosition = ((TexaPoker::RoomM::Scene::RoomMScene*)this)->getPRManager()->getCurrentFlowPosition();
				int flowPositionSize = ((TexaPoker::RoomM::Scene::RoomMScene*)this)->getPRManager()->getFlowPositionSize();
				//CCLOG("%d --- %d ",currentFlowPosition, flowPositionSize );
				int type = CARD_TYPE(TexaPoker::BaseUtil::Num::genRand(0, 4));
				int num = CARD_TYPE(TexaPoker::BaseUtil::Num::genRand(1, 13));
				int tempTag = getCardTag(type, num);
				if(currentFlowPosition > flowPositionSize - 1)
				{
					currentFlowPosition = 0;
					((TexaPoker::RoomM::Scene::RoomMScene*)this)->getPRManager()->setCurrentFlowPosition(0);
				}
				CCPoint* positionArray = ((TexaPoker::RoomM::Scene::RoomMScene*)this)->getPRManager()->getFlowPositionArray();
				TexaPoker::RoomM::Sprites::RoomCard* pcard = TexaPoker::RoomM::Sprites::RoomCard::createWithSpriteFrame( ((TexaPoker::RoomM::Scene::RoomMScene*)this)->getPRManager() , CARD_STATE_BACK, num, type, tempTag);
				pcard->setPosition(ccp((positionArray + currentFlowPosition)->x, (positionArray + currentFlowPosition)->y));
				CCDirector::sharedDirector()->getRunningScene()->addChild(pcard, SCENE_Z_ORDER_FRONT, tempTag);
				CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(pcard, 0, false);
				pcard->bindPhysicalBody(ccp((positionArray + currentFlowPosition)->x, (positionArray + currentFlowPosition)->y), LINEAER_DAMP - 6, ANGULAR_DAMP);
				currentFlowPosition++;
				((TexaPoker::RoomM::Scene::RoomMScene*)this)->getPRManager()->setCurrentFlowPosition(currentFlowPosition);
			}
			void RollingOverManager::stopAllCardsActions()
			{
				for(vector<int>::iterator it = this->cardsTagArray.begin(); 
					it !=this->cardsTagArray.end(); it++)
				{  
					CCDirector::sharedDirector()->getRunningScene()->getChildByTag(*it)->stopAllActions();
				} 

			}

			void RollingOverManager::turnOverAndFadeOutCards()
			{
				for(vector<int>::iterator it = this->cardsTagArray.begin(); 
					it !=this->cardsTagArray.end(); it++)
				{  
					TexaPoker::RoomM::Sprites::RoomCard* card = dynamic_cast<TexaPoker::RoomM::Sprites::RoomCard *>(CCDirector::sharedDirector()->getRunningScene()->getChildByTag(*it));
					if(card != NULL)
					{
						CCDirector::sharedDirector()->getRunningScene()->runAction(CCCallFunc::create(card, callfunc_selector(TexaPoker::RoomM::Sprites::RoomCard::turnOverBackAndFadeOut)));
					}
				} 
			}

			void RollingOverManager::turnOverAndFadeOutCardsFinished()
			{
				currentFlowTurnOverCountPosition++;
				if(currentFlowTurnOverCountPosition == cardsTagArray.size()){
					initFlowCards();
				}
				//CCLOG("current%d size %d", currentFlowTurnOverCountPosition, cardsTagArray.size());
			}

			int RollingOverManager::getCardArrayCount(int num, int type)
			{
				return num + type * 13;
			}

			std::string * RollingOverManager::getCardArrays()
			{
				return this->cardsArray;
			}

			std::vector <int> RollingOverManager::getCardsTagArray()
			{
				return this->cardsTagArray;
			}

			void RollingOverManager::setCardsTagArray(std::vector<int> i)
			{
				this->cardsTagArray = i;
			}

			int RollingOverManager::getCardPositionSize()
			{
				return cardPositionSize;
			}

			void RollingOverManager::setCurrentCardPosition(int p)
			{
				currentCardPosition = p;
			}

			int RollingOverManager::getCurrentCardPosition()
			{
				return currentCardPosition;
			}

			CCPoint* RollingOverManager::getCardPositionArray()
			{
				return cardsPosition;
			}

			CCPoint* RollingOverManager::getFlowPositionArray()
			{
				return flowPosition;
			}

			int RollingOverManager::getFlowPositionSize()
			{
				return this->flowPositionSize;
			}

			int RollingOverManager::getCurrentFlowPosition()
			{
				return this->currentFlowPosition;
			}

			void RollingOverManager::setCurrentFlowPosition(int p)
			{
				this->currentFlowPosition = p;
			}

			CCLayer* RollingOverManager::getMScence()
			{
				return mScene;
			}

		}
	}
}