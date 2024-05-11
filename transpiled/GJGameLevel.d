// Generated automatically with "fut". Do not edit.
import std.container.array;

private void removeAt(T)(Array!T* arr, size_t pos, size_t count = 1)
{
	arr.linearRemove((*arr)[pos .. pos + count]);
}
struct gdd
{
	static:

	enum DifficultyFaces{
		na,
		auto_,
		easy,
		normal,
		hard,
		harder,
		insane,
		demon
	}

	enum DemonFaces{
		na,
		easy,
		medium,
		hard,
		insane,
		extreme
	}

	enum LevelLength{
		na,
		tiny,
		short_,
		medium,
		long_,
		xL
	}

	enum LevelType{
		na,
		normal,
		gauntlet,
		weekly,
		daily,
		event
	}

	class GJGameLevel
	{
		private this()
		{
		}
		static immutable string prop_settingsString = "48";
		static immutable string prop_editorTime2 = "47";
		static immutable string prop_editorTime = "46";
		static immutable string prop_objectCount = "45";
		static immutable string prop_isGauntlet = "44";
		static immutable string prop_demonDifficulty = "43";
		static immutable string prop_epic = "42";
		static immutable string prop_dailyNumber = "41";
		static immutable string prop_lowDetailMode = "40";
		static immutable string prop_starsRequested = "39";
		static immutable string prop_verifiedCoins = "38";
		static immutable string prop_coins = "37";
		static immutable string prop_extraString = "36";
		static immutable string prop_customSongId = "35";
		static immutable string prop_twoPlayer = "31";
		static immutable string prop_copiedId = "30";
		static immutable string prop_updateDate = "29";
		static immutable string prop_uploadDate = "28";
		static immutable string prop_password = "27";
		static immutable string prop_recordString = "26";
		static immutable string prop_auto = "25";
		static immutable string prop_featureScore = "19";
		static immutable string prop_stars = "18";
		static immutable string prop_is_demon = "17";
		static immutable string prop_dislikes = "16";
		static immutable string prop_length = "15";
		static immutable string prop_likes = "14";
		static immutable string prop_gameVersion = "13";
		static immutable string prop_officialSong = "12";
		static immutable string prop_setCompletes = "11";
		static immutable string prop_downloads = "10";
		static immutable string prop_difficultyNumerator = "9";
		static immutable string prop_difficultyDenominator = "8";
		static immutable string prop_playerId = "6";
		static immutable string prop_version = "5";
		static immutable string prop_levelString = "4";
		static immutable string prop_description = "3";
		static immutable string prop_levelname = "2";
		static immutable string prop_levelId = "1";

