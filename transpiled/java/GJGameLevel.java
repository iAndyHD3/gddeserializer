// Generated automatically with "fut". Do not edit.
package gdd;
import java.util.ArrayList;

public class GJGameLevel
{

	public static final String PROP_SETTINGS_STRING = "48";

	public static final String PROP_EDITOR_TIME2 = "47";

	public static final String PROP_EDITOR_TIME = "46";

	public static final String PROP_OBJECT_COUNT = "45";

	public static final String PROP_IS_GAUNTLET = "44";

	public static final String PROP_DEMON_DIFFICULTY = "43";

	public static final String PROP_EPIC = "42";

	public static final String PROP_DAILY_NUMBER = "41";

	public static final String PROP_LOW_DETAIL_MODE = "40";

	public static final String PROP_STARS_REQUESTED = "39";

	public static final String PROP_VERIFIED_COINS = "38";

	public static final String PROP_COINS = "37";

	public static final String PROP_EXTRA_STRING = "36";

	public static final String PROP_CUSTOM_SONG_ID = "35";

	public static final String PROP_TWO_PLAYER = "31";

	public static final String PROP_COPIED_ID = "30";

	public static final String PROP_UPDATE_DATE = "29";

	public static final String PROP_UPLOAD_DATE = "28";

	public static final String PROP_PASSWORD = "27";

	public static final String PROP_RECORD_STRING = "26";

	public static final String PROP_AUTO = "25";

	public static final String PROP_FEATURE_SCORE = "19";

	public static final String PROP_STARS = "18";

	public static final String PROP_IS_DEMON = "17";

	public static final String PROP_DISLIKES = "16";

	public static final String PROP_LENGTH = "15";

	public static final String PROP_LIKES = "14";

	public static final String PROP_GAME_VERSION = "13";

	public static final String PROP_OFFICIAL_SONG = "12";

	public static final String PROP_SET_COMPLETES = "11";

	public static final String PROP_DOWNLOADS = "10";

	public static final String PROP_DIFFICULTY_NUMERATOR = "9";

	public static final String PROP_DIFFICULTY_DENOMINATOR = "8";

	public static final String PROP_PLAYER_ID = "6";

	public static final String PROP_VERSION = "5";

	public static final String PROP_LEVEL_STRING = "4";

	public static final String PROP_DESCRIPTION = "3";

	public static final String PROP_LEVELNAME = "2";

	public static final String PROP_LEVEL_ID = "1";

	public static int tryParse(String str, int defaultVal)
	{
		int result = 0;
		int sign = 1;
		int i = 0;
		int len = str.length();
		while (len > i && (str.charAt(i) == ' ' || str.charAt(i) == '\t' || str.charAt(i) == '\n')) {
			i++;
		}
		if (len > i && str.charAt(i) == '-') {
			sign = -1;
			i++;
		}
		while (len > i && str.charAt(i) == '0') {
			i++;
		}
		while (len > i && str.charAt(i) >= '0' && str.charAt(i) <= '9') {
			result = result * 10 + str.charAt(i) - '0';
			i++;
		}
		result = result * sign;
		return result == 0 ? defaultVal : result;
	}

	public static int tryParse(String str)
	{
		return tryParse(str, 0);
	}

	public static int findDelimiterIndex(String str, String delimiter, int startPos)
	{
		int len = str.length();
		int delimiterLen = delimiter.length();
		for (int i = startPos; i < len - delimiterLen + 1; i++) {
			boolean found = true;
			for (int j = 0; j < delimiterLen; j++) {
				if (str.charAt(i + j) != delimiter.charAt(j)) {
					found = false;
					break;
				}
			}
			if (found)
				return i;
		}
		return -1;
	}

	public static ArrayList<String> split(String str, String delimiter)
	{
		final ArrayList<String> ret = new ArrayList<String>();
		int pos = 0;
		int len = str.length();
		int delimiterLen = delimiter.length();
		while (pos < len) {
			int end = findDelimiterIndex(str, delimiter, pos);
			if (end == -1) {
				ret.add(str.substring(pos));
				break;
			}
			ret.add(str.substring(pos, pos + end - pos));
			pos = end + delimiterLen;
		}
		return ret;
	}

