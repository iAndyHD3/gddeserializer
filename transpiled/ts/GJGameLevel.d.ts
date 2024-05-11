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

	public static readonly PROP_SETTINGS_STRING: string;

	public static readonly PROP_EDITOR_TIME2: string;

	public static readonly PROP_EDITOR_TIME: string;

	public static readonly PROP_OBJECT_COUNT: string;

	public static readonly PROP_IS_GAUNTLET: string;

	public static readonly PROP_DEMON_DIFFICULTY: string;

	public static readonly PROP_EPIC: string;

	public static readonly PROP_DAILY_NUMBER: string;

	public static readonly PROP_LOW_DETAIL_MODE: string;

	public static readonly PROP_STARS_REQUESTED: string;

	public static readonly PROP_VERIFIED_COINS: string;

	public static readonly PROP_COINS: string;

	public static readonly PROP_EXTRA_STRING: string;

	public static readonly PROP_CUSTOM_SONG_ID: string;

	public static readonly PROP_TWO_PLAYER: string;

	public static readonly PROP_COPIED_ID: string;

	public static readonly PROP_UPDATE_DATE: string;

	public static readonly PROP_UPLOAD_DATE: string;

	public static readonly PROP_PASSWORD: string;

	public static readonly PROP_RECORD_STRING: string;

	public static readonly PROP_AUTO: string;

	public static readonly PROP_FEATURE_SCORE: string;

	public static readonly PROP_STARS: string;

	public static readonly PROP_IS_DEMON: string;

	public static readonly PROP_DISLIKES: string;

	public static readonly PROP_LENGTH: string;

	public static readonly PROP_LIKES: string;

	public static readonly PROP_GAME_VERSION: string;

	public static readonly PROP_OFFICIAL_SONG: string;

	public static readonly PROP_SET_COMPLETES: string;

	public static readonly PROP_DOWNLOADS: string;

	public static readonly PROP_DIFFICULTY_NUMERATOR: string;

	public static readonly PROP_DIFFICULTY_DENOMINATOR: string;

	public static readonly PROP_PLAYER_ID: string;

	public static readonly PROP_VERSION: string;

	public static readonly PROP_LEVEL_STRING: string;

	public static readonly PROP_DESCRIPTION: string;

	public static readonly PROP_LEVELNAME: string;

	public static readonly PROP_LEVEL_ID: string;

	public static tryParse(str: string, defaultVal?: number): number;

	public static findDelimiterIndex(str: string, delimiter: string, startPos: number): number;

	public static split(str: string, delimiter: string): string[];

	public addFromObjectString(response: string): void;

	public static createFromGjlevels21Response(response: string): GJGameLevel[];
	#levelName: string;

	public getLevelName(): string;

	public setLevelname(levelname: string): GJGameLevel;
	#levelString: string;

	public getLevelString(): string;

	public setLevelString(levelDesc: string): GJGameLevel;
	#levelDesc: string;

	public getDescription(): string;

	public setDescription(desc: string): GJGameLevel;
	#creatorName: string;

	public getCreatorName(): string;

	public setCreatorname(creatorname: string): GJGameLevel;
	#uploadDate: string;

	public getUploadDate(): string;

	public setUploadDate(uploadDate: string): GJGameLevel;
	#updateDate: string;

	public getUpdateDate(): string;

	public setUpdateDate(updateDate: string): GJGameLevel;
	#playerId: number;

	public getPlayerId(): number;

	public setPlayerId(playerId: number): GJGameLevel;
	#accountId: number;

	public getAccountId(): number;

	public setAccountId(accountId: number): GJGameLevel;
	#levelId: number;

	public getLevelId(): number;

	public setLevelId(levelId: number): GJGameLevel;
	#songId: number;

	public getSongId(): number;

	public setSongId(songId: number): GJGameLevel;
	#levelRev: number;

	public getLevelRev(): number;

	public setLevelRev(levelRev: number): GJGameLevel;
	#objectCount: number;

	public getObjectCount(): number;

	public setObjectCount(objectCount: number): GJGameLevel;
	#downloads: number;

	public getDownloads(): number;

	public setDownloads(downloads: number): GJGameLevel;
	#officialSongId: number;

	public getOfficialSong(): number;

	public setOfficialSong(officialSong: number): GJGameLevel;
	#likes: number;

	public getLikes(): number;

	public setLikes(likes: number): GJGameLevel;
	#dislikes: number;

	public getDislikes(): number;

	public setDislikes(dislikes: number): GJGameLevel;
	#workingTime: number;

	public getWorkingTime(): number;

	public setWorkingTime(workingTime: number): GJGameLevel;
	#levelVersion: number;

	public getLevelVersion(): number;

	public setLevelVersion(levelVersion: number): GJGameLevel;
	#gameVersion: number;

	public getGameVersion(): number;

	public setGameVersion(gameVersion: number): GJGameLevel;
	#coins: number;

	public getCoins(): number;

	public setCoins(coins: number): GJGameLevel;
	#stars: number;

	public getStars(): number;

	public setStars(stars: number): GJGameLevel;
	#featureScore: number;

	public getFeatureScore(): number;

	public setFeatureScore(featureScore: number): GJGameLevel;
	#copyPassword: number;

	public getCopyPassword(): number;

	public setCopyPassword(copyPassword: number): GJGameLevel;
	#originalLevelId: number;

	public getOriginalLevelId(): number;

	public setOriginalLevelId(originalLevelId: number): GJGameLevel;
	#starsRequested: number;

	public getStarsRequested(): number;

	public setStarsRequested(starsRequested: number): GJGameLevel;
	#copiedId: number;

	public getCopiedId(): number;

	public setCopiedId(copiedId: number): GJGameLevel;
	#dailyWeeklyNumber: number;

	public getDailyWeeklyNumber(): number;

	public setDailyWeeklyNumber(dailyWeeklyNumber: number): GJGameLevel;
	#epic: number;

	public getEpic(): number;

	public setEpic(epic: number): GJGameLevel;
	#editorTime: number;

	public getEditorTime(): number;

	public setEditorTime(editorTime: number): GJGameLevel;
	#editorTimeCopies: number;

	public getEditorTimeCopies(): number;

	public setEditorTimeCopies(editorTimeCopies: number): GJGameLevel;
	#levelDifficulty: DifficultyFaces;

	public getLevelDifficulty(): DifficultyFaces;

	public setLevelDifficulty(levelDifficulty: DifficultyFaces): GJGameLevel;
	#demonDifficulty: DemonFaces;

	public getDemonDifficulty(): DemonFaces;

	public setDemonDifficulty(demonDifficulty: DemonFaces): GJGameLevel;
	#levelDuration: LevelLength;

	public getLevelLength(): LevelLength;

	public setLevelLength(levelLength: LevelLength): GJGameLevel;
	#isUnlisted: boolean;

	public getIsUnlisted(): boolean;

	public setIsUnlisted(isUnlisted: boolean): GJGameLevel;
	#isFriendsOnly: boolean;

	public getIsFriendsOnly(): boolean;

	public setIsFriendsOnly(isFriendsOnly: boolean): GJGameLevel;
	#isGauntletLevel: boolean;

	public getIsGauntletLevel(): boolean;

	public setIsGauntletLevel(isGauntletLevel: boolean): GJGameLevel;
	#m_hasLowDetail: boolean;

	public getHasLowDetail(): boolean;

	public setHasLowDetail(hasLowDetail: boolean): GJGameLevel;
	#isUnrated: boolean;

	public getIsUnrated(): boolean;

	public setIsUnrated(isUnrated: boolean): GJGameLevel;
	#isFeatured: boolean;

	public getIsFeatured(): boolean;

	public setIsFeatured(isFeatured: boolean): GJGameLevel;
	#isAuto: boolean;

	public getIsAuto(): boolean;

	public setIsAuto(isAuto: boolean): GJGameLevel;
	#isDemon: boolean;

	public getIsDemon(): boolean;

	public setIsDemon(isDemon: boolean): GJGameLevel;
	#isCoinsVerified: boolean;

	public getIsCoinsVerified(): boolean;

	public setIsCoinsVerified(isCoinsVerified: boolean): GJGameLevel;
	#isTwoPlayer: boolean;

	public getIsTwoPlayer(): boolean;

	public setIsTwoPlayer(isTwoPlayer: boolean): GJGameLevel;
	#m_verifiedCoins: boolean;

	public getVerifiedCoins(): boolean;

	public setVerifiedCoins(verifiedCoins: boolean): GJGameLevel;
}
