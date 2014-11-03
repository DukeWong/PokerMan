#ifndef _ROOM_ROLLINGOVER_MANAGER_H__
#define _ROOM_ROLLINGOVER_MANAGER_H__

#include "cocos2d.h"
#include "Constants.h"

USING_NS_CC;

namespace TexaPoker{
	namespace RoomM{
		namespace Controller{
			class RollingOverManager
			{
			private:
				std::string cardsArray[53];
				CCPoint cardsPosition[45];
				CCLayer *mScene;
				int cardPositionSize;
				int currentCardPosition;
			public:
				RollingOverManager(CCLayer * c);
				void initCardData();
				void initCards();
				void addCards(float time);
				int getCardArrayCount(int cardNum, int cardType);
				std::string* getCardArrays();
				int getCardTag(int type, int num);
				int getCardPositionSize();
				CCPoint* getCardPositionArray();
				void setCurrentCardPosition(int position);
				int getCurrentCardPosition();
				
			};
		}
	}
}

#endif