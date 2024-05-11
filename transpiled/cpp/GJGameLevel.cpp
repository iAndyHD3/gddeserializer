// Generated automatically with "fut". Do not edit.
#include "GJGameLevel.hpp"

namespace gdd
{

int GJGameLevel::tryParse(std::string_view str, int defaultVal)
{
	int result = 0;
	int sign = 1;
	int i = 0;
	int len = std::ssize(str);
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

int GJGameLevel::findDelimiterIndex(std::string_view str, std::string_view delimiter, int startPos)
{
	int len = std::ssize(str);
	int delimiterLen = std::ssize(delimiter);
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

std::vector<std::string_view> GJGameLevel::split(std::string_view str, std::string_view delimiter)
{
	std::vector<std::string_view> ret;
	int pos = 0;
	int len = std::ssize(str);
	int delimiterLen = std::ssize(delimiter);
	while (pos < len) {
		int end = findDelimiterIndex(str, delimiter, pos);
		if (end == -1) {
			ret.push_back(str.substr(pos));
			break;
		}
		ret.push_back(str.substr(pos, end - pos));
		pos = end + delimiterLen;
	}
	return ret;
}

void GJGameLevel::addFromObjectString(std::string_view response)
{
	std::vector<std::string_view> level_fields = split(response, ":");
	for (int i = 0; i < std::ssize(level_fields); i += 2) {
		std::string_view val = level_fields[i + 1];
		if (val.empty())
			continue;
		if (level_fields[i] == "1")
			this->levelId = tryParse(val, 0);
		else if (level_fields[i] == "2")
			this->levelName = val;
		else if (level_fields[i] == "3")
			this->levelDesc = val;
		else if (level_fields[i] == "4")
			this->levelString = val;
		else if (level_fields[i] == "5")
			this->levelVersion = tryParse(val);
		else if (level_fields[i] == "6")
			this->playerId = tryParse(val);
		else if (level_fields[i] == "9")
			do {
				{
					int temp = tryParse(val, -1);
					if (temp == -1)
						break;
					switch (temp) {
					case 0:
						this->levelDifficulty = DifficultyFaces::na;
						break;
					case 10:
						this->levelDifficulty = DifficultyFaces::easy;
						break;
					case 20:
						this->levelDifficulty = DifficultyFaces::normal;
						break;
					case 30:
						this->levelDifficulty = DifficultyFaces::hard;
						break;
					case 40:
						this->levelDifficulty = DifficultyFaces::harder;
						break;
					case 50:
						this->levelDifficulty = DifficultyFaces::insane;
						break;
					default:
						this->levelDifficulty = DifficultyFaces::na;
						break;
					}
					break;
				}
			}
			while (false);
		else if (level_fields[i] == "10")
			this->downloads = tryParse(val);
		else if (level_fields[i] == "12")
			this->officialSongId = tryParse(val);
		else if (level_fields[i] == "13")
			this->gameVersion = tryParse(val);
		else if (level_fields[i] == "14")
			this->likes = tryParse(val);
		else if (level_fields[i] == "15")
			do {
				{
					int temp = tryParse(val, -1);
					if (temp == -1)
						break;
					switch (temp) {
					case 0:
						this->levelDuration = LevelLength::tiny;
						break;
					case 1:
						this->levelDuration = LevelLength::short_;
						break;
					case 2:
						this->levelDuration = LevelLength::medium;
						break;
					case 3:
						this->levelDuration = LevelLength::long_;
						break;
					case 4:
						this->levelDuration = LevelLength::xL;
						break;
					default:
						this->levelDuration = LevelLength::na;
						break;
					}
					break;
				}
			}
			while (false);
		else if (level_fields[i] == "16")
			this->dislikes = tryParse(val);
		else if (level_fields[i] == "17")
			this->isDemon = tryParse(val) == 1;
		else if (level_fields[i] == "18")
			this->stars = tryParse(val);
		else if (level_fields[i] == "19")
			this->featureScore = tryParse(val);
		else if (level_fields[i] == "25")
			this->isAuto = tryParse(val) == 1;
		else if (level_fields[i] == "28")
			this->uploadDate = val;
		else if (level_fields[i] == "29")
			this->updateDate = val;
		else if (level_fields[i] == "30")
			this->copiedId = tryParse(val);
		else if (level_fields[i] == "35")
			this->songId = tryParse(val);
		else if (level_fields[i] == "37")
			this->coins = tryParse(val);
		else if (level_fields[i] == "38")
			this->m_verifiedCoins = tryParse(val) == 1;
		else if (level_fields[i] == "41")
			this->dailyWeeklyNumber = tryParse(val);
		else if (level_fields[i] == "42")
			this->epic = tryParse(val);
		else if (level_fields[i] == "43")
			do {
				{
					int temp = tryParse(val, -1);
					if (temp == -1)
						break;
					switch (temp) {
					case 0:
						this->demonDifficulty = DemonFaces::hard;
						break;
					case 3:
						this->demonDifficulty = DemonFaces::easy;
						break;
					case 4:
						this->demonDifficulty = DemonFaces::medium;
						break;
					case 5:
						this->demonDifficulty = DemonFaces::insane;
						break;
					case 6:
						this->demonDifficulty = DemonFaces::extreme;
						break;
					default:
						this->demonDifficulty = DemonFaces::na;
						break;
					}
					break;
				}
			}
			while (false);
		else if (level_fields[i] == "44")
			this->isGauntletLevel = tryParse(val) == 1;
		else if (level_fields[i] == "45")
			this->objectCount = tryParse(val);
		else if (level_fields[i] == "46")
			this->editorTime = tryParse(val);
		else if (level_fields[i] == "47")
			this->editorTimeCopies = tryParse(val);
		if (!this->isDemon) {
			this->demonDifficulty = DemonFaces::na;
		}
		else {
			this->levelDifficulty = DifficultyFaces::demon;
		}
	}
}

std::vector<GJGameLevel> GJGameLevel::createFromGjlevels21Response(std::string_view response)
{
	std::vector<GJGameLevel> ret;
	std::vector<std::string_view> resp_parts = split(response, "#");
	if (std::ssize(resp_parts) == 1)
		return ret;
	std::vector<std::string_view> level_objects_strs = split(resp_parts[0], "|");
	if (std::ssize(level_objects_strs) == 1)
		return ret;
	for (std::string_view level_object_str : level_objects_strs) {
		ret.emplace_back();
		GJGameLevel * level = &static_cast<GJGameLevel &>(ret.back());
		level->addFromObjectString(level_object_str);
		if (level->levelId <= 0) {
			ret.erase(ret.begin() + std::ssize(ret));
		}
	}
	return ret;
}

std::string_view GJGameLevel::getLevelName() const
{
	return this->levelName;
}

GJGameLevel * GJGameLevel::setLevelname(std::string_view levelname)
{
	this->levelName = levelname;
	return this;
}

std::string_view GJGameLevel::getLevelString() const
{
	return this->levelString;
}

GJGameLevel * GJGameLevel::setLevelString(std::string_view levelDesc)
{
	this->levelString = levelDesc;
	return this;
}

std::string_view GJGameLevel::getDescription() const
{
	return this->levelDesc;
}

GJGameLevel * GJGameLevel::setDescription(std::string_view desc)
{
	this->levelDesc = desc;
	return this;
}

std::string_view GJGameLevel::getCreatorName() const
{
	return this->creatorName;
}

GJGameLevel * GJGameLevel::setCreatorname(std::string_view creatorname)
{
	this->creatorName = creatorname;
	return this;
}

std::string_view GJGameLevel::getUploadDate() const
{
	return this->uploadDate;
}

GJGameLevel * GJGameLevel::setUploadDate(std::string_view uploadDate)
{
	this->uploadDate = uploadDate;
	return this;
}

std::string_view GJGameLevel::getUpdateDate() const
{
	return this->updateDate;
}

GJGameLevel * GJGameLevel::setUpdateDate(std::string_view updateDate)
{
	this->updateDate = updateDate;
	return this;
}

int GJGameLevel::getPlayerId() const
{
	return this->playerId;
}

GJGameLevel * GJGameLevel::setPlayerId(int playerId)
{
	this->playerId = playerId;
	return this;
}

int GJGameLevel::getAccountId() const
{
	return this->accountId;
}

GJGameLevel * GJGameLevel::setAccountId(int accountId)
{
	this->accountId = accountId;
	return this;
}

int GJGameLevel::getLevelId() const
{
	return this->levelId;
}

GJGameLevel * GJGameLevel::setLevelId(int levelId)
{
	this->levelId = levelId;
	return this;
}

int GJGameLevel::getSongId() const
{
	return this->songId;
}

GJGameLevel * GJGameLevel::setSongId(int songId)
{
	this->songId = songId;
	return this;
}

int GJGameLevel::getLevelRev() const
{
	return this->levelRev;
}

GJGameLevel * GJGameLevel::setLevelRev(int levelRev)
{
	this->levelRev = levelRev;
	return this;
}

int GJGameLevel::getObjectCount() const
{
	return this->objectCount;
}

GJGameLevel * GJGameLevel::setObjectCount(int objectCount)
{
	this->objectCount = objectCount;
	return this;
}

int GJGameLevel::getDownloads() const
{
	return this->downloads;
}

GJGameLevel * GJGameLevel::setDownloads(int downloads)
{
	this->downloads = downloads;
	return this;
}

int GJGameLevel::getOfficialSong() const
{
	return this->officialSongId;
}

GJGameLevel * GJGameLevel::setOfficialSong(int officialSong)
{
	this->officialSongId = officialSong;
	return this;
}

int GJGameLevel::getLikes() const
{
	return this->likes;
}

GJGameLevel * GJGameLevel::setLikes(int likes)
{
	this->likes = likes;
	return this;
}

int GJGameLevel::getDislikes() const
{
	return this->dislikes;
}

GJGameLevel * GJGameLevel::setDislikes(int dislikes)
{
	this->dislikes = dislikes;
	return this;
}

int GJGameLevel::getWorkingTime() const
{
	return this->workingTime;
}

GJGameLevel * GJGameLevel::setWorkingTime(int workingTime)
{
	this->workingTime = workingTime;
	return this;
}

int GJGameLevel::getLevelVersion() const
{
	return this->levelVersion;
}

GJGameLevel * GJGameLevel::setLevelVersion(int levelVersion)
{
	this->levelVersion = levelVersion;
	return this;
}

int GJGameLevel::getGameVersion() const
{
	return this->gameVersion;
}

GJGameLevel * GJGameLevel::setGameVersion(int gameVersion)
{
	this->gameVersion = gameVersion;
	return this;
}

int GJGameLevel::getCoins() const
{
	return this->coins;
}

GJGameLevel * GJGameLevel::setCoins(int coins)
{
	this->coins = coins;
	return this;
}

int GJGameLevel::getStars() const
{
	return this->stars;
}

GJGameLevel * GJGameLevel::setStars(int stars)
{
	this->stars = stars;
	return this;
}

int GJGameLevel::getFeatureScore() const
{
	return this->featureScore;
}

GJGameLevel * GJGameLevel::setFeatureScore(int featureScore)
{
	this->featureScore = featureScore;
	return this;
}

int GJGameLevel::getCopyPassword() const
{
	return this->copyPassword;
}

GJGameLevel * GJGameLevel::setCopyPassword(int copyPassword)
{
	this->copyPassword = copyPassword;
	return this;
}

int GJGameLevel::getOriginalLevelId() const
{
	return this->originalLevelId;
}

GJGameLevel * GJGameLevel::setOriginalLevelId(int originalLevelId)
{
	this->originalLevelId = originalLevelId;
	return this;
}

int GJGameLevel::getStarsRequested() const
{
	return this->starsRequested;
}

GJGameLevel * GJGameLevel::setStarsRequested(int starsRequested)
{
	this->starsRequested = starsRequested;
	return this;
}

int GJGameLevel::getCopiedId() const
{
	return this->copiedId;
}

GJGameLevel * GJGameLevel::setCopiedId(int copiedId)
{
	this->copiedId = copiedId;
	return this;
}

int GJGameLevel::getDailyWeeklyNumber() const
{
	return this->dailyWeeklyNumber;
}

GJGameLevel * GJGameLevel::setDailyWeeklyNumber(int dailyWeeklyNumber)
{
	this->dailyWeeklyNumber = dailyWeeklyNumber;
	return this;
}

int GJGameLevel::getEpic() const
{
	return this->epic;
}

GJGameLevel * GJGameLevel::setEpic(int epic)
{
	this->epic = epic;
	return this;
}

int GJGameLevel::getEditorTime() const
{
	return this->editorTime;
}

GJGameLevel * GJGameLevel::setEditorTime(int editorTime)
{
	this->editorTime = editorTime;
	return this;
}

int GJGameLevel::getEditorTimeCopies() const
{
	return this->editorTimeCopies;
}

GJGameLevel * GJGameLevel::setEditorTimeCopies(int editorTimeCopies)
{
	this->editorTimeCopies = editorTimeCopies;
	return this;
}

DifficultyFaces GJGameLevel::getLevelDifficulty() const
{
	return this->levelDifficulty;
}

GJGameLevel * GJGameLevel::setLevelDifficulty(DifficultyFaces levelDifficulty)
{
	this->levelDifficulty = levelDifficulty;
	return this;
}

DemonFaces GJGameLevel::getDemonDifficulty() const
{
	return this->demonDifficulty;
}

GJGameLevel * GJGameLevel::setDemonDifficulty(DemonFaces demonDifficulty)
{
	this->demonDifficulty = demonDifficulty;
	return this;
}

LevelLength GJGameLevel::getLevelLength() const
{
	return this->levelDuration;
}

GJGameLevel * GJGameLevel::setLevelLength(LevelLength levelLength)
{
	this->levelDuration = levelLength;
	return this;
}

bool GJGameLevel::getIsUnlisted() const
{
	return this->isUnlisted;
}

GJGameLevel * GJGameLevel::setIsUnlisted(bool isUnlisted)
{
	this->isUnlisted = isUnlisted;
	return this;
}

bool GJGameLevel::getIsFriendsOnly() const
{
	return this->isFriendsOnly;
}

GJGameLevel * GJGameLevel::setIsFriendsOnly(bool isFriendsOnly)
{
	this->isFriendsOnly = isFriendsOnly;
	return this;
}

bool GJGameLevel::getIsGauntletLevel() const
{
	return this->isGauntletLevel;
}

GJGameLevel * GJGameLevel::setIsGauntletLevel(bool isGauntletLevel)
{
	this->isGauntletLevel = isGauntletLevel;
	return this;
}

bool GJGameLevel::getHasLowDetail() const
{
	return this->m_hasLowDetail;
}

GJGameLevel * GJGameLevel::setHasLowDetail(bool hasLowDetail)
{
	this->m_hasLowDetail = hasLowDetail;
	return this;
}

bool GJGameLevel::getIsUnrated() const
{
	return this->isUnrated;
}

GJGameLevel * GJGameLevel::setIsUnrated(bool isUnrated)
{
	this->isUnrated = isUnrated;
	return this;
}

bool GJGameLevel::getIsFeatured() const
{
	return this->isFeatured;
}

GJGameLevel * GJGameLevel::setIsFeatured(bool isFeatured)
{
	this->isFeatured = isFeatured;
	return this;
}

bool GJGameLevel::getIsAuto() const
{
	return this->isAuto;
}

GJGameLevel * GJGameLevel::setIsAuto(bool isAuto)
{
	this->isAuto = isAuto;
	return this;
}

bool GJGameLevel::getIsDemon() const
{
	return this->isDemon;
}

GJGameLevel * GJGameLevel::setIsDemon(bool isDemon)
{
	this->isDemon = isDemon;
	return this;
}

bool GJGameLevel::getIsCoinsVerified() const
{
	return this->isCoinsVerified;
}

GJGameLevel * GJGameLevel::setIsCoinsVerified(bool isCoinsVerified)
{
	this->isCoinsVerified = isCoinsVerified;
	return this;
}

bool GJGameLevel::getIsTwoPlayer() const
{
	return this->isTwoPlayer;
}

GJGameLevel * GJGameLevel::setIsTwoPlayer(bool isTwoPlayer)
{
	this->isTwoPlayer = isTwoPlayer;
	return this;
}

bool GJGameLevel::getVerifiedCoins() const
{
	return this->m_verifiedCoins;
}

GJGameLevel * GJGameLevel::setVerifiedCoins(bool verifiedCoins)
{
	this->m_verifiedCoins = verifiedCoins;
	return this;
}
}
