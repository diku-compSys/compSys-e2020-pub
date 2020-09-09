#GDB-kommandoer

## fra kommandolinjen:
    gdb                        -> start gdb
------------------------------------------------------------------------------------------------
    gdb <eksekverbar>          -> start gdb; hent samtidig symboler fra og klargør den
                                  kompilerede kodefil <eksekverbar> til afvikling
------------------------------------------------------------------------------------------------
    gdb -x <gdb-scriptfil>
      <valgfri eksekverbar>    -> start gdb; afvikl gdb-kommandoerne i <gdb-scriptfil> fra top-
                                  pen og ned. En eksekverbar, der skal debugges, kan specificeres
                                  i kommandolinjen, men kan ligeså godt loades inde i scriptet
------------------------------------------------------------------------------------------------

## i gdb:
    file <eksekverbar>         -> hent symboler fra og klargør <eksekverbar> til afvikling
------------------------------------------------------------------------------------------------
    run <arg 1> ... <arg n>    -> kør den eksekvérbare med kommandolinjeargumenterne
                                  <arg 1> ... <arg n>
------------------------------------------------------------------------------------------------
    start <arg 1> ... <arg n>  -> start debugging af den eksekverbare med kommandolinjeargumenterne;
                                  <arg 1> ... <arg n>; ligesom run, men
------------------------------------------------------------------------------------------------
    break <breakpoint>         -> sæt et breakpoint i koden, som debuggeren skal stoppe ved,
                                  når afvikling når hertil. Et breakpoint kan enten være en funk-
                                  tion, f.eks "break main", eller en linje i koden: f.eks "break 10".
                                  Kan kaldes før eller efter run/start
------------------------------------------------------------------------------------------------
    next                       -> hop videre fra et break, linje for linje
------------------------------------------------------------------------------------------------
    continue                   -> lad programmet fortsætte, hvor det slap, og køre indtil
                                  næste breakpoint (eller til programmet er slut)
------------------------------------------------------------------------------------------------
    print <var>                -> vis værdien af en variabel <var> i koden på nuværende tidspunkt.
                                  <var> kan også være en macro, og tager denne macro argumenter,
                                  gives de også her. eks: "print UTF8_2B(192)"
------------------------------------------------------------------------------------------------
    print <var> = <val>        -> sæt variablen <var> til <val>. <var> har denne værdi indtil <var>
                                  <var> næste gang sættes i koden/gdb. Duer *ikke* til, at
                                  ændre macro-definitioner
------------------------------------------------------------------------------------------------
    quit                       -> gæt 1 gang
