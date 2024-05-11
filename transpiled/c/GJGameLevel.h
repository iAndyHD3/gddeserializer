// Generated automatically with "fut". Do not edit.
#pragma once
#include <glib.h>
#include <stdbool.h>
#ifdef __cplusplus
extern "C" {
#endif
typedef struct gddGJGameLevel gddGJGameLevel;

#define gddGJGameLevel_PROP_SETTINGS_STRING "48"

#define gddGJGameLevel_PROP_EDITOR_TIME2 "47"

#define gddGJGameLevel_PROP_EDITOR_TIME "46"

#define gddGJGameLevel_PROP_OBJECT_COUNT "45"

#define gddGJGameLevel_PROP_IS_GAUNTLET "44"

#define gddGJGameLevel_PROP_DEMON_DIFFICULTY "43"

#define gddGJGameLevel_PROP_EPIC "42"

#define gddGJGameLevel_PROP_DAILY_NUMBER "41"

#define gddGJGameLevel_PROP_LOW_DETAIL_MODE "40"

#define gddGJGameLevel_PROP_STARS_REQUESTED "39"

#define gddGJGameLevel_PROP_VERIFIED_COINS "38"

#define gddGJGameLevel_PROP_COINS "37"

#define gddGJGameLevel_PROP_EXTRA_STRING "36"

#define gddGJGameLevel_PROP_CUSTOM_SONG_ID "35"

#define gddGJGameLevel_PROP_TWO_PLAYER "31"

#define gddGJGameLevel_PROP_COPIED_ID "30"

#define gddGJGameLevel_PROP_UPDATE_DATE "29"

#define gddGJGameLevel_PROP_UPLOAD_DATE "28"

#define gddGJGameLevel_PROP_PASSWORD "27"

#define gddGJGameLevel_PROP_RECORD_STRING "26"

#define gddGJGameLevel_PROP_AUTO "25"

#define gddGJGameLevel_PROP_FEATURE_SCORE "19"

#define gddGJGameLevel_PROP_STARS "18"

#define gddGJGameLevel_PROP_IS_DEMON "17"

#define gddGJGameLevel_PROP_DISLIKES "16"

#define gddGJGameLevel_PROP_LENGTH "15"

#define gddGJGameLevel_PROP_LIKES "14"

#define gddGJGameLevel_PROP_GAME_VERSION "13"

#define gddGJGameLevel_PROP_OFFICIAL_SONG "12"

#define gddGJGameLevel_PROP_SET_COMPLETES "11"

#define gddGJGameLevel_PROP_DOWNLOADS "10"

#define gddGJGameLevel_PROP_DIFFICULTY_NUMERATOR "9"

#define gddGJGameLevel_PROP_DIFFICULTY_DENOMINATOR "8"

#define gddGJGameLevel_PROP_PLAYER_ID "6"

#define gddGJGameLevel_PROP_VERSION "5"

#define gddGJGameLevel_PROP_LEVEL_STRING "4"

#define gddGJGameLevel_PROP_DESCRIPTION "3"

#define gddGJGameLevel_PROP_LEVELNAME "2"

#define gddGJGameLevel_PROP_LEVEL_ID "1"

int gddGJGameLevel_tryParse(const char *str, int defaultVal);

int gddGJGameLevel_FindDelimiterIndex(const char *str, const char *delimiter, int startPos);

GArray *gddGJGameLevel_Split(const char *str, const char *delimiter);

void gddGJGameLevel_addFromObjectString(gddGJGameLevel *self, const char *response);

GArray *gddGJGameLevel_createFromGjlevels21Response(const char *response);

const char *gddGJGameLevel_getLevelName(const gddGJGameLevel *self);

gddGJGameLevel *gddGJGameLevel_setLevelname(gddGJGameLevel *self, const char *levelname);

const char *gddGJGameLevel_getLevelString(const gddGJGameLevel *self);

gddGJGameLevel *gddGJGameLevel_setLevelString(gddGJGameLevel *self, const char *levelDesc);

const char *gddGJGameLevel_getDescription(const gddGJGameLevel *self);

gddGJGameLevel *gddGJGameLevel_setDescription(gddGJGameLevel *self, const char *desc);

const char *gddGJGameLevel_getCreatorName(const gddGJGameLevel *self);

gddGJGameLevel *gddGJGameLevel_setCreatorname(gddGJGameLevel *self, const char *creatorname);

const char *gddGJGameLevel_getUploadDate(const gddGJGameLevel *self);

gddGJGameLevel *gddGJGameLevel_setUploadDate(gddGJGameLevel *self, const char *uploadDate);

const char *gddGJGameLevel_getUpdateDate(const gddGJGameLevel *self);

gddGJGameLevel *gddGJGameLevel_setUpdateDate(gddGJGameLevel *self, const char *updateDate);

int gddGJGameLevel_getPlayerId(const gddGJGameLevel *self);

gddGJGameLevel *gddGJGameLevel_setPlayerId(gddGJGameLevel *self, int playerId);

int gddGJGameLevel_getAccountId(const gddGJGameLevel *self);

gddGJGameLevel *gddGJGameLevel_setAccountId(gddGJGameLevel *self, int accountId);

int gddGJGameLevel_getLevelId(const gddGJGameLevel *self);

gddGJGameLevel *gddGJGameLevel_setLevelId(gddGJGameLevel *self, int levelId);

int gddGJGameLevel_getSongId(const gddGJGameLevel *self);

gddGJGameLevel *gddGJGameLevel_setSongId(gddGJGameLevel *self, int songId);

int gddGJGameLevel_getLevelRev(const gddGJGameLevel *self);

gddGJGameLevel *gddGJGameLevel_setLevelRev(gddGJGameLevel *self, int levelRev);

int gddGJGameLevel_getObjectCount(const gddGJGameLevel *self);

gddGJGameLevel *gddGJGameLevel_setObjectCount(gddGJGameLevel *self, int objectCount);

int gddGJGameLevel_getDownloads(const gddGJGameLevel *self);

gddGJGameLevel *gddGJGameLevel_setDownloads(gddGJGameLevel *self, int downloads);

int gddGJGameLevel_getOfficialSong(const gddGJGameLevel *self);

gddGJGameLevel *gddGJGameLevel_setOfficialSong(gddGJGameLevel *self, int officialSong);

int gddGJGameLevel_getLikes(const gddGJGameLevel *self);

gddGJGameLevel *gddGJGameLevel_setLikes(gddGJGameLevel *self, int likes);

int gddGJGameLevel_getDislikes(const gddGJGameLevel *self);

gddGJGameLevel *gddGJGameLevel_setDislikes(gddGJGameLevel *self, int dislikes);

int gddGJGameLevel_getWorkingTime(const gddGJGameLevel *self);

gddGJGameLevel *gddGJGameLevel_setWorkingTime(gddGJGameLevel *self, int workingTime);

int gddGJGameLevel_getLevelVersion(const gddGJGameLevel *self);

gddGJGameLevel *gddGJGameLevel_setLevelVersion(gddGJGameLevel *self, int levelVersion);

int gddGJGameLevel_getGameVersion(const gddGJGameLevel *self);

gddGJGameLevel *gddGJGameLevel_setGameVersion(gddGJGameLevel *self, int gameVersion);

int gddGJGameLevel_getCoins(const gddGJGameLevel *self);

gddGJGameLevel *gddGJGameLevel_setCoins(gddGJGameLevel *self, int coins);

int gddGJGameLevel_getStars(const gddGJGameLevel *self);

gddGJGameLevel *gddGJGameLevel_setStars(gddGJGameLevel *self, int stars);

int gddGJGameLevel_getFeatureScore(const gddGJGameLevel *self);

gddGJGameLevel *gddGJGameLevel_setFeatureScore(gddGJGameLevel *self, int featureScore);

int gddGJGameLevel_getCopyPassword(const gddGJGameLevel *self);

gddGJGameLevel *gddGJGameLevel_setCopyPassword(gddGJGameLevel *self, int copyPassword);

int gddGJGameLevel_getOriginalLevelId(const gddGJGameLevel *self);

gddGJGameLevel *gddGJGameLevel_setOriginalLevelId(gddGJGameLevel *self, int originalLevelId);

int gddGJGameLevel_getStarsRequested(const gddGJGameLevel *self);

gddGJGameLevel *gddGJGameLevel_setStarsRequested(gddGJGameLevel *self, int starsRequested);

int gddGJGameLevel_getCopiedId(const gddGJGameLevel *self);

gddGJGameLevel *gddGJGameLevel_setCopiedId(gddGJGameLevel *self, int copiedId);

int gddGJGameLevel_getDailyWeeklyNumber(const gddGJGameLevel *self);

gddGJGameLevel *gddGJGameLevel_setDailyWeeklyNumber(gddGJGameLevel *self, int dailyWeeklyNumber);

int gddGJGameLevel_getEpic(const gddGJGameLevel *self);

gddGJGameLevel *gddGJGameLevel_setEpic(gddGJGameLevel *self, int epic);

int gddGJGameLevel_getEditorTime(const gddGJGameLevel *self);

gddGJGameLevel *gddGJGameLevel_setEditorTime(gddGJGameLevel *self, int editorTime);

int gddGJGameLevel_getEditorTimeCopies(const gddGJGameLevel *self);

gddGJGameLevel *gddGJGameLevel_setEditorTimeCopies(gddGJGameLevel *self, int editorTimeCopies);

gddDifficultyFaces gddGJGameLevel_getLevelDifficulty(const gddGJGameLevel *self);

gddGJGameLevel *gddGJGameLevel_setLevelDifficulty(gddGJGameLevel *self, gddDifficultyFaces levelDifficulty);

gddDemonFaces gddGJGameLevel_getDemonDifficulty(const gddGJGameLevel *self);

gddGJGameLevel *gddGJGameLevel_setDemonDifficulty(gddGJGameLevel *self, gddDemonFaces demonDifficulty);

gddLevelLength gddGJGameLevel_getLevelLength(const gddGJGameLevel *self);

gddGJGameLevel *gddGJGameLevel_setLevelLength(gddGJGameLevel *self, gddLevelLength levelLength);

bool gddGJGameLevel_getIsUnlisted(const gddGJGameLevel *self);

gddGJGameLevel *gddGJGameLevel_setIsUnlisted(gddGJGameLevel *self, bool isUnlisted);

bool gddGJGameLevel_getIsFriendsOnly(const gddGJGameLevel *self);

gddGJGameLevel *gddGJGameLevel_setIsFriendsOnly(gddGJGameLevel *self, bool isFriendsOnly);

bool gddGJGameLevel_getIsGauntletLevel(const gddGJGameLevel *self);

gddGJGameLevel *gddGJGameLevel_setIsGauntletLevel(gddGJGameLevel *self, bool isGauntletLevel);

bool gddGJGameLevel_getHasLowDetail(const gddGJGameLevel *self);

gddGJGameLevel *gddGJGameLevel_setHasLowDetail(gddGJGameLevel *self, bool hasLowDetail);

bool gddGJGameLevel_getIsUnrated(const gddGJGameLevel *self);

gddGJGameLevel *gddGJGameLevel_setIsUnrated(gddGJGameLevel *self, bool isUnrated);

bool gddGJGameLevel_getIsFeatured(const gddGJGameLevel *self);

gddGJGameLevel *gddGJGameLevel_setIsFeatured(gddGJGameLevel *self, bool isFeatured);

bool gddGJGameLevel_getIsAuto(const gddGJGameLevel *self);

gddGJGameLevel *gddGJGameLevel_setIsAuto(gddGJGameLevel *self, bool isAuto);

bool gddGJGameLevel_getIsDemon(const gddGJGameLevel *self);

gddGJGameLevel *gddGJGameLevel_setIsDemon(gddGJGameLevel *self, bool isDemon);

bool gddGJGameLevel_getIsCoinsVerified(const gddGJGameLevel *self);

gddGJGameLevel *gddGJGameLevel_setIsCoinsVerified(gddGJGameLevel *self, bool isCoinsVerified);

bool gddGJGameLevel_getIsTwoPlayer(const gddGJGameLevel *self);

gddGJGameLevel *gddGJGameLevel_setIsTwoPlayer(gddGJGameLevel *self, bool isTwoPlayer);

bool gddGJGameLevel_getVerifiedCoins(const gddGJGameLevel *self);

gddGJGameLevel *gddGJGameLevel_setVerifiedCoins(gddGJGameLevel *self, bool verifiedCoins);

#ifdef __cplusplus
}
#endif