	public final void addFromObjectString(String response)
	{
		final ArrayList<String> level_fields = split(response, ":");
		for (int i = 0; i < level_fields.size(); i += 2) {
			String val = level_fields.get(i + 1);
			if (val.length() == 0)
				continue;
			switch (level_fields.get(i)) {
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
						this.levelDifficulty = DifficultyFaces.NA;
						break;
					case 10:
						this.levelDifficulty = DifficultyFaces.EASY;
						break;
					case 20:
						this.levelDifficulty = DifficultyFaces.NORMAL;
						break;
					case 30:
						this.levelDifficulty = DifficultyFaces.HARD;
						break;
					case 40:
						this.levelDifficulty = DifficultyFaces.HARDER;
						break;
					case 50:
						this.levelDifficulty = DifficultyFaces.INSANE;
						break;
					default:
						this.levelDifficulty = DifficultyFaces.NA;
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
						this.levelDuration = LevelLength.TINY;
						break;
					case 1:
						this.levelDuration = LevelLength.SHORT;
						break;
					case 2:
						this.levelDuration = LevelLength.MEDIUM;
						break;
					case 3:
						this.levelDuration = LevelLength.LONG;
						break;
					case 4:
						this.levelDuration = LevelLength.X_L;
						break;
					default:
						this.levelDuration = LevelLength.NA;
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
						this.demonDifficulty = DemonFaces.HARD;
						break;
					case 3:
						this.demonDifficulty = DemonFaces.EASY;
						break;
					case 4:
						this.demonDifficulty = DemonFaces.MEDIUM;
						break;
					case 5:
						this.demonDifficulty = DemonFaces.INSANE;
						break;
					case 6:
						this.demonDifficulty = DemonFaces.EXTREME;
						break;
					default:
						this.demonDifficulty = DemonFaces.NA;
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
			}
			if (!this.isDemon) {
				this.demonDifficulty = DemonFaces.NA;
			}
			else {
				this.levelDifficulty = DifficultyFaces.DEMON;
			}
		}
	}

	public static ArrayList<GJGameLevel> createFromGjlevels21Response(String response)
	{
		final ArrayList<GJGameLevel> ret = new ArrayList<GJGameLevel>();
		final ArrayList<String> resp_parts = split(response, "#");
		if (resp_parts.size() == 1)
			return ret;
		final ArrayList<String> level_objects_strs = split(resp_parts.get(0), "|");
		if (level_objects_strs.size() == 1)
			return ret;
		for (String level_object_str : level_objects_strs) {
			ret.add(new GJGameLevel());
			GJGameLevel level = ret.get(ret.size() - 1);
			level.addFromObjectString(level_object_str);
			if (level.levelId <= 0) {
				ret.remove(ret.size());
			}
		}
		return ret;
	}
	private String levelName = "";

	public final String getLevelName()
	{
		return this.levelName;
	}

	public final GJGameLevel setLevelname(String levelname)
	{
		this.levelName = levelname;
		return this;
	}
	private String levelString = "";

	public final String getLevelString()
	{
		return this.levelString;
	}

	public final GJGameLevel setLevelString(String levelDesc)
	{
		this.levelString = levelDesc;
		return this;
	}
	private String levelDesc = "";

	public final String getDescription()
	{
		return this.levelDesc;
	}

	public final GJGameLevel setDescription(String desc)
	{
		this.levelDesc = desc;
		return this;
	}
	private String creatorName = "";

	public final String getCreatorName()
	{
		return this.creatorName;
	}

	public final GJGameLevel setCreatorname(String creatorname)
	{
		this.creatorName = creatorname;
		return this;
	}
	private String uploadDate = "";

	public final String getUploadDate()
	{
		return this.uploadDate;
	}

	public final GJGameLevel setUploadDate(String uploadDate)
	{
		this.uploadDate = uploadDate;
		return this;
	}
	private String updateDate = "";

	public final String getUpdateDate()
	{
		return this.updateDate;
	}

	public final GJGameLevel setUpdateDate(String updateDate)
	{
		this.updateDate = updateDate;
		return this;
	}
	private int playerId = 0;

	public final int getPlayerId()
	{
		return this.playerId;
	}

	public final GJGameLevel setPlayerId(int playerId)
	{
		this.playerId = playerId;
		return this;
	}
	private int accountId = 0;

	public final int getAccountId()
	{
		return this.accountId;
	}

	public final GJGameLevel setAccountId(int accountId)
	{
		this.accountId = accountId;
		return this;
	}
	private int levelId = 0;

	public final int getLevelId()
	{
		return this.levelId;
	}

	public final GJGameLevel setLevelId(int levelId)
	{
		this.levelId = levelId;
		return this;
	}
	private int songId = 0;

