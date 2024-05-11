# gddeserializer

Deserializer for the terrible geometry dash http api. Experimental test of the [Fusion programming language](https://github.com/fusionlanguage/fut). Fusion can be automatically translated to pure C, C++, C#, D, Java, JavaScript, Python, Swift and TypeScript with no additional dependencies. See the [transpiled](transpiled) directory for these translations.

## GJGameLevel

For now the only partially supported endpoint is getGJLevels21.php, which returns a list of levels.

Examples:

Python:
```py
data = {
    "type": "1", #most downloaded
    "str": "",
    "secret": "Wmfd2893gb7",
}
url = "http://www.boomlings.com/database/getGJLevels21.php"

req = requests.post(url=url, data=data, headers={"User-Agent": ""})

levels = GJGameLevel.create_from_gjlevels21_response(req.text)
for level in levels:
    print(level.get_level_name(), end=", ")
```
Output: `OuterSpace, Sonar, The Nightmare, ReTraY, Bloodbath, Level Easy, Dark Paradise, Acid Factory, Dreamland, Amplification,`

C++ (Geode)

```cpp
geode::utils::web::AsyncWebRequest()
.bodyRaw("type=1&str=&secret=Wmfd2893gb7")
.userAgent("")
.post("http://www.boomlings.com/database/getGJLevels21.php")
.text()
.then([](std::string str) {
	std::vector<gdd::GJGameLevel> levels = gdd::GJGameLevel::createFromGjlevels21Response(str);
	for(const auto& level : levels) {
		log::info("{}", level.getLevelName());
	}
});
```
Output
```cpp
02:27:05 INFO  [Main] [TestMod]: OuterSpace
02:27:05 INFO  [Main] [TestMod]: Sonar
02:27:05 INFO  [Main] [TestMod]: The Nightmare
02:27:05 INFO  [Main] [TestMod]: ReTraY
02:27:05 INFO  [Main] [TestMod]: Bloodbath
02:27:05 INFO  [Main] [TestMod]: Level Easy
02:27:05 INFO  [Main] [TestMod]: Dark Paradise
02:27:05 INFO  [Main] [TestMod]: Acid Factory
02:27:05 INFO  [Main] [TestMod]: Dreamland
02:27:05 INFO  [Main] [TestMod]: Amplification
```

In C++ **do NOT use** `using namespace gdd;` as that will likely conflict with the gd's `GJGameLevel`


More languages in the [transpiled](transpiled) dir. Tested languages: C++, Python, Javascript