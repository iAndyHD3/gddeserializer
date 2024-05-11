// Generated automatically with "fut". Do not edit.
#include <stdlib.h>
#include <string.h>
#include "GJGameLevel.h"

static char *FuString_Substring(const char *str, int len)
{
	char *p = malloc(len + 1);
	memcpy(p, str, len);
	p[len] = '\0';
	return p;
}

typedef enum {
	gddDifficultyFaces_NA,
	gddDifficultyFaces_AUTO,
	gddDifficultyFaces_EASY,
	gddDifficultyFaces_NORMAL,
	gddDifficultyFaces_HARD,
	gddDifficultyFaces_HARDER,
	gddDifficultyFaces_INSANE,
	gddDifficultyFaces_DEMON
} gddDifficultyFaces;

typedef enum {
	gddDemonFaces_NA,
	gddDemonFaces_EASY,
	gddDemonFaces_MEDIUM,
	gddDemonFaces_HARD,
	gddDemonFaces_INSANE,
	gddDemonFaces_EXTREME
} gddDemonFaces;

typedef enum {
	gddLevelLength_NA,
	gddLevelLength_TINY,
	gddLevelLength_SHORT,
	gddLevelLength_MEDIUM,
	gddLevelLength_LONG,
	gddLevelLength_X_L
} gddLevelLength;

typedef enum {
	gddLevelType_NA,
	gddLevelType_NORMAL,
	gddLevelType_GAUNTLET,
	gddLevelType_WEEKLY,
	gddLevelType_DAILY,
	gddLevelType_EVENT
} gddLevelType;

struct gddGJGameLevel {
	const char *levelName;
	const char *levelString;
	const char *levelDesc;
	const char *creatorName;
	const char *uploadDate;
	const char *updateDate;
	int playerId;
	int accountId;
	int levelId;
	int songId;
	int levelRev;
	int objectCount;
	int downloads;
	int officialSongId;
	int likes;
	int dislikes;
	int workingTime;
	int levelVersion;
	int gameVersion;
	int coins;
	int stars;
	int featureScore;
	int copyPassword;
	int originalLevelId;
	int starsRequested;
	int copiedId;
	int dailyWeeklyNumber;
	int epic;
	int editorTime;
	int editorTimeCopies;
	gddDifficultyFaces levelDifficulty;
	gddDemonFaces demonDifficulty;
	gddLevelLength levelDuration;
	bool isUnlisted;
	bool isFriendsOnly;
	bool isGauntletLevel;
	bool m_hasLowDetail;
	bool isUnrated;
	bool isFeatured;
	bool isAuto;
	bool isDemon;
	bool isCoinsVerified;
	bool isTwoPlayer;
	bool m_verifiedCoins;
};
static void gddGJGameLevel_Construct(gddGJGameLevel *self);

static void gddGJGameLevel_Construct(gddGJGameLevel *self)
{
	self->levelName = "";
	self->levelString = "";
	self->levelDesc = "";
	self->creatorName = "";
	self->uploadDate = "";
	self->updateDate = "";
	self->playerId = 0;
	self->accountId = 0;
	self->levelId = 0;
	self->songId = 0;
	self->levelRev = 0;
	self->objectCount = 0;
	self->downloads = 0;
	self->officialSongId = 0;
	self->likes = 0;
	self->dislikes = 0;
	self->workingTime = 0;
	self->levelVersion = 0;
	self->gameVersion = 0;
	self->coins = 0;
	self->stars = 0;
	self->featureScore = 0;
	self->copyPassword = 0;
	self->originalLevelId = 0;
	self->starsRequested = 0;
	self->copiedId = 0;
	self->dailyWeeklyNumber = 0;
	self->epic = 0;
	self->editorTime = 0;
	self->editorTimeCopies = 0;
	self->levelDifficulty = gddDifficultyFaces_NA;
	self->demonDifficulty = gddDemonFaces_NA;
	self->levelDuration = gddLevelLength_NA;
	self->isUnlisted = false;
	self->isFriendsOnly = false;
	self->isGauntletLevel = false;
	self->m_hasLowDetail = false;
	self->isUnrated = false;
	self->isFeatured = false;
	self->isAuto = false;
	self->isDemon = false;
	self->isCoinsVerified = false;
	self->isTwoPlayer = false;
	self->m_verifiedCoins = false;
}

