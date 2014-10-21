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
			public:
				void initCardData();
				void initCards();
				RollingOverManager();
				int getCardArrayCount(int cardNum, int cardType);
				std::string* getCardArrays();
			};
		}
	}
}

#endif