		static int tryParse(string str, int defaultVal = 0)
		{
			int result = 0;
			int sign = 1;
			int i = 0;
			int len = cast(int)(str.length);
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

		static int findDelimiterIndex(string str, string delimiter, int startPos)
		{
			int len = cast(int)(str.length);
			int delimiterLen = cast(int)(delimiter.length);
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

		static Array!(string)* split(string str, string delimiter)
		{
			Array!(string)* ret = new Array!(string);
			int pos = 0;
			int len = cast(int)(str.length);
			int delimiterLen = cast(int)(delimiter.length);
			while (pos < len) {
				int end = findDelimiterIndex(str, delimiter, pos);
				if (end == -1) {
					ret.insertBack(str[pos .. $]);
					break;
				}
				ret.insertBack(str[pos .. $][0 .. end - pos]);
				pos = end + delimiterLen;
			}
			return ret;
		}

		void addFromObjectString(string response)
		{
			Array!(string)* level_fields = split(response, ":");
			for (int i = 0; i < level_fields.length; i += 2) {
				string val = (*level_fields)[i + 1];
				if (val.length == 0)
					continue;
				switch ((*level_fields)[i]) {
				case "1":
					this.levelId = tryParse(val, 0);
					break;
				case "2":
					this.levelName = val;
					break;
				case "3":
					this.levelDesc = val;
					break;
				case "4":
					this.levelString = val;
					break;
				case "5":
					this.levelVersion = tryParse(val);
					break;
				case "6":
					this.playerId = tryParse(val);
					break;
				case "9":
					{
						int temp = tryParse(val, -1);
						if (temp == -1)
							break;
						switch (temp) {
						case 0:
							this.levelDifficulty = DifficultyFaces.na;
							break;
						case 10:
							this.levelDifficulty = DifficultyFaces.easy;
							break;
						case 20:
							this.levelDifficulty = DifficultyFaces.normal;
							break;
						case 30:
							this.levelDifficulty = DifficultyFaces.hard;
							break;
						case 40:
							this.levelDifficulty = DifficultyFaces.harder;
							break;
						case 50:
							this.levelDifficulty = DifficultyFaces.insane;
							break;
						default:
							this.levelDifficulty = DifficultyFaces.na;
							break;
						}
						break;
					}
				case "10":
					this.downloads = tryParse(val);
					break;
				case "12":
					this.officialSongId = tryParse(val);
					break;
				case "13":
					this.gameVersion = tryParse(val);
					break;
				case "14":
					this.likes = tryParse(val);
					break;
				case "15":
					{
						int temp = tryParse(val, -1);
						if (temp == -1)
							break;
						switch (temp) {
						case 0:
							this.levelDuration = LevelLength.tiny;
							break;
						case 1:
							this.levelDuration = LevelLength.short_;
							break;
						case 2:
							this.levelDuration = LevelLength.medium;
							break;
						case 3:
							this.levelDuration = LevelLength.long_;
							break;
						case 4:
							this.levelDuration = LevelLength.xL;
							break;
						default:
							this.levelDuration = LevelLength.na;
							break;
						}
						break;
					}
				case "16":
					this.dislikes = tryParse(val);
					break;
				case "17":
					this.isDemon = tryParse(val) == 1;
					break;
				case "18":
					this.stars = tryParse(val);
					break;
				case "19":
					this.featureScore = tryParse(val);
					break;
				case "25":
					this.isAuto = tryParse(val) == 1;
					break;
				case "28":
					this.uploadDate = val;
					break;
				case "29":
					this.updateDate = val;
					break;
				case "30":
					this.copiedId = tryParse(val);
					break;
				case "35":
					this.songId = tryParse(val);
					break;
				case "37":
					this.coins = tryParse(val);
					break;
				case "38":
					this.m_verifiedCoins = tryParse(val) == 1;
					break;
				case "41":
					this.dailyWeeklyNumber = tryParse(val);
					break;
				case "42":
					this.epic = tryParse(val);
					break;
				case "43":
					{
						int temp = tryParse(val, -1);
						if (temp == -1)
							break;
						switch (temp) {
						case 0:
							this.demonDifficulty = DemonFaces.hard;
							break;
						case 3:
							this.demonDifficulty = DemonFaces.easy;
							break;
						case 4:
							this.demonDifficulty = DemonFaces.medium;
							break;
						case 5:
							this.demonDifficulty = DemonFaces.insane;
							break;
						case 6:
							this.demonDifficulty = DemonFaces.extreme;
							break;
						default:
							this.demonDifficulty = DemonFaces.na;
							break;
						}
						break;
					}
				case "44":
					this.isGauntletLevel = tryParse(val) == 1;
					break;
				case "45":
					this.objectCount = tryParse(val);
					break;
				case "46":
					this.editorTime = tryParse(val);
					break;
				case "47":
					this.editorTimeCopies = tryParse(val);
					break;
				default:
					assert(false);
				}
				if (!this.isDemon) {
					this.demonDifficulty = DemonFaces.na;
				}
				else {
					this.levelDifficulty = DifficultyFaces.demon;
				}
			}
		}

		static Array!(GJGameLevel)* createFromGjlevels21Response(string response)
		{
			Array!(GJGameLevel)* ret = new Array!(GJGameLevel);
			Array!(string)* resp_parts = split(response, "#");
			if (resp_parts.length == 1)
				return ret;
			Array!(string)* level_objects_strs = split((*resp_parts)[0], "|");
			if (level_objects_strs.length == 1)
				return ret;
			foreach (string level_object_str; (*level_objects_strs)) {
				ret.insertBack(new GJGameLevel);
				GJGameLevel level = ret.back;
				level.addFromObjectString(level_object_str);
				if (level.levelId <= 0) {
					ret.removeAt(cast(int)(ret.length));
				}
			}
			return ret;
		}

		private string levelName = "";

		string getLevelName() => this.levelName;

		GJGameLevel setLevelname(string levelname)
		{
			this.levelName = levelname;
			return this;
		}

		private string levelString = "";

		string getLevelString() => this.levelString;

		GJGameLevel setLevelString(string levelDesc)
		{
			this.levelString = levelDesc;
			return this;
		}

		private string levelDesc = "";

		string getDescription() => this.levelDesc;

		GJGameLevel setDescription(string desc)
		{
			this.levelDesc = desc;
			return this;
		}

		private string creatorName = "";

		string getCreatorName() => this.creatorName;

		GJGameLevel setCreatorname(string creatorname)
		{
			this.creatorName = creatorname;
			return this;
		}

		private string uploadDate = "";

		string getUploadDate() => this.uploadDate;

		GJGameLevel setUploadDate(string uploadDate)
		{
			this.uploadDate = uploadDate;
			return this;
		}

		private string updateDate = "";

		string getUpdateDate() => this.updateDate;

		GJGameLevel setUpdateDate(string updateDate)
		{
			this.updateDate = updateDate;
			return this;
		}

		private int playerId = 0;

		int getPlayerId() => this.playerId;

		GJGameLevel setPlayerId(int playerId)
		{
			this.playerId = playerId;
			return this;
		}

		private int accountId = 0;

		int getAccountId() => this.accountId;

		GJGameLevel setAccountId(int accountId)
		{
			this.accountId = accountId;
			return this;
		}

		private int levelId = 0;

		int getLevelId() => this.levelId;

		GJGameLevel setLevelId(int levelId)
		{
			this.levelId = levelId;
			return this;
		}

		private int songId = 0;

		int getSongId() => this.songId;

		GJGameLevel setSongId(int songId)
		{
			this.songId = songId;
			return this;
		}

		private int levelRev = 0;

		int getLevelRev() => this.levelRev;

		GJGameLevel setLevelRev(int levelRev)
		{
			this.levelRev = levelRev;
			return this;
		}

		private int objectCount = 0;

		int getObjectCount() => this.objectCount;

		GJGameLevel setObjectCount(int objectCount)
		{
			this.objectCount = objectCount;
			return this;
		}

		private int downloads = 0;

		int getDownloads() => this.downloads;

		GJGameLevel setDownloads(int downloads)
		{
			this.downloads = downloads;
			return this;
		}

		private int officialSongId = 0;

		int getOfficialSong() => this.officialSongId;

		GJGameLevel setOfficialSong(int officialSong)
		{
			this.officialSongId = officialSong;
			return this;
		}

		private int likes = 0;

		int getLikes() => this.likes;

		GJGameLevel setLikes(int likes)
		{
			this.likes = likes;
			return this;
		}

		private int dislikes = 0;

		int getDislikes() => this.dislikes;

		GJGameLevel setDislikes(int dislikes)
		{
			this.dislikes = dislikes;
			return this;
		}

		private int workingTime = 0;

		int getWorkingTime() => this.workingTime;

		GJGameLevel setWorkingTime(int workingTime)
		{
			this.workingTime = workingTime;
			return this;
		}

		private int levelVersion = 0;

		int getLevelVersion() => this.levelVersion;

		GJGameLevel setLevelVersion(int levelVersion)
		{
			this.levelVersion = levelVersion;
			return this;
		}

		private int gameVersion = 0;

		int getGameVersion() => this.gameVersion;

		GJGameLevel setGameVersion(int gameVersion)
		{
			this.gameVersion = gameVersion;
			return this;
		}

		private int coins = 0;

		int getCoins() => this.coins;

		GJGameLevel setCoins(int coins)
		{
			this.coins = coins;
			return this;
		}

		private int stars = 0;

		int getStars() => this.stars;

		GJGameLevel setStars(int stars)
		{
			this.stars = stars;
			return this;
		}

		private int featureScore = 0;

		int getFeatureScore() => this.featureScore;

		GJGameLevel setFeatureScore(int featureScore)
		{
			this.featureScore = featureScore;
			return this;
		}

		private int copyPassword = 0;

		int getCopyPassword() => this.copyPassword;

		GJGameLevel setCopyPassword(int copyPassword)
		{
			this.copyPassword = copyPassword;
			return this;
		}

		private int originalLevelId = 0;

		int getOriginalLevelId() => this.originalLevelId;

		GJGameLevel setOriginalLevelId(int originalLevelId)
		{
			this.originalLevelId = originalLevelId;
			return this;
		}

		private int starsRequested = 0;

		int getStarsRequested() => this.starsRequested;

		GJGameLevel setStarsRequested(int starsRequested)
		{
			this.starsRequested = starsRequested;
			return this;
		}

		private int copiedId = 0;

		int getCopiedId() => this.copiedId;

		GJGameLevel setCopiedId(int copiedId)
		{
			this.copiedId = copiedId;
			return this;
		}

		private int dailyWeeklyNumber = 0;

		int getDailyWeeklyNumber() => this.dailyWeeklyNumber;

		GJGameLevel setDailyWeeklyNumber(int dailyWeeklyNumber)
		{
			this.dailyWeeklyNumber = dailyWeeklyNumber;
			return this;
		}

		private int epic = 0;

		int getEpic() => this.epic;

		GJGameLevel setEpic(int epic)
		{
			this.epic = epic;
			return this;
		}

		private int editorTime = 0;

		int getEditorTime() => this.editorTime;

		GJGameLevel setEditorTime(int editorTime)
		{
			this.editorTime = editorTime;
			return this;
		}

		private int editorTimeCopies = 0;

		int getEditorTimeCopies() => this.editorTimeCopies;

		GJGameLevel setEditorTimeCopies(int editorTimeCopies)
		{
			this.editorTimeCopies = editorTimeCopies;
			return this;
		}

		private DifficultyFaces levelDifficulty;

		DifficultyFaces getLevelDifficulty() => this.levelDifficulty;

		GJGameLevel setLevelDifficulty(DifficultyFaces levelDifficulty)
		{
			this.levelDifficulty = levelDifficulty;
			return this;
		}

		private DemonFaces demonDifficulty;

		DemonFaces getDemonDifficulty() => this.demonDifficulty;

		GJGameLevel setDemonDifficulty(DemonFaces demonDifficulty)
		{
			this.demonDifficulty = demonDifficulty;
			return this;
		}

		private LevelLength levelDuration;

		LevelLength getLevelLength() => this.levelDuration;

		GJGameLevel setLevelLength(LevelLength levelLength)
		{
			this.levelDuration = levelLength;
			return this;
		}

		private bool isUnlisted = false;

		bool getIsUnlisted() => this.isUnlisted;

		GJGameLevel setIsUnlisted(bool isUnlisted)
		{
			this.isUnlisted = isUnlisted;
			return this;
		}

		private bool isFriendsOnly = false;

		bool getIsFriendsOnly() => this.isFriendsOnly;

		GJGameLevel setIsFriendsOnly(bool isFriendsOnly)
		{
			this.isFriendsOnly = isFriendsOnly;
			return this;
		}

		private bool isGauntletLevel = false;

		bool getIsGauntletLevel() => this.isGauntletLevel;

		GJGameLevel setIsGauntletLevel(bool isGauntletLevel)
		{
			this.isGauntletLevel = isGauntletLevel;
			return this;
		}

		private bool m_hasLowDetail = false;

		bool getHasLowDetail() => this.m_hasLowDetail;

		GJGameLevel setHasLowDetail(bool hasLowDetail)
		{
			this.m_hasLowDetail = hasLowDetail;
			return this;
		}

		private bool isUnrated = false;

		bool getIsUnrated() => this.isUnrated;

		GJGameLevel setIsUnrated(bool isUnrated)
		{
			this.isUnrated = isUnrated;
			return this;
		}

		private bool isFeatured = false;

		bool getIsFeatured() => this.isFeatured;

		GJGameLevel setIsFeatured(bool isFeatured)
		{
			this.isFeatured = isFeatured;
			return this;
		}

		private bool isAuto = false;

		bool getIsAuto() => this.isAuto;

		GJGameLevel setIsAuto(bool isAuto)
		{
			this.isAuto = isAuto;
			return this;
		}

		private bool isDemon = false;

		bool getIsDemon() => this.isDemon;

		GJGameLevel setIsDemon(bool isDemon)
		{
			this.isDemon = isDemon;
			return this;
		}

		private bool isCoinsVerified = false;

		bool getIsCoinsVerified() => this.isCoinsVerified;

		GJGameLevel setIsCoinsVerified(bool isCoinsVerified)
		{
			this.isCoinsVerified = isCoinsVerified;
			return this;
		}

		private bool isTwoPlayer = false;

		bool getIsTwoPlayer() => this.isTwoPlayer;

		GJGameLevel setIsTwoPlayer(bool isTwoPlayer)
		{
			this.isTwoPlayer = isTwoPlayer;
			return this;
		}

		private bool m_verifiedCoins = false;

		bool getVerifiedCoins() => this.m_verifiedCoins;

		GJGameLevel setVerifiedCoins(bool verifiedCoins)
		{
			this.m_verifiedCoins = verifiedCoins;
			return this;
		}
	}
}
