
# Tools

## GCC
Der er vigtigt at benytte de rigtige tools. For at cross-compileringen til x86prime fungerer korrekt er du nødt til at benytte `gcc` på en Linux maskine; husk at oversættelse på forskellige arkitekturer og OS's kan være meget forskelligt. Der er tre måder at gøre dette på. Du kan:

* Benytte vores python-script til at oversætte koden via på en af vores servere. [gcc-online.py](https://github.com/kirkedal/compSys-e2020-pub/blob/master/x86prime_tools/gcc-online.py) -- Vi kan ikke garanterer stabiliteten af denne.
* Have en maskine med Linux eller Windows subsystem for Linux. ([Detaljer](https://github.com/kirkedal/compSys-e2020-pub/tree/master/tools))
* Have en maskine med macOS eller andet og benytte en virtuel Linux maskine. ([Detaljer](https://github.com/kirkedal/compSys-e2020-pub/tree/master/tools/vm))

## x86prime Tools

Som beskrevet nedenfor (og I A2 opgaveteksten) vil der de næste uger være nødvendigt at benytte et speciel udviklet værktøj. Dette er skrevet i OCaml. Det kan installeres eller køres på følgende måde:

* Have en maskine med Linux eller Windows subsystem for Linux og installerer det. ([Detaljer](https://github.com/finnschiermer/x86prime/blob/master/README.md))
* Have en hvilken som helst maskine og benytte en virtuel Linux maskine med værktøjet præinstalleret. ([Detaljer](https://github.com/kirkedal/compSys-e2020-pub/tree/master/tools/vm))
* (Den midlertidige) Benytte vores python-script til at benytte x86prime via en af vores servere. [gcc-online.py](https://github.com/kirkedal/compSys-e2020-pub/blob/master/x86prime_tools/) -- Vi kan ikke garanterer stabiliteten af denne.

