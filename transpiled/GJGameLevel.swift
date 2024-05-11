// Generated automatically with "fut". Do not edit.

enum DifficultyFaces
{
	case na
	case auto
	case easy
	case normal
	case hard
	case harder
	case insane
	case demon
}

enum DemonFaces
{
	case na
	case easy
	case medium
	case hard
	case insane
	case extreme
}

enum LevelLength
{
	case na
	case tiny
	case short
	case medium
	case long
	case xL
}

enum LevelType
{
	case na
	case normal
	case gauntlet
	case weekly
	case daily
	case event
}

public class GJGameLevel
{

	public static let prop_settingsString = "48"

	public static let prop_editorTime2 = "47"

	public static let prop_editorTime = "46"

	public static let prop_objectCount = "45"

	public static let prop_isGauntlet = "44"

	public static let prop_demonDifficulty = "43"

	public static let prop_epic = "42"

	public static let prop_dailyNumber = "41"

	public static let prop_lowDetailMode = "40"

	public static let prop_starsRequested = "39"

	public static let prop_verifiedCoins = "38"

	public static let prop_coins = "37"

	public static let prop_extraString = "36"

	public static let prop_customSongId = "35"

	public static let prop_twoPlayer = "31"

	public static let prop_copiedId = "30"

	public static let prop_updateDate = "29"

	public static let prop_uploadDate = "28"

	public static let prop_password = "27"

	public static let prop_recordString = "26"

	public static let prop_auto = "25"

	public static let prop_featureScore = "19"

	public static let prop_stars = "18"

	public static let prop_is_demon = "17"

	public static let prop_dislikes = "16"

	public static let prop_length = "15"

	public static let prop_likes = "14"

	public static let prop_gameVersion = "13"

	public static let prop_officialSong = "12"

	public static let prop_setCompletes = "11"

	public static let prop_downloads = "10"

	public static let prop_difficultyNumerator = "9"

	public static let prop_difficultyDenominator = "8"

	public static let prop_playerId = "6"

	public static let prop_version = "5"

	public static let prop_levelString = "4"

	public static let prop_description = "3"

	public static let prop_levelname = "2"

	public static let prop_levelId = "1"

	public static func tryParse(_ str : String, _ defaultVal : Int = 0) -> Int
	{
		var result : Int = 0
		var sign : Int = 1
		var i : Int = 0
		let len : Int = str.count
		while len > i && (fuStringCharAt(str, i) == 32 || fuStringCharAt(str, i) == 9 || fuStringCharAt(str, i) == 10) {
			i += 1
		}
		if len > i && fuStringCharAt(str, i) == 45 {
			sign = -1
			i += 1
		}
		while len > i && fuStringCharAt(str, i) == 48 {
			i += 1
		}
		while len > i && fuStringCharAt(str, i) >= 48 && fuStringCharAt(str, i) <= 57 {
			result = result * 10 + fuStringCharAt(str, i) - 48
			i += 1
		}
		result = result * sign
		return result == 0 ? defaultVal : result
	}

	public static func findDelimiterIndex(_ str : String, _ delimiter : String, _ startPos : Int) -> Int
	{
		let len : Int = str.count
		let delimiterLen : Int = delimiter.count
		var i : Int = startPos
		while i < len - delimiterLen + 1 {
			var found : Bool = true
			for j in 0..<delimiterLen {
				if fuStringCharAt(str, i + j) != fuStringCharAt(delimiter, j) {
					found = false
					break
				}
			}
			if found {
				return i
			}
			i += 1
		}
		return -1
	}

	public static func split(_ str : String, _ delimiter : String) -> [String]
	{
		var ret = [String]()
		var pos : Int = 0
		let len : Int = str.count
		let delimiterLen : Int = delimiter.count
		while pos < len {
			let end : Int = GJGameLevel.findDelimiterIndex(str, delimiter, pos)
			if end == -1 {
				ret.append(String(fuStringSubstring(str, pos)))
				break
			}
			ret.append(String(fuStringSubstring(str, pos).prefix(end - pos)))
			pos = end + delimiterLen
		}
		return ret
	}

