#ifndef __TEXTPOKER_CONSTANT_H__
#define __TEXTPOKER_CONSTANT_H__

#define HALL_PATH "/hall"
#define HALL_SPRITE_PATH "/hall/sprites"
#define HALL_PATH_CONNECT(path) HALL_PATH#path
#define HALL_SPRITE_PATH_CONNECT(path) HALL_SPRITE_PATH#path

#define ROOM_M_PATH "/room_m"
#define ROOM_M_SPRITE_PATH "/room_m/sprites"
#define ROOM_M_PATH_CONNECT(path) ROOM_M_PATH#path
#define ROOM_M_SPRITE_PATH_CONNECT(path) ROOM_M_SPRITE_PATH#path

#define SCENE_Z_ORDER_BG 0
#define SCENE_Z_ORDER_FRONT SCENE_Z_ORDER_BG + 3

#define COLOR_YELLOW 250, 210, 40

/*  Tag begin  */
#define ROOMM_SCENE_TAG(name) ROOMM_SCENE_##name##_TAG //房间类型
#define CARD_CLUBS_TAG(num) CARD_CLUBS_##num##_TAG; //牌类型

#define ROOMM_SCENE_1_TAG 1;
#define ROOMM_SCENE_2_TAG 2;
#define ROOMM_SCENE_3_TAG 3;
#define ROOMM_SCENE_4_TAG 4;
#define ROOMM_SCENE_5_TAG 5;
#define ROOMM_SCENE_6_TAG 6;
#define ROOMM_SCENE_7_TAG 7;

#define CARD_CLUBS_10_TAG 256;
#define CARD_3_10_TAG 332;

/*  Tag end  */
#endif

