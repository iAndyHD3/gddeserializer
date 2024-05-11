// Generated automatically with "fut". Do not edit.

const DifficultyFaces = {
	NA : 0,
	AUTO : 1,
	EASY : 2,
	NORMAL : 3,
	HARD : 4,
	HARDER : 5,
	INSANE : 6,
	DEMON : 7
}

const DemonFaces = {
	NA : 0,
	EASY : 1,
	MEDIUM : 2,
	HARD : 3,
	INSANE : 4,
	EXTREME : 5
}

const LevelLength = {
	NA : 0,
	TINY : 1,
	SHORT : 2,
	MEDIUM : 3,
	LONG : 4,
	X_L : 5
}

const LevelType = {
	NA : 0,
	NORMAL : 1,
	GAUNTLET : 2,
	WEEKLY : 3,
	DAILY : 4,
	EVENT : 5
}

export class GJGameLevel
{

	static PROP_SETTINGS_STRING = "48";

	static PROP_EDITOR_TIME2 = "47";

	static PROP_EDITOR_TIME = "46";

	static PROP_OBJECT_COUNT = "45";

	static PROP_IS_GAUNTLET = "44";

	static PROP_DEMON_DIFFICULTY = "43";

	static PROP_EPIC = "42";

	static PROP_DAILY_NUMBER = "41";

	static PROP_LOW_DETAIL_MODE = "40";

	static PROP_STARS_REQUESTED = "39";

	static PROP_VERIFIED_COINS = "38";

	static PROP_COINS = "37";

	static PROP_EXTRA_STRING = "36";

	static PROP_CUSTOM_SONG_ID = "35";

	static PROP_TWO_PLAYER = "31";

	static PROP_COPIED_ID = "30";

	static PROP_UPDATE_DATE = "29";

	static PROP_UPLOAD_DATE = "28";

	static PROP_PASSWORD = "27";

	static PROP_RECORD_STRING = "26";

	static PROP_AUTO = "25";

	static PROP_FEATURE_SCORE = "19";

	static PROP_STARS = "18";

	static PROP_IS_DEMON = "17";

	static PROP_DISLIKES = "16";

	static PROP_LENGTH = "15";

	static PROP_LIKES = "14";

	static PROP_GAME_VERSION = "13";

	static PROP_OFFICIAL_SONG = "12";

	static PROP_SET_COMPLETES = "11";

	static PROP_DOWNLOADS = "10";

	static PROP_DIFFICULTY_NUMERATOR = "9";

	static PROP_DIFFICULTY_DENOMINATOR = "8";

	static PROP_PLAYER_ID = "6";

	static PROP_VERSION = "5";

	static PROP_LEVEL_STRING = "4";

	static PROP_DESCRIPTION = "3";

	static PROP_LEVELNAME = "2";

	static PROP_LEVEL_ID = "1";

	static tryParse(str, defaultVal = 0)
	{
		let result = 0;
		let sign = 1;
		let i = 0;
		let len = str.length;
		while (len > i && (str.charCodeAt(i) == 32 || str.charCodeAt(i) == 9 || str.charCodeAt(i) == 10)) {
			i++;
		}
		if (len > i && str.charCodeAt(i) == 45) {
			sign = -1;
			i++;
		}
		while (len > i && str.charCodeAt(i) == 48) {
			i++;
		}
		while (len > i && str.charCodeAt(i) >= 48 && str.charCodeAt(i) <= 57) {
			result = result * 10 + str.charCodeAt(i) - 48;
			i++;
		}
		result = result * sign;
		return result == 0 ? defaultVal : result;
	}

	static findDelimiterIndex(str, delimiter, startPos)
	{
		let len = str.length;
		let delimiterLen = delimiter.length;
		for (let i = startPos; i < len - delimiterLen + 1; i++) {
			let found = true;
			for (let j = 0; j < delimiterLen; j++) {
				if (str.charCodeAt(i + j) != delimiter.charCodeAt(j)) {
					found = false;
					break;
				}
			}
			if (found)
				return i;
		}
		return -1;
	}

	static split(str, delimiter)
	{
		const ret = [];
		let pos = 0;
		let len = str.length;
		let delimiterLen = delimiter.length;
		while (pos < len) {
			let end = GJGameLevel.findDelimiterIndex(str, delimiter, pos);
			if (end == -1) {
				ret.push(str.substring(pos));
				break;
			}
			ret.push(str.substring(pos, pos + end - pos));
			pos = end + delimiterLen;
		}
		return ret;
	}