	public func addFromObjectString(_ response : String)
	{
		var level_fields = GJGameLevel.split(response, ":")
		var i : Int = 0
		while i < level_fields.count {
			let val : String = level_fields[i + 1]
			if val.count == 0 {
				i += 2
				continue
			}
			switch level_fields[i] {
			case "1":
				self.levelId = GJGameLevel.tryParse(val, 0)
				break
			case "2":
				self.levelName = val
				break
			case "3":
				self.levelDesc = val
				break
			case "4":
				self.levelString = val
				break
			case "5":
				self.levelVersion = GJGameLevel.tryParse(val)
				break
			case "6":
				self.playerId = GJGameLevel.tryParse(val)
				break
			case "9":
				let temp : Int = GJGameLevel.tryParse(val, -1)
				if temp == -1 {
					break
				}
				switch temp {
				case 0:
					self.levelDifficulty = DifficultyFaces.na
					break
				case 10:
					self.levelDifficulty = DifficultyFaces.easy
					break
				case 20:
					self.levelDifficulty = DifficultyFaces.normal
					break
				case 30:
					self.levelDifficulty = DifficultyFaces.hard
					break
				case 40:
					self.levelDifficulty = DifficultyFaces.harder
					break
				case 50:
					self.levelDifficulty = DifficultyFaces.insane
					break
				default:
					self.levelDifficulty = DifficultyFaces.na
					break
				}
				break
			case "10":
				self.downloads = GJGameLevel.tryParse(val)
				break
			case "12":
				self.officialSongId = GJGameLevel.tryParse(val)
				break
			case "13":
				self.gameVersion = GJGameLevel.tryParse(val)
				break
			case "14":
				self.likes = GJGameLevel.tryParse(val)
				break
			case "15":
				let temp : Int = GJGameLevel.tryParse(val, -1)
				if temp == -1 {
					break
				}
				switch temp {
				case 0:
					self.levelDuration = LevelLength.tiny
					break
				case 1:
					self.levelDuration = LevelLength.short
					break
				case 2:
					self.levelDuration = LevelLength.medium
					break
				case 3:
					self.levelDuration = LevelLength.long
					break
				case 4:
					self.levelDuration = LevelLength.xL
					break
				default:
					self.levelDuration = LevelLength.na
					break
				}
				break
			case "16":
				self.dislikes = GJGameLevel.tryParse(val)
				break
			case "17":
				self.isDemon = GJGameLevel.tryParse(val) == 1
				break
			case "18":
				self.stars = GJGameLevel.tryParse(val)
				break
			case "19":
				self.featureScore = GJGameLevel.tryParse(val)
				break
			case "25":
				self.isAuto = GJGameLevel.tryParse(val) == 1
				break
			case "28":
				self.uploadDate = val
				break
			case "29":
				self.updateDate = val
				break
			case "30":
				self.copiedId = GJGameLevel.tryParse(val)
				break
			case "35":
				self.songId = GJGameLevel.tryParse(val)
				break
			case "37":
				self.coins = GJGameLevel.tryParse(val)
				break
			case "38":
				self.m_verifiedCoins = GJGameLevel.tryParse(val) == 1
				break
			case "41":
				self.dailyWeeklyNumber = GJGameLevel.tryParse(val)
				break
			case "42":
				self.epic = GJGameLevel.tryParse(val)
				break
			case "43":
				let temp : Int = GJGameLevel.tryParse(val, -1)
				if temp == -1 {
					break
				}
				switch temp {
				case 0:
					self.demonDifficulty = DemonFaces.hard
					break
				case 3:
					self.demonDifficulty = DemonFaces.easy
					break
				case 4:
					self.demonDifficulty = DemonFaces.medium
					break
				case 5:
					self.demonDifficulty = DemonFaces.insane
					break
				case 6:
					self.demonDifficulty = DemonFaces.extreme
					break
				default:
					self.demonDifficulty = DemonFaces.na
					break
				}
				break
			case "44":
				self.isGauntletLevel = GJGameLevel.tryParse(val) == 1
				break
			case "45":
				self.objectCount = GJGameLevel.tryParse(val)
				break
			case "46":
				self.editorTime = GJGameLevel.tryParse(val)
				break
			case "47":
				self.editorTimeCopies = GJGameLevel.tryParse(val)
				break
			}
			if !self.isDemon {
				self.demonDifficulty = DemonFaces.na
			}
			else {
				self.levelDifficulty = DifficultyFaces.demon
			}
			i += 2
		}
	}

