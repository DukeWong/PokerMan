#ifndef __BASE_GUI_H__
#define __BASE_GUI_H__

#include "cocos2d.h"
#include "CocoStudio\Armature\CCArmature.h"


using namespace cocos2d;

namespace TexaPoker{
	namespace BaseGUI{

		class BaseButton : public cocos2d::CCMenu{
		protected:
			float defaultScale;
			SEL_EventHandler mHandler;
		public:
			//BaseButton(float scale = 1.0);
			//virtual ~ BaseButton();
			bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
			void ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
			static BaseButton* create(float scale, cocos2d::CCMenuItem* item, SEL_EventHandler mHandler = NULL);
		};

		class BaseArmatureButton: public cocos2d::extension::CCArmature, public cocos2d::CCTouchDelegate{
		protected:
			float defaultScale;
			int _nPriority;
			SEL_EventHandler mHandler;
		public :
			virtual bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
			virtual void ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
			virtual void BaseArmatureButton::onEnter();
			virtual void BaseArmatureButton::onExit();
			static BaseArmatureButton* create(float scale, const char *name, int nPriority, SEL_EventHandler mHandler = NULL);
			void setPriority(int nPriority);
			int getPriority();
			CCRect rect();
		};

		class BaseMoveButton: public BaseButton
		{
		private:
			CCActionInterval*  actionTo;
			bool isMoveBack; // false 移动不返回  true 移动返回
			int moveStatus; // 0 原始方向  1返回方向
		public :
			static BaseMoveButton* create(float scale, cocos2d::CCMenuItem* item, CCActionInterval* action, bool isBack = false, int status = 0, SEL_EventHandler mHandler = NULL);
			void moveBack(BaseMoveButton* p);
			void moveBy(BaseMoveButton* p);
			void moveByReverse(BaseMoveButton* p);
		};
	}}

#endif