	addFromObjectString(response)
	{
		const level_fields = GJGameLevel.split(response, ":");
		for (let i = 0; i < level_fields.length; i += 2) {
			let val = level_fields[i + 1];
			if (val.length == 0)
				continue;
			switch (level_fields[i]) {
			case "1":
				this.#levelId = GJGameLevel.tryParse(val, 0);
				break;
			case "2":
				this.#levelName = val;
				break;
			case "3":
				this.#levelDesc = val;
				break;
			case "4":
				this.#levelString = val;
				break;
			case "5":
				this.#levelVersion = GJGameLevel.tryParse(val);
				break;
			case "6":
				this.#playerId = GJGameLevel.tryParse(val);
				break;
			case "9":
				{
					let temp = GJGameLevel.tryParse(val, -1);
					if (temp == -1)
						break;
					switch (temp) {
					case 0:
						this.#levelDifficulty = DifficultyFaces.NA;
						break;
					case 10:
						this.#levelDifficulty = DifficultyFaces.EASY;
						break;
					case 20:
						this.#levelDifficulty = DifficultyFaces.NORMAL;
						break;
					case 30:
						this.#levelDifficulty = DifficultyFaces.HARD;
						break;
					case 40:
						this.#levelDifficulty = DifficultyFaces.HARDER;
						break;
					case 50:
						this.#levelDifficulty = DifficultyFaces.INSANE;
						break;
					default:
						this.#levelDifficulty = DifficultyFaces.NA;
						break;
					}
					break;
				}
			case "10":
				this.#downloads = GJGameLevel.tryParse(val);
				break;
			case "12":
				this.#officialSongId = GJGameLevel.tryParse(val);
				break;
			case "13":
				this.#gameVersion = GJGameLevel.tryParse(val);
				break;
			case "14":
				this.#likes = GJGameLevel.tryParse(val);
				break;
			case "15":
				{
					let temp = GJGameLevel.tryParse(val, -1);
					if (temp == -1)
						break;
					switch (temp) {
					case 0:
						this.#levelDuration = LevelLength.TINY;
						break;
					case 1:
						this.#levelDuration = LevelLength.SHORT;
						break;
					case 2:
						this.#levelDuration = LevelLength.MEDIUM;
						break;
					case 3:
						this.#levelDuration = LevelLength.LONG;
						break;
					case 4:
						this.#levelDuration = LevelLength.X_L;
						break;
					default:
						this.#levelDuration = LevelLength.NA;
						break;
					}
					break;
				}
			case "16":
				this.#dislikes = GJGameLevel.tryParse(val);
				break;
			case "17":
				this.#isDemon = GJGameLevel.tryParse(val) == 1;
				break;
			case "18":
				this.#stars = GJGameLevel.tryParse(val);
				break;
			case "19":
				this.#featureScore = GJGameLevel.tryParse(val);
				break;
			case "25":
				this.#isAuto = GJGameLevel.tryParse(val) == 1;
				break;
			case "28":
				this.#uploadDate = val;
				break;
			case "29":
				this.#updateDate = val;
				break;
			case "30":
				this.#copiedId = GJGameLevel.tryParse(val);
				break;
			case "35":
				this.#songId = GJGameLevel.tryParse(val);
				break;
			case "37":
				this.#coins = GJGameLevel.tryParse(val);
				break;
			case "38":
				this.#m_verifiedCoins = GJGameLevel.tryParse(val) == 1;
				break;
			case "41":
				this.#dailyWeeklyNumber = GJGameLevel.tryParse(val);
				break;
			case "42":
				this.#epic = GJGameLevel.tryParse(val);
				break;
			case "43":
				{
					let temp = GJGameLevel.tryParse(val, -1);
					if (temp == -1)
						break;
					switch (temp) {
					case 0:
						this.#demonDifficulty = DemonFaces.HARD;
						break;
					case 3:
						this.#demonDifficulty = DemonFaces.EASY;
						break;
					case 4:
						this.#demonDifficulty = DemonFaces.MEDIUM;
						break;
					case 5:
						this.#demonDifficulty = DemonFaces.INSANE;
						break;
					case 6:
						this.#demonDifficulty = DemonFaces.EXTREME;
						break;
					default:
						this.#demonDifficulty = DemonFaces.NA;
						break;
					}
					break;
				}
			case "44":
				this.#isGauntletLevel = GJGameLevel.tryParse(val) == 1;
				break;
			case "45":
				this.#objectCount = GJGameLevel.tryParse(val);
				break;
			case "46":
				this.#editorTime = GJGameLevel.tryParse(val);
				break;
			case "47":
				this.#editorTimeCopies = GJGameLevel.tryParse(val);
				break;
			}
			if (!this.#isDemon) {
				this.#demonDifficulty = DemonFaces.NA;
			}
			else {
				this.#levelDifficulty = DifficultyFaces.DEMON;
			}
		}
	}

