#include "BaseAction.h"

namespace TexaPoker{
	namespace BaseAction{

		// not really useful, but I like clean default constructors  
		ShakeAction::ShakeAction() : m_strength_x(0), m_strength_y(0)  
		{  
		}      

		ShakeAction *ShakeAction::create(float duration, float strength_x, float strength_y)  
		{  
			ShakeAction *pRet = new ShakeAction();   
			if (pRet && pRet->initWithDuration(duration, strength_x, strength_y))  
			{  
				pRet->autorelease();  
			}  
			else  
			{  
				CC_SAFE_DELETE(pRet);  
			}  
			return pRet;  
		}  

		bool ShakeAction::initWithDuration(float duration, float strength_x, float strength_y)  
		{  
			if (CCActionInterval::initWithDuration(duration))  
			{  
				m_strength_x = strength_x;  
				m_strength_y = strength_y;  

				return true;  
			}    
			return false;  
		}  

		// Helper function. I included it here so that you can compile the whole file  
		// it returns a random value between min and max included  
		static float fgRangeRand( float min, float max )  
		{  
			float rnd = ((float)rand() / (float)RAND_MAX);  
			return rnd * (max - min) + min;  
		}  

		void ShakeAction::update(float dt)  
		{  
			float randx = fgRangeRand( -m_strength_x, m_strength_x );  
			float randy = fgRangeRand( -m_strength_y, m_strength_y );  

			// move the target to a shaked position  
			m_pTarget->setPosition( ccp( randx + m_StartPosition.x, randy + m_StartPosition.y)); 
		}  

		void ShakeAction::startWithTarget(CCNode *pTarget)  
		{  
			CCActionInterval::startWithTarget( pTarget );   
			// save the initial position  
			m_StartPosition=pTarget->getPosition();  
		}  

		void ShakeAction::stop(void)  
		{  
			// Action is done, reset clip position  
			this->getTarget()->setPosition( m_StartPosition);    
			CCActionInterval::stop();  
		}  		

	}}