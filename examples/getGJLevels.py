import sys
import os
import requests

sys.path.append(os.path.join(os.path.dirname(__file__), '..', 'transpiled'))
from GJGameLevel import GJGameLevel

def main():
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

if __name__ == '__main__':
    main()