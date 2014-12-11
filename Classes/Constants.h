#ifndef __TEXTPOKER_CONSTANT_H__
#define __TEXTPOKER_CONSTANT_H__

#define HALL_PATH "hall"
#define HALL_SPRITE_PATH "hall/sprites"
#define HALL_PARTICEL_PATH "hall/particle"
#define HALL_PATH_CONNECT(path) HALL_PATH#path
#define HALL_SPRITE_PATH_CONNECT(path) HALL_SPRITE_PATH#path
#define HALL_PARTICEL_PATH_CONNECT(path) HALL_PARTICEL_PATH#path


#define ROOM_M_PATH "room_m"
#define ROOM_M_SPRITE_PATH "room_m/sprites"
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

#define ROOMM_SCENE_1_TAG 0x0000;
#define ROOMM_SCENE_2_TAG 0x0001;
#define ROOMM_SCENE_3_TAG 0x0002;
#define ROOMM_SCENE_4_TAG 0x0003;
#define ROOMM_SCENE_5_TAG 0x0004;
#define ROOMM_SCENE_6_TAG 0x0005;
#define ROOMM_SCENE_7_TAG 0x0006;

#define CARD_CLUBS_1_TAG 0x1000;
#define CARD_CLUBS_2_TAG 0x1001;
#define CARD_CLUBS_3_TAG 0x1002;
#define CARD_CLUBS_4_TAG 0x1003;
#define CARD_CLUBS_5_TAG 0x1004;
#define CARD_CLUBS_6_TAG 0x1005;
#define CARD_CLUBS_7_TAG 0x1006;
#define CARD_CLUBS_8_TAG 0x1007;
#define CARD_CLUBS_9_TAG 0x1008;
#define CARD_CLUBS_10_TAG 0x1009;
#define CARD_CLUBS_11_TAG 0x100A;
#define CARD_CLUBS_12_TAG 0x100B;
#define CARD_CLUBS_13_TAG 0x100C;

#define CARD_DIAMONDS_1_TAG 0x100D;
#define CARD_DIAMONDS_2_TAG 0x100E;
#define CARD_DIAMONDS_3_TAG 0x100F;
#define CARD_DIAMONDS_4_TAG 0x1010;
#define CARD_DIAMONDS_5_TAG 0x1011;
#define CARD_DIAMONDS_6_TAG 0x1012;
#define CARD_DIAMONDS_7_TAG 0x1013;
#define CARD_DIAMONDS_8_TAG 0x1014;
#define CARD_DIAMONDS_9_TAG 0x1015;
#define CARD_DIAMONDS_10_TAG 0x1016;
#define CARD_DIAMONDS_11_TAG 0x1017;
#define CARD_DIAMONDS_12_TAG 0x1018;
#define CARD_DIAMONDS_13_TAG 0x1019;

#define CARD_HEARTS_1_TAG 0x101A;
#define CARD_HEARTS_2_TAG 0x101B;
#define CARD_HEARTS_3_TAG 0x101C;
#define CARD_HEARTS_4_TAG 0x101D;
#define CARD_HEARTS_5_TAG 0x101E;
#define CARD_HEARTS_6_TAG 0x101F;
#define CARD_HEARTS_7_TAG 0x1020;
#define CARD_HEARTS_8_TAG 0x1021;
#define CARD_HEARTS_9_TAG 0x1022;
#define CARD_HEARTS_10_TAG 0x1023;
#define CARD_HEARTS_11_TAG 0x1024;
#define CARD_HEARTS_12_TAG 0x1025;
#define CARD_HEARTS_13_TAG 0x1026;

#define CARD_SPADE_1_TAG 0x1027;
#define CARD_SPADE_2_TAG 0x1028;
#define CARD_SPADE_3_TAG 0x1029;
#define CARD_SPADE_4_TAG 0x102A;
#define CARD_SPADE_5_TAG 0x102B;
#define CARD_SPADE_6_TAG 0x102C;
#define CARD_SPADE_7_TAG 0x102D;
#define CARD_SPADE_8_TAG 0x102E;
#define CARD_SPADE_9_TAG 0x102F;
#define CARD_SPADE_10_TAG 0x1030;
#define CARD_SPADE_11_TAG 0x1031;
#define CARD_SPADE_12_TAG 0x1032;
#define CARD_SPADE_13_TAG 0x1033;

/*  Tag end  */

/* box2d begin*/
#define PTM_RATIO 32
/* box2d end*/
#endif

