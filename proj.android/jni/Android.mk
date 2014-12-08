LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := cocos2dcpp_shared

LOCAL_MODULE_FILENAME := libcocos2dcpp

LOCAL_SRC_FILES := hellocpp/main.cpp \
                   ../../Classes/AppDelegate.cpp \
                   ../../Classes/Common/Action/BaseAction.cpp \
                   ../../Classes/Common/External/B2DebugDraw/B2DebugDrawLayer.cpp \
                   ../../Classes/Common/External/B2DebugDraw/GLES-Render.cpp \
                   ../../Classes/Common/GUI/BaseGUI.cpp \
                   ../../Classes/Common/Util/BaseUtil.cpp \
                   ../../Classes/Scene/Hall/HallScene.cpp \
                   ../../Classes/Scene/RoomM/RoomMScene.cpp \
                   ../../Classes/Scene/RoomM/Controller/RollingOverManager.cpp \
                   ../../Classes/Scene/RoomM/Sprites/RoomBackground.cpp \
                   ../../Classes/Scene/RoomM/Sprites/RoomCard.cpp \
                   

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes

LOCAL_WHOLE_STATIC_LIBRARIES += cocos2dx_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocosdenshion_static
LOCAL_WHOLE_STATIC_LIBRARIES += box2d_static
LOCAL_WHOLE_STATIC_LIBRARIES += chipmunk_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocos_extension_static

include $(BUILD_SHARED_LIBRARY)

$(call import-module,cocos2dx)
$(call import-module,cocos2dx/platform/third_party/android/prebuilt/libcurl)
$(call import-module,CocosDenshion/android)
$(call import-module,extensions)
$(call import-module,external/Box2D)
$(call import-module,external/chipmunk)
