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
#define CARD1C "card_a_c.png"
#define CARD2C "card_2_c.png"
#define CARD3C "card_3_c.png"
#define CARD4C "card_4_c.png"
#define CARD5C "card_5_c.png"
#define CARD6C "card_6_c.png"
#define CARD7C "card_7_c.png"
#define CARD8C "card_8_c.png"
#define CARD9C "card_9_c.png"
#define CARD10C "card_10_c.png";
#define CARD11C "card_j_c.png"
#define CARD12C "card_q_c.png"
#define CARD13C "card_k_c.png"
//方块 diamonds 
#define CARD1D "card_a_d.png"
#define CARD2D "card_2_d.png"
#define CARD3D "card_3_d.png"
#define CARD4D "card_4_d.png"
#define CARD5D "card_5_d.png"
#define CARD6D "card_6_d.png"
#define CARD7D "card_7_d.png"
#define CARD8D "card_8_d.png"
#define CARD9D "card_9_d.png"
#define CARD10D "card_10_c.png";
#define CARD11D "card_j_d.png"
#define CARD12D "card_q_d.png"
#define CARD13D "card_k_d.png"
//红桃 hearts 
#define CARD1H "card_a_h.png"
#define CARD2H "card_2_h.png"
#define CARD3H "card_3_h.png"
#define CARD4H "card_4_h.png"
#define CARD5H "card_5_h.png"
#define CARD6H "card_6_h.png"
#define CARD7H "card_7_h.png"
#define CARD8H "card_8_h.png"
#define CARD9H "card_9_h.png"
#define CARD10H "card_10_h.png";
#define CARD11H "card_j_h.png"
#define CARD12H "card_q_h.png"
#define CARD13H "card_k_h.png"
//黑桃 spade 
#define CARD1S "card_a_s.png"
#define CARD2S "card_2_s.png"
#define CARD3S "card_3_s.png"
#define CARD4S "card_4_s.png"
#define CARD5S "card_5_s.png"
#define CARD6S "card_6_s.png"
#define CARD7S "card_7_s.png"
#define CARD8S "card_8_s.png"
#define CARD9S "card_9_s.png"
#define CARD10S "card_10_d.png";
#define CARD11S "card_j_s.png"
#define CARD12S "card_q_s.png"
#define CARD13S "card_k_s.png"

/* card end */

/*  Tag begin  */
#define ROOMM_SCENE_TAG(name) ROOMM_SCENE_##name##_TAG //房间类型
#define CARD_CLUBS_TAG(num) CARD_CLUBS_##num##_TAG; //牌类型
#define CARD_DIAMONDS_TAG(num) CARD_DIAMONDS_##num##_TAG; 
#define CARD_HEARTS_TAG(num) CARD_HEARTS_##num##_TAG; 
#define CARD_SPADE_TAG(num) CARD_SPADE_##num##_TAG; 

#define ROOMM_SCENE_1_TAG 1;
#define ROOMM_SCENE_2_TAG 2;
#define ROOMM_SCENE_3_TAG 3;
#define ROOMM_SCENE_4_TAG 4;
#define ROOMM_SCENE_5_TAG 5;
#define ROOMM_SCENE_6_TAG 6;
#define ROOMM_SCENE_7_TAG 7;

#define CARD_CLUBS_1_TAG 8;
#define CARD_CLUBS_2_TAG 9;
#define CARD_CLUBS_3_TAG 10;
#define CARD_CLUBS_4_TAG 11;
#define CARD_CLUBS_5_TAG 12;
#define CARD_CLUBS_6_TAG 13;
#define CARD_CLUBS_7_TAG 14;
#define CARD_CLUBS_8_TAG 15;
#define CARD_CLUBS_9_TAG 16;
#define CARD_CLUBS_10_TAG 17;
#define CARD_CLUBS_11_TAG 18;
#define CARD_CLUBS_12_TAG 19;
#define CARD_CLUBS_13_TAG 20;
#define CARD_3_10_TAG 332;

/*  Tag end  */
#endif

