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
				CCPoint flowPosition[8];
				CCLayer *mScene;
				int cardPositionSize;
				int currentCardPosition;
				int flowPositionSize;
				int currentFlowPosition;
				int currentFlowTurnOverCountPosition;
			public:
				RollingOverManager(CCLayer * c);
				~RollingOverManager();
				void initCardData();
				void initCards();
				void initFlowCards();
				void addCards(float time);
				void flowCards(float time);
				void stopAllCardsActions();
				void turnOverAndFadeOutCards();
				void turnOverAndFadeOutCardsFinished();
				void removeCardsByTag();
				int getCardArrayCount(int cardNum, int cardType);
				std::string* getCardArrays();
				std::vector <int> getCardsTagArray();
				void setCardsTagArray(std::vector<int> i);
				int getCardTag(int type, int num);

				int getCardPositionSize();
				CCPoint* getCardPositionArray();
				void setCurrentCardPosition(int position);
				int getCurrentCardPosition();

				int getFlowPositionSize();
				CCPoint* getFlowPositionArray();
				void setCurrentFlowPosition(int position);
				int getCurrentFlowPosition();
				CCLayer* getMScence();
			};
		}
	}
}

#endif