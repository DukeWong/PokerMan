#ifndef _ROOM_BACKGROUND_H__
#define _ROOM_BACKGROUND_H__

#include "cocos2d.h"

USING_NS_CC;
namespace TexaPoker{
	namespace RoomM{
		namespace Sprites{
			class RoomBackground: public cocos2d::CCSprite
			{
			public:
				static RoomBackground* create(const char *pszFileName, const CCRect& rect);
				void moveOn();
			};
		}}}
#endif