# Løsninger til øvelser til 28nde september

## Spg 1 - løsning
Den sidste movq-instruktion venter nu på %r11 i X-stadiet i stedet for i D. Den
bruger kun en enkelt cyklus i D, da %r10 allerede er klar.
~~~
Loop:
    movq (%r10),%r11    FDXMYW
    cbe $0,%r11,Done     FDDXMYW
    multq %r12,%r11       FFDXMYW
    movq %r11,(%r10)        FDXXXMYW
    addq $8,%r10             FDDDXMYW
    jmp Loop                  FFFDXMYW
Done:
~~~

## Spg 2 - løsning
jmp-instruktionen er i stand til, at ændre instruktionspegeren i slutningen af D-stadiet, så
den første instruktion i den næste iteration af loopet kan fetches i den efterfølgende cyklus.

De lodrette streger i plottet inkapsulerer cyklerne i en enkelt iteration.
~~~
Loop:
    movq (%r10),%r11    FDXMYW    |          |
    cbe $0,%r11,Done     FDDXMYW  |          |
    multq %r12,%r11       FFDXMYW |          |
    movq %r11,(%r10)        FDXXXM|YW        |
    addq $8,%r10             FDDDX|MYW       |
    jmp Loop                  FFFD|XMYW      |
                                  |          |
    movq (%r10),%r11           ***|FDXMYW    |  * = F-stadiet er ledigt, men IP'en peger ikke herhen endnu.
    cbe $0,%r11,Done              | FDDXMYW  |
    multq %r12,%r11               |  FFDXMYW |
    movq %r11,(%r10)              |    FDXXXM|YW
    addq $8,%r10                  |     FDDDX|MYW
    jmp Loop                      |      FFFD|XMYW
                                  |          |
    movq (%r10),%r11              |       ***|FDXMYW
    cbe $0,%r11,Done              |          | FDDXMYW
    multq %r12,%r11               |          |  FFDXMYW
    movq %r11,(%r10)              |          |    FDXXXMYW
    addq $8,%r10                  |          |     FDDDXMYW
    jmp Loop                      |          |        FDXMYW
Done:
~~~
Gennemløbstiden er den tid, der går, fra starten af en iteration og indtil næste iteration kan påbegyndes.
Loopet gennemløber altså på 10 cykler. Den sidste iteration af loopet vil dog
kun løbe 5 cykler, før cbe-instruktionen i sit X-stadie hopper ud af loopet, og mere generelt kan man derfor sige,
at gennemløbstiden for en iteration er ((n-1)*10 + 5)/n, hvor n er størrelsen af det nul-terminerede array.
(tak til Kennie Larsen fra absalon).

## Spg 3 - løsning
Den sidste movq-instruktion staller, fordi den venter på resultatet fra multq.
addq-instruktionen kan med fordel rykkes op over den sidste movq-instruktion,
da denne er uafhængig af multq-resultatet. Til gengæld skal movq nu trække 8
fra adressen i %r10 for at kompensere for, at addq-instruktionen sker for tidligt.
Da ser afviklingsplottet for loopet sådan her:
~~~
Loop:
    movq (%r10),%r11    FDXMYW  |        | 
    cbe $0,%r11,Done     FDDXMYW|        |
    multq %r12,%r11       FFDXMY|W       |
    addq $8,%r10            FDXM|YW      |
    movq %r11,-8(%r10)       FDX|XMYW    |
    jmp Loop                  FD|DXMYW   |
                                |        |
    movq (%r10),%r11           *|FDXMYW  |  * = F-stadiet er ledigt, men IP'en peger ikke herhen endnu.
    cbe $0,%r11,Done            | FDDXMYW|
    multq %r12,%r11             |  FFDXMY|W
    addq $8,%r10                |    FDXM|YW
    movq %r11,-8(%r10)          |     FDX|XMYW
    jmp Loop                    |      FD|DXMYW
                                |        |
    movq (%r10),%r11            |       *|FDXMYW
    cbe $0,%r11,Done            |        | FDDXMYW
    multq %r12,%r11             |        |  FFDXMYW
    addq $8,%r10                |        |    FDXMYW
    movq %r11,-8(%r10)          |        |     FDXMYW
    jmp Loop                    |        |      FDXMYW
Done:
~~~

Gennemløbstiden er igen den tid, der går, fra starten af en iteration indtil den næste iteration kan påbegyndes.
Gennemløbstiden for det optimerede loop er altså 8 cykler. Den sidste iteration af loopet vil dog
kun løbe 5 cykler, før cbe-instruktionen hopper ud af loopet, og mere generelt kan man derfor sige,
at gennemløbstiden for en iteration er ((n-1)*8 + 5)/n.