int gddGJGameLevel_tryParse(const char *str, int defaultVal)
{
	int result = 0;
	int sign = 1;
	int i = 0;
	int len = (int) strlen(str);
	while (len > i && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')) {
		i++;
	}
	if (len > i && str[i] == '-') {
		sign = -1;
		i++;
	}
	while (len > i && str[i] == '0') {
		i++;
	}
	while (len > i && str[i] >= '0' && str[i] <= '9') {
		result = result * 10 + str[i] - '0';
		i++;
	}
	result = result * sign;
	return result == 0 ? defaultVal : result;
}

int gddGJGameLevel_FindDelimiterIndex(const char *str, const char *delimiter, int startPos)
{
	int len = (int) strlen(str);
	int delimiterLen = (int) strlen(delimiter);
	for (int i = startPos; i < len - delimiterLen + 1; i++) {
		bool found = true;
		for (int j = 0; j < delimiterLen; j++) {
			if (str[i + j] != delimiter[j]) {
				found = false;
				break;
			}
		}
		if (found)
			return i;
	}
	return -1;
}

GArray *gddGJGameLevel_Split(const char *str, const char *delimiter)
{
	GArray *ret = g_array_new(FALSE, FALSE, sizeof(const char *));
	int pos = 0;
	int len = (int) strlen(str);
	int delimiterLen = (int) strlen(delimiter);
	while (pos < len) {
		int end = gddGJGameLevel_FindDelimiterIndex(str, delimiter, pos);
		if (end == -1) {
			const char *futemp0 = str + pos;
			g_array_append_val(ret, futemp0);
			break;
		}
		const char *futemp0 = FuString_Substring(str + pos, end - pos);
		g_array_append_val(ret, futemp0);
		pos = end + delimiterLen;
	}
	return ret;
}

