#ifndef __BASE_ACTION_H__
#define __BASE_ACTION_H__

#include "cocos2d.h"

USING_NS_CC;

namespace TexaPoker{
	namespace BaseAction{
		class ShakeAction : public CCActionInterval
		{
		public:
			ShakeAction();
			static ShakeAction* create(float fDuration, float m_strength_x, float m_strength_y);
			virtual bool initWithDuration(float fDuration, float m_strength_x, float m_strength_y);
			/**
			*  @js NA
			*  @lua NA
			*/
			virtual void startWithTarget(CCNode *pTarget);
			virtual void update(float time);
			virtual void stop();

		protected:
			// Strength of the action  
			float m_strength_x, m_strength_y; 
			CCPoint m_StartPosition;  
		};

	}}

#endif