	public static func createFromGjlevels21Response(_ response : String) -> [GJGameLevel]
	{
		var ret = [GJGameLevel]()
		var resp_parts = GJGameLevel.split(response, "#")
		if resp_parts.count == 1 {
			return ret
		}
		var level_objects_strs = GJGameLevel.split(resp_parts[0], "|")
		if level_objects_strs.count == 1 {
			return ret
		}
		for level_object_str in level_objects_strs {
			ret.append(GJGameLevel())
			let level : GJGameLevel = ret.last
			level.addFromObjectString(level_object_str)
			if level.levelId <= 0 {
				ret.remove(at: ret.count)
			}
		}
		return ret
	}

	private var levelName : String = ""

	public func getLevelName() -> String
	{
		return self.levelName
	}

	public func setLevelname(_ levelname : String) -> GJGameLevel
	{
		self.levelName = levelname
		return self
	}

	private var levelString : String = ""

	public func getLevelString() -> String
	{
		return self.levelString
	}

	public func setLevelString(_ levelDesc : String) -> GJGameLevel
	{
		self.levelString = levelDesc
		return self
	}

	private var levelDesc : String = ""

	public func getDescription() -> String
	{
		return self.levelDesc
	}

	public func setDescription(_ desc : String) -> GJGameLevel
	{
		self.levelDesc = desc
		return self
	}

	private var creatorName : String = ""

	public func getCreatorName() -> String
	{
		return self.creatorName
	}

	public func setCreatorname(_ creatorname : String) -> GJGameLevel
	{
		self.creatorName = creatorname
		return self
	}

	private var uploadDate : String = ""

	public func getUploadDate() -> String
	{
		return self.uploadDate
	}

	public func setUploadDate(_ uploadDate : String) -> GJGameLevel
	{
		self.uploadDate = uploadDate
		return self
	}

	private var updateDate : String = ""

	public func getUpdateDate() -> String
	{
		return self.updateDate
	}

	public func setUpdateDate(_ updateDate : String) -> GJGameLevel
	{
		self.updateDate = updateDate
		return self
	}

	private var playerId : Int = 0

	public func getPlayerId() -> Int
	{
		return self.playerId
	}

	public func setPlayerId(_ playerId : Int) -> GJGameLevel
	{
		self.playerId = playerId
		return self
	}

	private var accountId : Int = 0

	public func getAccountId() -> Int
	{
		return self.accountId
	}

	public func setAccountId(_ accountId : Int) -> GJGameLevel
	{
		self.accountId = accountId
		return self
	}

	private var levelId : Int = 0

	public func getLevelId() -> Int
	{
		return self.levelId
	}

	public func setLevelId(_ levelId : Int) -> GJGameLevel
	{
		self.levelId = levelId
		return self
	}

	private var songId : Int = 0

	public func getSongId() -> Int
	{
		return self.songId
	}

	public func setSongId(_ songId : Int) -> GJGameLevel
	{
		self.songId = songId
		return self
	}

	private var levelRev : Int = 0

	public func getLevelRev() -> Int
	{
		return self.levelRev
	}

	public func setLevelRev(_ levelRev : Int) -> GJGameLevel
	{
		self.levelRev = levelRev
		return self
	}

	private var objectCount : Int = 0

	public func getObjectCount() -> Int
	{
		return self.objectCount
	}

	public func setObjectCount(_ objectCount : Int) -> GJGameLevel
	{
		self.objectCount = objectCount
		return self
	}

	private var downloads : Int = 0

	public func getDownloads() -> Int
	{
		return self.downloads
	}

	public func setDownloads(_ downloads : Int) -> GJGameLevel
	{
		self.downloads = downloads
		return self
	}

	private var officialSongId : Int = 0

	public func getOfficialSong() -> Int
	{
		return self.officialSongId
	}

	public func setOfficialSong(_ officialSong : Int) -> GJGameLevel
	{
		self.officialSongId = officialSong
		return self
	}

	private var likes : Int = 0

	public func getLikes() -> Int
	{
		return self.likes
	}

	public func setLikes(_ likes : Int) -> GJGameLevel
	{
		self.likes = likes
		return self
	}