	public final int getSongId()
	{
		return this.songId;
	}

	public final GJGameLevel setSongId(int songId)
	{
		this.songId = songId;
		return this;
	}
	private int levelRev = 0;

	public final int getLevelRev()
	{
		return this.levelRev;
	}

	public final GJGameLevel setLevelRev(int levelRev)
	{
		this.levelRev = levelRev;
		return this;
	}
	private int objectCount = 0;

	public final int getObjectCount()
	{
		return this.objectCount;
	}

	public final GJGameLevel setObjectCount(int objectCount)
	{
		this.objectCount = objectCount;
		return this;
	}
	private int downloads = 0;

	public final int getDownloads()
	{
		return this.downloads;
	}

	public final GJGameLevel setDownloads(int downloads)
	{
		this.downloads = downloads;
		return this;
	}
	private int officialSongId = 0;

	public final int getOfficialSong()
	{
		return this.officialSongId;
	}

	public final GJGameLevel setOfficialSong(int officialSong)
	{
		this.officialSongId = officialSong;
		return this;
	}
	private int likes = 0;

	public final int getLikes()
	{
		return this.likes;
	}

	public final GJGameLevel setLikes(int likes)
	{
		this.likes = likes;
		return this;
	}
	private int dislikes = 0;

	public final int getDislikes()
	{
		return this.dislikes;
	}

	public final GJGameLevel setDislikes(int dislikes)
	{
		this.dislikes = dislikes;
		return this;
	}
	private int workingTime = 0;

	public final int getWorkingTime()
	{
		return this.workingTime;
	}

	public final GJGameLevel setWorkingTime(int workingTime)
	{
		this.workingTime = workingTime;
		return this;
	}
	private int levelVersion = 0;

	public final int getLevelVersion()
	{
		return this.levelVersion;
	}

	public final GJGameLevel setLevelVersion(int levelVersion)
	{
		this.levelVersion = levelVersion;
		return this;
	}
	private int gameVersion = 0;

	public final int getGameVersion()
	{
		return this.gameVersion;
	}

	public final GJGameLevel setGameVersion(int gameVersion)
	{
		this.gameVersion = gameVersion;
		return this;
	}
	private int coins = 0;

	public final int getCoins()
	{
		return this.coins;
	}

	public final GJGameLevel setCoins(int coins)
	{
		this.coins = coins;
		return this;
	}
	private int stars = 0;

	public final int getStars()
	{
		return this.stars;
	}

	public final GJGameLevel setStars(int stars)
	{
		this.stars = stars;
		return this;
	}
	private int featureScore = 0;

	public final int getFeatureScore()
	{
		return this.featureScore;
	}

	public final GJGameLevel setFeatureScore(int featureScore)
	{
		this.featureScore = featureScore;
		return this;
	}
	private int copyPassword = 0;

	public final int getCopyPassword()
	{
		return this.copyPassword;
	}

	public final GJGameLevel setCopyPassword(int copyPassword)
	{
		this.copyPassword = copyPassword;
		return this;
	}
	private int originalLevelId = 0;

	public final int getOriginalLevelId()
	{
		return this.originalLevelId;
	}

	public final GJGameLevel setOriginalLevelId(int originalLevelId)
	{
		this.originalLevelId = originalLevelId;
		return this;
	}
	private int starsRequested = 0;

	public final int getStarsRequested()
	{
		return this.starsRequested;
	}

	public final GJGameLevel setStarsRequested(int starsRequested)
	{
		this.starsRequested = starsRequested;
		return this;
	}
	private int copiedId = 0;

	public final int getCopiedId()
	{
		return this.copiedId;
	}

	public final GJGameLevel setCopiedId(int copiedId)
	{
		this.copiedId = copiedId;
		return this;
	}
	private int dailyWeeklyNumber = 0;

	public final int getDailyWeeklyNumber()
	{
		return this.dailyWeeklyNumber;
	}

	public final GJGameLevel setDailyWeeklyNumber(int dailyWeeklyNumber)
	{
		this.dailyWeeklyNumber = dailyWeeklyNumber;
		return this;
	}
	private int epic = 0;

	public final int getEpic()
	{
		return this.epic;
	}

	public final GJGameLevel setEpic(int epic)
	{
		this.epic = epic;
		return this;
	}
	private int editorTime = 0;

	public final int getEditorTime()
	{
		return this.editorTime;
	}

