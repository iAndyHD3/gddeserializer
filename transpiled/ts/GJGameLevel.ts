// Generated automatically with "fut". Do not edit.

enum DifficultyFaces {
	NA,
	AUTO,
	EASY,
	NORMAL,
	HARD,
	HARDER,
	INSANE,
	DEMON,
}

enum DemonFaces {
	NA,
	EASY,
	MEDIUM,
	HARD,
	INSANE,
	EXTREME,
}

enum LevelLength {
	NA,
	TINY,
	SHORT,
	MEDIUM,
	LONG,
	X_L,
}

enum LevelType {
	NA,
	NORMAL,
	GAUNTLET,
	WEEKLY,
	DAILY,
	EVENT,
}

export class GJGameLevel
{

	public static readonly PROP_SETTINGS_STRING: string = "48";

	public static readonly PROP_EDITOR_TIME2: string = "47";

	public static readonly PROP_EDITOR_TIME: string = "46";

	public static readonly PROP_OBJECT_COUNT: string = "45";

	public static readonly PROP_IS_GAUNTLET: string = "44";

	public static readonly PROP_DEMON_DIFFICULTY: string = "43";

	public static readonly PROP_EPIC: string = "42";

	public static readonly PROP_DAILY_NUMBER: string = "41";

	public static readonly PROP_LOW_DETAIL_MODE: string = "40";

	public static readonly PROP_STARS_REQUESTED: string = "39";

	public static readonly PROP_VERIFIED_COINS: string = "38";

	public static readonly PROP_COINS: string = "37";

	public static readonly PROP_EXTRA_STRING: string = "36";

	public static readonly PROP_CUSTOM_SONG_ID: string = "35";

	public static readonly PROP_TWO_PLAYER: string = "31";

	public static readonly PROP_COPIED_ID: string = "30";

	public static readonly PROP_UPDATE_DATE: string = "29";

	public static readonly PROP_UPLOAD_DATE: string = "28";

	public static readonly PROP_PASSWORD: string = "27";

	public static readonly PROP_RECORD_STRING: string = "26";

	public static readonly PROP_AUTO: string = "25";

	public static readonly PROP_FEATURE_SCORE: string = "19";

	public static readonly PROP_STARS: string = "18";

	public static readonly PROP_IS_DEMON: string = "17";

	public static readonly PROP_DISLIKES: string = "16";

	public static readonly PROP_LENGTH: string = "15";

	public static readonly PROP_LIKES: string = "14";

	public static readonly PROP_GAME_VERSION: string = "13";

	public static readonly PROP_OFFICIAL_SONG: string = "12";

	public static readonly PROP_SET_COMPLETES: string = "11";

	public static readonly PROP_DOWNLOADS: string = "10";

	public static readonly PROP_DIFFICULTY_NUMERATOR: string = "9";

	public static readonly PROP_DIFFICULTY_DENOMINATOR: string = "8";

	public static readonly PROP_PLAYER_ID: string = "6";

	public static readonly PROP_VERSION: string = "5";

	public static readonly PROP_LEVEL_STRING: string = "4";

	public static readonly PROP_DESCRIPTION: string = "3";

	public static readonly PROP_LEVELNAME: string = "2";

	public static readonly PROP_LEVEL_ID: string = "1";