	private var dislikes : Int = 0

	public func getDislikes() -> Int
	{
		return self.dislikes
	}

	public func setDislikes(_ dislikes : Int) -> GJGameLevel
	{
		self.dislikes = dislikes
		return self
	}

	private var workingTime : Int = 0

	public func getWorkingTime() -> Int
	{
		return self.workingTime
	}

	public func setWorkingTime(_ workingTime : Int) -> GJGameLevel
	{
		self.workingTime = workingTime
		return self
	}

	private var levelVersion : Int = 0

	public func getLevelVersion() -> Int
	{
		return self.levelVersion
	}

	public func setLevelVersion(_ levelVersion : Int) -> GJGameLevel
	{
		self.levelVersion = levelVersion
		return self
	}

	private var gameVersion : Int = 0

	public func getGameVersion() -> Int
	{
		return self.gameVersion
	}

	public func setGameVersion(_ gameVersion : Int) -> GJGameLevel
	{
		self.gameVersion = gameVersion
		return self
	}

	private var coins : Int = 0

	public func getCoins() -> Int
	{
		return self.coins
	}

	public func setCoins(_ coins : Int) -> GJGameLevel
	{
		self.coins = coins
		return self
	}

	private var stars : Int = 0

	public func getStars() -> Int
	{
		return self.stars
	}

	public func setStars(_ stars : Int) -> GJGameLevel
	{
		self.stars = stars
		return self
	}

	private var featureScore : Int = 0

	public func getFeatureScore() -> Int
	{
		return self.featureScore
	}

	public func setFeatureScore(_ featureScore : Int) -> GJGameLevel
	{
		self.featureScore = featureScore
		return self
	}

	private var copyPassword : Int = 0

	public func getCopyPassword() -> Int
	{
		return self.copyPassword
	}

	public func setCopyPassword(_ copyPassword : Int) -> GJGameLevel
	{
		self.copyPassword = copyPassword
		return self
	}

	private var originalLevelId : Int = 0

	public func getOriginalLevelId() -> Int
	{
		return self.originalLevelId
	}

	public func setOriginalLevelId(_ originalLevelId : Int) -> GJGameLevel
	{
		self.originalLevelId = originalLevelId
		return self
	}

	private var starsRequested : Int = 0

	public func getStarsRequested() -> Int
	{
		return self.starsRequested
	}

	public func setStarsRequested(_ starsRequested : Int) -> GJGameLevel
	{
		self.starsRequested = starsRequested
		return self
	}

	private var copiedId : Int = 0

	public func getCopiedId() -> Int
	{
		return self.copiedId
	}

	public func setCopiedId(_ copiedId : Int) -> GJGameLevel
	{
		self.copiedId = copiedId
		return self
	}

	private var dailyWeeklyNumber : Int = 0

	public func getDailyWeeklyNumber() -> Int
	{
		return self.dailyWeeklyNumber
	}

	public func setDailyWeeklyNumber(_ dailyWeeklyNumber : Int) -> GJGameLevel
	{
		self.dailyWeeklyNumber = dailyWeeklyNumber
		return self
	}

	private var epic : Int = 0

	public func getEpic() -> Int
	{
		return self.epic
	}

	public func setEpic(_ epic : Int) -> GJGameLevel
	{
		self.epic = epic
		return self
	}

	private var editorTime : Int = 0

	public func getEditorTime() -> Int
	{
		return self.editorTime
	}

	public func setEditorTime(_ editorTime : Int) -> GJGameLevel
	{
		self.editorTime = editorTime
		return self
	}

	private var editorTimeCopies : Int = 0

	public func getEditorTimeCopies() -> Int
	{
		return self.editorTimeCopies
	}

	public func setEditorTimeCopies(_ editorTimeCopies : Int) -> GJGameLevel
	{
		self.editorTimeCopies = editorTimeCopies
		return self
	}

	private var levelDifficulty : DifficultyFaces = DifficultyFaces.na

	public func getLevelDifficulty() -> DifficultyFaces
	{
		return self.levelDifficulty
	}

	public func setLevelDifficulty(_ levelDifficulty : DifficultyFaces) -> GJGameLevel
	{
		self.levelDifficulty = levelDifficulty
		return self
	}

