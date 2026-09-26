#include "Object20.hpp"

// Node of the linked zone list walked by func_ov054_02168bac
struct Object20Zone {
	u16 index;
	u16 minX;
	u16 minY;
	u8 _6[6];
};

// Row of the global zone table; only the flag word is consulted
struct Object20ZoneTbl {
	u8 _0[0x10];
	u16 flags;
	u8 _12[2];
};

// Partial view of a player actor: only the members func_ov054_02168418 reads
struct Object20Player {
	u8 _0[0x5c];
	Vec3_32 position;
	u8 _6c[0xb2];
	i8 linkedPlayer;
	u8 _11f[0x12d];
	u32 _24c;
	u8 _250[0x528];
	u32 _778;
	u8 _77c[0x30];
	s8 powerup;
};

extern "C" {
	extern volatile u8 data_ov000_020ca2a4[];
	extern u8 *data_020887f0;
	extern u32 data_0208af3c[2];

	extern Object20Zone *data_0208b168[8];
	extern u8 data_ov000_020ca3cc[];
	extern Object20ZoneTbl data_ov000_020c529c[];

	extern Object20Event data_ov054_0217262c;
	extern Object20Event data_ov054_02172634;
	extern Object20Event data_ov054_0217263c;
	extern Object20Event data_ov054_02172644;
	extern Object20Event data_ov054_0217264c;
	extern Object20Event data_ov054_02172654;
	extern Object20Event data_ov054_0217265c;

	void func_0201eef8(u32, FxRect *);
	Object20Player *func_020205ec();

	extern u16 data_ov054_0216c43c[];
	extern s16 data_0208b350[];

	bool func_ov054_0216821c(Object20 *, u32, u32);
	bool func_ov054_02168418(Object20 *, u32);
	bool func_ov054_02168bac(Object20 *);
	bool func_ov054_02168c80(Object20 *, u32);
	bool func_ov054_02168e80(Object20 *, u32);
	bool func_ov054_02169014(Object20 *, u32);
}

