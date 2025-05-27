#pragma  once

#include "Game/MapObj/MapObjActor.hpp"
class PeachCastleGardenPlanet : public MapObjActor {
public:
    PeachCastleGardenPlanet(const char *);

    virtual ~PeachCastleGardenPlanet();
    virtual void init(const JMapInfoIter &);
    virtual void connectToScene(const MapObjActorInitInfo &);
    virtual void initCaseUseSwitchA(const MapObjActorInitInfo &);
    
    void startDamage();
    void exeWait();
    void exeDamage();

    u32 _C4;
};
