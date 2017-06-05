# Podzial_rafy_koralowej

Podział rafy

Na dnie pewnego ocenu korale zaczęły budować rafę. Wszystko zaczęło się od jednego koralowca, do którego dołączył inny, do nich dołączył kolejny itd. Za każdym razem gdy nowy koralowiec chciał dołączyć do rafy, wybierał sobie sąsiada (jednego koralowca z rafy) i doklejał się do niego. Upłynęło wiele czasu, rafa się rozrosła i koralowcom zrobiło się zbyt tłoczono. Zdecydowały więc o podziale rafy na dwie części. Podział nastąpi poprzez rozdzielenie dwóch wybranych sąsiadów. Aby jedna z części nie czuła się odrzucona przez większość, podział należy zrobić tak, aby po podziale różnica wag dwóch nowopowstałych raf była jak najmniejsza. Waga każdej części jest sumą wag każdego koralowca należącego do tej części, z kolei waga pojedynczego koralowca jest jego prywatną sprawą.
Wejście
Koralowce numerowane są od zera.
Pierwszą liczbą w pierwszym wierszu na wejściu będzie liczba koralowców w rafie (n). Kolejna liczba, w kolejnym wierszu to waga koralowca, od którego zaczęła się rafa (w0). Następnie pojawi się n-1 wierszy, każdy zawierający parę liczb
wj   sj
dla j = 1, ..., n-1 oznaczających, że do rafy dołączył koralowec o wadze wj doklejając się do koralowca sj (sj < j). Waga żadnego koralowca nie przekroczy 1000, liczba koralowców w rafie nie będzie większa niż 1000000.
Wyjście
Na wyjściu należy wypisać: w pierwszej linii minimalną różnicę wag raf po podziale oraz, po spacji, liczbę możliwych podziałów, które doprowadzą do minimalnej różnicy (k). W kolejnych k wierszach należy wypisać wszystkie te podziały. Każdy podział powinien być opisany przez dwie liczby u v – koralowce które powinny się rozdzielić (u < v). Podziały powinny być uporządkowane rosnąco według koralowca u (w przypadku remisów, rosnąco według koralowca v).  

Przykład 

Wejście  
8  
1  
1 0  
1 1  
1 2  
1 3  
1 1  
1 1  
1 4

Wyjście  
0 1  
1 2  

Wejście
5  
2  
2 0  
2 1  
2 2  
2 3  

Wyjście  
2 2  
1 2  
2 3  