	private var demonDifficulty : DemonFaces = DemonFaces.na

	public func getDemonDifficulty() -> DemonFaces
	{
		return self.demonDifficulty
	}

	public func setDemonDifficulty(_ demonDifficulty : DemonFaces) -> GJGameLevel
	{
		self.demonDifficulty = demonDifficulty
		return self
	}

	private var levelDuration : LevelLength = LevelLength.na

	public func getLevelLength() -> LevelLength
	{
		return self.levelDuration
	}

	public func setLevelLength(_ levelLength : LevelLength) -> GJGameLevel
	{
		self.levelDuration = levelLength
		return self
	}

	private var isUnlisted : Bool = false

	public func getIsUnlisted() -> Bool
	{
		return self.isUnlisted
	}

	public func setIsUnlisted(_ isUnlisted : Bool) -> GJGameLevel
	{
		self.isUnlisted = isUnlisted
		return self
	}

	private var isFriendsOnly : Bool = false

	public func getIsFriendsOnly() -> Bool
	{
		return self.isFriendsOnly
	}

	public func setIsFriendsOnly(_ isFriendsOnly : Bool) -> GJGameLevel
	{
		self.isFriendsOnly = isFriendsOnly
		return self
	}

	private var isGauntletLevel : Bool = false

	public func getIsGauntletLevel() -> Bool
	{
		return self.isGauntletLevel
	}

	public func setIsGauntletLevel(_ isGauntletLevel : Bool) -> GJGameLevel
	{
		self.isGauntletLevel = isGauntletLevel
		return self
	}

	private var m_hasLowDetail : Bool = false

	public func getHasLowDetail() -> Bool
	{
		return self.m_hasLowDetail
	}

	public func setHasLowDetail(_ hasLowDetail : Bool) -> GJGameLevel
	{
		self.m_hasLowDetail = hasLowDetail
		return self
	}

	private var isUnrated : Bool = false

	public func getIsUnrated() -> Bool
	{
		return self.isUnrated
	}

	public func setIsUnrated(_ isUnrated : Bool) -> GJGameLevel
	{
		self.isUnrated = isUnrated
		return self
	}

	private var isFeatured : Bool = false

	public func getIsFeatured() -> Bool
	{
		return self.isFeatured
	}

	public func setIsFeatured(_ isFeatured : Bool) -> GJGameLevel
	{
		self.isFeatured = isFeatured
		return self
	}

	private var isAuto : Bool = false

	public func getIsAuto() -> Bool
	{
		return self.isAuto
	}

	public func setIsAuto(_ isAuto : Bool) -> GJGameLevel
	{
		self.isAuto = isAuto
		return self
	}

	private var isDemon : Bool = false

	public func getIsDemon() -> Bool
	{
		return self.isDemon
	}

	public func setIsDemon(_ isDemon : Bool) -> GJGameLevel
	{
		self.isDemon = isDemon
		return self
	}

	private var isCoinsVerified : Bool = false

	public func getIsCoinsVerified() -> Bool
	{
		return self.isCoinsVerified
	}

	public func setIsCoinsVerified(_ isCoinsVerified : Bool) -> GJGameLevel
	{
		self.isCoinsVerified = isCoinsVerified
		return self
	}

	private var isTwoPlayer : Bool = false

	public func getIsTwoPlayer() -> Bool
	{
		return self.isTwoPlayer
	}

	public func setIsTwoPlayer(_ isTwoPlayer : Bool) -> GJGameLevel
	{
		self.isTwoPlayer = isTwoPlayer
		return self
	}

	private var m_verifiedCoins : Bool = false

	public func getVerifiedCoins() -> Bool
	{
		return self.m_verifiedCoins
	}

	public func setVerifiedCoins(_ verifiedCoins : Bool) -> GJGameLevel
	{
		self.m_verifiedCoins = verifiedCoins
		return self
	}
}

fileprivate func fuStringCharAt(_ s: String, _ offset: Int) -> Int
{
	return Int(s.unicodeScalars[s.index(s.startIndex, offsetBy: offset)].value)
}

fileprivate func fuStringSubstring(_ s: String, _ offset: Int) -> Substring
{
	return s[s.index(s.startIndex, offsetBy: offset)...]
}