void gddGJGameLevel_addFromObjectString(gddGJGameLevel *self, const char *response)
{
	GArray *level_fields = gddGJGameLevel_Split(response, ":");
	for (int i = 0; i < level_fields->len; i += 2) {
		const char *val = g_array_index(level_fields, const char *, i + 1);
		if (val[0] == '\0')
			continue;
		if (strcmp(g_array_index(level_fields, const char *, i), "1") == 0)
			self->levelId = gddGJGameLevel_tryParse(val, 0);
		else if (strcmp(g_array_index(level_fields, const char *, i), "2") == 0)
			self->levelName = val;
		else if (strcmp(g_array_index(level_fields, const char *, i), "3") == 0)
			self->levelDesc = val;
		else if (strcmp(g_array_index(level_fields, const char *, i), "4") == 0)
			self->levelString = val;
		else if (strcmp(g_array_index(level_fields, const char *, i), "5") == 0)
			self->levelVersion = gddGJGameLevel_tryParse(val, 0);
		else if (strcmp(g_array_index(level_fields, const char *, i), "6") == 0)
			self->playerId = gddGJGameLevel_tryParse(val, 0);
		else if (strcmp(g_array_index(level_fields, const char *, i), "9") == 0)
			do {
				{
					int temp = gddGJGameLevel_tryParse(val, -1);
					if (temp == -1)
						break;
					switch (temp) {
					case 0:
						self->levelDifficulty = gddDifficultyFaces_NA;
						break;
					case 10:
						self->levelDifficulty = gddDifficultyFaces_EASY;
						break;
					case 20:
						self->levelDifficulty = gddDifficultyFaces_NORMAL;
						break;
					case 30:
						self->levelDifficulty = gddDifficultyFaces_HARD;
						break;
					case 40:
						self->levelDifficulty = gddDifficultyFaces_HARDER;
						break;
					case 50:
						self->levelDifficulty = gddDifficultyFaces_INSANE;
						break;
					default:
						self->levelDifficulty = gddDifficultyFaces_NA;
						break;
					}
					break;
				}
			}
			while (false);
		else if (strcmp(g_array_index(level_fields, const char *, i), "10") == 0)
			self->downloads = gddGJGameLevel_tryParse(val, 0);
		else if (strcmp(g_array_index(level_fields, const char *, i), "12") == 0)
			self->officialSongId = gddGJGameLevel_tryParse(val, 0);
		else if (strcmp(g_array_index(level_fields, const char *, i), "13") == 0)
			self->gameVersion = gddGJGameLevel_tryParse(val, 0);
		else if (strcmp(g_array_index(level_fields, const char *, i), "14") == 0)
			self->likes = gddGJGameLevel_tryParse(val, 0);
		else if (strcmp(g_array_index(level_fields, const char *, i), "15") == 0)
			do {
				{
					int temp = gddGJGameLevel_tryParse(val, -1);
					if (temp == -1)
						break;
					switch (temp) {
					case 0:
						self->levelDuration = gddLevelLength_TINY;
						break;
					case 1:
						self->levelDuration = gddLevelLength_SHORT;
						break;
					case 2:
						self->levelDuration = gddLevelLength_MEDIUM;
						break;
					case 3:
						self->levelDuration = gddLevelLength_LONG;
						break;
					case 4:
						self->levelDuration = gddLevelLength_X_L;
						break;
					default:
						self->levelDuration = gddLevelLength_NA;
						break;
					}
					break;
				}
			}
			while (false);
		else if (strcmp(g_array_index(level_fields, const char *, i), "16") == 0)
			self->dislikes = gddGJGameLevel_tryParse(val, 0);
		else if (strcmp(g_array_index(level_fields, const char *, i), "17") == 0)
			self->isDemon = gddGJGameLevel_tryParse(val, 0) == 1;
		else if (strcmp(g_array_index(level_fields, const char *, i), "18") == 0)
			self->stars = gddGJGameLevel_tryParse(val, 0);
		else if (strcmp(g_array_index(level_fields, const char *, i), "19") == 0)
			self->featureScore = gddGJGameLevel_tryParse(val, 0);
		else if (strcmp(g_array_index(level_fields, const char *, i), "25") == 0)
			self->isAuto = gddGJGameLevel_tryParse(val, 0) == 1;
		else if (strcmp(g_array_index(level_fields, const char *, i), "28") == 0)
			self->uploadDate = val;
		else if (strcmp(g_array_index(level_fields, const char *, i), "29") == 0)
			self->updateDate = val;
		else if (strcmp(g_array_index(level_fields, const char *, i), "30") == 0)
			self->copiedId = gddGJGameLevel_tryParse(val, 0);
		else if (strcmp(g_array_index(level_fields, const char *, i), "35") == 0)
			self->songId = gddGJGameLevel_tryParse(val, 0);
		else if (strcmp(g_array_index(level_fields, const char *, i), "37") == 0)
			self->coins = gddGJGameLevel_tryParse(val, 0);
		else if (strcmp(g_array_index(level_fields, const char *, i), "38") == 0)
			self->m_verifiedCoins = gddGJGameLevel_tryParse(val, 0) == 1;
		else if (strcmp(g_array_index(level_fields, const char *, i), "41") == 0)
			self->dailyWeeklyNumber = gddGJGameLevel_tryParse(val, 0);
		else if (strcmp(g_array_index(level_fields, const char *, i), "42") == 0)
			self->epic = gddGJGameLevel_tryParse(val, 0);
		else if (strcmp(g_array_index(level_fields, const char *, i), "43") == 0)
			do {
				{
					int temp = gddGJGameLevel_tryParse(val, -1);
					if (temp == -1)
						break;
					switch (temp) {
					case 0:
						self->demonDifficulty = gddDemonFaces_HARD;
						break;
					case 3:
						self->demonDifficulty = gddDemonFaces_EASY;
						break;
					case 4:
						self->demonDifficulty = gddDemonFaces_MEDIUM;
						break;
					case 5:
						self->demonDifficulty = gddDemonFaces_INSANE;
						break;
					case 6:
						self->demonDifficulty = gddDemonFaces_EXTREME;
						break;
					default:
						self->demonDifficulty = gddDemonFaces_NA;
						break;
					}
					break;
				}
			}
			while (false);
		else if (strcmp(g_array_index(level_fields, const char *, i), "44") == 0)
			self->isGauntletLevel = gddGJGameLevel_tryParse(val, 0) == 1;
		else if (strcmp(g_array_index(level_fields, const char *, i), "45") == 0)
			self->objectCount = gddGJGameLevel_tryParse(val, 0);
		else if (strcmp(g_array_index(level_fields, const char *, i), "46") == 0)
			self->editorTime = gddGJGameLevel_tryParse(val, 0);
		else if (strcmp(g_array_index(level_fields, const char *, i), "47") == 0)
			self->editorTimeCopies = gddGJGameLevel_tryParse(val, 0);
		if (!self->isDemon) {
			self->demonDifficulty = gddDemonFaces_NA;
		}
		else {
			self->levelDifficulty = gddDifficultyFaces_DEMON;
		}
	}
	g_array_unref(level_fields);
}

