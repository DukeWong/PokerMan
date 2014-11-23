#ifndef _ROOM_CARD_H__
#define _ROOM_CARD_H__

#include "cocos2d.h"
#include "Constants.h"
#include "..\Controller\RollingOverManager.h"

#define CARD_STATE_BACK 0
#define CARD_STATE_FRONT 1

enum CARD_TYPE{CARD_HERATS = 0, CARD_SPADES, CARD_CLUBS, CARD_DIAMONDS};

USING_NS_CC;

namespace TexaPoker{
	namespace RoomM{
		namespace Sprites{
			class RoomCard : public cocos2d::CCSprite, public cocos2d::CCTouchDelegate
			{
				private: int tag;
						 int num;
						 int type;
						 int state;
						 const char* name;
			public:
				static RoomCard* createWithSpriteFrame(TexaPoker::RoomM::Controller::RollingOverManager* manager, int state, int cardNum, int cardType, int tag);
				void dealCard(CCPoint to, float intervalTime);
				void dealCardShake(CCPoint to, float intervalTime);
				void turnOverBack();
				void turnOverBackFinished();
				CCRect rect();
				virtual bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
				virtual void ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
				CCPoint genInitPosition();

				//CC_SYNTHESIZE_READONLY(int, tag, Tag);
				//CC_SYNTHESIZE_READONLY(int, num, Num);
				//CC_SYNTHESIZE_READONLY(int, type, Type);
				//CC_SYNTHESIZE_READONLY(int, state, State);
			};

		}}}
#endif