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

/* card begin*/
#define CARDBACK "card_back.png"
//梅花 Clubs 
#define CARDAC "card_a_c.png"
#define CARD2C "card_2_c.png"
#define CARD3C "card_3_c.png"
#define CARD4C "card_4_c.png"
#define CARD5C "card_5_c.png"
#define CARD6C "card_6_c.png"
#define CARD7C "card_7_c.png"
#define CARD8C "card_8_c.png"
#define CARD9C "card_9_c.png"
#define CARD10C "card_10_c.png";
#define CARDJC "card_j_c.png"
#define CARDQC "card_q_c.png"
#define CARDKC "card_k_c.png"
//方块 diamonds 
#define CARDAD "card_a_d.png"
#define CARD2D "card_2_d.png"
#define CARD3D "card_3_d.png"
#define CARD4D "card_4_d.png"
#define CARD5D "card_5_d.png"
#define CARD6D "card_6_d.png"
#define CARD7D "card_7_d.png"
#define CARD8D "card_8_d.png"
#define CARD9D "card_9_d.png"
#define CARD10D "card_10_c.png";
#define CARDJD "card_j_d.png"
#define CARDQD "card_q_d.png"
#define CARDKD "card_k_d.png"
//红桃 hearts 
#define CARDAH "card_a_h.png"
#define CARD2H "card_2_h.png"
#define CARD3H "card_3_h.png"
#define CARD4H "card_4_h.png"
#define CARD5H "card_5_h.png"
#define CARD6H "card_6_h.png"
#define CARD7H "card_7_h.png"
#define CARD8H "card_8_h.png"
#define CARD9H "card_9_h.png"
#define CARD10H "card_10_h.png";
#define CARDJH "card_j_h.png"
#define CARDQH "card_q_h.png"
#define CARDKH "card_k_h.png"
//黑桃 spade 
#define CARDAS "card_a_s.png"
#define CARD2S "card_2_s.png"
#define CARD3S "card_3_s.png"
#define CARD4S "card_4_s.png"
#define CARD5S "card_5_s.png"
#define CARD6S "card_6_s.png"
#define CARD7S "card_7_s.png"
#define CARD8S "card_8_s.png"
#define CARD9S "card_9_s.png"
#define CARD10S "card_10_d.png";
#define CARDJS "card_j_s.png"
#define CARDQS "card_q_s.png"
#define CARDKS "card_k_s.png"

/* card end */

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