GArray *gddGJGameLevel_createFromGjlevels21Response(const char *response)
{
	GArray *ret = g_array_new(FALSE, FALSE, sizeof(gddGJGameLevel));
	GArray *resp_parts = gddGJGameLevel_Split(response, "#");
	if (resp_parts->len == 1) {
		g_array_unref(resp_parts);
		return ret;
	}
	GArray *level_objects_strs = gddGJGameLevel_Split(g_array_index(resp_parts, const char *, 0), "|");
	if (level_objects_strs->len == 1) {
		g_array_unref(level_objects_strs);
		g_array_unref(resp_parts);
		return ret;
	}
	for (const char * const *level_object_str = (const char * const *) level_objects_strs->data, * const *fuend = level_object_str + level_objects_strs->len; level_object_str < fuend; level_object_str++) {
		gddGJGameLevel futemp0;
		gddGJGameLevel_Construct(&futemp0);
		g_array_append_val(ret, futemp0);
		gddGJGameLevel *level = &g_array_index(ret, gddGJGameLevel, ret->len - 1);
		gddGJGameLevel_addFromObjectString(level, *level_object_str);
		if (level->levelId <= 0) {
			g_array_remove_index(ret, ret->len);
		}
	}
	g_array_unref(level_objects_strs);
	g_array_unref(resp_parts);
	return ret;
}

const char *gddGJGameLevel_getLevelName(const gddGJGameLevel *self)
{
	return self->levelName;
}

gddGJGameLevel *gddGJGameLevel_setLevelname(gddGJGameLevel *self, const char *levelname)
{
	self->levelName = levelname;
	return self;
}

const char *gddGJGameLevel_getLevelString(const gddGJGameLevel *self)
{
	return self->levelString;
}

gddGJGameLevel *gddGJGameLevel_setLevelString(gddGJGameLevel *self, const char *levelDesc)
{
	self->levelString = levelDesc;
	return self;
}

const char *gddGJGameLevel_getDescription(const gddGJGameLevel *self)
{
	return self->levelDesc;
}

gddGJGameLevel *gddGJGameLevel_setDescription(gddGJGameLevel *self, const char *desc)
{
	self->levelDesc = desc;
	return self;
}

const char *gddGJGameLevel_getCreatorName(const gddGJGameLevel *self)
{
	return self->creatorName;
}

gddGJGameLevel *gddGJGameLevel_setCreatorname(gddGJGameLevel *self, const char *creatorname)
{
	self->creatorName = creatorname;
	return self;
}

const char *gddGJGameLevel_getUploadDate(const gddGJGameLevel *self)
{
	return self->uploadDate;
}

gddGJGameLevel *gddGJGameLevel_setUploadDate(gddGJGameLevel *self, const char *uploadDate)
{
	self->uploadDate = uploadDate;
	return self;
}

