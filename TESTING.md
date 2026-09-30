# Test Results

Program built with `g++ -std=c++17 -Wall -Wextra` (zero errors, zero warnings) and run on the merged main branch. Expected values use the coordinates in `location.cpp` and the rates in `fare.cpp` and `eta.cpp`.

|#| Test|Input|Expected|Actual|Result|Screenshot|
|---|---|---|---|---|---|---|
|1|Letters at menu|abc|Error message, asks again|Please enter a whole number from 0 to 5.|PASS|[test01.png](tests/screenshots/test01.png)|
|2|Out of range at menu|9|Error message, asks again|Please enter a whole number from 0 to 5.|PASS|[test02.png](tests/screenshots/test02.png)|
|3|Decimal at menu|2.5|Error message, asks again|Please enter a whole number from 0 to 5.|PASS|[test03.png](tests/screenshots/test03.png)|
|4|Empty input|Press Enter|Error message, asks again|Please enter a whole number from 0 to 5.|PASS|[test04.png](tests/screenshots/test04.png)|
|5|Fare before a trip|Option 2 with no trip set|Set a trip first (option 1).|Set a trip first (option 1).|PASS|[test05.png](tests/screenshots/test05.png)|
|6|Same place twice|Option 1, pickup 3, drop-off 3|Pickup and drop-off must be different. Asks again|Pickup and drop-off must be different. Asks again|PASS|[test06.png](tests/screenshots/test06.png)|
|7|Normal trip|Option 1, MMU Cyberjaya to KLCC|Straight 26.77 km, road 34.80 km|Straight 26.77 km, road 34.80 km|PASS|[test07.png](tests/screenshots/test07.png)|
|8|Car, peak hour|Trip KL Sentral to KLCC, option 2, Car, hour 8|RM 15.01 and surge notice|RM 15.01, Peak hour surge x1.5 applied.|PASS|[test08.png](tests/screenshots/test08.png)|
|9|Car, after peak|Same trip, option 2, Car, hour 9|RM 10.01, no surge notice|RM 10.01, no surge notice|PASS|[test09.png](tests/screenshots/test09.png)|
|10|Minimum fare|KL Sentral to Mid Valley, option 2, Bike, hour 12|RM 5.00|RM 5.00|PASS|[test10.png](tests/screenshots/test10.png)|
|11|Hour out of range|Option 2, hour 24|Error message, asks again|Please enter a whole number from 0 to 23.|PASS|[test11.png](tests/screenshots/test11.png)|
|12|Car vs Bike, heavy traffic|Trip MMU Cyberjaya to Dataran Putra, option 3, Heavy, Car then Bike|Car 36 min, Bike 22 min|Car 36 min, Bike 22 min|PASS|[test12.png](tests/screenshots/test12.png)|
|13|GPS era 1 vs era 2|Option 4, era 1, then option 4, era 2|Era 1 error 10.0 to 100.0 m, era 2 error 2.0 to 20.0 m, verdict matches the error band|Era 1: 84.5 m, wrong pickup warning. Era 2: 18.5 m, pickup OK|PASS|[test13.png](tests/screenshots/test13.png)|
|14|Receipt and exit|Option 5, then 0|Receipt prints, goodbye line, program ends|Receipt printed (RM 68.65, 84 min), Goodbye., program ended|PASS|[test14.png](tests/screenshots/test14.png)|
