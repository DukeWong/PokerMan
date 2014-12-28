#ifndef _ROOM_ROLLINGOVER_MANAGER_H__
#define _ROOM_ROLLINGOVER_MANAGER_H__

#include "cocos2d.h"
#include "Constants.h"

USING_NS_CC;

namespace TexaPoker{
	namespace RoomM{
		namespace Controller{
			class RollingOverManager: public CCObject
			{
			private:
				std::string cardsArray[53];
				std::vector <int> cardsTagArray;
				CCPoint cardsPosition[45];
				CCPoint flowPosition[2];
				CCLayer *mScene;
				int cardPositionSize;
				int currentCardPosition;
				int flowPositionSize;
				int currentFlowPositionSize;
			public:
				RollingOverManager(CCLayer * c);
				~RollingOverManager();
				void initCardData();
				void initCards();
				void addCards(float time);
				void flowCards(float time);
				void stopAllCardsActions();
				void turnOverAndFadeOutCards();
				void removeCardsByTag();
				int getCardArrayCount(int cardNum, int cardType);
				std::string* getCardArrays();
				int getCardTag(int type, int num);
				int getCardPositionSize();
				CCPoint* getCardPositionArray();
				void setCurrentCardPosition(int position);
				int getCurrentCardPosition();
				CCLayer* getMScence();
			};
		}
	}
}

#endif