const char *gddGJGameLevel_getUpdateDate(const gddGJGameLevel *self)
{
	return self->updateDate;
}

gddGJGameLevel *gddGJGameLevel_setUpdateDate(gddGJGameLevel *self, const char *updateDate)
{
	self->updateDate = updateDate;
	return self;
}

int gddGJGameLevel_getPlayerId(const gddGJGameLevel *self)
{
	return self->playerId;
}

gddGJGameLevel *gddGJGameLevel_setPlayerId(gddGJGameLevel *self, int playerId)
{
	self->playerId = playerId;
	return self;
}

int gddGJGameLevel_getAccountId(const gddGJGameLevel *self)
{
	return self->accountId;
}

gddGJGameLevel *gddGJGameLevel_setAccountId(gddGJGameLevel *self, int accountId)
{
	self->accountId = accountId;
	return self;
}

int gddGJGameLevel_getLevelId(const gddGJGameLevel *self)
{
	return self->levelId;
}

gddGJGameLevel *gddGJGameLevel_setLevelId(gddGJGameLevel *self, int levelId)
{
	self->levelId = levelId;
	return self;
}

int gddGJGameLevel_getSongId(const gddGJGameLevel *self)
{
	return self->songId;
}

gddGJGameLevel *gddGJGameLevel_setSongId(gddGJGameLevel *self, int songId)
{
	self->songId = songId;
	return self;
}

int gddGJGameLevel_getLevelRev(const gddGJGameLevel *self)
{
	return self->levelRev;
}

gddGJGameLevel *gddGJGameLevel_setLevelRev(gddGJGameLevel *self, int levelRev)
{
	self->levelRev = levelRev;
	return self;
}

int gddGJGameLevel_getObjectCount(const gddGJGameLevel *self)
{
	return self->objectCount;
}

gddGJGameLevel *gddGJGameLevel_setObjectCount(gddGJGameLevel *self, int objectCount)
{
	self->objectCount = objectCount;
	return self;
}

int gddGJGameLevel_getDownloads(const gddGJGameLevel *self)
{
	return self->downloads;
}

gddGJGameLevel *gddGJGameLevel_setDownloads(gddGJGameLevel *self, int downloads)
{
	self->downloads = downloads;
	return self;
}

int gddGJGameLevel_getOfficialSong(const gddGJGameLevel *self)
{
	return self->officialSongId;
}

gddGJGameLevel *gddGJGameLevel_setOfficialSong(gddGJGameLevel *self, int officialSong)
{
	self->officialSongId = officialSong;
	return self;
}

int gddGJGameLevel_getLikes(const gddGJGameLevel *self)
{
	return self->likes;
}

gddGJGameLevel *gddGJGameLevel_setLikes(gddGJGameLevel *self, int likes)
{
	self->likes = likes;
	return self;
}

int gddGJGameLevel_getDislikes(const gddGJGameLevel *self)
{
	return self->dislikes;
}

gddGJGameLevel *gddGJGameLevel_setDislikes(gddGJGameLevel *self, int dislikes)
{
	self->dislikes = dislikes;
	return self;
}

int gddGJGameLevel_getWorkingTime(const gddGJGameLevel *self)
{
	return self->workingTime;
}

gddGJGameLevel *gddGJGameLevel_setWorkingTime(gddGJGameLevel *self, int workingTime)
{
	self->workingTime = workingTime;
	return self;
}

int gddGJGameLevel_getLevelVersion(const gddGJGameLevel *self)
{
	return self->levelVersion;
}

gddGJGameLevel *gddGJGameLevel_setLevelVersion(gddGJGameLevel *self, int levelVersion)
{
	self->levelVersion = levelVersion;
	return self;
}

int gddGJGameLevel_getGameVersion(const gddGJGameLevel *self)
{
	return self->gameVersion;
}

gddGJGameLevel *gddGJGameLevel_setGameVersion(gddGJGameLevel *self, int gameVersion)
{
	self->gameVersion = gameVersion;
	return self;
}