extern "C" {

bool func_ov054_0216821c(Object20 *self, u32 unused1, u32 unused2) {
	if (self->_41a == 0) {
		self->_41a++;
		self->_412 = 0;
	} else if (self->_41a != -1) {
		if (self->_40c != 0) {
			self->_40c--;
		}
		if (self->_412 == 0) {
			if ((*(u64 *)data_0208af3c & ((u64)1 << self->_419)) != 0) {
				self->_412 = 1;
				self->_40c = self->_40e;
				self->_413 = self->_419 + 1;
			}
		} else if (self->_412 == 1) {
			if (self->_40c == 0) {
				self->_40c = self->_40e;
				self->setTimedEvent(self->_413, 0, true, false, false);
				self->_413++;
				if (self->_413 > self->_414) {
					if (self->_416 != 0) {
						self->_412 = 2;
					} else {
						self->Base::destroy();
					}
				}
			}
		} else if (self->_412 == 2) {
			if ((*(u64 *)data_0208af3c & ((u64)1 << self->_419)) == 0) {
				self->_412 = 3;
				self->_40c = self->_40e;
				self->_413 = self->_419 + 1;
			}
		} else {
			if (self->_40c == 0) {
				self->_40c = self->_40e;
				self->setTimedEvent(self->_413, 0, false, false, false);
				self->_413++;
				if (self->_413 > self->_414) {
					self->_412 = 0;
				}
			}
		}
	}
	return true;
}

bool func_ov054_02168418(Object20 *self, u32 unused) {
	FxRect rect;

	if (self->_41a == 0) {
		self->_41a++;
	} else if (self->_41a != -1) {
		u8 flags = 0;
		fx32 right, bottom;
		u32 shift, lo, hi;

		if (self->_415 == 0xff) {
			flags |= 1;
		} else {
			func_0201eef8(self->_415, &rect);
			right = rect.x + rect.halfWidth;
			bottom = rect.y - rect.halfHeight;

			if (self->_419 != 0) {
				u8 id = self->_419 - 1;
				if (func_020202a0() == 2) {
					Object20Player *p0 = (Object20Player *)Game::getPlayer(0);
					Object20Player *p1 = (Object20Player *)Game::getPlayer(1);
					if (id == p0->linkedPlayer || id == p1->linkedPlayer) {
						Object20Player *p = p0;
						if (id == p1->linkedPlayer) {
							p = p1;
						}
						Vec3_32 *pos = &p->position;
						if (rect.x <= pos->x && pos->x <= right && rect.y >= pos->y && pos->y >= bottom) {
							flags |= 1;
						}
					}
				} else {
					Object20Player *p = func_020205ec();
					if (id == p->linkedPlayer) {
						Vec3_32 *pos = &p->position;
						if (rect.x <= pos->x && pos->x <= right && rect.y >= pos->y && pos->y >= bottom) {
							flags |= 1;
						}
					}
				}
			} else {
				if (func_020202a0() == 2) {
					Object20Player *p0 = (Object20Player *)Game::getPlayer(0);
					Object20Player *p1 = (Object20Player *)Game::getPlayer(1);
					Vec3_32 *pos0 = &p0->position;
					if (rect.x <= pos0->x && pos0->x <= right && rect.y >= pos0->y && pos0->y >= bottom) {
						flags |= 1;
					}
					Vec3_32 *pos1 = &p1->position;
					if (rect.x <= pos1->x && pos1->x <= right && rect.y >= pos1->y && pos1->y >= bottom) {
						flags |= 1;
					}
				} else {
					Object20Player *p = func_020205ec();
					Vec3_32 *pos = &p->position;
					if (rect.x <= pos->x && pos->x <= right && rect.y >= pos->y && pos->y >= bottom) {
						flags |= 1;
					}
				}
			}
		}

		if (self->_416 == 0xff) {
			flags |= 2;
		} else {
			if (func_ov054_02168bac(self)) {
				flags |= 2;
			}
		}

		if (self->_417 == 0) {
			flags |= 4;
		} else {
			if (self->_419 != 0) {
				u8 id = self->_419 - 1;
				if (func_020202a0() == 2) {
					Object20Player *p0 = (Object20Player *)Game::getPlayer(0);
					Object20Player *p1 = (Object20Player *)Game::getPlayer(1);
					if (id == p0->linkedPlayer || id == p1->linkedPlayer) {
						Object20Player *p = p0;
						if (id == p1->linkedPlayer) {
							p = p1;
						}
						if (data_ov054_0216c43c[self->_417 - 1] == p->powerup) {
							flags |= 4;
						}
					}
				} else {
					Object20Player *p = func_020205ec();
					if (self->_417 < 7) {
						if (id == p->linkedPlayer) {
							if (data_ov054_0216c43c[self->_417 - 1] == p->powerup) {
								flags |= 4;
							}
						}
					} else {
						if (data_0208b350[p->linkedPlayer] != 0) {
							flags |= 4;
						}
					}
				}
			} else {
				if (func_020202a0() == 2) {
					Object20Player *p0 = (Object20Player *)Game::getPlayer(0);
					Object20Player *p1 = (Object20Player *)Game::getPlayer(1);
					if (data_ov054_0216c43c[self->_417 - 1] == p0->powerup) {
						flags |= 4;
					}
					if (data_ov054_0216c43c[self->_417 - 1] == p1->powerup) {
						flags |= 4;
					}
				} else {
					Object20Player *p = func_020205ec();
					if (self->_417 < 7) {
						if (data_ov054_0216c43c[self->_417 - 1] == p->powerup) {
							flags |= 4;
						}
					} else {
						if (data_0208b350[p->linkedPlayer] != 0) {
							flags |= 4;
						}
					}
				}
			}
		}

		if (self->_418 == 0) {
			flags |= 8;
		} else {
			if (self->_419 != 0) {
				u8 id = self->_419 - 1;
				if (func_020202a0() == 2) {
					Object20Player *p0 = (Object20Player *)Game::getPlayer(0);
					Object20Player *p1 = (Object20Player *)Game::getPlayer(1);
					if (id == p0->linkedPlayer || id == p1->linkedPlayer) {
						Object20Player *p = p0;
						if (id == p1->linkedPlayer) {
							p = p1;
						}
						if (self->_418 == 1) {
							if (p->_24c & 0x1f40) {
								flags |= 8;
							}
						} else if (self->_418 == 2) {
							if (!(p->_24c & 0x1f40)) {
								flags |= 8;
							}
						} else if (self->_418 == 3) {
							if (p->_778 & 0x10000) {
								flags |= 8;
							}
						}
					}
				} else {
					Object20Player *p = func_020205ec();
					if (id == p->linkedPlayer) {
						if (self->_418 == 1) {
							if (p->_24c & 0x1f40) {
								flags |= 8;
							}
						} else if (self->_418 == 2) {
							if (!(p->_24c & 0x1f40)) {
								flags |= 8;
							}
						} else if (self->_418 == 3) {
							if (p->_778 & 0x10000) {
								flags |= 8;
							}
						}
					}
				}
			} else {
				if (func_020202a0() == 2) {
					Object20Player *p0 = (Object20Player *)Game::getPlayer(0);
					Object20Player *p1 = (Object20Player *)Game::getPlayer(1);
					if (self->_418 == 1) {
						if (p0->_24c & 0x1f40) {
							flags |= 8;
						}
						if (p1->_24c & 0x1f40) {
							flags |= 8;
						}
					} else if (self->_418 == 2) {
						if (!(p0->_24c & 0x1f40)) {
							flags |= 8;
						}
						if (!(p1->_24c & 0x1f40)) {
							flags |= 8;
						}
					} else if (self->_418 == 3) {
						if (p0->_778 & 0x10000) {
							flags |= 8;
						}
						if (p1->_778 & 0x10000) {
							flags |= 8;
						}
					}
				} else {
					Object20Player *p = func_020205ec();
					if (self->_418 == 1) {
						if (p->_24c & 0x1f40) {
							flags |= 8;
						}
					} else if (self->_418 == 2) {
						if (!(p->_24c & 0x1f40)) {
							flags |= 8;
						}
					} else if (self->_418 == 3) {
						if (p->_778 & 0x10000) {
							flags |= 8;
						}
					}
				}
			}
		}

		shift = (self->_408 >> 4) & 0xf;
		lo = *(u32 *)((u8 *)self + 0x3f8) & data_0208af3c[0];
		hi = *(u32 *)((u8 *)self + 0x3fc) & data_0208af3c[1];

		if (flags == 0xf) {
			u8 fired = 0;
			if (self->_408 & 1) {
				if (hi != 0 || lo != 0) {
					self->setTimedEvent(self->_414, 0, false, false, false);
					fired++;
				}
			} else {
				if (hi == 0 && lo == 0) {
					self->setTimedEvent(self->_414, 0, true, false, false);
					fired++;
				}
			}
			if (!shift && fired) {
				self->Base::destroy();
			}
		} else if (shift == 2) {
			if (self->_408 & 1) {
				if (hi == 0 && lo == 0) {
					self->setTimedEvent(self->_414, 0, true, false, false);
				}
			} else {
				if (hi != 0 || lo != 0) {
					self->setTimedEvent(self->_414, 0, false, false, false);
				}
			}
		}
	}
	return true;
}

bool func_ov054_021692f4(Object20 *self, Object20Event *event) {
	if (self->_14 != event) {
		if (self->_14) {
			self->_41a = -1;
			Object20Event *old = (Object20Event *)self->_14;
			s32 tag = old->_4;
			u8 *base = (u8 *)self + (tag >> 1);
			u32 fn = tag & 1 ? *(u32 *)((u8 *)*(u32 **)base + old->_0) : old->_0;
			((void (*)(void))fn)();
		}
		self->_14 = event;
		self->_41a = 0;
		Object20Event *cur = (Object20Event *)self->_14;
		s32 tag = cur->_4;
		u8 *base = (u8 *)self + (tag >> 1);
		u32 fn = tag & 1 ? *(u32 *)((u8 *)*(u32 **)base + cur->_0) : cur->_0;
		((void (*)(void))fn)();
	}
	return true;
}

void func_ov054_02167be4(Object20 *self) {
	if (func_020202a0() == 1) {
		u8 owner = ((StageActor *)Game::getPlayer(*data_020887f0))->_2be;
		if (owner == self->_2be) {
			return;
		}
		self->destroy(false);
	} else {
		u8 owner0 = ((StageActor *)Game::getPlayer(0))->_2be;
		u8 owner1 = ((StageActor *)Game::getPlayer(1))->_2be;
		if (owner0 == self->_2be) {
			return;
		}
		if (owner1 == self->_2be) {
			return;
		}
		self->destroy(false);
	}
}

bool func_ov054_0216914c(Object20 *self) {
	if (self->_41a == 0) {
		self->_41a++;
	} else if (self->_41a != -1) {
		u32 shift = (self->_408 >> 4) & 0xf;
		u32 oldLo = self->_3f8;
		u32 oldHi = *(u32 *)((u8 *)self + 0x3fc);
		u32 lo = oldLo & data_0208af3c[0];
		u32 hi = oldHi & data_0208af3c[1];

		if (hi == oldHi && lo == oldLo) {
			u32 curHi = self->_404;
			u32 curLo = self->_400;
			if (curHi == hi && curLo == lo) {
				return true;
			}
			self->_400 = lo;
			self->_404 = hi;
			if (self->_408 & 1) {
				self->setTimedEvent(self->_414, 0, false, false, false);
			} else {
				self->setTimedEvent(self->_414, 0, true, false, false);
			}
			if (!shift) {
				self->Base::destroy();
			}
		} else {
			if (shift == 2) {
				u32 curHi = self->_404;
				u32 curLo = self->_400;
				if (curHi != hi || curLo != lo) {
					if (self->_408 & 1) {
						self->setTimedEvent(self->_414, 0, true, false, false);
					} else {
						self->setTimedEvent(self->_414, 0, false, false, false);
					}
				}
			}
			self->_400 = lo;
			self->_404 = hi;
		}
	}
	return true;
}

void func_ov054_021692ac(Object20 *self) {
	if (self->_14 == 0) {
		func_ov054_021692f4(self, (Object20Event *)&data_ov054_02172644);
	}
	Object20Event *cur = (Object20Event *)self->_14;
	s32 tag = cur->_4;
	u8 *base = (u8 *)self + (tag >> 1);
	u32 fn = tag & 1 ? *(u32 *)((u8 *)*(u32 **)base + cur->_0) : cur->_0;
	((void (*)(void))fn)();
}

bool func_ov054_02169290(Object20 *self) {
	if (self->_41a == 0) {
		self->_41a++;
	}
	return true;
}

bool func_ov054_02168bac(Object20 *self) {
	FxRect rect;
	Object20Zone *zone = data_0208b168[6];
	u8 *flags = data_ov000_020ca3cc;
	fx32 right, bottom, x, y;

	func_0201eef8(self->_416, &rect);
	x = rect.x;
	right = x + rect.halfWidth;
	y = rect.y;
	bottom = y - rect.halfHeight;

	while (zone->index != 0xffff) {
		fx32 minX = (fx32)zone->minX << 16;
		fx32 minY = -(fx32)((u32)zone->minY << 16);
		if ((data_ov000_020c529c[zone->index].flags & 0x2000) == 0
		    && x <= minX && minX <= right && y >= minY && minY >= bottom) {
			if ((*flags & 8) == 0) {
				return false;
			}
		}
		zone++;
		flags++;
	}
	return true;
}

bool func_ov054_02169014(Object20 *self, u32 unused) {
	if (self->_41a == 0) {
		self->_41a++;
	} else if (self->_41a != -1) {
		u32 shift = (self->_408 >> 4) & 0xf;
		u32 lo = *(u32 *)((u8 *)self + 0x3f8) & data_0208af3c[0];
		u32 hi = *(u32 *)((u8 *)self + 0x3fc) & data_0208af3c[1];

		if (hi != 0 || lo != 0) {
			u32 curHi = self->_404;
			u32 curLo = self->_400;
			if (curHi != hi || curLo != lo) {
				self->_400 = lo;
				self->_404 = hi;
				if (self->_408 & 1) {
					self->setTimedEvent(self->_414, 0, false, false, false);
				} else {
					self->setTimedEvent(self->_414, 0, true, false, false);
				}
				if (!shift) {
					self->Base::destroy();
				}
			}
		} else {
			if (shift == 2) {
				u32 curHi = self->_404;
				u32 curLo = self->_400;
				if (curHi != hi || curLo != lo) {
					if (self->_408 & 1) {
						self->setTimedEvent(self->_414, 0, true, false, false);
					} else {
						self->setTimedEvent(self->_414, 0, false, false, false);
					}
				}
			}
			self->_400 = lo;
			self->_404 = hi;
		}
	}
	return true;
}

bool func_ov054_02168e80(Object20 *self, u32 unused) {
	if (self->_41a == 0) {
		self->_41a++;
	} else if (self->_41a != -1) {
		u32 n = self->_414;
		u32 hi = *(u32 *)((u8 *)self + 0x3fc) & data_0208af3c[1];
		u32 lo = *(u32 *)((u8 *)self + 0x3f8) & data_0208af3c[0];
		u32 shift = (self->_408 >> 4) & 0xf;

		if ((*(u64 *)data_0208af3c & ((u64)1 << n)) != 0) {
			u32 curHi = self->_404;
			u32 curLo = self->_400;
			if (curHi != hi || curLo != lo) {
				u8 slots[4];
				u8 slot;
				u8 pick;
				u32 sel;

				self->_400 = lo;
				self->_404 = hi;
				sel = (self->random() >> 16) & 3;
				slots[0] = self->_415;
				slots[1] = self->_416;
				slots[2] = self->_417;
				slots[3] = self->_418;
				for (u8 i = 0; i < 4; i++) {
					if (slots[i] != 0xff) {
						slot = slots[i];
					}
				}
				pick = self->_415;
				if (sel == 1) {
					pick = self->_416;
				} else if (sel == 2) {
					pick = self->_417;
				} else if (sel == 3) {
					pick = self->_418;
				}
				if (pick != 0xff) {
					slot = pick;
				}
				if (self->_408 & 1) {
					self->setTimedEvent(slot, 0, false, false, false);
				} else {
					self->setTimedEvent(slot, 0, true, false, false);
				}
				if (!shift) {
					self->Base::destroy();
				}
			}
		} else {
			self->_400 = lo;
			self->_404 = hi;
		}
	}
	return true;
}

bool func_ov054_02168c80(Object20 *self, u32 unused) {
	if (self->_41a == 0) {
		self->_41a++;
	} else if (self->_41a != -1) {
		bool inv = self->_416 ^ 1;
		u32 shift = (self->_408 >> 4) & 0xf;
		u32 lo = *(u32 *)((u8 *)self + 0x3f8) & data_0208af3c[0];
		u32 hi = *(u32 *)((u8 *)self + 0x3fc) & data_0208af3c[1];
		bool hit;

		if (self->_417 == 0) {
			hit = (*(u64 *)data_0208af3c & ((u64)1 << self->_415)) != 0;
		} else {
			hit = (*(u64 *)data_0208af3c & ((u64)1 << self->_415)) == 0;
		}

		if (hit) {
			u32 curHi = self->_404;
			u32 curLo = self->_400;
			if (curHi != hi || curLo != lo) {
				self->_400 = lo;
				self->_404 = hi;
				if (self->_408 & 1) {
					self->setTimedEvent(self->_414, self->_40c & 0xff, false, false, inv);
				} else {
					self->setTimedEvent(self->_414, self->_40c & 0xff, true, false, inv);
				}
				if (!shift) {
					self->Base::destroy();
				}
			}
		} else {
			if (shift == 2) {
				u32 curHi = self->_404;
				u32 curLo = self->_400;
				if (curHi != hi || curLo != lo) {
					if (self->_408 & 1) {
						self->setTimedEvent(self->_414, self->_40c & 0xff, true, false, inv);
					} else {
						self->setTimedEvent(self->_414, self->_40c & 0xff, false, false, inv);
					}
				}
			}
			self->_400 = lo;
			self->_404 = hi;
		}
	}
	return true;
}

}

