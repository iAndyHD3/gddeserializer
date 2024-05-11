// Generated automatically with "fut". Do not edit.
using System.Collections.Generic;
namespace gdd
{

	enum DifficultyFaces
	{
		na,
		auto,
		easy,
		normal,
		hard,
		harder,
		insane,
		demon
	}

	enum DemonFaces
	{
		na,
		easy,
		medium,
		hard,
		insane,
		extreme
	}

	enum LevelLength
	{
		na,
		Tiny,
		Short,
		Medium,
		Long,
		XL
	}

	enum LevelType
	{
		na,
		Normal,
		Gauntlet,
		Weekly,
		Daily,
		Event
	}

	public class GJGameLevel
	{

		public const string prop_settingsString = "48";

		public const string prop_editorTime2 = "47";

		public const string prop_editorTime = "46";

		public const string prop_objectCount = "45";

		public const string prop_isGauntlet = "44";

		public const string prop_demonDifficulty = "43";

		public const string prop_epic = "42";

		public const string prop_dailyNumber = "41";

		public const string prop_lowDetailMode = "40";

		public const string prop_starsRequested = "39";

		public const string prop_verifiedCoins = "38";

		public const string prop_coins = "37";

		public const string prop_extraString = "36";

		public const string prop_customSongId = "35";

		public const string prop_twoPlayer = "31";

		public const string prop_copiedId = "30";

		public const string prop_updateDate = "29";

		public const string prop_uploadDate = "28";

		public const string prop_password = "27";

		public const string prop_recordString = "26";

		public const string prop_auto = "25";

		public const string prop_featureScore = "19";

		public const string prop_stars = "18";

		public const string prop_is_demon = "17";

		public const string prop_dislikes = "16";

		public const string prop_length = "15";

		public const string prop_likes = "14";

		public const string prop_gameVersion = "13";

		public const string prop_officialSong = "12";

		public const string prop_setCompletes = "11";

		public const string prop_downloads = "10";

		public const string prop_difficultyNumerator = "9";

		public const string prop_difficultyDenominator = "8";

		public const string prop_playerId = "6";

		public const string prop_version = "5";

		public const string prop_levelString = "4";

		public const string prop_description = "3";

		public const string prop_levelname = "2";

		public const string prop_levelId = "1";

