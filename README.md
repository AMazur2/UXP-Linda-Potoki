# UXP-Linda-Potoki

## 1. treść zadania. 

Napisać wieloprocesowy system realizujący komunikację w języku komunikacyjnym Linda. W uproszczeniu Linda realizuje trzy operacje: 

output(krotka) 
input(wzorzec-krotki, timeout) 
read(wzorzec-krotki, timeout) 

Komunikacja między-procesowa w Lindzie realizowana jest poprzez wspólną dla wszystkich procesów przestrzeń krotek. Krotki są arbitralnymi tablicami dowolnej długości składającymi się z elementów 3 typów podstawowych: string, integer, float. Przykłady krotek: (1, ”abc”, 3.1415, ”d”), (10, ”abc”, 3.1415) lub (2,3,1,„Ala ma kota”). Funkcja output umieszcza krotkę w przestrzeni. Funkcja input pobiera i atomowo usuwa krotkę z przestrzeni, przy czym wybór krotki następuje poprzez dopasowanie wzorca-krotki. Wzorzec jest krotką, w której dowolne składniki mogą być niewyspecyfikowane: „*” (podany jest tylko typ) lub zadane warunkiem logicznym. Przyjąć warunki: ==, <, <=, > , >= . Przykład: input (integer:1, string:*, float:*,string:”d”) – pobierze pierwszą krotkę z przykładu wyżej zaś: input (integer:>0, string:”abc”, float:*,string:*) drugą. Operacja read działa tak samo jak input, lecz nie usuwa krotki z przestrzeni. Operacje read i input zawsze zwracają jedną krotkę. W przypadku gdy wyspecyfikowana krotka nie istnieje operacje read i input zawieszają się do czasu pojawienia się oczekiwanej danej. Zrealizować przestrzeń krotek przy pomocy potoków nienazwanych. 
