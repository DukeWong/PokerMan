#include "RoomBackground.h"

USING_NS_CC;

namespace TexaPoker{
	namespace RoomM{
		namespace Sprites{
			RoomBackground* RoomBackground::create(const char *pszFileName, const CCRect& rect)
			{
				RoomBackground *pobSprite = new RoomBackground();
				if (pobSprite && pobSprite->initWithFile(pszFileName, rect))
				{
					pobSprite->autorelease();
					return pobSprite;
				}
				CC_SAFE_DELETE(pobSprite);
				return NULL;
			}

			void RoomBackground::moveOn()
			{
				this->setPositionY(this->getPositionY() + CCDirector::sharedDirector()->getVisibleSize().height / 80);

				if(this->getPositionY() >= CCDirector::sharedDirector()->getVisibleSize().height / 2 * 3)
				{
					this->setPositionY(- CCDirector::sharedDirector()->getVisibleSize().height / 2);
				}
			}
		}}}
