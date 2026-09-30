|#| Test|Input|Expected|Actual|Result|Screenshot|
|---|---|---|---|---|---|---|
|1|Letters at menu|abc|Error message, asks again||||
|2|Out of range at menu|9|Error message, asks again||||
|3|Decimal at menu|2.5|Error message, asks again||||
|4|Empty input|Press Enter|Error message, asks again||||
|5|Fare before a trip|Option 2 with no trip set|Set a trip first (option 1).||||
|6|Same place twice|Option 1, pickup 3, drop-off 3|Pickup and drop-off must be different. Asks again||||
|7|Normal trip|Option 1, MMU Cyberjaya to KLCC|Straight 26.77 km, road 34.80 km||||
|8|Car, peak hour|Trip KL Sentral to KLCC, option 2, Car, hour 8|RM 15.01 and surge notice||||
|9|Car, after peak|Same trip, option 2, Car, hour 9|RM 10.01, no surge notice||||
|10|Minimum fare|KL Sentral to Mid Valley, option 2, Bike, hour 12|RM 5.00||||
|11|Hour out of range|Option 2, hour 24|Error message, asks again||||
|12|Car vs Bike, heavy traffic|Trip MMU Cyberjaya to Dataran Putra, option 3, Heavy, Car then Bike|Car 36 min, Bike 22 min||||
|13|GPS era 1 vs era 2|Option 4, era 1, then option 4, era 2|Era 1 error 10.0 to 100.0 m, era 2 error 2.0 to 20.0 m, verdict matches Section 6.5||||
|14|Receipt and exit|Option 5, then 0|Receipt prints, goodbye line, program ends||||