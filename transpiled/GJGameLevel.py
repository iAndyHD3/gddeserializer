# Generated automatically with "fut". Do not edit.
import enum

class _CiBreak(Exception): pass

class _DifficultyFaces(enum.Enum):
	NA = 0
	AUTO = 1
	EASY = 2
	NORMAL = 3
	HARD = 4
	HARDER = 5
	INSANE = 6
	DEMON = 7

class _DemonFaces(enum.Enum):
	NA = 0
	EASY = 1
	MEDIUM = 2
	HARD = 3
	INSANE = 4
	EXTREME = 5

class _LevelLength(enum.Enum):
	NA = 0
	TINY = 1
	SHORT = 2
	MEDIUM = 3
	LONG = 4
	X_L = 5

class _LevelType(enum.Enum):
	NA = 0
	NORMAL = 1
	GAUNTLET = 2
	WEEKLY = 3
	DAILY = 4
	EVENT = 5

class GJGameLevel:

	def __init__(self):
		self._level_name = ""
		self._level_string = ""
		self._level_desc = ""
		self._creator_name = ""
		self._upload_date = ""
		self._update_date = ""
		self._player_id = 0
		self._account_id = 0
		self._level_id = 0
		self._song_id = 0
		self._level_rev = 0
		self._object_count = 0
		self._downloads = 0
		self._official_song_id = 0
		self._likes = 0
		self._dislikes = 0
		self._working_time = 0
		self._level_version = 0
		self._game_version = 0
		self._coins = 0
		self._stars = 0
		self._feature_score = 0
		self._copy_password = 0
		self._original_level_id = 0
		self._stars_requested = 0
		self._copied_id = 0
		self._daily_weekly_number = 0
		self._epic = 0
		self._editor_time = 0
		self._editor_time_copies = 0
		self._level_difficulty = _DifficultyFaces.NA
		self._demon_difficulty = _DemonFaces.NA
		self._level_duration = _LevelLength.NA
		self._is_unlisted = False
		self._is_friends_only = False
		self._is_gauntlet_level = False
		self._m_has_low_detail = False
		self._is_unrated = False
		self._is_featured = False
		self._is_auto = False
		self._is_demon = False
		self._is_coins_verified = False
		self._is_two_player = False
		self._m_verified_coins = False

	PROP_SETTINGS_STRING = "48"

	PROP_EDITOR_TIME2 = "47"

	PROP_EDITOR_TIME = "46"

	PROP_OBJECT_COUNT = "45"

	PROP_IS_GAUNTLET = "44"

	PROP_DEMON_DIFFICULTY = "43"

	PROP_EPIC = "42"

	PROP_DAILY_NUMBER = "41"

	PROP_LOW_DETAIL_MODE = "40"

	PROP_STARS_REQUESTED = "39"

	PROP_VERIFIED_COINS = "38"

	PROP_COINS = "37"

	PROP_EXTRA_STRING = "36"

	PROP_CUSTOM_SONG_ID = "35"

	PROP_TWO_PLAYER = "31"

	PROP_COPIED_ID = "30"

	PROP_UPDATE_DATE = "29"

	PROP_UPLOAD_DATE = "28"

	PROP_PASSWORD = "27"

	PROP_RECORD_STRING = "26"

	PROP_AUTO = "25"

	PROP_FEATURE_SCORE = "19"

	PROP_STARS = "18"

	PROP_IS_DEMON = "17"

	PROP_DISLIKES = "16"

	PROP_LENGTH = "15"

	PROP_LIKES = "14"

	PROP_GAME_VERSION = "13"

	PROP_OFFICIAL_SONG = "12"

	PROP_SET_COMPLETES = "11"

	PROP_DOWNLOADS = "10"

	PROP_DIFFICULTY_NUMERATOR = "9"

	PROP_DIFFICULTY_DENOMINATOR = "8"

	PROP_PLAYER_ID = "6"

	PROP_VERSION = "5"

	PROP_LEVEL_STRING = "4"

	PROP_DESCRIPTION = "3"

	PROP_LEVELNAME = "2"

	PROP_LEVEL_ID = "1"

	@staticmethod
	def try_parse(str_: str, default_val: int = 0) -> int:
		result: int = 0
		sign: int = 1
		i: int = 0
		len_: int = len(str_)
		while len_ > i and (ord(str_[i]) == 32 or ord(str_[i]) == 9 or ord(str_[i]) == 10):
			i += 1
		if len_ > i and ord(str_[i]) == 45:
			sign = -1
			i += 1
		while len_ > i and ord(str_[i]) == 48:
			i += 1
		while len_ > i and ord(str_[i]) >= 48 and ord(str_[i]) <= 57:
			result = result * 10 + ord(str_[i]) - 48
			i += 1
		result = result * sign
		return default_val if result == 0 else result

	@staticmethod
	def find_delimiter_index(str_: str, delimiter: str, start_pos: int) -> int:
		len_: int = len(str_)
		delimiter_len: int = len(delimiter)
		i: int = start_pos
		while i < len_ - delimiter_len + 1:
			found: bool = True
			for j in range(delimiter_len):
				if ord(str_[i + j]) != ord(delimiter[j]):
					found = False
					break
			if found:
				return i
			i += 1
		return -1

	@staticmethod
	def split(str_: str, delimiter: str) -> list[str]:
		ret: list[str] = []
		pos: int = 0
		len_: int = len(str_)
		delimiter_len: int = len(delimiter)
		while pos < len_:
			end: int = GJGameLevel.find_delimiter_index(str_, delimiter, pos)
			if end == -1:
				ret.append(str_[pos:])
				break
			ret.append(str_[pos:pos + end - pos])
			pos = end + delimiter_len
		return ret

	def add_from_object_string(self, response: str) -> None:
		level_fields: list[str] = GJGameLevel.split(response, ":")
		i: int = 0
		while i < len(level_fields):
			val: str = level_fields[i + 1]
			if len(val) == 0:
				i += 2
				continue
			try:
				match level_fields[i]:
					case "1":
						self._level_id = GJGameLevel.try_parse(val, 0)
					case "2":
						self._level_name = val
					case "3":
						self._level_desc = val
					case "4":
						self._level_string = val
					case "5":
						self._level_version = GJGameLevel.try_parse(val)
					case "6":
						self._player_id = GJGameLevel.try_parse(val)
					case "9":
						temp: int = GJGameLevel.try_parse(val, -1)
						if temp == -1:
							raise _CiBreak()
						match temp:
							case 0:
								self._level_difficulty = _DifficultyFaces.NA
							case 10:
								self._level_difficulty = _DifficultyFaces.EASY
							case 20:
								self._level_difficulty = _DifficultyFaces.NORMAL
							case 30:
								self._level_difficulty = _DifficultyFaces.HARD
							case 40:
								self._level_difficulty = _DifficultyFaces.HARDER
							case 50:
								self._level_difficulty = _DifficultyFaces.INSANE
							case _:
								self._level_difficulty = _DifficultyFaces.NA
						raise _CiBreak()
					case "10":
						self._downloads = GJGameLevel.try_parse(val)
					case "12":
						self._official_song_id = GJGameLevel.try_parse(val)
					case "13":
						self._game_version = GJGameLevel.try_parse(val)
					case "14":
						self._likes = GJGameLevel.try_parse(val)
					case "15":
						temp: int = GJGameLevel.try_parse(val, -1)
						if temp == -1:
							raise _CiBreak()
						match temp:
							case 0:
								self._level_duration = _LevelLength.TINY
							case 1:
								self._level_duration = _LevelLength.SHORT
							case 2:
								self._level_duration = _LevelLength.MEDIUM
							case 3:
								self._level_duration = _LevelLength.LONG
							case 4:
								self._level_duration = _LevelLength.X_L
							case _:
								self._level_duration = _LevelLength.NA
						raise _CiBreak()
					case "16":
						self._dislikes = GJGameLevel.try_parse(val)
					case "17":
						self._is_demon = GJGameLevel.try_parse(val) == 1
					case "18":
						self._stars = GJGameLevel.try_parse(val)
					case "19":
						self._feature_score = GJGameLevel.try_parse(val)
					case "25":
						self._is_auto = GJGameLevel.try_parse(val) == 1
					case "28":
						self._upload_date = val
					case "29":
						self._update_date = val
					case "30":
						self._copied_id = GJGameLevel.try_parse(val)
					case "35":
						self._song_id = GJGameLevel.try_parse(val)
					case "37":
						self._coins = GJGameLevel.try_parse(val)
					case "38":
						self._m_verified_coins = GJGameLevel.try_parse(val) == 1
					case "41":
						self._daily_weekly_number = GJGameLevel.try_parse(val)
					case "42":
						self._epic = GJGameLevel.try_parse(val)
					case "43":
						temp: int = GJGameLevel.try_parse(val, -1)
						if temp == -1:
							raise _CiBreak()
						match temp:
							case 0:
								self._demon_difficulty = _DemonFaces.HARD
							case 3:
								self._demon_difficulty = _DemonFaces.EASY
							case 4:
								self._demon_difficulty = _DemonFaces.MEDIUM
							case 5:
								self._demon_difficulty = _DemonFaces.INSANE
							case 6:
								self._demon_difficulty = _DemonFaces.EXTREME
							case _:
								self._demon_difficulty = _DemonFaces.NA
						raise _CiBreak()
					case "44":
						self._is_gauntlet_level = GJGameLevel.try_parse(val) == 1
					case "45":
						self._object_count = GJGameLevel.try_parse(val)
					case "46":
						self._editor_time = GJGameLevel.try_parse(val)
					case "47":
						self._editor_time_copies = GJGameLevel.try_parse(val)
			except _CiBreak:
				pass
			if not self._is_demon:
				self._demon_difficulty = _DemonFaces.NA
			else:
				self._level_difficulty = _DifficultyFaces.DEMON
			i += 2

	@staticmethod
	def create_from_gjlevels21_response(response: str) -> list["GJGameLevel"]:
		ret: list["GJGameLevel"] = []
		resp_parts: list[str] = GJGameLevel.split(response, "#")
		if len(resp_parts) == 1:
			return ret
		level_objects_strs: list[str] = GJGameLevel.split(resp_parts[0], "|")
		if len(level_objects_strs) == 1:
			return ret
		for level_object_str in level_objects_strs:
			ret.append(GJGameLevel())
			level: "GJGameLevel" = ret[-1]
			level.add_from_object_string(level_object_str)
			if level._level_id <= 0:
				del ret[len(ret)]
		return ret
	_level_name: str

	def get_level_name(self) -> str:
		return self._level_name

	def set_levelname(self, levelname: str) -> "GJGameLevel":
		self._level_name = levelname
		return self
	_level_string: str

	def get_level_string(self) -> str:
		return self._level_string

	def set_level_string(self, level_desc: str) -> "GJGameLevel":
		self._level_string = level_desc
		return self
	_level_desc: str

	def get_description(self) -> str:
		return self._level_desc

	def set_description(self, desc: str) -> "GJGameLevel":
		self._level_desc = desc
		return self
	_creator_name: str

	def get_creator_name(self) -> str:
		return self._creator_name

	def set_creatorname(self, creatorname: str) -> "GJGameLevel":
		self._creator_name = creatorname
		return self
	_upload_date: str

	def get_upload_date(self) -> str:
		return self._upload_date

	def set_upload_date(self, upload_date: str) -> "GJGameLevel":
		self._upload_date = upload_date
		return self
	_update_date: str

	def get_update_date(self) -> str:
		return self._update_date

	def set_update_date(self, update_date: str) -> "GJGameLevel":
		self._update_date = update_date
		return self
	_player_id: int

	def get_player_id(self) -> int:
		return self._player_id

	def set_player_id(self, player_id: int) -> "GJGameLevel":
		self._player_id = player_id
		return self
	_account_id: int

	def get_account_id(self) -> int:
		return self._account_id

	def set_account_id(self, account_id: int) -> "GJGameLevel":
		self._account_id = account_id
		return self
	_level_id: int

	def get_level_id(self) -> int:
		return self._level_id

	def set_level_id(self, level_id: int) -> "GJGameLevel":
		self._level_id = level_id
		return self
	_song_id: int

	def get_song_id(self) -> int:
		return self._song_id

	def set_song_id(self, song_id: int) -> "GJGameLevel":
		self._song_id = song_id
		return self
	_level_rev: int

	def get_level_rev(self) -> int:
		return self._level_rev

	def set_level_rev(self, level_rev: int) -> "GJGameLevel":
		self._level_rev = level_rev
		return self
	_object_count: int

	def get_object_count(self) -> int:
		return self._object_count

	def set_object_count(self, object_count: int) -> "GJGameLevel":
		self._object_count = object_count
		return self
	_downloads: int

	def get_downloads(self) -> int:
		return self._downloads

	def set_downloads(self, downloads: int) -> "GJGameLevel":
		self._downloads = downloads
		return self
	_official_song_id: int

	def get_official_song(self) -> int:
		return self._official_song_id

	def set_official_song(self, official_song: int) -> "GJGameLevel":
		self._official_song_id = official_song
		return self
	_likes: int

	def get_likes(self) -> int:
		return self._likes

	def set_likes(self, likes: int) -> "GJGameLevel":
		self._likes = likes
		return self
	_dislikes: int

	def get_dislikes(self) -> int:
		return self._dislikes

	def set_dislikes(self, dislikes: int) -> "GJGameLevel":
		self._dislikes = dislikes
		return self
	_working_time: int

	def get_working_time(self) -> int:
		return self._working_time

	def set_working_time(self, working_time: int) -> "GJGameLevel":
		self._working_time = working_time
		return self
	_level_version: int

	def get_level_version(self) -> int:
		return self._level_version

	def set_level_version(self, level_version: int) -> "GJGameLevel":
		self._level_version = level_version
		return self
	_game_version: int

	def get_game_version(self) -> int:
		return self._game_version

	def set_game_version(self, game_version: int) -> "GJGameLevel":
		self._game_version = game_version
		return self
	_coins: int

	def get_coins(self) -> int:
		return self._coins

	def set_coins(self, coins: int) -> "GJGameLevel":
		self._coins = coins
		return self
	_stars: int

	def get_stars(self) -> int:
		return self._stars

	def set_stars(self, stars: int) -> "GJGameLevel":
		self._stars = stars
		return self
	_feature_score: int

	def get_feature_score(self) -> int:
		return self._feature_score

	def set_feature_score(self, feature_score: int) -> "GJGameLevel":
		self._feature_score = feature_score
		return self
	_copy_password: int

	def get_copy_password(self) -> int:
		return self._copy_password

	def set_copy_password(self, copy_password: int) -> "GJGameLevel":
		self._copy_password = copy_password
		return self
	_original_level_id: int

	def get_original_level_id(self) -> int:
		return self._original_level_id

	def set_original_level_id(self, original_level_id: int) -> "GJGameLevel":
		self._original_level_id = original_level_id
		return self
	_stars_requested: int

	def get_stars_requested(self) -> int:
		return self._stars_requested

	def set_stars_requested(self, stars_requested: int) -> "GJGameLevel":
		self._stars_requested = stars_requested
		return self
	_copied_id: int

	def get_copied_id(self) -> int:
		return self._copied_id

	def set_copied_id(self, copied_id: int) -> "GJGameLevel":
		self._copied_id = copied_id
		return self
	_daily_weekly_number: int

	def get_daily_weekly_number(self) -> int:
		return self._daily_weekly_number

	def set_daily_weekly_number(self, daily_weekly_number: int) -> "GJGameLevel":
		self._daily_weekly_number = daily_weekly_number
		return self
	_epic: int

	def get_epic(self) -> int:
		return self._epic

	def set_epic(self, epic: int) -> "GJGameLevel":
		self._epic = epic
		return self
	_editor_time: int

	def get_editor_time(self) -> int:
		return self._editor_time

	def set_editor_time(self, editor_time: int) -> "GJGameLevel":
		self._editor_time = editor_time
		return self
	_editor_time_copies: int

	def get_editor_time_copies(self) -> int:
		return self._editor_time_copies

	def set_editor_time_copies(self, editor_time_copies: int) -> "GJGameLevel":
		self._editor_time_copies = editor_time_copies
		return self
	_level_difficulty: _DifficultyFaces

	def get_level_difficulty(self) -> _DifficultyFaces:
		return self._level_difficulty

	def set_level_difficulty(self, level_difficulty: _DifficultyFaces) -> "GJGameLevel":
		self._level_difficulty = level_difficulty
		return self
	_demon_difficulty: _DemonFaces

	def get_demon_difficulty(self) -> _DemonFaces:
		return self._demon_difficulty

	def set_demon_difficulty(self, demon_difficulty: _DemonFaces) -> "GJGameLevel":
		self._demon_difficulty = demon_difficulty
		return self
	_level_duration: _LevelLength

	def get_level_length(self) -> _LevelLength:
		return self._level_duration

	def set_level_length(self, level_length: _LevelLength) -> "GJGameLevel":
		self._level_duration = level_length
		return self
	_is_unlisted: bool

	def get_is_unlisted(self) -> bool:
		return self._is_unlisted

	def set_is_unlisted(self, is_unlisted: bool) -> "GJGameLevel":
		self._is_unlisted = is_unlisted
		return self
	_is_friends_only: bool

	def get_is_friends_only(self) -> bool:
		return self._is_friends_only

	def set_is_friends_only(self, is_friends_only: bool) -> "GJGameLevel":
		self._is_friends_only = is_friends_only
		return self
	_is_gauntlet_level: bool

	def get_is_gauntlet_level(self) -> bool:
		return self._is_gauntlet_level

	def set_is_gauntlet_level(self, is_gauntlet_level: bool) -> "GJGameLevel":
		self._is_gauntlet_level = is_gauntlet_level
		return self
	_m_has_low_detail: bool

	def get_has_low_detail(self) -> bool:
		return self._m_has_low_detail

	def set_has_low_detail(self, has_low_detail: bool) -> "GJGameLevel":
		self._m_has_low_detail = has_low_detail
		return self
	_is_unrated: bool

	def get_is_unrated(self) -> bool:
		return self._is_unrated

	def set_is_unrated(self, is_unrated: bool) -> "GJGameLevel":
		self._is_unrated = is_unrated
		return self
	_is_featured: bool

	def get_is_featured(self) -> bool:
		return self._is_featured

	def set_is_featured(self, is_featured: bool) -> "GJGameLevel":
		self._is_featured = is_featured
		return self
	_is_auto: bool

	def get_is_auto(self) -> bool:
		return self._is_auto

	def set_is_auto(self, is_auto: bool) -> "GJGameLevel":
		self._is_auto = is_auto
		return self
	_is_demon: bool

	def get_is_demon(self) -> bool:
		return self._is_demon

	def set_is_demon(self, is_demon: bool) -> "GJGameLevel":
		self._is_demon = is_demon
		return self
	_is_coins_verified: bool

	def get_is_coins_verified(self) -> bool:
		return self._is_coins_verified

	def set_is_coins_verified(self, is_coins_verified: bool) -> "GJGameLevel":
		self._is_coins_verified = is_coins_verified
		return self
	_is_two_player: bool

	def get_is_two_player(self) -> bool:
		return self._is_two_player

	def set_is_two_player(self, is_two_player: bool) -> "GJGameLevel":
		self._is_two_player = is_two_player
		return self
	_m_verified_coins: bool

	def get_verified_coins(self) -> bool:
		return self._m_verified_coins

	def set_verified_coins(self, verified_coins: bool) -> "GJGameLevel":
		self._m_verified_coins = verified_coins
		return self
