# Opgaver til 21/9-2019

Se også [Reading Material](readingMaterial.md).

De øvelser der ikke nås 21/9, vil nok indgå 23/9

## Opgave 1

Få installeret x86prime. Hvis du kører Windows eller Mac skal du formodentlig have
fat i en virtuel maskine med Linux. 

Alternativt: få installeret scripts til at kalde de samme programmer på DIKUs remote
server. Tjek at det virker.

Se følgende anbefalinger [Tool setup](tools.md).

## Opgave 2

Oversæt nedenstående C program til x86prime:
~~~
long fib(long n) {
  if (n < 2) return 1;
  return fib(n-1) + fib(n-2);
}
~~~

Spg 1: Prøv først at lave oversættelsen i hånden. 

Spg 2: Brug dernæst gcc til at lave et x86-assembler program, 
og oversæt så dette program manuelt til x86prime.

Spg 3: Brug x86prime til få oversat fra x86 assembler.
Svarer resultatet til din manuelle oversættelse? Hvis ikke,
hvad er forskellen?


## Opgave 3

Byg den udleverede simulator til A2. Lav et ganske lille program
der kun bruger de aritmetisk/logiske instruktioner samt STOP.
Oversæt programmet med "prasm". Kør den resulterende hex file
(det oversatte program) med den udleverede simulator. Ser
udførelsen korrekt ud?


## Opgave 4

Udfør programmet fra forrige opgave med "prun" (også kaldet
reference-simulatoren). Få "prun" til at generere en sporingsfil
(også kaldet en trace-file). Gentag derefter kørslen af hex filen
på simulatoren til A2 og brug sporingsfilen til at tjekke om kørslen
er korrekt.


## Opgave 5

Indfør en brug af CALL, RET eller JMP i dit prime program.
Oversæt til en hex fil, kør den med simulatoren til A2.
Hvad går der galt? Eller virker det?


## Opgave 6

Lav en sporingsfil (som i opgave 4) og brug den til at detektere 
afvigelser mellem simulatoren til A2 og reference-simulatoren.


## Opgave 7

Betragt koden i kroppen af løkken i main() funktionen i main.c.
Prøv at beskrive hvad de forskellige dele af koden gør.
Tegningen af mikroarkitekturen (se forelæsnings slides) er ret
overordnet. Man signaler er udeladt.

Lav en mere detaljeret tegning af mikroarkitekturen, hvor de 
signaler/forbindelser der indgår i den udleverede kode er medtaget.

## Opgave 8

Besøg "nandgame.com" og brug en times tid på at bygge kredsløb.
Stop og vær meget stolt af dig selv, hvis du når til opbygning
af aritmetisk-logiske kredsløb.


