#pragma once
#include "../../graphics/3d/model.hpp"
#include "../../graphics/3d/texture.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 232  |  ov098  |  profile @ 0x02189718
class Object232 : public StageEntity {
public:
	Platform _3f4;        /* 0x3F4 */
	Vec2_32 _44c[6];      /* 0x44C */
	Texture _494;         /* 0x494 */
	u8 _pad0[0x8];        /* 0x49C */
	Vec2_32 _4a4[4];      /* 0x4A4 */
	Vec2_32 _4d4[15];     /* 0x4D4 */
	u8 _pad1[0x40];       /* 0x588 */
	u8 _5c8;              /* 0x5C8 */
	u8 _pad2[0x3];        /* 0x5C9 */
	u8 _5cc[0x20];        /* 0x5CC */
	u8 _5ec[0x20];        /* 0x5EC */
	Model _60c;           /* 0x60C */
	RotatingPlatform _69c[2]; /* 0x69C */
	Vec2_32 _77c[4];      /* 0x77C */
	u32 _7ac;             /* 0x7AC */
	u8 _7b0;              /* 0x7B0 */
	u8 _pad3[0x3];        /* 0x7B1 */

	static void *create();
	inline Object232() {};
	inline ~Object232() {};

	virtual void pendingDestroy();
	virtual s32 onDestroy();
	virtual bool onHeapCreated();
	virtual s32 onRender();
};

extern ActorProfile Object232_Profile;