	public static tryParse(str: string, defaultVal: number = 0): number
	{
		let result: number = 0;
		let sign: number = 1;
		let i: number = 0;
		let len: number = str.length;
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

	public static findDelimiterIndex(str: string, delimiter: string, startPos: number): number
	{
		let len: number = str.length;
		let delimiterLen: number = delimiter.length;
		for (let i: number = startPos; i < len - delimiterLen + 1; i++) {
			let found: boolean = true;
			for (let j: number = 0; j < delimiterLen; j++) {
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

	public static split(str: string, delimiter: string): string[]
	{
		const ret: string[] = [];
		let pos: number = 0;
		let len: number = str.length;
		let delimiterLen: number = delimiter.length;
		while (pos < len) {
			let end: number = GJGameLevel.findDelimiterIndex(str, delimiter, pos);
			if (end == -1) {
				ret.push(str.substring(pos));
				break;
			}
			ret.push(str.substring(pos, pos + end - pos));
			pos = end + delimiterLen;
		}
		return ret;
	}

	public addFromObjectString(response: string): void
	{
		const level_fields: string[] = GJGameLevel.split(response, ":");
		for (let i: number = 0; i < level_fields.length; i += 2) {
			let val: string = level_fields[i + 1];
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
					let temp: number = GJGameLevel.tryParse(val, -1);
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
					let temp: number = GJGameLevel.tryParse(val, -1);
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
					let temp: number = GJGameLevel.tryParse(val, -1);
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

	public static createFromGjlevels21Response(response: string): GJGameLevel[]
	{
		const ret: GJGameLevel[] = [];
		const resp_parts: string[] = GJGameLevel.split(response, "#");
		if (resp_parts.length == 1)
			return ret;
		const level_objects_strs: string[] = GJGameLevel.split(resp_parts[0], "|");
		if (level_objects_strs.length == 1)
			return ret;
		for (const level_object_str of level_objects_strs) {
			ret.push(new GJGameLevel());
			let level: GJGameLevel = ret.at(-1);
			level.addFromObjectString(level_object_str);
			if (level.#levelId <= 0) {
				ret.splice(ret.length, 1);
			}
		}
		return ret;
	}
	#levelName: string = "";

	public getLevelName(): string
	{
		return this.#levelName;
	}

	public setLevelname(levelname: string): GJGameLevel
	{
		this.#levelName = levelname;
		return this;
	}
	#levelString: string = "";

	public getLevelString(): string
	{
		return this.#levelString;
	}

	public setLevelString(levelDesc: string): GJGameLevel
	{
		this.#levelString = levelDesc;
		return this;
	}
	#levelDesc: string = "";

	public getDescription(): string
	{
		return this.#levelDesc;
	}

	public setDescription(desc: string): GJGameLevel
	{
		this.#levelDesc = desc;
		return this;
	}
	#creatorName: string = "";

	public getCreatorName(): string
	{
		return this.#creatorName;
	}

	public setCreatorname(creatorname: string): GJGameLevel
	{
		this.#creatorName = creatorname;
		return this;
	}
	#uploadDate: string = "";

	public getUploadDate(): string
	{
		return this.#uploadDate;
	}

	public setUploadDate(uploadDate: string): GJGameLevel
	{
		this.#uploadDate = uploadDate;
		return this;
	}
	#updateDate: string = "";

	public getUpdateDate(): string
	{
		return this.#updateDate;
	}

	public setUpdateDate(updateDate: string): GJGameLevel
	{
		this.#updateDate = updateDate;
		return this;
	}
	#playerId: number = 0;

	public getPlayerId(): number
	{
		return this.#playerId;
	}

	public setPlayerId(playerId: number): GJGameLevel
	{
		this.#playerId = playerId;
		return this;
	}
	#accountId: number = 0;

	public getAccountId(): number
	{
		return this.#accountId;
	}

	public setAccountId(accountId: number): GJGameLevel
	{
		this.#accountId = accountId;
		return this;
	}
	#levelId: number = 0;

	public getLevelId(): number
	{
		return this.#levelId;
	}

	public setLevelId(levelId: number): GJGameLevel
	{
		this.#levelId = levelId;
		return this;
	}
	#songId: number = 0;

	public getSongId(): number
	{
		return this.#songId;
	}

	public setSongId(songId: number): GJGameLevel
	{
		this.#songId = songId;
		return this;
	}
	#levelRev: number = 0;

	public getLevelRev(): number
	{
		return this.#levelRev;
	}

	public setLevelRev(levelRev: number): GJGameLevel
	{
		this.#levelRev = levelRev;
		return this;
	}
	#objectCount: number = 0;

	public getObjectCount(): number
	{
		return this.#objectCount;
	}

	public setObjectCount(objectCount: number): GJGameLevel
	{
		this.#objectCount = objectCount;
		return this;
	}
	#downloads: number = 0;

	public getDownloads(): number
	{
		return this.#downloads;
	}

	public setDownloads(downloads: number): GJGameLevel
	{
		this.#downloads = downloads;
		return this;
	}
	#officialSongId: number = 0;

	public getOfficialSong(): number
	{
		return this.#officialSongId;
	}

	public setOfficialSong(officialSong: number): GJGameLevel
	{
		this.#officialSongId = officialSong;
		return this;
	}
	#likes: number = 0;

	public getLikes(): number
	{
		return this.#likes;
	}

	public setLikes(likes: number): GJGameLevel
	{
		this.#likes = likes;
		return this;
	}
	#dislikes: number = 0;

	public getDislikes(): number
	{
		return this.#dislikes;
	}

	public setDislikes(dislikes: number): GJGameLevel
	{
		this.#dislikes = dislikes;
		return this;
	}
	#workingTime: number = 0;

	public getWorkingTime(): number
	{
		return this.#workingTime;
	}

	public setWorkingTime(workingTime: number): GJGameLevel
	{
		this.#workingTime = workingTime;
		return this;
	}
	#levelVersion: number = 0;

	public getLevelVersion(): number
	{
		return this.#levelVersion;
	}

	public setLevelVersion(levelVersion: number): GJGameLevel
	{
		this.#levelVersion = levelVersion;
		return this;
	}
	#gameVersion: number = 0;

	public getGameVersion(): number
	{
		return this.#gameVersion;
	}

	public setGameVersion(gameVersion: number): GJGameLevel
	{
		this.#gameVersion = gameVersion;
		return this;
	}
	#coins: number = 0;

	public getCoins(): number
	{
		return this.#coins;
	}

	public setCoins(coins: number): GJGameLevel
	{
		this.#coins = coins;
		return this;
	}
	#stars: number = 0;

	public getStars(): number
	{
		return this.#stars;
	}

	public setStars(stars: number): GJGameLevel
	{
		this.#stars = stars;
		return this;
	}
	#featureScore: number = 0;

	public getFeatureScore(): number
	{
		return this.#featureScore;
	}

	public setFeatureScore(featureScore: number): GJGameLevel
	{
		this.#featureScore = featureScore;
		return this;
	}
	#copyPassword: number = 0;

	public getCopyPassword(): number
	{
		return this.#copyPassword;
	}

	public setCopyPassword(copyPassword: number): GJGameLevel
	{
		this.#copyPassword = copyPassword;
		return this;
	}
	#originalLevelId: number = 0;

	public getOriginalLevelId(): number
	{
		return this.#originalLevelId;
	}

	public setOriginalLevelId(originalLevelId: number): GJGameLevel
	{
		this.#originalLevelId = originalLevelId;
		return this;
	}
	#starsRequested: number = 0;

	public getStarsRequested(): number
	{
		return this.#starsRequested;
	}

	public setStarsRequested(starsRequested: number): GJGameLevel
	{
		this.#starsRequested = starsRequested;
		return this;
	}
	#copiedId: number = 0;

	public getCopiedId(): number
	{
		return this.#copiedId;
	}

	public setCopiedId(copiedId: number): GJGameLevel
	{
		this.#copiedId = copiedId;
		return this;
	}
	#dailyWeeklyNumber: number = 0;

	public getDailyWeeklyNumber(): number
	{
		return this.#dailyWeeklyNumber;
	}

	public setDailyWeeklyNumber(dailyWeeklyNumber: number): GJGameLevel
	{
		this.#dailyWeeklyNumber = dailyWeeklyNumber;
		return this;
	}
	#epic: number = 0;

	public getEpic(): number
	{
		return this.#epic;
	}

	public setEpic(epic: number): GJGameLevel
	{
		this.#epic = epic;
		return this;
	}
	#editorTime: number = 0;

	public getEditorTime(): number
	{
		return this.#editorTime;
	}

	public setEditorTime(editorTime: number): GJGameLevel
	{
		this.#editorTime = editorTime;
		return this;
	}
	#editorTimeCopies: number = 0;

	public getEditorTimeCopies(): number
	{
		return this.#editorTimeCopies;
	}

	public setEditorTimeCopies(editorTimeCopies: number): GJGameLevel
	{
		this.#editorTimeCopies = editorTimeCopies;
		return this;
	}
	#levelDifficulty: DifficultyFaces = DifficultyFaces.NA;

	public getLevelDifficulty(): DifficultyFaces
	{
		return this.#levelDifficulty;
	}

	public setLevelDifficulty(levelDifficulty: DifficultyFaces): GJGameLevel
	{
		this.#levelDifficulty = levelDifficulty;
		return this;
	}
	#demonDifficulty: DemonFaces = DemonFaces.NA;

	public getDemonDifficulty(): DemonFaces
	{
		return this.#demonDifficulty;
	}

	public setDemonDifficulty(demonDifficulty: DemonFaces): GJGameLevel
	{
		this.#demonDifficulty = demonDifficulty;
		return this;
	}
	#levelDuration: LevelLength = LevelLength.NA;

	public getLevelLength(): LevelLength
	{
		return this.#levelDuration;
	}

	public setLevelLength(levelLength: LevelLength): GJGameLevel
	{
		this.#levelDuration = levelLength;
		return this;
	}
	#isUnlisted: boolean = false;

	public getIsUnlisted(): boolean
	{
		return this.#isUnlisted;
	}

	public setIsUnlisted(isUnlisted: boolean): GJGameLevel
	{
		this.#isUnlisted = isUnlisted;
		return this;
	}
	#isFriendsOnly: boolean = false;

	public getIsFriendsOnly(): boolean
	{
		return this.#isFriendsOnly;
	}

	public setIsFriendsOnly(isFriendsOnly: boolean): GJGameLevel
	{
		this.#isFriendsOnly = isFriendsOnly;
		return this;
	}
	#isGauntletLevel: boolean = false;

	public getIsGauntletLevel(): boolean
	{
		return this.#isGauntletLevel;
	}

	public setIsGauntletLevel(isGauntletLevel: boolean): GJGameLevel
	{
		this.#isGauntletLevel = isGauntletLevel;
		return this;
	}
	#m_hasLowDetail: boolean = false;

	public getHasLowDetail(): boolean
	{
		return this.#m_hasLowDetail;
	}

	public setHasLowDetail(hasLowDetail: boolean): GJGameLevel
	{
		this.#m_hasLowDetail = hasLowDetail;
		return this;
	}
	#isUnrated: boolean = false;

	public getIsUnrated(): boolean
	{
		return this.#isUnrated;
	}

	public setIsUnrated(isUnrated: boolean): GJGameLevel
	{
		this.#isUnrated = isUnrated;
		return this;
	}
	#isFeatured: boolean = false;

	public getIsFeatured(): boolean
	{
		return this.#isFeatured;
	}

	public setIsFeatured(isFeatured: boolean): GJGameLevel
	{
		this.#isFeatured = isFeatured;
		return this;
	}
	#isAuto: boolean = false;

	public getIsAuto(): boolean
	{
		return this.#isAuto;
	}

	public setIsAuto(isAuto: boolean): GJGameLevel
	{
		this.#isAuto = isAuto;
		return this;
	}
	#isDemon: boolean = false;

	public getIsDemon(): boolean
	{
		return this.#isDemon;
	}

	public setIsDemon(isDemon: boolean): GJGameLevel
	{
		this.#isDemon = isDemon;
		return this;
	}
	#isCoinsVerified: boolean = false;

	public getIsCoinsVerified(): boolean
	{
		return this.#isCoinsVerified;
	}

	public setIsCoinsVerified(isCoinsVerified: boolean): GJGameLevel
	{
		this.#isCoinsVerified = isCoinsVerified;
		return this;
	}
	#isTwoPlayer: boolean = false;

	public getIsTwoPlayer(): boolean
	{
		return this.#isTwoPlayer;
	}

	public setIsTwoPlayer(isTwoPlayer: boolean): GJGameLevel
	{
		this.#isTwoPlayer = isTwoPlayer;
		return this;
	}
	#m_verifiedCoins: boolean = false;

	public getVerifiedCoins(): boolean
	{
		return this.#m_verifiedCoins;
	}

	public setVerifiedCoins(verifiedCoins: boolean): GJGameLevel
	{
		this.#m_verifiedCoins = verifiedCoins;
		return this;
	}
}
