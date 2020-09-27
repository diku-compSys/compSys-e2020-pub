# Øvelser til 28. sept. 2019


Færdiggør eventuelle overskydende øvelser fra sidste uge.


# Afviklingsplot

Nedenfor ses afviklingen af en stump x86prime kode på en simpel pipeline:

Den viste kode er den indre løkke i en funktion som multiplicerer
alle elementer i en nul-termineret tabel med et argument.

Ved indgang til løkken indeholder %r10 pointeren til tabellen og
%r12 det tal alle elementer skal multipliceres med.

~~~
Loop:
    movq (%r10),%r11    FDXMYW
    cbe $0,%r11,Done     FDDXMYW
    multq %r12,%r11       FFDXMYW
    movq %r11,(%r10)        FDDDXMYW
    addq $8,%r10             FFFDXMYW
    jmp Loop                    FDXMYW
Done:
~~~

Bogstaverne til højre viser hver instruktions passage gennem pipelinen.
Betydningen af bogstaverne er:

 * F: Fetch, instruktionhentning
 * D: Decode, afkodning, læsning af registre, evt venten på operander
 * X: eXecute, udførelse af ALU op, af adresseberegning eller af første del af multiplikation
 * M: Memory, læsning/skrivning af data fra data-cache, midterste del af multiplikation
 * Y: sidste del af multiplikation
 * W: Writeback, opdatering af registre

Alle instruktioner passerer gennem de samme 6 trin. Multiplikation udføres over 3 pipeline-trin,
E, M og Y. Et ubetinget hop udføres i D-trinnet, dvs den instruktion der hoppes til kan blive
hentet i cyklussen efter. Et betinget hop udføres derimod først i X-trinnet.

Der er fuld forwarding af operander fra en instruktion til en afhængig instruktion.
Instruktioner venter i D-trinnet indtil operander er tilgængelige.

## Spg 1:

Vi indfører en særlig undtagelse for movq instruktioner som skriver til lageret.
De skal stadig vente i D på operander til adresseberegning, men skal først vente
i X på selve den værdi der skal skrives til lageret.

Gentegn afviklingsplottet ovenfor under hensyntagen til denne ændring.

## Spg 2:

Hvor mange clock-cyklusser (sic) tager hvert gennemløb af løkken. Udvid eventuelt figuren
med instruktioner fra efterfølgende gennemløb, indtil du er sikker på dit svar.

## Spg 3:

Kan du optimere koden ved at flytte rundt på instruktionerne således at der er færre
instruktioner der skal vente på vej gennem pipelinen?

Vis den optimerede kode og tegn det tilsvarende afviklingsplot der viser hvordan den udføres 
i pipelinen. Hvor meget hurtigere er din optimerede kode?

