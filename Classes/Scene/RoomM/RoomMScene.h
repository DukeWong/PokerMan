#ifndef __ROOM_M_SCENE_H__
#define __ROOM_M_SCENE_H__

#include "cocos2d.h"
#include "Constants.h"
#include "..\Hall\HallScene.h"
#include "Sprites\RoomBackground.h"
#include "Controller\RollingOverManager.h"
#include "..\..\Common\GUI\BaseGUI.h"
#include "..\..\Common\Action\BaseAction.h"
#include "..\external\Box2D\Box2D.h"

#define ROOM_STATUS_INIT 0
#define ROOM_STATUS_CARD_FLOW 1

#define ROOM_INIT_INTERVAL_TIME 0.3F
/* box2d begin*/
#define VELOCITY_ITERATIONS 8
#define POSITION_ITERATIONS 1
/* box2d end*/
#

namespace TexaPoker{
	namespace RoomM{
		namespace Scene{
			class RoomMScene : public cocos2d::CCLayer , public b2ContactListener 
			{
			private:
				CCSize visibleSize;
				CCPoint origin;
				int roomBackground1Tag;
				int roomBackground2Tag;
				int pokerTag;
				int heartButtonTag;
				int fireButtonTag;
				int roomMGirlButtonTag;
				int roomStatus;
				TexaPoker::RoomM::Controller::RollingOverManager* pRManager;
				void checkSpritesStatus();
				virtual void keyBackClicked();//Android ·µ»Ø¼ü
				virtual void BeginContact(b2Contact* contact);
				void finishFadeOutAction(CCNode* pSender);
				virtual void PreSolve(b2Contact* contact, const b2Manifold* oldManifold);
				//box2d
				b2World* pWorld; 
				b2Body* m_groundBody;


			public:
				RoomMScene();
				~RoomMScene();
				virtual bool init();
				virtual void initPhysics();
				CREATE_FUNC(RoomMScene);
				void onEnter();
				void onExit();
				TexaPoker::RoomM::Controller::RollingOverManager* getPRManager();
				void menuBackCallback(CCObject* pSender);
				void heartCallback(CCEvent* pEvent);
				void update(float data);
				void initCards(float data);
				b2World* getWorld();
				b2Body* getGroundBody();
			};
		}
	}
}


#endif