s32 Object20::onCreate() {
	u16 id = this->object_id;

	this->_408 = this->settings;
	this->_3f8 = 0;
	this->_400 = 0;
	this->_404 = 0;
	this->_414 = data_ov000_020ca2a4[0] - 1;
	this->collisionType = 1;

	if (id == 0x89) {
		u8 n = data_ov000_020ca2a4[1];
		if (n) {
			this->_3f8 |= (u64)1 << (n - 1);
		}
		n = (this->_408 >> 24) & 0xff;
		if (n) {
			this->_3f8 |= (u64)1 << (n - 1);
		}
		n = (this->_408 >> 16) & 0xff;
		if (n) {
			this->_3f8 |= (u64)1 << (n - 1);
		}
		n = (this->_408 >> 8) & 0xff;
		if (n) {
			this->_3f8 |= (u64)1 << (n - 1);
		}
		func_ov054_021692f4(this, (Object20Event *)&data_ov054_02172634);
	} else if (id == 0x8a) {
		u8 n = data_ov000_020ca2a4[1];
		if (n) {
			this->_3f8 |= (u64)1 << (n - 1);
		}
		n = (this->_408 >> 24) & 0xff;
		if (n) {
			this->_3f8 |= (u64)1 << (n - 1);
		}
		n = (this->_408 >> 16) & 0xff;
		if (n) {
			this->_3f8 |= (u64)1 << (n - 1);
		}
		n = (this->_408 >> 8) & 0xff;
		if (n) {
			this->_3f8 |= (u64)1 << (n - 1);
		}
		func_ov054_021692f4(this, (Object20Event *)&data_ov054_0217263c);
	} else if (id == 0x8b) {
		u8 n;
		this->_418 = 0xff;
		this->_417 = this->_418;
		this->_416 = this->_417;
		this->_415 = this->_416;
		n = data_ov000_020ca2a4[1];
		if (n) {
			this->_415 = n - 1;
		}
		n = (this->_408 >> 24) & 0xff;
		if (n) {
			this->_416 = n - 1;
		}
		n = (this->_408 >> 16) & 0xff;
		if (n) {
			this->_417 = n - 1;
		}
		n = (this->_408 >> 8) & 0xff;
		if (n) {
			this->_418 = n - 1;
		}
		this->_3f8 |= (u64)1 << this->_414;
		func_ov054_021692f4(this, (Object20Event *)&data_ov054_0217262c);
	} else if (id == 0x8c) {
		this->_40c = (this->_408 >> 24) & 0xff;
		this->_417 = (this->_408 >> 16) & 0xf;
		this->_416 = (this->_408 >> 20) & 0xf;
		this->_415 = data_ov000_020ca2a4[1] - 1;
		this->_3f8 |= (u64)1 << this->_415;
		func_ov054_021692f4(this, (Object20Event *)&data_ov054_0217265c);
	} else if (id == 0x8d) {
		this->_419 = data_ov000_020ca2a4[1];
		this->_415 = this->_408 >> 24;
		this->_416 = this->_408 >> 16;
		this->_417 = (this->_408 >> 12) & 0xf;
		this->_418 = (this->_408 >> 8) & 0xf;
		this->_3f8 |= (u64)1 << this->_414;
		func_ov054_021692f4(this, (Object20Event *)&data_ov054_02172654);
	} else if (id == 0x8e) {
		this->_419 = data_ov000_020ca2a4[1] - 1;
		this->_415 = this->_408 >> 24;
		this->_413 = this->_419;
		this->_416 = (this->_408 >> 4) & 0xf;
		this->_40e = this->_415 * 10;
		func_ov054_021692f4(this, (Object20Event *)&data_ov054_0217264c);
	} else {
		u8 value = 0;
		bool enable = false;
		if (!(this->_408 & 1)) {
			if (this->_408 & 0x10) {
				value = (this->settings >> 24) & 0xff;
				enable = true;
			}
			u8 n = data_ov000_020ca2a4[0];
			if (n) {
				this->setTimedEvent((u8)(n - 1), value, enable, false, false);
			}
			n = data_ov000_020ca2a4[1];
			if (n) {
				this->setTimedEvent((u8)(n - 1), value, enable, false, false);
			}
		}
		this->Base::destroy();
	}

	return 1;
}