	static createFromGjlevels21Response(response)
	{
		const ret = [];
		const resp_parts = GJGameLevel.split(response, "#");
		if (resp_parts.length == 1)
			return ret;
		const level_objects_strs = GJGameLevel.split(resp_parts[0], "|");
		if (level_objects_strs.length == 1)
			return ret;
		for (const level_object_str of level_objects_strs) {
			ret.push(new GJGameLevel());
			let level = ret.at(-1);
			level.addFromObjectString(level_object_str);
			if (level.#levelId <= 0) {
				ret.splice(ret.length, 1);
			}
		}
		return ret;
	}
	#levelName = "";

	getLevelName()
	{
		return this.#levelName;
	}

	setLevelname(levelname)
	{
		this.#levelName = levelname;
		return this;
	}
	#levelString = "";

	getLevelString()
	{
		return this.#levelString;
	}

	setLevelString(levelDesc)
	{
		this.#levelString = levelDesc;
		return this;
	}
	#levelDesc = "";

	getDescription()
	{
		return this.#levelDesc;
	}

	setDescription(desc)
	{
		this.#levelDesc = desc;
		return this;
	}
	#creatorName = "";

	getCreatorName()
	{
		return this.#creatorName;
	}

	setCreatorname(creatorname)
	{
		this.#creatorName = creatorname;
		return this;
	}
	#uploadDate = "";

	getUploadDate()
	{
		return this.#uploadDate;
	}

	setUploadDate(uploadDate)
	{
		this.#uploadDate = uploadDate;
		return this;
	}
	#updateDate = "";

	getUpdateDate()
	{
		return this.#updateDate;
	}

	setUpdateDate(updateDate)
	{
		this.#updateDate = updateDate;
		return this;
	}
	#playerId = 0;

	getPlayerId()
	{
		return this.#playerId;
	}

	setPlayerId(playerId)
	{
		this.#playerId = playerId;
		return this;
	}
	#accountId = 0;

	getAccountId()
	{
		return this.#accountId;
	}

	setAccountId(accountId)
	{
		this.#accountId = accountId;
		return this;
	}
	#levelId = 0;

	getLevelId()
	{
		return this.#levelId;
	}

	setLevelId(levelId)
	{
		this.#levelId = levelId;
		return this;
	}
	#songId = 0;

	getSongId()
	{
		return this.#songId;
	}

	setSongId(songId)
	{
		this.#songId = songId;
		return this;
	}
	#levelRev = 0;

	getLevelRev()
	{
		return this.#levelRev;
	}

	setLevelRev(levelRev)
	{
		this.#levelRev = levelRev;
		return this;
	}
	#objectCount = 0;

	getObjectCount()
	{
		return this.#objectCount;
	}

	setObjectCount(objectCount)
	{
		this.#objectCount = objectCount;
		return this;
	}
	#downloads = 0;

	getDownloads()
	{
		return this.#downloads;
	}

	setDownloads(downloads)
	{
		this.#downloads = downloads;
		return this;
	}
	#officialSongId = 0;

	getOfficialSong()
	{
		return this.#officialSongId;
	}

	setOfficialSong(officialSong)
	{
		this.#officialSongId = officialSong;
		return this;
	}
	#likes = 0;

	getLikes()
	{
		return this.#likes;
	}

	setLikes(likes)
	{
		this.#likes = likes;
		return this;
	}
	#dislikes = 0;

	getDislikes()
	{
		return this.#dislikes;
	}

	setDislikes(dislikes)
	{
		this.#dislikes = dislikes;
		return this;
	}
	#workingTime = 0;

	getWorkingTime()
	{
		return this.#workingTime;
	}

	setWorkingTime(workingTime)
	{
		this.#workingTime = workingTime;
		return this;
	}
	#levelVersion = 0;

	getLevelVersion()
	{
		return this.#levelVersion;
	}

	setLevelVersion(levelVersion)
	{
		this.#levelVersion = levelVersion;
		return this;
	}
	#gameVersion = 0;

	getGameVersion()
	{
		return this.#gameVersion;
	}

	setGameVersion(gameVersion)
	{
		this.#gameVersion = gameVersion;
		return this;
	}
	#coins = 0;

	getCoins()
	{
		return this.#coins;
	}

	setCoins(coins)
	{
		this.#coins = coins;
		return this;
	}
	#stars = 0;

	getStars()
	{
		return this.#stars;
	}

	setStars(stars)
	{
		this.#stars = stars;
		return this;
	}
	#featureScore = 0;

	getFeatureScore()
	{
		return this.#featureScore;
	}

	setFeatureScore(featureScore)
	{
		this.#featureScore = featureScore;
		return this;
	}
	#copyPassword = 0;

	getCopyPassword()
	{
		return this.#copyPassword;
	}

	setCopyPassword(copyPassword)
	{
		this.#copyPassword = copyPassword;
		return this;
	}
	#originalLevelId = 0;

	getOriginalLevelId()
	{
		return this.#originalLevelId;
	}

