#pragma once

#include <revolution.h>

class JMapInfoIter;
class LiveActor;
class NameObj;

namespace MR {
    s32 getPlayerLeft();
    void incPlayerLeft();
    void decPlayerLeft();
    bool isLuigiLeftSupply();
    void incPlayerGameOverNum();
    bool isAnyPlayerLeftSupply();
    void offAllPlayerLeftSupply();
    s32 getStarPieceNum();
    void addStarPiece(int);
    s32 getStockedStarPieceNum();
    void addStockedStarPiece(int);
    bool isPlayerLuigi();
    void explainEnableToSpin(LiveActor*);
    void onGameEventFlagBeeMarioAtFirst();
    void onGameEventFlagTeresaMarioAtFirst();
    void onGameEventFlagHopperMarioAtFirst();
    void onGameEventFlagFireMarioAtFirst();
    void onGameEventFlagIceMarioAtFirst();
    void onGameEventFlagFlyingMarioAtFirst();
    void onGameEventFlagInvincibleMarioAtFirst();
    void onGameEventFlagLifeUpAtFirst();
    void onGameEventFlagOneUpAtFirst();
    bool isOnGameEventFlagPlayMoviePrologueA();
    bool isOnGameEventFlagEndTicoGuideDemo();
    bool isOnGameEventFlagEndButlerDomeLecture();
    bool isOnGameEventFlagEndButlerGalaxyMoveLecture();
    bool isOnGameEventFlagEndButlerStarPieceLecture();
    bool isOnGameEventFlagBeeMarioAtFirst();
    bool isOnGameEventFlagTeresaMarioAtFirst();
    bool isOnGameEventFlagHopperMarioAtFirst();
    bool isOnGameEventFlagFireMarioAtFirst();
    bool isOnGameEventFlagIceMarioAtFirst();
    bool isOnGameEventFlagFlyingMarioAtFirst();
    bool isOnGameEventFlagSurfingTutorialAtFirst();
    bool isOnGameEventFlagTamakoroTutorialAtFirst();
    bool isOnGameEventFlagViewCompleteEnding();
    bool isOnGameEventFlagViewCompleteEndingMarioAndLuigi();
    bool isOnGameEventFlagOffAstroDomeGuidance();
    bool isOnGameEventFlagChildsRoom();
    bool isOnGameEventFlagLibraryRoom();
    bool isOnGameEventFlagRosettaTalkAboutTicoInTower();
    bool isRosettaTalkTorchProgress();
    bool isRosettaTalkCountDownStart();
    bool isRosettaTalkAstroDomeRecover();
    bool isRosettaTalkKoopa();
    bool isRosettaTalkTorchLecture();
    bool isKinopioExplorerCompleteTrickComet();
    bool isKinopioExplorerTalkGoFinalBattle();
    bool isKinopioExplorerTalkGetGrandStar6();
    bool isKinopioExplorerTalkGetGrandStar5();
    bool isKinopioExplorerTalkGetGrandStar4();
    bool isKinopioExplorerTalkGetGrandStar3();
    bool isKinopioExplorerTrickComet();
    bool isKinopioExplorerTalkGetGrandStar2();
    bool isUFOKinokoBeforeConstruction();
    bool isUFOKinokoUnderConstruction();
    bool isButlerMapAppear();
    s32 setupAlreadyDoneFlag(const char*, const JMapInfoIter&, u32*);
    void updateAlreadyDoneFlag(int, u32);
    bool isOnGameEventFlagGalaxyOpen(const char*);
    bool isAlreadyVisitedCurrentStageAndScenario();
    bool isAlreadyVisitedStage(const char*);
    bool canOpenGalaxy(const char*);
    bool isAppearGalaxy(const char*);
    bool isGalaxyAppearGreenDriver(const char*);
    void onGameEventFlagGalaxyOpen(const char*);
    bool hasPowerStarInCurrentStage(s32);
    bool isPowerStarGreenInCurrentStage(s32);
    bool isPowerStarRedInCurrentStage(s32);
    bool isGrandStarInCurrentStage(s32);
    bool hasPowerStarInCurrentStageWithDeclarer(const char*, s32);
    bool isPowerStarGreenInCurrentStageWithDeclarer(const char*, s32);
    bool isPowerStarRedInCurrentStageWithDeclarer(const char*, s32);
    bool isGrandStarInCurrentStageWithDeclarer(const char*, s32);
    bool hasPowerStarAtResultSequence();
    bool isPowerStarGreenAtResultSequence();
    bool isPowerStarRedAtResultSequence();
    void sendStageResultSequenceParam(s32);
    bool isOnGameEventFlagPowerStarSuccess(const char*, s32);
    bool hasGrandStar(int);
    s32 calcOpenedAstroDomeNum();
    s32 calcCurrentGreenStarNum();
    s32 getPowerStarNumToOpenGalaxy(const char*);
    s32 getPowerStarNumSucceed(const char*);
    bool isPowerStarGreen(const char*, s32);
    s32 getPictureBookChapterCanRead();
    s32 getPictureBookChapterAlreadyRead();
    void setPictureBookChapterAlreadyRead(int);
    void setRaceBestTime(int, u32);
    u32 getRaceBestTime(int);
    u32 getRaceCurrentTime();
    void setWarpPodPathFlag(int, bool);
    s32 registerStorageSpinDriverPathDrawRange(const NameObj*, const JMapInfoIter&, int, f32*);
    void updateStorageSpinDriverPathDrawRange(int, f32);
    s32 getStarPieceNumGivingToTicoSeed(int);
    void addStarPieceGivingToTicoSeed(int, int);
    s32 getStarPieceNumGivingToTicoGalaxy(int);
    s32 getStarPieceNumMaxGivingToTicoGalaxy(int);
    void addStarPieceGivingToTicoGalaxy(int, int);
    void setTicoGalaxyAlreadyTalk(int, bool);
    bool isGalaxyAnyCometAppearInCurrentStage();
    void startGalaxyCometEvent();
    void endGalaxyCometEvent();
    s32 getGalaxyCometStateIndexInCurrentStage();
    void forceToNextStateGalaxyCometScheduler();
    bool isGalaxyCometLandInStage(const char*);
    s32 getEncounterGalaxyCometPowerStarId(const char*);
    bool isGalaxyPurpleCometLaunch();
    bool canAppearNormalComet(const char*);
    bool canAppearCoin100Comet(const char*);
    int getEncounterGalaxyCometNameId(const char*);
    int getCometNameIdFromString(const char*);
    const char* getCometNameFromId(int);
    bool isStarComplete(const char*);
    bool isStarCompleteNormalScenario(const char*);
    s32 getCoinBestScore(const char*, s32);
    s32 getCoinBestScore(const char*);
    bool isPlacedCoin(const char*, s32);
    bool isActiveLuigiHideAndSeekEvent();
    bool isEndLuigiHideAndSeekEvent();
    bool isLuigiDisappearFromAstroGalaxy();
    bool isOnGameEventFlagLuigiRescued();
    void onGameEventFlagTalkedToLuigiAfterRescued();
    void onGameEventFlagGetLuigiLetter();
    bool isOnLuigiHiding();
    bool isOnLuigiHidingCurrentStage();
    bool isLuigiDisappearFromAstroGalaxyOrHiding();
    bool isLuigiLetterArrivalAtMessenger();
    bool isLuigiHidingGalaxyAndScenario(const char*, s32);
    bool isPowerStarGetDemoWithLuigiCurrentGalaxy();
    bool isPowerStarGetDemoWithLuigiCurrentGalaxyAndScenario(s32);
    const char* getLuigiLetterGalaxyName();
    const char* getLuigiLetterGalaxyNameForNPC();
    void onMessageAlreadyRead(s8);
    void offMsgLedPattern();
    bool isMsgLedPattern();
    void explainBeeMarioIfAtFirst();
    void explainTeresaMarioIfAtFirst();
    void explainHopperMarioIfAtFirst();
    void explainFireMarioIfAtFirst();
    void explainIceMarioIfAtFirst();
    void explainFlyingMarioIfAtFirst();
    void explainInvincibleMarioIfAtFirst();
    void explainLifeUpIfAtFirst();
    void explainOneUpIfAtFirst();
    void onGameEventFlagPlayMoviePrologueA();
    void onGameEventFlagPlayMoviePrologueB();
    void onGameEventFlagEndTicoGuideDemo();
    void onGameEventFlagEnableToSpinAndStarPointer();
    void onGameEventFlagEndButlerDomeLecture();
    void onGameEventFlagEndButlerGalaxyMoveLecture();
    void onGameEventFlagEndButlerStarPieceLecture();
    void onGameEventFlagSurfingTutorialAtFirst();
    void onGameEventFlagTamakoroTutorialAtFirst();
    void onGameEventFlagRosettaTalkAboutTicoInTower();
    void onGameEventFlagViewNormalEnding();
    void onGameEventFlagViewCompleteEnding();
    bool isOnGameEventFlagUseAstroDome();
    bool isOnGameEventFlagGreenDriver();
    bool isOnGameEventFlagRedDriver();
    bool isOnGameEventFlagViewNormalEnding();
    bool isRosettaTalkTrickComet();
    bool isKinopioExplorerStartMessenger();
    bool isKinopioExplorerOrganize();
    bool isKinopioExplorerRescued();
    s32 getPowerStarLeftToDisplayCountDownPlate();
    bool isOnWarpPodPathFlag(int);
    bool isOnTicoGalaxyAlreadyTalk(int);
    bool isKoopaFortressAppearInGalaxy();
    bool isGalaxyRedCometAppearInCurrentStage();
    bool isGalaxyDarkCometAppearInCurrentStage();
    bool isGalaxyGhostCometAppearInCurrentStage();
    bool isGalaxyQuickCometAppearInCurrentStage();
    bool isGalaxyBlackCometAppearInCurrentStage();
    bool isStarCompleteAllGalaxy();
    bool isStarPieceCounterStop();
    bool isOnGameEventFlagAstroGalaxyBgmBright();
    bool isOnMessageAlreadyRead(s8);
    void onMessageAlreadyRead(s8);

    bool isGalaxyCometLandInStage(const char *);

    int getEncounterGalaxyCometNameId(const char *);

    const char* getCometNameFromId(int);

    s32 getEncounterGalaxyCometPowerStarId(const char *);

    s32 getPowerStarLeftToDisplayCountDownPlate();

    bool isOnGameEventFlagViewNormalEnding();
    bool isButlerMapAppear();

    bool isAlreadyVisitedStage(const char *);

    bool isOnGameEventFlagPlayMoviePrologueA();

    void onGameEventFlagPlayMoviePrologueA();
    void onGameEventFlagPlayMoviePrologueB();

    bool isAlreadyVisitedCurrentStageAndScenario();

    void endGalaxyCometEvent();

    bool isGalaxyAnyCometAppearInCurrentStage();

    void incPlayerGameOverNum();

    s32 calcCurrentGreenStarNum();

    void forceToNextStateGalaxyCometScheduler();

    bool isAppearGalaxy(const char *);
};
