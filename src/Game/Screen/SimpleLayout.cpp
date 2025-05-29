#include "Game/Screen/SimpleLayout.hpp"
#include "Game/Util/ObjUtil.hpp"

SimpleLayout::SimpleLayout(const char *pName, const char *pLayoutName, u32 a3, int a4) :
    LayoutActor(pName, true)
{
    int v1 = a4 >= 0 ? a4 : 60;

    MR::connectToScene(this, 14, 13, -1, v1);
    initLayoutManager(pLayoutName, a3);
}

SimpleEffectLayout::SimpleEffectLayout(const char *pName, const char *pLayoutName, u32 a3, int a4) :
    SimpleLayout(pName, pLayoutName, a3, a4)
{
    initEffectKeeper(0, nullptr, nullptr);
}