s32 Object20::onDestroy() {
	return true;
}

bool Object20::onUpdate_0() {
	func_ov054_021692ac(this);
	func_ov054_02167be4(this);
	return true;
}

void Object20::pendingDestroy() {

}

void *Object20::create()
{
	return new Object20();
}

void *Object137::create()
{
	return new Object137();
}

void *Object138::create()
{
	return new Object138();
}

void *Object139::create()
{
	return new Object139();
}

void *Object140::create()
{
	return new Object140();
}

void *Object141::create()
{
	return new Object141();
}

void *Object142::create()
{
	return new Object142();
}

// 0x02170820
ActorProfile Object20_Profile = { Object20::create, 20, 27, NULL };

// 0x0217082c
ActorProfile Object137_Profile = { Object137::create, 137, 113, NULL };

// 0x021707f0
ActorProfile Object138_Profile = { Object138::create, 138, 114, NULL };

// 0x021707fc
ActorProfile Object139_Profile = { Object139::create, 139, 115, NULL };

// 0x02170814
ActorProfile Object140_Profile = { Object140::create, 140, 116, NULL };

// 0x02170838
ActorProfile Object141_Profile = { Object141::create, 141, 117, NULL };

// 0x02170808
ActorProfile Object142_Profile = { Object142::create, 142, 118, NULL };