	setOriginalLevelId(originalLevelId)
	{
		this.#originalLevelId = originalLevelId;
		return this;
	}
	#starsRequested = 0;

	getStarsRequested()
	{
		return this.#starsRequested;
	}

	setStarsRequested(starsRequested)
	{
		this.#starsRequested = starsRequested;
		return this;
	}
	#copiedId = 0;

	getCopiedId()
	{
		return this.#copiedId;
	}

	setCopiedId(copiedId)
	{
		this.#copiedId = copiedId;
		return this;
	}
	#dailyWeeklyNumber = 0;

	getDailyWeeklyNumber()
	{
		return this.#dailyWeeklyNumber;
	}

	setDailyWeeklyNumber(dailyWeeklyNumber)
	{
		this.#dailyWeeklyNumber = dailyWeeklyNumber;
		return this;
	}
	#epic = 0;

	getEpic()
	{
		return this.#epic;
	}

	setEpic(epic)
	{
		this.#epic = epic;
		return this;
	}
	#editorTime = 0;

	getEditorTime()
	{
		return this.#editorTime;
	}

	setEditorTime(editorTime)
	{
		this.#editorTime = editorTime;
		return this;
	}
	#editorTimeCopies = 0;

	getEditorTimeCopies()
	{
		return this.#editorTimeCopies;
	}

	setEditorTimeCopies(editorTimeCopies)
	{
		this.#editorTimeCopies = editorTimeCopies;
		return this;
	}
	#levelDifficulty = DifficultyFaces.NA;

	getLevelDifficulty()
	{
		return this.#levelDifficulty;
	}

	setLevelDifficulty(levelDifficulty)
	{
		this.#levelDifficulty = levelDifficulty;
		return this;
	}
	#demonDifficulty = DemonFaces.NA;

	getDemonDifficulty()
	{
		return this.#demonDifficulty;
	}

	setDemonDifficulty(demonDifficulty)
	{
		this.#demonDifficulty = demonDifficulty;
		return this;
	}
	#levelDuration = LevelLength.NA;

	getLevelLength()
	{
		return this.#levelDuration;
	}

	setLevelLength(levelLength)
	{
		this.#levelDuration = levelLength;
		return this;
	}
	#isUnlisted = false;

	getIsUnlisted()
	{
		return this.#isUnlisted;
	}

	setIsUnlisted(isUnlisted)
	{
		this.#isUnlisted = isUnlisted;
		return this;
	}
	#isFriendsOnly = false;

	getIsFriendsOnly()
	{
		return this.#isFriendsOnly;
	}

	setIsFriendsOnly(isFriendsOnly)
	{
		this.#isFriendsOnly = isFriendsOnly;
		return this;
	}
	#isGauntletLevel = false;

	getIsGauntletLevel()
	{
		return this.#isGauntletLevel;
	}

	setIsGauntletLevel(isGauntletLevel)
	{
		this.#isGauntletLevel = isGauntletLevel;
		return this;
	}
	#m_hasLowDetail = false;

	getHasLowDetail()
	{
		return this.#m_hasLowDetail;
	}

	setHasLowDetail(hasLowDetail)
	{
		this.#m_hasLowDetail = hasLowDetail;
		return this;
	}
	#isUnrated = false;

	getIsUnrated()
	{
		return this.#isUnrated;
	}

	setIsUnrated(isUnrated)
	{
		this.#isUnrated = isUnrated;
		return this;
	}
	#isFeatured = false;

	getIsFeatured()
	{
		return this.#isFeatured;
	}

	setIsFeatured(isFeatured)
	{
		this.#isFeatured = isFeatured;
		return this;
	}
	#isAuto = false;

	getIsAuto()
	{
		return this.#isAuto;
	}

	setIsAuto(isAuto)
	{
		this.#isAuto = isAuto;
		return this;
	}
	#isDemon = false;

	getIsDemon()
	{
		return this.#isDemon;
	}

	setIsDemon(isDemon)
	{
		this.#isDemon = isDemon;
		return this;
	}
	#isCoinsVerified = false;

	getIsCoinsVerified()
	{
		return this.#isCoinsVerified;
	}

	setIsCoinsVerified(isCoinsVerified)
	{
		this.#isCoinsVerified = isCoinsVerified;
		return this;
	}
	#isTwoPlayer = false;

	getIsTwoPlayer()
	{
		return this.#isTwoPlayer;
	}

	setIsTwoPlayer(isTwoPlayer)
	{
		this.#isTwoPlayer = isTwoPlayer;
		return this;
	}
	#m_verifiedCoins = false;

	getVerifiedCoins()
	{
		return this.#m_verifiedCoins;
	}

	setVerifiedCoins(verifiedCoins)
	{
		this.#m_verifiedCoins = verifiedCoins;
		return this;
	}
}