	public final GJGameLevel setEditorTime(int editorTime)
	{
		this.editorTime = editorTime;
		return this;
	}
	private int editorTimeCopies = 0;

	public final int getEditorTimeCopies()
	{
		return this.editorTimeCopies;
	}

	public final GJGameLevel setEditorTimeCopies(int editorTimeCopies)
	{
		this.editorTimeCopies = editorTimeCopies;
		return this;
	}
	private DifficultyFaces levelDifficulty = DifficultyFaces.NA;

	public final DifficultyFaces getLevelDifficulty()
	{
		return this.levelDifficulty;
	}

	public final GJGameLevel setLevelDifficulty(DifficultyFaces levelDifficulty)
	{
		this.levelDifficulty = levelDifficulty;
		return this;
	}
	private DemonFaces demonDifficulty = DemonFaces.NA;

	public final DemonFaces getDemonDifficulty()
	{
		return this.demonDifficulty;
	}

	public final GJGameLevel setDemonDifficulty(DemonFaces demonDifficulty)
	{
		this.demonDifficulty = demonDifficulty;
		return this;
	}
	private LevelLength levelDuration = LevelLength.NA;

	public final LevelLength getLevelLength()
	{
		return this.levelDuration;
	}

	public final GJGameLevel setLevelLength(LevelLength levelLength)
	{
		this.levelDuration = levelLength;
		return this;
	}
	private boolean isUnlisted = false;

	public final boolean getIsUnlisted()
	{
		return this.isUnlisted;
	}

	public final GJGameLevel setIsUnlisted(boolean isUnlisted)
	{
		this.isUnlisted = isUnlisted;
		return this;
	}
	private boolean isFriendsOnly = false;

	public final boolean getIsFriendsOnly()
	{
		return this.isFriendsOnly;
	}

	public final GJGameLevel setIsFriendsOnly(boolean isFriendsOnly)
	{
		this.isFriendsOnly = isFriendsOnly;
		return this;
	}
	private boolean isGauntletLevel = false;

	public final boolean getIsGauntletLevel()
	{
		return this.isGauntletLevel;
	}

	public final GJGameLevel setIsGauntletLevel(boolean isGauntletLevel)
	{
		this.isGauntletLevel = isGauntletLevel;
		return this;
	}
	private boolean m_hasLowDetail = false;

	public final boolean getHasLowDetail()
	{
		return this.m_hasLowDetail;
	}

	public final GJGameLevel setHasLowDetail(boolean hasLowDetail)
	{
		this.m_hasLowDetail = hasLowDetail;
		return this;
	}
	private boolean isUnrated = false;

	public final boolean getIsUnrated()
	{
		return this.isUnrated;
	}

	public final GJGameLevel setIsUnrated(boolean isUnrated)
	{
		this.isUnrated = isUnrated;
		return this;
	}
	private boolean isFeatured = false;

	public final boolean getIsFeatured()
	{
		return this.isFeatured;
	}

	public final GJGameLevel setIsFeatured(boolean isFeatured)
	{
		this.isFeatured = isFeatured;
		return this;
	}
	private boolean isAuto = false;

	public final boolean getIsAuto()
	{
		return this.isAuto;
	}

	public final GJGameLevel setIsAuto(boolean isAuto)
	{
		this.isAuto = isAuto;
		return this;
	}
	private boolean isDemon = false;

	public final boolean getIsDemon()
	{
		return this.isDemon;
	}

	public final GJGameLevel setIsDemon(boolean isDemon)
	{
		this.isDemon = isDemon;
		return this;
	}
	private boolean isCoinsVerified = false;

	public final boolean getIsCoinsVerified()
	{
		return this.isCoinsVerified;
	}

	public final GJGameLevel setIsCoinsVerified(boolean isCoinsVerified)
	{
		this.isCoinsVerified = isCoinsVerified;
		return this;
	}
	private boolean isTwoPlayer = false;

	public final boolean getIsTwoPlayer()
	{
		return this.isTwoPlayer;
	}

	public final GJGameLevel setIsTwoPlayer(boolean isTwoPlayer)
	{
		this.isTwoPlayer = isTwoPlayer;
		return this;
	}
	private boolean m_verifiedCoins = false;

	public final boolean getVerifiedCoins()
	{
		return this.m_verifiedCoins;
	}

	public final GJGameLevel setVerifiedCoins(boolean verifiedCoins)
	{
		this.m_verifiedCoins = verifiedCoins;
		return this;
	}
}
