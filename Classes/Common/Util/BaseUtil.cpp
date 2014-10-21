#include "BaseUtil.h"

namespace TexaPoker{
	namespace BaseUtil{
		int BaseUtil::genRand(float x, float y)
		{
			return  x + std::rand() % (int)(y - x);
		}
	}}