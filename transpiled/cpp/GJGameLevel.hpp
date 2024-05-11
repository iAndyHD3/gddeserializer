// Generated automatically with "fut". Do not edit.
#pragma once
#include <string_view>
#include <vector>

namespace gdd
{

enum class DifficultyFaces
{
	na,
	auto_,
	easy,
	normal,
	hard,
	harder,
	insane,
	demon
};

enum class DemonFaces
{
	na,
	easy,
	medium,
	hard,
	insane,
	extreme
};

enum class LevelLength
{
	na,
	tiny,
	short_,
	medium,
	long_,
	xL
};

enum class LevelType
{
	na,
	normal,
	gauntlet,
	weekly,
	daily,
	event
};
class GJGameLevel;

class GJGameLevel
{
public:
	GJGameLevel() = default;
	static constexpr std::string_view prop_settingsString = "48";
	static constexpr std::string_view prop_editorTime2 = "47";
	static constexpr std::string_view prop_editorTime = "46";
	static constexpr std::string_view prop_objectCount = "45";
	static constexpr std::string_view prop_isGauntlet = "44";
	static constexpr std::string_view prop_demonDifficulty = "43";
	static constexpr std::string_view prop_epic = "42";
	static constexpr std::string_view prop_dailyNumber = "41";
	static constexpr std::string_view prop_lowDetailMode = "40";
	static constexpr std::string_view prop_starsRequested = "39";
	static constexpr std::string_view prop_verifiedCoins = "38";
	static constexpr std::string_view prop_coins = "37";
	static constexpr std::string_view prop_extraString = "36";
	static constexpr std::string_view prop_customSongId = "35";
	static constexpr std::string_view prop_twoPlayer = "31";
	static constexpr std::string_view prop_copiedId = "30";
	static constexpr std::string_view prop_updateDate = "29";
	static constexpr std::string_view prop_uploadDate = "28";
	static constexpr std::string_view prop_password = "27";
	static constexpr std::string_view prop_recordString = "26";
	static constexpr std::string_view prop_auto = "25";
	static constexpr std::string_view prop_featureScore = "19";
	static constexpr std::string_view prop_stars = "18";
	static constexpr std::string_view prop_is_demon = "17";
	static constexpr std::string_view prop_dislikes = "16";
	static constexpr std::string_view prop_length = "15";
	static constexpr std::string_view prop_likes = "14";
	static constexpr std::string_view prop_gameVersion = "13";
	static constexpr std::string_view prop_officialSong = "12";
	static constexpr std::string_view prop_setCompletes = "11";
	static constexpr std::string_view prop_downloads = "10";
	static constexpr std::string_view prop_difficultyNumerator = "9";
	static constexpr std::string_view prop_difficultyDenominator = "8";
	static constexpr std::string_view prop_playerId = "6";
	static constexpr std::string_view prop_version = "5";
	static constexpr std::string_view prop_levelString = "4";
	static constexpr std::string_view prop_description = "3";
	static constexpr std::string_view prop_levelname = "2";
	static constexpr std::string_view prop_levelId = "1";
	static int tryParse(std::string_view str, int defaultVal = 0);
	static int findDelimiterIndex(std::string_view str, std::string_view delimiter, int startPos);
	static std::vector<std::string_view> split(std::string_view str, std::string_view delimiter);
	void addFromObjectString(std::string_view response);
	static std::vector<GJGameLevel> createFromGjlevels21Response(std::string_view response);
	std::string_view getLevelName() const;
	GJGameLevel * setLevelname(std::string_view levelname);
	std::string_view getLevelString() const;
	GJGameLevel * setLevelString(std::string_view levelDesc);
	std::string_view getDescription() const;
	GJGameLevel * setDescription(std::string_view desc);
	std::string_view getCreatorName() const;
	GJGameLevel * setCreatorname(std::string_view creatorname);
	std::string_view getUploadDate() const;
	GJGameLevel * setUploadDate(std::string_view uploadDate);
	std::string_view getUpdateDate() const;
	GJGameLevel * setUpdateDate(std::string_view updateDate);
	int getPlayerId() const;
	GJGameLevel * setPlayerId(int playerId);
	int getAccountId() const;
	GJGameLevel * setAccountId(int accountId);
	int getLevelId() const;
	GJGameLevel * setLevelId(int levelId);
	int getSongId() const;
	GJGameLevel * setSongId(int songId);
	int getLevelRev() const;
	GJGameLevel * setLevelRev(int levelRev);
	int getObjectCount() const;
	GJGameLevel * setObjectCount(int objectCount);
	int getDownloads() const;
	GJGameLevel * setDownloads(int downloads);
	int getOfficialSong() const;
	GJGameLevel * setOfficialSong(int officialSong);
	int getLikes() const;
	GJGameLevel * setLikes(int likes);
	int getDislikes() const;
	GJGameLevel * setDislikes(int dislikes);
	int getWorkingTime() const;
	GJGameLevel * setWorkingTime(int workingTime);
	int getLevelVersion() const;
	GJGameLevel * setLevelVersion(int levelVersion);
	int getGameVersion() const;
	GJGameLevel * setGameVersion(int gameVersion);
	int getCoins() const;
	GJGameLevel * setCoins(int coins);
	int getStars() const;
	GJGameLevel * setStars(int stars);
	int getFeatureScore() const;
	GJGameLevel * setFeatureScore(int featureScore);
	int getCopyPassword() const;
	GJGameLevel * setCopyPassword(int copyPassword);
	int getOriginalLevelId() const;
	GJGameLevel * setOriginalLevelId(int originalLevelId);
	int getStarsRequested() const;
	GJGameLevel * setStarsRequested(int starsRequested);
	int getCopiedId() const;
	GJGameLevel * setCopiedId(int copiedId);
	int getDailyWeeklyNumber() const;
	GJGameLevel * setDailyWeeklyNumber(int dailyWeeklyNumber);
	int getEpic() const;
	GJGameLevel * setEpic(int epic);
	int getEditorTime() const;
	GJGameLevel * setEditorTime(int editorTime);
	int getEditorTimeCopies() const;
	GJGameLevel * setEditorTimeCopies(int editorTimeCopies);
	DifficultyFaces getLevelDifficulty() const;
	GJGameLevel * setLevelDifficulty(DifficultyFaces levelDifficulty);
	DemonFaces getDemonDifficulty() const;
	GJGameLevel * setDemonDifficulty(DemonFaces demonDifficulty);
	LevelLength getLevelLength() const;
	GJGameLevel * setLevelLength(LevelLength levelLength);
	bool getIsUnlisted() const;
	GJGameLevel * setIsUnlisted(bool isUnlisted);
	bool getIsFriendsOnly() const;
	GJGameLevel * setIsFriendsOnly(bool isFriendsOnly);
	bool getIsGauntletLevel() const;
	GJGameLevel * setIsGauntletLevel(bool isGauntletLevel);
	bool getHasLowDetail() const;
	GJGameLevel * setHasLowDetail(bool hasLowDetail);
	bool getIsUnrated() const;
	GJGameLevel * setIsUnrated(bool isUnrated);
	bool getIsFeatured() const;
	GJGameLevel * setIsFeatured(bool isFeatured);
	bool getIsAuto() const;
	GJGameLevel * setIsAuto(bool isAuto);
	bool getIsDemon() const;
	GJGameLevel * setIsDemon(bool isDemon);
	bool getIsCoinsVerified() const;
	GJGameLevel * setIsCoinsVerified(bool isCoinsVerified);
	bool getIsTwoPlayer() const;
	GJGameLevel * setIsTwoPlayer(bool isTwoPlayer);
	bool getVerifiedCoins() const;
	GJGameLevel * setVerifiedCoins(bool verifiedCoins);
private:
	std::string_view levelName = "";
	std::string_view levelString = "";
	std::string_view levelDesc = "";
	std::string_view creatorName = "";
	std::string_view uploadDate = "";
	std::string_view updateDate = "";
	int playerId = 0;
	int accountId = 0;
	int levelId = 0;
	int songId = 0;
	int levelRev = 0;
	int objectCount = 0;
	int downloads = 0;
	int officialSongId = 0;
	int likes = 0;
	int dislikes = 0;
	int workingTime = 0;
	int levelVersion = 0;
	int gameVersion = 0;
	int coins = 0;
	int stars = 0;
	int featureScore = 0;
	int copyPassword = 0;
	int originalLevelId = 0;
	int starsRequested = 0;
	int copiedId = 0;
	int dailyWeeklyNumber = 0;
	int epic = 0;
	int editorTime = 0;
	int editorTimeCopies = 0;
	DifficultyFaces levelDifficulty = DifficultyFaces::na;
	DemonFaces demonDifficulty = DemonFaces::na;
	LevelLength levelDuration = LevelLength::na;
	bool isUnlisted = false;
	bool isFriendsOnly = false;
	bool isGauntletLevel = false;
	bool m_hasLowDetail = false;
	bool isUnrated = false;
	bool isFeatured = false;
	bool isAuto = false;
	bool isDemon = false;
	bool isCoinsVerified = false;
	bool isTwoPlayer = false;
	bool m_verifiedCoins = false;
};
}