int gddGJGameLevel_getCoins(const gddGJGameLevel *self)
{
	return self->coins;
}

gddGJGameLevel *gddGJGameLevel_setCoins(gddGJGameLevel *self, int coins)
{
	self->coins = coins;
	return self;
}

int gddGJGameLevel_getStars(const gddGJGameLevel *self)
{
	return self->stars;
}

gddGJGameLevel *gddGJGameLevel_setStars(gddGJGameLevel *self, int stars)
{
	self->stars = stars;
	return self;
}

int gddGJGameLevel_getFeatureScore(const gddGJGameLevel *self)
{
	return self->featureScore;
}

gddGJGameLevel *gddGJGameLevel_setFeatureScore(gddGJGameLevel *self, int featureScore)
{
	self->featureScore = featureScore;
	return self;
}

int gddGJGameLevel_getCopyPassword(const gddGJGameLevel *self)
{
	return self->copyPassword;
}

gddGJGameLevel *gddGJGameLevel_setCopyPassword(gddGJGameLevel *self, int copyPassword)
{
	self->copyPassword = copyPassword;
	return self;
}

int gddGJGameLevel_getOriginalLevelId(const gddGJGameLevel *self)
{
	return self->originalLevelId;
}

gddGJGameLevel *gddGJGameLevel_setOriginalLevelId(gddGJGameLevel *self, int originalLevelId)
{
	self->originalLevelId = originalLevelId;
	return self;
}

int gddGJGameLevel_getStarsRequested(const gddGJGameLevel *self)
{
	return self->starsRequested;
}

gddGJGameLevel *gddGJGameLevel_setStarsRequested(gddGJGameLevel *self, int starsRequested)
{
	self->starsRequested = starsRequested;
	return self;
}

int gddGJGameLevel_getCopiedId(const gddGJGameLevel *self)
{
	return self->copiedId;
}

gddGJGameLevel *gddGJGameLevel_setCopiedId(gddGJGameLevel *self, int copiedId)
{
	self->copiedId = copiedId;
	return self;
}

int gddGJGameLevel_getDailyWeeklyNumber(const gddGJGameLevel *self)
{
	return self->dailyWeeklyNumber;
}

gddGJGameLevel *gddGJGameLevel_setDailyWeeklyNumber(gddGJGameLevel *self, int dailyWeeklyNumber)
{
	self->dailyWeeklyNumber = dailyWeeklyNumber;
	return self;
}

int gddGJGameLevel_getEpic(const gddGJGameLevel *self)
{
	return self->epic;
}

gddGJGameLevel *gddGJGameLevel_setEpic(gddGJGameLevel *self, int epic)
{
	self->epic = epic;
	return self;
}

int gddGJGameLevel_getEditorTime(const gddGJGameLevel *self)
{
	return self->editorTime;
}

gddGJGameLevel *gddGJGameLevel_setEditorTime(gddGJGameLevel *self, int editorTime)
{
	self->editorTime = editorTime;
	return self;
}

int gddGJGameLevel_getEditorTimeCopies(const gddGJGameLevel *self)
{
	return self->editorTimeCopies;
}

gddGJGameLevel *gddGJGameLevel_setEditorTimeCopies(gddGJGameLevel *self, int editorTimeCopies)
{
	self->editorTimeCopies = editorTimeCopies;
	return self;
}

gddDifficultyFaces gddGJGameLevel_getLevelDifficulty(const gddGJGameLevel *self)
{
	return self->levelDifficulty;
}

gddGJGameLevel *gddGJGameLevel_setLevelDifficulty(gddGJGameLevel *self, gddDifficultyFaces levelDifficulty)
{
	self->levelDifficulty = levelDifficulty;
	return self;
}

gddDemonFaces gddGJGameLevel_getDemonDifficulty(const gddGJGameLevel *self)
{
	return self->demonDifficulty;
}

gddGJGameLevel *gddGJGameLevel_setDemonDifficulty(gddGJGameLevel *self, gddDemonFaces demonDifficulty)
{
	self->demonDifficulty = demonDifficulty;
	return self;
}

