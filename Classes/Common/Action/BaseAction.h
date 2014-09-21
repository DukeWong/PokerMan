#ifndef __BASE_ACTION_H__
#define __BASE_ACTION_H__

#include "cocos2d.h"

using namespace cocos2d;

namespace TexaPoker{
	namespace BaseAction{

		class MoveAction
		{
		private:
			CCActionInterval*  actionByMap;
		public:
			void ActionBy(CCNode *pNode, float duration, CCPoint &pos);
		};

	}}


#endif