		public static int tryParse(string str, int defaultVal = 0)
		{
			int result = 0;
			int sign = 1;
			int i = 0;
			int len = str.Length;
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

		public static int FindDelimiterIndex(string str, string delimiter, int startPos)
		{
			int len = str.Length;
			int delimiterLen = delimiter.Length;
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

		public static List<string> Split(string str, string delimiter)
		{
			List<string> ret = new List<string>();
			int pos = 0;
			int len = str.Length;
			int delimiterLen = delimiter.Length;
			while (pos < len) {
				int end = FindDelimiterIndex(str, delimiter, pos);
				if (end == -1) {
					ret.Add(str.Substring(pos));
					break;
				}
				ret.Add(str.Substring(pos, end - pos));
				pos = end + delimiterLen;
			}
			return ret;
		}

		public void addFromObjectString(string response)
		{
			List<string> level_fields = Split(response, ":");
			for (int i = 0; i < level_fields.Count; i += 2) {
				string val = level_fields[i + 1];
				if (val.Length == 0)
					continue;
				switch (level_fields[i]) {
				case "1":
					this.LevelId = tryParse(val, 0);
					break;
				case "2":
					this.LevelName = val;
					break;
				case "3":
					this.LevelDesc = val;
					break;
				case "4":
					this.LevelString = val;
					break;
				case "5":
					this.LevelVersion = tryParse(val);
					break;
				case "6":
					this.PlayerId = tryParse(val);
					break;
				case "9":
					{
						int temp = tryParse(val, -1);
						if (temp == -1)
							break;
						switch (temp) {
						case 0:
							this.LevelDifficulty = DifficultyFaces.na;
							break;
						case 10:
							this.LevelDifficulty = DifficultyFaces.easy;
							break;
						case 20:
							this.LevelDifficulty = DifficultyFaces.normal;
							break;
						case 30:
							this.LevelDifficulty = DifficultyFaces.hard;
							break;
						case 40:
							this.LevelDifficulty = DifficultyFaces.harder;
							break;
						case 50:
							this.LevelDifficulty = DifficultyFaces.insane;
							break;
						default:
							this.LevelDifficulty = DifficultyFaces.na;
							break;
						}
						break;
					}
				case "10":
					this.Downloads = tryParse(val);
					break;
				case "12":
					this.OfficialSongId = tryParse(val);
					break;
				case "13":
					this.GameVersion = tryParse(val);
					break;
				case "14":
					this.Likes = tryParse(val);
					break;
				case "15":
					{
						int temp = tryParse(val, -1);
						if (temp == -1)
							break;
						switch (temp) {
						case 0:
							this.LevelDuration = LevelLength.Tiny;
							break;
						case 1:
							this.LevelDuration = LevelLength.Short;
							break;
						case 2:
							this.LevelDuration = LevelLength.Medium;
							break;
						case 3:
							this.LevelDuration = LevelLength.Long;
							break;
						case 4:
							this.LevelDuration = LevelLength.XL;
							break;
						default:
							this.LevelDuration = LevelLength.na;
							break;
						}
						break;
					}
				case "16":
					this.Dislikes = tryParse(val);
					break;
				case "17":
					this.IsDemon = tryParse(val) == 1;
					break;
				case "18":
					this.Stars = tryParse(val);
					break;
				case "19":
					this.FeatureScore = tryParse(val);
					break;
				case "25":
					this.IsAuto = tryParse(val) == 1;
					break;
				case "28":
					this.UploadDate = val;
					break;
				case "29":
					this.UpdateDate = val;
					break;
				case "30":
					this.CopiedId = tryParse(val);
					break;
				case "35":
					this.SongId = tryParse(val);
					break;
				case "37":
					this.Coins = tryParse(val);
					break;
				case "38":
					this.m_verifiedCoins = tryParse(val) == 1;
					break;
				case "41":
					this.DailyWeeklyNumber = tryParse(val);
					break;
				case "42":
					this.Epic = tryParse(val);
					break;
				case "43":
					{
						int temp = tryParse(val, -1);
						if (temp == -1)
							break;
						switch (temp) {
						case 0:
							this.DemonDifficulty = DemonFaces.hard;
							break;
						case 3:
							this.DemonDifficulty = DemonFaces.easy;
							break;
						case 4:
							this.DemonDifficulty = DemonFaces.medium;
							break;
						case 5:
							this.DemonDifficulty = DemonFaces.insane;
							break;
						case 6:
							this.DemonDifficulty = DemonFaces.extreme;
							break;
						default:
							this.DemonDifficulty = DemonFaces.na;
							break;
						}
						break;
					}
				case "44":
					this.IsGauntletLevel = tryParse(val) == 1;
					break;
				case "45":
					this.ObjectCount = tryParse(val);
					break;
				case "46":
					this.EditorTime = tryParse(val);
					break;
				case "47":
					this.EditorTimeCopies = tryParse(val);
					break;
				}
				if (!this.IsDemon) {
					this.DemonDifficulty = DemonFaces.na;
				}
				else {
					this.LevelDifficulty = DifficultyFaces.demon;
				}
			}
		}

		public static List<GJGameLevel> createFromGjlevels21Response(string response)
		{
			List<GJGameLevel> ret = new List<GJGameLevel>();
			List<string> resp_parts = Split(response, "#");
			if (resp_parts.Count == 1)
				return ret;
			List<string> level_objects_strs = Split(resp_parts[0], "|");
			if (level_objects_strs.Count == 1)
				return ret;
			foreach (string level_object_str in level_objects_strs) {
				ret.Add(new GJGameLevel());
				GJGameLevel level = ret[^1];
				level.addFromObjectString(level_object_str);
				if (level.LevelId <= 0) {
					ret.RemoveAt(ret.Count);
				}
			}
			return ret;
		}

		string LevelName = "";

		public string getLevelName() => this.LevelName;

		public GJGameLevel setLevelname(string levelname)
		{
			this.LevelName = levelname;
			return this;
		}

		string LevelString = "";

		public string getLevelString() => this.LevelString;

		public GJGameLevel setLevelString(string levelDesc)
		{
			this.LevelString = levelDesc;
			return this;
		}

		string LevelDesc = "";

		public string getDescription() => this.LevelDesc;

		public GJGameLevel setDescription(string desc)
		{
			this.LevelDesc = desc;
			return this;
		}

		string CreatorName = "";

		public string getCreatorName() => this.CreatorName;

		public GJGameLevel setCreatorname(string creatorname)
		{
			this.CreatorName = creatorname;
			return this;
		}

		string UploadDate = "";

		public string getUploadDate() => this.UploadDate;

		public GJGameLevel setUploadDate(string uploadDate)
		{
			this.UploadDate = uploadDate;
			return this;
		}

		string UpdateDate = "";

		public string getUpdateDate() => this.UpdateDate;

		public GJGameLevel setUpdateDate(string updateDate)
		{
			this.UpdateDate = updateDate;
			return this;
		}

		int PlayerId = 0;

		public int getPlayerId() => this.PlayerId;

		public GJGameLevel setPlayerId(int playerId)
		{
			this.PlayerId = playerId;
			return this;
		}

		int AccountId = 0;

		public int getAccountId() => this.AccountId;

		public GJGameLevel setAccountId(int accountId)
		{
			this.AccountId = accountId;
			return this;
		}

		int LevelId = 0;

		public int getLevelId() => this.LevelId;

		public GJGameLevel setLevelId(int levelId)
		{
			this.LevelId = levelId;
			return this;
		}

		int SongId = 0;

		public int getSongId() => this.SongId;

		public GJGameLevel setSongId(int songId)
		{
			this.SongId = songId;
			return this;
		}

		int LevelRev = 0;

		public int getLevelRev() => this.LevelRev;

		public GJGameLevel setLevelRev(int levelRev)
		{
			this.LevelRev = levelRev;
			return this;
		}

		int ObjectCount = 0;

		public int getObjectCount() => this.ObjectCount;

		public GJGameLevel setObjectCount(int objectCount)
		{
			this.ObjectCount = objectCount;
			return this;
		}

		int Downloads = 0;

		public int getDownloads() => this.Downloads;

		public GJGameLevel setDownloads(int downloads)
		{
			this.Downloads = downloads;
			return this;
		}

		int OfficialSongId = 0;

		public int getOfficialSong() => this.OfficialSongId;

		public GJGameLevel setOfficialSong(int officialSong)
		{
			this.OfficialSongId = officialSong;
			return this;
		}

		int Likes = 0;

		public int getLikes() => this.Likes;

		public GJGameLevel setLikes(int likes)
		{
			this.Likes = likes;
			return this;
		}

		int Dislikes = 0;

		public int getDislikes() => this.Dislikes;

		public GJGameLevel setDislikes(int dislikes)
		{
			this.Dislikes = dislikes;
			return this;
		}

		int WorkingTime = 0;

		public int getWorkingTime() => this.WorkingTime;

		public GJGameLevel setWorkingTime(int workingTime)
		{
			this.WorkingTime = workingTime;
			return this;
		}

		int LevelVersion = 0;

		public int getLevelVersion() => this.LevelVersion;

		public GJGameLevel setLevelVersion(int levelVersion)
		{
			this.LevelVersion = levelVersion;
			return this;
		}

		int GameVersion = 0;

		public int getGameVersion() => this.GameVersion;

		public GJGameLevel setGameVersion(int gameVersion)
		{
			this.GameVersion = gameVersion;
			return this;
		}

		int Coins = 0;

		public int getCoins() => this.Coins;

		public GJGameLevel setCoins(int coins)
		{
			this.Coins = coins;
			return this;
		}

		int Stars = 0;

		public int getStars() => this.Stars;

		public GJGameLevel setStars(int stars)
		{
			this.Stars = stars;
			return this;
		}

		int FeatureScore = 0;

		public int getFeatureScore() => this.FeatureScore;

		public GJGameLevel setFeatureScore(int featureScore)
		{
			this.FeatureScore = featureScore;
			return this;
		}

		int CopyPassword = 0;

		public int getCopyPassword() => this.CopyPassword;

		public GJGameLevel setCopyPassword(int copyPassword)
		{
			this.CopyPassword = copyPassword;
			return this;
		}

		int OriginalLevelId = 0;

		public int getOriginalLevelId() => this.OriginalLevelId;

		public GJGameLevel setOriginalLevelId(int originalLevelId)
		{
			this.OriginalLevelId = originalLevelId;
			return this;
		}

		int StarsRequested = 0;

		public int getStarsRequested() => this.StarsRequested;

		public GJGameLevel setStarsRequested(int starsRequested)
		{
			this.StarsRequested = starsRequested;
			return this;
		}

		int CopiedId = 0;

		public int getCopiedId() => this.CopiedId;

		public GJGameLevel setCopiedId(int copiedId)
		{
			this.CopiedId = copiedId;
			return this;
		}

		int DailyWeeklyNumber = 0;

		public int getDailyWeeklyNumber() => this.DailyWeeklyNumber;

		public GJGameLevel setDailyWeeklyNumber(int dailyWeeklyNumber)
		{
			this.DailyWeeklyNumber = dailyWeeklyNumber;
			return this;
		}

		int Epic = 0;

		public int getEpic() => this.Epic;

		public GJGameLevel setEpic(int epic)
		{
			this.Epic = epic;
			return this;
		}

		int EditorTime = 0;

		public int getEditorTime() => this.EditorTime;

		public GJGameLevel setEditorTime(int editorTime)
		{
			this.EditorTime = editorTime;
			return this;
		}

		int EditorTimeCopies = 0;

		public int getEditorTimeCopies() => this.EditorTimeCopies;

		public GJGameLevel setEditorTimeCopies(int editorTimeCopies)
		{
			this.EditorTimeCopies = editorTimeCopies;
			return this;
		}

		DifficultyFaces LevelDifficulty = DifficultyFaces.na;

		public DifficultyFaces getLevelDifficulty() => this.LevelDifficulty;

		public GJGameLevel setLevelDifficulty(DifficultyFaces levelDifficulty)
		{
			this.LevelDifficulty = levelDifficulty;
			return this;
		}

		DemonFaces DemonDifficulty = DemonFaces.na;

		public DemonFaces getDemonDifficulty() => this.DemonDifficulty;

		public GJGameLevel setDemonDifficulty(DemonFaces demonDifficulty)
		{
			this.DemonDifficulty = demonDifficulty;
			return this;
		}

		LevelLength LevelDuration = LevelLength.na;

		public LevelLength getLevelLength() => this.LevelDuration;

		public GJGameLevel setLevelLength(LevelLength levelLength)
		{
			this.LevelDuration = levelLength;
			return this;
		}

		bool IsUnlisted = false;

		public bool getIsUnlisted() => this.IsUnlisted;

		public GJGameLevel setIsUnlisted(bool isUnlisted)
		{
			this.IsUnlisted = isUnlisted;
			return this;
		}

		bool IsFriendsOnly = false;

		public bool getIsFriendsOnly() => this.IsFriendsOnly;

		public GJGameLevel setIsFriendsOnly(bool isFriendsOnly)
		{
			this.IsFriendsOnly = isFriendsOnly;
			return this;
		}

		bool IsGauntletLevel = false;

		public bool getIsGauntletLevel() => this.IsGauntletLevel;

		public GJGameLevel setIsGauntletLevel(bool isGauntletLevel)
		{
			this.IsGauntletLevel = isGauntletLevel;
			return this;
		}

		bool m_hasLowDetail = false;

		public bool getHasLowDetail() => this.m_hasLowDetail;

		public GJGameLevel setHasLowDetail(bool hasLowDetail)
		{
			this.m_hasLowDetail = hasLowDetail;
			return this;
		}

		bool IsUnrated = false;

		public bool getIsUnrated() => this.IsUnrated;

		public GJGameLevel setIsUnrated(bool isUnrated)
		{
			this.IsUnrated = isUnrated;
			return this;
		}

		bool IsFeatured = false;

		public bool getIsFeatured() => this.IsFeatured;

		public GJGameLevel setIsFeatured(bool isFeatured)
		{
			this.IsFeatured = isFeatured;
			return this;
		}

		bool IsAuto = false;

		public bool getIsAuto() => this.IsAuto;

		public GJGameLevel setIsAuto(bool isAuto)
		{
			this.IsAuto = isAuto;
			return this;
		}

		bool IsDemon = false;

		public bool getIsDemon() => this.IsDemon;

		public GJGameLevel setIsDemon(bool isDemon)
		{
			this.IsDemon = isDemon;
			return this;
		}

		bool IsCoinsVerified = false;

		public bool getIsCoinsVerified() => this.IsCoinsVerified;

		public GJGameLevel setIsCoinsVerified(bool isCoinsVerified)
		{
			this.IsCoinsVerified = isCoinsVerified;
			return this;
		}

		bool IsTwoPlayer = false;

		public bool getIsTwoPlayer() => this.IsTwoPlayer;

		public GJGameLevel setIsTwoPlayer(bool isTwoPlayer)
		{
			this.IsTwoPlayer = isTwoPlayer;
			return this;
		}

		bool m_verifiedCoins = false;

		public bool getVerifiedCoins() => this.m_verifiedCoins;

		public GJGameLevel setVerifiedCoins(bool verifiedCoins)
		{
			this.m_verifiedCoins = verifiedCoins;
			return this;
		}
	}
}
