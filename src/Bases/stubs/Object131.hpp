#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"
#include "../../graphics/3d/blendmodelanm.hpp"
#include "../../graphics/3d/modelanm.hpp"
#include "../../graphics/3d/model.hpp"
#include "../../Collision/activecollider.hpp"
#include "../../Collision/collisionmgr.hpp"
#include "../Player/PlayerBase.hpp"

namespace FS
{
void *loadFileEmb(u32, u32);
void *loadFileToOverlayEmb(u32, u32);
}

class CollisionManager : public CollisionMgr
{
public:
	u8 _pad[8];

	CollisionManager();
	virtual ~CollisionManager();
};

// MainProfileTable slot 131  |  ov013  |  profile @ 0x0213ba78
class Object131 : public StageEntity {
public:
	// 0x24: two virtual vectors plus a word the default ctor leaves alone
	struct Elem {
		u32 _0;
		Vec3_16 _4;
		s16 _10;
		u8 _pad12[2];
		Vec3_32 _14;
	};

	// 0xEC state block at 0xA00
	struct Sub {
		struct Row {
			s32 a, b;
		};

		s32 _0;
		s32 _4;
		s32 _8;
		s32 _c;
		Row _10[10];
		s8 _60;
		u8 _61;
		s16 _62;
		u32 _64;
		s8 _68;
		s8 _69;
		s8 _6a;
		s8 _6b;
		Vec3_32 _6c;
		Vec3_32 _7c;
		Vec3_32 _8c;
		Vec3_32 _9c;
		u32 _ac;
		u32 _b0;
		s8 _b4;
		s8 _b5;
		u8 _padb6[2];
		u32 _b8;
		u32 _bc;
		s8 _c0;
		s8 _c1;
		u8 _padc2;
		s8 _c3;
		s8 _c4;
		u8 _padc5;
		u16 _c6;
		u32 _c8;
		u32 _cc;
		s8 _d0;
		s8 _d1;
		u16 _d2;
		s8 _d4;
		u8 _pad5[2];
		s8 _d7;
		u16 _d8;
		u16 _da;
		s16 _dc;
		s16 _de;
		s8 _e0;
		u8 _e1;
		s16 _e2;
		s16 _e4;
		s16 _e6;
		s8 _e8;
		u8 _e9;
		s16 _ea;
	};

	BlendModelAnm blendModel;
	ModelAnm modelAnm;
	Model models[6];
	Elem elems[8];
	u8 _pad9e0[0x20];
	Sub sub;
	ActiveCollider collider1;
	ActiveCollider collider2;
	CollisionManager collisionMgr;

	static void *create();
	inline Object131() {};
	inline ~Object131() {};

	s32 onCreate();
	s32 onDestroy();
	s32 onRender();
	void pendingDestroy();
	bool onHeapCreated();
	virtual bool onUpdate_0();
	virtual bool _01();
	virtual void _11();
	virtual void _23();
	virtual void _31();
	virtual bool playerCollision(ActiveCollider *, ActiveCollider *);
	virtual void entityCollision();
	virtual void damagePlayer(ActiveCollider *, PlayerBase *);
};

extern ActorProfile Object131_Profile;

// MainProfileTable slot 132  |  ov013  |  profile @ 0x0213ba84
class Object132 : public StageEntity {
public:
	static void *create();
	inline Object132() {};
	inline ~Object132() {};
};

extern ActorProfile Object132_Profile;

// MainProfileTable slot 133  |  ov013  |  profile @ 0x0213ba90
class Object133 : public StageEntity {
public:
	static void *create();
	inline Object133() {};
	inline ~Object133() {};
};

extern ActorProfile Object133_Profile;