gddLevelLength gddGJGameLevel_getLevelLength(const gddGJGameLevel *self)
{
	return self->levelDuration;
}

gddGJGameLevel *gddGJGameLevel_setLevelLength(gddGJGameLevel *self, gddLevelLength levelLength)
{
	self->levelDuration = levelLength;
	return self;
}

bool gddGJGameLevel_getIsUnlisted(const gddGJGameLevel *self)
{
	return self->isUnlisted;
}

gddGJGameLevel *gddGJGameLevel_setIsUnlisted(gddGJGameLevel *self, bool isUnlisted)
{
	self->isUnlisted = isUnlisted;
	return self;
}

bool gddGJGameLevel_getIsFriendsOnly(const gddGJGameLevel *self)
{
	return self->isFriendsOnly;
}

gddGJGameLevel *gddGJGameLevel_setIsFriendsOnly(gddGJGameLevel *self, bool isFriendsOnly)
{
	self->isFriendsOnly = isFriendsOnly;
	return self;
}

bool gddGJGameLevel_getIsGauntletLevel(const gddGJGameLevel *self)
{
	return self->isGauntletLevel;
}

gddGJGameLevel *gddGJGameLevel_setIsGauntletLevel(gddGJGameLevel *self, bool isGauntletLevel)
{
	self->isGauntletLevel = isGauntletLevel;
	return self;
}

bool gddGJGameLevel_getHasLowDetail(const gddGJGameLevel *self)
{
	return self->m_hasLowDetail;
}

gddGJGameLevel *gddGJGameLevel_setHasLowDetail(gddGJGameLevel *self, bool hasLowDetail)
{
	self->m_hasLowDetail = hasLowDetail;
	return self;
}

bool gddGJGameLevel_getIsUnrated(const gddGJGameLevel *self)
{
	return self->isUnrated;
}

gddGJGameLevel *gddGJGameLevel_setIsUnrated(gddGJGameLevel *self, bool isUnrated)
{
	self->isUnrated = isUnrated;
	return self;
}

bool gddGJGameLevel_getIsFeatured(const gddGJGameLevel *self)
{
	return self->isFeatured;
}

gddGJGameLevel *gddGJGameLevel_setIsFeatured(gddGJGameLevel *self, bool isFeatured)
{
	self->isFeatured = isFeatured;
	return self;
}

bool gddGJGameLevel_getIsAuto(const gddGJGameLevel *self)
{
	return self->isAuto;
}

gddGJGameLevel *gddGJGameLevel_setIsAuto(gddGJGameLevel *self, bool isAuto)
{
	self->isAuto = isAuto;
	return self;
}

bool gddGJGameLevel_getIsDemon(const gddGJGameLevel *self)
{
	return self->isDemon;
}

gddGJGameLevel *gddGJGameLevel_setIsDemon(gddGJGameLevel *self, bool isDemon)
{
	self->isDemon = isDemon;
	return self;
}

bool gddGJGameLevel_getIsCoinsVerified(const gddGJGameLevel *self)
{
	return self->isCoinsVerified;
}

gddGJGameLevel *gddGJGameLevel_setIsCoinsVerified(gddGJGameLevel *self, bool isCoinsVerified)
{
	self->isCoinsVerified = isCoinsVerified;
	return self;
}

bool gddGJGameLevel_getIsTwoPlayer(const gddGJGameLevel *self)
{
	return self->isTwoPlayer;
}

gddGJGameLevel *gddGJGameLevel_setIsTwoPlayer(gddGJGameLevel *self, bool isTwoPlayer)
{
	self->isTwoPlayer = isTwoPlayer;
	return self;
}

bool gddGJGameLevel_getVerifiedCoins(const gddGJGameLevel *self)
{
	return self->m_verifiedCoins;
}

gddGJGameLevel *gddGJGameLevel_setVerifiedCoins(gddGJGameLevel *self, bool verifiedCoins)
{
	self->m_verifiedCoins = verifiedCoins;
	return self;
}
