#ifndef _ROOM_ROLLINGOVER_MANAGER_H__
#define _ROOM_ROLLINGOVER_MANAGER_H__

#include "cocos2d.h"
#include "Constants.h"

#define CARD10C "card_10_c.png";
#define CARD10H "card_10_d.png";

USING_NS_CC;

namespace TexaPoker{
	namespace RoomM{
		namespace Controller{
			class RollingOverManager
			{
			private:
				std::string cardsArray[55];
			public:
				void initCards();
				RollingOverManager();
				int getCardArrayCount(int cardNum, int cardType);
				std::string* getCardArrays();
			};
		}
	}
}

#endif