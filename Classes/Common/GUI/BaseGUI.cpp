#include "BaseGUI.h"

namespace TexaPoker{
	namespace BaseGUI{

		bool BaseButton::ccTouchBegan(CCTouch* touch, CCEvent* event){
			CC_UNUSED_PARAM(event);
			if (m_eState != kCCMenuStateWaiting || ! m_bVisible)
			{
				return false;
			}

			for (CCNode *c = this->m_pParent; c != NULL; c = c->getParent())
			{
				if (c->isVisible() == false)
				{
					return false;
				}
			}

			m_pSelectedItem = this->itemForTouch(touch);
			if (m_pSelectedItem)
			{
				m_eState = kCCMenuStateTrackingTouch;
				m_pSelectedItem->selected();
				this->setScale(defaultScale * 0.99);
				return true;
			}
			return false;
		}

		void BaseButton::ccTouchEnded(CCTouch* touch, CCEvent* event){
			CC_UNUSED_PARAM(touch);
			CC_UNUSED_PARAM(event);
			CCAssert(m_eState == kCCMenuStateTrackingTouch, "[Menu ccTouchEnded] -- invalid state");
			if (m_pSelectedItem)
			{
				m_pSelectedItem->unselected();
				m_pSelectedItem->activate();
				this->setScale(defaultScale);
				//	return CCMenu::ccTouchEnded(touch, event);
				if(this->mTarget && this->mHandler)
				{
					(mTarget->*mHandler)(event);
				}
			}
			m_eState = kCCMenuStateWaiting;

		}

		//BaseButton* BaseButton::create(float mScaleNum, CCMenuItem* item, ...){

		//	defaultScale = mScaleNum;
		//	va_list arg = NULL;
		//	va_start(arg, item);
		//	return (BaseButton *)CCMenu::create(item, arg);
		//};

		BaseButton* BaseButton::create(float mScaleNum, CCMenuItem* item, CCObject* mTarget, SEL_EventHandler mHandler){
			CCArray* pArray = NULL;
			if( item )
			{
				pArray = CCArray::create(item, NULL);

			}
			BaseButton * pBaseButton = new BaseButton();
			if(pBaseButton && pBaseButton->initWithArray(pArray)){
				pBaseButton->defaultScale = mScaleNum;
				pBaseButton->setScale(mScaleNum);
				pBaseButton->mTarget = mTarget;
				pBaseButton->mHandler = mHandler;
				pBaseButton->autorelease();
			}else{
				CC_SAFE_DELETE(pBaseButton);
			}
			return pBaseButton;
		}

		void BaseButton::resetScale()
		{
			this->setScale(defaultScale);
		}

		void BaseArmatureButton::setPriority(int nPriority){
			_nPriority = nPriority;
		}
		int BaseArmatureButton::getPriority(){
			return _nPriority;
		} 

		BaseArmatureButton* BaseArmatureButton::create(float scale, const char *name, int nPriority,  CCObject* mTarget, SEL_EventHandler mHandler){
			BaseArmatureButton *armature = new BaseArmatureButton();
			if (armature && armature->init(name))
			{
				armature->defaultScale = scale;
				armature->setScale(scale);
				armature->mTarget = mTarget;
				armature->mHandler = mHandler;
				armature->setPriority(nPriority);
				armature->autorelease();
				return armature;
			}
			CC_SAFE_DELETE(armature);
			return NULL;
		}

		bool BaseArmatureButton::ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event){
			CCPoint touchLocation= touch->getLocation();
			CCRect r = this->rect();
			if(r.containsPoint(touchLocation)){
				this->setScale(defaultScale * 0.99);
			}
			return true;
		}

		void BaseArmatureButton::ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event){
			CCPoint touchLocation= touch->getLocation();
			CCRect r = this->rect();
			if(r.containsPoint(touchLocation)){
				this->setScale(defaultScale);
				if(this->mTarget && this->mHandler)
				{
					(mTarget->*mHandler)(event);
				}
			}
		}

		void BaseArmatureButton::onEnter(){
			CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, _nPriority, true);
			CCArmature::onEnter();
		}

		void BaseArmatureButton::onExit(){
			CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
			CCArmature::onExit();
		}

		CCRect BaseArmatureButton::rect()
		{
			return CCRectMake( m_obPosition.x - m_obContentSize.width * m_obAnchorPoint.x,
				m_obPosition.y - m_obContentSize.height * m_obAnchorPoint.y,
				m_obContentSize.width, m_obContentSize.height);
		}

		void BaseArmatureButton::resetScale()
		{
			this->setScale(defaultScale);
		}

		BaseMoveButton* BaseMoveButton::create(float mScaleNum, cocos2d::CCMenuItem* item, CCActionInterval* action, CCObject * mTarget, bool isBack, int status, SEL_EventHandler mHandler)
		{
			CCArray* pArray = NULL;
			if( item )
			{
				pArray = CCArray::create(item, NULL);

			}
			BaseMoveButton * pBaseButton = new BaseMoveButton();
			if(pBaseButton && pBaseButton->initWithArray(pArray)){
				pBaseButton->defaultScale = mScaleNum;
				pBaseButton->setScale(mScaleNum);
				pBaseButton->isMoveBack = isBack;
				pBaseButton->moveStatus = status;
				pBaseButton->mTarget = mTarget;
				pBaseButton->mHandler = mHandler;
				CC_SAFE_RETAIN(action); 
				pBaseButton->actionTo = action;
				pBaseButton->autorelease();
			}else{
				CC_SAFE_DELETE(pBaseButton);
			}
			return pBaseButton;
		}

		void BaseMoveButton::moveBack(BaseMoveButton* p)
		{
			if(this->isMoveBack)
			{
				if(this->moveStatus == 0){
					p->moveBy(p);
					moveStatus = 1;
				}else{
					p->moveByReverse(p);
					moveStatus = 0;
				}

			}else{
				p->moveBy(p);
			}

		}

		void BaseMoveButton::moveBy(BaseMoveButton* p)
		{
			p->runAction(p->actionTo);
		}

		void BaseMoveButton::moveByReverse(BaseMoveButton* p)
		{
			p->runAction(p->actionTo->reverse());
		}

	}}